/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_box_commu.h
 * Description:  Audio ux headset - box commu define
 */

#ifndef __UX_BOX_COMMU_H__
#define __UX_BOX_COMMU_H__

#include <stdint.h>
#include "los_typedef.h"
#include "ux_types.h"
#include "bt_service.h"

#pragma pack (1)
#define TLV_MEMORY_LEN 1024
#define MAX_TX_MSG_LEN 1024

typedef enum {
    UX_PD_TYPE_NONE = 0,
    UX_PD_TYPE_POWER_KEY,
    UX_PD_TYPE_SHIPMODE,
    UX_PD_TYPE_SLEEP,
    UX_PD_TYPE_RESET,
    UX_PD_TYPE_BAT_LOW,
    UX_PD_TYPE_POWERDOWN_FINISHED,
    UX_PD_TYPE_RIGHT_EAR_SHIPMODE,
    UX_PD_TYPE_SHIPMODE_CLOSE_COVER,

    UX_PD_TYPE_RESP = 1000,
    UX_PD_TYPE_RESP_POWER_KEY,
    UX_PD_TYPE_RESP_SHIPMODE,
    UX_PD_TYPE_RESP_SLEEP,
    UX_PD_TYPE_RESP_RESET,
    UX_PD_TYPE_RESP_BAT_LOW,
    UX_PD_TYPE_RESP_POWERDOWN_FINISHED,
    UX_PD_TYPE_RESP_RIGHT_EAR_SHIPMODE,
    UX_PD_TYPE_RESP_SHIPMODE_CLOSE_COVER,
} ux_shut_down_type;

enum {
    UX_BOX_ENTER_SHIPPING_MODE_SUCCESS = 0,
    UX_BOX_ENTER_SHIPPING_MODE_FAIL,
};

typedef enum {
    UX_TOUCH_PAD_ACK = 0,
    UX_TOUCH_PAD_UP,
    UX_TOUCH_PAD_DOWN,
    UX_TOUCH_PAD_FORWARD,
    UX_TOUCH_PAD_BACKWARD,
    UX_TOUCH_PAD_PRESS_2S,
    UX_TOUCH_PAD_DOUBLE_CLICK,
    UX_TOUCH_COVER_ALL,
    UX_TOUCH_COVER_RELEASE,
    UX_TOUCH_TYPE_END,
} ux_touch_pad_type;

typedef enum {
    UX_POWERON_WAKEUP_TYPE = 0x01,
} ux_msg_power_on_type_enum;

typedef enum {
    UX_WAKEUP_NULL = 0,
    UX_WAKEUP_POWER_KEY,
    UX_WAKEUP_BT_KEY,
    UX_WAKEUP_PAIR,
    UX_WAKEUP_WEAR,
    UX_WAKEUP_END,
} wake_up_type_enum;

typedef enum {
    UX_RESTORE_FACTORY_DEVICE_SN = 0x01,
} ux_msg_restore_factory_type_enum;

// heartbeat tlv type
typedef enum {
    UX_HEARTBEAT_VOLTAGE = 0x01,
    UX_HEARTBEAT_CURRENT,
    UX_HEARTBEAT_WHETHER_EXITBOX,
    UX_HEARTBEAT_REQUEST_VOLTAGE,
    UX_HEARTBEAT_PAIR_STATE,
} ux_msg_heartbeat_type_enum;

// headset req to box
typedef enum {
    UX_HEADSET_REQ_WEARSTATUS = 0x01,
    UX_HEADSET_REQ_CHARGE_STATUS,
} ux_msg_heartset_req_type_enum;

// box notify to headset
typedef enum {
    UX_NOTIFY_MOVEMENT = 0x01,
} ux_msg_notify_type_enum;

typedef struct {
    uint8_t event;
    uint8_t dst;
    uint8_t handle_flag;
    uint8_t send_type;
    uint16_t data_len;
    void* data_buff;
} ux_box_msg_info;

typedef struct {
    uint8_t wait_pairing_tone;
    uint8_t has_played_power_on_tone;
    BOOL factory_reboot_flag;
    uint8_t ear_commu_finished;
} ux_box_common_info;

/*************************************************new send type***********************************************/
typedef struct {
    uint8_t ear_side;
    uint8_t headset_bt_addr[UX_BD_ADDR_SIZE]; // size 6 Bytes
    uint8_t headset_coupled_addr[UX_BD_ADDR_SIZE]; // size 6 Bytes
} headset_bt_info;

typedef struct {
    uint8_t pd_num;
    uint8_t pdl_order[PD_NUM_MAX]; // size 10 Bytes
    uint8_t pdl_data[0];
} ux_head_set_pdl_info;

typedef struct {
    uint8_t mono_or_biaural;
    uint8_t recover_type;
    uint8_t device_sn[0];
} ux_head_set_recover_info;

typedef struct {
    uint8_t ear_side;
    uint8_t headset_battery_level;
    uint8_t headset_charge_state;
    uint8_t is_self_need_charge;
} ux_headset_battery_info;

typedef struct {
    uint8_t box_battery_level;
    uint8_t box_charge_state;
} ux_box_battery_info;

typedef struct {
    uint8_t headset_exit_box;
    uint16_t reboot_count;
    uint32_t timestamp;
    int16_t time_offset;
} ux_headset_sys_info;

typedef struct {
    uint8_t open_or_close_box;
    uint8_t box_version[VERSION_NAME_LEN]; // size 32 Bytes
} ux_box_sys_info;

typedef struct {
    uint16_t headset_voltage;
    uint16_t headset_current;
    uint16_t request_voltage;
} ux_headset_charge_info;

typedef struct {
    uint8_t ear_side;
    uint8_t headset_version[VERSION_NAME_LEN]; // size 32 Bytes
} ux_headset_version_info;

typedef struct {
    uint8_t device_type;
    uint8_t model_id;
    uint8_t sub_model_id;
} ux_model_id;

typedef struct {
    uint32_t shutdown_type;
    uint8_t result;
} ux_headset_shutdown_info;

typedef struct {
    uint32_t touch_type;
    uint8_t double_click_level;
} ux_touch_info;

typedef struct {
    uint8_t first_out_box;
    uint8_t last_in_box;
} ux_first_out_last_in_box;

typedef struct {
    uint8_t box_color;
    uint8_t box_shape;
    uint8_t box_model; // 0 is high-configuration
} ux_box_appearance;

#pragma pack ()

#endif

