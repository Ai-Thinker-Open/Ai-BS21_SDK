/*
 * Copyright (c) @CompanyNameMagicTag 2019-2021. All rights reserved.
 * File          ux_multiple_device.h
 * Description:  Audio ux multiple device interface
 */
#ifndef UX_MULTIPLE_DEVICE_H
#define UX_MULTIPLE_DEVICE_H

#include "ux_bt_common.h"
#include "ha_common.h"
#include "bt_device.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef enum {
    SERVICE_FEATURE_TYPE_MULTIPLE_DEVICE_SWITCH = 0x00,
    SERVICE_FEATURE_TYPE_PRIORITY_DEVICE = 0x01,
    SERVICE_FEATURE_TYPE_BACKCONN_PERMIT,
    SERVICE_FEATURE_TYPE_DISCONNECT_OR_CONNECT,
    SERVICE_FEATURE_TYPE_CANCEL_PAIR,
} service_multiconn_switch_feature_type;

typedef enum {
    MBB_CM_PAIRED_DEV_QUERY_PDL_GET = 0x01,
    MBB_CM_PAIRED_DEV_QUERY_PDL_NUM = 0x02,
    MBB_CM_PAIRED_DEV_QUERY_PDL_DEV_INDEX = 0x03,
    MBB_CM_PAIRED_DEV_QUERY_PDL_DEV_ADDR = 0x04,
    MBB_CM_PAIRED_DEV_QUERY_PDL_CONN_STA = 0x05,
    MBB_CM_PAIRED_DEV_QUERY_PDL_DEV_TYPE = 0x06,
    MBB_CM_PAIRED_DEV_QUERY_PDL_PRI = 0x07,
    MBB_CM_PAIRED_DEV_QUERY_PDL_BACKCONN = 0x08,
    MBB_CM_PAIRED_DEV_QUERY_PDL_DEV_NAME = 0x09,
} mbb_cm_paired_dev_query;

typedef enum {
    MBB_CM_DEV_CTRL_CONN = 0x01,
    MBB_CM_DEV_CTRL_DISCONN = 0x02,
    MBB_CM_DEV_CTRL_DELETE = 0x03,
    MBB_CM_DEV_CTRL_BACKCONN_PERMIT = 0x04,
    MBB_CM_DEV_CTRL_BACKCONN_NO_PERMIT = 0x05,
}mbb_cm_dev_ctrl;

typedef struct multiple_dev_info_node {
    struct multiple_dev_info_node *prev;
    struct multiple_dev_info_node *next;
    bd_addr connect_addr;
    bool is_has_ble_addr;
    bd_addr ble_addr;
    ux_bt_common_dev_state state;
}ux_multiple_dev_info_node;

typedef struct {
    uint8_t main_state;
#ifndef CONFIG_MULTIPLE_DEVICE
    ux_bt_common_dev_state state;
#else
    uint8_t node_lenth;
    uint8_t incomming_switch_flag;
    bd_addr main_connect_addr;
    bd_addr pre_main_connect_addr;
    ux_multiple_dev_info_node *head_node;
#endif
}ux_multiple_dev_info_node_head;

uint8_t ux_multiple_get_main_state(void);
void ux_multiple_set_main_state(uint8_t state);
uint8_t ux_bt_get_mobile_connect_state(void);

#ifdef CONFIG_MULTIPLE_DEVICE
uint8_t ux_multiple_next_state(uint8_t *para, uint8_t State);
int32_t ux_multiple_get_main_state_addr(uint8_t *outAddr);
uint8_t ux_multiple_get_connect_num(void);
int32_t ux_multiple_insert_new_node(ServiceToUxMobileConnectStateMsgParam *parameter);
int32_t multiple_dev_hand_and_addr(uint8_t *para, uint8_t length);
int32_t ux_multiple_device_replace_other_addr(uint8_t *remoteAddr);
ux_bt_common_dev_state* ux_multiple_get_common_state(uint8_t *para);
void ux_multiple_update_work_mode(uint8_t *para);
void ux_multiple_switch_active_dev(uint8_t *para);
#else
ux_bt_common_dev_state* ux_multiple_get_common_state(void);
#endif

uint8_t multiple_dev_get_main_state(uint8_t *para);
int32_t multiple_dev_get_hfp_state(uint8_t *para, uint8_t length);
int32_t multiple_dev_get_a2dp_source_state(uint8_t *para, uint8_t length);
int32_t multiple_dev_get_a2dp_sink_state(uint8_t *para, uint8_t length);
int32_t multiple_dev_get_bt_mode_state(uint8_t *para, uint8_t length);

void ux_multiple_cm_event_handle(uint8_t *param, uint16_t length);
void ux_multiple_cm_single_pd_changed(void *param);
void ux_multiple_cm_multiple_pd_changed(void *param);
void ux_multiple_cm_order_list_changed(uint8_t pd_num);
void ux_multiple_cm_mobile_conn_state_changed(bd_addr addr, uint8_t state);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
