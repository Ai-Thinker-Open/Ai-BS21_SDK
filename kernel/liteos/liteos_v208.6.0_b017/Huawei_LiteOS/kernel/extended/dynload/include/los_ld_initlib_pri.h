/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2019. All rights reserved.
 * Description: Ld InitLib
 * Author: Huawei LiteOS Team
 * Create: 2013-01-01
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

#ifndef _LOS_LD_INITLIB_PRI_H
#define _LOS_LD_INITLIB_PRI_H

#include "los_ld_type_pri.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern LDSymbol g_dynloadGlobalSymbolBegin;
extern LDSymbol g_dynloadGlobalSymbolEnd;
extern DynModuleInfo g_sysModuleInfo[N_MAX_MODULES];

extern LOS_DL_LIST g_dlLoadQueue;
extern LOS_DL_LIST g_dlRelocQueue;

extern UINT32 g_dlLoadQueueLocker;
extern UINT32 g_dlRelocQueueLocker;

extern BOOL LD_IsLoaderInit(VOID);
extern VOID LD_InitHandler(DynModuleInfo *moduleHandle);
extern INT32 LD_Init(VOID);
extern UINT32 LD_LoadLock(VOID);
extern VOID LD_LoadUnlock(VOID);
extern UINT32 LD_LoadLockerInit(VOID);
extern UINT32 OsDynloadInit(VOID);
extern VOID LD_DlLoadQueueInit(VOID);
extern VOID LD_DlRelocQueueInit(VOID);
extern UINT32 LD_DlLoadQueueLockerInit(VOID);
extern VOID LD_DlLoadQueueLockerDel(VOID);
extern UINT32 LD_DlRelocQueueLockerInit(VOID);
extern VOID LD_DlRelocQueueLockerDel(VOID);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LOS_LD_INITLIB_PRI_H */
