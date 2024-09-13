/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides trng hal funcs \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-05, Create file. \n
 */
#ifndef HAL_TRNG_H
#define HAL_TRNG_H

#include <stdio.h>
#include <stdint.h>
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_hal_trng_api Api
 * @ingroup  drivers_hal_trng
 * @{
 */

/**
 * @if Eng
 * @brief  Definition of trng output
 * @else
 * @brief  trng输出定义
 * @endif
 */
typedef struct {
    uint32_t trng_data_0;                   /*!< @if Eng trng output 0
                                                 @else trng输出0 @endif */
    uint32_t trng_data_1;                   /*!< @if Eng trng output 0
                                                 @else trng输出1 @endif */
    uint32_t trng_data_2;                   /*!< @if Eng trng output 0
                                                 @else trng输出2 @endif */
    uint32_t trng_data_3;                   /*!< @if Eng trng output 0
                                                 @else trng输出3 @endif */
} trng_data_t;

typedef struct {
    uint32_t sample_cycles;                 /*!< @if Eng trng output 0
                                                 @else 采样周期 @endif */
    uint32_t read_timeout;                  /*!< @if Eng read gate closure timeout
                                                 @else 读取超时门限 @endif */
    uint32_t sample_div;                    /*!< @if Eng trng sample div
                                                 @else 采样周期 @endif */
    uint32_t noise_blocks;                  /*!< @if Eng trng noise blocks
                                                 @else 噪声块大小 @endif */
    uint32_t data_blocks;                   /*!< @if Eng trng data blocks
                                                 @else 数据块大小 @endif */
} hal_trng_attr_t;

/**
 * @if Eng
 * @brief  Deinit device for hal trng.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  HAL层trng初始化接口
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
typedef errcode_t (*hal_trng_init_t)(void);

/**
 * @if Eng
 * @brief  DeInit device for hal trng.
 * @else
 * @brief  HAL层TRNG的去初始化接口
 * @endif
 */
typedef void (*hal_trng_deinit_t)(void);

/**
 * @if Eng
 * @brief  start interface for hal trng.
 * @param  [in]  trng_attr trng attribute cfg see @ref hal_trng_attr_t
 * @else
 * @brief  HAL层TRNG启动接口
 * @param  [in]  trng_attr trng配置属性， 参考 @ref hal_trng_attr_t
 * @endif
 */
typedef void (*hal_trng_start_t)(hal_trng_attr_t trng_attr);

/**
 * @if Eng
 * @brief  Get output trng data.
 * @param  [in] trng_data output data pointer, see @ref trng_data_t
 * @retval ERRCODE_SUCC success
 * @retval Other        fail，参考 @ref errcode_t
 * @else
 * @brief  HAL层TRNG获取随机数接口
 * @param  [in] trng_data 输出随机数指针, 参考 @ref trng_data_t
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
typedef errcode_t (*hal_trng_get_t)(trng_data_t *trng_data);

/**
 * @if Eng
 * @brief  Interface between pke driver and pke hal.
 * @else
 * @brief  Driver层TRNG和HAL层TRNG的接口
 * @endif
 */
typedef struct {
    hal_trng_init_t   init;               /*!< @if Eng Init pke interface.
                                               @else   HAL层TRNG的初始化接口 @endif */
    hal_trng_deinit_t deinit;             /*!< @if Eng Deinit pke interface.
                                               @else   HAL层TRNG去初始化接口 @endif */
    hal_trng_start_t  start;              /*!< @if Eng pke start interface.
                                               @else   HAL层TRNG启动接口 @endif */
    hal_trng_get_t get_trng;              /*!< @if Eng pke cfg interface.
                                               @else   HAL层TRNG获取数据接口 @endif */
} hal_trng_funcs_t;

/**
 * @if Eng
 * @brief  Register @ref hal_trng_funcs_t into the g_hal_trngs_funcs.
 * @param  [in]  funcs Interface between trng driver and trng hal.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  注册 @ref hal_trng_funcs_t 到 g_hal_trngs_funcs
 * @param  [in]  funcs Driver层TRNG和HAL层TRNG的接口实例
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
errcode_t hal_trng_register_funcs(hal_trng_funcs_t *funcs);

/**
 * @if Eng
 * @brief  Unregister @ref hal_trng_funcs_t from the g_hal_trngs_funcs.
 * @return ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  从g_hal_trngs_funcs注销 @ref hal_trng_funcs_t
 * @return ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
errcode_t hal_trng_unregister_funcs(void);

/**
 * @if Eng
 * @brief  Get interface between trng driver and trng hal, see @ref hal_trng_funcs_t.
 * @return Interface between trng driver and trng hal, see @ref hal_trng_funcs_t.
 * @else
 * @brief  获取Driver层TRNG和HAL层TRNG的接口实例，参考 @ref hal_trng_funcs_t.
 * @return Driver层TRNG和HAL层TRNG的接口实例，参考 @ref hal_trng_funcs_t.
 * @endif
 */
hal_trng_funcs_t *hal_trng_get_funcs(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif