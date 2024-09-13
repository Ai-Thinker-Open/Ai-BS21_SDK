/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: SPI Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-06-25, Create file. \n
 */
#include "pinctrl.h"
#include "spi.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"

#define SPI_SLAVE_NUM                   1
#define SPI_FREQUENCY                   2
#define SPI_CLK_POLARITY                0
#define SPI_CLK_PHASE                   0
#define SPI_FRAME_FORMAT                0
#define SPI_FRAME_FORMAT_STANDARD       0
#define SPI_FRAME_SIZE_8                0x1f
#define SPI_TMOD                        0
#define SPI_WAIT_CYCLES                 0x10

#define SPI_TASK_STACK_SIZE             0x1000
#define SPI_TASK_DURATION_MS            1000
#define SPI_TASK_PRIO                   (osPriority_t)(17)

static void app_spi_init_pin(void)
{
    if (CONFIG_SPI_MASTER_BUS_ID == 0) {
        uapi_pin_set_mode(CONFIG_SPI_DI_MASTER_PIN, HAL_PIO_SPI0_RXD);
        uapi_pin_set_mode(CONFIG_SPI_DO_MASTER_PIN, HAL_PIO_SPI0_TXD);
        uapi_pin_set_mode(CONFIG_SPI_CLK_MASTER_PIN, HAL_PIO_SPI0_SCLK);
        uapi_pin_set_mode(CONFIG_SPI_CS_MASTER_PIN, HAL_PIO_SPI0_CS0);      
    }else if (CONFIG_SPI_MASTER_BUS_ID == 1) {
        uapi_pin_set_mode(CONFIG_SPI_DI_MASTER_PIN, HAL_PIO_SPI1_RXD);
        uapi_pin_set_mode(CONFIG_SPI_DO_MASTER_PIN, HAL_PIO_SPI1_TXD);
        uapi_pin_set_mode(CONFIG_SPI_CLK_MASTER_PIN, HAL_PIO_SPI1_CLK);
        uapi_pin_set_mode(CONFIG_SPI_CS_MASTER_PIN, HAL_PIO_SPI1_CS0);     
    }else if (CONFIG_SPI_MASTER_BUS_ID == 2) {
        uapi_pin_set_mode(CONFIG_SPI_DI_MASTER_PIN, HAL_PIO_SPI2_RXD);
        uapi_pin_set_mode(CONFIG_SPI_DO_MASTER_PIN, HAL_PIO_SPI2_TXD);
        uapi_pin_set_mode(CONFIG_SPI_CLK_MASTER_PIN, HAL_PIO_SPI2_CLK);
        uapi_pin_set_mode(CONFIG_SPI_CS_MASTER_PIN, HAL_PIO_SPI2_CS0);         
    }
}

static void app_spi_master_init_config(void)
{
    spi_attr_t config = { 0 };
    spi_extra_attr_t ext_config = { 0 };

    config.is_slave = false;
    config.slave_num = SPI_SLAVE_NUM;
    config.bus_clk = SPI_CLK_FREQ;
    config.freq_mhz = SPI_FREQUENCY;
    config.clk_polarity = SPI_CLK_POLARITY;
    config.clk_phase = SPI_CLK_PHASE;
    config.frame_format = SPI_FRAME_FORMAT;
    config.spi_frame_format = HAL_SPI_FRAME_FORMAT_STANDARD;
    config.frame_size = SPI_FRAME_SIZE_8;
    config.tmod = SPI_TMOD;
    config.sste = 1;

    ext_config.qspi_param.wait_cycles = SPI_WAIT_CYCLES;
    uapi_spi_init(CONFIG_SPI_MASTER_BUS_ID, &config, &ext_config);
}

static void *spi_master_task(const char *arg)
{
    unused(arg);
    /* SPI pinmux. */
    app_spi_init_pin();

    /* SPI master init config. */
    app_spi_master_init_config();

    /* SPI data config. */
    uint8_t tx_data[CONFIG_SPI_TRANSFER_LEN] = { 0 };
    for (uint32_t loop = 0; loop < CONFIG_SPI_TRANSFER_LEN; loop++) {
        tx_data[loop] = (loop & 0xFF);
    }
    uint8_t rx_data[CONFIG_SPI_TRANSFER_LEN] = { 0 };
    spi_xfer_data_t data = {
        .tx_buff = tx_data,
        .tx_bytes = CONFIG_SPI_TRANSFER_LEN,
        .rx_buff = rx_data,
        .rx_bytes = CONFIG_SPI_TRANSFER_LEN,
    };

    while (1) {
        osDelay(SPI_TASK_DURATION_MS);
        osal_printk("spi%d master send start!\r\n", CONFIG_SPI_MASTER_BUS_ID);
        if (uapi_spi_master_write(CONFIG_SPI_MASTER_BUS_ID, &data, 0xFFFFFFFF) == ERRCODE_SUCC) {
            osal_printk("spi%d master send succ!\r\n", CONFIG_SPI_MASTER_BUS_ID);
        } else {
            continue;
        }
        osal_printk("spi%d master receive start!\r\n", CONFIG_SPI_MASTER_BUS_ID);
        if (uapi_spi_master_read(CONFIG_SPI_MASTER_BUS_ID, &data, 0xFFFFFFFF) == ERRCODE_SUCC) {
            for (uint32_t i = 0; i < data.rx_bytes; i++) {
                osal_printk("spi%d master receive data is %x\r\n", CONFIG_SPI_MASTER_BUS_ID, data.rx_buff[i]);
            }
            osal_printk("spi%d master receive succ!\r\n", CONFIG_SPI_MASTER_BUS_ID);
        }
    }

    return NULL;
}

static void spi_master_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "SpiMasterTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = SPI_TASK_STACK_SIZE;
    attr.priority = SPI_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)spi_master_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the spi_master_entry. */
app_run(spi_master_entry);