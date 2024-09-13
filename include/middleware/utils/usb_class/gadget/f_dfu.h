/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: LiteOS USB Device Dfu Header File
 * Author: Huawei LiteOS Team
 * Create: 2017-12-25
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

#ifndef _USB_DFU_INCLUDE_H
#define _USB_DFU_INCLUDE_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define DFU_NAME_MAX_LEN  32

/* The status of Flash upgrade state */

#define DFU_FLASH_STATE_UPGRADING   1
#define DFU_FLASH_STATE_UPGRADED    0
#define DFU_FLASH_STATE_ERROR       2

struct usb_dfu_entity
{
#ifndef CONFIG_DRIVERS_USB_DFU_DOWNLOAD_CALLBACK
  char dfu_name[DFU_NAME_MAX_LEN];
  void *ram_addr;
  uint32_t ram_size;
  uint64_t trans_size;
  uint32_t seq_num;
  uint32_t offset;
#endif
  uint32_t trans_complete;
};

#ifndef CONFIG_DRIVERS_USB_DFU_DOWNLOAD_CALLBACK
void usb_dfu_free_entities(void);
int usb_dfu_init_env_entities(const char *type, char *envstr, const char *devstr);
struct usb_dfu_entity *usb_dfu_get_entity(int alter);
uint64_t *usb_dfu_update_size_get(void);
int usb_dfu_read(struct usb_dfu_entity *dfu, void *buf, int size, uint32_t blk_seq_num);
#endif
int usb_dfu_wait_transmit_finish(uint32_t timeout);
uint32_t usb_dfu_update_status(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_DFU_INCLUDE_H */