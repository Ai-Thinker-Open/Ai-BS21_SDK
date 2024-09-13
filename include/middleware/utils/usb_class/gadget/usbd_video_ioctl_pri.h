/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: LiteOS USB Driver UVC Ioctl Private Header File
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

#ifndef _USBD_VIDEO_CONTROLLER_PRI_H
#define _USBD_VIDEO_CONTROLLER_PRI_H

#include "stdint.h"
#include "gadget/f_uvc.h"
#include "gadget/f_uvc_pri.h"
#include "gadget/usbd_video_ioctl.h"

#ifdef CONFIG_DRIVERS_USB_UVC_IOCTL
struct usbd_uvc_event_queue_node
{
  uint8_t *buf;
  uint32_t buf_len;
  struct LOS_DL_LIST event_queue_node;
};

int uvc_fops_init(struct uvc_dev_s *fuvc);
int uvc_fops_deinit(struct uvc_dev_s *fuvc);
#endif /* CONFIG_DRIVERS_USB_UVC_IOCTL */

enum uvc_control_mode
{
  MODE_NONE,
  MODE_IOCTL,
  MODE_FUNCCALL,
};

int queue_video_event(struct uvc_dev_s *fuvc, uint32_t event_type);

#endif /* _USBD_VIDEO_CONTROLLER_PRI_H */