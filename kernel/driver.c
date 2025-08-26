/* driver.c - deferred registration, kfifo + misc device, compatible with modern kernels */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/kfifo.h>
#include <linux/wait.h>
#include <linux/spinlock.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/poll.h>

#define DEVICE_NAME "arduino_buzzer"
#define FIFO_SIZE 256

/* FIFO, lock and waitqueue */
static DECLARE_KFIFO(buzzer_fifo, char, FIFO_SIZE);
static spinlock_t fifo_lock;
static wait_queue_head_t fifo_wq;

/* misc device */
static const struct file_operations dev_fops; /* forward decl */
static struct miscdevice buzzer_misc;

/* work and handler state */
static DECLARE_WORK(register_work, NULL);
static bool handler_registered;

/* input handler prototypes */
static bool my_filter(struct input_handle *handle, unsigned int type, unsigned int code, int value);
static int my_connect(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id);
static void my_disconnect(struct input_handle *handle);

/* input id_table: match devices that support EV_KEY (reduces scope) */
static const struct input_device_id ids[] = {
    {
        .flags = INPUT_DEVICE_ID_MATCH_EVBIT,
        .evbit = { BIT_WORD(EV_KEY) },
    },
    { }, /* terminator */
};

MODULE_DEVICE_TABLE(input, ids);

/* input handler struct (filled below) */
static struct input_handler my_input_handler = {
    .filter = my_filter,
    .connect = my_connect,
    .disconnect = my_disconnect,
    .name = "arduino_buzzer_handler",
    .id_table = ids,
};

/* input filter: runs in IRQ/context; must be fast and non-sleeping */
static bool my_filter(struct input_handle *handle, unsigned int type, unsigned int code, int value)
{
    unsigned long flags;
    char c = 'b';

    if (type == EV_KEY && value == 1 && code == KEY_B) {
        spin_lock_irqsave(&fifo_lock, flags);
        if (!kfifo_is_full(&buzzer_fifo))
            kfifo_in(&buzzer_fifo, &c, 1);
        spin_unlock_irqrestore(&fifo_lock, flags);

        wake_up_interruptible(&fifo_wq);
        pr_info("arduino_buzzer: KEY_B captured\n");
    }
    return false; /* allow other handlers to receive event */
}

/* connect/disconnect: allocate an input_handle and open device */
static int my_connect(struct input_handler *handler, struct input_dev *dev, const struct input_device_id *id)
{
    struct input_handle *handle;
    int error;

    handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
    if (!handle)
        return -ENOMEM;

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

/* device read: read from kfifo (blocking unless O_NONBLOCK) */
static ssize_t dev_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    unsigned int copied;
    unsigned long flags;
    char tmpbuf[256];
    unsigned int to_copy;

    if (count == 0)
        return 0;

    to_copy = min_t(unsigned int, count, (unsigned int)sizeof(tmpbuf));

    spin_lock_irqsave(&fifo_lock, flags);
    if (kfifo_is_empty(&buzzer_fifo)) {
        spin_unlock_irqrestore(&fifo_lock, flags);
        if (file->f_flags & O_NONBLOCK)
            return -EAGAIN;
        if (wait_event_interruptible(fifo_wq, !kfifo_is_empty(&buzzer_fifo)))
            return -ERESTARTSYS;
        spin_lock_irqsave(&fifo_lock, flags);
    }

    copied = kfifo_out(&buzzer_fifo, tmpbuf, to_copy);
    spin_unlock_irqrestore(&fifo_lock, flags);

    if (copy_to_user(buf, tmpbuf, copied))
        return -EFAULT;

    return copied;
}

/* poll implementation using modern signature */
static unsigned int dev_poll(struct file *file, struct poll_table_struct *wait)
{
    unsigned int mask = 0;
    unsigned long flags;

    poll_wait(file, &fifo_wq, wait);

    spin_lock_irqsave(&fifo_lock, flags);
    if (!kfifo_is_empty(&buzzer_fifo))
        mask |= POLLIN | POLLRDNORM;
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

/* deferred work function to register the input handler after module init */
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

/* module init/exit */
static int __init arduino_init(void)
{
    int ret;

    spin_lock_init(&fifo_lock);
    init_waitqueue_head(&fifo_wq);
    INIT_WORK(&register_work, register_handler_workfn);

    ret = misc_register(&buzzer_misc);
    if (ret) {
        pr_err("arduino_buzzer: misc_register failed: %d\n", ret);
        return ret;
    }

    /* schedule deferred registration of input handler */
    schedule_work(&register_work);

    pr_info("arduino_buzzer module loaded, device /dev/%s\n", DEVICE_NAME);
    return 0;
}

static void __exit arduino_exit(void)
{
    /* cancel and flush the deferred work if pending */
    cancel_work_sync(&register_work);

    if (handler_registered)
        input_unregister_handler(&my_input_handler);

    misc_deregister(&buzzer_misc);
    pr_info("arduino_buzzer module unloaded\n");
}

module_init(arduino_init);
module_exit(arduino_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Seu Nome");
MODULE_DESCRIPTION("Kernel module capturing KEY_B and exposing events via /dev/arduino_buzzer (deferred reg)");
