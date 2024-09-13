/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: ota upgrade header file
 */

#ifndef OTA_UPGRADE_H
#define OTA_UPGRADE_H

#include "diag_service.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef errcode_t (*upgrade_pkt_recv_hook)(uint8_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size, uint8_t dst);

errcode_t ota_upgrade_service_process(diag_ser_data_t *data);

errcode_t uapi_upgrade_init(void);

typedef enum {
    OTA_UPGRADE_STATE_NONE     = 0x0,
    OTA_UPGRADE_STATE_PERMIT   = 0x1,
    OTA_UPGRADE_STATE_START    = 0x2,
    OTA_UPGRADE_STATE_END      = 0x3,
} ota_upgrade_state_t;

typedef errcode_t (*ota_upgrade_state_changed_callback)(ota_upgrade_state_t upgrade_state, errcode_t upgrade_errcode);

errcode_t ota_upgrade_callback_register(ota_upgrade_state_changed_callback func);

void ota_upgrade_callback_unregister(void);

ota_upgrade_state_changed_callback ota_upgrade_get_callback(void);

errcode_t ota_upgrade_transmit_result_cb(bool is_finished, uintptr_t usr_data);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif