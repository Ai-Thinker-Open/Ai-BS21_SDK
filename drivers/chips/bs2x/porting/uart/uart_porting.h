/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides uart port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-06， Create file. \n
 */
#ifndef UART_PORT_H
#define UART_PORT_H

#include <stdint.h>
#include <stdbool.h>
#include "platform_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_uart Uart
 * @ingroup  drivers_port
 * @{
 */

#ifdef SLEM_CARKEY
#define SW_UART_BAUDRATE 921600UL
#else
#define SW_UART_BAUDRATE 115200UL
#endif
#define UART_L_BAUDRATE  115200UL
#define UART_BUS_MAX_NUM UART_BUS_MAX_NUMBER

#define UART_SHADOW  YES
#define UART_DLF_SIZE  6
#define UART_FIFO_ENABLED  YES

#ifdef CONFIG_DRIVERS_USB_SERIAL_GADGET
typedef enum {
    USB_SERIAL,
    CHIP_UART
} uart_mode_t;
#endif

/**
 * @brief  Base address list for all of the IPs.
 */
extern const uintptr_t g_uart_base_addrs[UART_BUS_MAX_NUM];

/**
 * @brief  Register hal funcs objects into hal_uart module.
 */
void uart_port_register_hal_funcs(uart_bus_t bus);

/**
 * @brief  Get the bus clock of specified uart.
 * @param  [in]  bus The uart bus. see @ref uart_bus_t
 * @return The bus clock of specified uart.
 */
uint32_t uart_port_get_clock_value(uart_bus_t bus);

/**
 * @brief  Config the pinmux of the uarts above.
 */
void uart_port_config_pinmux(uart_bus_t bus);

/**
 * @brief  Register the interrupt of uarts.
 */
void uart_port_register_irq(uart_bus_t bus);

/**
 * @brief  unRegister the interrupt of uarts.
 */
void uart_port_unregister_irq(uart_bus_t bus);

/**
 * @brief  Handler of UART0 IRQ.
 */
void irq_uart0_handler(void);

/**
 * @brief  Handler of UART1 IRQ.
 */
void irq_uart1_handler(void);

/**
 * @brief  Handler of UART2 IRQ.
 */
void irq_uart2_handler(void);

void hal_uart_clear_pending(uart_bus_t uart);

/**
 * @brief Force trigger uart interrupt.
 */
void uart_port_set_pending_irq(uart_bus_t uart);
/**
 * @}
 */

uintptr_t uart_porting_base_addr_get(uart_bus_t bus);

#if defined(CONFIG_UART_SUPPORT_DMA)
/**
 * @brief  Get the DMA destination handshaking select of uart transfer.
 * @param  [in]  bus The uart bus. see @ref uart_bus_t
 * @return The DMA destination handshaking select of uart transfer.
 */
uint8_t uart_port_get_dma_trans_dest_handshaking(uart_bus_t bus);

/**
 * @brief  Get the DMA source handshaking select of uart transfer.
 * @param  [in]  bus The uart bus. see @ref uart_bus_t
 * @return The DMA source handshaking select of uart transfer.
 */
uint8_t uart_port_get_dma_trans_src_handshaking(uart_bus_t bus);
#if defined(CONFIG_UART_SUPPORT_INT_TRIGGER_DMA)
/**
 * @brief  uart irq enable.
 *
 * @param bus bus.
 */
void uart_porting_int_enable(uart_bus_t bus);

/**
 * @brief  uart irq disable.
 *
 * @param bus bus.
 */
void uart_porting_int_disable(uart_bus_t bus);
#endif  /* CONFIG_UART_SUPPORT_INT_TRIGGER_DMA */
#endif  /* CONFIG_UART_SUPPORT_DMA */

/**
 * @brief  uart lock.
 *
 * @param uart bus.
 */
uint32_t uart_porting_lock(uart_bus_t bus);

/**
 * @brief  uart unlock.
 *
 * @param uart bus.
 */
void uart_porting_unlock(uart_bus_t bus, uint32_t irq_sts);

/**
 * @brief  uart get pincfg.
 *
 * @param uart bus, pin_cfg ptr.
 */
uint32_t uart_update_pincfg(uart_bus_t bus, uint8_t uart_pin_id, uintptr_t *pin_cfg);

#ifdef SW_UART_DEBUG
void sw_debug_uart_init(uint32_t baud_rate);
void sw_debug_uart_deinit(void);
void sw_debug_set_uart_bus(uart_bus_t bus);
void print_str(const char *str, ...);
#endif

/**
 * @brief  UART clock enable or disable.
 * @param  [in]  bus The bus index of I2C.
 * @param  [in]  on Enable or disable.
 */
void uart_port_clock_enable(uart_bus_t bus, bool on);

#if defined(CONFIG_UART_SUPPORT_QUERY_REGS)
/**
 * @brief  get uart all regs value.
 */
void uart_port_get_regs_value(uart_bus_t bus);
#endif

/**
 * @brief  Exchange the uart pin's tx rx mode.
 * @param  [in]  bus The bus index of UART.
 * @param  [in]  ex_en Enable or disable.
 */
void uart_port_exchange_trx_mode(uart_bus_t bus, bool ex_en);

#ifdef CONFIG_DRIVERS_USB_SERIAL_GADGET
void uart_porting_switch_serial_mode(uart_mode_t mode);
#endif
#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
