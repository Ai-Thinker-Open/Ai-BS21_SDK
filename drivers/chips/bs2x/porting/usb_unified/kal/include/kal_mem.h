/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: LiteOS USB Driver KalMem HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2024-02-07
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

#ifndef KAL_MEM_H
#define KAL_MEM_H

#include "securec.h"
#include "common_def.h"
#include "irmalloc.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define zalloc irzalloc
#define malloc irmalloc
#define free irfree

#define memalign(boundary, size) irmalloc(size)

static inline uint32_t KAL_MemInit(void *pool, uint32_t size)
{
    unused(pool);
    unused(size);
    return 0;
}

static inline uint32_t KAL_MemDeInit(void *pool)
{
    unused(pool);
    return 0;
}

static inline void *KAL_MemAllocAlign(void *pool, uint32_t size, uint32_t boundary)
{
    unused(pool);
    unused(boundary);
    return irmalloc(size);
}

static inline uint32_t KAL_MemFree(void *pool, void *ptr)
{
    unused(pool);
    irfree(ptr);
    return 0;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* KAL_MEM_H */