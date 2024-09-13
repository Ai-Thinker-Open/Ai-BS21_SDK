/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V150 systick register operation api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-01， Create file. \n
 */
#ifndef HAL_SYSTICK_V150_REGS_OP_H
#define HAL_SYSTICK_V150_REGS_OP_H

#include <stdint.h>
#include "hal_systick_v150_regs_def.h"
#include "systick_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_systick_v150_regs_op Systick V150 Regs Operation
 * @ingroup  drivers_hal_systick
 * @{
 */

/**
 * @brief  The registers list about value.
 */
typedef enum systick_value_reg {
    VALUE0,                    /*!< value0 register. */
    VALUE1,                    /*!< value1 register. */
    VALUE2,                    /*!< value2 register. */
    VALUE3                     /*!< value3 register. */
} systick_value_reg_t;

extern systick_regs_t *g_systick_regs;

/**
 * @brief  Init the systick which will set the base address of registers.
 */
void hal_systick_v150_regs_init(void);

/**
 * @brief  Deinit the hal_systick which will clear the base address of registers has been
 *         set by @ref hal_systick_v150_regs_init.
 */
void hal_systick_v150_regs_deinit(void);

/**
 * @brief  Get the value of value.
 * @return  The value of value.
 */
uint64_t hal_systick_reg_count_get(void);

/**
 * @brief  Get the value of @ref cfg_data_t.clr.
 * @return The value of @ref cfg_data_t.clr.
 */
static inline uint32_t hal_systick_reg_cfg_get_clr(void)
{
    cfg_data_t cfg;
    cfg.d32 = g_systick_regs->cfg;
    return cfg.b.clr;
}

/**
 * @brief  Set the value of @ref cfg_data_t.stz.
 * @param  [in]  val The value of @ref cfg_data_t.stz
 */
static inline void hal_systick_reg_cfg_set_stz(uint32_t val)
{
    cfg_data_t cfg;
    cfg.d32 = g_systick_regs->cfg;
    cfg.b.stz = val;
    g_systick_regs->cfg = cfg.d32;
}

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif