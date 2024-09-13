#define __DEMO_C_
#include "demo.h"

#define SLE_TEST1_TASK_STACK_SIZE 4096
#define SLE_TEST1_TASK_PRIO 27
#define SLE_TEST2_TASK_STACK_SIZE 4096
#define SLE_TEST2_TASK_PRIO 26

static void bs21_rst(void)
{
    uapi_pin_set_mode(S_MGPIO21, (pin_mode_t)HAL_PIO_FUNC_GPIO);
    uapi_gpio_set_dir(S_MGPIO21, GPIO_DIRECTION_INPUT);
    uapi_pin_set_pull(S_MGPIO21, PIN_PULL_UP);
    reg16_setbits(0x5702C51C, 4, 5, 21);
    reg16_clrbit(0x5702C51C, 0);
}

static void *sle_test_task1(const char *arg)
{
    arg = arg;
    osal_printk("\r\n\r\n sle_test_task1 \r\n\r\n");
    while (1)
    {
        osal_printk("\r\n\r\n test1 \r\n\r\n");
        osal_msleep(1000);
    }

    return NULL;
}

static void *sle_test_task2(const char *arg)
{
    arg = arg;
    osal_printk("\r\n\r\n sle_test_task2 \r\n\r\n");
    while (1)
    {
        osal_printk("\r\n\r\n test2 \r\n\r\n");
        osal_msleep(1000);
    }

    return NULL;
}

void axk_main(void)
{
    bs21_rst();

    osal_task *task_handle = NULL;

    osal_kthread_lock();

    task_handle = osal_kthread_create((osal_kthread_handler)sle_test_task1, 0, "sle_test_task1",
                                      SLE_TEST1_TASK_STACK_SIZE);

    if (task_handle != NULL)
    {
        osal_kthread_set_priority(task_handle, SLE_TEST1_TASK_PRIO);
        osal_kfree(task_handle);
    }

    task_handle = osal_kthread_create((osal_kthread_handler)sle_test_task2, 0, "sle_test_task2",
                                      SLE_TEST2_TASK_STACK_SIZE);

    if (task_handle != NULL)
    {
        osal_kthread_set_priority(task_handle, SLE_TEST2_TASK_PRIO);
        osal_kfree(task_handle);
    }
    osal_kthread_unlock();
}