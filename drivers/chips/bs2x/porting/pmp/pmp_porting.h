/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pmp port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-26， Create file. \n
 */
#ifndef PMP_PORTING_H
#define PMP_PORTING_H

#include <stdint.h>
#include "arch_encoding.h"
#include "arch_barrier.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_port_pmp PMP
 * @ingroup  drivers_port
 * @{
 */

/**
 * @if Eng
 * @brief  Register hal funcs objects into hal_pmp module.
 * @else
 * @brief  将hal funcs对象注册到hal_module模块中
 * @endif
 */
void pmp_port_register_hal_funcs(void);

/**
 * @if Eng
 * @brief  Unregister hal funcs objects from hal_pmp module.
 * @else
 * @brief  从hal_pmp模块注销hal funcs对象
 * @endif
 */
void pmp_port_unregister_hal_funcs(void);

/**
 * @if Eng
 * @brief  reset pmp cfg regs.
 * @else
 * @brief  复位pmp寄存器，防止读出x态
 * @endif
 */
void uapi_pmp_reset_cfg(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
#endif