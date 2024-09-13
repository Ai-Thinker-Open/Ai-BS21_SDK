/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: LiteOS USB Driver KalAtomic HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2024-02-26
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

#ifndef KAL_ATOMIC_H
#define KAL_ATOMIC_H

#include "stdint.h"
#include "stdbool.h"
#include "osal_interrupt.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef volatile int32_t   KalAtomic;

static inline int KAL_AtomicRead(const KalAtomic *v)
{
    return *(volatile int32_t *)v;
}

static inline void KAL_AtomicSet(KalAtomic *v, int setVal)
{
    *(volatile int32_t *)v = setVal;
}

static inline void KAL_AtomicInc(KalAtomic *v)
{
    int32_t flag = osal_irq_lock();
    *v += 1;
    osal_irq_restore(flag);
}

static inline void KAL_AtomicDec(KalAtomic *v)
{
    int32_t flag = osal_irq_lock();
    *v -= 1;
    osal_irq_restore(flag);
}

static inline bool KAL_AtomicCmpXchg32(KalAtomic *v, int val, int oldVal)
{
    int32_t flag = osal_irq_lock();
    int32_t prevVal = *v;
    if (prevVal == oldVal) {
        *v = val;
    }
    osal_irq_restore(flag);
    return (prevVal != oldVal);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* KAL_ATOMIC_H */