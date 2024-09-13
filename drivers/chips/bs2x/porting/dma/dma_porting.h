/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides dma port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-10-16， Create file. \n
 */

#ifndef DMA_PORTING_H
#define DMA_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "dma.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_dma_v151 DMA V151
 * @ingroup  drivers_port_dma
 * @{
 */

#define S_DMA_CHANNEL_MAX_NUM    4  /*!< Max number of SM_DMA available. */
#define B_DMA_CHANNEL_MAX_NUM    8  /*!< Max number of M_DMA available. */

#define S_MGPIO33 33
#define S_MGPIO34 34

#define DMA_CHANNEL_MAX_NUM      (S_DMA_CHANNEL_MAX_NUM + B_DMA_CHANNEL_MAX_NUM)

/**
 * @brief  DMA channel ID.
 */
typedef enum {
    DMA_CHANNEL_0,    /*!< DMA channel 0. */
    DMA_CHANNEL_1,    /*!< DMA channel 1. */
    DMA_CHANNEL_2,    /*!< DMA channel 2. */
    DMA_CHANNEL_3,    /*!< DMA channel 3. */
    DMA_CHANNEL_4,    /*!< DMA channel 4. */
    DMA_CHANNEL_5,    /*!< DMA channel 5. */
    DMA_CHANNEL_6,    /*!< DMA channel 6. */
    DMA_CHANNEL_7,    /*!< DMA channel 7. */
    DMA_CHANNEL_NONE = DMA_CHANNEL_MAX_NUM
} dma_channel_t;

/**
 * @brief  DMA handshaking source select.
 */

typedef enum {
    /* MDMA */
    HAL_DMA_HANDSHAKING_I2C0_TX,
    HAL_DMA_HANDSHAKING_I2C0_RX,
    HAL_DMA_HANDSHAKING_I2C1_TX,
    HAL_DMA_HANDSHAKING_I2C1_RX,
    HAL_DMA_HANDSHAKING_MIC45_UPLINK_REQ,
    HAL_DMA_HANDSHAKING_QSPI0_RX,
    HAL_DMA_HANDSHAKING_UART_H0_TX,
    HAL_DMA_HANDSHAKING_UART_H0_RX,
    HAL_DMA_HANDSHAKING_UART_L0_TX,
    HAL_DMA_HANDSHAKING_UART_L0_RX,
    HAL_DMA_HANDSHAKING_UART_L1_TX = HAL_DMA_HANDSHAKING_UART_L0_TX,
    HAL_DMA_HANDSHAKING_UART_L1_RX = HAL_DMA_HANDSHAKING_UART_L0_RX,
    HAL_DMA_HANDSHAKING_SPI0_TX,
    HAL_DMA_HANDSHAKING_SPI0_RX,
    HAL_DMA_HANDSHAKING_SPI1_TX,
    HAL_DMA_HANDSHAKING_SPI1_RX,
    HAL_DMA_HANDSHAKING_SPI2_TX,
    HAL_DMA_HANDSHAKING_SPI2_RX,
    HAL_DMA_HANDSHAKING_I2S_TX = HAL_DMA_HANDSHAKING_SPI2_TX,
    HAL_DMA_HANDSHAKING_I2S_RX = HAL_DMA_HANDSHAKING_SPI2_RX,
    HAL_DMA_HANDSHAKING_MAX_NUM
} hal_dma_handshaking_source_t;

/**
 * @brief  DMA Hardshaking channel.
 */
typedef enum hal_dma_hardshaking_channel {
    HAL_DMA_HARDSHAKING_CHANNEL_0,
    HAL_DMA_HARDSHAKING_CHANNEL_1,
    HAL_DMA_HARDSHAKING_CHANNEL_2,
    HAL_DMA_HARDSHAKING_CHANNEL_3,
    HAL_DMA_HARDSHAKING_CHANNEL_4,
    HAL_DMA_HARDSHAKING_CHANNEL_5,
    HAL_DMA_HARDSHAKING_CHANNEL_6,
    HAL_DMA_HARDSHAKING_CHANNEL_7,
    HAL_DMA_HARDSHAKING_CHANNEL_MAX_NUM,
    HAL_DMA_HARDSHAKING_CHANNEL_NONE = HAL_DMA_HARDSHAKING_CHANNEL_MAX_NUM
} hal_dma_hardshaking_channel_t;

extern uintptr_t g_dma_base_addr;

/**
 * @brief  Register the interrupt of dma.
 */
void dma_port_register_irq(void);

/**
 * @brief  Unregister the interrupt of dma.
 */
void dma_port_unregister_irq(void);

/**
 * @brief  Set the channel status of handshaking.
 * @param  [in]  channel  The handshaking select. For details, see @ref hal_dma_handshaking_source_t.
 * @param  [in]  on  Set or clear.
 */
void dma_port_set_handshaking_channel_status(hal_dma_handshaking_source_t channel, bool on);

/**
 * @brief  add sleep veto before dma transfer.
 */
void dma_port_add_sleep_veto(void);

/**
 * @brief  remove sleep veto after dma transfer.
 */
void dma_port_remove_sleep_veto(void);

/**
 * @brief  dma clock enable.
 */
void dma_port_clock_enable(void);

/**
 * @brief  dma clock disable.
 */
void dma_port_clock_disable(void);

#if defined(CONFIG_DMA_SUPPORT_QUERY_REGS)
/**
 * @brief  get dma all regs value.
 */
void dma_port_get_regs_value(void);
#endif

/**
 * @brief  Release the channel source of handshaking.
 * @param  [in]  ch  The handshaking select. For details, see @ref dma_channel_t.
 */
void dma_port_release_handshaking_source(dma_channel_t ch);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif