/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: LiteOS USB Driver Video Class HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2022-04-16
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

#ifndef _USB_UVC_H
#define _USB_UVC_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)   ((sizeof(a) / sizeof(a[0])))
#endif

#define fourcc(a, b, c, d) \
  ((uint32_t)(a) | ((uint32_t)(b) << 8) | ((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))

#define V4L2_PIX_FMT_YUYV   fourcc('Y', 'U', 'Y', 'V') /* 16  YUV 4:2:2 */
#define V4L2_PIX_FMT_NV12   fourcc('N', 'V', '1', '2') /* 12  Y/CbCr 4:2:0 */
#define V4L2_PIX_FMT_NV21   fourcc('N', 'V', '2', '1') /* 12  Y/CrCb 4:2:0 */
#define V4L2_PIX_FMT_MJPEG  fourcc('M', 'J', 'P', 'G') /* Motion-JPEG */
#define V4L2_PIX_FMT_H264   fourcc('H', '2', '6', '4') /* H264 with start codes */
#define V4L2_PIX_FMT_H265   fourcc('H', '2', '6', '5') /* H265 with start codes */

/* UVC Video Class-specific Descriptor Types, UVC spec. 1.5, section A.2 */

#define USB_UVC_SC_UNDEFINED                   0x00
#define USB_UVC_SC_VIDEOCONTROL                0x01
#define USB_UVC_SC_VIDEOSTREAMING              0x02
#define USB_UVC_SC_VIDEO_INTERFACE_COLLECTION  0x03

/* UVC Video Class-specific Descriptor Types, UVC spec. 1.5, section A.3 */

#define USB_UVC_PC_PROTOCOL_UNDEFINED 0x00
#define USB_UVC_PC_PROTOCOL_15        0x00

/* UVC Video Class-specific Descriptor Types, UVC spec. 1.5, section A.4 */

#define USB_UVC_CS_UNDEFINED      0x20
#define USB_UVC_CS_DEVICE         0x21
#define USB_UVC_CS_CONFIGURATION  0x22
#define USB_UVC_CS_STRING         0x23
#define USB_UVC_CS_INTERFACE      0x24
#define USB_UVC_CS_ENDPOINT       0x25

/* UVC Video Class-specific Descriptor Subtypes, UVC spec. 1.5, section A.5 */

#define UVC_VC_DESCRIPTOR_UNDEFINED  0x0
#define UVC_VC_HEADER                0x1
#define UVC_VC_INPUT_TERMINAL        0x2
#define UVC_VC_OUTPUT_TERMINAL       0x3
#define UVC_VC_SELECTOR_UNIT         0x4
#define UVC_VC_PROCESSING_UNIT       0x5
#define UVC_VC_EXTENSION_UNIT        0x6
#define UVC_VC_ENCODING_UNIT         0x7

/* Video Class-specific VS interface Descriptor Subtypes, UVC spec. 1.5, section A.6 */

#define USB_UVC_VS_UNDEFINED            0x00
#define USB_UVC_VS_INPUT_HEADER         0x01
#define USB_UVC_VS_OUTPUT_HEADER        0x02
#define USB_UVC_VS_STILL_IMAGE_FRAME    0x03
#define USB_UVC_VS_FORMAT_UNCOMPRESSED  0x04
#define USB_UVC_VS_FRAME_UNCOMPRESSED   0x05
#define USB_UVC_VS_FORMAT_MJPEG         0x06
#define USB_UVC_VS_FRAME_MJPEG          0x07

#define USB_UVC_VS_FORMAT_MPEG2TS         0x0a
#define USB_UVC_VS_FORMAT_DV              0x0c
#define USB_UVC_VS_COLOR_FORMAT           0x0d
#define USB_UVC_VS_FORMAT_FRAME_BASED     0x10
#define USB_UVC_VS_FRAME_FRAME_BASED      0x11
#define USB_UVC_VS_FORMAT_STREAM_BASED    0x12
#define USB_UVC_VS_FORMAT_H264            0x13
#define USB_UVC_VS_FRAME_H264             0x14
#define USB_UVC_VS_FORMAT_H264_SIMULCAST  0x15
#define USB_UVC_VS_FORMAT_VP8             0x16
#define USB_UVC_VS_FRAME_VP8              0x17
#define USB_UVC_VS_FORMAT_VP8_SIMULCAST   0x18

/* Video Class-specific Request Codes, UVC spec. 1.5, section A.8 */

#define UVC_RC_SETCUR       0x01
#define UVC_RC_SETCUR_ALL   0x11
#define UVC_RC_GETCUR       0x81
#define UVC_RC_GETMIN       0x82
#define UVC_RC_GETMAX       0x83
#define UVC_RC_GETRES       0x84
#define UVC_RC_GETLEN       0x85
#define UVC_RC_GETINFO      0x86
#define UVC_RC_GETDEF       0x87
#define UVC_RC_GETCUR_ALL   0x91
#define UVC_RC_GETMIN_ALL   0x92
#define UVC_RC_GETMAX_ALL   0x93
#define UVC_RC_GETRES_ALL   0x94
#define UVC_RC_GETDEF_ALL   0x95

/* VideoStreaming Interface Control Selectors, UVC spec. 1.5, section A.9.8 */

#define USB_UVC_VS_CONTROL_UNDEFINED            0x00
#define USB_UVC_VS_PROBE_CONTROL                0x01
#define USB_UVC_VS_COMMIT_CONTROL               0x02
#define USB_UVC_VS_STILL_PROBE_CONTROL          0x03
#define USB_UVC_VS_STILL_COMMIT_CONTROL         0x04
#define USB_UVC_VS_STILL_IMAGE_TRIGGER_CONTROL  0x05
#define USB_UVC_VS_STREAM_ERROR_CODE_CONTROL    0x06
#define USB_UVC_VS_GENERATE_KEY_FRAME_CONTROL   0x07
#define USB_UVC_VS_UPDATE_FRAME_SEGMENT_CONTROL 0x08
#define USB_UVC_VS_SYNCH_DELAY_CONTROL          0x09

#define USB_UVC_INTERFACE_CONTROL    0x0
#define USB_UVC_INTERFACE_STREAMING  0x1

/* UVC stream Header definitions, refer to USB_Video_Payload_H264_1.5, section 2.2 */

#define UVC_STREAM_HEADER_FID  0x01
#define UVC_STREAM_HEADER_EOF  0x02
#define UVC_STREAM_HEADER_PTS  0x04
#define UVC_STREAM_HEADER_SCR  0x08
#define UVC_STREAM_HEADER_EOS  0x10
#define UVC_STREAM_HEADER_STI  0x20
#define UVC_STREAM_HEADER_ERR  0x40
#define UVC_STREAM_HEADER_EOH  0x80

#define UVC_HEADER_MIN_LEN 0x2
#define UVC_HEADER_MAX_LEN 0xc

struct uvc_payload_header
{
  uint8_t bHeaderLength;
  uint8_t bmHeaderInfo;
} __attribute__ ((packed));

/* Video Class-specific Endpoint Descriptor Subtypes, UVC spec. 1.5, section A.7 */

#define UVC_EP_UNDEFINED  0x0
#define UVC_EP_GENERAL    0x1
#define UVC_EP_ENDPOINT   0x2
#define UVC_EP_INTERRUPT  0x3

/* Video probe and commit controls, UVC spec. 1.1, section 4.3.1.1 */

struct uvc_probe_commit_control1_1
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
  uint32_t  dwClockFrequency;
  uint8_t   bmFramingInfo;
  uint8_t   bPreferedVersion;
  uint8_t   bMinVersion;
  uint8_t   bMaxVersion;
} __attribute__ ((packed));

/* USB Video Class -- Class-specific VC Interface Header Descriptor
 * Refer to USB Video Class Specification 1.5, section 3.7.2
 */

#define DEFINE_UVC_VC_INTERFACE_HEADER_DESC(n)  \
struct uvc_vc_interface_header_desc##n          \
{                                               \
  uint8_t   bLength;                            \
  uint8_t   bDescriptorType;                    \
  uint8_t   bDescriptorSubtype;                 \
  uint16_t  bcdUVC;                             \
  uint16_t  wTotalLength;                       \
  uint32_t  dwClockFrequency;                   \
  uint8_t   bInCollection;                      \
  uint8_t   baInterfaceNr[n];                   \
} __attribute__ ((packed))

/* UVC Video Streaming interface header descriptor, UVC spec., section 3.9.2.1 */

#define DEFINE_UVC_VS_INPUT_HEADER_DESC(n, p) \
struct uvc_vs_input_header_desc_n_##p         \
{                                             \
  uint8_t   bLength;                          \
  uint8_t   bDescriptorType;                  \
  uint8_t   bDescriptorSubtype;               \
  uint8_t   bNumFormats;                      \
  uint16_t  wTotalLength;                     \
  uint8_t   bEndpointAddress;                 \
  uint8_t   bmInfo;                           \
  uint8_t   bTerminalLink;                    \
  uint8_t   bStillCaptureMethod;              \
  uint8_t   bTriggerSupport;                  \
  uint8_t   bTriggerUsage;                    \
  uint8_t   bControlSize;                     \
  uint8_t   bmControls[n][p];                 \
} __attribute__((packed))

