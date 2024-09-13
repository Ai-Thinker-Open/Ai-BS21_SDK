/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_product_interface.h
 * Description:  Audio ux tws product config
 */

#ifndef __UX_TWS_PRODUCT_PARAM_H__
#define __UX_TWS_PRODUCT_PARAM_H__

#include "ux_manager_common.h"
#include "ux_types.h"
#include "audio.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define UX_JUDGEMENT_NUM (7)
#define UX_TWS_DEFAULE_INDEX (8)
#define UX_TWS_VALUE_INDEX (7)
#define UX_JUDGE_NA      (0xff)

/*
 * if headset do not charge when openbox, implement this func in product config
 * @return UINT8
 */
uint8_t ux_product_headset_charge_state(uint8_t charge_state);
UINT8* ux_get_support_double_click_func(UINT8* info_len);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
