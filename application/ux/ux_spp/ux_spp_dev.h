/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_spp_dev.h
 * Description:  Audio ux spp device manager service handler
 */
#ifndef __UX_SPP_DEV_H__
#define __UX_SPP_DEV_H__

#include <los_typedef.h>
#include "ux_spp_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct {
    uint8_t left_battery;
    uint8_t right_battery;
} battery_info_upload;

typedef enum {
    SELF_BATTERY_PERCENT = 0x01,
    MULTI_BATTERY_PERCENT,
    MULTI_BATTERY_CHARGE_STATE,
    LOW_BATTERY_LINE
} ux_battery_upload_id;

typedef struct {
    uint8_t self_battery_percent;
    uint8_t other_one_dev_battery_percent;
    uint8_t other_two_dev_battery_percent;
    uint8_t reserved;
} ux_get_battery_percent_info;

typedef struct {
    uint8_t self_battery_charge_state;
    uint8_t other_one_dev_battery_charge_state;
    uint8_t other_two_dev_battery_charge_state;
    uint8_t reserved;
} ux_get_battery_charge_info;

typedef struct {
    uint8_t low_battery_line_h;
    uint8_t low_battery_line_l;
    uint8_t reserved;
} ux_get_battery_low_battery_line_info;

typedef enum {
    SELF_DOUBLE_CLICK = 0x01,
    OTHER_DOUBLE_CLICK,
    SUPPORT_FUNCTION
} ux_double_click_id;

typedef enum {
    UX_SPP_SET_LEFT_SUCCESS = 0,
    UX_SPP_SET_LEFT_FAIL,
    UX_SPP_SET_RIGHT_SUCCESS,
    UX_SPP_SET_RIGHT_FAIL,
} ux_spp_set_left_right_result_t;

typedef enum {
    UX_SPP_SET_TOUCH_PAD_SWITCH_SUCCESS = 0,
    UX_SPP_SET_TOUCH_PAD_SWITCH_FAIL,
}ux_spp_set_touch_pad_switch_result_t;

typedef enum {
    DEV_MGR_SET_DEVICE_TIME = 0x05,
    DEV_MGR_REQ_GET_TIME = 0x06,
    DEV_MGR_GET_DEVICE_VERSION = 0x07,
    DEV_MGR_GET_BATTERY_PERCENTAGE = 0x08,
    DEV_MGR_SET_DOUBLE_CLICK = 0x1F,
    DEV_MGR_GET_DOUBLE_CLICK = 0x20,
    DEV_MGR_SET_TRIPLE_CLICK = 0x25,
    DEV_MGR_GET_TRIPLE_CLICK,
    DEV_MGR_BATTERY_INFO_UPLOAD,
    DEV_MGR_SET_TOUCH_PAD_SWITCH       = 0x2C,
    DEV_MGR_GET_TOUCH_PAD_SWITCH = 0x2D,
    DEV_MGR_RESEND_MSG = 0x99,
} device_management_command_id;

typedef enum {
    ONE_SEVEN_DEVICE_TYPE         = 0x02,
    ONE_SEVEN_DEVICE_VERSION      = 0x03,
    ONE_SEVEN_DEVICE_SOFT_VERSION = 0x07,
    ONE_SEVEN_DEVICE_SN           = 0x09,
    ONE_SEVEN_DEVICE_MODEL        = 0x0A,
    ONE_SEVEN_DEVICE_OTA_PACKAGENAME = 0x0F,
    ONE_SEVEN_DEVICE_SN_MASTER    = 0x18,
    ONE_SEVEN_DEVICE_SUBMODELID   = 0x19,
} service_id_one_command_id_seven_type;

int32_t ux_spp_dev_manager_service_init(void);
void ux_spp_event_device_management_handle(uint8_t *p_data, uint16_t uw_len);

void ux_spp_event_get_dev_ver(uint8_t *p_data, uint16_t data_len);

void ux_spp_event_get_bttry_percent(uint8_t *p_data, uint16_t data_len);

void ux_spp_event_get_double_click(uint8_t *p_data, uint16_t data_len);


void ux_spp_dev_mgr_send_data_to_phone(const VOID *param, uint16_t length, uint8_t type);
void ux_spp_send_data_to_all_phone(const VOID *param, uint16_t length, data_transport_data_node *head);
void ux_spp_get_time_from_phone(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
