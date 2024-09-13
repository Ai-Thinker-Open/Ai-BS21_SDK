/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2021. All rights reserved.
 * Description: Usb Init Head File
 * Author: Huawei LiteOS Team
 * Create: 2013-01-01
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

#ifndef _USB_INIT_H
#define	_USB_INIT_H

#include "stdint.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Controller type */
typedef enum controller_type {
	HOST = 0,
	DEVICE
} controller_type;

/* device speed */
typedef enum device_speed {
    USB_FULL_SPEED = 2,
    USB_HIGH_SPEED = 3
} device_speed_t;

/* device type */
typedef enum device_type {
	DEV_START,		/* start value of the device type */
	DEV_SERIAL,		/* used for serial */
	DEV_ETHERNET,	/* used for rndis */
	DEV_SER_ETH,	/* used for serial and rndis */
	DEV_DFU,		/* used for DFU */
	DEV_MASS,		/* used for mass */
	DEV_UVC,		/* used for USB video */
	DEV_UAC,		/* used for USB audio */
	DEV_CAMERA,		/* used for USB camera */
	DEV_HID,		/* used for USB hid */
	DEV_CUSTOM,		/* used for USB custom */
	DEV_UAC_HID,    /* used for USB uac and hid */
	DEV_SER_HID,    /* used for USB uac and hid */
	DEV_END			/* end value of the device type */
} device_type;

struct device_string
{
	const char *str;	/* string descriptor */
	uint32_t len;		/* String descriptor length */
};

struct device_id
{
	uint16_t vendor_id;		/* Vendor id */
	uint16_t product_id;	/* Product id */
	uint16_t release_num;	/* Device release number */
};

/*
 * Function:usb_init
 * Description: initialize the controller of usb, attach the usb protocol.
 * Input: ctype ------ the type of usb's controller, the legal value is one of 'controller_type';
 * 					if it is HOST , 'dtype' can be any value of 'device_type';
 * 					if it is DEVICE, 'dtype' must be one of 'device_type' that user needs.
 *		  dtype ------ the type of device, the legal value is one of 'device_type';
 * 					if 'ctype' is DEVICE, it is determined by the use requirements.
 * Output: None
 * Return: success is LOS_OK, failure is LOS_NOK.
 */
uint32_t usb_init(controller_type ctype, device_type dtype);

/*
 * Function:usb_deinit
 * Description: uninitialize the controller of usb, detach the usb protocol.
 * Input: None
 * Output: None
 * Return: success is LOS_OK, failure is LOS_NOK.
 */
uint32_t usb_deinit(void);

/*
 * Function:usb_is_devicemode
 * Description: check usb device mode.
 * Input: None
 * Output: None
 * Return: true is usb device mode, false is not linked or not usb device mode.
 */
bool usb_is_devicemode(void);

/*
 * Function:usbd_set_device_info
 * Description: Set device VID, PID and string descriptor information.
 * Input:dtype ------ the type of device, the legal value is one of 'device_type';
 * 		 str_manufacturer ------ manufacturer string information.
 * 		 str_product  ------ product string information.
 * 		 str_serial_number  ------ serial number string information.
 * 		 dev_id  ------ VID, PID and device release number.
 * Output: None
 * Return: success is LOS_OK, failure is LOS_NOK.
 */
uint32_t usbd_set_device_info(device_type dtype,
							  const struct device_string *str_manufacturer,
							  const struct device_string *str_product,
							  const struct device_string *str_serial_number,
							  struct device_id dev_id);

#ifdef CONFIG_DRIVERS_USB2_DEVICE_CONTROLLER
/*
 * Function:usb_device_is_host_suspended
 * Description: check whether the host is suspended.
 * Input: None
 * Output: None
 * Return: true: host is suspended, false: host is not suspended.
 */
bool usb_device_is_host_suspended(void);

/*
 * Function:usb_device_remote_wakeup
 * Description: usb device remotely wakes up the suspended host.
 * Input: None
 * Output: None
 * Return: 0: remote wakeup operation succeeded, -1: remote wakeup operation failed.
 */
int usb_device_remote_wakeup(void);

/*
 * Function:usb_device_set_speed
 * Description: set custom speed of usb(fs/hs), default speed is hs. If you want to initialize USB in full-speed mode,
 *              you need to set the speed before calling usb_init() every time.
 * Input: speed: 2 means full-speed, 3 means high-speed.
 * Output: None
 * Return: 0: speed set succeeded, -1: param invalid, speed set failed.
 */
int usb_device_set_speed(device_speed_t speed);

/*
 * Function:usb_ep0_do_stall
 * Description: stall unsupport requests when enable custom enum.
 * Input: None.
 * Output: None
 * Return: 0: stall succeeded, -1: usb  is not initialized or custom enum is not enabled.
 */
int usb_ep0_do_stall(void);

/*
 * Function:usb_device_enable_custom_enum
 * Description: enable custom enum, and all request will be reported to composite.c(g_driverops.setup function),
 *              You need to reply on your own.
 * Input: None.
 * Output: None
 * Return: None.
 */
void usb_device_enable_custom_enum(void);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_INIT_H */
