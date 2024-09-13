/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2023. All rights reserved.
 * Description: LiteOS USB Driver HID HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2019-10-24
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --------------------------------------------------------------------------- */

#ifndef _USB_HID_INCLUDE_H
#define _USB_HID_INCLUDE_H

#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Define usb hid gadget path. */

#define USB_HID_DEV "/dev/hid"

#ifdef CONFIG_DRIVERS_USB_HID_FUNC_INTERFACE
int hid_add_report_descriptor(const uint8_t *report_desc, size_t report_desc_len, uint8_t protocol);
size_t fhid_send_data(uint8_t report_index, const char *buf, size_t buflen);
#ifdef CONFIG_DRIVERS_USB_HID_OUTPUT_REPORT
typedef void(*fhid_recv_cb_t)(uint8_t *buf, uint32_t len);
bool fhid_register_output_callback(int32_t device_id, fhid_recv_cb_t cb);
bool fhid_unregister_output_callback(int32_t device_id);
size_t fhid_recv_data(uint8_t report_index, char *buf, size_t buflen);
#endif /* CONFIG_DRIVERS_USB_HID_OUTPUT_REPORT */
#else /* CONFIG_DRIVERS_USB_HID_VFS_INTERFACE */
int hid_report_descriptor_info(const void *report_desc, size_t report_desc_len);
#endif /* CONFIG_DRIVERS_USB_HID_FUNC_INTERFACE */
size_t fhid_get_protocol(uint8_t device_id);
void fhid_set_protocol(uint8_t device_id, uint32_t val);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_HID_INCLUDE_H */