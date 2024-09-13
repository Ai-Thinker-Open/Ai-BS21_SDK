/*
 * Copyright (c) @CompanyNameMagicTag 2019-2020. All rights reserved.
 * File          ux_spp_tws.h
 * Description:  Audio ux spp tws interface
 */

#ifndef __UX_SPP_TWS_H__
#define __UX_SPP_TWS_H__

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

uint16_t ux_spp_state_get(void);
void ux_spp_upload_tws_battery_info(void);
void ux_spp_send_info_to_tws(uint8_t service_id, uint8_t command_id);
void ux_spp_tws_send_at_slave_result(const char *buffer, uint16_t buf_len, const char *ack, uint16_t ack_len);

void ux_spp_event_sync_double_click_to_peer(uint8_t type_from_phone, uint8_t value_from_phone);
void ux_spp_event_tws_com_config_set_anc_switch_ack_to_audio(uint8_t type);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
