/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: LiteOS USB Driver UVC Protocol Private HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2021-08-17
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

#ifndef _F_UVC_PRI_H
#define _F_UVC_PRI_H

#include "gadget/f_uvc.h"
#include "gadget/composite.h"
#include "gadget/usbdev.h"
#include "implementation/_thread_ref.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* The following macros can not be configured for lib version */

#if defined(CONFIG_DRIVERS_USB_UVC_GADGET_ISOC)
#define FUVC_BULK_TO_ISO_CONVERT 1 /* 0: BULK mode, 1: ISOC mode */
#else
#define FUVC_BULK_TO_ISO_CONVERT 0
#endif

#if FUVC_BULK_TO_ISO_CONVERT
#define STREAM_BUF_SIZE 3072
#else
#define STREAM_BUF_SIZE 16384
#endif

#if defined(CONFIG_DRIVERS_USB_UVC_GADGET_VER_1_0)
#define UVC_VERSION_1_0
#define UVC_VERSION 0x100
#elif defined(CONFIG_DRIVERS_USB_UVC_GADGET_VER_1_1)
#define UVC_VERSION_1_1
#define UVC_VERSION 0x110
#endif

#define UVC_FRAME_WIDTH_144    144
#define UVC_FRAME_WIDTH_240    240
#define UVC_FRAME_WIDTH_288    288
#define UVC_FRAME_WIDTH_360    360
#define UVC_FRAME_WIDTH_480    480
#define UVC_FRAME_WIDTH_720    720
#define UVC_FRAME_WIDTH_1080   1080

/* UVC input terminal descriptor, refer to UVC Specification
 * 1.5, section 3.7.2.1 for the details
 */

struct uvc_it_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    terminalid;
  u16   terminaltype;
  u8    assocterminal;
  u8    terminal;
} __attribute__((packed));

/* UVC output terminal descriptor, refer to UVC specification
 * 1.5, section 3.7.2.2 for the details
 */

struct uvc_ot_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    terminalid;
  u16   terminaltype;
  u8    assocterminal;
  u8    sourceid;
  u8    terminal;
} __attribute__((packed));

/* UVC camera terminal descriptor, refer to UVC specification
 * 1.5, section 3.7.2.3 for the details
 */

struct uvc_ct_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    terminalid;
  u16   terminaltype;
  u8    assocterminal;
  u8    terminal;
  u16   objfocallenmin;
  u16   objfocallenmax;
  u16   ocularfocallen;
  u8    controlsize;
  u8    controls[3];
} __attribute__((packed));

/* Selector Unit Descriptor, UVC spec., section 3.7.2.4 */

#define DEFINE_UVC_SELECTOR_DESCRIPTOR(p)   \
struct uvc_selector_descriptor ## p         \
{                                           \
  u8    len;                                \
  u8    type;                               \
  u8    subtype;                            \
  u8    unitid;                             \
  u8    nrinpins;                           \
  u8    sourceid[p];                        \
  u8    selector;                           \
} __attribute__((packed))

DEFINE_UVC_SELECTOR_DESCRIPTOR(2);

/* Processing Unit Descriptor, UVC spec. 1.5, section 3.7.2.5 */

struct uvc_processing_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    unitid;
  u8    sourceid;
  u16   maxmultiplier;
  u8    controlsize;
  u8    controls[3];
  u8    processing;
#ifndef UVC_VERSION_1_0
  u8    videostandards;
#endif
} __attribute__((packed));

/* UVC Extension Unit Descriptor, UVC spec. 1.5, section 3.7.2.7 */

#define DECLARE_UVC_EXTENSION_UNIT(p, n)               \
struct uvc_extension_unit_descriptor ## p ## x ## n    \
{                                                      \
  u8    len;                                           \
  u8    type;                                          \
  u8    subtype;                                       \
  u8    unitid;                                        \
  u8    guidextensioncode[16];                         \
  u8    numcontrols;                                   \
  u8    nrinpins;                                      \
  u8    sourceid[p];                                   \
  u8    controlsize;                                   \
  u8    controls[n];                                   \
  u8    extension;                                     \
} __attribute__((packed))

DECLARE_UVC_EXTENSION_UNIT(1, 2);

/* frame based Payload Video Format Descriptor, USB_Video_Payload_Frame_Based_1.1, section 3.1.1 */

struct uvc_frame_based_format_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    formatindex;
  u8    numframedesc;
  u8    guidformat[16];
  u8    bitsperpixel;
  u8    dframeindex;
  u8    aspectratiox;
  u8    aspectratioy;
  u8    interlaceflags;
  u8    copyprotect;
  u8    variablesize;
} __attribute__((packed));

/* Frame Based payload Video Frame Descriptors, USB_Video_Payload_Frame_Based_1.1, section 3.1.2 */

