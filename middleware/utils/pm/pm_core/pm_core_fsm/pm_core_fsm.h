/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provide pm core fsm header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-05-06, Create file. \n
 */
#ifndef PM_CORE_FSM_H
#define PM_CORE_FSM_H

#include <stdint.h>
#include "errcode.h"
#include "pm_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_core_fsm PM Core fsm
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

typedef errcode_t (*fsm_handler_t)(void);

void uapi_pm_core_fsm_init(void);

void uapi_pm_core_fsm_deinit(void);

errcode_t uapi_pm_core_fsm_register_handler(uint8_t cur, uint8_t nxt, fsm_handler_t handler);

void uapi_pm_core_fsm_unregister_handler(uint8_t cur, uint8_t nxt);

errcode_t uapi_pm_core_fsm_execute_handler(uint8_t nxt);

void uapi_pm_core_fsm_change_nxt_state(void);

uint16_t uapi_pm_core_fsm_get_cur_state(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif