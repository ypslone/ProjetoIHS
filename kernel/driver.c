/* driver.c - captura todas letras e números e envia para Arduino */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/kfifo.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/poll.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/mutex.h>

#define DEVICE_NAME "arduino_buzzer"
#define FIFO_SIZE 256
#define ARDUINO_DEVICE "/dev/ttyACM0"

/* FIFO, lock and waitqueue */
static DECLARE_KFIFO(buzzer_fifo, char, FIFO_SIZE);
static spinlock_t fifo_lock;
static wait_queue_head_t fifo_wq;

/* Arduino serial communication */
static struct file *arduino_file = NULL;
static struct mutex arduino_mutex;
static struct task_struct *arduino_thread = NULL;
static bool thread_running = true;

/* misc device forward declaration */
static const struct file_operations dev_fops;
static struct miscdevice buzzer_misc;

/* work and handler state */
static DECLARE_WORK(register_work, NULL);
static bool handler_registered;

/* input handler prototypes */
static bool my_filter(struct input_handle *handle, unsigned int type, unsigned int code, int value);
static int my_connect(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id);
static void my_disconnect(struct input_handle *handle);

/* input id_table: match devices that support EV_KEY */
static const struct input_device_id ids[] = {
    { .flags = INPUT_DEVICE_ID_MATCH_EVBIT, .evbit = { BIT_WORD(EV_KEY) } },
    { }, /* terminator */
};
MODULE_DEVICE_TABLE(input, ids);

/* input handler */
static struct input_handler my_input_handler = {
    .filter = my_filter,
    .connect = my_connect,
    .disconnect = my_disconnect,
    .name = "arduino_buzzer_handler",
    .id_table = ids,
};

/* Map codes to chars (simplified, só letras e números) */
static char code_to_char(unsigned int code)
{
    switch(code) {
        case KEY_A: return 'A'; case KEY_B: return 'B'; case KEY_C: return 'C';
        case KEY_D: return 'D'; case KEY_E: return 'E'; case KEY_F: return 'F';
        case KEY_G: return 'G'; case KEY_H: return 'H'; case KEY_I: return 'I';
        case KEY_J: return 'J'; case KEY_K: return 'K'; case KEY_L: return 'L';
        case KEY_M: return 'M'; case KEY_N: return 'N'; case KEY_O: return 'O';
        case KEY_P: return 'P'; case KEY_Q: return 'Q'; case KEY_R: return 'R';
        case KEY_S: return 'S'; case KEY_T: return 'T'; case KEY_U: return 'U';
        case KEY_V: return 'V'; case KEY_W: return 'W'; case KEY_X: return 'X';
        case KEY_Y: return 'Y'; case KEY_Z: return 'Z';
        case KEY_0: return '0'; case KEY_1: return '1'; case KEY_2: return '2';
        case KEY_3: return '3'; case KEY_4: return '4'; case KEY_5: return '5';
        case KEY_6: return '6'; case KEY_7: return '7'; case KEY_8: return '8';
        case KEY_9: return '9';
        default: return 0;
    }
}

/* Tenta abrir o Arduino */
static int open_arduino(void)
{
    arduino_file = filp_open(ARDUINO_DEVICE, O_WRONLY | O_NOCTTY, 0);
    if (IS_ERR(arduino_file)) {
        pr_info("arduino_buzzer: Arduino não encontrado em %s, usando modo compatibilidade\n", ARDUINO_DEVICE);
        arduino_file = NULL;
        return -1;
    }
    
    pr_info("arduino_buzzer: Arduino conectado em %s\n", ARDUINO_DEVICE);
    return 0;
}

/* Envia caractere para Arduino usando kernel_write (kernels modernos) */
static void send_to_arduino(char c)
{
    loff_t pos = 0;
    ssize_t ret;
    
    if (!arduino_file)
        return;
        
    mutex_lock(&arduino_mutex);
    
    ret = kernel_write(arduino_file, &c, 1, &pos);
    if (ret == 1) {
        pr_info("arduino_buzzer: '%c' → Arduino\n", c);
    } else {
        pr_debug("arduino_buzzer: erro ao enviar '%c': %zd\n", c, ret);
    }
    
    mutex_unlock(&arduino_mutex);
}

/* Thread para processar FIFO */
static int arduino_sender(void *data)
{
    char c;
    unsigned long flags;
    
    pr_info("arduino_buzzer: thread Arduino iniciada\n");
    
    while (thread_running && !kthread_should_stop()) {
        wait_event_interruptible(fifo_wq, 
            !kfifo_is_empty(&buzzer_fifo) || kthread_should_stop());
        
        if (kthread_should_stop())
            break;
            
        spin_lock_irqsave(&fifo_lock, flags);
        if (kfifo_out(&buzzer_fifo, &c, 1)) {
            spin_unlock_irqrestore(&fifo_lock, flags);
            send_to_arduino(c);
            msleep(100); // pausa entre caracteres
        } else {
            spin_unlock_irqrestore(&fifo_lock, flags);
        }
    }
    
    pr_info("arduino_buzzer: thread Arduino finalizada\n");
    return 0;
}

/* input filter: captura tecla pressionada */
static bool my_filter(struct input_handle *handle, unsigned int type, unsigned int code, int value)
{
    unsigned long flags;
    char c;

    if (type == EV_KEY && value == 1) { // pressionada
        c = code_to_char(code);
        if (c) {
            spin_lock_irqsave(&fifo_lock, flags);
            if (!kfifo_is_full(&buzzer_fifo))
                kfifo_in(&buzzer_fifo, &c, 1);
            spin_unlock_irqrestore(&fifo_lock, flags);

            wake_up_interruptible(&fifo_wq);
            pr_info("arduino_buzzer: tecla %c capturada\n", c);
        }
    }
    return false; /* permitir outros handlers */
}

/* connect/disconnect */
static int my_connect(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id)
{
    struct input_handle *handle;
    int error;

    handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
    if (!handle) return -ENOMEM;

    handle->dev = dev;
    handle->handler = handler;
    handle->name = "buzzer_arduino_handle";

    error = input_register_handle(handle);
    if (error) {
        kfree(handle);
        return error;
    }

    error = input_open_device(handle);
    if (error) {
        input_unregister_handle(handle);
        kfree(handle);
        return error;
    }

    return 0;
}

static void my_disconnect(struct input_handle *handle)
{
    input_close_device(handle);
    input_unregister_handle(handle);
    kfree(handle);
}

/* device read - mantém compatibilidade com versão original */
static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    unsigned int copied;
    unsigned long flags;
    char tmpbuf[256];
    unsigned int to_copy;

    if (count == 0) return 0;

    to_copy = min_t(unsigned int, count, (unsigned int)sizeof(tmpbuf));

    spin_lock_irqsave(&fifo_lock, flags);
    if (kfifo_is_empty(&buzzer_fifo)) {
        spin_unlock_irqrestore(&fifo_lock, flags);
        if (file->f_flags & O_NONBLOCK) return -EAGAIN;
        if (wait_event_interruptible(fifo_wq, !kfifo_is_empty(&buzzer_fifo)))
            return -ERESTARTSYS;
        spin_lock_irqsave(&fifo_lock, flags);
    }

    copied = kfifo_out(&buzzer_fifo, tmpbuf, to_copy);
    spin_unlock_irqrestore(&fifo_lock, flags);

    if (copy_to_user(buf, tmpbuf, copied)) return -EFAULT;

    return copied;
}

/* poll */
static unsigned int dev_poll(struct file *file, struct poll_table_struct *wait)
{
    unsigned int mask = 0;
    unsigned long flags;

    poll_wait(file, &fifo_wq, wait);

    spin_lock_irqsave(&fifo_lock, flags);
    if (!kfifo_is_empty(&buzzer_fifo)) mask |= POLLIN | POLLRDNORM;
    spin_unlock_irqrestore(&fifo_lock, flags);

    return mask;
}

static const struct file_operations dev_fops = {
    .owner = THIS_MODULE,
    .read  = dev_read,
    .poll  = dev_poll,
};

static struct miscdevice buzzer_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEVICE_NAME,
    .fops = &dev_fops,
};

/* deferred work */
static void register_handler_workfn(struct work_struct *work)
{
    int ret;
    pr_info("arduino_buzzer: deferred input_register_handler()\n");
    ret = input_register_handler(&my_input_handler);
    if (ret) {
        pr_err("arduino_buzzer: input_register_handler failed: %d\n", ret);
    } else {
        handler_registered = true;
        pr_info("arduino_buzzer: input handler registered\n");
    }
}

/* init/exit */
static int __init arduino_init(void)
{
    int ret;

    spin_lock_init(&fifo_lock);
    init_waitqueue_head(&fifo_wq);
    mutex_init(&arduino_mutex);
    INIT_WORK(&register_work, register_handler_workfn);

    /* Registra device para compatibilidade */
    ret = misc_register(&buzzer_misc);
    if (ret) {
        pr_err("arduino_buzzer: misc_register failed: %d\n", ret);
        return ret;
    }

    /* Tenta conectar Arduino diretamente */
    if (open_arduino() == 0 && arduino_file) {
        msleep(2000); // Aguarda Arduino resetar
        
        /* Cria thread para enviar dados */
        arduino_thread = kthread_create(arduino_sender, NULL, "arduino_sender");
        if (!IS_ERR(arduino_thread)) {
            wake_up_process(arduino_thread);
            pr_info("arduino_buzzer: modo comunicação direta ativado\n");
        } else {
            pr_err("arduino_buzzer: falha ao criar thread: %ld\n", PTR_ERR(arduino_thread));
            arduino_thread = NULL;
        }
    }

    /* Registra handler de input */
    schedule_work(&register_work);

    pr_info("arduino_buzzer: módulo carregado, device /dev/%s criado\n", DEVICE_NAME);
    pr_info("arduino_buzzer: %s\n", 
        arduino_file ? "✓ Arduino conectado - envio direto" : "⚠ Arduino não detectado - use script Python");
    
    return 0;
}

static void __exit arduino_exit(void)
{
    pr_info("arduino_buzzer: finalizando módulo\n");
    
    thread_running = false;
    
    cancel_work_sync(&register_work);

    if (handler_registered)
        input_unregister_handler(&my_input_handler);

    /* Para thread Arduino */
    if (arduino_thread && !IS_ERR(arduino_thread)) {
        wake_up_interruptible(&fifo_wq);
        kthread_stop(arduino_thread);
    }

    /* Fecha Arduino */
    if (arduino_file) {
        filp_close(arduino_file, NULL);
        arduino_file = NULL;
    }

    misc_deregister(&buzzer_misc);
    pr_info("arduino_buzzer: módulo descarregado\n");
}

module_init(arduino_init);
module_exit(arduino_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Seu Nome");
MODULE_DESCRIPTION("Kernel module capturing letters and numbers - direct Arduino support");
MODULE_VERSION("2.0");