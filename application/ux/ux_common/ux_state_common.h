/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_state_common.h
 * Description:  Audio ux common state
 */
#ifndef __UX_STATE_COMMON_H__
#define __UX_STATE_COMMON_H__

#include <std_def.h>
#include <los_typedef.h>
#include "bt_device.h"
#include "ux_types.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

typedef struct {
    int8_t hfp_vol;
    int8_t avrcp_vol;
    int8_t mic_role;
    bool is_mute;
    service_a2dp_stream_config_s a2dp_codec_setting;
    service_hfp_config_s sco_codec_setting;
} ux_audio_config;

typedef struct {
    uint16_t sub_version;
    uint8_t advanced_version;
    uint8_t market;
} ux_version_number;

typedef struct {
    char version[VERSION_NAME_LEN]; // version to phone
    char model_name[VERSION_NAME_LEN];
    char ota_name[VERSION_NAME_LEN];
} ux_version_state;

typedef struct {
    uint32_t unix_timestamp;  // from 1970/01/01
    int16_t utc_time_zone;     // high bit: 1 for negative; 0 for positive;
} ux_time_setting;

typedef struct {
    uint8_t state;  // ota_status
} ux_ota_state;

ux_audio_config *ux_get_audio_config(void);
ux_version_state *ux_get_version(void);

uint8_t ux_get_ota_state(void);
void ux_set_ota_state(uint8_t state);

void ux_time_state_set(uint32_t timestamp, int16_t time_offset);
void ux_time_state_get(uint32_t *timestamp, int16_t *time_offset);

void ux_ota_state_change_handle(uint8_t old_state, uint8_t new_state);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif

