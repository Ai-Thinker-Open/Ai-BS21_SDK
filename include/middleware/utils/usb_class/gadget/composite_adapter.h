/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: LiteOS composite adapt HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2022-07-15
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

#ifndef _USB_DEVICE_COMPOSITE_ADAPTER_H
#define _USB_DEVICE_COMPOSITE_ADAPTER_H

#include <stdint.h>
#include <nuttx/usb/usb.h>
#include "implementation/usb_init.h"
#include "implementation/usb_dma_cache.h"
#include "implementation/_printf_ref.h"
#include "implementation/_thread_ref.h"
#include "usb_os_adapt.h"
#include "kal_mem.h"
#ifdef CONFIG_DRIVERS_USB2_DEVICE_CONTROLLER
#include USB_HEADER_PATH
#endif
#ifdef CONFIG_DRIVERS_USB3_DEVICE_CONTROLLER
#include USB3_HEADER_PATH
#endif

#if defined(CONFIG_DRIVERS_USB_ETHERNET_GADGET) || defined(CONFIG_DRIVERS_USB_ETH_SER_GADGET) || \
defined(CONFIG_COMPAT_LINUX_WORKQUEUE)
#include <linux/workqueue.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Composite and usbdev definition for compile. */

#ifndef CODE
#define CODE
#endif
#ifndef FAR
#define FAR
#endif

#ifndef OK
#define OK 0
#endif

#ifdef UNUSED
#undef UNUSED
#define UNUSED(a)
#endif

/* USB controller definition. */

#ifdef CONFIG_DRIVERS_USB_DEVICE_CUSTOM_CTRLREQ_BUF_SIZE
extern uint32_t g_usb_ep0_buffer_size;
#define USB_COMP_EP0_BUFSIZ         g_usb_ep0_buffer_size
#else
#define USB_COMP_EP0_BUFSIZ         4096U
#endif

#define USB_FULL_SPEED_MAX_PACKET_SIZE  64
#define USB_DWC_U2_MAX_PACKET_SIZE      512
#define USB_DWC_MAX_PACKET_SIZE         1024

#ifdef CONFIG_DRIVERS_USB3_DEVICE_CONTROLLER
#define USB_VERSION_BCD 0x0300
#define USB_EP_MPS      0x9
#else
#define USB_VERSION_BCD 0x0200
#define USB_EP_MPS      0x40
#endif

/* USB generic definitions. */

#define USB_COMPOSITE_DEV_NUM 2

#define USB_ALIGN_SIZE(size, align) \
  (((size) + (align) - 1U) & ~((align) - 1U))

#define HSETW(ptr, val)  ptr = { (uint8_t)(val), (uint8_t)((val) >> 8) }
#define HSETDW(ptr, val) ptr = { (uint8_t)(val), (uint8_t)((val) >> 8), \
                                 (uint8_t)((val) >> 16), (uint8_t)((val) >> 24) }

#define USB_GETW(ptr)     \
  ((uint16_t)((ptr)[0]) | \
  (((uint16_t)((ptr)[1])) << 8))

#define USB_SETW(ptr, val)            \
  do {                                \
    (ptr)[0] = (uint8_t)(val);        \
    (ptr)[1] = (uint8_t)((val) >> 8); \
  } while (0)

#define USB_GETDW(ptr)             \
  ((uint32_t)((ptr)[0])          | \
  (((uint32_t)((ptr)[1])) << 8)  | \
  (((uint32_t)((ptr)[2])) << 16) | \
  (((uint32_t)((ptr)[3])) << 24))

#define USB_SETDW(ptr, val)            \
  do {                                 \
    (ptr)[0] = (uint8_t)(val);         \
    (ptr)[1] = (uint8_t)((val) >> 8);  \
    (ptr)[2] = (uint8_t)((val) >> 16); \
    (ptr)[3] = (uint8_t)((val) >> 24); \
  } while (0)

/* This is a flag that device strings struct is ended. */

#define USBD_DEVICE_STRINGS_END { 0, NULL }

#define usbtrace(a, b)
#define TRACE_CLSERROR(a)

#define uinfo(x...)
#define uwarn(x...)
#define uerr(x...)    usb_err(x)

/* Alloc no cache mem from usb memory pool.  */

uint8_t *ep_alloc_buffer(int len);
#define EP_ALLOCBUFFER_NONCACHE(ep,nb)    ep_alloc_buffer(len)
#define EP_FREEBUFFER_NONCACHE(ep,buf)    KAL_MemFree((void *)g_usb_mem_addr_start, buf)
#if defined(CONFIG_DRIVERS_USB_ETHERNET_GADGET) || defined(CONFIG_DRIVERS_USB_ETH_SER_GADGET)
#define work_available(work) ((work)->work_status == 0)
#define work_s work_struct
#define wdog_s work_struct
#endif

/* USB device string. */

struct usbd_string
{
  uint8_t     id;
  const char  *s;
};

struct composite_dev_s;
struct composite_devdesc_s;
struct usbdevclass_driver_s;
struct usbdev_s;
struct usbdev_ep_s;
struct usbdev_req_s;

/* Interface for composite adapter. */

void *composite_initialize(uint8_t ndevices, FAR struct composite_devdesc_s *pdevices);
void composite_uninitialize(FAR void *handle);
int usbd_gadget_attach_driver(void *context, struct usbdevclass_driver_s *driver);
int usbd_gadget_detach_driver(void *context, struct usbdevclass_driver_s *driver);
device_type dev_type_get(void);
bool device_is_uvc(void);
uint32_t composite_spin_lock_irqsave(void);
void composite_spin_unlock_irqrestore(uint32_t flags);
void dev_str_desc_free(struct usbd_string *device_strings);

/* Interface for composite. */

void composite_mkdevdesc(FAR struct composite_dev_s *priv, FAR uint8_t *buf);
void modify_device_descriptor_byspeed(const struct usbdev_s *dev, uint8_t *buf);
int composite_get_config_descriptor(const struct usbdev_s *dev, struct usbdev_req_s *req, unsigned len);
int composite_getstrdesc(FAR struct composite_dev_s *priv, uint8_t id, uint16_t index, FAR uint8_t *buf);
int composite_classsetup_specific(FAR struct composite_dev_s *priv,
                                  FAR struct usbdev_s *dev,
                                  FAR const struct usb_ctrlreq_s *ctrl,
                                  FAR uint8_t *dataout, size_t outlen);
void composite_setup_complete(FAR struct usbdev_ep_s *ep,
                              FAR struct usbdev_req_s *req);

/* Interface for USB class. */

struct composite_devobj_s *usbclass_devobj_get(struct composite_dev_s *cdev, device_type type);
void usbd_configep_byspeed(const struct usbdev_s *dev, struct usb_epdesc_s *ep_desc);
int composite_initialize_softc(uint8_t ndevices, FAR struct composite_devdesc_s *pdevices, void *handle);
int composite_ep0submit(FAR struct usbdevclass_driver_s *driver,
                        FAR struct usbdev_s *dev,
                        FAR struct usbdev_req_s *ctrlreq,
                        FAR const struct usb_ctrlreq_s *ctrl);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_DEVICE_COMPOSITE_ADAPTER_H */
