/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_spp_intelligent.h
 * Description:  Audio ux spp intelligent msg
 */
#ifndef __UX_SPP_INTELLIGENT_H__
#define __UX_SPP_INTELLIGENT_H__

#include "bt_service.h"
#include "los_typedef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define UX_SPP_SUPPORT_NOISYROL_CONTOLR_FUNC_NUM 10
#define UX_SPP_SUPPORT_LONG_PRESS_FUNC_NUM 12
#define INVALID_ANC_MODE_IN_TIGER 255
#define HEARINGAIDINVALIDENHANCEEFFECT 2

typedef struct {
    uint8_t noisy_control_function;
    uint8_t supported_function_list[UX_SPP_SUPPORT_NOISYROL_CONTOLR_FUNC_NUM];
} ux_get_noisy_control_info;

typedef struct {
    uint8_t self_long_press_function;
    uint8_t other_long_press_function;
    uint8_t long_press_function_len;
    uint8_t long_press_function_list[UX_SPP_SUPPORT_LONG_PRESS_FUNC_NUM];
} ux_get_long_press_info;

typedef struct {
    uint8_t hearing_aid_switch;
    uint8_t hearing_aid_enhance_effect;
    uint8_t hearing_aid_environment_eet;
    uint8_t reserved1;
    uint16_t hearing_aid_size;
    uint16_t reserved2;
} ux_hearing_aid_info;

typedef struct {
    uint8_t *pbuffer;
    uint16_t buffer_len;
    uint32_t offset_para;
} ux_event_memcp_addr_info;

// TLV type in service id 43, command id 03, DEV_MGR_ANC_SWITCH_UPLOAD
typedef enum {
    ANC_INITIATIVE_STATE_4303 = 0x01,
    FLY_MODE_4303,
    ANC_INTELLIGENT_MODE_NEGO_4303,
    SMART_BRAIN_SWITCH_4303,
    ANC_CS_RESULT_4303,
    ANC_INTELLIGENT_MODE_4303,
    MCU_STATE_UPLOAD_4303,
    LEFT_WEAR_DETECT_STATE_4303 = 0x08,
    RIGHT_WEAR_DETECT_STATE_4303,
    UX_ANC_INTELLIGENT_MODE_NEGO_RESULT_UPLOAD = 0xf0, // special for headset upload
} intelligent_anc_switch_upload_4303;

typedef enum {
    NOISY_CONTROL_STATE_UPLOAD = 0x01,
    NOISY_CONTROL_STATE_UPLOAD_BY_APP_SET = 0xf0,
} intelligent_noisy_control_upload;

typedef enum {
    DORA_FUNC_NOT_SUPPORT,
    DORA_FUNC_SUPPORT,
} intelligent_dora;

typedef enum {
    INTELLIGENT_ABILITY_NEGO = 0x01,
    INTELLIGENT_ANC_MODE,
    INTELLIGENT_ABILITY_NEGO_UPLOAD_TO_APP = 0xf0, // special for headset upload
} intelligent_ability_nego_and_mode_upload;

typedef enum {
    INTELLIGENT_CS_RESULT = 0x01,
    INTELLIGENT_MCU_MOTION_RESULT,
} intelligent_cs_and_motion_result_upload;

typedef enum {
    UX_SPP_ANC_MODE = 0X1,
    UX_SPP_INTELLIGENT_WALKING_SCENE = 0X3,
    UX_SPP_INTELLIGENT_STAY_SILENCE_SCENE,
    UX_SPP_INTELLIGENT_STAY_NOISY_SCENE,
    UX_SPP_INTELLIGENT_RUNNING_SCENE,
    UX_SPP_INTELLIGENT_TREADMILL_SCENE,
    UX_SPP_INTELLIGENT_SUBWAY_SCENE,
    UX_SPP_INTELLIGENT_HSRAIL_SCENE,
    UX_SPP_INTELLIGENT_PLANE_SCENE,
    UX_SPP_INTELLIGENT_CAR_SCENE,
    UX_SPP_INTELLIGENT_NORMAL_SCENE,
} ux_spp_set_anc_mode_type_t;


typedef enum {
    ENTER_DETECT = 0x01,
    EXIT_DETECT = 0x03,
} ux_spp_eatplugs_detect_type_t;

