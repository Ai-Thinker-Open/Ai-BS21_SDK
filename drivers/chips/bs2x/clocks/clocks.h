/*
 * Copyright (c) @CompanyNameMagicTag 2018-2023. All rights reserved.
 * Description:  CLOCKS DRIVER HEADER
 * Author: @CompanyNameTag
 * Create:
 */

#ifndef SRC_DRIVERS_NON_OS_SHARED_CLOCKS_H
#define SRC_DRIVERS_NON_OS_SHARED_CLOCKS_H

#include "std_def.h"

/** @defgroup connectivity_drivers_non_os_clocks CLOCKS
  * @ingroup  connectivity_drivers_non_os
  * @{
  */

#define RC_1X_DIV_CLK   1  // System RC 1X clock.
#define TCXO_1X_DIV_CLK 1  // System TCXO/1 clock.
#define TCXO_2X_DIV_CLK 2  // System TCXO/2 clock.

/**
 * @brief  Initialize the clocks with the given configuration.
 */
void clocks_init(void);

/**
 * @brief  Init some hardware confing about low power.
 */
void clocks_hardware_sub_init(void);

/**
 * @brief  Return the value of the tcxo clock.
 * @return value of the tcxo clock in Hz.
 */
uint32_t clocks_get_tcxo_clock(void);

/**
 * @brief  Return the value of the core clock.
 * @return value of the core clock in Hz.
 * @note   the value returned is the mid one between the maximum limit and lower not the instant one.
 */
uint32_t clocks_get_core_frequency(void);

/**
  * @}
  */
#endif
