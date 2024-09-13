/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \nPDM
 *
 * Description: Provides PDM porting for SUSONG \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-31, Create file. \n
 */
#ifndef PDM_PORTING_H
#define PDM_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "common_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup device_susong_port_app_pdm PDM
 * @ingroup  device_susong_port_app
 * @{
 */

/**
 * @if Eng
 * @brief  Get the base address of a PDM.
 * @return The base address of PDM.
 * @else
 * @brief  获取指定PDM BUS的基地址。
 * @return PDM的基地址。
 * @endif
 */
uintptr_t pdm_porting_base_addr_get(void);

/**
 * @if Eng
 * @brief  Enable or disable the clock of PDM.
 * @param  [in]  en Enable or disale.
 * @else
 * @brief  使能或去使能PDM的时钟。
 * @param  [in]  en 使能或者去使能。
 * @endif
 */
void pdm_port_clock_enable(bool en);

/**
 * @if Eng
 * @brief  Register hal funcs objects into hal_pdm module.
 * @else
 * @brief  注册HAL层实例到hal_pdm模块。
 * @endif
 */
void pdm_port_register_hal_funcs(void);

/**
 * @if Eng
 * @brief  Unregister hal funcs objects from hal_pdm module.
 * @else
 * @brief  从hal_pdm模块注销HAL层实例。
 * @endif
 */
void pdm_port_unregister_hal_funcs(void);

#if defined(CONFIG_PDM_SUPPORT_QUERY_REGS)
/**
 * @brief  get pdm all regs value.
 */
void pdm_port_get_regs_value(void);
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