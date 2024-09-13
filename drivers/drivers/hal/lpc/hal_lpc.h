/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:   Low Power controller HAL INTERFACE
 * Author: @CompanyNameTag
 * Create:  2018-10-15
 */

#ifndef HAL_LPC_H
#define HAL_LPC_H

#include "std_def.h"

/** @defgroup connectivity_drivers_hal_lpc LPC
  * @ingroup  connectivity_drivers_hal
  * @{
  */
typedef enum {
    HAL_LPC_SLEEP_MODE_LIGHT,
    HAL_LPC_SLEEP_MODE_DEEP,
} hal_lpc_sleep_mode_t; // Low Power Controller Sleep Modes

/**
 * @brief  Enter Wait for interrupt state
 */
void hal_lpc_enter_wfi(void);

/**
 * @brief  Set a type of sleep mode
 * @param  mode Sleep Mode
 * @note   It configures the appropriate values for LPC_CTRL and SCB->SCR registers
 */
void hal_lpc_set_sleep_mode(hal_lpc_sleep_mode_t mode);

/**
 * @brief  Set the sleep on exit
 * @param  sleep_on_exit uses (true) sleep on exit or not (false)
 */
void hal_lpc_set_sleep_on_exit(bool sleep_on_exit);

/**
  * @}
  */
#endif
