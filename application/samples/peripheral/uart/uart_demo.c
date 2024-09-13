/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: UART Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-06-29, Create file. \n
 */
#include "pinctrl.h"
#include "uart.h"
#include "watchdog.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"

#define UART_BAUDRATE                      115200
#define UART_DATA_BITS                     3
#define UART_STOP_BITS                     1
#define UART_PARITY_BIT                    0
#define UART_TRANSFER_SIZE                 512
#define CONFIG_UART_INT_WAIT_MS            5

#define UART_TASK_STACK_SIZE               0x1000
#define UART_TASK_DURATION_MS              500
#define UART_TASK_PRIO                     (osPriority_t)(17)

static uint8_t g_app_uart_rx_buff[UART_TRANSFER_SIZE] = { 0 };
#if defined(CONFIG_UART_INT_TRANSFER_MODE)
static uint8_t g_app_uart_int_rx_flag = 0;
#endif
static uart_buffer_config_t g_app_uart_buffer_config = {
    .rx_buffer = g_app_uart_rx_buff,
    .rx_buffer_size = UART_TRANSFER_SIZE
};


static void app_uart_init_pin(void)
{
    if (CONFIG_UART_BUS_ID == 0) {
        uapi_pin_set_mode(CONFIG_UART_TXD_PIN, HAL_PIO_UART_L0_TXD);
        uapi_pin_set_mode(CONFIG_UART_RXD_PIN, HAL_PIO_UART_L0_RXD);       
    }else if (CONFIG_UART_BUS_ID == 1) {
        uapi_pin_set_mode(CONFIG_UART_TXD_PIN, HAL_PIO_UART_H0_TXD);
        uapi_pin_set_mode(CONFIG_UART_RXD_PIN, HAL_PIO_UART_H0_RXD);       
    }else if (CONFIG_UART_BUS_ID == 2) {
        uapi_pin_set_mode(CONFIG_UART_TXD_PIN, HAL_PIO_UART_L1_TXD);
        uapi_pin_set_mode(CONFIG_UART_RXD_PIN, HAL_PIO_UART_L1_RXD);       
    }
}

static void app_uart_init_config(void)
{
    uart_attr_t attr = {
        .baud_rate = UART_BAUDRATE,
        .data_bits = UART_DATA_BITS,
        .stop_bits = UART_STOP_BITS,
        .parity = UART_PARITY_BIT
    };

    uart_pin_config_t pin_config = {
        .tx_pin = CONFIG_UART_TXD_PIN,
        .rx_pin = CONFIG_UART_RXD_PIN,
        .cts_pin = PIN_NONE,
        .rts_pin = PIN_NONE
    };
    uapi_uart_deinit(CONFIG_UART_BUS_ID);
    uapi_uart_init(CONFIG_UART_BUS_ID, &pin_config, &attr, NULL, &g_app_uart_buffer_config);

}

#if defined(CONFIG_UART_INT_TRANSFER_MODE)
static void app_uart_read_int_handler(const void *buffer, uint16_t length, bool error)
{
    unused(error);
    if (buffer == NULL || length == 0) {
        osal_printk("uart%d int mode transfer illegal data!\r\n", CONFIG_UART_BUS_ID);
        return;
    }
    uint8_t *buff = (uint8_t *)buffer;
    if (memcpy_s(g_app_uart_rx_buff, length, buff, length) != EOK) {
        osal_printk("uart%d int mode data copy fail!\r\n", CONFIG_UART_BUS_ID);
        return;
    }
    g_app_uart_int_rx_flag = 1;
}

static void app_uart_write_int_handler(const void *buffer, uint32_t length, const void *params)
{
    unused(params);
    uint8_t *buff = (void *)buffer;
    for (uint32_t i = 0; i < length; i++) {
        osal_printk("uart%d write data[%d] = %d\r\n", CONFIG_UART_BUS_ID, i, buff[i]);
    }
    
}
#endif

static void *uart_task(const char *arg)
{
    unused(arg);
    /* UART pinmux. */
    app_uart_init_pin();

    /* UART init config. */
    app_uart_init_config();

#if defined(CONFIG_UART_INT_TRANSFER_MODE)
    osal_printk("uart%d int mode register receive callback start!\r\n", CONFIG_UART_BUS_ID);
    uapi_uart_unregister_rx_callback(CONFIG_UART_BUS_ID);
    if (uapi_uart_register_rx_callback(CONFIG_UART_BUS_ID, UART_RX_CONDITION_FULL_OR_IDLE,
                                       1, app_uart_read_int_handler) == ERRCODE_SUCC) {
        osal_printk("uart%d int mode register receive callback succ!\r\n", CONFIG_UART_BUS_ID);
    }
#endif

    while (1) {
        osDelay(UART_TASK_DURATION_MS);
#if defined(CONFIG_UART_POLL_TRANSFER_MODE)
        osal_printk("uart%d poll mode receive start!\r\n", CONFIG_UART_BUS_ID);
        (void)uapi_watchdog_kick();
        if (uapi_uart_read(CONFIG_UART_BUS_ID, g_app_uart_rx_buff, UART_TRANSFER_SIZE, 0) == UART_TRANSFER_SIZE) {
            osal_printk("uart%d poll mode receive succ!\r\n", CONFIG_UART_BUS_ID);
        }
        osal_printk("uart%d poll mode send back!\r\n", CONFIG_UART_BUS_ID);
        if (uapi_uart_write(CONFIG_UART_BUS_ID, g_app_uart_rx_buff, UART_TRANSFER_SIZE, 0) == UART_TRANSFER_SIZE) {
            osal_printk("uart%d poll mode send back succ!\r\n", CONFIG_UART_BUS_ID);
        }
#endif
#if defined(CONFIG_UART_INT_TRANSFER_MODE)
        while (g_app_uart_int_rx_flag != 1) {
            osDelay(CONFIG_UART_INT_WAIT_MS);
        }
        g_app_uart_int_rx_flag = 0;
        osal_printk("uart%d int mode send back!\r\n", CONFIG_UART_BUS_ID);
        if (uapi_uart_write_int(CONFIG_UART_BUS_ID, g_app_uart_rx_buff, UART_TRANSFER_SIZE, 0,
                                app_uart_write_int_handler) == ERRCODE_SUCC) {
            osal_printk("uart%d int mode send back succ!\r\n", CONFIG_UART_BUS_ID);
        }
#endif
    }

    return NULL;
}

static void uart_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "UartTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = UART_TASK_STACK_SIZE;
    attr.priority = UART_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)uart_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the uart_entry. */
app_run(uart_entry);