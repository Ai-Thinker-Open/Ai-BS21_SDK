/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_config_common.h
 * Description:  Audio ux common config
 */
#ifndef __UX_CONFIG_TWS_H__
#define __UX_CONFIG_TWS_H__

#include "ux_types.h"
#include "ux_manager_common.h"
#include "bt_device.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define INVALID_AH_SWITCH 3
#define INVALID_ANC_INDEX 15
#define INIT_ANC_INDEX 5
#define INVALID_CONFIDENCE_STATE 3
#define PROPERTY_KEY_PAIRED_ADDRESS_FACTORY "factory.system.bt.paired_address"
#define PROPERTY_KEY_PAIRED_ADDRESS_SYSTEM "system.bt.paired_address"
#define SETTING_DOUBLE_CLICK_KEY "user.setting.double_click"
#define SETTING_PEER_DOUBLE_CLICK_KEY "user.setting.peer_double_click"

typedef struct {
    ux_bd_addr coupled_addr;
    uint8_t double_click;     // click_config 0:voice helper  1:play or pause music(default) 2:next music 255:no action
    uint8_t peer_double_click; // click_config FOR OTHER  HEADSET
    uint8_t noisy_control;
    uint8_t long_press;
    uint8_t other_long_press;
    uint8_t last_double_wear_anc_switch;
} ux_config_tws;

typedef enum {
    TOUCH_PAD_SWITCH_OFF,
    TOUCH_PAD_SWITCH_ON,
} ux_config_touch_pad_switch;

ux_config_tws* ux_get_tws_config(void);

int32_t ux_config_product_form_init(void);
void ux_config_read_factory_pair_bt_addr(void);
VOID UX_ConfigGetConfidenceState(VOID);
VOID UX_ConfigInitNoisyControlOptions(VOID);
VOID UX_ConfigInitLongPressOptions(VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
