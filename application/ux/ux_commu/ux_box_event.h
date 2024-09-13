/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_box_event.h
 * Description:  Audio ux box interface
 */

#ifndef __UX_BOX_EVENT_H__
#define __UX_BOX_EVENT_H__

#include "bt_device.h"
#include "ux_box_commu.h"
#include "ux_manager_common.h"
#include "tlv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define ux_box_print_err(log_num, fmt, args...)  ha_base_print_err(0, fmt, ##args)
#define ux_box_print_warn(log_num, fmt, args...) ha_base_print_warn(0, fmt, ##args)
#define ux_box_print_info(log_num, fmt, args...) ha_base_print_info(0, fmt, ##args)
#define ux_box_print_debug(log_num, fmt, args...) ha_base_print_debug(0, fmt, ##args)

#pragma pack (1)

#define COMMU_DST_BOX 'B'

#define UX_BOX_MODELID_LEN 3 // sizeof(Module ID) + sizeof(Sub model ID)
#define UXBOX_RESEND_MAX_BUFF_LEN 4
#define UX_BOX_COMMU_HEADER_LEN 15
#define UX_BOX_TRANSMITTED_TLV_NUM_MAX 15
#define POWER_ENTER_SHIPPING_DELAY 100
#define UX_BOX_TWS_INIT_COMMU_GAP        1000 // 1 second
#define UX_BOX_TWS_INIT_SEND_MAX_COUNT   600  // 10 min
#define UX_BOX_USB_INIT_SEND_MAX_COUNT   60  // 1 min
#define UX_BOX_RESNED_GAP 200 // 200ms
#define UX_BOX_RESEND_MAX_COUNT 6

#define DEV_CONN_MIN_TIME 30000
#define DEV_CONN_MAX_TIME 1800000
#define DEV_RECON_MIN_TIME 30000
#define DEV_RECON_MAX_TIME 120000

int32_t ux_box_battery_ack_to_tws(void);
void ux_reissue_reconnection(void);
int32_t ux_notify_bt_recon(uint8_t flag);
int32_t ux_reissue_disconnection(void);
void ux_enter_pair_mode_set_state(void);
int32_t ux_bt_fill_bt_data_notify_bt(tlv_item_t *cfg_msg, service_to_bt_msg msg_id, uint8_t is_forced);
int32_t ux_notify_bt_enter_pair_mode(tlv_item_t* cfg_msg, uint8_t is_forced);
int32_t ux_notify_bt_open_box_switch_info(void);
uint32_t ux_get_limit_time(uint32_t time, uint32_t max_time, uint32_t min_time);

#pragma pack ()

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif

