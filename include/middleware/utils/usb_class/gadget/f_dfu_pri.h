/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: LiteOS USB Driver DFU Protocol Private HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2021-08-17
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

#ifndef _USB_F_DFU_PRI_H
#define _USB_F_DFU_PRI_H

#include "gadget/f_dfu.h"
#include "gadget/usbdev.h"
#include "implementation/_thread_ref.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef CONFIG_DRIVERS_USB_DFU_DRIVE_FREE
#define COMPATIBLE_ID_LEN        8
#define STRING_WINUSB_LEN        6
#define MULTI_LINE_STRING_TYPE   7
#define STRING_PROPERTY_NAME_LEN 42
#define STRING_GUID_LEN          70
struct usb_os_msft_proerty_desc
{
  uint32_t dwSize;
  uint32_t dwPropertyDataType;
  uint16_t wPropertyNameLength;
  uint8_t  bPropertyName[STRING_PROPERTY_NAME_LEN];
  uint32_t dwPropertyDataLength;
  uint8_t  bPropertyData[STRING_GUID_LEN];
};
#endif

struct dfu_status_response
{
  uint8_t bStatus;
  uint8_t bPollTimeout[3]; /* The poll timeout duration is represented by 3 bytes. */
  uint8_t bState;
  uint8_t bStringIdx;
};

struct usb_dfu_dev
{
  struct dfu_status_response dfu_status;
  int dfu_state;
  uint32_t seq_num;
};

struct dfu_func_desc
{
  uint8_t bFunctionLength;
  uint8_t bDescriptorType;
  uint8_t bAttributes;
  uint8_t bDetachTimeout[2]; /* The protocol requires 2 bytes to indicate the detach timeout. */
  uint8_t bTransferSize[2];  /* The protocol requires 2 bytes to indicate the transfer size. */
  uint8_t bDfuVersion[2];    /* The protocol requires 2 bytes to indicate the DFU version. */
};

struct dfu_dev_s
{
  struct usbdev_req_s *ctrlreq;
};

struct dfu_driver_s
{
  struct usbdevclass_driver_s drvr;
  struct dfu_dev_s dev;
};

/* Minimum time, in milliseconds, that the host should wait before
 * sending a subsequent DFU_GETSTATUS request.
 */

#define USB_DFU_POLLTIMEOUT 100

/* Define the return value for request */

#define USB_DFU_RET_ERR        -1
#define USB_DFU_RET_OK          0
#define USB_DFU_RET_STATUS_LEN  6
#define USB_DFU_RET_STATE_LEN   1
#define USB_DFU_STATUS_OK       0

/* Define the type for request */

#define USB_DFU_DETACH      0
#define USB_DFU_DNLOAD      1
#define USB_DFU_UPLOAD      2
#define USB_DFU_GET_STATUS  3
#define USB_DFU_CLR_STATUS  4
#define USB_DFU_GET_STATE   5
#define USB_DFU_ABORT       6
#define USB_DFU_FLASH_STATE 7

/* Define the state for request */

#define USB_DFU_APP_IDLE            0
#define USB_DFU_APP_DETACH          1
#define USB_DFU_IDLE                2
#define USB_DFU_DNLOAD_SYNC         3
#define USB_DFU_DNBUSY              4
#define USB_DFU_DNLOAD_IDLE         5
#define USB_DFU_MANIFEST_SYNC       6
#define USB_DFU_MANIFEST            7
#define USB_DFU_MANIFEST_WAIT_RESET 8
#define USB_DFU_UPLOAD_IDLE         9
#define USB_DFU_ERROR              10

/* Define the status for request */

#define USB_DFU_OK                0x00
#define USB_DFU_ERR_TARGET        0x01
#define USB_DFU_ERR_FILE          0x02
#define USB_DFU_ERR_WRITE         0x03
#define USB_DFU_ERR_ERASE         0x04
#define USB_DFU_ERR_CHECK_ERASED  0x05
#define USB_DFU_ERR_PROG          0x06
#define USB_DFU_ERR_VERIFY        0x07
#define USB_DFU_ERR_ADDRESS       0x08
#define USB_DFU_ERR_NOTDONE       0x09
#define USB_DFU_ERR_FIRMWARE      0x0A
#define USB_DFU_ERR_VENDOR        0x0B
#define USB_DFU_ERR_USBR          0x0C
#define USB_DFU_ERR_POR           0x0D
#define USB_DFU_ERR_UNKNOWN       0x0E
#define USB_DFU_ERR_STALLEDPKT    0x0F

#ifdef LOSCFG_DRIVERS_USB_DFU_FINISH_EVENT
/* Define the events for g_finish_event */

enum {
  USB_DFU_FINISH_EVENT = 1u << 0,
  USB_DFU_ERROR_EVENT  = 1u << 1,
  USB_DFU_FREE_EVENT   = 1u << 2
};
#endif

enum dfu_atomic_status
{
  DFU_IDLE_STATUS = 0,
  DFU_FREE_STATUS,
#ifndef CONFIG_DRIVERS_USB_DFU_DOWNLOAD_CALLBACK
  DFU_INIT_STATUS,
  DFU_WRITE_STATUS,
  DFU_READ_STATUS
#endif
};

void set_flash_state(volatile uint8_t flash_state);
void get_flash_state(const struct usbdev_req_s *req);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_F_DFU_PRI_H */
