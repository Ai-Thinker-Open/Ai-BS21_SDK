/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides EDGE driver api. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-12-02, Create file. \n
 */

#ifndef EDGE_H
#define EDGE_H

#include <stdint.h>
#include "errcode.h"
#include "hal_edge.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_edge EDGE
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  EDGE configuration parameters, see @ref hal_edge_param_t.
 * @else
 * @brief  EDGE配置参数，参考 @ref hal_edge_param_t 。
 * @endif
 */
typedef hal_edge_param_t edge_param_t;

/**
 * @if Eng
 * @brief  Initialize the EDGE module.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @note   This function should be called before any other on in the module.
 * @else
 * @brief  初始化EDGE模块。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @note   此初始化函数应该在所有函数之前执行。
 * @endif
 */
errcode_t uapi_edge_init(void);

/**
 * @if Eng
 * @brief  Deinitialize the EDGE module.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去初始化EDGE模块。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_edge_deinit(void);

/**
 * @if Eng
 * @brief  Activate the EDGE, configure parameters and register the callback function for the specified EDGE.
 * @param  [in]  edge EDGE ID.
 * @param  [in]  param EDGE Param, see @ref edge_param_t.
 * @param  [in]  callback Pointer to callback, see @ref edge_callback_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  激活EDGE，并为其配置检测参数，注册回调函数。
 * @param  [in]  edge EDGE ID。
 * @param  [in]  param EDGE配置参数，参考 @ref edge_param_t 。
 * @param  [in]  callback 指向回调的指针，参考 @ref edge_callback_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_edge_activate(uint8_t edge, edge_param_t *param, edge_callback_t callback);

/**
 * @if Eng
 * @brief  Deactivate the EDGE, clear configuration and unregister the callback function.
 * @param  [in]  edge EDGE ID.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去激活EDGE，清除参数配置，去注册回调函数。
 * @param  [in]  edge EDGE ID。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_edge_deactivate(uint8_t edge);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
