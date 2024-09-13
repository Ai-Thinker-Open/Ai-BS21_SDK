/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: LiteOS compat headfile for nuttx mutex
 * Author: Huawei LiteOS Team
 * Create: 2023-07-15
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

#ifndef __INCLUDE_NUTTX_MUTEX_H
#define __INCLUDE_NUTTX_MUTEX_H

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Type Definitions
 ****************************************************************************/

struct rmutex_s {
    uint32_t mux;
    pid_t    holder;
    uint32_t count;
};

typedef struct rmutex_s mutex_t;
typedef struct rmutex_s rmutex_t;

/* Compatible with the NuttX internal OS interface:
 * It follows the NuttX internal error return policy: Zero (OK) is
 * returned on success. A negated errno value is returned on failure.
 */

int nxrmutex_init(rmutex_t *rmutex);
int nxrmutex_lock(rmutex_t *rmutex);
int nxrmutex_unlock(rmutex_t *rmutex);
int nxrmutex_destroy(rmutex_t *rmutex);

#define nxmutex_init nxrmutex_init
#define nxmutex_lock nxrmutex_lock
#define nxmutex_unlock nxrmutex_unlock
#define nxmutex_destroy nxrmutex_destroy

/* LiteOS does not support static mutex.
 * Therefore, this parameter needs to be set to null.
 */

#define NXMUTEX_INITIALIZER {}
#define NXRMUTEX_INITIALIZER {}

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __INCLUDE_NUTTX_MUTEX_H */