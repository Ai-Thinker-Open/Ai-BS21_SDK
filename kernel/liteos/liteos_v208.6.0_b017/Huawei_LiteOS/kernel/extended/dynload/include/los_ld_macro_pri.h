/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2019. All rights reserved.
 * Description: Ld Macro
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

#ifndef _LOS_LD_MACRO_PRI_H
#define _LOS_LD_MACRO_PRI_H

#include "los_ld_type_pri.h"
#include "los_ld_initlib_pri.h"

#include "stdarg.h"
#include "los_config.h"

#if defined(LOSCFG_ARCH_CORTEX_A7) || defined(LOSCFG_ARCH_CORTEX_A53_AARCH32)
#include "arch/mmu.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define GET_MODULE_BY_ID(moduleId) ((DynModuleInfo *)&g_sysModuleInfo[(moduleId)])

/* Macro to check if the alignment is a power of 2 */
#define LD_CHECK_2_ALIGN(x) (((x) & ((x) - 1)) == 0)

/* New load flags */
#define LD_NO_SYMBOLS     0x1U /* No symbols added to the target symbol table */
#define LD_LOCAL_SYMBOLS  0x2U /* Only internal symbols added to the target symbol table */
#define LD_GLOBAL_SYMBOLS 0x4U /* Only external symbols added to the target symbol table */
#define LD_ALL_SYMBOLS    (LD_LOCAL_SYMBOLS | LD_GLOBAL_SYMBOLS) /* All symbols added to the target symbol table */

/* Symbol types */
#define LD_SYM_UNDF       0x0U /* Undefined */
#define LD_SYM_LOCAL      0x0U /* Local */
#define LD_SYM_GLOBAL     0x1U /* Global (external) (ORed) */
#define LD_SYM_ABS        0x2U /* Absolute */
#define LD_SYM_TEXT       0x4U /* Text */
#define LD_SYM_DATA       0x6U /* Data */
#define LD_SYM_BSS        0x8U /* Bss */
#define LD_SYM_COMM       0x10U /* Common symbol */

#define LD_SYM_BAL_ENTRY  0x20 /* I80960 BAL entry point to function */
#define LD_SYM_SDA        0x40 /* Symbols related to a PowerPC SDA section */
#define LD_SYM_SDA2       0x80 /* Symbols related to a PowerPC SDA2 section */

#define LD_SYM_THUMB      0x40 /* Thumb function - unlikely clash with SYM_SDA */

#define LD_SYM_MIPS16     0x80 /* Mips16 function - unlikely clash with SYM_SDA2, arch. specific */

#define LD_SeekAddr(fd, offset) ((fd) + (offset))

#ifndef _ALLOC_ALIGN_SIZE
#define _ALLOC_ALIGN_SIZE 4 /* 4 byte boundary */
#endif

#if defined(LOSCFG_ARCH_CORTEX_A7) || defined(LOSCFG_ARCH_CORTEX_A53_AARCH32)
#define DYN_NX_PROTECT(vaddr, memSize, flags) do {                                 \
    MMU_PARAM para;                                                                \
    para.startAddr = (UINTPTR)vaddr & ~(MMU_4K - 1);                               \
    para.endAddr = ((((UINTPTR)vaddr + memSize) + MMU_4K - 1) & ~(MMU_4K - 1));    \
    para.uwFlag = BUFFER_ENABLE | CACHE_ENABLE;                                    \
    if ((flags & PF_X) == 0) {                                                     \
        para.uwFlag |= EXEC_DISABLE;                                               \
    }                                                                              \
    if ((flags & PF_W) != 0) {                                                     \
        para.uwFlag |= ACCESS_PERM_RW_RW;                                          \
    } else {                                                                       \
        para.uwFlag |= ACCESS_PERM_RO_RO;                                          \
    }                                                                              \
    para.stPage = (SENCOND_PAGE *)&g_mmuDlPage;                                    \
    ArchMMUParamSet(&para);                                                        \
} while (0)

#define DYN_NX_UNPROTECT(vaddr, memSize) do {                                      \
    MMU_PARAM para;                                                                \
    para.startAddr = vaddr;                                                        \
    para.endAddr = ((((UINTPTR)vaddr + memSize) + MMU_4K - 1) & ~(MMU_4K - 1));    \
    para.uwFlag = BUFFER_ENABLE | CACHE_ENABLE | EXEC_DISABLE | ACCESS_PERM_RW_RW; \
    para.stPage = (SENCOND_PAGE *)&g_mmuDlPage;                                    \
    ArchMMUParamSet(&para);                                                        \
} while (0)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LOS_LD_MACRO_PRI_H */
