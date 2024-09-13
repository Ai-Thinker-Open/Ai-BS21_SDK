/*
 * Copyright (c) @CompanyNameMagicTag 2020-2021. All rights reserved.
 * File          ux_types.h
 * Description:  Audio ux common parameter, common definition
 */

#ifndef __UX_TYPES_H__
#define __UX_TYPES_H__

#include <stdint.h>

#define VERSION_CMP_LEN      5  // 1.X.Y
#define UX_SPECIAL_VERSION   "999999" // image version not match
#define VERSION_NAME_LEN     32
#define VERSION_RESERVED_LEN 2
#define SN_LEN               64
#define UX_BD_ADDR_SIZE      (6)
#define PEER_MODE_ID_LEN     3
#define GENERAL_BUF_LEN_64   64
#define PD_RESERVED_SIZE    6
#define HALF_LINK_KEY_LEN    8
#define INT_TYPE_DECIMAL     10
#define MODULE_LEN           3 // UX^

#define ANC_INDEX_DEFAULT (0)
#define ANC_INDEX_MAX (3)
#define ANC_INDEX_MIN (0)

#define HFP_VOLUME_MAX           (15)
#define HFP_VOLUME_MIN           (1)
#define A2DP_VOLUME_MAX          (127)
#define A2DP_VOLUME_MIN          (0)
#define AVRCP_VOLUME_MAX (15)
#define AVRCP_VOLUME_MIN (0)
#define SENSOR_TRIGGER_VOLUME_STEP (1)

#define AVRCP_VOLUME_TO_BT_MAX          (127)
#define HFP_VOLUME_TO_BT_MAX            (15)

#define BITWISE_OFFSET_1_BITS  1
#define BITWISE_OFFSET_2_BITS  2
#define BITWISE_OFFSET_8_BITS   8
#define BITWISE_OFFSET_24_BITS  24
#define BITWISE_OFFSET_32_BITS  32

#define VALUE_BY_BIT_LOW_1_BIT 0x1
#define VALUE_BY_BIT_LOW_2_BIT 0x2
#define VALUE_BY_BIT_LOW_3_BIT 0x4

#define UINT32_MAX_VALUE        0xFFFFFFFF

#define VOLUME_CONVERT_COEFFICIENT  8
#define BOX_REQ_NORMAL_CNT    1
#define BOX_REQ_ABNORMAL_CNT  7
#define NORMAL_REQ_OTHER_NOT_IN_BOX    0
#define NORMAL_REQ_OTHER_IN_BOX        1
#define ABNORMAL_REQ_OTHER_NOT_IN_BOX  2
#define ABNORMAL_REQ_OTHER_IN_BOX      3
#define REISSUE_OPEN_BOX      0
#define REISSUE_CLOSE_BOX     1
#define SNPRINTF_S_ERR_NUM (-1)
#define COMPLEMENT_ONE     (1)

#define ZH_CN     "zh-CN"
#define ZH_HK     "zh-HK"
#define ZH_MO     "zh-MO"
#define ZH_SG     "zh-SG"
#define ZH_TW     "zh-TW"
#define ZH_CHS    "zh-CHS"
#define ZH_CHT    "zh-CHT"
#define EN_GB     "en-GB"
#define FONT_LIST "zh-CN,en-GB"

#define i8updnlmt(i8Var, i8Max, i8Min) \
    do { \
        (i8Var) = ((i8Var) >= (i8Max)) ? (i8Max) : (i8Var); \
        (i8Var) = ((i8Var) <= (i8Min)) ? (i8Min) : (i8Var); \
    } while (0)

#define convert(volume, multiplier, divisor) \
    ((volume) = (uint8_t)(((volume) * ((multiplier) + COMPLEMENT_ONE)) / ((divisor) + COMPLEMENT_ONE)))
 
typedef uint8_t ux_bd_addr[UX_BD_ADDR_SIZE];

typedef enum {
    OUT_EAR = 0,
    IN_EAR,
} ux_in_or_out_ear;

typedef enum {
    BOX_OPEN = 0,
    BOX_CLOSED,
} ux_cover_open_or_close;

typedef enum {
    INIT_EARPHONE_POS = 0,
    INIT_IN_BOX = 1,
    INIT_OUT_BOX = 2,
    INBOX_CLOSED = 3,
    INBOX_OPENED = 4,
    OUTBOX_OUTEAR = 5,
    INEAR = 6,
    OUTEAR = 7, // tws without box
    UX_POS_MAX,
} earphone_pos_state;

typedef enum {
    OTA_IDLE = 0,
    OTA_START = 1,
    OTA_SUCCESS = 2,
    OTA_FAILED = 3,
    OTA_CANCELED = 4,
    OTA_UX_CANCELED,
} ota_status;

typedef enum {
    OPEN_VOICE_HELPER,
    PLAY_OR_PAUSE_MUSIC,
    NEXT_MUSIC,
    ANC_ON_OFF,
    PLAY_OR_NEXT_MUSIC,
    PREVIOUS_MUSIC = 7,
    NO_ACTION_CONFIG = 255,
} click_config;

typedef enum {
    SWITCH_OFF,
    SWITCH_ON,
    HEAR_THROUGH,
    INTELLIGENT_MODE,
    AHA_OFF,
} switch_config;

typedef enum {
    RECORDING_MODE_HD,
    RECORDING_MODE_MESH,
    RECORDING_MODE_END,
} recording_mode;

typedef enum {
    INTELLIGENT_SWITCH_ON,
    INTELLIGENT_SWITCH_OFF,
    AH_SWITCH_ON,
    AH_SWITCH_OFF,
} intelligent_ah_switch_type;

