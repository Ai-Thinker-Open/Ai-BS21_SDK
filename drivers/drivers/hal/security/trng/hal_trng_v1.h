/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides trng v1 hal drivers header file\n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-05, Create file. \n
 */
#ifndef HAL_TRNG_V1_H
#define HAL_TRNG_V1_H

#include <stdint.h>
#include <stdbool.h>
#include "hal_trng.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_trng_v1_functions Funcs
 * @ingroup  drivers_hal_trng_v1
 * @{
 */

/**
 * @if Eng
 * @brief  Get trng v1 hal func.
 * @retval trng v1 hal func, see @ref hal_trng_funcs_t
 * @else
 * @brief  HAL层TRNG V1获取HAL函数接口
 * @retval TRNG V1 hal 函数指针, 参考 @ref hal_trng_funcs_t
 * @endif
 */
hal_trng_funcs_t *hal_trng_v1_get_funcs(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif