/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2019. All rights reserved.
 * Description: Ld CommLib
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

#ifndef _LOS_LD_COMMLIB_PRI_H
#define _LOS_LD_COMMLIB_PRI_H

#include "los_ld_type_pri.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern BOOL LD_IsModuleTaken(const CHAR *elfFileName, DynModuleInfo **moduleHandle);
extern CHAR *LD_FilePathGet(const CHAR *path);
extern BOOL LD_ElfSymIsVisible(const LD_ELF_SYM *symbol);
extern INT8 LD_ElfSymTypeGet(const LD_ELF_SYM *symbol, const LD_ELF_SHDR *scnHdrTbl);
extern VOID LD_FlushICache(VOID);
extern VOID LD_FlushDCache(UINTPTR start, UINTPTR end);
extern BOOL LD_IsHandleLegal(const VOID *handle);
extern VOID OsPathDelete(VOID);
extern UINT32 LD_ElfHdrVerify(const LD_ELF_EHDR *ehdr);

extern INT32 LD_DlRelocAll(const RelocFunc relocFunc);
extern INT32 LD_DlDoRead(const SrcInfo *srcInfo, DestInfo *destInfo);
extern INT32 LD_DlLoadAll(const SrcInfo *srcInfo, DynModuleInfo * const moduleHandle,
                          const LoadFunc loadFunc, BOOL useHash);
extern INT32 LD_DlLoadEnqueue(DynModuleInfo * const moduleHandle);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LOS_LD_COMMLIB_PRI_H */
