/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: LiteOS USB Driver UVC Protocol HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2017-04-17
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

#ifndef _USB_UVC_INCLUDE_H
#define _USB_UVC_INCLUDE_H

#include "stdint.h"
#include "stdbool.h"
#include "implementation/_types_ref.h"
#include "uvc/usb_uvc.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* The following macros can be configured */

#define UNIT_ID_CAMERA               1
#define UNIT_ID_PROCESSING           2
#define UNIT_ID_OUTPUT               3
#define UNIT_ID_H264_EXTENSION       10
#define UNIT_ID_HICAMERA_EXTENSION   0x11

#if !defined(CONFIG_DRIVERS_USB_UVC_GADGET_YUYV) && \
    !defined(CONFIG_DRIVERS_USB_UVC_GADGET_NV12) && \
    !defined(CONFIG_DRIVERS_USB_UVC_GADGET_NV21) && \
    !defined(CONFIG_DRIVERS_USB_UVC_GADGET_MJPEG) && \
    !defined(CONFIG_DRIVERS_USB_UVC_GADGET_H264) && \
    !defined(CONFIG_DRIVERS_USB_UVC_GADGET_H265)

#define CONFIG_DRIVERS_USB_UVC_GADGET_YUYV
#endif

#ifdef CONFIG_DRIVERS_USB_UVC_GADGET_YUYV
#define ENABLE_YUYV                  1
#else
#define ENABLE_YUYV                  0
#endif

#ifdef CONFIG_DRIVERS_USB_UVC_GADGET_NV12
#define ENABLE_NV12                  1
#else
#define ENABLE_NV12                  0
#endif

#ifdef CONFIG_DRIVERS_USB_UVC_GADGET_NV21
#define ENABLE_NV21                  1
#else
#define ENABLE_NV21                  0
#endif

#ifdef CONFIG_DRIVERS_USB_UVC_GADGET_MJPEG
#define ENABLE_MJPEG                 1
#else
#define ENABLE_MJPEG                 0
#endif

#ifdef CONFIG_DRIVERS_USB_UVC_GADGET_H264
#define ENABLE_H264                  1
#else
#define ENABLE_H264                  0
#endif

#ifdef CONFIG_DRIVERS_USB_UVC_GADGET_H265
#define ENABLE_H265                  1
#else
#define ENABLE_H265                  0
#endif

#define UVC_FORMAT_COUNT (ENABLE_YUYV + ENABLE_NV12 + ENABLE_NV21 + \
                          ENABLE_H264 + ENABLE_H265 + ENABLE_MJPEG)

/* USB Terminal types, UVC spec. 1.5, section B.1 */

#define USB_UVC_TT_VENDOR_SPECIFIC  0x0100
#define USB_UVC_TT_STREAMING        0x0101

/* Camera Terminal Control Selectors, UVC spec. 1.5, section A.9.4 */

#define USBD_UVC_CT_CONTROL_UNDEFINED                0x00
#define USBD_UVC_CT_SCANNING_MODE_CONTROL            0x01
#define USBD_UVC_CT_AE_MODE_CONTROL                  0x02
#define USBD_UVC_CT_AE_PRIORITY_CONTROL              0x03
#define USBD_UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL   0x04
#define USBD_UVC_CT_EXPOSURE_TIME_RELATIVE_CONTROL   0x05
#define USBD_UVC_CT_FOCUS_ABSOLUTE_CONTROL           0x06
#define USBD_UVC_CT_FOCUS_RELATIVE_CONTROL           0x07
#define USBD_UVC_CT_FOCUS_AUTO_CONTROL               0x08
#define USBD_UVC_CT_IRIS_ABSOLUTE_CONTROL            0x09
#define USBD_UVC_CT_IRIS_RELATIVE_CONTROL            0x0a
#define USBD_UVC_CT_ZOOM_ABSOLUTE_CONTROL            0x0b
#define USBD_UVC_CT_ZOOM_RELATIVE_CONTROL            0x0c
#define USBD_UVC_CT_PANTILT_ABSOLUTE_CONTROL         0x0d
#define USBD_UVC_CT_PANTILT_RELATIVE_CONTROL         0x0e
#define USBD_UVC_CT_ROLL_ABSOLUTE_CONTROL            0x0f
#define USBD_UVC_CT_ROLL_RELATIVE_CONTROL            0x10
#define USBD_UVC_CT_PRIVACY_CONTROL                  0x11
#define USBD_UVC_CT_FOCUS_SIMPLE_CONTROL             0x12
#define USBD_UVC_CT_WINDOW_CONTROL                   0x13
#define USBD_UVC_CT_REGION_OF_INTEREST_CONTROL       0x14

/* Input Terminal Types, UVC spec. 1.5, section B.2 */

#define USB_UVC_ITT_VENDOR_SPECIFIC        0x0200
#define USB_UVC_ITT_CAMERA                 0x0201
#define USB_UVC_ITT_MEDIA_TRANSPORT_INPUT  0x0202

/* UVC Processing Unit Control Selectors, UVC spec. 1.5, section A.9.5 */

#define USBD_UVC_PU_CONTROL_UNDEFINED                        0x00
#define USBD_UVC_PU_BACKLIGHT_COMPENSATION_CONTROL           0x01
#define USBD_UVC_PU_BRIGHTNESS_CONTROL                       0x02
#define USBD_UVC_PU_CONTRAST_CONTROL                         0x03
#define USBD_UVC_PU_GAIN_CONTROL                             0x04
#define USBD_UVC_PU_POWER_LINE_FREQUENCY_CONTROL             0x05
#define USBD_UVC_PU_HUE_CONTROL                              0x06
#define USBD_UVC_PU_SATURATION_CONTROL                       0x07
#define USBD_UVC_PU_SHARPNESS_CONTROL                        0x08
#define USBD_UVC_PU_GAMMA_CONTROL                            0x09
#define USBD_UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL        0x0a
#define USBD_UVC_PU_WHITE_BALANCE_TEMPERATURE_AUTO_CONTORL   0x0b
#define USBD_UVC_PU_WHITE_BALANCE_COMPONENT_CONTROL          0x0c
#define USBD_UVC_PU_WHITE_BALANCE_COMPONENT_AUTO_CONTROL     0x0d
#define USBD_UVC_PU_DIGITAL_MULTIPLIER_CONTROL               0x0e
#define USBD_UVC_PU_DIGITAL_MULTIPLIER_LIMIT_CONTROL         0x0f
#define USBD_UVC_PU_HUE_AUTO_CONTROL                         0x10
#define USBD_UVC_PU_ANALOG_VIDEO_STANDARD_CONTROL            0x11
#define USBD_UVC_PU_ANALOG_LOCK_STATUS_CONTROL               0x12
#define USBD_UVC_PU_CONTRAST_AUTO_CONTROL                    0x13

/* Color Primaries and the reference white */

#define UVC_COLOR_UNSPECIFIED      0x0
#define UVC_COLOR_BT709_SRGB       0x1
#define UVC_COLOR_BT4702M          0x2
#define UVC_COLOR_BT4702BG         0x3
#define UVC_COLOR_SMPTE_170M       0x4
#define UVC_COLOR_SMPTE_240M       0x5

/* Color transfer characteristics, gamma function */

#define UVC_COLOR_LINEAR           0x6
#define UVC_COLOR_SRGB             0x7

/* Matrix Coefficients */

#define UVC_COLOR_MC_UNSPECIFIED   0x0
#define UVC_COLOR_MC_BT709         0x1
#define UVC_COLOR_MC_FCC           0x2
#define UVC_COLOR_MC_BT4702BG      0x3
#define UVC_COLOR_MC_SMPTE_170M    0x4
#define UVC_COLOR_MC_SMPTE_240M    0x5

#define HICAMERA_GET_VERSION_CONTROL    0x01
#define HICAMERA_START_UPDATE_CONTROL   0x02
#define HICAMERA_TRUN_ON_CONTROL        0x03
#define HICAMERA_TRUN_OFF_CONTROL       0x04
#define HICAMERA_RESET_CONTROL          0x05
#define HICAMERA_VIBRATOR_UP_CONTROL    0x06
#define HICAMERA_VIBRATOR_DOWN_CONTROL  0x07
#define HICAMERA_VIBRATOR_LEFT_CONTROL  0x08
#define HICAMERA_VIBRATOR_RIGHT_CONTROL 0x09

enum camera_cmd
{
  CMD_CAMERA_UNIT_CONTROL   = 1,
  CMD_PROCESS_UNIT_CONTROL  = 2,
  CMD_HICAMERA_UNIT_CONTROL = 0x11,  /* Extern unit */
  CMD_H264_UNIT_CONTROL     = 0xa,   /* Extern unit */
};

/* Type-define UVC handle as pointer type */

typedef void *uvc_t;

/* UVC handle structure, includes various related information to
 * transmit video stream over USB protocol.
 */

struct uvc_handle
{
  u32 vid_w;                    /* Video Frame width in pixels */
  u32 vid_h;                    /* Video Frame height in pixels */
  u32 vid_f;                    /* Video Frame format */
  u32 state;                    /* State of UVC handle */

  void *fuvc;                   /* Pointer to the UVC function structure uvc_dev_s */
};

struct fuvc_frame_info
{
  uint32_t width;
  uint32_t height;
  uint32_t intervals[8];
};

struct fuvc_format_info
{
  uint32_t fcc;
  const struct fuvc_frame_info *frames;
};