#define DECLARE_UVC_FRAME_BASED_FRAME_DESCRITPROR(n)  \
struct uvc_frame_based_frame_descriptor ## n          \
{                                                     \
  u8    len;                                          \
  u8    type;                                         \
  u8    subtype;                                      \
  u8    frameindex;                                   \
  u8    capabilities;                                 \
  u16   width;                                        \
  u16   height;                                       \
  u32   minbitrate;                                   \
  u32   maxbitrate;                                   \
  u32   dframeinterval;                               \
  u8    frameintervaltype;                            \
  u32   bytesperline;                                 \
  u32   frameinterval[n];                             \
} __attribute__((packed))

DECLARE_UVC_FRAME_BASED_FRAME_DESCRITPROR(1);

/* H.264 Payload Video Format Descriptor, USB_Video_Payload_H264_1.5, section 3.1.1 */

struct uvc_h264_format_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    formatindex;
  u8    numframedesc;
  u8    dframeindex;
  u8    maxcodecconfigdelay;
  u8    slicemodes;
  u8    syncframetypes;
  u8    resolutionscaling;
  u8    reserved1;
  u8    ratecontrolmodes;
  u16   maxmbpersec_no[4];
  u16   maxmbpersec_temp[4];
  u16   maxmbpersec_qual[4];
  u16   maxmbpersec_spat[4];
  u16   maxmbpersec_full[4];
} __attribute__((packed));

/* H.264 Payload Video Frame Descriptor, section 3.1.2 */

#define DECLARE_UVC_H264_FRAME_DESCRIPTOR(n)  \
struct uvc_h264_frame_descriptor ## n         \
{                                             \
  u8    len;                                  \
  u8    type;                                 \
  u8    subtype;                              \
  u8    frameindex;                           \
  u16   width;                                \
  u16   height;                               \
  u16   sarwidth;                             \
  u16   sarheight;                            \
  u16   profile;                              \
  u8    levelidc;                             \
  u16   constrainedtoolset;                   \
  u32   usages;                               \
  u16   capabilities;                         \
  u32   svccapabilities;                      \
  u32   mvccapabilities;                      \
  u32   minbitrate;                           \
  u32   maxbitrate;                           \
  u32   dframeinterval;                       \
  u8    numframeintervals;                    \
  u8    frameintervals[n];                    \
} __attribute__((packed))

DECLARE_UVC_H264_FRAME_DESCRIPTOR(1);

/* UVC color-matching descriptor, UVC spec., section 3.9.2.6 */

struct uvc_color_matching_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u8    colorprimaries;
  u8    transferchars;
  u8    matrixcoefficients;
} __attribute__((packed));

#define YUYV_FRAME_FACTOR 2
#define NV12_FRAME_FACTOR 1.5
#define NV21_FRAME_FACTOR 1.5

/* UVC VideoControl interrupt endpoint descriptor, UVC spec. 1.5, section 3.8.2.2 */

struct uvc_vc_int_endpoint_descriptor
{
  u8    len;
  u8    type;
  u8    subtype;
  u16   maxtransfersize;
} __attribute__((packed));

/* Video probe and commit controls for device, UVC spec. 1.0 and 1.1, section 4.3.1.1 */

struct uvc_probe_commit_control_dev
{
  uint16_t  bmHint;
  uint8_t   bFormatIndex;
  uint8_t   bFrameIndex;
  uint32_t  dwFrameInterval;
  uint16_t  wKeyFrameRate;
  uint16_t  wPFrameRate;
  uint16_t  wCompQuality;
  uint16_t  wCompWindowSize;
  uint16_t  wDelay;
  uint32_t  dwMaxVideoFrameSize;
  uint32_t  dwMaxPayloadTransferSize;
#ifndef UVC_VERSION_1_0
  uint32_t  dwClockFrequency;
  uint8_t   bmFramingInfo;
  uint8_t   bPreferedVersion;
  uint8_t   bMinVersion;
  uint8_t   bMaxVersion;
#endif
} __attribute__ ((packed));

/* Video probe and commit controls, UVC spec. 1.5, section 4.3.1.1 */

struct uvc_probe_commit_control1_5
{
  u16   hint;
  u8    formatindex;
  u8    frameindex;
  u32   frameinterval;
  u16   keyframerate;
  u16   framerate;
  u16   compquality;
  u16   compwindowsize;
  u16   delay;
  u32   maxframesize;
  u32   maxpayloadsize;
  u32   clockfrequency;
  u8    mframinginfo;
  u8    preferedversion;
  u8    minversion;
  u8    maxversion;
  u8    usage;
  u8    bitdepthluma;
  u8    settings;
  u8    maxframesplus;
  u8    ratecontrolmodes;
  u8    layoutperstream;
} __attribute__((packed));


enum atomic_status
{
  IDLE_STATUS = 0,
  RECV_STATUS,
  CLOSE_STATUS,
  UNBIND_STATUS,
};

enum {
  STREAM_STATUS_EVENT   = 1u << 0,
  STREAM_CLEAR_EVENT    = 1u << 1,
  UNBIND_STATUS_EVENT   = 1u << 2,
  UVC_EXIT_STATUS_EVENT = 1u << 3,
};

enum {
  UVC_EVENT_LIST     = 1u << 0,
  UVC_TRANSFER_EVENT = 1u << 1,
};

struct uvc_probe_t
{
  u8 set;
  u8 get;
  u8 max;
  u8 min;
};

struct uvc_stream_pack
{
  uint8_t *buf;
  uint32_t buf_len;
  struct uvc_pack *pack;
  struct LOS_DL_LIST list;
  uint8_t free_flag;
  bool last; /* receive is_frame_end */
};

struct uvc_dev_s
{
  uint32_t                                   control;       /* Class-specific control request value */
  struct uvc_probe_commit_control_dev        probe;         /* Probe control structure */
  struct uvc_probe_commit_control_dev        commit;        /* Probe control structure */
  struct usbdev_ep_s                        *ctrl_ep;       /* Control transfer endpoint */
  struct usbdev_ep_s                        *vs_ep;         /* Video Streaming endpoint */

  struct usbdev_req_s                        ctrlreq;       /* Control request */
  struct usbdev_req_s                        vc_ctrlreq;    /* Video Control request */
  struct usbdev_req_s                        streamreq;     /* Video Streaming request */

  bool                                       connected;     /* Connected to USB host? */

  void                                      *uvc_handle;    /* UVC transmission handle */
  uint32_t                                   fid;           /* Frame Identifier */

  struct uvc_format_info                     format_info;
  uint32_t                                   bulk_size;
  uint32_t                                   img_size;
  uint32_t                                   com_flag;
  struct uvc_probe_t                         probe_status;

  spinlock_t                                 lock;
  uint32_t                                   event_id;
  uint32_t                                   unit_id;

  volatile Atomic                            uvc_atomic;
  EVENT_CB_S                                 uvc_transfer_event;

  spinlock_t                                 pack_list_lock;
  spinlock_t                                 release_list_lock;
  EVENT_CB_S                                 uvc_stream_event;
  uint32_t                                   task_id;
  struct LOS_DL_LIST                         pack_list;
  struct LOS_DL_LIST                         release_list;
  struct LOS_DL_LIST                         send_queue;
  uint8_t                                    stream_off_flag; /* Flag for switching resolution in bulk mode */

#ifdef CONFIG_DRIVERS_USB_UVC_IOCTL
  /* uvc queue for ioctl cmd VIDIOC_DQEVENT */
  spinlock_t                                 uvc_event_lock;
  struct LOS_DL_LIST                         uvc_event_queue;
  uint32_t                                   uvc_event_queue_len;
#define UVC_EVENT_UPPER_LIMIT                5
#endif
};

struct uvc_driver_s
{
  struct usbdevclass_driver_s  drvr;
  struct uvc_dev_s            *dev;
};

/* Private UVC device driver instance structure */

struct uvc_softc
{
  struct uvc_dev_s    dev;
  struct uvc_driver_s drvr;
} __attribute__((packed));

/* Transfer continue function, defined in usbd_video.c */

int uvc_acquire_mutex(void);
void uvc_release_mutex(void);
bool uvc_is_running(void);
void uvc_stream_init(struct uvc_dev_s *fuvc);
void uvc_stream_deinit(struct uvc_dev_s *fuvc);
int uvc_stream_thread_init(struct uvc_dev_s *fuvc);
void uvc_stream_thread_deinit(struct uvc_dev_s *fuvc);
void fuvc_vs_req_complete(struct usbdev_ep_s *ep, struct usbdev_req_s *req);

void fuvc_streaming_on(struct uvc_dev_s *fuvc, uint32_t events);
void fuvc_streaming_off(struct uvc_dev_s *fuvc);

bool uvc_open_format_check(const struct uvc_open_param *param);
bool uvc_format_info_check(const struct uvc_format_info *format_info);

void uvc_unit_control_register(void);

void usbdev_uvc_initialize_sub(struct composite_devdesc_s *dev, int ifnobase, int minor);
void usbclass_uvc_stream_ep_reset(const struct uvc_dev_s *fuvc);
extern struct usb_epdesc_s g_fuvc_hs_bulk_streaming_ep;
extern struct usb_epdesc_s g_fuvc_hs_isoc_streaming_ep;

bool is_ioctl_mode(void);
bool set_control_mode(int control_mode);
void clear_control_mode(void);
int set_uvc_streamon(struct uvc_dev_s *fuvc);
int set_uvc_streamoff(struct uvc_dev_s *fuvc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _F_UVC_PRI_H */