typedef enum {
    ANC_ON_OR_OFF = 1,
    ANC_ON_HT_OFF,
    ANC_ON_HT,
    HT_OFF,
    INTELLI_ANC_ON,
    INTELLI_ANC_ON_HT,
    INTELLI_ANC_ON_OFF,
    INTELLI_HT,
    INTELLI_HT_OFF,
    INTELLI_OFF,
    INTELLI_HT_ANC_ON_OFF,
    NOISY_CONTROL_STATE_END,
} noisy_control_config;

typedef enum {
    LONG_PRESS_OPEN_VOICE_HELPER,
    LONG_PRESS_PLAY_OR_PAUSE_MUSIC,
    LONG_PRESS_NEXT_MUSIC,
    LONG_PRESS_ANC_ON_OFF,
    LONG_PRESS_PLAY_OR_NEXT_MUSIC,
    LONG_PRESS_ANC_ON_OFF_HT,
    LONG_PRESS_ANC_ON_HT,
    LONG_PRESS_LAST_MUSIC,
    LONG_PRESS_PLAY_OR_LAST_MUSIC,
    LONG_PRESS_ANC_ON_HT_OFF,
    LONG_PRESS_NOISY_CONTROL = 10,
    LONG_PRESS_MISIC_ASSEMBLE = 13,
    LONG_PRESS_DORA_INDIVIDUAL = 15,
} press_config;

typedef enum {
    PHONE_CONFIG,
    LOCAL_RING,
    AUDIO_SYNC_CONFIG,
    BT_BATTERY_INFO,
    FOTA_INFO,
    WEAR_STATE,
    MOBILE_CONNECT_STATE,
    BT_STATE_TEST,
    SN_INFO,
    AT_INFO,
    HAID_TWS_MODE,
    BT_STANDBY_TWS_MODE,
    UX_MANAGER_NOTIFY,
} tws_data_type;

typedef enum {
    DEFAULT_TRIGGER,
    SENSOR_TRIGGER,
    PHONE_TRIGGER,
    PAIRED_RESEND_TRIGGER,
} anc_trigger_type;

typedef enum {
    HEADSET_BATTERY = 0x01,
    BOX_BATTERY,
} battery_command_id;

typedef enum {
    MSG_FROM_BT_PRIR,
    MSG_FROM_DEV_MGR,
} double_click_type;

typedef enum {
    MS_HANDOVER_SUCCESS, // 0
    MS_HANDOVER_FAIL,
    MS_HANDOVER_START,
} ms_handover_state;

typedef enum {
    NOT_RECEIVE_RSSI,
    RECEIVE_RSSI,
} rssi_state;

typedef enum {
    BOX_NOT_CHARGING = 0,
    BOX_WIRE_CHARGING = 1,
    BOX_WIRELESS_CHARGING = 2,
} box_charge_status;

typedef enum {
    DEFULT_MODE,
    FLY_MODE,
    SET_WALK = 3,
    SET_SILENCE,
    SET_NOISY,
    SET_RUN,
    SET_TREADMILL,
    SET_SUBWAY,
    SET_HSRAIL,
    SET_PLANE,
    SET_CAR,
    NORMAL_MODE,
    ANC_MODE_END,
} anc_mode;

typedef enum {
    AH_OFF,
    AH_ON,
} ah_switch;

typedef enum {
    PRIVATE_TYPE,
    GOOGLE_TYPE,
    GENERAL_TYPE = 6,   /* 标准协议 */
} voice_assistant_type;

typedef enum {
    ANC_SWITCH_ON,
    ANC_SWITCH_OFF,
    BT_CONNECTED,
} local_ring_type;

typedef enum {
    BT_NOT_CONNECT,
    BT_CONNECT,
} bt_connect_state_test;

typedef enum {
    NORMAL_ENV,
    QUIET_ENV,
    LOW_FREQ_ENV,
} anc_ht_cs_env;

typedef enum {
    TIGER_BALANCED,
    TIGER_COMFORTABLE,
    TIGER_DEPTH,
    TIGER_INTELLIGENT,
    TIGER_KEEP_ORIGINAL_VALUE = 0xFF,
} anc_submode_from_phone;

typedef enum {
    TIGER_SWITCH_ON = 0x01,
    TIGER_SWITCH_OFF,
    TIGER_KEEP_UNCHANGED = 0xFF,
} ah_switch_value_from_phone;

typedef enum {
    HD_SCO_SWITCH_OFF,
    HD_SCO_SWITCH_ON,
} hd_sco_switch;

typedef struct {
    uint8_t intelli_anc_index;
    uint8_t intelli_ah_switch;
} intelligent_scence_config;

typedef struct {
    uint8_t service_id;
    uint8_t command_id;
} mbb_header_t;

typedef struct {
    uint8_t type;
    uint8_t len;
    uint8_t value;
} __attribute__((__packed__)) mbb_ack_data_t;

typedef struct {
    uint8_t type;             // tws_data_type
    mbb_header_t mbb_header;  // if type is PHONE_CONFIG, follow the mbb, or zero
    uint16_t length;
    uint8_t value[0];
} __attribute__((__packed__)) tws_trans_data_t;

typedef enum {
    USER_EQ_TYPE_DEFAULT = 1,
    USER_EQ_TYPE_BASS,
    USER_EQ_TYPE_HIGH_RESOLUTION,
} user_eq_setting_type;

typedef enum {
    USER_EQ_SUPPORT_OFF,
    USER_EQ_SUPPORT_ON,
} user_eq_setting_support;

typedef struct {
    uint8_t type;
    uint8_t length;
} mbb_tl_t;

#endif
