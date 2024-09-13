/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2021. All rights reserved.
 * Description: LiteOS USB OS DEVICE Core HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2014-11-11
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

#ifndef _USB_DEV3_DEFS_H
#define _USB_DEV3_DEFS_H

#include <errno.h>
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

#define USB_OTG_NTF_HOST_REL	51
#define USB_OTG_B3_RSP_ENABLE	52

/* super-speed companion descriptor related macros */
#define USB_SSE_GET_MAX_STREAMS(a)			((a) & 0x1f)
#define USB_SSE_SET_MAX_STREAMS(a, b)		((a) | ((b) & 0x1f))
#define USB_SSE_GET_MAX_PACKET_NUM(a)		((a) & 0x03)
#define USB_SSE_SET_MAX_PACKET_NUM(a, b)	((a) | ((b) & 0x03))

/* Dwc3_usb error codes */
#define DWC3_USB_E_INVALID			EINVAL
#define DWC3_USB_E_NOT_SUPPORTED	EOPNOTSUPP
#define DWC3_USB_E_BUSY				EBUSY
#define DWC3_USB_E_SHUTDOWN			ESHUTDOWN
#define DWC3_USB_E_DISCONNECT		ECONNRESET

/* Type for DMA addresses */
typedef uintptr_t	usb_dwc_dma_t;
#define DWC_DMA_ADDR_INVALID	(~(usb_dwc_dma_t)0)

#define DWC_USB3_NUM_BULK_TRBS	256
#define DWC_USB3_NUM_INTR_TRBS	1
#define DWC_USB3_NUM_ISOC_TRBS	256

#if defined (CONFIG_DRIVERS_USB3_DEVICE_USB_MODE_USB_1_1)
#define USB_MODE	1
#elif defined (CONFIG_DRIVERS_USB3_DEVICE_USB_MODE_USB_2_0)
#define USB_MODE	2
#else
#define USB_MODE	0
#endif

#if !defined (CONFIG_DRIVERS_USB_DEVICE_SLAVE_CONFIG)
#define USB_GEVENT_BUF_NUM	0
#define USB_DEPCFG_INTR_NUM	0
#define USB_DMA_OFFSET		0
#define OUT_EP_NUM			2
#define IN_EP_NUM			4
#else
#define USB_GEVENT_BUF_NUM	CONFIG_USB_GEVENT_BUF_NUM
#define USB_DEPCFG_INTR_NUM	CONFIG_USB_DEPCFG_INTR_NUM
#define USB_DMA_OFFSET		CFG_USB_DMA_OFFSET
#define OUT_EP_NUM			CONFIG_USB_OUT_EP_NUM
#define IN_EP_NUM			CONFIG_USB_IN_EP_NUM
#endif

/*
 * These parameters may be specified when loading the module. They define how
 * the DWC_usb3 controller should be configured. The parameter values are passed
 * to the CIL initialization routine dwc_usb3_pcd_common_init().
 */
typedef struct dwc_usb3_core_params {
	int burst;
	int newcore;
	int phy;
	int wakeup;
	uint32_t pwrctl;
	int lpmctl;
	int phyctl;
	int usb2mode;
	int hibernate;
	int hiberdisc;
	int clkgatingen;
	int ssdisquirk;
	int nobos;
	int loop;
	uint32_t nump;
	int newcsr;
	uint32_t rxfsz;
	uint32_t txfsz[16];
	int txfsz_cnt;
	int baseline_besl;
	int deep_besl;
	int besl;
	int ebc;
} dwc_usb3_core_params_t;

#ifdef __cplusplus
}
#endif

#endif /* _USB_DEV3_DEFS_H */
