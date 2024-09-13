/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: LiteOS USB Driver KalSpinLock HeadFile
 * Author: Huawei LiteOS Team
 * Create: 2024-02-23
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

#ifndef KAL_SPINLOCK_H
#define KAL_SPINLOCK_H

#include "osal_interrupt.h"
#include "common_def.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define KAL_SPIN_LOCK_INIT(lock) int32_t lock

typedef struct {
    volatile uintptr_t v;
} KalSpinLock;

static inline uint32_t KAL_SpinInit(KalSpinLock *spinLock)
{
    unused(spinLock);
    return 0;
}

static inline void KAL_SpinLock(KalSpinLock *spinLock)
{
    unused(spinLock);
    osal_irq_lock();
}


static inline void KAL_SpinUnlock(KalSpinLock *spinLock)
{
    unused(spinLock);
    osal_irq_unlock();
}

static inline void KAL_SpinLockSave(KalSpinLock *spinLock, uint32_t *intSave)
{
    unused(spinLock);
    *intSave = osal_irq_lock();
}

static inline void KAL_SpinUnlockRestore(KalSpinLock *spinLock, uint32_t intSave)
{
    unused(spinLock);
    osal_irq_restore(intSave);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* KAL_SPINLOCK_H */