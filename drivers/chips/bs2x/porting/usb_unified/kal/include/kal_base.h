/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2024-2024. All rights reserved.
 * Description: Usb Kal Adapt Macro Definition
 * Author: Huawei LiteOS Team
 * Create: 2024-02-27
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

#ifndef _USB_KAL_BASE_H
#define _USB_KAL_BASE_H

#include "chip_io.h"
#include "stdint.h"
#include "arch_barrier.h"
#include "securec.h"
#include "errno.h"
#include "debug_print.h"
#include "irmalloc.h"

/* Adapt print function */
#define DEBUGASSERT(f)
#define KAL_Printf(fmt...)   PRINT(fmt)

/* Basic definitions */

#define KAL_WRITE32_MB(value, addr)   { \
    dsb(); \
    writel(addr, value); \
}
#define KAL_READ32_MB(addr)           { \
    uint32_t r = readl((addr)); \
    dsb(); \
    r; \
}

#define container_of(item, type, member) \
    ((type *)(void *)((char *)(item) - ((uintptr_t)&((type *)0)->member)))

#ifndef LOS_OK
#define LOS_OK   (0)
#endif

#ifndef LOS_NOK
#define LOS_NOK  (1)
#endif

#define KAL_OK   LOS_OK
#define KAL_NOK  LOS_NOK

#ifndef NULL
#define NULL     ((void *)0)
#endif

#define ALIGN(addr, boundary) (((addr) + (boundary) - 1) & ~((uintptr_t)((boundary) - 1)))

#endif /* _USB_KAL_ADAPT_H */