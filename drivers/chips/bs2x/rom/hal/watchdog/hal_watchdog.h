/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides hal watchdog \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-26, Create file. \n
 */

#ifndef HAL_WATCHDOG_H
#define HAL_WATCHDOG_H

#include <stdint.h>
#include "common_def.h"
#include "errcode.h"
#include "watchdog_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_watchdog_api Watchdog
 * @ingroup  drivers_hal_watchdog
 * @{
 */

/**
 * @if Eng
 * @brief  Definition of the watchdog mode.
 * @else
 * @brief  watchdog模式的定义
 * @endif
 */
typedef enum hal_wdt_mode {
    HAL_WDT_MODE_RESET,                            /*!< @if Eng Will reset core instructions, when watchdog trigger
                                                        @else   当watchdog触发时，将重置核心指令 @endif */
    HAL_WDT_MODE_INTERRUPT                         /*!< @if Eng Will enter interrupt, when watchdog trigger.
                                                                If watchdog not kick in interrupt, core will reset
                                                        @else   当看门狗触发时，将进入中断。如果看门狗没有进入中断，
                                                                内核将复位。@endif */
} hal_wdt_mode_t;

/**
 * @if Eng
 * @brief  Watchdog timeout callback.
 * @param  [in]  param Parameters of the callback function.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t
 * @else
 * @brief  Watchdog超时回调
 * @param  [in]  param 回调函数的参数
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
typedef errcode_t (*hal_watchdog_callback_t)(uintptr_t param);

/**
 * @if Eng
 * @brief  Init device for hal watchdog.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t
 * @else
 * @brief  HAL层WATCHDOG的初始化接口
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
errcode_t hal_watchdog_init(void);

/**
 * @if Eng
 * @brief  Deinit device for hal watchdog.
 * @else
 * @brief  HAL层WATCHDOG的去初始化接口
 * @endif
 */
void hal_watchdog_deinit(void);

/**
 * @if Eng
 * @brief  Set the attribute for hal watchdog.
 * @param  [in]  timeout The watchdog_timeout, the timeout period has only 16 types.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t
 * @else
 * @brief  设置Watchdog的属性。
 * @param  [in]  timeout 超时时间,超时时间只有16种类型。
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t hal_watchdog_set_attr(uint32_t timeout);

/**
 * @if Eng
 * @brief  Get the attribute for hal watchdog.
 * @return The watchdog_timeout, the timeout period has only 16 types.
 * @else
 * @brief  获取Watchdog的属性。
 * @return 超时时间，超时时间只有16种类型。
 * @endif
 */
uint32_t hal_watchdog_get_attr(void);

/**
 * @if Eng
 * @brief  Enable device for hal watchdog.
 * @param  [in]  mode The watchdog_mode. see @ref hal_wdt_mode_t
 * @else
 * @brief  HAL层WATCHDOG的使能接口
 * @param  [in]  mode watchdog模式，参考 @ref hal_wdt_mode_t
 * @endif
 */
void hal_watchdog_enable(hal_wdt_mode_t mode);

/**
 * @if Eng
 * @brief  Disable device for hal watchdog.
 * @else
 * @brief  HAL层WATCHDOG去使能接口
 * @endif
 */
void hal_watchdog_disable(void);

/**
 * @if Eng
 * @brief  Kick watchdog interface for hal watchdog.
 * @else
 * @brief  HAL层喂狗接口
 * @endif
 */
void hal_watchdog_kick(void);

/**
 * @if Eng
 * @brief  Get the time left interface for hal watchdog.
 * @return Time left in number of clock cycles.
 * @retval 0        Failure.
 * @else
 * @brief  HAL层获取剩余时间接口
 * @return 时钟周期数的剩余时间， 成功
 * @retval  0        失败
 * @endif
 */
uint32_t hal_watchdog_get_left_time(void);

/**
 * @if Eng
 * @brief  Register callback interface for hal watchdog.
 * @param  [in]  callback Callback function.
 * @else
 * @brief  HAL层注册回调接口
 * @param  [in]  callback 回调函数
 * @endif
 */
void hal_register_watchdog_callback(hal_watchdog_callback_t callback);

/**
 * @if Eng
 * @brief  Init the watchdog which will set the base address of registers.
 * @retval ERRCODE_SUCC   Success
 * @retval ERRCODE_WDT_REG_ADDR_INVALID   Failure, see @ref errcode_t
 * @else
 * @brief  初始化watchdog，watchdog将设置寄存器的基址
 * @retval ERRCODE_SUCC   成功
 * @retval ERRCODE_WDT_REG_ADDR_INVALID   失败, 参考 @ref errcode_t
 * @endif
 */
errcode_t hal_watchdog_regs_init(void);

/**
 * @if Eng
 * @brief  Deinit the hal_watchdog which will clear the base address of registers has been set
 *         by @ref hal_watchdog_regs_init.
 * @else
 * @brief  去初始化hal_watchdog，这将清除被 @ref hal_watchdog_regs_init 已经设置的寄存器的基址
 * @endif
 */
void hal_watchdog_regs_deinit(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif