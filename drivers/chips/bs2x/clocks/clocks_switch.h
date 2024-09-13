/*
 * Copyright (c) @CompanyNameMagicTag 2020-2023. All rights reserved.
 * Description: SYSTEM CLOCKS SWITCH DRIVER
 * Author: @CompanyNameTag
 * Create: 2020-7-28
 */

#ifndef CLOCKS_SWITCH_H
#define CLOCKS_SWITCH_H

#include <stdint.h>
#include "clocks_types.h"

/** @addtogroup connectivity_drivers_non_os_clocks_core
 * @{
 */

#define SYSTICK_CLK     32768ULL            // System 32k clock.
#define TCXO_1X_CLK     32000000ULL         // System TCXO 1X 32M clock.
#define TCXO_2X_CLK     64000000ULL         // System TCXO 2X 64M clock.
#define RC_CLK          27120000ULL         // System RC 27.12M clock.

/**
 * @brief  Modules in the common crg.
 */
typedef enum {
    CLOCKS_CCRG_MODULE_MCU_CORE,
    CLOCKS_CCRG_MODULE_MCU_PERP_LS,
    CLOCKS_CCRG_MODULE_MCU_PERP_UART,
    CLOCKS_CCRG_MODULE_MCU_PERP_SPI,
    CLOCKS_CCRG_MODULE_NFC_SUB,
    CLOCKS_CCRG_MODULE_I2S,
    CLOCKS_CCRG_MODULE_XIP_QSPI,
    CLOCKS_CCRG_MODULE_MAX,
} clocks_ccrg_module_t;

/**
 * @brief  The clock source of the system.
 */
typedef enum {
    CLOCKS_CLK_SRC_RC,
    CLOCKS_CLK_SRC_TCXO,
    CLOCKS_CLK_SRC_TCXO_2X,
    CLOCKS_CLK_SRC_32K,
    CLOCKS_CLK_SRC_NONE,
    CLOCKS_CLK_SRC_MAX = CLOCKS_CLK_SRC_NONE,
} clocks_clk_src_t;

/**
 * @brief clock config struct type.
 */
typedef struct {
    clocks_clk_src_t clk_src;
    uint8_t clk_div;
} clocks_clk_cfg_t;

typedef void (* clock_switch_proc_func)(void);

/**
 * @brief config common crg module clock.
 * @param module  The clock module to config clock.
 * @param clk_src The clock source selected.
 * @param clk_div The clock frenquency div number.
 */
void system_ccrg_clock_config(clocks_ccrg_module_t module, clocks_clk_src_t clk_src, uint8_t clk_div);

/**
 * @brief Get clock module frequency.
 * @param module The clock module selected.
 * @return Return the clock frequency of clock module selected.
 */
uint32_t clocks_get_module_frequency(clocks_ccrg_module_t module);

/**
  * @}
  */
#endif
