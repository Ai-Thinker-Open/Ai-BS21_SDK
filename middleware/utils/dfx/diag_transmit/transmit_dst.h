/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: transmit
 * This file should be changed only infrequently and with great care.
 */
#ifndef __TRANSMIT_DST_H__
#define __TRANSMIT_DST_H__

#include <stdint.h>
#include "transmit_st.h"
#include "transmit_item.h"

errcode_t transmit_dst_item_process_data_reply_frame(transmit_data_reply_pkt_t *reply, diag_option_t *option,
    bool from_upper_machine);
errcode_t transmit_dst_item_process_start_frame(transmit_start_pkt_t *start_pkt, diag_option_t *option,
    bool from_upper_machine);
errcode_t transmit_dst_item_process_negotiate_frame(transmit_negotiate_pkt_t *negotiate_pkt, diag_option_t *option,
    bool from_upper_machine);
errcode_t transmit_dst_item_process_stop_frame(transmit_stop_pkt_t *pkt, diag_option_t *option,
    bool from_upper_machine);
void transmit_dst_item_process_timer(transmit_item_t *item, uint32_t cur_time);
void transmit_dst_item_send_start_frame(transmit_item_t *item, uint32_t cur_time);
void transmit_dst_item_send_data_request_frame(transmit_item_t *item, uint32_t cur_time);
#endif
