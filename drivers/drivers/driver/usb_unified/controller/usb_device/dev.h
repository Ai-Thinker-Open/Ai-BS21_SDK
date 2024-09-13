/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2021. All rights reserved.
 * Description: LiteOS USB device HeadFile
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

#ifndef _USB_DEV3_DEV_H
#define _USB_DEV3_DEV_H

#ifdef __cplusplus
extern "C" {
#endif

/* 64bit */
#ifdef CONFIG_AARCH64
#define DWC_USB3_64B_ARCH
#endif

/*
 * This structure is a wrapper that encapsulates the driver components used to
 * manage a single DWC_usb3 controller.
 */
typedef struct usb3_dwc_device {
	/*
	 * OS-specific stuff. KEEP THIS AT THE VERY BEGINNING OF THE DEVICE
	 * STRUCT. OSes such as FreeBSD and NetBSD require this.
	 */

	/* Base address returned from ioremap() */
	volatile uint8_t *base;
	volatile uint8_t *gasket_base;

	/* Offset to 'gasket' registers (Synopsys FPGA only) */
	int gasket_ofs;

	/* Device context */
	void *dev;

	/* IRQ resource */
	uint32_t irq;

	/* Count of threads inside Gadget API */
	int hiber_cnt;

	/* Hibernation state */
	int hibernate;

#define DWC_HIBER_AWAKE			0
#define DWC_HIBER_ENTER_NOSAVE	1
#define DWC_HIBER_ENTER_SAVE	2
#define DWC_HIBER_SLEEPING		3
#define DWC_HIBER_WAIT_LINK_UP	4
#define DWC_HIBER_WAIT_U0		5
#define DWC_HIBER_SS_DIS_QUIRK	6

	int pme_ready;

	/* PCD structure */
	struct usb3_dwc_pcd pcd;

	/* Value from SNPSID register */
	uint32_t snpsid;

	/* Parameters that define how the core should be configured */
	dwc_usb3_core_params_t *core_params;

	/* Core Global registers starting at offset 100h */
	dwc_usb3_core_global_regs_t *core_global_regs;

#define DWC_EVENT_BUF_SIZE	1024	/* size in dwords */
#define DWC_NUM_EVENT_BUFS	1
	/*
	 * Event Buffers for receiving interrupts. Up to 32 buffers are
	 * supported by the hardware, but we only use 1.
	 */
	uint32_t *event_ptr[DWC_NUM_EVENT_BUFS];
	uint32_t *event_buf[DWC_NUM_EVENT_BUFS];
	usb_dwc_dma_t event_buf_dma[DWC_NUM_EVENT_BUFS];

	/* Total RAM for FIFOs (Bytes) */
	unsigned short total_fifo_size;

	/* Size of Rx FIFO (Bytes) */
	unsigned short rx_fifo_size;

	/* Hardware Configuration - stored here for convenience */
	uint32_t hwparams0;
	uint32_t hwparams1;
	uint32_t hwparams2;
	uint32_t hwparams3;
	uint32_t hwparams4;
	uint32_t hwparams5;
	uint32_t hwparams6;
	uint32_t hwparams7;
	uint32_t hwparams8;

	/* Register state, saved across core hibernation */
	uint32_t dcfg_save;
	uint32_t dctl_save;
	uint32_t gtxfifosiz0_save;
	uint32_t gtxfifosiz1_save;
	uint32_t gtxfifosiz2_save;
	uint32_t gtxfifosiz3_save;
	uint32_t grxfifosiz0_save;
	uint32_t guctl_save;
	uint32_t guctl1_save;

	/*
	 * Hooks for customizing device initialization. See
	 * dwc_usb3_pcd_device_init() in cil.c to see how these work.
	 */
	void (*soft_reset_hook)(struct usb3_dwc_device *dev, int softrst, int rstor);
	void (*phy_config_hook)(struct usb3_dwc_device *dev, int softrst, int rstor);
	void (*fifo_sizing_hook)(struct usb3_dwc_device *dev, int softrst, int rstor);
	void (*gctl_init_hook)(struct usb3_dwc_device *dev, int softrst, int rstor);
	void (*set_address_hook)(struct usb3_dwc_device *dev, int softrst, int rstor);
	void (*ep0_start_hook)(struct usb3_dwc_device *dev, int softrst, int rstor);

	/*
	 * Value to write into the DCTL HIRD_Thresh field on register
	 * initialization. If 0 then a default value of 0x1c will be used.
	 */
	uint32_t hird_thresh;

	/*
	 * Values to write into GSBUSCFG0 and GSBUSCFG1 on initialization or
	 * when exiting from hibernation. 'program_gsbuscfg' below must also be
	 * set to 1 to enable the writing of these values.
	 */
	uint32_t gsbuscfg0;
	uint32_t gsbuscfg1;

	/* True if common functionality has been initialized */
	uint32_t cmn_initialized		: 1;

	/* True if Gadget has been initialized */
	uint32_t gadget_initialized		: 1;

	/* True if PCD has been initialized */
	uint32_t pcd_initialized		: 1;

	/* True if common IRQ handler has been installed */
	uint32_t cmn_irq_installed		: 1;

	/* True if sysfs functions have been installed */
	uint32_t sysfs_initialized		: 1;

	/* True if waiting for connect before resuming from hibernation */
	uint32_t hiber_wait_connect		: 1;

	/* True if waiting for U0 state before sending remote wake */
	uint32_t hiber_wait_u0			: 1;

	/*
	 * True if GBUSCFG0/GBUSCFG1 should be written with the above
	 * values when exiting hibernation.
	 */
	uint32_t program_gsbuscfg		: 1;
} dwc_usb3_device_t;

#ifdef __cplusplus
}
#endif

#endif /* _USB_DEV3_DEV_H */
