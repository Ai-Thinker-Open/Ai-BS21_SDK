/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm core ballot header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-05-06, Create file. \n
 */
#ifndef PM_CORE_BALLOT_H
#define PM_CORE_BALLOT_H

#include <stdint.h>
#include "soc_osal.h"
#include "errcode.h"
#include "pm_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_core_ballot PM Core ballot
 * @ingroup  middleware_utils_pm
 * @{
 */

void uapi_pm_core_ballot_init(void);

void uapi_pm_core_ballot_deinit(void);

errcode_t uapi_pm_core_ballot_enable_serv_id(uint16_t sid);

void uapi_pm_core_ballot_disable_serv_id(uint16_t sid);

errcode_t uapi_pm_core_ballot_register_notify(pm_notify_block_t *notify);

void uapi_pm_core_ballot_unregister_notify(pm_notify_block_t *notify);

errcode_t uapi_pm_core_ballot_register_check_state(pm_state_check_ops_t *ops);

void uapi_pm_core_ballot_unregister_check_state(pm_state_check_ops_t *ops);

errcode_t uapi_pm_core_ballot_switch_to_state(uint16_t sid, uint16_t state);

errcode_t uapi_pm_core_ballot_low_power_handler(void);


/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif