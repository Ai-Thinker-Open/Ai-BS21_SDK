/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2023. All rights reserved.
 * Description: LiteOS USB Driver UAC Protocol Private HeadFile
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

#ifndef _F_UAC_PRI_H
#define _F_UAC_PRI_H

#include <los_atomic.h>
#include "gadget/f_uac.h"
#include "gadget/usbdev.h"
#include "gadget/composite.h"
#include "implementation/_thread_ref.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(CONFIG_DRIVERS_USB_UAC_GADGET_VER_1_0) || defined(CONFIG_DRIVERS_USB_CAMERA_GADGET)
#define UAC_VER_1_0
#elif defined(CONFIG_DRIVERS_USB_UAC_GADGET_VER_2_0)
#define UAC_VER_2_0
#endif

/* For high speed and SuperSpeed, the bus interval is a microframe.
 * The length of a microframe is 125 microseconds.
 * Eight consecutive microframes constitute one high-speed or SuperSpeed frame
 */

#define UAC_FACTOR             8000

/* Interval for polling endpoint for data transfers
 * Expressed in frames or microframes depending on the
 * device operating speed (i.e., either 1 millisecond or
 * 125 μs units)
 * For high-speed isochronous endpoints, this value
 * must be in the range from 1 to 16. The bInterval value
 * is used as the exponent for a 2^(Interval -1) value
 * e.g., a bInterval of 4 means a period of 8 (2^(4-1))
 */

#ifdef UAC_VER_1_0
#define UAC_INTERVAL           4
#else
#define UAC_INTERVAL           3
#endif

#define DIV_ROUND_UP(n,d)   (((n) + (d) - 1) / (d))

#define UAC_GETRATE(ptr)           \
  ((uint32_t)((ptr)[0])          | \
  (((uint32_t)((ptr)[1])) << 8)  | \
  (((uint32_t)((ptr)[2])) << 16))

#define UAC_COMPLETE_EVENT 0x1

#define UAC_BUF_COUNT_MAX 10

enum uac_buf_state
{
  UAC_BUF_IDLE = 0,
  UAC_BUF_USE,
};

struct uac_dev_s
{
  uint8_t            *descs;  /* Pointer to the concatenated descriptors */
  uint32_t           desl;    /* Length of all descriptors */
  uint32_t           control; /* Class-specific control request value */
  struct usbdev_ep_s *out_ep; /* Control transfer endpoint */
  struct usbdev_ep_s *in_ep;  /* Audio Streaming endpoint */
  bool               out_ep_enabled;
  bool               in_ep_enabled;

  struct usbdev_req_s ctrlreq;   /* Control request */
  struct usbdev_req_s outputreq; /* Audio Control request */
  struct usbdev_req_s inputreq;  /* Audio Streaming request */
  uint32_t            dyn_fc;    /* Dynamic format change, non-zero indicates that format change occurred */

  volatile int connected;        /* Connected to USB host ? */
  uint32_t     fid;              /* Frame Identifier */

  uint8_t    *data_buf[UAC_BUF_COUNT_MAX];     /* Address to store audio data to be sent */
  uint8_t    data_buf_flag[UAC_BUF_COUNT_MAX]; /* Mark the status of each data_buf_flag. There are two statuses
                                                  in total. The one with no audio data stored is UAC_BUF_IDLE,
                                                  and the one with stored audio data is UAC_BUF_USE.*/
  uint32_t   data_buf_count; /* The count of audio data that needs to be stored */
  uint32_t   buf_use_count;  /* The count of data_buf obtained but not returned by the application layer */
  uint32_t   data_buf_len;   /* The length of audio data sent each time */
  uint32_t   data_offset;    /* The data length of the current audio data buf that has been taken away by the Host */
  uint32_t   data_buf_head;  /* The index number corresponding to the audio data buf sent to the USB controller layer */
  uint32_t   data_buf_tail;  /* The application layer obtains the index number corresponding to the UAC idle buf */
  int        p_srate;        /* Playback sample rate before switching */
  EVENT_CB_S in_complete_event;

  volatile Atomic        busy_flag;
  spinlock_t             lock;

  uint8_t                clock_id; /* The value in the bClockID field of the Clock Source Descriptor */
  EVENT_CB_S             out_event; /* Indicates that data is received */
  struct LOS_DL_LIST     out_queue; /* Caches data sent by the USB host */
  int                    out_queue_num; /* Number of cached data packets */
  bool                   out_start; /* Indicates whether the AO device starts to request data */
  int                    dir; /* Indicates the USB transmission direction */
};

struct uac_driver_s
{
  struct usbdevclass_driver_s  drvr;
  struct uac_dev_s            *dev;
};

/* Private UAC device driver instance structure */

struct uac_softc
{
  struct uac_dev_s    dev;
  struct uac_driver_s drvr;
};

/* Class-Specific AC Interface Descriptor, UAC spec. 1.0 section 4.3.2, UAC spec. 2.0 section 4.7.2. */

struct uac_ac_header_descriptor
{
  uint8_t  bLength;             /* Descriptor length */
  uint8_t  bDescriptorType;     /* Descriptor type */
  uint8_t  bDescriptorSubtype;  /* Descriptor subtype */
  uint16_t bcdADC;              /* Audio Device Class Specification Release Number in Binary-Coded Decimal */
#ifdef UAC_VER_1_0
  uint16_t wTotalLength;        /* Total number of bytes returned for the class-specific AudioControl interface descriptor */
  uint8_t  bIncollection;       /* Number of Audio Streaming and MIDI Streaming interfaces */
  uint8_t  bIfnr[2];            /* Interface number of the last Audio Streaming or MIDI Streaming */
#else
  uint8_t  bCategory;
  uint16_t wTotalLength;
  uint8_t  bmControls;
#endif
} __attribute__((packed));

/* Input Terminal Descriptor, UAC spec. 1.0 section 4.3.2.1, UAC spec. 2.0 section 4.7.2.4. */

struct uac_input_terminal_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;          /* CS_INTERFACE descriptor type */
  uint8_t  bDescriptorSubtype;       /* INPUT_TERMINAL descriptor subtype */
  uint8_t  bTerminalID;              /* Constant uniquely terminal ID */
  uint16_t wTerminalType;            /* USB Audio Terminal Types */
  uint8_t  bAssocTerminal;           /* ID of the Output Terminal associated */
#ifndef UAC_VER_1_0
  uint8_t  bCSourceID;
#endif
  uint8_t  bNrChannels;              /* Number of logical output channels */
#ifdef UAC_VER_1_0
  uint16_t bmChannelConfig;          /* Describes the spatial location of the logical channels */
#else
  uint32_t bmChannelConfig;
#endif
  uint8_t  iChannelNames;            /* Describing the name of the first logical channel */
#ifndef UAC_VER_1_0
  uint16_t bmControls;
#endif
  uint8_t  iTerminal;                /* Describing the Input Terminal */
} __attribute__ ((packed));

/* Output Terminal Descriptor, UAC spec. 1.0 section 4.3.2.2, UAC spec. 2.0 section 4.7.2.5. */

struct uac_output_terminal_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;       /* CS_INTERFACE descriptor type */
  uint8_t  bDescriptorSubtype;    /* OUTPUT_TERMINAL descriptor subtype */
  uint8_t  bTerminalID;           /* Constant uniquely terminal ID */
  uint16_t wTerminalType;         /* USB Audio Terminal Types */
  uint8_t  bAssocTerminal;        /* ID of the Input Terminal associated */
  uint8_t  bSourceID;             /* ID of the connected Unit or Terminal*/
#ifndef UAC_VER_1_0
  uint8_t  bCSourceID;
  uint16_t bmControls;
#endif
  uint8_t  iTerminal;             /* Describing the Output terminal */
} __attribute__ ((packed));

/* Class-Specific AS Interface Descriptor, UAC spec. 1.0 section 4.5.2, UAC spec. 2.0 section 4.9.2. */

struct uac_as_header_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;         /* USB_DT_CS_INTERFACE */
  uint8_t  bDescriptorSubtype;      /* AS_GENERAL */
  uint8_t  bTerminalLink;           /* Terminal ID of connected Terminal */
#ifdef UAC_VER_1_0
  uint8_t  bDelay;                  /* Delay introduced by the data path */
  uint16_t wFormatTag;              /* The Audio Data Format */
#else
  uint8_t  bmControls;
  uint8_t  bFormatType;
  uint32_t bmFormats;
  uint8_t  bNrChannels;
  uint32_t bmChannelConfig;
  uint8_t  iChannelNames;
#endif
} __attribute__((packed));

/* Audio Class-Specific AS Interface Descriptor Subtypes */

#define UAC_AS_GENERAL                     0x01
#define UAC_FORMAT_TYPE                    0x02

/* Type I Format Type Descriptor, UAC frmts. 1.0 section 2.2.5, UAC frmts. 2.0 section 2.3.1.6. */

struct uac_format_type_i_discrete_descriptor
{
  uint8_t  bLength;             /* Size of this descriptor */
  uint8_t  bDescriptorType;     /* CS_INTERFACE descriptor */
  uint8_t  bDescriptorSubtype;  /* FORMAT_TYPE subtype */
  uint8_t  bFormatType;         /* FORMAT_TYPE_I */
#ifdef UAC_VER_1_0
  uint8_t  bNrChannels;         /* One channel */
  uint8_t  bSubFrameSize;       /* Two bytes per audio subframe */
  uint8_t  bBitResolution;      /* 16 bits per sample */
  uint8_t  bSamFreqType;        /* One frequency supported */
  uint8_t  tSamFreq[4][3];      /* Sampling frequency */
#else
  uint8_t  bSubslotSize;
  uint8_t  bBitResolution;
#endif
} __attribute__ ((packed));

/* AC Interrupt Endpoint Descriptors, UAC spec. 1.0 section 4.4.2, UAC spec. 2.0 section 4.8.2. */

struct uac_endpoint_descriptor
{
  uint8_t  bLength;               /* Size of this descriptor */
  uint8_t  bDescriptorType;       /* ENDPOINT descriptor type */
  uint8_t  bEndpointAddress;      /* The address of the endpoint on the USB device */
  uint8_t  bmAttributes;          /* Transfer type */
  uint8_t  wMaxPacketSize[2];     /* Maximum packet size */
  uint8_t  bInterval;             /* Time interval */
#ifdef UAC_VER_1_0
  uint8_t  bRefresh;              /* Reset to 0 */
  uint8_t  bSynchAddress;         /* Reset to 0 */
#endif
} __attribute__((packed));

/* Class-Specific AS Isochronous Audio Data Endpoint Descriptor,
 * UAC spec. 1.0 section 4.6.1.2, UAC spec. 2.0 section 4.10.1.2.
 */

struct uac_iso_endpoint_descriptor
{
  uint8_t  bLength;
  uint8_t  bDescriptorType;    /* USB_DT_CS_ENDPOINT */
  uint8_t  bDescriptorSubtype; /* EP_GENERAL */
  uint8_t  bmAttributes;
#ifndef UAC_VER_1_0
  uint8_t  bmControls;
#endif
  uint8_t  bLockDelayUnits;
  uint16_t wLockDelay;
} __attribute__((packed));

/* Feature Unit Descriptor, UAC spec. 1.0 section 4.3.2.5, UAC spec. 2.0 section 4.7.2.8. */

struct uac_feature_unit_descriptor
{
  uint8_t  bLength;               /* Size of this descriptor */
  uint8_t  bDescriptorType;       /* CS_INTERFACE descriptor type */
  uint8_t  bDescriptorSubtype;    /* FEATURE_UNIT descriptor subtype */
  uint8_t  bUnitID;               /* Constant uniquely identifying the Unit within the audio function */
  uint8_t  bSourceID;             /* ID of the Unit or Terminal to which this Feature Unit is connected */
  uint8_t  bControlSize;          /* Size in bytes of an element of the controls array */
  uint16_t bmaControls[1];        /* variable length */
  uint8_t  iFeature;              /* describing this Feature Unit */
} __attribute__((packed));

/* Audio Class-specific Descriptor Types, UAC spec. 1.0, section A.2 */

#define UAC_SUBCLASS_UNDEFINED 0x00
#define UAC_AUDIOCONTROL       0x01
#define UAC_AUDIOSTREAMING     0x02
#define UAC_MIDISTREAMING      0x03

/* AudioStreaming Interface Control Selectors */

#define UAC_VS_CONTROL_UNDEFINED                   0x00
#define UAC_VS_PROBE_CONTROL                       0x01
#define UAC_VS_COMMIT_CONTROL                      0x02
#define UAC_VS_STILL_PROBE_CONTROL                 0x03
#define UAC_VS_STILL_COMMIT_CONTROL                0x04
#define UAC_VS_STILL_IMAGE_TRIGGER_CONTROL         0x05
#define UAC_VS_STREAM_ERROR_CODE_CONTROL           0x06
#define UAC_VS_GENERATE_KEY_FRAME_CONTROL          0x07
#define UAC_VS_UPDATE_FRAME_SEGMENT_CONTROL        0x08
#define UAC_VS_SYNCH_DELAY_CONTROL                 0x09

#define UAC_SETCUR_COMPLETE             0xfe

#define UAC2_SET_SAMPLING_RATE          0xffe

/* Audio Class-Specific AC Interface Descriptor Subtypes, UAC spec. 1.0 table A-5, UAC spec. 2.0 Table A-9. */

#define UAC_HEADER                      0x01
#define UAC_INPUT_TERMINAL              0x02
#define UAC_OUTPUT_TERMINAL             0x03
#define UAC_MIXER_UNIT                  0x04
#define UAC_SELECTOR_UNIT               0x05
#define UAC_FEATURE_UNIT                0x06
#define UAC1_PROCESSING_UNIT            0x07
#define UAC1_EXTENSION_UNIT             0x08

/* Audio Class-Specific Request Codes, UAC spec. 1.0 table A-9. */

#define SET_CUR_UAC                     0x1
#define GET_CUR_UAC                     0x81
#define SET_MIN_UAC                     0x2
#define GET_MIN_UAC                     0x82
#define SET_MAX_UAC                     0x3
#define GET_MAX_UAC                     0x83
#define SET_RES_UAC                     0x4
#define GET_RES_UAC                     0x84
#define SET_MEM_UAC                     0x5
#define GET_MEM_UAC                     0x85

/* Audio Data Format Type I Codes, UAC frmts. 1.0 table A-1, UAC frmts. 2.0 table A-5. */

#define UAC_FORMAT_TYPE_I_UNDEFINED     0x0
#define UAC_FORMAT_TYPE_I_PCM           0x1
#define UAC_FORMAT_TYPE_I_PCM8          0x2

/* Format Type Codes, UAC frmts. 1.0 table A-4, UAC frmts. 2.0 table A-1. */

#define UAC_FORMAT_TYPE_UNDEFINED       0x0
#define UAC_FORMAT_TYPE_I               0x1
#define UAC_FORMAT_TYPE_II              0x2
#define UAC_FORMAT_TYPE_III             0x3

/* Audio Class-Specific Endpoint Descriptor Subtypes, UAC spec. 1.0 table A-8, UAC frmts. 2.0 table A-13. */

#define UAC_EP_GENERAL                  0x01

/* USB Terminal Types, UAC termt. 1.0 table 2-1, UAC termt. 2.0 table 2-1. */

#define UAC_TERMINAL_UNDEFINED          0x100
#define UAC_TERMINAL_STREAMING          0x101
#define UAC_TERMINAL_VENDOR_SPEC        0x1FF

/* Input Terminal Types, UAC termt. 1.0 table 2-2, UAC termt. 2.0 table 2-2. */

#define UAC_IN_UNDEFINED                0x200
#define UAC_IN_MICROPHONE               0x201

/* Output Terminal Types, UAC termt. 1.0 table 2-3, UAC termt. 2.0 table 2-3. */

#define UAC_OUT_UNDEFINED               0x300
#define UAC_OUT_SPEAKER                 0x301
#define UAC_OUT_HEADPHONES              0x302

#define UAC_SAMPLING_RATE_8K      8000
#define UAC_SAMPLING_RATE_16K     16000
#define UAC_SAMPLING_RATE_32K     32000
#define UAC_SAMPLING_RATE_48K     48000
#define UAC_SAMPLING_RATE_96K     96000
#define UAC_SAMPLING_RATE_192K    192000
#define UAC_SAMPLING_RATE_384K    384000

#define UAC_DEF_CSRATE            UAC_SAMPLING_RATE_48K
#define UAC_DEF_PSRATE            UAC_SAMPLING_RATE_8K
#define UAC_DEF_CSSIZE            2
#define UAC_DEF_PSSIZE            2

#if defined(CONFIG_DRIVERS_USB_UAC_GADGET_VER_1_0_SPEAKER) || defined(CONFIG_DRIVERS_USB_UAC_GADGET_VER_2_0)
#define UAC_GADGET_SPEAKER        1
#else
#define UAC_GADGET_SPEAKER        0
#endif

#define IN_CLK_ID                 1
#define IN_IT_ID                  2
#define IN_OT_ID                  3

#if UAC_GADGET_SPEAKER
#define OUT_CLK_ID                5
#define OUT_IT_ID                 6
#define OUT_OT_ID                 7
#endif
#define UAC_USB_IN_IT             8
#define UAC_USB_IN_OT             9

#if UAC_GADGET_SPEAKER
#define UAC_USB_OUT_IT            10
#define UAC_USB_OUT_OT            11
#endif

#define UAC_CONFIGID              0
#define UAC_NCONFIGS              1
#define UAC_NUM_EPS               2
#define UAC_NINTERFACES           (2 + UAC_GADGET_SPEAKER)
#define UAC_NSTRIDS               10

#ifdef UAC_VER_1_0
#define UAC_VERSION               0
#define UAC_SPEC_VERSION          0x100
#define UAC_CHANNEL_NUM           1
#define UAC_DEF_PCHMASK           0x1    /* Playback support signal channel. */
#define UAC_DEF_CCHMASK           0x1
#define UAC_AC_IF_STRDESC_LEN     38
#define UAC_EP_TRANSFER_TYPE      (USB_EP_ATTR_XFER_ISOC | USB_EP_ATTR_ASYNC)
#define UAC_SET_EP_CONTROL        UAC_SETCUR_COMPLETE
#else
#define UAC_VERSION               0x20
#define UAC_SPEC_VERSION          0x200
#define UAC_CHANNEL_NUM           2
#define UAC_DEF_PCHMASK           0x3    /* Playback support dual channel. */
#define UAC_DEF_CCHMASK           0x3
#define UAC_AC_IF_STRDESC_LEN     44
#define UAC_EP_TRANSFER_TYPE      (USB_EP_ATTR_XFER_ISOC | USB_EP_ATTR_SYNC)
#define UAC_SET_EP_CONTROL        UAC2_SET_SAMPLING_RATE

#define CONTROL_RDWR              3
#endif

#define UAC_DIR_INVALID           -1

#define ISO_DATA_SIZE             256

#define STR_AC_IF                 4

#define UAC_READ_EVENT            0x22

#define HSETM(_var, _val) _var = { (uint8_t)(_val), (uint8_t)((_val) >> 0x8), (uint8_t)((_val) >> 16) }

struct uac_softc *get_uac(void);
void usbdev_uac_initialize_sub(struct composite_devdesc_s *dev, int ifnobase, int minor);
extern struct uac_endpoint_descriptor g_fuac_as_in_ep_desc;
extern size_t g_uac_iso_data_size;

extern uint32_t usb_mtx;

/* Added Structure For UAC 2.0 */

#ifndef UAC_VER_1_0

/* Clock Source Descriptor, UAC spec. 2.0 section 4.7.2.1. */

struct uac2_clock_source_descriptor
{
  uint8_t   bLength;
  uint8_t   bDescriptorType;
  uint8_t   bDescriptorSubtype;
  uint8_t   bClockID;
  uint8_t   bmAttributes;
  uint8_t   bmControls;
  uint8_t   bAssocTerminal;
  uint8_t   iClockSource;
} __attribute__((packed));

/* bmAttribute fields Clock Source */

#define UAC2_CS_TYPE_EXT           0x0
#define UAC2_CS_TYPE_INT_FIXED     0x1
#define UAC2_CS_TYPE_INT_VAR       0x2
#define UAC2_CS_TYPE_INT_PROG      0x3
#define UAC2_CS_SYNCED_TO_SOF      0x4

/* Audio Function Category Codes, UAC spec. 2.0 table A-7. */

#define UAC2_AFC_SUBCLASS_UNDEFINED     0x00
#define UAC2_AFC_DESKTOP_SPEAKER        0x01
#define UAC2_AFC_HOME_THEATER           0x02
#define UAC2_AFC_MICROPHONE             0x03
#define UAC2_AFC_HEADSET                0x04
#define UAC2_AFC_TELEPHONE              0x05
#define UAC2_AFC_CONVERTER              0x06
#define UAC2_AFC_SOUND_RECORDER         0x07
#define UAC2_AFC_IO_BOX                 0x08
#define UAC2_AFC_MUSICAL_INSTRUMENT     0x09
#define UAC2_AFC_PRO_AUDIO              0x0a
#define UAC2_AFC_AUDIO_VIDEO            0x0b
#define UAC2_AFC_CONTROL_PANEL          0x0c
#define UAC2_AFC_OTHER                  0xff

/* Audio Class-Specific AS Interface Descriptor Subtypes, UAC spec. 2.0 table A-10. */

#define UAC2_CLOCK_SOURCE               0x0a
#define UAC2_CLOCK_SELECTOR             0x0b
#define UAC2_CLOCK_MULTIPLIER           0x0c
#define UAC2_SAMPLE_RATE_CONVERTER      0x0d

/* Clock Source Control Selectors, UAC spec. 2.0 table A-17. */

#define UAC2_CS_UNDEFINED               0x00
#define UAC2_CS_CONTROL_SAM_FREQ        0x01
#define UAC2_CS_CONTROL_CLOCK_VALID     0x02

/* Audio Class-Specific Request Codes, UAC spec. 2.0 table A-14. */

#define UAC2_CS_CUR                    0x01
#define UAC2_CS_RANGE                  0x02
#define UAC2_CS_MEM                    0x03

struct ctl_range_lay3
{
  /* 4 eight-bit array elements store 32-bit data */

  uint8_t dMIN[4];
  uint8_t dMAX[4];
  uint8_t dRES[4];
} __attribute__((packed));

struct ctl_ranges_lay3
{
  uint8_t wNumSubRanges[2]; /* 2 eight-bit array elements store 16-bit data */
  struct ctl_range_lay3 range[UAC2_MAX_RATES];
} __attribute__((packed));
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _F_UAC_PRI_H */
