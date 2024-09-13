/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: I2S port for project
 * Author: @CompanyNameTag
 * Create: 2023-03-10
 */

#ifndef SIO_PORTING_H
#define SIO_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "chip_io.h"
#include "product.h"
#include "platform_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_sio SIO
 * @ingroup  drivers_port
 * @{
 */
#define I2S_S_CLK                       32000    /* unit: khz. */
#define FREQ_OF_NEED                    32       /* unit: khz. */
#define I2S_CR                          0x608
#define M_CLKEN0                        0x40
#define I2S_MCLK_DIV_NUM                2
#define I2S_CR_DIV_NUM_BIT              5
#define I2S_CR_DIV_NUM_LEN              4
#define I2S_CLKEN_BIT                   2
#define I2S_DUTY_CYCLE                  2
#define I2S_PARAM                       2
#define I2S_MCLK_DIV                    2
#define CONFIG_I2S_BUS_MAX_NUM          1
#define CONFIG_DATA_LEN_MAX             128

/**
 * @brief  Definition of the contorl ID of hal sio.
 */

typedef void (*i2s_irq_func_t)(void);

/**
 * @brief  Get the base address of a specified sio.
 * @param  [in]  bus PCM device to use.
 * @return The base address of specified sio.
 */
uintptr_t sio_porting_base_addr_get(sio_bus_t bus);

/**
 * @brief  Register hal funcs objects into hal_sio module.
 * @param  [in]  bus PCM device to use.
 */
void sio_porting_register_hal_funcs(sio_bus_t bus);

/**
 * @brief  Unregister hal funcs objects from hal_sio module.
 * @param  [in]  bus PCM device to use.
 */
void sio_porting_unregister_hal_funcs(sio_bus_t bus);

/**
 * @brief  Register the interrupt of sio.
 * @param  [in]  bus PCM device to use.
 */
void sio_porting_register_irq(sio_bus_t bus);

/**
 * @brief  Unregister the interrupt of sio.
 * @param  [in]  bus PCM device to use.
 */
void sio_porting_unregister_irq(sio_bus_t bus);

/**
 * @brief  The interrupt handler of sio0.
 */
void irq_sio0_handler(void);

/**
 * @brief  SIO clock.
 * @param  [in]  enable Enable or not.
 */
void sio_porting_clock_enable(bool enable);

/**
 * @brief  Get the BCLK Div number.
 * @param  [in]  data_width I2S data width.
 * @param  [in]  ch I2S transmission Channels Number.
 * @return The BCLK Div number.
 */
uint32_t sio_porting_get_bclk_div_num(uint8_t data_width, uint32_t ch);

/**
 * @brief  Config the pin mode.
 */
void sio_porting_i2s_pinmux(void);

#if defined(CONFIG_I2S_SUPPORT_QUERY_REGS)
/**
 * @brief  get sio all regs value.
 */
void sio_port_get_regs_value(sio_bus_t bus);
#endif

#if defined(CONFIG_I2S_SUPPORT_DMA)
/**
 * @brief  Get the src handshaking of dma.
 * @param  [in]  bus PCM/I2S device to use.
 */
uint32_t i2s_port_get_dma_trans_src_handshaking(sio_bus_t bus);

/**
 * @brief  Get the dest handshaking of dma.
 * @param  [in]  bus PCM/I2S device to use.
 */
uint32_t i2s_port_get_dma_trans_dest_handshaking(sio_bus_t bus);

/**
 * @brief  Get the tx merge addr of I2S.
 * @param  [in]  bus PCM/I2S device to use.
 */
uintptr_t i2s_porting_tx_merge_data_addr_get(sio_bus_t bus);

/**
 * @brief  Get the rx merge addr of I2S.
 * @param  [in]  bus PCM/I2S device to use.
 */
uintptr_t i2s_porting_rx_merge_data_addr_get(sio_bus_t bus);
#endif

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif