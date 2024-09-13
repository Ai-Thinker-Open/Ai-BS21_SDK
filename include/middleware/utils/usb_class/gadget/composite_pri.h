/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 * Description: LiteOS USB Driver composite private HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2020-06-20
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

#ifndef _USB_DEVICE_COMPOSITE_PRI_H
#define _USB_DEVICE_COMPOSITE_PRI_H

#include "gadget/composite_adapter.h"
#include "gadget/usbdev.h"
#include "gadget/composite.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define STRING_HEAD_LEN   2
#define STRING_DESC_NUM   3
#define STRING_LEN_MAX    0xFF

void mass_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void uvc_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void uac_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void camera_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void acm_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void eth_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void multi_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void dfu_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void hid_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void uac_hid_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);
void acm_hid_get_device_dec_info(struct usbd_string **device_strings, struct usb_devdesc_s **device_desc);

int usbdev_mass_initialize(void *handle);
int usbdev_uvc_initialize(void *handle);
int usbdev_uac_initialize(void *handle);
int usbdev_uac2_initialize(void *handle);
int usbdev_camera_initialize(void *handle);
int usbdev_acm_initialize(void *handle);
int usbdev_rndis_initialize(void *handle);
int usbdev_multi_initialize(void *handle);
int usbdev_dfu_initialize(void *handle);
int usbdev_hid_initialize(void *handle);
int usbdev_uac_hid_initialize(void *handle);
int usbdev_test_initialize(void *handle);
int usbdev_acm_hid_initialize(void *handle);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_DEVICE_COMPOSITE_PRI_H */