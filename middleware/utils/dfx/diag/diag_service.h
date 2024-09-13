/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: diag service header file
 */

#ifndef DIAG_SERVICE_H
#define DIAG_SERVICE_H

#include <unistd.h>
#include "errcode.h"
#include "stdbool.h"
#include "diag_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    DIAG_SER_DEV_STATUS = 1,
    DIAG_SER_OTA,
    DIAG_SER_HEAR_AID_BUSUBESS,
    DIAG_SER_HEAR_AID_PARAM,
    DIAG_SER_MAINTENANCE,
    DIAG_SER_FILE_TRANFER,
    DIAG_SER_DEV_CONFIG,
    DIAG_SER_APP_TEST,
    DIAG_SER_BT_TEST,
    DIAG_SER_MEDIA_TEST,
    DIAG_SER_GRAPHIC_TEST,
    DIAG_SER_AUDIO_TEST,
    DIAG_SER_MSG_CENTER,
    DIAG_SER_INTER_MAX, /* 内部ID的最大值，增加内部ID需要在这个宏上面增加 */
    DIAG_SER_CUSTOM_SERVICE = 127,
    DIAG_SER_MAX,
    DIAG_SER_RESERVED = 0x80,
} diag_ser_id_t;

typedef struct {
    uint8_t        module_id;
    uint8_t        cmd_id;
    uint8_t        tlv[0];
} diag_ser_frame_t;

typedef struct {
    uint8_t           ser_id;  /* 业务模块id, 同module_id */
    uint8_t           cmd_id;  /* cmd_id, 同frame中的cmd_id */
    uint8_t           src;     /* 数据来源 */
    uint8_t           dst;     /* 数据目的地 */
    bool              crc_en;  /* 当前帧数据是否使能crc16校验 */
    bool              ack_en;  /* 当前帧数据是否需要对端回复ack */
    uint16_t          length;  /* 有效数据长度，包括module_id/cmd_id/payload(tlv) */
} diag_ser_header_t;

typedef struct {
    diag_ser_header_t   header;
    uint8_t             payload[0];   /* 包括module_id/cmd_id/payload(tlv) */
} diag_ser_data_t;

typedef enum {
    DIAG_DATA_NO_MERGE,
    DIAG_DATA_MERGED,
    DIAG_DATA_MERGING,
} diag_merge_data_status;

typedef struct {
    diag_merge_data_status status;
    uint8_t module_id;
    uint8_t cmd_id;
    uint8_t last_sn;
    uint16_t offset;
    uint8_t *buff;
} diag_merge_data_t;

typedef errcode_t (*diag_notify_f)(diag_ser_data_t *data);

errcode_t diag_service_data_proc(diag_router_frame_t *data, uint16_t data_len);

errcode_t uapi_diag_service_register(diag_ser_id_t module_id, diag_notify_f func);

errcode_t uapi_diag_service_send_data(diag_ser_data_t *data);

void uapi_diag_service_init(void);

#ifdef __cplusplus
}
#endif

#endif /* DIAG_SERVICE_H */
