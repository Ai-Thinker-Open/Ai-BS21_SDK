/*
 * Copyright (c) @CompanyNameMagicTag 2019-2020. All rights reserved.
 * File          ux_spp_interface.h
 * Description:  Audio ux spp weak interface, need to implete in product if need
 */
#ifndef __UX_SPP_INTERFACE_H__
#define __UX_SPP_INTERFACE_H__

#include <stdint.h>
#include "bt_device.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

void ux_spp_event_multi_dev_com_handle(const uint8_t *p_data, uint16_t uw_len);
void ux_spp_event_set_anc_switch_to_other_dev_phone_trigger(uint8_t value, uint8_t ai_or_ah_switch);
int32_t ux_spp_multi_device_init(void);
int32_t ux_spp_multi_dev_com_send_data(const void *param, uint16_t length, uint8_t business_type);
uint32_t ux_spp_get_cur_dev_resend_other_header(const data_transport_data *header, uint16_t data_len);
uint32_t ux_spp_get_cur_intelli_resend_other_header(const data_transport_data *header, uint16_t data_len);
void UX_SppEventSendTwsNoisyControlFunc(uint8_t value_from_phone);
void ux_spp_send_tws_intelligent_anc_param(uint8_t type_from_phone, uint8_t confidence_state);
void ux_spp_event_set_noisy_control_to_dev(uint8_t value);

int32_t ux_spp_event_set_long_press_to_dev(uint8_t type_from_phone, uint8_t value_from_phone);
void ux_spp_event_set_long_press_to_other_dev(uint8_t type_from_phone, uint8_t value_from_phone);
int32_t ux_spp_event_get_long_press_info(uint8_t type, const void *value);
uint16_t ux_spp_event_get_long_press_info_len(void);
uint32_t ux_spp_get_cur_midware_service_resend_other_header(data_transport_data *header, uint16_t data_len);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
