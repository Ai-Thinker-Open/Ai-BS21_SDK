/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_spp_ios.h
 * Description:  Processes the interaction between the UX and iOS.
 */
#ifndef __UX_SPP_IOS_H__
#define __UX_SPP_IOS_H__

#include <stdbool.h>
#include "ux_types.h"

#define IOS_AUTH_TOKEN_SIZE             32
#define IOS_AUTH_RANDOM_SIZE            16

typedef enum {
    IOS_AUTH_CHECK_SUCCESS = 0x00,
    IOS_AUTH_SESSION_ERR = 0x01,
    IOS_AUTH_TLV_FORMET_ERR = 0x02,
    IOS_AUTH_LOCAL_TOKEN_NULL = 0x03,
    IOS_AUTH_GENERATE_RANDOM_FAIL = 0x04,
    IOS_AUTH_CHECK_TOKEN_FAIL = 0x05,
    IOS_AUTH_INTERNAL_ERROR = 0x06,

    IOS_AUTH_END = 0xFF,
} ios_auth_check_result;

typedef enum {
    IOS_AUTH_RANDOM = 0x01,
    IOS_AUTH_TOKEN = 0x02,
    IOS_AUTH_PAIR_CODE = 0x03,
} ios_auth_value_type;

typedef enum {
    IOS_APP_LINK = 0x01,
} link_type;

typedef struct {
    ux_bd_addr device_addr;
    uint8_t conn_mode;
    uint8_t reserved;
} ble_update_conn_info;

typedef enum {
    GATT_CONN_PARAMS_SLOW,
    GATT_CONN_PARAMS_FAST,
    GATT_CONN_PARAMS_COMPAT,
    GATT_CONN_PARAMS_INVALID,
} service_ble_conn_params_mode_em;

void ux_ios_set_auth_state(uint8_t state);
bool ux_ios_is_need_filter_before_auth(void *param);
void ux_ios_start_auth_timer(ux_bd_addr addr);
void ux_ios_stop_auth_timer(void);
void ux_ios_start_auth_fail_timer(void);
int32_t ux_ios_ble_update_conn_info(bool is_fast, ux_bd_addr addr);

#endif
