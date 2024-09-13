/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_spp_midware.h
 * Description:  Audio ux spp middleware management module funciton declaration
 */
#ifndef __UX_SPP_MIDWARE_H__
#define __UX_SPP_MIDWARE_H__

#include <los_typedef.h>
#include "bt_device.h"

int32_t ux_spp_midware_service_send_data(const VOID *param, uint16_t length);
int32_t ux_spp_event_upload_assemble_music_to_phone(void);
void ux_spp_event_midware_service_handle(uint8_t *p_data, uint16_t uw_len);
int32_t ux_spp_midware_init(void);
#endif