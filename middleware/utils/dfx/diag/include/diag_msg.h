/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: zdiag msg
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_MSG_H
#define DIAG_MSG_H

#include "errcode.h"
#include "diag_common.h"
#include "diag_channel.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef bool (*diag_msg_flow_control_hook)(uint8_t mid, uint8_t level);

errcode_t diag_msg_proc(uint16_t msg_id, uint8_t *msg, uint32_t msg_len);

void uapi_zdiag_set_offline_log_enable(bool enable);
bool uapi_zdiag_offline_log_is_enable(void);

void uapi_diag_register_msg_flow_control_hook(diag_msg_flow_control_hook func);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
