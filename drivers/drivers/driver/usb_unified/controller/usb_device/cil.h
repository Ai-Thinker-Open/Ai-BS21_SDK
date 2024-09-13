/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2021. All rights reserved.
 * Description: LiteOS USB register operation HeadFile
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

#ifndef _USB_DEV3_CIL_H
#define _USB_DEV3_CIL_H

#ifdef __cplusplus
extern "C" {
#endif

extern int dwc_usb3_pcd_check_snpsid(dwc_usb3_device_t *pdev, uint32_t addr_ofs);
extern int dwc_usb3_pcd_common_init(dwc_usb3_device_t *pdev,
				    const volatile uint8_t *base, dwc_usb3_core_params_t *core_params);
extern void dwc_usb3_pcd_common_remove(dwc_usb3_device_t *pdev);
extern void dwc_usb3_pcd_device_init(dwc_usb3_device_t *pdev, int soft_reset, int restore);
extern void dwc_usb3_pcd_device_remove(dwc_usb3_device_t *pdev);
extern int dwc_usb3_pcd_get_link_state(const usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_pcd_set_link_state(usb_dwc_pcd_t *pcd_t, uint32_t state);
extern void dwc_usb3_pcd_remote_wake(usb_dwc_pcd_t *pcd_t, uint32_t func);
extern void dwc_usb3_fill_desc(usb_dwc_dma_desc_t *pdesc, usb_dwc_dma_t addr,
			       uint32_t dma_len, uint32_t stream, uint32_t type,
			       uint32_t ctrlbits, int own);
extern void dwc_usb3_start_desc_chain(usb_dwc_dma_desc_t *pdesc);
extern void dwc_usb3_end_desc_chain(usb_dwc_dma_desc_t *pdesc);
extern void dwc_usb3_enable_desc(usb_dwc_dma_desc_t *pdesc);
extern void dwc_usb3_disable_desc(usb_dwc_dma_desc_t *pdesc);
extern int dwc_usb3_xmit_fn_remote_wake(usb_dwc_pcd_t *pcd, uint32_t intf);
extern int dwc_usb3_xmit_ltm(usb_dwc_pcd_t *pcd, uint32_t val);
extern int dwc_usb3_xmit_host_role_request(usb_dwc_pcd_t *pcd, uint32_t param);
extern int dwc_usb3_set_scratchpad_buf_array(usb_dwc_pcd_t *pcd, usb_dwc_dma_t addr);
extern int dwc_usb3_flush_fifo(usb_dwc_pcd_t *pcd, uint32_t fifo_sel);
extern int dwc_usb3_dep_cfg(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    uint32_t dep_cfg0, uint32_t dep_cfg1, uint32_t dep_cfg2);
extern int dwc_usb3_dep_xfercfg(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    uint32_t dep_strmcfg);
extern uint32_t dwc_usb3_dep_getepstate(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg);
extern int dwc_usb3_dep_sstall(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg);
extern int dwc_usb3_dep_cstall(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    int clr_pend);
extern int dwc_usb3_dep_startxfer(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    usb_dwc_dma_t addr, uint32_t stream_or_uf);
extern int dwc_usb3_dep_updatexfer(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    uint32_t tri);
extern int dwc_usb3_dep_endxfer(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    uint32_t tri, uint32_t flags, void *condition);
#define DWC_ENDXFER_FORCE	1
#define DWC_ENDXFER_NODELAY	2

extern int dwc_usb3_dep_startnewcfg(const usb_dwc_pcd_t *pcd, usb_dwc_dev_ep_regs_t *ep_reg,
			    uint32_t rsrcidx);
extern int dwc_usb3_enable_ep(usb_dwc_pcd_t *pcd_t, const usb_dwc_pcd_ep_t *ep);
extern int dwc_usb3_disable_ep(usb_dwc_pcd_t *pcd_t, const usb_dwc_pcd_ep_t *ep);
extern int dwc_usb3_get_device_speed(const usb_dwc_pcd_t *pcd_t);
extern int dwc_usb3_get_frame(const usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_set_address(usb_dwc_pcd_t *pcd_t, uint32_t addr);
extern void dwc_usb3_ena_usb2_suspend(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_dis_usb2_suspend(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_accept_u1(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_accept_u2(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_enable_u1(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_enable_u2(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_disable_u1(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_disable_u2(usb_dwc_pcd_t *pcd_t);
extern int dwc_usb3_u1_enabled(usb_dwc_pcd_t *pcd_t);
extern int dwc_usb3_u2_enabled(usb_dwc_pcd_t *pcd_t);
extern void dwc_usb3_clr_eps_enabled(usb_dwc_pcd_t *pcd_t);

#define dwc_usb3_is_hwo(pdesc)	((pdesc)->control & USB_DWC_DSCCTL_HWO_BIT)
#define dwc_usb3_is_ioc(pdesc)	((pdesc)->control & USB_DWC_DSCCTL_IOC_BIT)

#define dwc_usb3_get_xfercnt(pdesc) \
	((pdesc)->status >> USB_DWC_DSCSTS_XFRCNT_SHIFT & \
	 USB_DWC_DSCSTS_XFRCNT_BITS >> USB_DWC_DSCSTS_XFRCNT_SHIFT)

#define dwc_usb3_get_xfersts(pdesc) \
	((pdesc)->status >> USB_DWC_DSCSTS_TRBRSP_SHIFT & \
	 USB_DWC_DSCSTS_TRBRSP_BITS >> USB_DWC_DSCSTS_TRBRSP_SHIFT)

#define dwc_usb3_get_xfersofn(pdesc) \
	((pdesc)->control >> DWC_DSCCTL_STRMID_SOFN_SHIFT & \
	 USB_DWC_DSCCTL_STRMID_SOFN_BITS >> USB_DWC_DSCCTL_STRMID_SOFN_SHIFT)

#define dwc_usb3_get_eventsofn(event) \
	((event) >> USB_DWC_DEPEVT_ISOC_UFRAME_NUM_SHIFT & \
	 USB_DWC_DEPEVT_ISOC_UFRAME_NUM_BITS >> USB_DWC_DEPEVT_ISOC_UFRAME_NUM_SHIFT)

extern void dwc_usb3_set_tx_fifo_size(const dwc_usb3_device_t *pdev, const uint32_t *sz);
extern void dwc_usb3_set_rx_fifo_size(const dwc_usb3_device_t *pdev, uint32_t size);
extern void dwc_usb3_init_eventbuf(dwc_usb3_device_t *pdev, int bufno,
			    uint32_t *addr, const uint32_t sz, usb_dwc_dma_t dma_addr);
extern void dwc_usb3_dis_flush_eventbuf_intr(dwc_usb3_device_t *pdev, int bufno);
extern void dwc_usb3_enable_common_interrupts(dwc_usb3_device_t *pdev);
extern void dwc_usb3_enable_device_interrupts(dwc_usb3_device_t *pdev);
extern int dwc_usb3_handle_event(dwc_usb3_device_t *pdev);
extern int dwc_usb3_irq(dwc_usb3_device_t *pdev, int irq);
extern int dwc_usb3_get_eventbuf_count(dwc_usb3_device_t *dev);
extern void dwc_usb3_update_eventbuf_count(dwc_usb3_device_t *dev, int count);

static __inline uint32_t
dwc_usb3_mode(dwc_usb3_device_t *pdev)
{
	return (dwc_rd32(pdev, &pdev->core_global_regs->gsts) & 0x1);
}

static __inline int
dwc_usb3_is_device_mode(dwc_usb3_device_t *pdev)
{
	return (dwc_usb3_mode(pdev) != USB_DWC_GSTS_HOST_MODE);
}

static __inline int
dwc_usb3_is_host_mode(dwc_usb3_device_t *pdev)
{
	return (dwc_usb3_mode(pdev) == USB_DWC_GSTS_HOST_MODE);
}

#ifdef __cplusplus
}
#endif

#endif /* _USB_DEV3_CIL_H */