/* This is the common structure part of stream format descriptors,
 * which is convenient for taking member variables for logical judgment
 */

struct uvc_common_format_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;
  uint8_t  bDescriptorSubtype;
  uint8_t  bFormatIndex;
  uint8_t  bNumFrameDescriptors;
} __attribute__ ((packed));

/* UVC uncompressed video format descriptor, USB Video Payload Uncompressed 1.5, section 3.1.1 */

struct uvc_uncompressed_format_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;
  uint8_t  bDescriptorSubtype;
  uint8_t  bFormatIndex;
  uint8_t  bNumFrameDescriptors;
  uint8_t  guidFormat[16];
  uint8_t  bBitsPerPixel;
  uint8_t  bDefaultFrameIndex;
  uint8_t  bAspectRatioX;
  uint8_t  bAspectRatioY;
  uint8_t  bmInterlaceFlags;
  uint8_t  bCopyProtect;
} __attribute__ ((packed));

/* MJPEG Payload - 3.1.1. MJPEG Video Format Descriptor */

struct uvc_mjpeg_format_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;
  uint8_t  bDescriptorSubtype;
  uint8_t  bFormatIndex;
  uint8_t  bNumFrameDescriptors;
  uint8_t  bmFlags;
  uint8_t  bDefaultFrameIndex;
  uint8_t  bAspectRatioX;
  uint8_t  bAspectRatioY;
  uint8_t  bmInterlaceFlags;
  uint8_t  bCopyProtect;
} __attribute__ ((packed));

/* UVC uncompressed video frame descriptor, USB Video Payload Uncompressed 1.5, section 3.1.2 */

#define DEFINE_UVC_FRAME_DESCRIPTOR(n, p) \
struct uvc_##n##_frame_descriptor##p      \
{                                         \
  uint8_t   bLength;                      \
  uint8_t   bDescriptorType;              \
  uint8_t   bDescriptorSubtype;           \
  uint8_t   bFrameIndex;                  \
  uint8_t   bmCapabilities;               \
  uint16_t  wWidth;                       \
  uint16_t  wHeight;                      \
  uint32_t  dwMinBitRate;                 \
  uint32_t  dwMaxBitRate;                 \
  uint32_t  dwMaxVideoFrameBufferSize;    \
  uint32_t  dwDefaultFrameInterval;       \
  uint8_t   bFrameIntervalType;           \
  uint32_t  dwFrameInterval[p];           \
} __attribute__((packed))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_UVC_H */