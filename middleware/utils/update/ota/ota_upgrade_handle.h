/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: ota upgrade handle header file
 */

#ifndef OTA_UPGRADE_HANDLE_H
#define OTA_UPGRADE_HANDLE_H

#include <stdint.h>
#include "osal_debug.h"
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#ifdef CONFIG_OTA_LOG_ENABLE
#define ota_log_print(fmt...) osal_printk(fmt)
#else
#define ota_log_print(fmt...)
#endif

typedef enum {
    UPG_INFO_TYPE_VER,
    UPG_INFO_TYPE_PERMIT,
    UPG_INFO_TYPE_RESEND,
    UPG_INFO_TYPE_IMAGE_FLAG,
} upgrade_type_t;

typedef struct {
    uint8_t type;
    uint8_t len;
    uint8_t value[0];
} tlv_t;

typedef struct {
    uint16_t info_type;
    uint16_t info_size;
    uint8_t info[0];
} info_ack_t;

typedef struct {
    uint32_t node;
    uint32_t len;
    uint8_t hash[0];
} file_flag_t;

errcode_t ota_upgrade_prepare(uint8_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size, uint8_t dst);

errcode_t ota_upgrade_request(uint8_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size, uint8_t dst);

errcode_t ota_upgrade_start(uint8_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size, uint8_t dst);

errcode_t ota_upgrade_getinfo(uint8_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size, uint8_t dst);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif