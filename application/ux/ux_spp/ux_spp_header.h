/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_spp_header.h
 * Description:  Audio ux spp msg header
 */
#ifndef __UX_SPP_HEADER_H__
#define __UX_SPP_HEADER_H__

#include <los_typedef.h>
#include "ux_spp_common.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef enum {
    UX_SPP_MGR_INTELLIGENT_HEADER_STATUS,
    UX_SPP_MGR_DEV_HEADER_STATUS,
    UX_SPP_MGR_MAX_HEADER_STATUS,
} ux_spp_mgr_header_statue_type;

VOID ux_spp_add_or_del_i_connect_header(data_transport_data_node **head_node_ptr, data_transport_port_state *param);

data_transport_data* ux_get_cur_dev_spp_data_header(void);
data_transport_data* ux_get_cur_intelligent_spp_data_header(void);

data_transport_port_state* ux_get_spp_port_state(void);

data_transport_data* ux_get_font_spp_data_header(void);
data_transport_data* ux_get_dev_spp_data_header(void);

#ifdef CONFIG_LONG_PRESS_FUNC_ROC
data_transport_data* ux_get_cur_mideware_spp_data_header(void);
data_transport_data_node** ux_get_mideware_spp_i_connect_header_node(void);
data_transport_data_node** ux_get_mideware_spp_app_header_node(void);
#endif

data_transport_data_node* ux_get_dev_spp_app_header_node(void);
data_transport_data_node** ux_get_dev_spp_app_header_node_ptr(void);
data_transport_data_node* ux_get_dev_spp_i_connect_header_node(void);
data_transport_data_node** ux_get_dev_spp_i_connect_header_node_ptr(void);
data_transport_data_node* ux_get_intelligent_spp_i_connect_header_node(void);
data_transport_data_node** ux_get_intelligent_spp_i_connect_header_node_ptr(void);
data_transport_data_node* ux_get_intelligent_spp_app_header_node(void);
data_transport_data_node** ux_get_intelligent_spp_app_header_node_ptr(void);

VOID ux_spp_mgr_header_status(VOID *param, uint8_t type);
VOID ux_spp_event_mgr_header_status(const VOID* const header, uint8_t type);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
