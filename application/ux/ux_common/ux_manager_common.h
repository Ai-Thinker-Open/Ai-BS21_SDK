/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_manager_common.h
 * Description:  Audio ux manager common interface
 */

#ifndef __UX_MANAGER_COMMON_H__
#define __UX_MANAGER_COMMON_H__

#include "app.h"
#include "ux_event_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define SHIPMODE_FLAG (0xabcdbeef)
#define UX_BOX_EVENT_BEGIN_NUM (1)
#define UX_SENSOR_EVENT_BEGIN_NUM (64)
#define UX_CHARGE_EVENT_BEGIN_NUM (128)
#define UX_SPP_EVENT_BEGIN_NUM (196)

typedef enum {
    /* box event */
    UX_BOX_EVENT_BEGIN = UX_EVENT_TYPE_BUTT + 1,
    UX_BOX_RECOVERY = UX_BOX_EVENT_BEGIN,
    UX_BOX_ENTER_PAIR_MODE,
    UX_BOX_CONNECT_INFO_INTERACTION,
    UX_BOX_RECONNECTION,
    UX_BOX_DISCONNECTED,
    UX_BOX_INBOX_INFO_INTERACTION,
    UX_BOX_BATTERY_INFO_NOTIFICATION,
    UX_BOX_LED_CONTROL,
    UX_BOX_MCU_NOTIFY_SHUTDOWN,
    UX_BOX_HEADSET_SHUTDOWN_NOTIFICATION,
    UX_BOX_TOUCHPAD_NOTIFICATION,
    UX_BOX_WEAR_STATUS_HANDLE,
    UX_BOX_WEAR_STATUS_REQ,
    UX_BOX_WAKE_UP_NOTIFICATION,
    UX_BOX_HEARTBEAT,
    UX_BOX_HEADSET_SELF_OPEN_BOX,
    UX_BOX_MOVEMENT,
    UX_BOX_USB_STATUS_REQ,
    UX_BOX_NOTIFY_USB_STATUS,
    UX_BOX_EVENT_END = UX_BOX_NOTIFY_USB_STATUS,

    UX_BOX_EVENT_MAX = UX_BOX_EVENT_END - UX_BOX_EVENT_BEGIN + 1,

    /* sensor event */
    UX_SENSOR_EVENT_BEGIN = UX_SENSOR_EVENT_BEGIN_NUM,
    UX_DC = UX_SENSOR_EVENT_BEGIN,          // double click 64
    UX_TC,                            // triple click 65
    UX_TOUCH,                         // long touch 66
    UX_SLIP_UP,                       // slip up 67
    UX_SLIP_DOWN,                     // slip down 68
    UX_WEAR_STATUS_OUT,               // out of ear 69
    UX_WEAR_STATUS_IN,                // in ear 70
    UX_OUT_BOX,                       // out of box 71
    UX_IN_BOX,                        // in box 72
    UX_PRESS,
    UX_DOUBLE_PRESS,
    UX_TRIPLE_PRESS,
    UX_LONG_PRESS,
    UX_SLIDE_UP, // 77
    UX_SLIDE_DOWN, // 78
    UX_SLIDE_FORWARD, // 79
    UX_SLIDE_BACKWARD, // 80
    UX_PRESS_2S, // 81
    UX_COVER_ALL, // 82
    UX_PRESS_1S, // 83
    UX_COVER_RELEASE, // 84
    UX_PRESS_3S, // 85
    UX_VOLUP_PRESS, // 86
    UX_VOLUP_2S, // 87
    UX_VOLDOWN_PRESS, // 88
    UX_VOLDOWN_2S, // 89
    UX_POWER_PRESS, // 90
    UX_POWER_DOUBLE_PRESS, // 91
    UX_POWER_TRIPLE_PRESS, // 92
    UX_POWER_2S_UP, // 93
    UX_POWER_4S_UP,
    UX_POWER_2S, // 95
    UX_POWER_4S,
    UX_POWER_10S,
    UX_POWER_TIME_ENOUGH, // 98
    UX_POWER_TIME_ENOUGH_UP, // 99
    UX_POWER_TIME_NOT_ENOUGH, // 100
    UX_PWR_VOLUP_VOLDOWN_2S, // 101
    UX_HALL_CLOSE,
    UX_HALL_OPEN,
    UX_SENSOR_EVENT_END = UX_HALL_OPEN,

    // charge event
    UX_CHARGE_EVENT_BEGIN = UX_CHARGE_EVENT_BEGIN_NUM,
    UX_HEADSET_BATTERY_POWER = UX_CHARGE_EVENT_BEGIN,  // headset battery level
    UX_HEADSET_BATTERY_LOW_POWER,
    UX_BOX_BATTERY_POWER,                              // box battery level
    UX_CHARGE_EVENT_END = UX_BOX_BATTERY_POWER,

    UX_SPP_EVENT_BEGIN = UX_SPP_EVENT_BEGIN_NUM,
    UX_DEVICE_MANAGEMENT,
    UX_INTELLIGENT,
    UX_FONT,
    UX_TWS_CONFIG,
    UX_MIDWARE_SERVICE,
    UX_SPP_MGR_HEADER_STATUS,
    UX_SPP_EVENT_END = UX_SPP_MGR_HEADER_STATUS,

    UX_PROTOCOL_MSG, // 对外联接协议
    UX_HAID_SER_MSG, // 助听的业务消息

    UX_FOTA_START,
    UX_FOTA_END,

    UX_PLAY_TONE,
    UX_STOP_TONE,
    UX_STOP_ALL_TONE,

    UX_A2DP_STOP,
    UX_SCO_STOP,

    UX_BUTT
}ux_cmd_type;

