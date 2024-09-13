/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm core struct header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-04-12, Create file. \n
 */
#ifndef PM_CORE_H
#define PM_CORE_H

#include <stdint.h>
#include "soc_osal.h"
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_core  PM Core
 * @ingroup  middleware_utils_pm
 * @{
 */

/*!<
 * Pm State Machine: \n
 *  __       __       __ \n
 * |  |     |  | --->|  | \n
 * |  |---> |  |     |LS| \n
 * |  |     |  | <---|__ | \n
 * |SD|     |WK|      __ \n
 * |  |     |  | --->|  | \n
 * |  |<--- |  |     |DS| \n
 * |__|     |__| <---|__| \n
 */

/* bit[1:0]: Status */
#define PM_STS_POS   0
#define PM_STS_BTS   0x3
#define PM_STS_MSK   (PM_STS_BTS << PM_STS_POS)

/* bit[5:2]: Sub Status */
#define PM_SUB_STS_POS 2
#define PM_SUB_STS_BTS ((uint16_t)(0xF))
#define PM_SUB_STS_MSK (PM_SUB_STS_BTS << PM_SUB_STS_POS)

/**
 * @if Eng
 * @brief  Function for checking the WORK status.
 * @retval 0   Further low power processing can be performed.
 * @retval Other   Retain the WORK state.
 * @else
 * @brief  WORK状态检查函数。
 * @retval 0   可以进行进一步的低功耗处理。
 * @retval Other   保持work状态。
 * @endif
 */
typedef int32_t (*wk_state_check_t)(void);
/**
 * @if Eng
 * @brief  Function for checking the WFI status.
 * @retval 0   WFI instructions are not allowed.
 * @retval Other   Allows execution of WFI instructions.
 * @else
 * @brief  WFI状态检查函数。
 * @retval 0   不允许执行WFI指令。
 * @retval Other   允许执行WFI指令。
 * @endif
 */
typedef int32_t (*wfi_state_check_t)(void);
/**
 * @if Eng
 * @brief  Function for checking the sleep status.
 * @retval 0   No allows to deep sleep status.
 * @retval Other   Allows.
 * @else
 * @brief  深睡状态检查函数。
 * @retval 0   不允许进入深睡状态。
 * @retval Other   允许进入深睡状态。
 * @endif
 */
typedef int32_t (*sleep_state_check_t)(void);
/**
 * @if Eng
 * @brief  Notification function of the deep sleep and wakeup processes.
 * @else
 * @brief  深睡和唤醒流程通知函数。
 * @endif
 */
typedef void (*notifier_call_t)(uint32_t event, uint8_t *data);
/**
 * @if Eng
 * @brief  Sleep and wakeup interrupt callback function.
 * @else
 * @brief  睡眠和唤醒中断回调函数。
 * @endif
 */
typedef void (*isr_callback_t)(uint8_t *data);

/**
 * @if Eng
 * @brief  Enumeration of FSM status.
 * @else
 * @brief  状态机状态枚举。
 * @endif
 */
typedef enum pm_fsm_sts_enum {
    PM_SHUTDOWN = 0x0,                      /*!< @if Eng Shutdown state.
                                                 @else   关闭状态 @endif */
    PM_DEEPSLEEP = 0x1,                     /*!< @if Eng Deepsleep state.
                                                 @else   深睡眠状态 @endif */
    PM_LIGHTSLEEP = 0x2,                    /*!< @if Eng Lightsleep state.
                                                 @else   浅睡眠状态 @endif */
    PM_WORK = 0x3,                          /*!< @if Eng Work state.
                                                 @else   工作状态 @endif */
    PM_FSM_STS_NUM                          /*!< @if Eng Maximum value.
                                                 @else   枚举边界最大值 @endif */
}pm_fsm_sts_enum_t;

/**
 * @if Eng
 * @brief  Enumeration of deep sleep and wakeup process notification events.
 * @else
 * @brief  深睡与唤醒流程通知事件枚举。
 * @endif
 */
typedef enum pm_core_notify_event_enum {
    PM_NOTIFY_PRE_LS,                       /*!< @if Eng Processing Events Before Lightsleep.
                                                 @else   浅睡前事件 @endif */
    PM_NOTIFY_POST_LS,                      /*!< @if Eng Processing Events After Lightsleep.
                                                 @else   浅睡后事件 @endif */
    PM_NOTIFY_DS_PREPARE,                   /*!< @if Eng Preparing Events Before Deepsleep.
                                                 @else   深睡准备事件 @endif */
    PM_NOTIFY_DS_SUSPEND_PREP,              /*!< @if Eng Event After the Peripheral is Turned off in Deepsleep.
                                                 @else   深睡关闭外设后事件 @endif */
    PM_NOTIFY_DS_SWITCH_LOWFREQ_PRE,        /*!< @if Eng Processing Events Before Switch high frequency in Deepsleep.
                                                 @else   深睡切换高频前事件 @endif */
    PM_NOTIFY_DS_SWITCH_LOWFREQ_POST,       /*!< @if Eng Processing Events After Switch high frequency in Deepsleep.
                                                 @else   深睡切换高频后事件 @endif */
    PM_NOTIFY_DS_WK_PREPARE,                /*!< @if Eng Preparing Events Before Wakeup.
                                                 @else   唤醒准备事件 @endif */
    PM_NOTIFY_DS_WK_RESUME_PREP,            /*!< @if Eng Events After the Peripheral is Turned on in Wakeup.
                                                 @else   唤醒恢复外设后事件 @endif */
    PM_NOTIFY_DS_WK_SWITCH_HIGHFREQ_PRE,    /*!< @if Eng Processing Events Before Switch high frequency in Wakeup.
                                                 @else   唤醒切换高频前事件 @endif */
    PM_NOTIFY_DS_WK_SWITCH_HIGHFREQ_POST,   /*!< @if Eng Processing Events After Switch high frequency in Wakeup.
                                                 @else   唤醒切换外设后事件 @endif */
    PM_NOTIFY_NUM                           /*!< @if Eng Maximum value.
                                                 @else   枚举边界最大值 @endif */
} pm_core_notify_event_enum_t;

/**
 * @if Eng
 * @brief  Structure of the interrupt callback function.
 * @else
 * @brief  中断回调函数结构体。
 * @endif
 */
typedef struct pm_isr_callback {
    struct osal_list_head st_entry;         /*!< @if Eng Linked list pointer structure.
                                                 @else   链表指针结构体 @endif */
    isr_callback_t isr_callback;            /*!< @if Eng Interrupt callback function.
                                                 @else   中断回调函数 @endif */
    uint8_t *data;                          /*!< @if Eng Interrupt callback parameter.
                                                 @else   中断回调函数入参 @endif */
} pm_isr_callback_t;

/**
 * @if Eng
 * @brief  Structure of the function for checking the status of the ballot box.
 * @else
 * @brief  投票箱状态检查函数结构体。
 * @endif
 */
typedef struct pm_state_check_ops {
    struct osal_list_head st_entry;         /*!< @if Eng Linked list pointer structure.
                                                 @else   链表指针结构体 @endif */
    wk_state_check_t wk_check;              /*!< @if Eng Function for checking the WORK status.
                                                 @else   WORK状态检查函数 @endif */
    wfi_state_check_t wfi_check;            /*!< @if Eng Function for checking the WFI status.
                                                 @else   WFI使能检查函数 @endif */
    sleep_state_check_t sleep_check;        /*!< @if Eng Function for checking the sleep status.
                                                 @else   睡眠状态确认函数 @endif */
}pm_state_check_ops_t;

/**
 * @if Eng
 * @brief  Structure of the function for checking the status of the ballot box.
 * @else
 * @brief  状态转移通知函数结构体。
 * @endif
 */
typedef struct pm_notify_block {
    struct osal_list_head st_entry;         /*!< @if Eng Linked list pointer structure.
                                                 @else   链表指针结构体 @endif */
    int32_t priority;                       /*!< @if Eng Priority of this node.
                                                 @else   节点优先级 @endif */
    notifier_call_t notifier_call;          /*!< @if Eng Notification function of the deep sleep and wakeup processes.
                                                 @else   深睡和唤醒事件通知函数 @endif */
}pm_notify_block_t;

/**
 * @if Eng
 * @brief  Init pm core.
 * @else
 * @brief  初始化协议状态机框架。
 * @endif
 */
void uapi_pm_core_init(void);

/**
 * @if Eng
 * @brief  Deinit pm core.
 * @else
 * @brief  去初始化协议状态机框架。
 * @endif
 */
void uapi_pm_core_deinit(void);

/**
 * @if Eng
 * @brief  Register and enable the service id.
 * @param  [in]  sid service id.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册并使能业务ID。
 * @param  [in]  sid 业务ID。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_enable_serv_id(uint8_t sid);

/**
 * @if Eng
 * @brief  Unregister and disable the service id.
 * @param  [in]  sid service id.
 * @else
 * @brief  解注册并去使能业务ID。
 * @param  [in]  sid 业务ID。
 * @endif
 */
void uapi_pm_core_disable_serv_id(uint8_t sid);

/**
 * @if Eng
 * @brief  Register the function for checking the status of the ballot box.
 * @param  [in]  ops structure of the notification function. For details, see @ref pm_state_check_ops_t.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册状态检查函数。
 * @param  [in]  ops 状态检查函数结构体。参考 @ref pm_state_check_ops_t 。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_register_state_check(pm_state_check_ops_t *ops);

/**
 * @if Eng
 * @brief  Unregister the function for checking the status of the ballot box.
 * @param  [in]  ops structure of the notification function. For details, see @ref pm_state_check_ops_t.
 * @else
 * @brief  解注册状态检查函数。
 * @param  [in]  ops 通知函数结构体。参考 @ref pm_state_check_ops_t 。
 * @endif
 */
void uapi_pm_core_unregister_state_check(pm_state_check_ops_t *ops);

/**
 * @if Eng
 * @brief  Register the notification function of the deep sleep and wakeup processes.
 * @param  [in]  notify Structure of the function. For details, see @ref pm_notify_block_t.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册深睡与唤醒事件通知函数。
 * @param  [in]  notify 通知函数结构体。参考 @ref pm_notify_block_t 。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_register_notify(pm_notify_block_t *notify);

/**
 * @if Eng
 * @brief  Unregister the notification function of the deep sleep and wakeup processes.
 * @param  [in]  notify Structure of the function. For details, see @ref pm_notify_block_t.
 * @else
 * @brief  解注册深睡与唤醒事件通知函数。
 * @param  [in]  notify 通知函数结构体。参考 @ref pm_notify_block_t 。
 * @endif
 */
void uapi_pm_core_unregister_notify(pm_notify_block_t *notify);

/**
 * @if Eng
 * @brief  Voting function for state transition of the state machine.
 * @param  [in]  sid service ID.
 * @param  [in]  state Expected transition state.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  状态机状态转换投票函数。
 * @param  [in]  sid 业务ID。
 * @param  [in]  state 预计转换的目标状态。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_switch_to_state(uint8_t sid, uint16_t state);

/**
 * @if Eng
 * @brief  Register the wakeup callback function.
 * @param  [in]  src wakeup interrupt request source.
 * @param  [in]  callback wakeup callback function.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册唤醒中断回调函数。
 * @param  [in]  src 唤醒中断源。
 * @param  [in]  callback 唤醒中断回调函数。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_register_wkup_isr(uint8_t src, pm_isr_callback_t *callback);

/**
 * @if Eng
 * @brief  Register the sleep callback function.
 * @param  [in]  src sleep interrupt request source.
 * @param  [in]  callback sleep callback function.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册睡眠中断回调函数。
 * @param  [in]  src 睡眠中断请求源。
 * @param  [in]  callback 睡眠中断回调函数。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_register_sleep_isr(uint8_t src, pm_isr_callback_t *callback);

/**
 * @if Eng
 * @brief  Unregister the wakeup callback function.
 * @param  [in]  src wakeup interrupt request source.
 * @else
 * @brief  解注册唤醒中断回调函数。
 * @param  [in]  src 唤醒中断请求源。
 * @endif
 */
void uapi_pm_core_unregister_wkup_isr(uint8_t src, pm_isr_callback_t *callback);

/**
 * @if Eng
 * @brief  Unregister the sleep callback function.
 * @param  [in]  src sleep interrupt request source.
 * @else
 * @brief  解注册睡眠中断回调函数。
 * @param  [in]  src 睡眠中断请求源。
 * @endif
 */
void uapi_pm_core_unregister_sleep_isr(uint8_t src, pm_isr_callback_t *callback);

/**
 * @if Eng
 * @brief  Low-power state machine control function, which is called at the end of the main loop.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  低功耗状态机控制函数，在main循环的最后调用。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pm_core_low_power_handler(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif