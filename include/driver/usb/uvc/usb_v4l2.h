/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2022-2022. All rights reserved.
 * Description: Video For Linux Two HeadFile
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

#ifndef _USB_V4L2_H
#define _USB_V4L2_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define V4L2_CAP_VIDEO_CAPTURE      0x00000001
#define V4L2_CAP_READWRITE          0x01000000
#define V4L2_CAP_ASYNCIO            0x02000000
#define V4L2_CAP_STREAMING          0x04000000
#define V4L2_MODE_HIGHQUALITY       0x0001
#define V4L2_CAP_TIMEPERFRAME       0x1000
#define V4L2_FMT_FLAG_UNCOMPRESSED  0
#define V4L2_FMT_FLAG_COMPRESSED    1
#define V4L2_FMT_FLAG_EMULATED      2
#define FRAME_INTERVAL_DENOMINATOR  10000000
#define V4L2_FRMSIZE_TYPE_DISCRETE  1
#define V4L2_FRMIVAL_TYPE_DISCRETE  1
#define V4L2_FRMIVAL_TYPE_STEPWISE  3

#define V4L2_BUF_FLAG_MAPPED        0x00000001
#define V4L2_BUF_FLAG_QUEUED        0x00000002
#define V4L2_BUF_FLAG_DONE          0x00000004

#define VIDIOC_QUERYCAP             _IOR('V', 0, struct v4l2_capability)
#define VIDIOC_ENUM_FMT             _IOWR('V', 2, struct v4l2_fmtdesc)

#define VIDIOC_G_FMT                _IOWR('V', 4, struct v4l2_format)
#define VIDIOC_S_FMT                _IOWR('V', 5, struct v4l2_format)

#define VIDIOC_G_PARM               _IOWR('V', 21, struct v4l2_streamparm)
#define VIDIOC_S_PARM               _IOWR('V', 22, struct v4l2_streamparm)
#define VIDIOC_TRY_FMT              _IOWR('V', 64, struct v4l2_streamparm)

#define VIDIOC_ENUM_FRAMESIZES      _IOWR('V', 74, struct v4l2_frmsizeenum)
#define VIDIOC_ENUM_FRAMEINTERVALS  _IOWR('V', 75, struct v4l2_frmivalenum)

#define VIDIOC_REQBUFS              _IOWR('V', 8, struct v4l2_requestbuffers)
#define VIDIOC_QUERYBUF             _IOWR('V', 9, struct v4l2_buffer)
#define VIDIOC_QBUF                 _IOWR('V', 15, struct v4l2_buffer)
#define VIDIOC_DQBUF                _IOWR('V', 17, struct v4l2_buffer)
#define VIDIOC_STREAMON             _IOW('V', 18, int)
#define VIDIOC_STREAMOFF            _IOW('V', 19, int)

enum v4l2_field
{
  V4L2_FIELD_ANY = 0,
  V4L2_FIELD_NONE,
  V4L2_FIELD_TOP,
  V4L2_FIELD_BOTTOM,
  V4L2_FIELD_INTERLACED,
  V4L2_FIELD_SEQ_TB,
  V4L2_FIELD_SEQ_BT,
  V4L2_FIELD_ALTERNATE,
  V4L2_FIELD_INTERLACED_TB,
  V4L2_FIELD_INTERLACED_BT,
};

enum v4l2_buf_type
{
  V4L2_BUF_TYPE_VIDEO_CAPTURE = 1,
  V4L2_BUF_TYPE_VIDEO_OUTPUT,
  V4L2_BUF_TYPE_VIDEO_OVERLAY,
  V4L2_BUF_TYPE_VBI_CAPTURE,
  V4L2_BUF_TYPE_VBI_OUTPUT,
  V4L2_BUF_TYPE_SLICED_VBI_CAPTURE,
  V4L2_BUF_TYPE_SLICED_VBI_OUTPUT,
  V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY,
  V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE,
  V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE,
  V4L2_BUF_TYPE_SDR_CAPTURE,
  V4L2_BUF_TYPE_SDR_OUTPUT,
};

struct v4l2_capability
{
  uint8_t driver[16];
  uint8_t card[32];
  uint8_t bus_info[32];
  uint32_t version;
  uint32_t capabilities;
  uint32_t device_caps;
  uint32_t reserved[3];
};

struct v4l2_fmtdesc
{
  uint32_t index;
  uint32_t type;
  uint32_t flags;
  uint8_t description[32];
  uint32_t pixelformat;
  uint32_t reserved[4];
};

struct v4l2_frmsize_discrete
{
  uint32_t width;
  uint32_t height;
};

struct v4l2_frmsize_stepwise
{
  uint32_t min_width;
  uint32_t max_width;
  uint32_t step_width;
  uint32_t min_height;
  uint32_t max_height;
  uint32_t step_height;
};

struct v4l2_frmsizeenum
{
  uint32_t index;
  uint32_t pixel_format;
  uint32_t type;
  union
  {
    struct v4l2_frmsize_discrete discrete;
    struct v4l2_frmsize_stepwise stepwise;
  };
  uint32_t reserved[2];
};

struct v4l2_fract
{
  uint32_t numerator;
  uint32_t denominator;
};

struct v4l2_frmival_stepwise
{
  struct v4l2_fract min;
  struct v4l2_fract max;
  struct v4l2_fract step;
};

struct v4l2_frmivalenum
{
  uint32_t index;
  uint32_t pixel_format;
  uint32_t width;
  uint32_t height;
  uint32_t type;
  union
  {
    struct v4l2_fract discrete;
    struct v4l2_frmival_stepwise stepwise;
  };
  uint32_t reserved[2];
};

struct v4l2_pix_format
{
  uint32_t width;
  uint32_t height;
  uint32_t pixelformat;
  uint32_t field;
  uint32_t bytesperline;
  uint32_t sizeimage;
  uint32_t colorspace;
  uint32_t priv;
  uint32_t flags;
  union
  {
    uint32_t ycbcr_enc;
    uint32_t hsv_enc;
  };
  uint32_t quantization;
  uint32_t xfer_func;
};

struct v4l2_plane_pix_format
{
  uint32_t sizeimage;
  uint32_t bytesperline;
  uint16_t reserved[6];
} __attribute__((packed));

struct v4l2_pix_format_mplane
{
  uint32_t width;
  uint32_t height;
  uint32_t pixelformat;
  uint32_t field;
  uint32_t colorspace;
#define VIDEO_MAX_PLANES 8
  struct v4l2_plane_pix_format plane_fmt[VIDEO_MAX_PLANES];
  uint8_t num_planes;
  uint8_t flags;
  union
  {
    uint8_t ycbcr_enc;
    uint8_t hsv_enc;
  };
  uint8_t quantization;
  uint8_t xfer_func;
  uint8_t reserved[7];
} __attribute__((packed));

struct v4l2_rect
{
  int32_t left;
  int32_t top;
  uint32_t width;
  uint32_t height;
};

struct v4l2_clip
{
  struct v4l2_rect c;
  struct v4l2_clip *next;
};

struct v4l2_window
{
  struct v4l2_rect w;
  uint32_t field;
  uint32_t chromakey;
  struct v4l2_clip *clips;
  uint32_t clipcount;
  void *bitmap;
  uint8_t global_alpha;
};

struct v4l2_vbi_format
{
  uint32_t sampling_rate;
  uint32_t offset;
  uint32_t samples_per_line;
  uint32_t sample_format;
  int32_t start[2];
  uint32_t count[2];
  uint32_t flags;
  uint32_t reserved[2];
};

struct v4l2_sliced_vbi_format
{
  uint16_t service_set;
  uint16_t service_lines[2][24];
  uint32_t io_size;
  uint32_t reserved[2];
};

struct v4l2_sdr_format
{
  uint32_t pixelformat;
  uint32_t buffersize;
  uint8_t reserved[24];
} __attribute__((packed));

struct v4l2_format
{
  uint32_t type;
  union
  {
    struct v4l2_pix_format pix;
    struct v4l2_pix_format_mplane pix_mp;
    struct v4l2_window win;
    struct v4l2_vbi_format vbi;
    struct v4l2_sliced_vbi_format sliced;
    struct v4l2_sdr_format sdr;
    uint8_t raw_data[200];
  } fmt;
};

struct v4l2_captureparm
{
  uint32_t capability;
  uint32_t capturemode;
  struct v4l2_fract timeperframe;
  uint32_t extendedmode;
  uint32_t readbuffers;
  uint32_t reserved[4];
};

struct v4l2_outputparm
{
  uint32_t capability;
  uint32_t outputmode;
  struct v4l2_fract timeperframe;
  uint32_t extendedmode;
  uint32_t writebuffers;
  uint32_t reserved[4];
};

struct v4l2_streamparm
{
  uint32_t type;
  union
  {
    struct v4l2_captureparm capture;
    struct v4l2_outputparm output;
    uint8_t raw_data[200];
  } parm;
};

enum v4l2_memory {
  V4L2_MEMORY_MMAP    = 1,
  V4L2_MEMORY_USERPTR = 2,
  V4L2_MEMORY_OVERLAY = 3,
  V4L2_MEMORY_DMABUF  = 4,
};

struct v4l2_requestbuffers
{
  uint32_t count;
  uint32_t type;
  uint32_t memory;
  uint32_t reserved[2];
};

struct v4l2_timecode
{
  uint32_t type;
  uint32_t flags;
  uint8_t frames;
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
  uint8_t userbits[4];
};

struct v4l2_plane
{
  uint32_t bytesused;
  uint32_t length;
  union
  {
    uint32_t mem_offset;
    unsigned long userptr;
    int fd;
  } m;
  uint32_t data_offset;
  uint32_t reserved[11];
};

struct v4l2_buffer
{
  uint32_t index;
  uint32_t type;
  uint32_t bytesused;
  uint32_t flags;
  uint32_t field;
  struct timeval timestamp;
  struct v4l2_timecode timecode;
  uint32_t sequence;
  uint32_t memory;
  union
  {
    uint32_t offset;
    unsigned long userptr;
    struct v4l2_plane *planes;
    int fd;
  } m;
  uint32_t length;
  uint32_t reserved2;
  uint32_t reserved;
};

uint8_t *uvc_get_frame_buf(struct file *filep, uint32_t index, uint32_t offset);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_V4L2_H */