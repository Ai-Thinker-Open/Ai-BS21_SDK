
/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm sys API \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-11-28， Create file. \n
 */

#ifndef PM_SYS_H
#define PM_SYS_H

#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_chips_pm_sys PM sys
 * @ingroup  middleware_chips_pm
 * @{
 */

typedef int32_t (*pm_state_trans_func_t)(uintptr_t arg);

typedef struct pm_state_trans_handler {
    pm_state_trans_func_t work_to_standby;     /* 工作态转换到待机状态（如interval调大） */
    pm_state_trans_func_t standby_to_sleep;    /* 工作态转换到深睡状态（如断连、关广播） */
    pm_state_trans_func_t standby_to_work;     /* 待机态转换到工作状态（如interval调小） */
    pm_state_trans_func_t sleep_to_work;       /* 深睡态转换到工作状态（如开广播） */
} pm_state_trans_handler_t;

/**
 * @if Eng
 * @brief  Register the low-power state management interface.
 * @param  [inout]  handler Handler for processing state transfer.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  注册低功耗状态管理接口。
 * @param  [inout]  handler 状态转移处理句柄。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。 参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_state_trans_handler_register(pm_state_trans_handler_t *handler);

/**
 * @if Eng
 * @brief  Setting the low-power duration between state transition.
 * @param  [in]  work_to_standby  Duration from work to standby, the unit: ms.
 * @param  [in]  standby_to_sleep Duration from standby to sleep, the unit: ms.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  设置低功耗状态转移间的时间。
 * @param  [in]  work_to_standby  从工作到待机的时间，单位：ms。
 * @param  [in]  standby_to_sleep 从待机到睡眠的时间，单位：ms。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。 参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_set_state_trans_duration(uint32_t work_to_standby, uint32_t standby_to_sleep);

/**
 * @if Eng
 * @brief  Reset the working status. In this way, the timer from work to standby is reset.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  重置工作状态，从而重置工作到待机的计时器。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。 参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_work_state_reset(void);

/**
 * @if Eng
 * @brief  Low-power wakeup processing, which is called when the peripheral wakes up to restore the working state.
 * @param  [in]  arg  This parameter is used to extend the function of the interface.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  低功耗唤醒处理，在外设唤醒的时候调用以恢复工作状态。
 * @param  [in]  arg  该参数用来该接口功能扩展使用。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。 参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_wkup_process(uintptr_t arg);

void pm_tick_handler_entry(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif