/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm device port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-13， Create file. \n
 */
#ifndef PM_DEV_PORTING_H
#define PM_DEV_PORTING_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_chips_pm_dev_port PM dev port
 * @ingroup  middleware_chips_pm
 * @{
 */

typedef enum pm_dev_id {
    PM_DEV_NONE,
    PM_DEV_M_TCXO,
    PM_DEV_M_SFC,
    PM_DEV_M_CACHE,
    PM_DEV_M_CPU_TRACE,
    PM_DEV_M_PINCTRL,
    PM_DEV_M_UART,
    PM_DEV_M_WDT,
    PM_DEV_MAX,
} pm_dev_id_t;

#if defined(CONFIG_PM_POWER_GATING_ENABLE)
errcode_t mpu_cache_suspend(uintptr_t arg);
errcode_t mpu_cache_resume(uintptr_t arg);
#endif
#if defined(CONFIG_WATCHDOG_SUPPORT_LPM)
errcode_t watchdog_resume(uintptr_t arg);
#endif  /* CONFIG_WDT_SUPPORT_LPM */
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif

