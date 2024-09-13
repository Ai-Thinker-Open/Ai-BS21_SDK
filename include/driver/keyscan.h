/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides Keyscan driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-15, Create file. \n
 */
#ifndef KEYSCAN_H
#define KEYSCAN_H

#include <stdint.h>
#include "errcode.h"
#include "hal_keyscan.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_keyscan Keyscan
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize the Keyscan.
 * @param  [in]  time Scan time of the Keyscan.
 * @param  [in]  mode Scan mode of the Keyscan.
 * @param  [in]  event_type Interrupt type of the Keyscan.
 * @else
 * @brief  初始化Keyscan。
 * @param  [in]  time Keyscan配置扫描时长。
 * @param  [in]  mode Keyscan配置扫描模式。
 * @param  [in]  event_type Keyscan配置中断类型。
 * @endif
 */
void uapi_keyscan_init(keyscan_pulse_time_t time, keyscan_mode_t mode, keyscan_int_t event_type);

/**
 * @if Eng
 * @brief  Deinitialize Keyscan.
 * @else
 * @brief  去初始化Keyscan。
 * @endif
 */
void uapi_keyscan_deinit(void);

/**
 * @if Eng
 * @brief  Enable Keyscan.
 * @retval ERRCODE_KEYSCAN_POWER_ON. Success of powered on.
 * @retval Other             Failure. For details, see @ref errcode_t.
 * @else
 * @brief  使能Keyscan。
 * @retval ERRCODE_KEYSCAN_POWER_ON  上电成功。
 * @retval Other                     失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_keyscan_enable(void);

/**
 * @if Eng
 * @brief  Disable Keyscan.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去使能Keyscan。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_keyscan_disable(void);

/**
 * @if Eng
 * @brief  Register callback for Keyscan.
 * @param  [in]  callback Pointer to the Keyscan repoter callback.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册Keyscan的回调。
 * @param  [in]  callback Keyscan的回调函数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_keyscan_register_callback(keyscan_report_callback_t callback);

/**
 * @if Eng
 * @brief  Unregister callback for Keyscan.
 * @param  [in]  callback Pointer to the Keyscan repoter callback.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去注册Keyscan的回调。
 * @param  [in]  callback Keyscan回调函数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_keyscan_unregister_callback(keyscan_report_callback_t callback);

/**
 * @if Eng
 * @brief Set the Keyscan value map.
 * @param [in]  map_addr  The Keyscan value map address.
 * @param [in]  row Number of rows in the keyboard matrix.
 * @param [in]  col Number of columns in the keyboard matrix.
 * @note  If the row and column of the used matrix are smaller than the specified maximum value,
 *        use 0x0 to fill the left bits. \n
 *        If the row and column of the used matrix are larger than the specified maximum value, an error is reported.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief 设置Keyscan的键值矩阵。
 * @param [in]  map_addr 键值矩阵地址。
 * @param [in]  row 键值矩阵的行数。
 * @param [in]  col 键值矩阵的列数。
 * @note  如果使用的矩阵行列小于指定的最大值，使用0x0填充空余位，若大于指定的最大值，则报错。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_set_keyscan_value_map(uint8_t **map_addr, uint16_t row, uint8_t col);

#if defined (CONFIG_KEYSCAN_SUPPORT_LPM)
/**
 * @if Eng
 * @brief  Suspend all of the keyscan channels.
 * @param  [in]  arg Argument for suspend.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  挂起所有Keyscan通道。
 * @param  [in]  arg 挂起所需要的参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_keyscan_suspend(uintptr_t arg);

/**
 * @if Eng
 * @brief  Resume all of the keyscan channels.
 * @param  [in]  arg Argument for resume.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  恢复所有Keyscan通道。
 * @param  [in]  arg 恢复所需要的参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_keyscan_resume(uintptr_t arg);
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