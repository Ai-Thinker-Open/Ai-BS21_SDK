/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: LiteOS global variables adapt
 * Author: Huawei LiteOS Team
 * Create: 2023-08-10
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

#ifndef _GLOBAL_VAR_ADAPT_H
#define _GLOBAL_VAR_ADAPT_H

#include "los_typedef.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef LOSCFG_BOX
STATIC INLINE UINTPTR OsGlobalVarAddrGet(VOID *addr, UINT32 boxId)
{
    UINTPTR *commonBaseAddr = (UINTPTR *)(UINTPTR)addr;
    if (boxId >= LOSCFG_BASE_BOX_MAX_LIMIT) {
        return 0;
    }
    return commonBaseAddr[boxId];
}

#define PERBOX_STR(x)   #x
#define PERBOX_VAR_DEFINED(baseName, boxId, type, size, initVal)             \
    type baseName##boxId[size] = {[0 ... (size) - 1] = initVal};             \
    asm(".global " PERBOX_STR(baseName##boxId##Alias));                      \
    asm(PERBOX_STR(baseName##boxId##Alias) " = " PERBOX_STR(baseName##boxId))

#define PERBOX_VAR_DECLARED(baseName, boxId) extern CHAR baseName##boxId##Alias[]

#else
STATIC INLINE UINTPTR OsGlobalVarAddrGet(VOID *addr, UINT32 boxId)
{
    (VOID)boxId;
    return (UINTPTR)addr;
}
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _GLOBAL_VAR_ADAPT_H */