/* frames_count is the frames count in format_info */

void fuvc_frame_descriptors_get(const struct fuvc_format_info *format_info, uint32_t frames_count);

/* UVC function error codes */

#define UVC_OK                   0x00     /* No error, function has successfully completed */
#define UVC_ERROR_NOMATCH        0x01     /* The operation can not be complete, due to mismatch of UVC state */
#define UVC_ERROR_HANDLE         0x02     /* Mismatch of UVC handle, UVC can be obtained only once before calling close */
#define UVC_ERROR_PTR            0x03     /* Invalid pointer */
#define UVC_ERROR_MEMORY         0x04     /* Memory error */
#define UVC_ERROR_VALUE          0x05     /* Incorrect value */
#define UVC_ERROR_FATAL          0x06     /* Fatal internal error, please contact the one who wrote the code */

/* UVC video format index*/

#define UVC_VFF_YUY2             0x00
#define UVC_VFF_NV12             (UVC_VFF_YUY2 + ENABLE_YUYV)
#define UVC_VFF_NV21             (UVC_VFF_NV12 + ENABLE_NV12)
#define UVC_VFF_MJPEG            (UVC_VFF_NV21 + ENABLE_NV21)
#define UVC_VFF_H264             (UVC_VFF_MJPEG + ENABLE_MJPEG)
#define UVC_VFF_H265             (UVC_VFF_H264 + ENABLE_H264)

#define UVC_INVALID_HANDLE       0xFFFFFFFF

/* Parameter structure used to open a Video handle (UVC device) */

struct uvc_open_param
{
#define UVC_VIDEO_WIDTH_DEF      1920
#define UVC_VIDEO_HEIGHT_DEF     1080
#define UVC_VIDEO_WIDTH_MAX      4096
#define UVC_VIDEO_HEIGHT_MAX     4096
  uint32_t vid_width;   /* Width of the video frame, in pixels */
  uint32_t vid_height;  /* Height of the video frame, in pixels */
  uint32_t vid_format;  /* Format of video frame */

  uint32_t bulk_size;
  uint32_t img_size;
};

/* Format info */

struct uvc_format_info
{
  uint32_t width;
  uint32_t height;
  uint32_t format;

  uint32_t status;
} __attribute__((packed));

struct uvc_pack
{
  uint64_t buf_vir_addr;             /* Virtual address of the stream buf */
  uint32_t buf_size;                 /* Size of the stream buf */
  uint64_t pack_vir_addr;            /* Virtual address of the current package */
  uint32_t pack_len;                 /* Length of the current package */

  void     (*callback_func)(void *); /* Callback for reclaiming current package resources */
  bool     is_frame_end;             /* Whether the current package is the end of a frame */

  void     *private_data;            /* Private data for SDK */
};

/* Receive uvc video stream data
 * Note:The business must ensure that buf_vir_addr and pack_vir_addr are legal addresses,
 * and the difference between the addresses cannot exceed the maximum value of uint32_t
 */

int uvc_recv_pack(const struct uvc_pack *pack);

/* Open the UVC device, and returns a handle */

int uvc_open_device(uvc_t *hdl, const struct uvc_open_param *param);

/* Closes a UVC handle */

int uvc_close_device(uvc_t hdl);

enum format_switch_status
{
  FORMAT_SWITCH_FINISH = 0,
  FORMAT_SWITCH_PENDING
};

/* Check the frame switch status */

enum format_switch_status uvc_format_status_check(void);

int uvc_format_info_get(struct uvc_format_info *info);

#define UVC_WAIT_HOST_NOP      0x0
#define UVC_WAIT_HOST_FOREVER  0x1

/* Wait for UVC USB host connection */

int uvc_wait_host(uvc_t hdl, int wait_option, int *connected);

/* UVC device state definitions */

enum uvc_state
{
  UVC_STATE_IDLE          = 0x01,     /* UVC device has been opened, but not connected to USB host */
  UVC_STATE_CONN          = 0x02,     /* UVC device has connected to USB host */
  UVC_STATE_CLOSE         = 0x04,     /* UVC device has been closed */
  UVC_STATE_NONE          = 0x08      /* Not used */
};

/* The function returns the operating state of UVC device */

int uvc_get_state(uvc_t hdl, uint32_t *state);

/* Stop stransmission */

int uvc_video_stop(uvc_t hdl);

typedef uint32_t (*camera_control_func)(void *buf, uint32_t len, uint32_t event_id, uint32_t cmd_type);

struct uvc_camera_cmd
{
  uint32_t id;
  uint8_t name[32];
  camera_control_func uvc_control_func;
};

int hi_camera_register_cmd(const struct uvc_camera_cmd *cmd);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_UVC_INCLUDE_H */