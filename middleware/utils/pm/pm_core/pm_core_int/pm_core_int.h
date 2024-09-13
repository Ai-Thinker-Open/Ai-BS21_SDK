/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm core interrupt header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-05-06, Create file. \n
 */
#ifndef PM_CORE_INT_H
#define PM_CORE_INT_H

#include <stdint.h>
#include "errcode.h"
#include "pm_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_int PM Interrupt
 * @ingroup  middleware_utils_pm
 * @{
 */

void uapi_pm_core_int_init(void);

void uapi_pm_core_int_deinit(void);

errcode_t uapi_pm_core_int_register_sleep_irq(uint8_t src, pm_isr_callback_t *callback);

void uapi_pm_core_int_unregister_sleep_irq(uint8_t src, pm_isr_callback_t *callback);

errcode_t uapi_pm_core_int_register_wkup_irq(uint8_t src, pm_isr_callback_t *callback);

void uapi_pm_core_int_unregister_wkup_irq(uint8_t src, pm_isr_callback_t *callback);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif