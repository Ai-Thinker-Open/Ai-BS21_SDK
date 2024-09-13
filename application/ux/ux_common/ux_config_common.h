/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_config_common.h
 * Description:  Audio ux common config
 */
#ifndef __UX_CONFIG_COMMON_H__
#define __UX_CONFIG_COMMON_H__

#include "ux_types.h"
#include "bt_device.h"
#include "ux_box_commu.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define SECONDS_OF_DAY    (60 * 60 * 24)
#define PD_DATA_VERSION   1 /* Must update this value when ServiceToBtPdData has been changed */
#define PD_DATA_VERSION_KEY                         "system.device.pdlversion"
#define RECORDING_MODE_KEY                          "user.setting.recording_mode"
#define HD_SCO_SWITCH_KEY                           "user.setting.intelligent_hd_sco_switch"
#define THIDR_WEAR_DETECTION_SWITCH_KEY             "user.setting.third_wear_detection_switch"
#define USER_EQ_SETTING_TYPE_KEY                    "user.setting.user_eq_setting_type"
#define USER_EQ_SETTING_SUPPORT_KEY                 "user.setting.user_eq_setting_support"
#define LANGUAGE_KEY                                "user.setting.language"
#define UX_SPP_SUPPORT_DOUBLE_CLICK_FUNC_NUM 5

typedef enum {
    LEFT_EAR = 1,
    RIGHT_EAR = 2,
} ear_side_enum;

typedef enum {
    DEVICE_TWS,
    DEVICE_FREEMAN,
} device_type_enum;

typedef enum {
    LANGUAGE_CHINESE = 0,
    LANGUAGE_ENGLISH = 1,
    LANGUAGE_BUTT    = 10,
} language_enum;

typedef enum {
    MARKET_CHINA,
    MARKET_OVERSEAS = 9,
} market_enum;

typedef enum {
    HONOR_MODEL_ID = 38,
    HW_MODEL_ID,
} model_id_enum;

// define in product
typedef enum {
    WHITE_ID,
    BLACK_ID,
    RED_ID,
} sub_model_id_enum;

typedef enum {
    HW_FC,
    HW_SC,
    HONOR_FC,
    HONOR_SC,
} advanced_version_enum;

typedef enum {
    HDAP_START,
    HDAP_STOP,
} recording_state_enum;

enum {
    BOX_COLOR_SILVERY,
    BOX_COLOR_WHITE,
    BOX_COLOR_BLACK,
    BOX_COLOR_RED,
    BOX_COLOR_GREEN,
    BOX_COLOR_BLUE,
    BOX_COLOR_PINK,
    BOX_COLOR_PURPLE,
    BOX_COLOR_YELLOW,
    BOX_COLOR_ORANGE,
    BOX_COLOR_CYAN,
    BOX_COLOR_BROWN,
    BOX_COLOR_GRAY,
    BOX_COLOR_GOLDEN,
    BOX_COLOR_MAX,
};

enum {
    BOX_SHAPE_ROUND,
    BOX_SHAPE_RECTANGLE,
    BOX_SHAPE_MAX,
};

typedef enum {
    COMB_TYPE_DEFAULT,
    COMB_WHITE_ROUND = COMB_TYPE_DEFAULT,
    COMB_SILVERY_ROUND,
    COMB_RED_ROUND,
    COMB_BLACK_RECTANGLE,
    COMB_SILVERY_RECTANGLE,
    COMB_TPYE_MAX,
} combe_type;

typedef enum {
    BOX_MODEL_DEFAULT,
    BOX_MODEL_HIGH = BOX_MODEL_DEFAULT,
    BOX_MODEL_LOW,
    BOX_MODEL_MAX,
} box_model;

typedef struct {
    uint32_t hw_version;
    char bt_name[DEVICE_NAME_LEN];
    uint32_t bt_name_time_stamp;
    char sn[SN_LEN]; // no used
    ear_side_enum ear_side;
    market_enum market;
    device_type_enum device_type;
    language_enum language; // language_enum 0:zh-CN  1:en-US
    uint8_t intelligent_voice_switch; // switch_config 0:off 1:on(default)
    ux_bd_addr self_addr;
    ux_bd_addr ble_addr;
    service_bt_work_mode work_mode;
    uint16_t modelid;
    uint8_t sub_model_id;
    advanced_version_enum advanced_version;
    uint8_t anc_switch; // switch_config 0:off(default) 1:on
    uint8_t anc_mode; // anc_mode 0:normal mode 1:fly mode
    uint8_t anc_index_normal_mode; // 0~63
    uint8_t anc_index_fly_mode; // 0~63
    uint8_t anc_switch_pre;
    uint8_t anc_intelligent_ability; // if mobile phone support tiger? TRUE-support, FALSE-not support
    uint8_t smart_brain_switch; // if mobile phone tiger switch on?  TRUE-support, FALSE-not support
    uint8_t anc_cs_result; // 0-quiet,1-low frequency noise,2-other
    uint8_t intelli_ah_switch[ANC_MODE_END];
    uint8_t intelli_anc_index[ANC_MODE_END];
    uint8_t mcu_state;
    uint8_t confidence_state;
    uint8_t tone_state;
    uint8_t intelligent_switch;
    uint8_t ah_switch;
    uint8_t recording_state;
    uint8_t ear_plugs_detect_switch;
    uint8_t temp_noisy_control_state;
    uint8_t hd_sco_switch;
    uint8_t shipping_mode_when_closed_flag;
    uint8_t third_wear_detection_switch;
    ux_box_appearance box_appearance;
    uint8_t user_eq_setting_support;
    uint8_t user_eq_setting_type;
} ux_common_config;

typedef struct {
    uint8_t self_double_click_function;
    uint8_t other_dev_double_click_function;
    uint8_t supported_function_len;
    uint8_t supported_function_list[UX_SPP_SUPPORT_DOUBLE_CLICK_FUNC_NUM];
}ux_get_double_click_info;

typedef enum {
    LANGUAGE_AUTO_ADAPT_NOT_SUPPORT = 0x00,
    LANGUAGE_AUTO_ADAPT_SUPPORT = 0x01,
} language_auto_adapt;

ux_common_config* ux_get_common_config(void);
int32_t ux_common_config_init(void);
service_bt_work_mode ux_get_work_mode(void);
void ux_set_work_mode(service_bt_work_mode work_mode);
BOOL ux_common_check_sn(const CHAR *sn);
void ux_set_tone_state(uint8_t new_tone_state);
void ux_config_set_audio_hadp_codec_setting(audio_hires_record_codec new_codec);
audio_hires_record_codec* ux_config_get_audio_hadp_codec_setting(void);
void ux_set_recording_mode(uint8_t new_recording_mode);
void ux_set_hd_sco_switch(uint8_t hd_sco_switch);
void ux_set_third_wear_detection_switch(uint8_t new_switch);
void ux_set_hd_sco_switch_delay_flag(uint8_t value);
uint8_t ux_get_hd_sco_switch_delay_flag(void);

int32_t ux_config_get_double_click_info(ux_get_double_click_info* info);
void ux_config_set_language(uint8_t new_language);
uint8_t ux_config_get_language(void);
uint8_t ux_config_get_language_auto_adapt(void);

#ifdef CONFIG_AUDIO_EFFECT_CSTM_EQ
void ux_set_user_eq_setting(uint8_t user_eq_setting_type);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