typedef enum {
    ENTER_DETECT_SUCCESS,
    ENTER_DETECT_FAIL,
    EXIT_DETECT_SUCCESS,
    EXIT_DETECT_FAIL,
} ux_spp_earplugs_detect_ack_value;

typedef enum {
    ANC_MODE_SET_SUCCESS,
    ANC_MODE_SET_FAIL,
} ux_spp_set_anc_mode_ack_value;

typedef enum {
    DEV_MGR_SEND_AT_CMD_TO_TWS,
    DEV_MGR_REC_AT_RESULT_FROM_TWS,
} ux_spp_at_cmd_id;

typedef enum {
    DEV_MGR_SET_VOICE_RECO_SWITCH = 0x01,
    DEV_MGR_GET_VOICE_RECO_SWITCH,
    DEV_MGR_ANC_SWITCH_UPLOAD,
    DEV_MGR_SET_ANC_SWITCH,
    DEV_MGR_GET_ANC_SWITCH,
    DEV_MGR_SET_ANC_MODE,
    DEV_MGR_GET_ANC_MODE_AND_INDEX,
    DEV_MGR_SET_ANC_INDEX,
    INTELLIGENT_GET_PAIR_FREE_DEV_INFO = 0x0a,
    INTELLIGENT_SET_WEAR_DETECTION_SWITCH = 0x10,
    INTELLIGENT_GET_WEAR_DETECTION_SWITCH = 0x11,
    INTELLIGENT_SET_LONG_PRESS_FUNC = 0x16,
    INTELLIGENT_GET_LONG_PRESS_FUNC = 0x17,
    INTELLIGENT_SET_NOISY_CONTROL_FUNC = 0x18,
    INTELLIGENT_GET_NOISY_CONTROL_FUNC = 0x19,
    INTELLIGENT_SET_LAST_DOUBLE_WEAR_ANC_SWITCH = 0x20,
    INTELLIGENT_GET_WEAR_STATE = 0X25,
    INTELLIGENT_SET_EARPLUGS_DETECT = 0x26,
    INTELLIGENT_UPLOAD_EARPLUGS_DETECT_RESULT = 0x27,
    INTELLIGENT_GET_AND_UPLOAD_NOISY_CONTROL_STATE = 0x2A,
    INTELLIGENT_ABILITY_NEGOTIATE_AND_UPLOAD = 0x2B,
    INTELLIGENT_CS_RESULT_AND_MOTION_STATE_UPLOAD = 0x2C,
    INTELLIGENT_GET_MULTIPLE_DEVICE_ABILITY = 0x2D,
    INTELLIGENT_SET_MULTIPLE_DEVICE_SWITCH = 0x2E,
    INTELLIGENT_GET_MULTIPLE_DEVICE_SWITCH = 0x2F,
    DEV_MGR_GET_MULTIPLE_DEVICE_INFO = 0x31,
    DEV_MGR_SET_MULTIPLE_DEVICE_ACTIVE_DEVICE = 0x32,
    DEV_MGR_SET_MULTIPLE_DEVICE_DEVICE_STATE = 0x33,
    DEV_MGR_UPLOAD_MULTIPLE_DEVICE_DEVICE_STATE = 0x34,
    DEV_MGR_GET_MULTIPLE_DEVICE_NEED_DISC_DEV = 0x35,
    DEV_MGR_UPLOAD_MULTIPLE_DEVICE_CHANGE_PDL = 0x36,
    DEV_MGR_UPLOAD_HEARING_AID_SWITCH = 0x3A,
    DEV_MGR_SET_HEARING_AID_SWITCH = 0x3B,
    DEV_MGR_UPLOAD_HEARING_AID_ENHANCE_EFFECT = 0x3C,
    DEV_MGR_SET_HEARING_AID_ENHANCE_EFFECT = 0x3D,
    DEV_MGR_UPLOAD_HEARING_AID_ENVIRONMENT = 0x3E,
    DEV_MGR_SET_HEARING_AID_ENVIRONMENT = 0x3F,
    INTELLIGENT_SET_RECORDING_MODE = 0x41,
    INTELLIGENT_GET_RECORDING_MODE = 0x42,
    INTELLIGENT_GET_IOS_AUTH_RANDOM = 0x43,
    INTELLIGENT_CHECK_IOS_AUTH_TOKEN = 0x44,
    INTELLIGENT_SET_HD_SCO_SWITCH = 0x45,
    INTELLIGENT_GET_HD_SCO_SWITCH = 0x46,
    INTELLIGENT_SET_USER_EQ_SETTING = 0x49,
    INTELLIGENT_GET_USER_EQ_SETTING = 0x4A,
    INTELLIGENT_GET_TOUCH_OPERATION = 0x4B,
    INTELLIGENT_UPLOAD_DORA_INDIVIDUAL = 0x56,
    INTELLIGENT_GET_DORA_INDIVIDUAL_ABILITY = 0x57,
    INTELLIGENT_SERVICE_COMMAND_END,
} intelligent_service_command_id;

