/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: LiteOS USB Driver Virtual Serial file.
 * Author: Huawei LiteOS Team
 * Create: 2022-11-02
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

#ifndef _F_ACM_H
#define _F_ACM_H

#include <los_event.h>
#ifdef CONFIG_DRIVERS_USB_SERIAL_VFS_INTERFACE
#include <fs/fs.h>
#endif
#ifdef CONFIG_ENABLE_MAGICKEY
#include "magickey.h"
#endif
#include <console.h>
#include <los_atomic.h>
#include <los_hwi.h>
#include "gadget/usbd_cdc.h"
#include "gadget/composite.h"
#include "gadget/composite_pri.h"
#include "implementation/_thread_ref.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef LOSCFG_DRIVERS_USB_SERIAL_GADGET_DUAL
#define NUM_SERIAL 2
#else
#define NUM_SERIAL 1
#endif

#ifdef LOSCFG_DRIVERS_USB3_DEVICE_CONTROLLER
#define DWC3_USB_SERIAL
#endif

#ifdef DWC3_USB_SERIAL
#define MAX_PACKET_SIZE 0x400
#else
#define MAX_PACKET_SIZE 0x200
#endif

#define ACM_NOTIFY_SERIAL_STATE 0x20

#define ACM_GET_LINE_STATE      0x21

#define ACM_SET_LINE_STATE      0x20

#define ACM_SET_CTRL_LINE_STATE 0x22

#define SIZEOF_ACM_LINE_STATE   7

#define USB_SERIAL_READ_EVENT   0x11

#define DEVICE_VERSION          0x0100

#define RING_BUFFER_SIZE        1024U

#define STAE_BUFFER_OFFSET      1

enum acm_ep_index
{
  ACM_INTERRUPT_EP_IDX = 0,
  ACM_BULKIN_EP_IDX,
  ACM_BULKOUT_EP_IDX
};

#define ACM_EP_NUM_PER_PORT     3

#define ACM_SET_INTERRUPT_EP_NUM(desc, index) ((desc)->epno[ACM_INTERRUPT_EP_IDX + ACM_EP_NUM_PER_PORT * (index)])

#define ACM_SET_BULKIN_EP_NUM(desc, index)    ((desc)->epno[ACM_BULKIN_EP_IDX + ACM_EP_NUM_PER_PORT * (index)])

#define ACM_SET_BULKOUT_EP_NUM(desc, index)   ((desc)->epno[ACM_BULKOUT_EP_IDX + ACM_EP_NUM_PER_PORT * (index)])

#define ACM_TOTAL_EP_NUM            (ACM_EP_NUM_PER_PORT * NUM_SERIAL)
#define ACM_CONFIG_NUM              1
#define ACM_IF_NUM_PER_PORT         2 /* Interfaces number per serial port */
#define ACM_CONFIG_ID               1 /* The only supported configuration ID */
#define ACM_STR_ID_NUM              4

/* Number of interfaces in the configuration */

#define ACM_INTERFACE_NUM           (ACM_IF_NUM_PER_PORT * NUM_SERIAL)

#define ACM_CONNECT_STATE           0x03

#ifdef DWC3_USB_SERIAL
#define ACM_IN_REQ_LEN              0x400
#define ACM_OUT_REQ_LEN             0x400
#else
#define ACM_IN_REQ_LEN              0x200
#define ACM_OUT_REQ_LEN             0x200
#endif

#define ACM_REQ_TYPE_INTERFACE      0x21

#define ACM_DEVNAME_FORMAT          "/dev/ttyGS%d"
#define ACM_DEVNAME_SIZE            16

#define ACM_DATA_SPEED              9600
#define ACM_DATA_BIT                8

#define ACM_UNBIND_EVENT            0x1

#define ACM_DRIVE_MODE              0666

enum acm_state_e
{
  ACM_UNBIND_STATE     = 0x1,
  ACM_READ_BUSY_STATE  = 0x1 << 1,
  ACM_WRITE_BUSY_STATE = 0x1 << 2,
  ACM_IOCTL_BUSY_STATE = 0x1 << 3
};

struct acm_hs_function_descriptor
{
  struct usb_iaddesc_s ifcad;
  struct usb_ifdesc_s ifcd; /* Acm control interface descriptor */
  struct cdc_header_func_desc cdc_desc;
  struct cdc_cm_func_desc cdc_call_desc;
  struct cdc_acm_func_desc cdc_acm_desc;
  struct cdc_union_func_desc cdc_union_desc;
  struct usb_epdesc_s nepd;
#ifdef DWC3_USB_SERIAL
  struct usb_ss_comp_epdesc_s ncompd;
#endif
  struct usb_ifdesc_s ifdd;
  struct usb_epdesc_s iepd;
#ifdef DWC3_USB_SERIAL
  struct usb_ss_comp_epdesc_s icompd;
#endif
  struct usb_epdesc_s oepd;
#ifdef DWC3_USB_SERIAL
  struct usb_ss_comp_epdesc_s ocompd;
#endif
} __attribute__ ((packed));

