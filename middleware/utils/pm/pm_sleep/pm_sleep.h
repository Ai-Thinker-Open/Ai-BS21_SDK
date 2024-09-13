/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides sleep header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-09， Create file. \n
 */

#ifndef PM_SLEEP_H
#define PM_SLEEP_H

#include <stdbool.h>
#include "common_def.h"
#include "errcode.h"
#include "pm_sleep_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_sleep PM sleep
 * @ingroup  middleware_utils_pm
 * @{
 */

/**
 * @if Eng
 * @brief  Sleep type.
 * @else
 * @brief  睡眠类型。
 * @endif
 */
typedef enum pm_sleep_type {
    PM_SLEEP_LS,
    PM_SLEEP_DS,
    PM_SLEEP_MAX,
} pm_sleep_type_t;

/**
 * @if Eng
 * @brief  Sleep veto recording.
 * @else
 * @brief  睡眠否决票记录。
 * @endif
 */
typedef struct sleep_veto {
    uint16_t last_veto_count;
    uint16_t last_veto_id;
} sleep_veto_t;

/**
 * @if Eng
 * @brief  Sleep event recording.
 * @else
 * @brief  睡眠事件记录。
 * @endif
 */
typedef struct sleep_event {
    uint16_t slp_event;
    uint16_t wkup_event;
} sleep_event_t;

/**
 * @if Eng
 * @brief  Sleep history recording.
 * @else
 * @brief  睡眠历史记录。
 * @endif
 */
typedef struct sleep_history {
    uint64_t total_slp_time  : 48;
    uint64_t total_slp_count : 16;
} sleep_history_t;

/**
 * @if Eng
 * @brief  Sleep information recording.
 * @else
 * @brief  睡眠信息记录。
 * @endif
 */
typedef struct sleep_info {
    uint64_t        sleep_base_time;
    sleep_veto_t    sleep_veto;
    sleep_event_t   event;
    sleep_history_t sleep_history[PM_SLEEP_MAX];
} sleep_info_t;

/**
 * @if Eng
 * @brief  The interface to start tickless.
 * @else
 * @brief  Tickless开启接口。
 * @endif
 */
typedef void (*pm_start_tickless_t)(void);

/**
 * @if Eng
 * @brief  The interface to stop tickless.
 * @param  [in]  sleep_ms Sleep time, time compensation needs to be performed based on the time.
 * @else
 * @brief  Tickless停止接口。
 * @param  [in]  sleep_ms 睡眠时间，需要根据该时间进行时间补偿。
 * @endif
 */
typedef void (*pm_stop_tickless_t)(uint32_t sleep_ms);

/**
 * @if Eng
 * @brief  Geting sleep time interface.
 * @return Sleep time.
 * @else
 * @brief  获取睡眠时间接口。
 * @return 睡眠时间。
 * @endif
 */
typedef uint32_t (*pm_get_sleep_ms_t)(void);

/**
 * @if Eng
 * @brief  Allowing deep-sleep interface.
 * @param  [in]  allow true: allow, false: disallow.
 * @else
 * @brief  允许深睡接口。
 * @param  [in]  allow true: 允许，false: 不允许。
 * @endif
 */
typedef void (*pm_allow_deepsleep_t)(bool allow);

/**
 * @if Eng
 * @brief  The wake-up timer interface.
 * @param  [in]  sleep_ms The sleep time.
 * @else
 * @brief  唤醒定时器接口。
 * @param  [in]  sleep_ms 睡眠时间。
 * @endif
 */
typedef void (*pm_start_wakeup_timer_t)(uint32_t sleep_ms);

/**
 * @if Eng
 * @brief  The system sleep and wake-up configuration interface.
 * @else
 * @brief  系统睡眠和唤醒配置接口。
 * @endif
 */
typedef void (*pm_slp_wkup_config_t)(void);

/**
 * @if Eng
 * @brief  The CPU suspend and resume interface.
 * @else
 * @brief  CPU挂起和恢复接口。
 * @endif
 */
typedef void (*pm_cpu_suspend_resume_t)(void);

/**
 * @if Eng
 * @brief  CPU enter WFI interface.
 * @else
 * @brief  CPU进入WFI接口。
 * @endif
 */
typedef void (*pm_enter_wfi_t)(void);

/**
 * @if Eng
 * @brief  The system enters the ultra-deep sleep state.
 * @else
 * @brief  系统进入超低深睡状态。
 * @endif
 */
typedef void (*pm_enter_udsleep_t)(void);

/**
 * @if Eng
 * @brief  Sleep interfaces that needs to be implemented by the user.
 * @else
 * @brief  需使用者实现的睡眠接口。
 * @endif
 */
typedef struct pm_sleep_funcs {
    pm_start_tickless_t      start_tickless;        /*!< @if Eng Starting tickless interface.
                                                         @else   开启tickless接口。 @endif */
    pm_stop_tickless_t       stop_tickless;         /*!< @if Eng Stoping tickless interface.
                                                         @else   关闭tickless接口。 @endif */
    pm_get_sleep_ms_t        get_sleep_ms;          /*!< @if Eng Geting sleep time interface.
                                                         @else   获取睡眠时间接口。 @endif */
    pm_start_wakeup_timer_t  start_wakeup_timer;    /*!< @if Eng Starting wake-up timer interface.
                                                         @else   启动唤醒定时器接口。 @endif */
    pm_allow_deepsleep_t     allow_deepsleep;       /*!< @if Eng Allowing deep-sleep interface.
                                                         @else   允许深度睡眠接口。 @endif */
    pm_slp_wkup_config_t     lightsleep_config;     /*!< @if Eng Light-sleep configuration interface.
                                                         @else   浅睡配置接口。 @endif */
    pm_slp_wkup_config_t     deepsleep_config;      /*!< @if Eng Deep-sleep configuration interface.
                                                         @else   深睡配置接口。 @endif */
    pm_slp_wkup_config_t     light_wakeup_config;   /*!< @if Eng Wake from light-sleep configuration interface.
                                                         @else   从浅睡唤醒配置接口。 @endif */
    pm_slp_wkup_config_t     deep_wakeup_config;    /*!< @if Eng Wake from deep-sleep configuration interface.
                                                         @else   从深睡唤醒配置接口。 @endif */
    pm_enter_wfi_t           enter_wfi;             /*!< @if Eng Entering WFI interface.
                                                         @else   进入WFI接口。 @endif */
#if defined(CONFIG_PM_POWER_GATING_ENABLE) && (CONFIG_PM_POWER_GATING_ENABLE == 1)
    pm_cpu_suspend_resume_t  cpu_suspend;           /*!< @if Eng CPU suspend interface.
                                                         @else   CPU挂起接口。 @endif */
    pm_cpu_suspend_resume_t  cpu_resume;            /*!< @if Eng CPU resume interface.
                                                         @else   CPU恢复接口。 @endif */
#endif
} pm_sleep_funcs_t;

/**
 * @if Eng
 * @brief  Register @ref pm_sleep_funcs_t into the g_pm_sleep_funcs.
 * @return Sleep interfaces that needs to be implemented by the user. For  see @ref pm_sleep_funcs_t
 * @else
 * @brief  注册 @ref pm_sleep_funcs_t 到 g_pm_sleep_funcs。
 * @return 需使用者实现的睡眠接口。参考 @ref pm_sleep_funcs_t
 * @endif
 */
void uapi_pm_register_sleep_funcs(pm_sleep_funcs_t *funcs);

/**
 * @if Eng
 * @brief  The system enters the sleep state if conditions are met.
 * @else
 * @brief  当条件满足则系统进入睡眠状态。
 * @endif
 */
void uapi_pm_enter_sleep(void);

/**
 * @if Eng
 * @brief  Get sleep-related information.
 * @return The sleep-related information. For details, see @ref sleep_info_t
 * @else
 * @brief  获取睡眠相关信息。
 * @return 睡眠相关信息。 参考 @ref sleep_info_t
 * @endif
 */
sleep_info_t *uapi_pm_get_sleep_info(void);

/**
 * @if Eng
 * @brief  Register the hook function for uapi_pm_enter_udsleep.
 * @param  [in]  func The hook function instance.
 * @else
 * @brief  为 uapi_pm_enter_udsleep 注册钩子函数。
 * @param  [in]  func 钩子函数实例。
 * @endif
 */
void uapi_pm_register_enter_udsleep_func(pm_enter_udsleep_t func);

/**
 * @if Eng
 * @brief  The system enters the ultra-deep sleep state.
 * @else
 * @brief  系统进入超低深睡状态。
 * @endif
 */
void uapi_pm_enter_udsleep(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif