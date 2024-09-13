/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: transmit header file
 * This file should be changed only infrequently and with great care.
 */
#ifndef __TRANSMIT_H__
#define __TRANSMIT_H__

#include "errcode.h"
#include "diag_service.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

errcode_t uapi_transmit_init(void);

errcode_t transmit_msg_proc(uint32_t msg_id, const uint8_t *msg, uint32_t msg_len);

typedef errcode_t (*transmit_result_hook)(bool is_finished, uintptr_t usr_data);

transmit_result_hook transmit_item_get_dst_result_hook(void);

errcode_t transmit_item_dst_result_hook_register(transmit_result_hook dst_result_hook);

void transmit_item_dst_result_hook_unregister(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
