/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: LiteOS USB Device CDC HeadFile.
 * Author: Huawei LiteOS Team
 * Create: 2023-02-14
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

#ifndef _USBD_CDC_H_
#define _USBD_CDC_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* USB Class Definitions for Communication Devices, Version 1.1, section 5.2.3 */

#define USB_CDC_HEADER_FUNC 0x00
#define USB_CDC_CM_FUNC     0x01
#define USB_CDC_ACM_FUNC    0x02
#define USB_CDC_UNION_FUNC  0x06

/* USB Class Definitions for Communication Devices, Version 1.1, section 5.2.3.1 */

struct cdc_header_func_desc
{
  uint8_t   bFunctionLength;
  uint8_t   bDescriptorType;
  uint8_t   bDescriptorSubtype;
  uint16_t  bcdCDC;
} __attribute__ ((packed));

/* USB Class Definitions for Communication Devices, Version 1.1, section 5.2.3.2 */

#define CDC_ACM_REQ_LINE 0x02
struct cdc_cm_func_desc
{
  uint8_t bFunctionLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubtype;
  uint8_t bmCapabilities;
  uint8_t bDataInterface;
} __attribute__ ((packed));

/* USB Class Definitions for Communication Devices, Version 1.1, section 5.2.3.3 */

struct cdc_acm_func_desc
{
  uint8_t bFunctionLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubtype;
  uint8_t bmCapabilities;
} __attribute__ ((packed));

/* USB Class Definitions for Communication Devices, Version 1.1, section 5.2.3.8 */

struct cdc_union_func_desc
{
  uint8_t bFunctionLength;
  uint8_t bDescriptorType;
  uint8_t bDescriptorSubtype;
  uint8_t bMasterInterface;
  uint8_t bSlaveInterface0;
} __attribute__ ((packed));

/* USB Class Definitions for Communication Devices, Version 1.1, section 6.2.13 */

#define CDC_STOP_BIT_1  0
#define CDC_PARITY_NONE 0
struct cdc_line_coding_state
{
  uint32_t dwDTERate;
  uint8_t  bCharFormat;
  uint8_t  bParityType;
  uint8_t  bDataBits;
} __attribute__ ((packed));

/* USB Class Definitions for Communication Devices, Version 1.1, section 6.3 */

struct cdc_notification_element
{
  uint8_t bmRequestType;
  uint8_t bNotification;
  uint16_t wValue;
  uint16_t wIndex;
  uint16_t wLength;
  uint8_t data[16];
} __attribute__ ((packed));

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USBD_CDC_H_ */
