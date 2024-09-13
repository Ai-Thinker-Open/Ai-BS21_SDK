/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: LiteOS USB Driver UAC Protocol HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2017-12-12
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

#ifndef _USB_UAC_INCLUDE_H
#define _USB_UAC_INCLUDE_H

#include <los_typedef.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(CONFIG_DRIVERS_USB_UAC_GADGET_VER_2_0)

#define UAC2_MAX_RATES  6
struct uac2_opts
{
  int c_chmask;                 /* Capture channel mask. */
  int c_srate[UAC2_MAX_RATES];  /* Capture sample rate */
  int c_ssize;                  /* Capture default sample size. */
  uint32_t c_srate_curr;        /* Selected capture sample rate */
  int p_chmask;                 /* Playback channel mask. */
  int p_srate[UAC2_MAX_RATES];  /* Playback sample rate. */
  int p_ssize;                  /* Playback default sample size. */
  uint32_t p_srate_curr;        /* Selected playback sample rate */
};
int fuac2_set_opts(const struct uac2_opts *opts);
int fuac2_get_opts(struct uac2_opts *opts);
#else
struct uac_opts
{
  int c_chmask; /* Capture channel mask. */
  int c_srate;  /* Capture default sample rate. */
  int c_ssize;  /* Capture default sample size. */
  int p_chmask; /* Playback channel mask. */
  int p_srate;  /* Playback default sample rate. */
  int p_ssize;  /* Playback default sample size. */
};

int fuac_opts_set(const struct uac_opts *opts);
uint32_t fuac_rate_get(void);
int fuac_get_opts(struct uac_opts *opts);
#endif

#if defined (CONFIG_DRIVERS_USB_UAC_GADGET_VER_2_0) || defined (CONFIG_DRIVERS_USB_UAC_GADGET_VER_1_0_SPEAKER)
int fuac_receive_message(void *buf, int len, int timeout);
#endif

/* UAC function error codes */

#define UAC_OK                   0x00     /* No error, function has successfully completed */
#define UAC_ERROR_NOMATCH        0x01     /* The operation can not be complete, due to mismatch of UAC state */
#define UAC_ERROR_PTR            0x02     /* Invalid pointer */
#define UAC_ERROR_MEMORY         0x03     /* Memory error */
#define UAC_ERROR_VALUE          0x04     /* Incorrect value */
#define UAC_ERROR_FATAL          0x05     /* Fatal internal error, please contact the one who wrote the code */
#define UAC_ERROR_EVENT          0x06     /* Event read or write error */
#define UAC_ERROR_TIMEOUT        0x07     /* Event read timeout */
#define UAC_ERROR_DISCONNECT     0x08     /* USB disconnect */

#define UAC_WAIT_HOST_NOP      0x0
#define UAC_WAIT_HOST_FOREVER  0x1

int fuac_reqbuf_init(uint32_t buf_count, uint32_t data_len);
int fuac_reqbuf_deinit(void);
uint8_t *fuac_reqbuf_get(uint32_t *buf_index);
int fuac_send_message(const uint8_t *buf, uint32_t len, uint32_t buf_index);

int uac_wait_host(int wait_option);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _USB_UAC_INCLUDE_H */