typedef enum {
    TOUCH_OPERATION_TYPE_SLIDE,
    TOUCH_OPERATION_TYPE_MAX,
} ux_spp_touch_operation_type;

typedef enum {
    TOUCH_OPERATION_VALUE_TURN_UP,
    TOUCH_OPERATION_VALUE_TURN_DOWN,
    TOUCH_OPERATION_VALUE_MAX,
}ux_spp_touch_operation_solide_value;

void ux_spp_set_anc_mode(uint8_t anc_mode);
uint8_t ux_spp_get_anc_mode(void);
int32_t ux_spp_intelligent_send_data(const VOID *param, uint16_t length);
void ux_spp_intelligent_send_data_to_phone(const VOID *param, uint16_t length, uint8_t type);
void ux_spp_anc_switch_upload_fill_mbb_data(uint8_t *p_buffer, uint16_t buffer_len,
    uint8_t type_list[], uint8_t list_len);
ux_hearing_aid_info* ux_hearing_info_get(VOID);

VOID ux_spp_event_get_dora_individual_ablity(uint8_t *p_data, uint16_t data_len);
VOID ux_spp_event_get_wear_state(uint8_t *p_data, uint16_t data_len);
VOID ux_spp_event_get_anc_switch(uint8_t *p_data, uint16_t data_len);
int32_t ux_spp_event_set_anc_switch_ack(void);
void ux_spp_event_set_anc_mode_ack(ux_spp_set_anc_mode_ack_value ack_value);
VOID ux_spp_event_get_anc_mode_index(uint8_t *p_data, uint16_t data_len);
int32_t ux_spp_event_set_anc_index_ack(void);
void ux_spp_event_get_pair_free_dev_info_with_value(uint8_t value_from_phone);
void ux_spp_event_set_wear_detection_switch_ack_phone(void);
VOID ux_spp_event_get_wear_detection_switch(uint8_t *p_data, uint16_t data_len);
void ux_send_multiple_device_switch_to_tws(uint8_t value_from_phone, bool is_send_to_bt);
void ux_send_hd_sco_switch_to_bth(uint8_t hd_sco_switch);
void ux_spp_event_set_multiple_device_switch_ack(uint32_t ret_code);
void ux_spp_event_get_multiple_device_ability_ack(void);
void ux_spp_event_get_multiple_device_switch_ack(void);

#ifdef CONFIG_AUDIO_EFFECT_CSTM_EQ
void ux_spp_event_set_user_eq_setting_ack_phone(void);
#endif

#ifdef CONFIG_UX_HD_SCO
void ux_spp_event_set_hd_sco_switch_ack_phone(void);
VOID ux_spp_event_get_hd_sco_switch(uint8_t *p_data, uint16_t data_len);
#endif
void ux_spp_event_intelligent_handle(UINT8* p_data, uint16_t uw_len);
void ux_spp_intelligent_callback(service_to_ux_msg msg, VOID *param);
int32_t ux_spp_intelligent_init(void);
void ux_spp_event_set_recording_mode_ack_phone(void);
VOID ux_spp_event_get_recording_mode(uint8_t *p_data, uint16_t data_len);
void ux_spp_get_touch_operation_to_app(uint8_t type, uint8_t value, uint8_t volume_pre, uint8_t volume_next);
int32_t ux_spp_event_get_earplugs_version(VOID);
VOID ux_spp_event_set_hearing_aid_version(uint8_t *p_data, uint16_t len);
VOID ux_spp_event_set_hearing_aid_enhance_effect(uint8_t *p_data, uint16_t len);
VOID ux_spp_event_set_hearing_aid_environment(uint8_t *p_data, uint16_t len);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
