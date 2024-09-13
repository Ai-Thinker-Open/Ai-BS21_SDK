/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2016-2019. All rights reserved.
 * Description: LiteOS USB Driver RNDIS Protocol HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2016-07-13
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

#ifndef _F_ETHER_H
#define _F_ETHER_H

#include "net/usb_eth_drv.h"
#include "gadget/usbd_cdc.h"
#include "gadget/composite.h"
#include "gadget/composite_pri.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define ETHER_NCONFIGS       1
#define ETHER_CONFIGID       0
#define ETHER_NINTERFACES    2
#define ETHER_NSTRIDS        5
#define ETHER_NUM_EPS        3
#define ETH_HDRLEN           sizeof(struct eth_hdr)

#ifdef CONFIG_DRIVERS_USB3_DEVICE_CONTROLLER
#define FRNDIS_MAX_PACKET_SIZE     0x0400
#else
#define FRNDIS_MAX_PACKET_SIZE     0x0200
#endif

#define RNDIS_STRING_ID_LEN        4
#define RNDIS_STRING_LEN           58
#define RNDIS_TYPE_LEN             40

#define LINK_STATUS_TASK_PRI       10

#define TX_COMPLETE_EVENT          1

#define RNDIS_MIN_BUFFER_COUNT     5
#define RNDIS_MAX_BUFFER_COUNT     10
#define RNDIS_MAX_TX_TIMEOUT       1000

#define LPWORK                     0

#define NETDEV_RXERRORS(a)

void rndis_net_lock(void);
void rndis_net_unlock(void);
#define net_lock() rndis_net_lock()
#define net_unlock() rndis_net_unlock()

typedef uint32_t wdparm_t;
typedef uint32_t irqstate_t;
typedef void (*worker_t)(struct work_s *arg);

enum link_status_e
{
  LINK_STATUS_UP_EVENT   = 1,
  LINK_STATUS_DOWN_EVENT = 1 << 1,
  UNLOAD_STATUS_EVENT    = 1 << 2,
  EXIT_STATUS_EVENT      = 1 << 3
};

struct fether_rndis_config_desc
{
  struct usb_cfgdesc_s confd;
  struct usb_iaddesc_s ifcad;
  struct usb_ifdesc_s ifcd;
  struct cdc_header_func_desc cdc_desc;
  struct cdc_cm_func_desc cdc_call_desc;
  struct cdc_acm_func_desc cdc_acm_desc;
  struct cdc_union_func_desc cdc_union_desc;
  struct usb_epdesc_s nepd;
  struct usb_ifdesc_s ifdd;
  struct usb_epdesc_s iepd;
  struct usb_epdesc_s oepd;
} __attribute__ ((packed));

/* Device descriptor */

struct rndis_hs_function_descriptor
{
  struct usb_iaddesc_s ifcad;
  struct usb_ifdesc_s ifcd;
  struct cdc_header_func_desc cdc_desc;
  struct cdc_cm_func_desc cdc_call_desc;
  struct cdc_acm_func_desc cdc_acm_desc;
  struct cdc_union_func_desc cdc_union_desc;
  struct usb_epdesc_s nepd;
#ifdef CONFIG_DRIVERS_USB3_DEVICE_CONTROLLER
  struct usb_ss_comp_epdesc_s ncompd;
#endif
  struct usb_ifdesc_s ifdd;
  struct usb_epdesc_s iepd;
#ifdef CONFIG_DRIVERS_USB3_DEVICE_CONTROLLER
  struct usb_ss_comp_epdesc_s icompd;
#endif
  struct usb_epdesc_s oepd;
#ifdef CONFIG_DRIVERS_USB3_DEVICE_CONTROLLER
  struct usb_ss_comp_epdesc_s ocompd;
#endif
} __attribute__ ((packed));

struct rndis_hs_descriptor
{
  struct usb_cfgdesc_s *rndis_config;
  struct rndis_hs_function_descriptor *rndis_func;
};

struct net_driver_s
{
  struct los_eth_driver driver;
  uintptr_t buf[MAX_ETH_DRV_SG];
  uint32_t len[MAX_ETH_DRV_SG];
  uint32_t sg_len;
  uint32_t total_len;
  uint8_t *d_buf;
  uint32_t d_len;
  uint32_t d_flags;
  void *d_private;
  int (*d_ifup)(struct net_driver_s *driver);
  int (*d_ifdown)(struct net_driver_s *driver);
  int (*d_txavail)(struct net_driver_s *driver);
};

void netdev_register(struct net_driver_s *netdev);
void netdev_unregister(struct net_driver_s *netdev);
void rndis_get_composite_devdesc(struct composite_devdesc_s *dev);

void rndis_workqueue_init(struct work_s *work, worker_t worker);
int work_queue(int qid, FAR struct work_s *work, worker_t worker,
               FAR void *arg, clock_t delay);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
