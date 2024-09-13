/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides QDEC driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-01， Create file. \n
 */
#ifndef QDEC_H
#define QDEC_H

#include <stdint.h>
#include "errcode.h"
#include "hal_qdec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_qdec QDEC
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize the QDEC.
 * @param  [in]  config Pointer to the structure with the initial configuration.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  初始化QDEC。
 * @param  [in]  config 指向具有初始配置的结构体的指针。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_qdec_init(qdec_config_t const *config);

/**
 * @if Eng
 * @brief  Deinitialize the QDEC.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去初始化QDEC。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_qdec_deinit(void);

/**
 * @if Eng
 * @brief  Enable the QDEC.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  使能QDEC。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_qdec_enable(void);

/**
 * @if Eng
 * @brief  Disable the QDEC.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去使能QDEC。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_qdec_disable(void);

/**
 * @if Eng
 * @brief  Reading accumulated transitions from the QDEC peripheral.
 * @param  [out]  acc Number of registration cumulative valid conversions.
 * @param  [out]  accdbl Indicates the number of repeated conversions detected during registration.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  从QDEC外设读取累积转换。
 * @param  [out]  acc 注册累计有效转换的次数。
 * @param  [out]  accdbl 注册累计检测到重复转换的次数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_qdec_read_accumulators(int16_t *acc, int16_t *accdbl);

/**
 * @if Eng
 * @brief  Register QDEC callback function.
 * @param  [in]  callback The callback is called to handle the exception.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  QDEC回调注册。
 * @param  [in]  callback 调用回调来处理异常。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_qdec_register_callback(qdec_callback_t callback);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif