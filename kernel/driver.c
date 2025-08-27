// driver.c - Kernel 6.x TTY-safe - VERSÃO CORRIGIDA

#include <linux/module.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/fs.h>
#include <linux/kfifo.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/mutex.h>
#include <linux/tty.h>
#include <linux/uaccess.h>
#include <linux/version.h>

#define ARDUINO_DEVICE "/dev/ttyACM1"
#define FIFO_SIZE 256

/* FIFO e sincronização */
static DEFINE_KFIFO(buzzer_fifo, unsigned char, FIFO_SIZE);
static spinlock_t fifo_lock;
static wait_queue_head_t fifo_wq;

/* Serial do Arduino */
static struct file *arduino_file = NULL;
static struct mutex arduino_mutex;
static struct task_struct *arduino_thread = NULL;
static bool thread_running = true;

/* Input handler prototypes */
static bool my_filter(struct input_handle *handle, unsigned int type, unsigned int code, int value);
static int my_connect(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id);
static void my_disconnect(struct input_handle *handle);

/* Devices EV_KEY */
static const struct input_device_id ids[] = {
    { .flags = INPUT_DEVICE_ID_MATCH_EVBIT, .evbit = { BIT_WORD(EV_KEY) } },
    { },
};
MODULE_DEVICE_TABLE(input, ids);

/* Input handler */
static struct input_handler my_input_handler = {
    .filter = my_filter,
    .connect = my_connect,
    .disconnect = my_disconnect,
    .name = "arduino_buzzer_handler",
    .id_table = ids,
};

/* Map KEY_* -> ASCII (A-Z, 0-9) */
static unsigned char code_to_char(unsigned int code)
{
    switch (code) {
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

/* Abrir Arduino via /dev/ttyACM0 */
static int open_arduino(void)
{
    if (arduino_file) return 0;

    arduino_file = filp_open(ARDUINO_DEVICE, O_RDWR | O_NOCTTY | O_NONBLOCK, 0);
    if (IS_ERR(arduino_file)) {
        pr_err("arduino_buzzer: falha ao abrir %s (%ld)\n", ARDUINO_DEVICE, PTR_ERR(arduino_file));
        arduino_file = NULL;
        return -ENODEV;
    }

    pr_info("arduino_buzzer: Arduino aberto com sucesso\n");
    return 0;
}

/* Envia dados usando vfs_write */
static int send_to_arduino(unsigned char c)
{
    ssize_t ret;
    loff_t pos = 0;
    
    if (!arduino_file) {
        pr_err("arduino_buzzer: arquivo não aberto\n");
        return -ENODEV;
    }

    mutex_lock(&arduino_mutex);
    
    /* Debug: mostra exatamente o que está sendo enviado */
    pr_info("arduino_buzzer: DEBUG - enviando caractere '%c' ASCII=%d HEX=0x%02x\n", 
            (c >= 32 && c <= 126) ? c : '?', c, c);
    
    /* Tenta diferentes métodos dependendo da versão do kernel */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
    /* Kernels mais novos */
    ret = kernel_write(arduino_file, &c, 1, &pos);
#else
    /* Kernels mais antigos */
    ret = vfs_write(arduino_file, &c, 1, &pos);
#endif
    
    if (ret != 1) {
        pr_err("arduino_buzzer: ERRO - falha ao escrever! ret=%zd, char=0x%02x\n", ret, c);
        mutex_unlock(&arduino_mutex);
        return -EIO;
    }
    
    /* Força flush se disponível */
    if (arduino_file->f_op && arduino_file->f_op->flush) {
        ret = arduino_file->f_op->flush(arduino_file, NULL);
        if (ret) {
            pr_warn("arduino_buzzer: aviso - flush retornou %zd\n", ret);
        }
    }
    
    mutex_unlock(&arduino_mutex);
    
    pr_info("arduino_buzzer: SUCESSO - enviado '%c' (0x%02x) ret=%zd\n", 
            (c >= 32 && c <= 126) ? c : '?', c, ret);
    
    return 0;
}

/* Thread de envio do FIFO */
static int arduino_sender(void *data)
{
    unsigned char c;
    unsigned long flags;
    int ret;

    pr_info("arduino_buzzer: thread de envio iniciada\n");

    while (thread_running && !kthread_should_stop()) {
        /* Aguarda dados no FIFO */
        ret = wait_event_interruptible(fifo_wq, 
                                       !kfifo_is_empty(&buzzer_fifo) || 
                                       kthread_should_stop());
        
        if (kthread_should_stop()) {
            pr_info("arduino_buzzer: thread interrompida\n");
            break;
        }
        
        if (ret == -ERESTARTSYS) {
            continue; /* Signal recebido, continua */
        }

        /* Retira caractere do FIFO */
        spin_lock_irqsave(&fifo_lock, flags);
        if (kfifo_out(&buzzer_fifo, &c, 1)) {
            spin_unlock_irqrestore(&fifo_lock, flags);
            
            pr_info("arduino_buzzer: THREAD - retirado do FIFO: '%c' (ASCII=%d, HEX=0x%02x)\n", 
                    (c >= 32 && c <= 126) ? c : '?', c, c);
            
            /* Envia para Arduino */
            ret = send_to_arduino(c);
            if (ret < 0) {
                pr_err("arduino_buzzer: THREAD - falha ao enviar '%c'\n", c);
            }
            
            /* Delay entre envios */
            msleep(100);
        } else {
            spin_unlock_irqrestore(&fifo_lock, flags);
            pr_warn("arduino_buzzer: THREAD - FIFO vazio após wake_up!\n");
        }
    }
    
    pr_info("arduino_buzzer: thread de envio finalizada\n");
    return 0;
}

/* Filtro de input - VERSÃO DE TESTE SEM FIFO */
static bool my_filter(struct input_handle *handle, unsigned int type, unsigned int code, int value)
{
    unsigned char c;

    /* Só processa key press (value == 1) */
    if (type != EV_KEY || value != 1) {
        return false;
    }

    /* Converte código para caractere */
    c = code_to_char(code);
    if (!c) {
        return false; /* Tecla não mapeada */
    }

    pr_info("arduino_buzzer: FILTER - tecla capturada: '%c' (code=%u, ASCII=%d, HEX=0x%02x)\n", 
            c, code, c, c);

    /* TESTE: Envia diretamente sem FIFO */
    pr_info("arduino_buzzer: TESTE - enviando DIRETO sem FIFO\n");
    send_to_arduino(c);
    
    /* Versão original com FIFO (comentada para teste)
    unsigned long flags;
    spin_lock_irqsave(&fifo_lock, flags);
    if (!kfifo_in(&buzzer_fifo, &c, 1)) {
        pr_warn("arduino_buzzer: FIFO cheio, descartando '%c'\n", c);
        spin_unlock_irqrestore(&fifo_lock, flags);
        return false;
    }
    spin_unlock_irqrestore(&fifo_lock, flags);
    
    pr_info("arduino_buzzer: FILTER - caractere '%c' adicionado ao FIFO\n", c);
    wake_up_interruptible(&fifo_wq);
    */
    
    return false; /* Não bloqueia o evento para outros handlers */
}

/* Connect / disconnect */
static int my_connect(struct input_handler *handler, struct input_dev *dev, 
                     const struct input_device_id *id)
{
    struct input_handle *handle;
    int error;

    /* Só conecta em teclados */
    if (!test_bit(EV_KEY, dev->evbit)) {
        return -ENODEV;
    }

    handle = kzalloc(sizeof(*handle), GFP_KERNEL);
    if (!handle) {
        return -ENOMEM;
    }

    handle->dev = dev;
    handle->handler = handler;
    handle->name = "buzzer_arduino_handle";

    error = input_register_handle(handle);
    if (error) {
        pr_err("arduino_buzzer: erro ao registrar handle: %d\n", error);
        kfree(handle);
        return error;
    }

    error = input_open_device(handle);
    if (error) {
        pr_err("arduino_buzzer: erro ao abrir device: %d\n", error);
        input_unregister_handle(handle);
        kfree(handle);
        return error;
    }

    pr_info("arduino_buzzer: conectado ao device: %s\n", 
            dev->name ? dev->name : "unknown");
    
    return 0;
}

static void my_disconnect(struct input_handle *handle)
{
    pr_info("arduino_buzzer: desconectando do device: %s\n", 
            handle->dev->name ? handle->dev->name : "unknown");
    
    input_close_device(handle);
    input_unregister_handle(handle);
    kfree(handle);
}

/* Init / Exit */
static int __init arduino_init(void)
{
    int ret;

    pr_info("arduino_buzzer: inicializando módulo...\n");

    /* Inicializa estruturas de sincronização */
    spin_lock_init(&fifo_lock);
    init_waitqueue_head(&fifo_wq);
    mutex_init(&arduino_mutex);
    
    /* Reinicializa o FIFO para garantir */
    INIT_KFIFO(buzzer_fifo);
    pr_info("arduino_buzzer: FIFO inicializado (tamanho=%d)\n", kfifo_size(&buzzer_fifo));

    /* Abre conexão com Arduino */
    ret = open_arduino();
    if (ret) {
        pr_err("arduino_buzzer: falha ao abrir Arduino\n");
        return ret;
    }

    /* Cria thread de envio */
    arduino_thread = kthread_create(arduino_sender, NULL, "arduino_sender");
    if (IS_ERR(arduino_thread)) {
        pr_err("arduino_buzzer: falha ao criar thread\n");
        ret = PTR_ERR(arduino_thread);
        goto cleanup_file;
    }
    wake_up_process(arduino_thread);

    /* Registra handler de input */
    ret = input_register_handler(&my_input_handler);
    if (ret) {
        pr_err("arduino_buzzer: falha ao registrar handler: %d\n", ret);
        goto cleanup_thread;
    }

    pr_info("arduino_buzzer: módulo carregado com sucesso!\n");
    pr_info("arduino_buzzer: pressione A-Z ou 0-9 para testar\n");
    return 0;

cleanup_thread:
    thread_running = false;
    wake_up_interruptible(&fifo_wq);
    kthread_stop(arduino_thread);

cleanup_file:
    if (arduino_file) {
        filp_close(arduino_file, NULL);
        arduino_file = NULL;
    }

    return ret;
}

static void __exit arduino_exit(void)
{
    pr_info("arduino_buzzer: descarregando módulo...\n");

    /* Remove handler de input */
    input_unregister_handler(&my_input_handler);

    /* Para thread */
    thread_running = false;
    if (arduino_thread && !IS_ERR(arduino_thread)) {
        wake_up_interruptible(&fifo_wq);
        kthread_stop(arduino_thread);
    }

    /* Fecha arquivo */
    if (arduino_file) {
        filp_close(arduino_file, NULL);
        arduino_file = NULL;
    }

    pr_info("arduino_buzzer: módulo descarregado\n");
}

module_init(arduino_init);
module_exit(arduino_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Seu Nome");
MODULE_DESCRIPTION("Captura A-Z/0-9 e envia via serial para Arduino");
MODULE_VERSION("2.7");