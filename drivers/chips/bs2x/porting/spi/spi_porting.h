/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides spi porting template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-18， Create file. \n
 */
#ifndef SPI_PORTING_H
#define SPI_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "platform_core.h"
#include "hal_spi_v151_regs_def.h"
#if defined(CONFIG_SPI_SUPPORT_DMA) && (CONFIG_SPI_SUPPORT_DMA == 1)
#include "dma_porting.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_spi SPI
 * @ingroup  drivers_port
 * @{
 */

#define SPI_CLK_FREQ        32000000

#define SPI_BUS_MAX_NUM SPI_BUS_MAX_NUMBER
#define CONFIG_SPI_MAX_TIMEOUT 0xFFFFFFFF

#if defined(CONFIG_SPI_SUPPORT_DMA) && (CONFIG_SPI_SUPPORT_DMA == 1)
#define DMA_HANDSHAKE_SPI_BUS_0_TX HAL_DMA_HANDSHAKING_SPI0_TX
#define DMA_HANDSHAKE_SPI_BUS_0_RX HAL_DMA_HANDSHAKING_SPI0_RX
#define DMA_HANDSHAKE_SPI_BUS_1_TX HAL_DMA_HANDSHAKING_SPI1_TX
#define DMA_HANDSHAKE_SPI_BUS_1_RX HAL_DMA_HANDSHAKING_SPI1_RX
#define DMA_HANDSHAKE_SPI_BUS_2_TX HAL_DMA_HANDSHAKING_SPI2_TX
#define DMA_HANDSHAKE_SPI_BUS_2_RX HAL_DMA_HANDSHAKING_SPI2_RX

/**
 * @brief  Spi dma control register.
 */
typedef enum {
    HAL_SPI_DMA_CONTROL_DISABLE = 0,        //!< Disables the transmit fifo and the receive fifo dma channel.
    HAL_SPI_DMA_CONTROL_RX_ENABLE = 1,      //!< Enables the receive fifo dma channel.
    HAL_SPI_DMA_CONTROL_TX_ENABLE = 2,      //!< Enables the transmit fifo dma channel.
    HAL_SPI_DMA_CONTROL_TXRX_ENABLE = 3,    //!< Enables the transmit fifo and the receive fifo dma channel.
    HAL_SPI_DMA_CONTROL_MAX_NUM,
    HAL_SPI_DMA_CONTROL_NONE = HAL_SPI_DMA_CONTROL_MAX_NUM,
} hal_spi_dma_control_t;
#endif

/**
 * @brief  SPI mode.
 */
typedef enum spi_mode {
    SPI_MODE_MASTER,        /*!< SPI Master mode. */
    SPI_MODE_SLAVE,         /*!< SPI Slave mode. */
    SPI_MODE_MAX_NUM,
    SPI_MODE_NONE = SPI_MODE_MAX_NUM
} spi_mode_t;

/**
 * @brief  SPI mode.
 */
typedef enum spi_line_mode {
    SPI_LINE_MODE_3,        /*!< SPI Master mode. */
    SPI_LINE_MODE_4,         /*!< SPI Slave mode. */
    SPI_LINE_MODE_MAX_NUM,
    SPI_LINE_MODE_NONE = SPI_LINE_MODE_MAX_NUM
} spi_line_mode_t;

/**
 * @brief  SPI slave select.
 */
typedef enum spi_slave {
    SPI_SLAVE0 = 0,         /*!< SPI Slave index 0. */
    SPI_SLAVE1,             /*!< SPI Slave index 1. */
    SPI_SLAVE_MAX_NUM,
    SPI_SLAVE_NONE = SPI_SLAVE_MAX_NUM
} spi_slave_t;

/**
 * @brief  Base address list for all of the IPs.
 */
extern spi_v151_regs_t * g_spi_base_addrs[SPI_BUS_MAX_NUM];

/**
 * @brief  Get the base address of specified spi.
 * @param  [in]  bus The bus index of SPI.
 * @return The base address of specified spi.
 */
uintptr_t spi_porting_base_addr_get(spi_bus_t bus);

/**
 * @brief  Get the max slave number can be selected.
 * @param  [in]  bus The bus index of SPI.
 * @return The  max slave number can be selected.
 */
uint32_t spi_porting_max_slave_select_get(spi_bus_t bus);

/**
 * @brief  Set the spi work mode.
 * @param  [in]  bus The bus index of SPI.
 * @param  [in]  mode The mode of SPI.
 */
void spi_porting_set_device_mode(spi_bus_t bus, spi_mode_t mode);

/**
 * @brief  Set the spi work mode.
 * @param  [in]  bus The bus index of SPI.
 * @param  [in]  mode The mode of SPI.
 */
void spi_porting_set_sspi_mode(spi_bus_t bus, bool val);

/**
 * @brief  Set the spi work mode.
 * @param  [in]  bus The bus index of SPI.
 * @param  [in]  mode The mode of SPI.
 */
void spi_porting_set_sspi_waite_cycle(spi_bus_t bus, uint32_t waite_cycle);

/**
 * @brief  Get the spi work mode.
 * @param  [in]  bus The bus index of SPI.
 * @return The mode of SPI.
 */
spi_mode_t spi_porting_get_device_mode(spi_bus_t bus);

/**
 * @brief  Set the spi recieve data number.
 * @param  [in]  bus The bus index of SPI.
 * @param  [in]  number recieve data number of SPI.
 * @return The mode of SPI.
 */
void spi_porting_set_rx_mode(spi_bus_t bus, uint16_t num);

/**
 * @brief  Set the spi mode tx.
 * @param  [in]  bus The bus index of SPI.
 * @return The mode of SPI.
 */
void spi_porting_set_tx_mode(spi_bus_t bus);

/**
 * @brief  Set the spi mode txrx.
 * @param  [in]  bus The bus index of SPI.
 * @return The mode of SPI.
 */
void spi_porting_set_txrx_mode(spi_bus_t bus);

/**
 * @brief  SPI lock.
 * @param [in]  bus The bus index of SPI.
 * @return The irq lock number of SPI.
 */
uint32_t spi_porting_lock(spi_bus_t bus);

/**
 * @brief  SPI unlock.
 * @param [in]  bus The bus index of SPI.
 * @param [in]  irq_sts The irq lock number of SPI.
 */
void spi_porting_unlock(spi_bus_t bus, uint32_t irq_sts);

#if defined(CONFIG_SPI_SUPPORT_INTERRUPT) && (CONFIG_SPI_SUPPORT_INTERRUPT == 1)
/**
 * @brief  Register the interrupt of spis.
 * @param  [in]  bus The bus index of SPI.
 */
void spi_port_register_irq(spi_bus_t bus);

/**
 * @brief  unRegister the interrupt of spis.
 * @param  [in]  bus The bus index of SPI.
 */
void spi_port_unregister_irq(spi_bus_t bus);
#endif

#if defined(CONFIG_SPI_SUPPORT_DMA) && (CONFIG_SPI_SUPPORT_DMA == 1)
/**
 * @brief  Get the DMA destination handshaking select of SPI transfer.
 * @param  [in]  bus The SPI bus. see @ref spi_bus_t
 * @return The DMA destination handshaking select of spi transfer.
 */
uint8_t spi_port_get_dma_trans_dest_handshaking(spi_bus_t bus);

/**
 * @brief  Get the DMA source handshaking select of SPI transfer.
 * @param  [in]  bus The SPI bus. see @ref spi_bus_t
 * @return The DMA source handshaking select of SPI transfer.
 */
uint8_t spi_port_get_dma_trans_src_handshaking(spi_bus_t bus);

/**
 * @brief  Get the SPI DMA TX level.
 * @param  [in]  bus The SPI bus. see @ref spi_bus_t
 * @return The SPI DMA TX level.
 */
uint8_t spi_port_tx_data_level_get(spi_bus_t bus);

/**
 * @brief  Get the SPI DMA RX level of SPI transfer.
 * @param  [in]  bus The SPI bus. see @ref spi_bus_t
 * @return The SPI DMA RX level.
 */
uint8_t spi_port_rx_data_level_get(spi_bus_t bus);
#endif

/**
 * @brief  SPI clock enable or disable.
 * @param  [in]  bus The bus index of I2C.
 * @param  [in]  on Enable or disable.
 */
void spi_port_clock_enable(spi_bus_t bus, bool on);

#if defined(CONFIG_SPI_SUPPORT_QUERY_REGS)
/**
 * @brief  get spi all regs value.
 */
void spi_port_get_regs_value(spi_bus_t bus);
#endif

#if defined(CONFIG_SPI_SUPPORT_SINGLE_SPI)
bool spi_porting_is_sspi_mode(spi_bus_t bus);
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