typedef struct {
    common_notify_mail_t mail;
}ux_cmd_msg_t;

typedef enum {
    TYPE_INIT,
    TYPE_DOUBLE_CLICK,
    TYPE_PRESS,
}ux_click_or_press_type;

typedef enum {
    UX_HANDUP_ENABLE_NONE = 0,
    UX_HANDUP_LED_ENABLE,
    UX_HANDUP_KEY_ENABLE,
    UX_HANDUP_LED_DISENABLE,
    UX_HANDUP_KEY_DISENABLE,
    UX_HANDUP_ENABLE_ALL,
    UX_HANDUP_NUM,
}ux_handup_type;

BOOL ux_manager_ux_led_handup_state_get(void);
BOOL ux_manager_ux_key_handup_state_get(void);
VOID ux_manager_ux_handup_state_set(ux_handup_type state);
VOID ux_manager_led_indication(uint16_t event);
app_t *ux_get_app(void);
void ux_set_break_down_state(uint8_t data);
int32_t ux_manager_common_init(const app_t *app);
int ux_config(const app_t *app, void *msg, uint16_t len);
int32_t ux_manager_dev_ioctl(app_t *app, uint8_t device_tag, uint8_t cmd, void *ioctl_buf, uint16_t buf_len);
int32_t ux_manager_event_handle(ux_cmd_msg_t *cfg_msg);
int32_t UX_ManagerIllegalEventHandle(ux_cmd_msg_t *mailMsg);
int32_t ux_manager_notify_stop_ota(void);
void ux_manager_ux_handup_state_init(void);
/* Protection scheme to prevent headset from abnormally exiting shipmode caused by static electricity :
    1. start shipmode timer when sensor send init position if: a.inbox b.shipmode flag exist
    2. stop shipmode timer if: a.receive box msg b.outbox c.receive bt pd info
*/
void ux_manager_start_enter_shipmode_timer(void);
void ux_manager_stop_enter_shipmode_timer_and_clear_flag(void);
void ux_equip_at_cmd_set(void);
int32_t ux_manager_shut_down(const void *param);
uint8_t ux_manager_get_shut_down_state(void);
VOID ux_manager_set_shut_down_state(uint8_t flag);
int32_t ux_manager_restore_factory_no_reboot(const void *param);
int32_t ux_test_cmd(const CHAR *module_name, const CHAR *func_name, uint8_t *buf, uint16_t buf_len);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif

