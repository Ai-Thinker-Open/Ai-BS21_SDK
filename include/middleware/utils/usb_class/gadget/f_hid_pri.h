/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2023. All rights reserved.
 * Description: LiteOS USB Driver HID Protocol Private HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2021-08-19
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

#ifndef _F_HID_PRI_H
#define _F_HID_PRI_H

#include <kal_atomic.h>
#include "gadget/f_hid.h"
#include "gadget/usbdev.h"
#include "gadget/composite.h"
#include "implementation/_thread_ref.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef CONFIG_DRIVERS_USB_HID_FUNC_INTERFACE
#define HID_REPORT_MAP_NUM CONFIG_DRIVERS_USB_HID_REPORT_MAP_NUM
#else
#define HID_REPORT_MAP_NUM 1
#endif

#define HID_IN_DATA_SIZE   0x40u
#define HID_WRITE_BUF_SIZE CONFIG_DRIVERS_USB_HID_INPUT_REPORT_LEN
#define HID_WRITE_BUF_NUM  8

#ifdef CONFIG_DRIVERS_USB_HID_OUTPUT_REPORT
#define HID_OUT_DATA_SIZE  0x100u

enum hid_read_event
{
  USB_HID_READ_EVENT = 1u << 0,
  USB_HID_EXIT_EVENT = 1u << 1,
};
#endif /* CONFIG_DRIVERS_USB_HID_OUTPUT_REPORT */

struct hid_data_ctl
{
  struct usbdev_ep_s *in_ep;  /* Interrupt input endpoint */
  bool in_ep_enabled;
  struct usbdev_req_s inputreq;  /* HID report request */

  struct usbdev_ep_s *out_ep;  /* Interrupt output endpoint */
  bool out_ep_enabled;
  struct usbdev_req_s outputreq;  /* HID report request */

  uint8_t *write_buf[HID_WRITE_BUF_NUM];
  uint32_t write_len[HID_WRITE_BUF_NUM];
  uint32_t write_buf_len;
  uint32_t write_head;
  uint32_t write_tail;
  uint8_t write_busy;

#ifdef CONFIG_DRIVERS_USB_HID_OUTPUT_REPORT
  uint32_t out_report_len;
  void *read_buf;
  size_t read_len;
  fhid_recv_cb_t read_callback;
  EVENT_CB_S read_event;
  bool event_flag;
#endif /* CONFIG_DRIVERS_USB_HID_OUTPUT_REPORT */
  KalSpinLock hid_lock;

  uint8_t idle_value; /* Save the idle value requested by the host */
  uint8_t protocol;   /* Save the protocol value requested by the host */
};

struct hid_dev_s
{
  struct hid_data_ctl hid_data[HID_REPORT_MAP_NUM];
  uint8_t connected; /* Hid device connection status. 1: connected, 0: disconnected */
};

struct hid_driver_s
{
  struct usbdevclass_driver_s drvr;
  struct hid_dev_s *dev;
};

struct hid_softc
{
  struct hid_dev_s dev;
  struct hid_driver_s drvr;
};

void usbdev_hid_initialize_sub(struct composite_devdesc_s *dev, int ifnobase, int minor);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _F_HID_PRI_H */
