/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides v150 hal keyscan \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16， Create file. \n
 */
#ifndef HAL_KEYSCAN_V150_H
#define HAL_KEYSCAN_V150_H

#include "hal_keyscan.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_keyscan_v150 Keyscan V150
 * @ingroup  drivers_hal_keyscan
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize device for hal keyscan.
 * @param  [in]  time Scan time of the keyscan.
 * @param  [in]  mode Scan mode of the keyscan.
 * @param  [in]  event_type Intterrupt type of the keyscan.
 * @param  [in]  callback Callback of the hal keyscan.
 * @else
 * @brief  HAL层keyscan的初始化接口。
 * @param  [in]  time keyscan配置扫描时长。
 * @param  [in]  mode keyscan配置扫描模式。
 * @param  [in]  event_type keyscan配置中断类型。
 * @param  [in]  callback 回调函数。
 * @endif
 */
void hal_keyscan_v150_init(keyscan_pulse_time_t time, keyscan_mode_t mode, keyscan_int_t event_type,
                           hal_keyscan_callback_t callback);

/**
 * @if Eng
 * @brief  Deinitialize device for hal keyscan.
 * @else
 * @brief  HAL层keyscan的去初始化接口。
 * @endif
 */
void hal_keyscan_v150_deinit(void);

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
errcode_t hal_keyscan_v150_enable(void);

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
errcode_t hal_keyscan_v150_disable(void);

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
errcode_t hal_keyscan_v150_suspend(uintptr_t arg);

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
errcode_t hal_keyscan_v150_resume(uintptr_t arg);
#endif

/**
 * @if Eng
 * @brief  Handler of the keyscan interrupt request.
 * @else
 * @brief  KEYSCAN中断处理函数。
 * @endif
 */
void hal_keyscan_v150_irq(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif