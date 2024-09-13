/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2021. All rights reserved.
 * Description: LiteOS USB Driver 2.0 HeadFile
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

#ifndef _DWC_OTG_PCD_H
#define _DWC_OTG_PCD_H

#include "kal_spinlock.h"
#include "implementation/_thread_ref.h"
#include "gadget/usbdev.h"

#if defined (CONFIG_DRIVERS_USB_DEVICE_SLAVE_CONFIG)
#define USB_DMA_OFFSET		CONFIG_USB_DMA_OFFSET
#define OUT_EP_NUM			CONFIG_USB_OUT_EP_NUM
#define IN_EP_NUM			CONFIG_USB_IN_EP_NUM
#if IN_EP_NUM >= OUT_EP_NUM
#define PCD_MAX_EPS		IN_EP_NUM + 1
#else
#define PCD_MAX_EPS		OUT_EP_NUM + 1
#endif

#else
#define USB_DMA_OFFSET		0
#define OUT_EP_NUM			2
#define IN_EP_NUM			4
#endif

#if defined (CONFIG_DRIVERS_USB2_ULPI_INTERFANCE)
/* If the USB PHY chip is external mounting, enable ULPI. */
#define DWC_INTERFACE_CFG    0x00001410
#else
/* If the USB PHY is integrated in the chip, disable ULPI. */
#define DWC_INTERFACE_CFG    0x00001400 /* DWC with UTMI.(sample back) */
#endif

#define DWC_REG_BASE  CONFIG_USBUDC_REG_BASE_ADDRESS

typedef enum usb_dwc2_lx_state {
	USB_DWC2_STATE_L0, /* USB on state */
	USB_DWC2_STATE_L1, /* USB sleep state */
	USB_DWC2_STATE_L2, /* USB suspend state */
	USB_DWC2_STATE_L3  /* USB off state */
} usb_dwc2_lx_state_e;

typedef struct dwc_otg_pcd_ep {
	uint32_t dma_addr;
	uint8_t *start_xfer_buff;
	uint8_t *xfer_buff;

	unsigned is_in		: 1;
	unsigned is_active	: 1;
	unsigned is_stopped	: 1;
	unsigned is_disabling	: 1;
	unsigned tx_fifo_num	: 4;

	unsigned xfer_len	: 19;
	unsigned xfer_count	: 19;
	unsigned xfer_type	: 2;
#define USB_EP_TYPE_CONTROL	0
#define USB_EP_TYPE_ISOC	1
#define USB_EP_TYPE_BULK	2
#define USB_EP_TYPE_INTR	3

	unsigned data_pid_start	: 1;
	unsigned even_odd_frame	: 1;
	unsigned maxpacket	: 11;
	unsigned sent_zlp	: 1;
	unsigned total_len	: 19;
	void *private_data;

	/* bInterval */
	uint32_t bInterval;
	/* Next frame num to setup next ISOC transfer */
	uint32_t frame_num;
	/* Indicates SOF number overrun in DSTS */
	uint32_t fifo_index;
	uint32_t fifo_size;
	uint8_t frm_overrun;
	uint8_t  num;
} dwc_otg_pcd_ep_t;

typedef struct dwc_otg_pcd_s {
	struct usbdev_s usb_dev;
	void *setup_pkt;
	struct {
		uint8_t type;
		uint8_t setup_complete;
		uint8_t out_complete;
		uint8_t in_complete;
	} cmdtype;

	int ep0state;
	unsigned status;
	volatile char *buf;
	int length;

	int xfer_len;

	dwc_otg_pcd_ep_t pcd_ep0;
	dwc_otg_pcd_ep_t pcd_in_eps[PCD_MAX_EPS - 1];
	dwc_otg_pcd_ep_t pcd_out_eps[PCD_MAX_EPS - 1];
	struct usbdev_ep_s usbd_ep0;
	struct usbdev_ep_s usbd_in_eps[PCD_MAX_EPS - 1];
	struct usbdev_ep_s usbd_out_eps[PCD_MAX_EPS - 1];

	struct usbdevclass_driver_s *driver;

	uint8_t pcd_num_eps;
	uint8_t num_in_eps;
	uint8_t num_out_eps;

	short is_pkt_resended;
	unsigned origi_sum;
	unsigned sequence_no;
	int xfer_need_reply;

	usb_dwc2_lx_state_e lx_state;

	unsigned request_config	: 1;
	unsigned remote_wakeup_enable	: 1;
	unsigned request_enable	: 1;
	unsigned request_reserv	: 29;

	KalSpinLock irq_lock;
	KalSpinLock lock;

	void *context;
	/* Frame number while entering to ISR - needed for ISOCs */
	uint32_t frame_num;
	uint32_t fifo_map;
	uint32_t custom_enum : 1;
} dwc_otg_pcd_t;

/***************************************************************
 * Control and Status Register (GOTGCTL)
 * The OTG Control and Status register controls the behavior and
 * reflects the status of the OTG function of the core.
 * @@ Size: 32 bits
 * @@ Offset: 0x0
 * @@ Memory Access: R/W
****************************************************************/
typedef union gotgctl_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned sesreqscs_r	: 1;
		unsigned sesreq_rw	: 1;
		unsigned reserved2_7	: 6;
		unsigned hstnegscs_r	: 1;
		unsigned hnpreq_rw	: 1;
		unsigned hstsethnpen_rw	: 1;
		unsigned devhnpen_rw	: 1;
		unsigned reserved12_15	: 4;
		unsigned conidsts_r	: 1;
		unsigned reserved17	: 1;
		unsigned asesvld_r	: 1;
		unsigned bsesvld_r	: 1;
		unsigned otgversion	: 1;
		unsigned currmod_rw	: 1;
		unsigned reserved22_31	: 10;
	} b;
} gotgctl_data_t;

/***************************************************************
 * Interrupt Register (GOTGINT)
 * The application reads this register whenever there is an OTG
 * interrupt and clears the bits in this register to clear the
 * OTG interrupt.
 * @@ Size: 32 bits
 * @@ Offset: 0x4
 * @@ Memory Access: R/W
****************************************************************/
typedef union gotgint_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned reserved0_1			: 2;
		unsigned sesenddet_r_ss_wc		: 1;
		unsigned reserved3_7			: 5;
		unsigned sesreqsucstschng_r_ss_wc	: 1;
		unsigned hstnegsucstschng_r_ss_wc	: 1;
		unsigned reserver10_16			: 7;
		unsigned hstnegdet_r_ss_wc		: 1;
		unsigned adevtoutchng_r_ss_wc		: 1;
		unsigned debdone_r_ss_wc		: 1;
		unsigned reserved31_20			: 12;

	} b;
} gotgint_data_t;


/***************************************************************
 * AHB Configuration Register (GAHBCFG)
 * This register can be used to configure the core after power-on
 * or a change in mode. This register mainly contains AHB
 * system-related configuration parameters. Do not change this
 * register after the initial programming. The application must
 * program this register before starting any transactions on either
 * the AHB or the USB.
 * @@ Size: 32 bits
 * @@ Offset: 0x8
 * @@ Memory Access: R/W
****************************************************************/
typedef union gahbcfg_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned glblintrmsk_rw	: 1;
#define GAHBCFG_GLBINT_ENABLE		1

		unsigned hburstlen_rw	: 4;
#define GAHBCFG_DMA_BURST_SINGLE	0
#define GAHBCFG_DMA_BURST_INCR		1
#define GAHBCFG_DMA_BURST_INCR4		3
#define GAHBCFG_DMA_BURST_INCR8		5
#define GAHBCFG_DMA_BURST_INCR16	7

		unsigned dma_enable_rw	: 1;
#define GAHBCFG_DMA_ENABLE		1

		unsigned reserved			: 1;
		unsigned nptxfemplvl_txfemplvl_rw	: 1;

		unsigned ptxfemplvl_rw			: 1;
#define GAHBCFG_TXFEMPTYLVL_EMPTY	1
#define GAHBCFG_TXFEMPTYLVL_HALF_EMPTY	0

		unsigned reserved9_31	: 23;
	} b;
} gahbcfg_data_t;

/***************************************************************
 * USB Configuration Register (GUSBCFG)
 * This register can be used to configure the core after power-on
 * or a changing to Host mode or Device mode. It contains USB and
 * USB-PHY related configuration parameters. The application must
 * program this register before starting any transactions on
 * either the AHB or the USB. Do not make changes to this register
 * after the initial programming.
 * @@ Size: 32 bits
 * @@ Offset: 0xc
 * @@ Memory Access: R/W
****************************************************************/
typedef union gusbcfg_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned toutcal_rw			: 3;
		unsigned phyif_rw			: 1;
		unsigned ulpi_utmi_sel_rw		: 1;
		unsigned fsintf_rw			: 1;
		unsigned physel_rw			: 1;
		unsigned ddrsel_rw			: 1;
		unsigned srpcap_rw			: 1;
		unsigned hnpcap_rw			: 1;
		unsigned usbtrdtim_rw			: 4;
		unsigned nptxfrwnden_rw			: 1;
		unsigned phylpwrclkselect_rw		: 1;
		unsigned otgutmifsselect_rw		: 1;
		unsigned ulpi_fsls_rw			: 1;
		unsigned ulpi_auto_res_rw		: 1;
		unsigned ulpi_clk_sus_m_rw		: 1;
		unsigned ulpi_ext_vbus_drv_rw		: 1;
		unsigned ulpi_int_vbus_indicator_rw	: 1;
		unsigned term_sel_dl_pulse_rw		: 1;
		unsigned reserved			: 9;
	} b;
} gusbcfg_data_t;

/***************************************************************
 * Reset Register (GRSTCTL)
 * The application uses this register to reset various hardware
 * features inside the core.
 * @@ Size: 32 bits
 * @@ Offset: 0x10
 * @@ Memory Access: R/W
****************************************************************/
typedef union grstctl_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned csftrst_rw		: 1;
		unsigned hsftrst_r		: 1;
		unsigned hstfrm_r		: 1;
		unsigned intknqflsh_r_ws_sc	: 1;
		unsigned rxfflsh_rw		: 1;
		unsigned txfflsh_r_ws_sc	: 1;
		unsigned txfnum_rw		: 5;
		unsigned reserved11_29		: 19;
		unsigned dmareq_r		: 1;
		unsigned ahbidle_r		: 1;
	} b;
} grstctl_t;


/***************************************************************
 * Interrupt Mask Register (GINTMSK)
 * This register works with the "Interrupt Register (GINTSTS)" to
 * interrupt the application. When an interrupt bit is masked, the
 * interrupt associated with that bit is not generated. However,
 * the GINTSTS register bit corresponding to that interrupt is
 * still set.
 * @@ Size: 32 bits
 * @@ Offset: 0x18
 * @@ Memory Access: R/
****************************************************************/
typedef union gintmsk_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned reserved0		: 1;
		unsigned modemismatch_rw	: 1;
		unsigned otgintr_rw		: 1;
		unsigned sofintr_rw		: 1;
		unsigned rxstsqlvl_rw		: 1;
		unsigned nptxfempty_rw		: 1;
		unsigned ginnakeff_rw		: 1;
		unsigned goutnakeff_rw		: 1;
		unsigned reserved8		: 1;
		unsigned i2cintr_rw		: 1;
		unsigned erlysuspend_rw		: 1;
		unsigned usbsuspend_rw		: 1;
		unsigned usbreset_rw		: 1;
		unsigned enumdone_rw		: 1;
		unsigned isooutdrop_rw		: 1;
		unsigned eopframe_rw		: 1;
		unsigned reserved16		: 1;
		unsigned epmismatch_rw		: 1;
		unsigned inepintr_rw		: 1;
		unsigned outepintr_rw		: 1;
		unsigned incomplisoin_rw	: 1;
		unsigned incomplisoout_rw	: 1;
		unsigned reserved22_23		: 2;
		unsigned portintr_rw		: 1;
		unsigned hcintr_rw		: 1;
		unsigned ptxfempty_rw		: 1;
		unsigned reserved27		: 1;
		unsigned conidstschng_rw	: 1;
		unsigned disconnect_rw		: 1;
		unsigned sessreqintr_rw		: 1;
		unsigned wkupintr_rw		: 1;
	} b;
} gintmsk_data_t;

/***************************************************************
 * Interrupt Register (GINTSTS)
 * This register interrupts the application for system-level events
 * in the current mode (Device mode or Host mode).
 * @@ Size: 32 bits
 * @@ Offset: 0x14
 * @@ Memory Access: R/W
****************************************************************/
typedef union gintsts_data {
	/* raw word */
	uint32_t d32;
	#define SOF_INTR_MASK 0x0008

	/* raw bits */
	struct {
#define DWC_OTG_HOST_MODE 1
		unsigned curmode_r		: 1;
		unsigned modemismatch_r_ss_wc	: 1;
		unsigned otgintr_r		: 1;
		unsigned sofintr_r_ss_wc	: 1;
		unsigned rxstsqlvl_r		: 1;
		unsigned nptxfempty_r		: 1;
		unsigned ginnakeff_r		: 1;
		unsigned goutnakeff_r		: 1;
		unsigned lpickint_r_ss_wc	: 1;
		unsigned i2cintr_r_ss_wc	: 1;
		unsigned erlysuspend_r_ss_wc	: 1;
		unsigned usbsuspend_r_ss_wc	: 1;
		unsigned usbreset_r_ss_wc	: 1;
		unsigned enumdone_r_ss_wc	: 1;
		unsigned isooutdrop_r_ss_wc	: 1;
		unsigned eopframe_r_ss_wc	: 1;
		unsigned intokenrx_r_ss_wc	: 1;
		unsigned epmismatch_r		: 1;
		unsigned inepint_r		: 1;
		unsigned outepintr_r		: 1;
		unsigned incomplisoin_r_ss_wc	: 1;
		unsigned incomplisoout_r_ss_wc	: 1;
		unsigned fetsusp_r_ss_wc	: 1;
		unsigned resetdet_r_ss_wc	: 1;
		unsigned portintr_r		: 1;
		unsigned hcintr_r		: 1;
		unsigned ptxfempty_r		: 1;
		unsigned lpm_int_r_ss_wc	: 1;
		unsigned conidstschng_r_ss_wc	: 1;
		unsigned disconnect_r_ss_wc	: 1;
		unsigned sessreqintr_r_ss_wc	: 1;
		unsigned wkupintr_r_ss_wc	: 1;
	} b;
} gintsts_data_t;

/***************************************************************
 * This union represents the bit fields in the FIFO Size Registers
 * (GNPTXFSIZ, HPTXFSIZ, DPTXFSIZn, DIEPTXFn), refer to DesignWare
 * Cores USB 2.0 Hi-Speed On-The-Go Databook(Version 3.30a),
 * section 5.3.3 for the details
****************************************************************/
typedef union fifosize_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned startaddr_rw	: 16;
		unsigned depth_rw	: 16;
	} b;
} fifosize_data_t;

/***************************************************************
 * This union represents the bit fields in the DFIFO Software Config
 * Registers, refer to DesignWare Cores USB 2.0 Hi-Speed On-The-Go
 * Databook(Version 3.30a), section 5.3.3.23 for the details
****************************************************************/
typedef union gdfifocfg_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned gdfifocfg_rw	: 16;
		unsigned epinfobase_rw	: 16;
	} b;
} gdfifocfg_data_t;

/***************************************************************
 * User HW Config1 Register (GHWCFG1)
 * This register contains the logical endpoint direction(s) selected
 * using coreConsultant.
 * @@ Size: 32 bits
 * @@ Offset: 0x44
 * @@ Memory Access: R
 * @@ Value After Reset: Configurable
****************************************************************/
typedef union hwcfg1_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned ep_dir0_r	: 2;
#define EP_DIR_BIDIR	0x00
#define EP_DIR_IN	0x01
#define EP_DIR_OUT	0x02

		unsigned ep_dir1_r	: 2;
		unsigned ep_dir2_r	: 2;
		unsigned ep_dir3_r	: 2;
		unsigned ep_dir4_r	: 2;
		unsigned ep_dir5_r	: 2;
		unsigned ep_dir6_r	: 2;
		unsigned ep_dir7_r	: 2;
		unsigned ep_dir8_r	: 2;
		unsigned ep_dir9_r	: 2;
		unsigned ep_dir10_r	: 2;
		unsigned ep_dir11_r	: 2;
		unsigned ep_dir12_r	: 2;
		unsigned ep_dir13_r	: 2;
		unsigned ep_dir14_r	: 2;
		unsigned ep_dir15_r	: 2;
	} b;
} hwcfg1_data_t;


/***************************************************************
 * User HW Config2 Register (GHWCFG2)
 * This register contains configuration options selected using
 * coreConsultant.
 * @@ Size: 32 bits
 * @@ Offset: 0x48
 * @@ Memory Access: R
 * @@ Value After Reset: Configurable
****************************************************************/
typedef union hwcfg2_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned op_mode_r 			: 3;
#define HWCFG2_OPMODE_HNP_SRP_CAPABLE_OTG		0
#define HWCFG2_OPMODE_SRP_ONLY_CAPABLE_OTG		1
#define HWCFG2_OPMODE_NO_HNP_SRP_CAPABLE_OTG		2
#define HWCFG2_OPMODE_SRP_CAPABLE_DEVICE		3
#define HWCFG2_OPMODE_NO_SRP_CAPABLE_DEVICE		4
#define HWCFG2_OPMODE_SRP_CAPABLE_HOST			5
#define HWCFG2_OPMODE_NO_SRP_CAPABLE_HOST		6

		unsigned architecture_r			: 2;
		unsigned point2point_r			: 1;

		unsigned hs_phy_type_r			: 2;
#define HWCFG2_HS_PHY_TYPE_NOT_SUPPORTED		0
#define HWCFG2_HS_PHY_TYPE_UTMI				1
#define HWCFG2_HS_PHY_TYPE_ULPI				2
#define HWCFG2_HS_PHY_TYPE_UTMI_ULPI			3

		unsigned fs_phy_type_r			: 2;
		unsigned num_dev_ep_r			: 4;
		unsigned num_host_chan_r		: 4;
		unsigned perio_ep_supported_r		: 1;
		unsigned dynamic_fifo_r			: 1;
		unsigned multi_proc_int_r		: 1;
		unsigned reserved21			: 1;
		unsigned nonperio_tx_q_depth_r		: 2;
		unsigned host_perio_tx_q_depth_r	: 2;
		unsigned dev_token_q_depth_r		: 5;
		unsigned otg_enable_ic_usb_r		: 1;
	} b;
} hwcfg2_data_t;

/**
 * This union represents the bit fields in the User HW Config4
 * Register.  Read the register into the <i>d32</i> element then read
 * out the bits using the <i>b</i>it elements.
 */
typedef union hwcfg4_data {
	/* raw register data */
	uint32_t d32;
	/* register bits */
	struct {
		unsigned num_dev_perio_in_ep_r	: 4;
		unsigned power_optimiz_r	: 1;
		unsigned min_ahb_freq_r		: 1;
		unsigned hiber_r		: 1;
		unsigned xhiber_r		: 1;
		unsigned reserved_r		: 6;
		unsigned utmi_phy_data_width_r	: 2;
		unsigned num_dev_mode_ctrl_ep_r	: 4;
		unsigned iddig_filt_en_r	: 1;
		unsigned vbus_valid_filt_en_r	: 1;
		unsigned a_valid_filt_en_r	: 1;
		unsigned b_valid_filt_en_r	: 1;
		unsigned session_end_filt_en_r	: 1;
		unsigned ded_fifo_en_r		: 1;
		unsigned num_in_eps_r		: 4;
		unsigned desc_dma_r		: 1;
		unsigned desc_dma_dyn_r		: 1;
	} b;
} hwcfg4_data_t;

/***************************************************************
 * Device Configuration Register (DCFG)
 * This register configures the core in Device mode after power-on
 * or after certain control commands or enumeration. Do not make
 * changes to this register after initial programming.
 * @@ Size: 32 bits
 * @@ Offset: 0x800
 * @@ Memory Access: R/W
****************************************************************/
typedef union dcfg_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned devspd_rw	: 2;
		unsigned nzstsouthshk_rw: 1;
#define DCFG_SEND_STALL		1

		unsigned ena32khzs_rw	: 1;
		unsigned devaddr_rw	: 7;

		unsigned perfrint_rw	: 2;
#define DCFG_FRAME_INTERVAL_80	0
#define DCFG_FRAME_INTERVAL_85	1
#define DCFG_FRAME_INTERVAL_90	2
#define DCFG_FRAME_INTERVAL_95	3

		unsigned endevoutnak_rw	: 1;
		unsigned reserved14_17	: 4;
		unsigned epmscnt_rw	: 5;
		unsigned descdma_rw	: 1;
		unsigned perschintvl_rw	: 2;
		unsigned resvalid_rw	: 6;
	} b;
} dcfg_data_t;

/***************************************************************
 * Device Control Register (DCTL)
 * @@ Size: 32 bits
 * @@ Offset: 0x804
 * @@ Memory Access: R/W
****************************************************************/
typedef union dctl_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned rmtwkupsig_rw		: 1;
		unsigned sftdiscon_rw		: 1;
		unsigned gnpinnaksts_r		: 1;
		unsigned goutnaksts_r		: 1;
		unsigned tstctl_rw		: 3;
		unsigned sgnpinnak_w		: 1;
		unsigned cgnpinnak_w		: 1;
		unsigned sgoutnak_w		: 1;
		unsigned cgoutnak_w		: 1;
		unsigned pwronprgdone_rw	: 1;

		/* Reserved */
		unsigned reserved		: 1;
		/* Global Multi Count */
		unsigned gmc			: 2;
		/* Ignore Frame Number for ISOC EPs */
		unsigned ifrmnum		: 1;
		/* NAK on Babble */
		unsigned nakonbble		: 1;
		/* Enable Continue on BNA */
		unsigned encontonbna		: 1;
		/* Enable deep sleep besl reject feature */
		unsigned besl_reject		: 1;
		unsigned reserved17_31		: 13;

	} b;
} dctl_data_t;

/***************************************************************
 * Device Status Register (DSTS)
 * This register indicates the status of the core with respect to
 * USB-related events. It must be read on interrupts from Device
 * All Interrupts (DAINT) register.
 * @@ Size: 32 bits
 * @@ Offset: 0x808
 * @@ Memory Access: R
****************************************************************/
typedef union dsts_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned suspsts_r		: 1;

		unsigned enumspd_r		: 2;
#define DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ	0
#define DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ	1
#define DSTS_ENUMSPD_LS_PHY_6MHZ		2
#define DSTS_ENUMSPD_FS_PHY_48MHZ		3

		unsigned errticerr_r	: 1;
		unsigned reserved4_7	: 4;
		unsigned soffn_r	: 14;
		unsigned reserved22_31	: 10;
	} b;
} dsts_data_t;


/***************************************************************
 * Device Endpoint-n Interrupt Register (DIEPINTn/DOEPINTn)
 * @@ Endpoint_number: 0 <= n <= 15
 * @@ Offset for IN endpoints: 908h + (Endpoint_number * 20h)
 * @@ Offset for OUT endpoints: B08h + (Endpoint_number * 20h)
****************************************************************/
typedef union diepint_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned xfercompl_r			: 1;
		unsigned epdisabled_r_ss_wc		: 1;
		unsigned ahberr_r_ss_wc			: 1;
		unsigned timeout_r_ss_wc		: 1;
		unsigned intktxfemp_r_ss_wc		: 1;
		unsigned intknepmis_r_ss_wc		: 1;
		unsigned inepnakeff_r_ss_wc		: 1;
		unsigned emptyintr_r			: 1;
		unsigned txfifoundrn_r_ss_wc		: 1;
		unsigned bnaintr_r_ss_wc		: 1;

		unsigned reserved10_12			: 3;
		/* BNA Interrupt mask */
		unsigned nak_r_ss_wc			: 1;

		unsigned reserved14_31			: 18;
	} b;
} diepint_data_t;
typedef union diepint_data diepmsk_data_t;


/***************************************************************
 * Device Endpoint-n Interrupt Register (DIEPINTn/DOEPINTn)
 * @@ Endpoint_number: 0 <= n <= 15
 * @@ Offset for IN endpoints: 908h + (Endpoint_number * 20h)
 * @@ Offset for OUT endpoints: B08h + (Endpoint_number * 20h)
****************************************************************/
typedef union doepint_data {
	/* raw word */
	volatile uint32_t d32;
	/* raw bits */
	struct {
		unsigned xfercompl_r		: 1;
		unsigned epdisabled_r_ss_wc	: 1;
		unsigned ahberr_r_ss_wc		: 1;
		unsigned setup_r_ss_wc		: 1;
		unsigned outtknepdis_r_ss_wc	: 1;
		unsigned stsphsercvd_r_ss_wc	: 1;
		unsigned back2backsetup_r_ss_wc	: 1;
		unsigned reserved7		: 1;
		unsigned outpkterr_r_ss_wc	: 1;
		unsigned bna_r_ss_wc		: 1;
		unsigned reserved10		: 1;
		unsigned pktdrpsts_r_ss_wc	: 1;
		unsigned babble_r_ss_wc		: 1;
		unsigned nak_r_ss_wc		: 1;
		unsigned nyet_r_ss_wc		: 1;
		unsigned sr_r_ss_wc		: 1;
		unsigned reserved16_31		: 16;
	} b;
} doepint_data_t;

typedef union doepint_data doepmsk_data_t;


/***************************************************************
 * Device All Endpoints Interrupt Register (DAINT)
 * When a significant event occurs on an endpoint, a Device All
 * Endpoints Interrupt register interrupts the application using
 * the Device OUT Endpoints Interrupt bit or Device IN Endpoints
 * Interrupt bit of the Core Interrupt register (GINTSTS.OEPInt or
 * GINTSTS.IEPInt, respectively).
 * @@ Size: 32 bits
 * @@ Offset: 0x818
 * @@ Memory Access: R

 * Device All Endpoints Interrupt Mask Register (DAINTMSK)
 * The Device Endpoint Interrupt Mask register works with the Device
 * Endpoint Interrupt register to interrupt the application when an
 * event occurs on a device endpoint. However, the Device All
 * Endpoints Interrupt (DAINT) register bit corresponding to that
 * interrupt is still set.
 * @@ Size: 32 bits
 * @@ Offset: 0x81c
 * @@ Memory Access: R/W
****************************************************************/
typedef union daint_data {
	/* raw word */
	uint32_t d32;

	struct {
		unsigned in	: 16;
		unsigned out	: 16;
	} ep;

	/* raw bits */
	struct {
		/* IN Endpoint bits */
		unsigned iep0	: 1;
		unsigned iep1	: 1;
		unsigned iep2	: 1;
		unsigned iep3	: 1;
		unsigned iep4	: 1;
		unsigned iep5	: 1;
		unsigned iep6	: 1;
		unsigned iep7	: 1;
		unsigned iep8	: 1;
		unsigned iep9	: 1;
		unsigned iep10	: 1;
		unsigned iep11	: 1;
		unsigned iep12	: 1;
		unsigned iep13	: 1;
		unsigned iep14	: 1;
		unsigned iep15	: 1;

		/* OUT Endpoint bits */
		unsigned oep0	: 1;
		unsigned oep1	: 1;
		unsigned oep2	: 1;
		unsigned oep3	: 1;
		unsigned oep4	: 1;
		unsigned oep5	: 1;
		unsigned oep6	: 1;
		unsigned oep7	: 1;
		unsigned oep8	: 1;
		unsigned oep9	: 1;
		unsigned oep10	: 1;
		unsigned oep11	: 1;
		unsigned oep12	: 1;
		unsigned oep13	: 1;
		unsigned oep14	: 1;
		unsigned oep15	: 1;
	} b;
} daint_data_t;

/***************************************************************
 * Device Endpoint-n Control Register (DIEPCTLn/DOEPCTLn)
 * The application uses this register to control the behavior of
 * each logical endpoint other than endpoint 0.
 * @@ Endpoint_number: 1 <= n <= 15
 * @@ Offset for IN endpoints: 900h + (Endpoint_number * 20h)
 * @@ Offset for OUT endpoints: B00h + (Endpoint_number * 20h)
****************************************************************/
typedef union depctl_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned mps_rw			: 11;
#define DEP0CTL_MPS_64	0
#define DEP0CTL_MPS_32	1
#define DEP0CTL_MPS_16	2
#define DEP0CTL_MPS_8	3

		unsigned nextep_rw		: 4;
		unsigned usbactep_r_w_sc	: 1;
		unsigned dpid_r			: 1;
		unsigned naksts_r		: 1;
		unsigned eptype_rw		: 2;
		unsigned snp_rw			: 1;
		unsigned stall_rw		: 1;
		unsigned txfnum_rw		: 4;
		unsigned cnak_w			: 1;
		unsigned snak_w			: 1;
		unsigned setd0pid_w		: 1;
		unsigned setd1pid_w		: 1;
		unsigned epdis_r_ws_sc		: 1;
		unsigned epena_r_ws_sc		: 1;
	} b;
} depctl_data_t;

/***************************************************************
 * Device Endpoint-n Transfer Size Register (DIEPTSIZn/DOEPTSIZn)
 * The application must modify this register before enabling the
 * endpoint. Once the endpoint is enabled using Endpoint Enable bit
 * of the Device Endpoint-n Control registers
 * (DIEPCTLn.EPEna/DOEPCTLn.EPEna), the core modifies this register.
 * The application can only read this register once the core has
 * cleared the Endpoint Enable bit.
 * @@ Size: 32 bits
 * @@ Offset: 0x930
 * @@ Memory Access: R/W
 * @@ Endpoint_number: 1 <= n <= 15
 * @@ Offset for IN endpoints: 910h + (Endpoint_number * 20h)
 * @@ Offset for OUT endpoints: B10h + (Endpoint_number * 20h)
****************************************************************/
typedef union deptsiz_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned xfersize_rw	: 19;
#define DEPSZ_MAX_PKT_CNT	1023

		unsigned pktcnt_rw	: 10;
		unsigned mc_rw		: 2;
		unsigned reserved	: 1;
	} b;
} deptsiz_data_t;

