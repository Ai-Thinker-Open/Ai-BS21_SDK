/*
 * Copyright (c) @CompanyNameMagicTag 2020-2023. All rights reserved.
 * Description:  HAL 32K CALIBRATION DRIVER
 * Author: @CompanyNameTag
 * Create: 2020-03-17
 */

#ifndef HAL_32K_CLOCK_H
#define HAL_32K_CLOCK_H

#include "std_def.h"
#include "platform_core.h"
/** @defgroup connectivity_drivers_hal_32k 32K Clock
  * @ingroup  connectivity_drivers_hal
  * @{
  */

/**
 * @brief  Enable 32k clock detect
 */
void hal_32k_clock_calibration_enable(void);

/**
 * @brief  Disable 32k clock detect
 */
void hal_32k_clock_calibration_disable(void);

/**
 * @brief  Set the 32k clock calibration cycle
 * @param  det_val Calibration cycle
 */
void hal_32k_clock_calibration_cycle_config(uint16_t det_val);

/**
 * @brief  Read the detect result register
 * @return  Detect result register value
 */
uint32_t hal_read_32k_clock_detect_result_reg(void);

/**
 * @brief  Enable the 32K clock detect and get detect result
 * @return Detect result
 */
uint32_t hal_32k_clock_get_detect_result(void);

/**
  * @}
  */
#endif
