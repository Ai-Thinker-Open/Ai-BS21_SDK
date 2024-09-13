/*
 * Copyright (c) @CompanyNameMagicTag 2019-2020. All rights reserved.
 * File          ux_spp_common.h
 * Description:  Audio ux common spp interface
 */

#ifndef __UX_SPP_COMMON_H__
#define __UX_SPP_COMMON_H__

#include "ux_manager_common.h"
#include "bt_device.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define ANC_DATA_LEN   3
#define UX_SPP_SUPPORT_NOISYROL_CONTOLR_FUNC_NUM 10
#define UX_SPP_SUPPORT_LONG_PRESS_FUNC_NUM 12
#define INVALID_ANC_MODE_IN_TIGER 255
#define SPP_REQ_BUF_LAST_TYPE_OFFSET 2

typedef enum {
    SPP_RESP_ERR_CODE_SUCCESS       = 100000,
    SPP_RESP_ERR_CODE_UNKNOW        = 100001,
    SPP_RESP_ERR_CODE_NOT_SUPPORTED = 100003,
    SPP_RESP_ERR_CODE_PARAMETER_ERR = 100007,
} ux_spp_resp_err_codes_type;

typedef enum {
    PRIVATE_MUSIC_ASSEMBLE = 0x03,
}midware_service_command_id;

typedef enum {
    FONT_TYPE_SET = 0x01,
    FONT_TYPE_GET,
} font_service_command_id;

typedef struct data_transport_data_n {
    data_transport_data data;
    struct data_transport_data_n *prev;
    struct data_transport_data_n *next;
} data_transport_data_node;

typedef enum {
    UX_SPP_GET_PAIR_FREE_DEV_INFO_TYPE_MODEL = 0x02,
} ux_spp_get_pair_free_dev_info_type_t;

typedef enum {
    MUSIC_ASSEMBLE_SUCCESS = 100000,
    APP_IS_NOT_INSTALLED = 133001,
    NOT_LOGGED_IN = 133002,
    NETWORK_NOT_CONNECT = 133003,
    ASSEMBLE_FAILED = 133004,
    LOCAL_VERSION = 133008,
    MUSIC_ASSEMBLE = 133009,
    AGREEMENT_NOT_CONFIRMED = 133010,
    LOWER_APP_VERSION = 133011,
    APP_RESPONSE_TIMEOUT = 100009,
} music_assemble_error_code;

typedef enum {
    ASSEMBLE_CURRENT_MUSIC = 1,
    PLAY_MUSIC_IN_FAVORITE_FOLDER,
}ux_spp_upload_music_assemble_type_t;

int32_t ux_spp_event_init(void);
int32_t ux_spp_event_handle(ux_cmd_msg_t *cfg_msg);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
