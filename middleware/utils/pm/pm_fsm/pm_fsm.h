/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides power management api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-13， Create file. \n
 */

#ifndef PM_FSM_H
#define PM_FSM_H

#include "common_def.h"
#include "errcode.h"
#include "pm_fsm_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_fsm PM fsm
 * @ingroup  middleware_utils_pm
 * @{
 */

/**
 * @if Eng
 * @brief  System running status.
 * @else
 * @brief  系统运行状态。
 * @endif
 */
typedef enum {
    PM_STATE_LIGHT_SLEEP,           /*!< @if Eng Light-sleep state.
                                         @else   浅睡状态。 @endif */
    PM_STATE_DEEP_SLEEP,            /*!< @if Eng Deep-sleep state.
                                         @else   深睡状态。 @endif */
    PM_STATE_WKUP_FROM_LIGHT_SLEEP, /*!< @if Eng Wakeup from light-sleep.
                                         @else   浅睡唤醒。 @endif */
    PM_STATE_WKUP_FROM_DEEP_SLEEP,  /*!< @if Eng Wakeup from Deep-sleep.
                                         @else   深睡唤醒。 @endif */
    PM_STATE_POWER_ON,              /*!< @if Eng Power-on state.
                                         @else   上电模式。 @endif */
    PM_STATE_POWER_OFF,             /*!< @if Eng Power-off state.
                                         @else   下电模式。 @endif */
    PM_STATE_WORK,                  /*!< @if Eng Working state.
                                         @else   工作模式。 @endif */
    PM_STATE_MAX,
} pm_states_t;

/**
 * @if Eng
 * @brief  Processing interfaces and parameters of the system state machine
 * @else
 * @brief  系统状态机处理接口和参数。
 * @endif
 */
typedef struct {
    uint8_t *data;
    uint32_t len;
    uint32_t (*handler)(uint8_t *data, uint32_t len);
} pm_fsm_content_t;

/**
 * @if Eng
 * @brief  Register the callback function of the state machine for the PM.
 * @param  [in]  id Indicates the ID of the state machine module.
 * @param  [in]  state System running status.
 * @param  [in]  content Processing interfaces and parameters of the system state machine.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  注册PM状态机回调函数。
 * @param  [in]  id 状态机模块ID。
 * @param  [in]  state 系统运行状态。
 * @param  [in]  content 系统状态机处理接口和参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_register_fsm_handler(pm_fsm_id_t id, pm_states_t state, pm_fsm_content_t *content);

/**
 * @if Eng
 * @brief  Unregister the callback function of the state machine for the PM.
 * @param  [in]  id Indicates the ID of the state machine module.
 * @param  [in]  state System running status.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  去注册PM状态机回调函数。
 * @param  [in]  id 状态机模块ID。
 * @param  [in]  state 系统运行状态。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_unregister_fsm_handler(pm_fsm_id_t id, pm_states_t state);

/**
 * @if Eng
 * @brief  The callback handler base on the ID and state.
 * @param  [in]  id Indicates the ID of the state machine module.
 * @param  [in]  state System running status.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  基于ID和状态的回调处理函数。
 * @param  [in]  id 状态机模块ID。
 * @param  [in]  state 系统运行状态。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_process_fsm_handler(pm_fsm_id_t id, pm_states_t state);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif