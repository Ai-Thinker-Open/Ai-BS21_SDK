/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2021. All rights reserved.
 * Description: LiteOS USB PCD Implementation HeadFile
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

#ifndef _USB_DEV3_PCD_H
#define _USB_DEV3_PCD_H

#include "gadget/usbdev.h"
#include "gadget/composite.h"
#include "implementation/_types_ref.h"
#include "implementation/_thread_ref.h"
#include "controller/usb_device/hw.h"
#include "controller/usb_device/os_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define USB_DWC_MAX_TX_FIFOS	16

#define USB_DWC_MAX_PHYS_EP	32

#define USB_DWC_MAX_DATA_BUFS	USBDEV_MAX_SG_NUM

#define USB_DWC_MAX_EPS		16

#define USB_DWC_MAX_EP0_SIZE	512


typedef enum usb_ep0_state {
	USB_EP0_IDLE,
	USB_EP0_IN_DATA_PHASE,
	USB_EP0_OUT_DATA_PHASE,
	USB_EP0_IN_WAIT_GADGET,
	USB_EP0_OUT_WAIT_GADGET,
	USB_EP0_IN_WAIT_NRDY,
	USB_EP0_OUT_WAIT_NRDY,
	USB_EP0_IN_STATUS_PHASE,
	USB_EP0_OUT_STATUS_PHASE,
	USB_EP0_STALL,
} usb_ep0state_e;

typedef enum usb_pcd_state {
	USB_DWC_STATE_UNCONNECTED,	/* no host */
	USB_DWC_STATE_DEFAULT,
	USB_DWC_STATE_ADDRESSED,
	USB_DWC_STATE_CONFIGURED,
} usb_pcdstate_e;

struct usb3_dwc_device;
struct usb3_dwc_pcd;

typedef struct LOS_DL_LIST usb_list_head_t;
typedef struct usbdev_req_s usb_request_t;
typedef struct usbdev_ep_s usb_endpoint_t;

typedef struct dwc_req {
	usb_dwc_dma_desc_t *trb;
	usb_dwc_dma_t trbdma;
	u32 length;
	u32 actual;
	u32 stream;

	u32 flags;
#define USB_DWC_PCD_REQ_ZERO	0x001
#define USB_DWC_PCD_REQ_STARTED	0x002
#define USB_DWC_PCD_REQ_MAP_DMA	0x100
#define USB_DWC_PCD_REQ_IN	0x200

	i32 numbuf;
	char *buf[USB_DWC_MAX_DATA_BUFS];
	usb_dwc_dma_t bufdma[USB_DWC_MAX_DATA_BUFS];
	u32 buflen[USB_DWC_MAX_DATA_BUFS];
} usb_dwc_req_t;

typedef struct usb_dwc_pcd_req {
	usb_dwc_req_t	dwc_req;
	usb_list_head_t	entry;
	struct usbdev_req_s *usb_req;
} usb_dwc_pcd_req_t;

typedef struct usb_dwc_ep {
	volatile struct usb3_dwc_pcd *pcd;
	usb_dwc_dev_ep_regs_t *out_ep_reg;
	usb_dwc_dev_ep_regs_t *in_ep_reg;

	u8 phys;
	u8 num;
	u8 type;	/* EP type: 0 - Control, 1 - ISOC, 2 - BULK, 3 - INTR */
	u8 intvl;

	u16 maxpacket;

	u8 mult;
	u8 maxburst;
	u8 num_streams;
	u8 tx_fifo_num;
	u8 tri_out;
	u8 tri_in;

	u32 stopped			: 1;
	u32 disabling			: 1;
	u32 queue_sof			: 1;
	u32 send_zlp			: 1;
	u32 stall_clear_flag		: 1;
	u32 three_stage			: 1;
	u32 xfer_started		: 1;
	u32 is_in			: 1;
	u32 active			: 1;
	u32 desc_link			: 1;
	u32 data_pid_start		: 1;
	u32 ena_once			: 1;
	u32 stalled_save		: 1;
	u32 xfer_pending		: 1;

	u32 param0out;
	u32 param1out;
	u32 param0in;
	u32 param1in;
	u32 save_state;

	const struct usb_epdesc_s *usb_ep_desc;

	usb_dwc_dma_desc_t *dma_desc;
	usb_dwc_dma_t dma_desc_dma;
	i32 desc_size;
	i32 num_desc;
	i32 desc_avail;
	i32 desc_idx;
	i32 hiber_desc_idx;

	u32 condition;
	usb_list_head_t queue;
} usb_dwc_ep_t;

typedef struct usb_dwc_usb3_pcd_ep {
	usb_dwc_ep_t dwc_ep;
	struct usbdev_ep_s usb_ep;
} usb_dwc_pcd_ep_t;

#define usb_dwc_pcd_ep_to_pcd(pcd_ep)	((pcd_ep)->dwc_ep.pcd)
#define usb_dwc_pcd_ep_num(pcd_ep)	((pcd_ep)->dwc_ep.num)
#define usb_dwc_pcd_ep_type(pcd_ep)	((pcd_ep)->dwc_ep.type)
#define usb_dwc_pcd_ep_is_in(pcd_ep)	((pcd_ep)->dwc_ep.is_in)

struct dwc_hiber_scratchpad_array {
	u64 dma_addr[15];
};

typedef struct dwc_hiber_scratchpad_array dwc_hiber_scratchpad_array_t;

typedef volatile struct usb3_dwc_pcd {
	volatile struct usb3_dwc_device *usb3_dev;

	i32 link_state;

	usb_pcdstate_e state;

	usb_ep0state_e ep0state;

	u32 ep0_status_pending			: 1;
	u32 request_config			: 1;
	u32 remote_wakeup_enable		: 1;
	u32 ltm_enable				: 1;
	u32 send_lpm				: 1;
	u32 wkup_rdy				: 1;
	u32 eps_enabled				: 1;
	u32 ute_change				: 1;

	usb_dwc_pcd_ep_t *ep0;

	usb_dwc_pcd_ep_t *out_ep[USB_DWC_MAX_EPS - 1];

	usb_dwc_pcd_ep_t *in_ep[USB_DWC_MAX_EPS - 1];

	dwc_usb3_dev_global_regs_t *dev_global_regs;

	usb_dwc_dev_ep_regs_t *out_ep_regs;

	usb_dwc_dev_ep_regs_t *in_ep_regs;

	void *hiber_scratchpad_buff[15];
	dwc_hiber_scratchpad_array_t *hiber_scratchpad_array;
	usb_dwc_dma_t hiber_scratchpad_array_dma;

	u32 ep0_out_save_state;
	u32 ep0_in_save_state;

	usb_dwc_pcd_req_t *ep0_req;

	u16 rx_thr_en;
	u16 iso_tx_thr_en;
	u16 non_iso_tx_thr_en;
	u16 rx_thr_length;
	u16 tx_thr_length;

	u8 speed;
	u8 num_out_eps;
	u8 num_in_eps;

	u8 test_mode;

	u32 request_pending;
	spinlock_t lock;
	struct usbdev_s *gadget;

	usb_dwc_dma_desc_t *ep0_setup_desc;
	usb_dwc_dma_t ep0_setup_desc_dma;

	usb_dwc_dma_desc_t *ep0_out_desc;
	usb_dwc_dma_t ep0_out_desc_dma;

	usb_dwc_dma_desc_t *ep0_in_desc;
	usb_dwc_dma_t ep0_in_desc_dma;

	u8 *ep0_status_buf;
	usb_dwc_dma_t ep0_status_buf_dma;
#define USB_DWC_STATUS_BUF_SIZE 512

	union dwc_setup_pkt {
		struct usb_ctrlreq_s req;
		u32 d32[2];
		char d8[8];
	} *usb_ep0_setup_pkt;
	usb_dwc_dma_t ep0_setup_pkt_dma;
} usb_dwc_pcd_t;

#define dwc_usb3_ep0_setup_desc(pcd)		(pcd)->ep0_setup_desc
#define dwc_usb3_ep0_setup_desc_dma(pcd)	(pcd)->ep0_setup_desc_dma
#define dwc_usb3_ep0_out_desc(pcd)		(pcd)->ep0_out_desc
#define dwc_usb3_ep0_out_desc_dma(pcd)		(pcd)->ep0_out_desc_dma
#define dwc_usb3_ep0_in_desc(pcd)		(pcd)->ep0_in_desc
#define dwc_usb3_ep0_in_desc_dma(pcd)		(pcd)->ep0_in_desc_dma
#define dwc_usb3_ep0_setup_pkt(pcd)		(pcd)->usb_ep0_setup_pkt
#define dwc_usb3_ep0_setup_pkt_dma(pcd)		(pcd)->ep0_setup_pkt_dma

extern void dwc_usb3_ep0_activate(usb_dwc_pcd_t *pcd, int restore);
extern void dwc_usb3_ep_activate(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep,
				    int restore);
extern void ep_deactivate(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep_t);
extern void dwc_usb3_stop_all_xfers(usb_dwc_pcd_t *pcd);
extern void dwc_usb3_endxfer(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_complete_request(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep, u32 event);
extern usb_dwc_pcd_ep_t *dwc_usb3_get_out_ep(const usb_dwc_pcd_t *pcd, u32 ep_num);
extern usb_dwc_pcd_ep_t *dwc_usb3_get_in_ep(const usb_dwc_pcd_t *pcd, u32 ep_num);
extern void dwc_usb3_handle_ep0_xfer(usb_dwc_pcd_t *pcd, u32 event);
extern void dwc_usb3_handle_ep_intr(usb_dwc_pcd_t *pcd, u32 physep, u32 event);
extern int dwc_usb3_handle_dev_intr(usb_dwc_pcd_t *pcd, u32 event);
extern void dwc_usb3_handle_connect_done_intr(usb_dwc_pcd_t *pcd);
extern void dwc_usb3_power_ctl(struct usb3_dwc_device *dev, int on);
extern int dwc_usb3_pcd_init(struct usb3_dwc_device *dev);
extern void dwc_usb3_pcd_remove(struct usb3_dwc_device *device);
extern usb_dwc_dma_desc_t *dwc_usb3_pcd_trb_alloc(usb_dwc_pcd_ep_t *ep,
				    int num_trbs, int trb_type, int iso_intvl, int link,
				    usb_dwc_dma_t *trbs_dma_ret);
extern void dwc_usb3_pcd_trb_free(usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_pcd_fill_trbs(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep,
				    usb_dwc_pcd_req_t *req);
extern int dwc_usb3_pcd_ep_enable(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep,
				    const struct usb_epdesc_s *ep_desc, const struct usb_ss_comp_epdesc_s *ep_comp);
extern int dwc_usb3_pcd_ep_disable(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep);
extern int dwc_usb3_pcd_ep_submit_req(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep,
				    usb_dwc_pcd_req_t *req, u32 req_flags);
extern void dwc_usb3_pcd_ep_cancel_req(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep,
				    usb_dwc_pcd_req_t *req, u32 stream);
extern void dwc_usb3_pcd_request_done(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep_t, usb_dwc_pcd_req_t *request, int status);
extern void dwc_usb3_pcd_ep_start_transfer(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep,
				    usb_dwc_pcd_req_t *req, u32 event);
extern void dwc_usb3_pcd_ep_set_stall(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_pcd_ep_clear_stall(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_pcd_ep_set_halt(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep_t,
				    int value);
extern void dwc_usb3_pcd_do_setup(usb_dwc_pcd_t *pcd);
extern void dwc_usb3_pcd_ep0_out_start(usb_dwc_pcd_t *pcd);
extern void dwc_usb3_pcd_ep0_start_transfer(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_req_t *req);
extern void dwc_usb3_pcd_ep0_continue_transfer(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_req_t *req);
extern void dwc_usb3_pcd_ep0_data_stage(usb_dwc_pcd_t *pcd, int length);
extern usb_dwc_pcd_ep_t *dwc_usb3_pcd_get_ep_by_addr(const usb_dwc_pcd_t *pcd,
				    u16 index);
extern int dwc_usb3_pcd_get_frame_number(const usb_dwc_pcd_t *pcd);
extern int dwc_usb3_pcd_isoc_ep_hiber_restart(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_pcd_stop(usb_dwc_pcd_t *pcd);
extern int dwc_usb3_gadget_connect(usb_dwc_pcd_t *pcd, int speed);
extern int dwc_usb3_gadget_disconnect(usb_dwc_pcd_t *pcd);
extern int dwc_usb3_gadget_suspend(usb_dwc_pcd_t *pcd);
extern int dwc_usb3_gadget_resume(usb_dwc_pcd_t *pcd);
extern int dwc_usb3_gadget_setup(usb_dwc_pcd_t *pcd,
				    struct usb_ctrlreq_s *ctrl);
extern int dwc_usb3_gadget_complete(usb_dwc_pcd_t *pcd, usb_dwc_pcd_ep_t *ep,
				    usb_dwc_pcd_req_t *pcd_req, int status);
extern void dwc_usb3_gadget_do_setup(usb_dwc_pcd_t *pcd);
extern void *dwc_usb3_gadget_alloc_dma(usb_dwc_pcd_ep_t *ep, int size,
				    usb_dwc_dma_t *mem_dma_ret);
extern void dwc_usb3_gadget_free_dma(usb_dwc_pcd_ep_t *ep, int size, void *mem,
				    usb_dwc_dma_t mem_dma);
extern usb_dwc_pcd_req_t *dwc_usb3_gadget_get_request(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_gadget_start_next_request(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_gadget_isoc_ep_start(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep, u32 event);
extern void dwc_usb3_gadget_request_nuke(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern void dwc_usb3_gadget_set_ep_not_started(usb_dwc_pcd_t *pcd,
				    usb_dwc_pcd_ep_t *ep);
extern int dwc_usb3_dev_speed_get(void);
extern int dwc_usb3_dev_maxpacket_get(const struct usbdev_ep_s *usb_ep);

#define USB_DMA_ALIGN_SIZE 64
#define SKB_DMA_DATA_ALIGN(X)  ALIGN(X, USB_DMA_ALIGN_SIZE)

static inline void *
dwc_usb3_dma_alloc(u32 dma_size)
{
	void *dma_addr = NULL;
	u32 size = SKB_DMA_DATA_ALIGN(dma_size);
	dma_addr = LOS_MemAllocAlign((void *)g_usb_mem_addr_start,
	    size, USB_DMA_ALIGN_SIZE);
	if (dma_addr == NULL) {
		dprintf("dwc_usb3_dma alloc failed!\n");
		return (NULL);
	}
	(void)memset_s(dma_addr, size, 0, size);
	return (dma_addr);
}

static inline void
dwc_usb3_dma_free(void *ptr)
{
	if (ptr == NULL) {
		return;
	}

	(void)LOS_MemFree((void *)g_usb_mem_addr_start, ptr);
}

#ifdef __cplusplus
}
#endif

#endif /* _USB_DEV3_PCD_H */
