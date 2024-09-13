/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2021. All rights reserved.
 * Description: LiteOS USB Driver DWC 2.0 HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2013-05-16
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

#ifndef _DWC_OTG_PCD_IRQ_H
#define _DWC_OTG_PCD_IRQ_H

#include "controller/usb_device/dwc_otg_pcd.h"

int dwc_otg_irq(void *dwc_arg);
void endpoint0_startup_receiving_setup(dwc_otg_pcd_t *pcd);
extern int dwc_otg_common_irq(dwc_otg_pcd_t *pcd);
extern int dwc_otg_pcd_irq(dwc_otg_pcd_t *pcd);
extern uint32_t dwc_otg_intr_status_get(dwc_otg_pcd_t *pcd);

#define EP0_DISCONNECT			0
#define EP0_IDLE			1
#define EP0_IN_DATA_PHASE		2
#define EP0_OUT_DATA_PHASE		3
#define EP0_IN_STATUS_PHASE		4
#define EP0_OUT_STATUS_PHASE		5
#define EP0_STALL			6

#endif
