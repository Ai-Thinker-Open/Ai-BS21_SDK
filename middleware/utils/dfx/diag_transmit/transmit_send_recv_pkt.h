/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: transmit header file
 * This file should be changed only infrequently and with great care.
 */
#ifndef TRANSMIT_SEND_RECV_PKT_H
#define TRANSMIT_SEND_RECV_PKT_H
#include "diag.h"
#include "transmit_st.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

// subtype: 是否包括子节点; id: type id
#define transmit_build_tlv_type(subtype, id)       ((subtype) << 0x7 | (id))

static inline uint8_t transmit_build_tlv_len(uint32_t size)
{
    if (size <= 0x7F) {
        return (uint8_t)((1U << 0x7) | size);
    } else if (size > 0xFF) {
        return 2; /* fill 2 to lenth field. */
    } else {
        return 1; /* fill 1 to lenth field. */
    }
}

static inline uint32_t transmit_get_tlv_ext_len(uint32_t data_len)
{
    if (data_len <= 0x7F) {
        return 0;
    } else if (data_len > 0xFF) {
        return 2; /* Use 2 bytes to identify the length. */
    } else {
        return 1; /* Use 1 byte to identify the length. */
    }
}

static inline void *transmit_get_tlv_payload(void *cmd_param)
{
    transmit_pkt_tlv_t *tlv = (transmit_pkt_tlv_t *)cmd_param;
    uint8_t offset = 0;

    if ((tlv->len & 0x80) != 0) {
        offset = (uint8_t)sizeof(transmit_pkt_tlv_t);
    } else {
        offset = (uint8_t)sizeof(transmit_pkt_tlv_t) + (tlv->len & 0x7F);
    }

    return ((uint8_t *)cmd_param + offset);
}

typedef errcode_t (*transmit_pkt_recv_hook)(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
    diag_option_t *option, bool from_upper_machine);

errcode_t transmit_receiver_start(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
                                  diag_option_t *option, bool from_upper_machine);

errcode_t transmit_receiver_negotiate(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
                                      diag_option_t *option, bool from_upper_machine);

errcode_t transmit_receiver_data_request(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
                                         diag_option_t *option, bool from_upper_machine);

errcode_t transmit_receiver_data_reply(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
                                       diag_option_t *option, bool from_upper_machine);

errcode_t transmit_receiver_notify(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
                                   diag_option_t *option, bool from_upper_machine);

errcode_t transmit_receiver_stop(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size,
                                 diag_option_t *option, bool from_upper_machine);

errcode_t transmit_send_packet(uint8_t cmd_id, uint8_t *pkt, uint32_t pkt_size, diag_option_t *option,
                               bool down_machine);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* TRANSMIT_SEND_RECV_PKT_H */
