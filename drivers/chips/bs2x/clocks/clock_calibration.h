/*
 * Copyright (c) @CompanyNameMagicTag 2020-2023. All rights reserved.
 * Description:  CLOCK CALIBRATION DRIVER
 * Author: @CompanyNameTag
 * Create: 2020-03-17
 */

#ifndef CLOCK_CALIBRATION_H
#define CLOCK_CALIBRATION_H

#include <stdint.h>
#include <stdbool.h>
#include "soc_osal.h"
#include "platform_core.h"

/** @addtogroup connectivity_drivers_non_os_clocks_core
  * @{
  */
typedef enum {
    XO_CTRIM_DECIMAL_0FF    = 0,
    XO_CTRIM_DECIMAL_250FF  = 1,
    XO_CTRIM_DECIMAL_500FF  = 2,
    XO_CTRIM_DECIMAL_750FF  = 3,
    XO_CTRIM_DECIMAL_1000FF = 4,
    XO_CTRIM_DECIMAL_1250FF = 5,
    XO_CTRIM_DECIMAL_1500FF = 6,
    XO_CTRIM_DECIMAL_1750FF = 7,
} xo_ctrim_decimal_t;

/**
 * @brief  Get the calibration result of 32k clock with cali_cycle times.
 * @param  cali_cycle num of 32K detect cycles.
 * @return Calibration result of 32k.
 */
uint32_t calibration_get_clock_frq(uint16_t cali_cycle);

/**
 * @brief  Get the calibration result of 32k clock with 100 times.
 * @return Calibration result of 32k.
 */
uint32_t calibration_get_clock_frq_result(void);

/**
 * @brief  Get the XO(32M) ctrim value from efuse.
 * @param  xo_ctrim_value ctrim value.
 */
#ifdef XO_32M_CALI
void calibration_xo_core_ctrim_init(void);
void calibration_xo_core_ctrim_flash_init(void);
void calibration_xo_core_ctrim_save_flash(uint8_t xo_ctrim_value);
void calibration_xo_core_ctrim_read_flash(uint8_t *xo_ctrim_value);
void calibration_set_xo_core_ctrim(uint8_t xo_ctrim_value);
void calibration_save_xo_core_ctrim(uint8_t xo_ctrim_value);
void calibration_read_xo_core_ctrim(uint8_t *xo_ctrim_value);
void calibration_xo_core_ctrim_algorithm(bool increase, uint8_t step_num);
void calibration_get_xo_core_ctrim_reg(uint8_t *xo_ctrim_value);
#endif
/**
  * @}
  */
#endif
