/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: Usb Header File
 * Author: @CompanyNameTag
 * Create:  2023-01-10
 */

#ifndef _HISOC_USB_H
#define _HISOC_USB_H

#include <stdint.h>
#include "chip_core_irq.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define CONFIG_USB_EHCI_IOBASE                  0xF9890000
#define CONFIG_USB_EHCI_IOSIZE                  0x00010000
#define CONFIG_USBUDC_REG_BASE_ADDRESS          0x58000000
#define CONFIG_USBUDC_REG_BASE_ADDRESS_LEN      0x0000

#define USB_CACHE_ALIGN_SIZE               32

#define PERI_USB                                (IO_ADDRESS(IO_REG_BASE + 0x120))
#define PERI_CRG46                              (IO_ADDRESS(CRG_REG_BASE + 0xB8))
#define PERI_CRG47                              (IO_ADDRESS(CRG_REG_BASE + 0xBC))
#define MISC_USB                                (IO_ADDRESS(USB2_PHY_REG_BASE))
#define USB2_BUS_CKEN                           BIT(0)
#define USB2_OHCI48M_CKEN                       BIT(1)
#define USB2_OHCI12M_CKEN                       BIT(2)
#define USB2_HST_PHY_CKEN                       BIT(4)
#define USB2_UTMI0_CKEN                         BIT(5)
#define USB2_UTMI1_CKEN                         BIT(6)
#define USB2_APB_CKEN                           BIT(8)
#define USB2_BUS_SRST_REQ                       BIT(12)
#define USB2_UTMI0_SRST_REQ                     BIT(13)
#define USB2_UTMI1_SRST_REQ                     BIT(14)
#define USB2_HST_PHY_SRST_REQ                   BIT(16)
#define USB2_APB_TEST_SRST_REQ                  BIT(17)

#define USB2_PHY0_REF_CKEN                      BIT(0)
#define USB2_PHY0_SRST_REQ                      BIT(8)
#define USB2_PHY0_SRST_TREQ                     BIT(9)
#define USB2_PHY1_SRST_TREQ                     BIT(11)

#define WORDINTERFACE                           BIT(0)
#define SS_BURST4_EN                            BIT(7)
#define SS_BURST8_EN                            BIT(8)
#define SS_BURST16_EN                           BIT(9)
#define USBOVR_P_CTRL                           BIT(17)
#define USB2_PHY_DPPULL_DOWN                    (3U << 26)
#define DWC_OTG_EN                              BIT(31)
#define PERI_USB0_MARK                          0x00FFFFFF
#define DEV_MODE_MARK                           0x80000000

#define DWC_USB_PORT1_BASE_ADDR                 0x58000000
#define DWC_USB_PORT1_ADDR_OFFSET               0xc000

extern const uint8_t m_aucIntPri[BUTT_IRQN];
#ifndef BUILD_FLASHBOOT
#define USB_INTR_PRIORITY                       m_aucIntPri[USB_IRQN]
#else
#define USB_INTR_PRIORITY       1
#endif
static inline uint16_t skb_data_align(uint16_t x)
{
    return (((x) + USB_CACHE_ALIGN_SIZE - 1) & ~((uintptr_t)(USB_CACHE_ALIGN_SIZE - 1)));
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _HISOC_USB_H */
