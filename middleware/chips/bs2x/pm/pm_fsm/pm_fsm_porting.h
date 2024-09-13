/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm fsm port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-13， Create file. \n
 */
#ifndef PM_FSM_PORTING_H
#define PM_FSM_PORTING_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_chips_pm_fsm_port PM fsm port
 * @ingroup  middleware_chips_pm
 * @{
 */

typedef enum pm_fsm_id {
    PM_FSM_ID_BTC,
    PM_FSM_ID_NFC,
    PM_FSM_ID_MCU,
    PM_FSM_ID_MAX,
} pm_fsm_id_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
