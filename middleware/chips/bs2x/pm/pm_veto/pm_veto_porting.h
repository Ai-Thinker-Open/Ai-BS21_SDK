/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm veto port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-13， Create file. \n
 */
#ifndef PM_VETO_PORTING_H
#define PM_VETO_PORTING_H

#include "non_os.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_chips_pm_veto_port PM veto port
 * @ingroup  middleware_chips_pm
 * @{
 */

#define PM_GET_LR    __return_address()

typedef enum pm_veto_id {
    PM_VETO_ID_BTC,
    PM_VETO_ID_NFC,
    PM_VETO_ID_MCU,
    PM_VETO_ULP_GPIO,
    PM_VETO_ID_KEYSCAN,
    PM_VETO_ID_SYS,
    PM_VETO_ID_USB,
    PM_VETO_ID_SLP,
    PM_VETO_ID_TIOT,
    PM_VETO_ID_MAX,
} pm_veto_id_t;

/**
 * @if Eng
 * @brief  Get customized sleep veto.
 * @retval true  Veto deep-sleep.
 * @retval false Allow deep-sleep.
 * @else
 * @brief  获取客制化的睡眠否决票。
 * @retval true  不允许睡眠。
 * @retval false 允许睡眠。
 * @endif
 */
bool pm_port_get_customized_sleep_veto(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
