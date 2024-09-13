/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides power management api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-09， Create file. \n
 */

#ifndef PM_H
#define PM_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_api API
 * @ingroup  middleware_utils_pm
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize pmu.
 * @note   This API needs to complete power initialization configuration and register necessary hook functions.
 * @else
 * @brief  初始化电源管理。
 * @note   该接口需要完成电源初始化配置并进行必要的钩子函数注册。
 * @endif
 */
void uapi_pm_pmu_init(void);

/**
 * @if Eng
 * @brief  Initialize clock.
 * @note   This API needs to complete clock initialization configuration and register necessary hook functions.
 * @else
 * @brief  初始化时钟。
 * @note   该接口需要完成时钟初始化配置并进行必要的钩子函数注册。
 * @endif
 */
void uapi_pm_clock_init(void);

/**
 * @if Eng
 * @brief  Initialize sleep-wakeup.
 * @note   This API needs to complete the initialization configuration of sleep and wakeup and \n
           register necessary hook functions.
 * @else
 * @brief  初始化睡眠唤醒。
 * @note   该接口需要完成睡眠唤醒初始化配置并进行必要的钩子函数注册。
 * @endif
 */
void uapi_pm_lpc_init(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif