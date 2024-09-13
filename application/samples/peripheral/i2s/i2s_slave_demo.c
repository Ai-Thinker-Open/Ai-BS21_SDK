/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: I2S Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-09-13, Create file. \n
 */
#include "common_def.h"
#include "pinctrl.h"
#include "i2s.h"
#include "hal_sio.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"

#define I2S_DATA_WIDTH             24
#define I2S_NUMBER_OF_CHANNELS     2

#define I2S_TASK_STACK_SIZE        0x1000
#define I2S_TASK_PRIO              (osPriority_t)(17)

static void app_i2s_init_pin(void)
{
    /* I2S pinmux. */
    uapi_pin_set_mode(CONFIG_I2S_CLK_SLAVE_PIN, HAL_PIO_I2S_SCLK);
    uapi_pin_set_mode(CONFIG_I2S_WS_SLAVE_PIN, HAL_PIO_I2S_WS);
    uapi_pin_set_mode(CONFIG_I2S_DO_SLAVE_PIN, HAL_PIO_I2S_DOUT);
    uapi_pin_set_mode(CONFIG_I2S_DI_SLAVE_PIN, HAL_PIO_I2S_DIN);
}

void app_i2s_rx_callbcak(uint32_t *left_buff, uint32_t *right_buff, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++) {
        osal_printk("left rx data is:0x%0x\r\n", left_buff[i]);
        osal_printk("right rx data is:0x%0x\r\n", right_buff[i]);
    }
}

static void *i2s_slave_task(const char *arg)
{
    unused(arg);
    i2s_config_t config = {
        .drive_mode= SLAVE,
        .transfer_mode = STD_MODE,
        .data_width = TWENTY_FOUR_BIT,
        .channels_num = TWO_CH,
        .timing = NONE_MODE,
        .clk_edge = NONE_EDGE,
        .div_number = I2S_DATA_WIDTH,
        .number_of_channels = I2S_NUMBER_OF_CHANNELS,
    };
    app_i2s_init_pin();
    /* I2S init. */
    uapi_i2s_init(CONFIG_I2S_SLAVE_BUS_ID, app_i2s_rx_callbcak);
    uapi_i2s_set_config(CONFIG_I2S_SLAVE_BUS_ID, &config);

    osal_printk("i2s slave read start!\r\n");
    uapi_i2s_read_start(CONFIG_I2S_SLAVE_BUS_ID);

    return NULL;
}

static void i2s_slave_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "I2sSlaveTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = I2S_TASK_STACK_SIZE;
    attr.priority = I2S_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)i2s_slave_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the i2s_slave_entry. */
app_run(i2s_slave_entry);