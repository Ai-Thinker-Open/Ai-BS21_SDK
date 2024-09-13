/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: pkt router
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_PKT_ROUTER_H
#define DIAG_PKT_ROUTER_H

#include "errcode.h"
#include "diag_pkt.h"
#include "diag_channel.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/* SN definitions */
enum {
    FRAME_SN_FLAG_NONE,
    FRAME_SN_FLAG_START,
    FRAME_SN_FLAG_ONGOING,
    FRAME_SN_FLAG_END,
};

typedef struct {
    uint8_t cur_proc; /* diag_pkt_mode_t */
    uint8_t dst_addr;
    uint8_t src_addr;
} diag_pkt_process_param_t;

typedef struct {
    diag_pkt_process_param_t param;
    diag_pkt_handle_t pkt;
} diag_pkt_msg_t;

errcode_t diag_pkt_router(diag_pkt_handle_t *pkt, diag_pkt_process_param_t *process_param);

errcode_t diag_pkt_router_send(diag_router_data_t *router_data);

void diag_pkt_msg_proc(uint32_t msg_id, uint8_t *msg, uint32_t msg_len);

/* 计算链路层帧的payload前的数据长度 */
static inline uint8_t diag_pkt_router_calc_prefix_len(diag_router_ctrl_t *ctrl, diag_router_ctrl2_t *ctrl2)
{
    uint8_t prefix_len = DIAG_ROUTER_HEADER_LEN;
    /* ctrl2 en */
    prefix_len += ctrl->en_extend;

    /* echo en */
    if (ctrl->en_extend != 0 && ctrl2 != NULL && ctrl2->ack_type == FRAME_ACK_TYPE_ECHO) {
        prefix_len++;
    }

    /* fid en */
    prefix_len += ctrl->en_fid;

    /* 是否是分包数据 */
    prefix_len += ((ctrl->en_sn == 0) ? 0 : 1);
    return prefix_len;
}

/* 计算链路层帧的payload后的数据长度 */
static inline uint8_t diag_pkt_router_calc_suffix_len(diag_router_ctrl_t *ctrl)
{
    uint8_t suffix_len = 0;

    if (ctrl->en_crc != 0) {
        suffix_len += DIAG_ROUTER_CRC_LEN;
    }

    suffix_len += ctrl->en_eof;
    return suffix_len;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* DIAG_PKT_ROUTER_H */