/***************************************************************
 * Device Endpoint 0 Transfer Size Register (DIEPTSIZ0/DOEPTSIZ0)
 * The application must modify this register before enabling
 * endpoint 0. Once endpoint 0 is enabled using Endpoint Enable
 * bit of the Device Control Endpoint 0 Control registers
 * (DIEPCTL0.EPEna/DOEPCTL0.EPEna), the core modifies this
 * register. The application can only read this register once the
 * core has cleared the Endpoint Enable bit.
 * @@ Size: 32 bits
 * @@ Offset: 0x910
 * @@ Memory Access: R/W
 * @@ Offset for IN endpoints: 910h
 * @@ Offset for OUT endpoints: B10h
****************************************************************/
typedef union deptsiz0_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned xfersize_rw	: 7;
		unsigned reserved7_18	: 12;
		unsigned pktcnt_rw	: 1;
		unsigned reserved20_28	: 9;
		unsigned supcnt_rw	: 2;
		unsigned reserved31;
	} b;
} deptsiz0_data_t;

typedef union pcgcctl_data {
	/* raw word */
	uint32_t d32;
	/* raw bits */
	struct {
		unsigned stoppclk_rw		:1;
		unsigned gatehclk_rw		:1;
		unsigned pwrclmp		:1;
		unsigned rstpdwnmodule_rw	:1;
		unsigned reserved		:1;
		unsigned enbl_l1gating_rw	:1;
		unsigned phy_sleep_r		:1;
		unsigned suspended_r		:1;
		unsigned resetaftsusp_rw	:1;
		unsigned restoremode_r		:1;
		unsigned enbl_extnd_hiber_rw	:1;
		unsigned extnd_hiber_pwrclmp_rw	:1;
		unsigned extnd_hiber_switch_rw	:1;
		unsigned ess_reg_restored_rw	:1;
		unsigned prt_clk_sel_rw		:2;
		unsigned port_power_rw		:1;
		unsigned max_xcvrselect_rw	:2;
		unsigned max_termsel_rw		:1;
		unsigned mac_dev_addr_rw	:7;
		unsigned p2hd_dev_enum_spd_rw	:2;
		unsigned p2hd_prt_spd_rw	:2;
		unsigned if_dev_mode_rw		:1;
	} b;
} pcgcctl_data_t;

extern uint32_t DWC_READ_REG32(uint32_t x);
extern void DWC_WRITE_REG32(uint32_t x, uint32_t v);
extern void DWC_MODIFY_REG32(uint32_t x, uint32_t c, uint32_t s);

int dwc_otg_close(dwc_otg_pcd_t *pcd);
int dwc_otg_initial(dwc_otg_pcd_t *pcd);
int dwc_otg_get_soffn(void);
int dwc_otg_remote_wakeup(void);
void dwc_otg_core_reset(void);
void dwc_otg_enable_common_interrupts(void);
void dwc_otg_enable_device_interrupts(void);
void dwc_otg_enable_global_interrupts(void);

int dwc_otg_core_init(dwc_otg_pcd_t *pcd);
int dwc_otg_core_dev_init(dwc_otg_pcd_t *pcd);
int dwc_otg_endpoint_enable(struct usbdev_ep_s *ep, const struct usb_epdesc_s *desc);
int dwc_otg_endpoint_disable(struct usbdev_ep_s *ep);
int dwc_otg_ep_req_start(struct usbdev_ep_s *usbd_ep,struct usbdev_req_s *req);
int dwc_otg_ep_halt(struct usbdev_ep_s *usbd_ep, int value);
void dwc_otg_core_do_dev_disconnect( dwc_otg_pcd_t *pcd);
void dwc_otg_core_do_pcd_setup(dwc_otg_pcd_t *pcd, struct usb_ctrlreq_s *ctrl);
void dwc_otg_core_ep_complete(dwc_otg_pcd_ep_t *pcd_ep, struct usbdev_ep_s *ep);

void dwc_otg_flush_tx_fifo(const uint32_t _num);
void dwc_otg_flush_rx_fifo(void);
void dwc_otg_ep_start_transfer(dwc_otg_pcd_ep_t *_ep);
void dwc_otg_endpoint_activate(dwc_otg_pcd_ep_t *ep);
void dwc_otg_endpoint_deactivate(dwc_otg_pcd_ep_t *ep);
void dwc_otg_power_off_phy(void);
void dwc_otg_pullup(int is_on);
void ep0_do_stall(dwc_otg_pcd_t *pcd, const int err_val);
void dwc_otg_wait_disable_in_endpoint(uint32_t epnum, uint32_t retry);
void dwc_otg_ep_set_stall(dwc_otg_pcd_t *pcd, dwc_otg_pcd_ep_t *ep);
void dwc_otg_ep_clear_stall(dwc_otg_pcd_t *pcd, dwc_otg_pcd_ep_t *ep);

#endif
