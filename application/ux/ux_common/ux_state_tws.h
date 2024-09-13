/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_state_tws.h
 * Description:  Audio ux tws state
 */
#ifndef __UX_STATE_TWS_H__
#define __UX_STATE_TWS_H__

#include "ux_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    KNOCK_NOT_HAPPENED = 0,
    KNOCK_HAPPENED,
} ux_knock_status;

typedef enum {
    UX_TWS_INIT_NONE,
    UX_TWS_SELF_INIT_OK,
    UX_TWS_RECEIVE_INIT_OK,
} ux_tws_init_state;

typedef enum {
    UX_USB_INIT_NONE,
    UX_USB_INIT_OK,
} ux_usb_init_state;

typedef enum {
    FIT_OK,
    FIT_NOT_OK,
    FIT_UNFINISHED,
}ux_ear_fit_state;

typedef struct {
    uint8_t in_or_out_box;           /* UX_InOrOutBox */
    uint8_t in_or_out_ear;           /* ux_in_or_out_ear */
    uint8_t other_in_or_out_box;     /* UX_InOrOutBox */
    uint8_t other_in_or_out_ear;     /* ux_in_or_out_ear */
    uint8_t box_open_or_close;       /* ux_cover_open_or_close */
    uint8_t earphone_position; /* earphone_pos_state */
    uint8_t in_box_or_not;  /* whether earphone is in box or not before factory */
} ux_tws_position_state;

typedef struct {
    char self_earbud_version[VERSION_NAME_LEN];
    char other_earbud_version[VERSION_NAME_LEN];
    char box_version[VERSION_NAME_LEN];
    char send_other_version[VERSION_NAME_LEN]; // version send to other, used in image version check
    uint8_t version_is_same;
    uint8_t image_version_is_match;
    uint8_t reserved[VERSION_RESERVED_LEN];
} ux_tws_version_state;

typedef struct {
    uint8_t box_led_scene;
    uint8_t shut_down_type;
    uint16_t mcu_type;
    volatile uint32_t retrans_task; // bit defined from UxBoxRetransMsgType
} ux_tws_box_state;

typedef struct {
    uint8_t power_on_or_not; // PowerOnState
    uint8_t wake_up_type;
} ux_tws_power_on_state;

typedef struct {
    uint8_t usb_on_or_not; // USBState
    uint8_t usb_init_state;
    uint16_t init_usb_count;
} ux_tws_usb_state;

typedef struct {
    uint8_t self_fit_state;
    uint8_t other_fit_state;
}ux_tws_ear_plugs_detect_state;

typedef struct {
    ux_tws_position_state position_state;
    ux_tws_version_state version_state;
    ux_tws_box_state box_state;
    ux_tws_power_on_state power_on_state;
    uint8_t knock_state; // UX_KnockStatus
    uint8_t init_ack_state; // ux_tws_init_state, is received other tws commu msg
    uint16_t init_send_count;
    ux_tws_ear_plugs_detect_state ear_plugs_detect_state;
    ux_tws_usb_state usb_state;
} ux_tws_state;

ux_tws_state *ux_get_tws_state(void);
void ux_tws_state_default_init(void);
uint8_t ux_get_earphone_position(void);
void ux_set_earphone_position(earphone_pos_state state);
ux_tws_position_state *ux_get_position_state(void);
ux_tws_version_state *ux_get_tws_version_state(void);

#ifdef __cplusplus
}
#endif

#endif
