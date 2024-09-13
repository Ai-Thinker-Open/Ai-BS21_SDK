/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2014-2021. All rights reserved.
 * Description: LiteOS USB OS DEVICE Implementation HeadFile
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

#ifndef _USB_DEV3_OS_H
#define _USB_DEV3_OS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Takes a usb ep pointer and returns the associated pcd ep pointer */
#define dwc_usb3_get_pcd_ep(usbep) \
	KAL_CONTAINER_OF((usbep), usb_dwc_pcd_ep_t, usb_ep)

/* Register read/write. */
#define dwc_rd32(dev, addr)	({ (void)dev; GET_UINT32(addr); })
#define dwc_wr32(dev, addr, val) ({ (void)dev; WRITE_UINT32(val, addr); })

static inline void
wmb(void)
{
	__asm__ __volatile__ ("" : : "r"(0) : "memory");
}

static inline void
dwc_udelay(void *what, uint32_t hl)
{
	LOS_Udelay(hl);
}

static inline void
dwc_mdelay(void *dev, uint32_t ms)
{
	LOS_Mdelay(ms);
}

static inline void
dwc_msleep(void *dev, uint32_t ms)
{
	LOS_Msleep(ms);
}

/* Prefix string for print macros. */
#define USB3_DWC	"dwc_usb3: "
struct dev_ice {
	int notused;
};

extern int dwc_usb3_gadget_init(struct usb3_dwc_device *usb3_dev, struct dev_ice *dev);
extern void dwc_usb3_gadget_remove(struct usb3_dwc_device *usb3_dev);
extern int dwc_usb3_create_dev_files(struct dev_ice *dev);
extern void dwc_usb3_remove_dev_files(struct dev_ice *dev);
extern int dwc_wait_pme_thread(void *data);

#ifdef __cplusplus
}
#endif

#endif /* _USB_DEV3_OS_H */
