/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_spp_tool.h
 * Description:  Audio ux spp general interface
 */
#ifndef __UX_SPP_TOOL_H__
#define __UX_SPP_TOOL_H__

#include <los_typedef.h>
#include "tlv.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define BT_ADDR_INDEX_0 0
#define BT_ADDR_INDEX_1 1
#define BT_ADDR_INDEX_2 2
#define BT_ADDR_INDEX_3 3
#define BT_ADDR_INDEX_4 4
#define BT_ADDR_INDEX_5 5
#define UX_SPP_SET_RUSULT_TYPE 0x7F

typedef VOID (*ux_spp_event_handle_func)(uint8_t *p_data, uint16_t data_len);

typedef struct {
    uint32_t command_id;
    ux_spp_event_handle_func func;
} ux_spp_event_handle_pair;

typedef struct {
    uint8_t type;
    uint8_t length;
    UINT8* value;
} __attribute__((__packed__)) ux_spp_tlv_pair;

uint32_t bswap32(uint32_t val32);
uint16_t bswap16(uint16_t val16);

void ux_spp_get_upload_sn(CHAR *sn, uint32_t in_len, uint32_t *sn_len);
uint16_t ux_spp_event_get_battery_info_len(void);
int32_t ux_spp_event_set_double_click_to_dev(uint8_t type, uint8_t value);
tlv_item_t* ux_spp_create_tlv_items_alloc(const ux_spp_tlv_pair* const get_msg_array, const uint8_t number);
UINT8* ux_spp_tlv_item_list_alloc_buffer(uint8_t service_id, uint8_t command_id,
    const ux_spp_tlv_pair* const get_msg_array, const uint8_t number, uint16_t *buff_len);
void ux_spp_tws_set_ai_switch_anc_index_ah_switch_from_bt_paired(uint8_t intelligent_switch,
    uint8_t anc_index, uint8_t ah_switch);
UINT8* ux_spp_set_rusult_buff(uint8_t service_id, uint8_t command_id, uint32_t err_code, uint16_t *buff_len);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