struct acm_hs_function_descriptor_multi
{
  struct acm_hs_function_descriptor func_descriptor[NUM_SERIAL];
};

struct acm_wrreq_s
{
  struct usbdev_req_s *req;            /* The write request */
  char *data_buffer;                   /* Ringbuffer starting address ,this is data buffer yet */
  char *receive_buffer;                /* Record the offset of the received data */
  char *send_buffer;                   /* Record the offset of the sent data */
};

struct acm_rdreq_s
{
  struct usbdev_req_s *req;            /* The read request */
  void *buf;                           /* The read event buffer */
  size_t buflen;                       /* Offset to valid data in the RX request */
};

struct acm_data_ctrl
{
  uint8_t acm_flag;
  spinlock_t acm_lock;                 /* Spinlock */
  uint16_t serialstate;
  bool bdisconnect;                    /* Flags of device action */
  bool read_pend;                      /* Pending status for read */
  struct usbdev_ep_s *epintin;         /* Interrupt IN endpoint structure */
  struct usbdev_ep_s *epbulkin;        /* Bulk IN endpoint structure */
  struct usbdev_ep_s *epbulkout;       /* Bulk OUT endpoint structure */
  bool epintin_enabled;                /* Interrupt IN endpoint enable flag */
  bool epbulkin_enabled;               /* Bulk IN endpoint enable flag */
  bool epbulkout_enabled;              /* Bulk OUT endpoint enable flag */
  struct acm_wrreq_s wrreqs;           /* Serial write buffer */
  struct acm_rdreq_s rdreqs;           /* Serial read buffer */
  EVENT_CB_S read_event;               /* Read event */
  uint32_t read_offset;                /* Quick command offset */
  bool waiting;                        /* If notify request is NULL, try submit(notify, req) again */
  bool received_char;                  /* Flags of write event */
  Atomic shutdown;                     /* Device shutdown when transfer data */
  Atomic send_char;                    /* Flag of read event */
};

/* This structure describes the internal state of the driver */

struct acm_dev_s
{
  struct usbdev_s *usbdev;                      /* Usb device pointer */
  struct cdc_line_coding_state line_state;      /* Serial status */
  struct usbdev_req_s *ctrlreq;                 /* control request */
  struct usbdev_devinfo_s devinfo;
  struct acm_data_ctrl datactrl[NUM_SERIAL];    /* Data control structures */
  EVENT_CB_S unbind_event;
  spinlock_t state_lock;
  uint8_t config;                               /* Configuration number */
  uint8_t ctrl_id;                              /* Control id of Interface-IDs */
  uint8_t data_id;                              /* Data id of Interface-IDs */
};

/* This structure describes a serial device with port number */

struct acm_dev_node
{
  struct acm_dev_s *dev;
  int index;
};

/* Serial port driver structure */

struct acm_driver_s
{
  struct usbdevclass_driver_s drvr;
  struct acm_dev_s dev;
};

#ifdef CONFIG_DRIVERS_USB_SERIAL_VFS_INTERFACE
int usbclass_acm_ioctl(struct file *filep, int cmd, unsigned long arg);
ssize_t usbclass_acm_read(struct file *filep, char *buffer, size_t buflen);
ssize_t usbclass_acm_write(struct file *filep, const char *buffer, size_t buflen);
int usbclass_acm_open(struct file *filep);
#else
struct acm_driver_s *acm_get_acm_driver(void);
#endif

void acm_wrcomplete_check_send_result(struct usbdev_ep_s *ep,
                                      struct usbdev_req_s *req);
void acm_rdcomplete_process_req(struct usbdev_ep_s *ep,
                                struct usbdev_req_s *req);
void acm_ep0incomplete_notify_callback(struct usbdev_ep_s *ep,
                                       struct usbdev_req_s *req);
int acm_send_out_req(struct acm_data_ctrl *datactrl,
                     struct acm_rdreq_s *rdcontainer);
int acm_serial_connect(struct acm_dev_s *priv, int index);
int acm_serial_disconnect(struct acm_dev_s *priv, int index);

void usbdev_acm_initialize_dev(struct composite_devdesc_s *dev, int ifnobase, int minor);

unsigned int userial_mask_get(void);

void userial_mask_set(unsigned int val);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _F_ACM_H */
