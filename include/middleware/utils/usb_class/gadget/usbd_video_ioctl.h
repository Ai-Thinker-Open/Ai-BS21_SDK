/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: LiteOS USB Driver UVC Ioctl Header File
 * Author: Huawei LiteOS Team
 * Create: 2021-12-06
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

#ifndef _USBD_VIDEO_CONTROLLER_H
#define _USBD_VIDEO_CONTROLLER_H

#include <stdint.h>
#include <sys/ioctl.h>
#include "gadget/f_uvc.h"

#define USB_UVC_DEV "/dev/usb_uvc-0"

#define V4L2_EVENT_PRIVATE_START 0x08000000
#define UVC_EVENT_FIRST          (V4L2_EVENT_PRIVATE_START + 0)
#define UVC_EVENT_CONNECT        (V4L2_EVENT_PRIVATE_START + 0)
#define UVC_EVENT_DISCONNECT     (V4L2_EVENT_PRIVATE_START + 1)
#define UVC_EVENT_STREAMON       (V4L2_EVENT_PRIVATE_START + 2)
#define UVC_EVENT_STREAMOFF      (V4L2_EVENT_PRIVATE_START + 3)
#define UVC_EVENT_SETUP          (V4L2_EVENT_PRIVATE_START + 4) /* reserved */
#define UVC_EVENT_DATA           (V4L2_EVENT_PRIVATE_START + 5)
#define UVC_EVENT_LAST           (V4L2_EVENT_PRIVATE_START + 5)

#define UVC_EVENT_DATA_RESERVED  64
struct usbd_uvc_video_event
{
  uint32_t event_type;
  union
  {
    struct uvc_format_info format;
    uint8_t data[UVC_EVENT_DATA_RESERVED];
  } event_data;
};

#define VIDIOC_STREAMON     _IOR ('V', 18, int)
#define VIDIOC_STREAMOFF    _IOR ('V', 19, int)
#define	VIDIOC_DQEVENT      _IOR ('V', 89, struct usbd_uvc_video_event)

#endif /* _USBD_VIDEO_CONTROLLER_H */