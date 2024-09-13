/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides hal keyscan \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16， Create file. \n
 */
#ifndef HAL_KEYSCAN_H
#define HAL_KEYSCAN_H

#include <stdint.h>
#include "errcode.h"
#include "keyscan_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_keyscan_api Keyscan
 * @ingroup  drivers_hal_keyscan
 * @{
 */

/**
 * @if Eng
 * @brief  Whether report status is release, press or error.
 * @else
 * @brief  上报的状态是释放、按下还是还是。
 * @endif
 */
typedef enum {
    KEY_RELEASE,                    /*!< @if Eng KEYSCAN release.
                                         @else   KEYSCAN按键状态为释放 @endif */
    KEY_PRESS,                      /*!< @if Eng KEYSCAN press.
                                         @else   KEYSCAN按键状态为按下 @endif */
    KEY_ERROR                       /*!< @if Eng KEYSCAN ERROR.
                                         @else   KEYSCAN按键超出键盘范围 @endif */
} key_value_report_status_t;

/**
 * @if Eng
 * @brief  Definition of keyscan callback type.
 * @param  [in]  argc Number of parameters.
 * @param  [in]  argv All input parameters.
 * @retval 0            Success.
 * @retval Other        Failure.
 * @else
 * @brief  Key_scan回调类型的定义。
 * @param  [in]  argc 参数的数目。
 * @param  [in]  argv 所有输入的参数。
 * @retval 0            成功。
 * @retval Other        失败。
 * @endif
 */
typedef int (*keyscan_report_callback_t)(int argc, uint8_t *argv);

/**
 * @if Eng
 * @brief  Callback of keyscanfor hal keyscan.
 * @param  [in]  key_value Number of key value.
 * @else
 * @brief  HAL层keyscan回调函数。
 * @param  [in]  key_value 待处理的键值。
 * @endif
 */
typedef void (*hal_keyscan_callback_t)(uint16_t key_value);

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
void hal_keyscan_init(keyscan_pulse_time_t time, keyscan_mode_t mode, keyscan_int_t event_type,
                      hal_keyscan_callback_t callback);

/**
 * @if Eng
 * @brief  Deinitialize device for hal keyscan.
 * @else
 * @brief  HAL层keyscan的去初始化接口。
 * @endif
 */
void hal_keyscan_deinit(void);

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
errcode_t hal_keyscan_enable(void);

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
errcode_t hal_keyscan_disable(void);

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
errcode_t hal_keyscan_suspend(uintptr_t arg);

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
errcode_t hal_keyscan_resume(uintptr_t arg);
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
