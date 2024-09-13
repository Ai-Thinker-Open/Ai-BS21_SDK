/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2019. All rights reserved.
 * Description: Ld Type
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

/**
 * @defgroup dynload dynamic loading
 * @ingroup kernel
 */

#ifndef _LOS_LD_TYPE_PRI_H
#define _LOS_LD_TYPE_PRI_H

#include "los_base.h"
#include "los_ld_elf_pri.h"
#include "los_elf_symbol_pri.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Maximum number of modules that are allowed to be loaded by OS. */
#define N_MAX_USER_MODULES                  LOSCFG_KERNEL_DYNLOAD_MODULE_NUM

#define N_MAX_MODULES                       (N_MAX_USER_MODULES + 1)

/* Maximum number of default paths */
#define N_DEFAULT_PATH                      10

extern LOS_DL_LIST g_freeHandleList;
extern VOID *g_dynloadHeap;

/* Symbol types */
#define ELF_STT_NOTYPE                      0x0 /* Unknown type */
#define ELF_STT_OBJECT                      0x1 /* Data object */
#define ELF_STT_FUNC                        0x2 /* Function */
#define ELF_STT_SECTION                     0x3 /* Section */
#define ELF_STT_FILE                        0x4 /* File name */

/* Symbol binding information */
#define ELF_STB_LOCAL                       0x0 /* Local */
#define ELF_STB_GLOBAL                      0x1 /* Global */
#define ELF_STB_WEAK                        0x2 /* Weak reference */

/* Information about the section in which a symbol is located. The following are constants. */
#define ELF_SHN_ABS                         0xFFF1 /* Absolute symbol value, for example, a file name. */
#define ELF_SHN_COMMON                      0xFFF2 /* COMMON block */
#define ELF_SHN_UNDEF                       0x0000 /* Undefined symbol */

/* Symbol types */
#define OS_SHN_UNDF                         0x0 /* Undefined */
#define OS_SHN_LOCAL                        0x0 /* Local */
#define OS_SHN_GLOBAL                       0x1 /* Global (external) (ORed) */
#define OS_SHN_ABS                          0x2 /* Absolute */
#define OS_SHN_TEXT                         0x4 /* Text */
#define OS_SHN_DATA                         0x6 /* Data */
#define OS_SHN_BSS                          0x8 /* BSS */
#define OS_SHN_COMM                         0x10 /* Common symbol */
#define OS_SHN_THUMB                        0x80 /* Thumb function */

/* New load flags */
#define OS_NO_SYMBOLS                       0x1 /* No symbols added to the target symbol table */

#define OS_LOCAL_SYMBOLS                    0x2 /* Only internal symbols added to the target symbol table */

#define OS_GLOBAL_SYMBOLS                   0x4 /* Only external symbols added to the target symbol table */

/* All symbols added to the target symbol table */
#define OS_ALL_SYMBOLS                      (OS_LOCAL_SYMBOLS | OS_GLOBAL_SYMBOLS)

#define ELF_BIND_LOCAL                      0
#define ELF_BIND_GLOBAL                     1
#define ELF_BIND_WEAK                       2
#define ELF_BIND_LOPROC                     13
#define ELF_BIND_HIPROC                     15

#define ELF_TYPE_NOTYPE                     0
#define ELF_TYPE_OBJECT                     1
#define ELF_TYPE_FUNC                       2
#define ELF_TYPE_SECTION                    3
#define ELF_TYPE_FILE                       4
#define ELF_TYPE_LOPROC                     13
#define ELF_TYPE_HIPROC                     15

#define MAX_SEARCH_SCOPE                    50

/* 0~15 bits maintain the module temporary flags during loadding, unloadding and searching. */
#define IS_LOADDING(handle) ((handle)->moduleStatus & (1U << 0))
#define IS_UNLOADDING(handle) ((handle)->moduleStatus & (1U << 1))
#define IS_SEARCHING(handle) ((handle)->moduleStatus & (1U << 2))
#define SET_LOADDING(handle) ((handle)->moduleStatus |= 1U << 0)
#define SET_UNLOADDING(handle) ((handle)->moduleStatus |= 1U << 1)
#define SET_SEARCHING(handle) ((handle)->moduleStatus |= 1U << 2)
#define CLEAR_SEARCHING(handle) ((handle)->moduleStatus &= ~(1U << 2))
#define CLEAR_TMPFLAGS(handle) ((handle)->moduleStatus &= 0xffff0000U)
/* 16~31 bits maintain the module status after load. */
#define IS_LOADED(handle) ((handle)->moduleStatus & (1U << 16))
#define IS_TAKEN(handle) ((handle)->moduleStatus & (1U << 17))
#define SET_LOADED(handle) ((handle)->moduleStatus |= 1U << 16)
#define SET_TAKEN(handle) ((handle)->moduleStatus |= 1U << 17)
#define CLEAR_LOADED(handle) ((handle)->moduleStatus &= ~(1U << 16))
#define CLEAR_TAKEN(handle) ((handle)->moduleStatus &= ~(1U << 17))
#define CLEAR_MODULESTATUS(handle) ((handle)->moduleStatus = 0)

#define INC_SOHEAD(handle) ((handle)->headCnt++)
#define DEC_SOHEAD(handle) ((handle)->headCnt--)
#define IS_SOHEAD(handle) ((handle)->headCnt > 0)

/* The values of n bits of a binary number are 1 */
#define OS_MASK(n) (((UINTPTR)1 << (n)) - 1)

/* The value of bit n of a binary number is 1 */
#define OS_SIGN_BIT_MASK(n) ((UINTPTR)1 << ((n) - 1))

/* Add an extended bit to the upper bit */
#define OS_SIGN_EXTEND(val, nBits) \
    (((OS_MASK((nBits)) & ((UINTPTR)(val))) ^ OS_SIGN_BIT_MASK((nBits))) - OS_SIGN_BIT_MASK((nBits)))

#define OS_SIGN_SHRINK(val, nBits) (OS_MASK(nBits) & (val))

/* Check whether the extended bit value falls within the nBits range */
#define OS_CHECK_FITS_BIT_MASK(bits)  (~(((UINTPTR)1 << ((bits) - 1)) - 1))
#define OS_CHECK_FITS(val, bits)                                   \
    (((((UINTPTR)(val)) & OS_CHECK_FITS_BIT_MASK(bits)) == 0) ||   \
     ((((UINTPTR)(val)) & OS_CHECK_FITS_BIT_MASK(bits)) == OS_CHECK_FITS_BIT_MASK(bits)))

#define OS_MEM_READ_32(relocAddr, offset) ((offset) = *((UINT32 *)(relocAddr)))
#define OS_MEM_READ_16(relocAddr, offset) ((offset) = *((UINT16 *)(relocAddr)))
#define OS_MEM_READ_8(relocAddr, offset) ((offset) = *((UINT8 *)(relocAddr)))

#define OS_MEM_WRITE_32(relocAddr, value32) do { \
    *((UINT32 *)(relocAddr)) = (value32);        \
} while (0)
#define OS_MEM_WRITE_16(relocAddr, value16) do { \
    *((UINT16 *)(relocAddr)) = (value16);        \
} while (0)
#define OS_MEM_WRITE_8(relocAddr, value8) do {   \
    *((UINT8 *)(relocAddr)) = (value8);          \
} while (0)

#define OS_READ_INSTRUCTION_THUMB16(position) (*(UINT16 *)(position))
#define OS_WRITE_INSTRUCTION_THUMB16(position, value16) do { \
    *(UINT16 *)(position) = (UINT16)(value16);               \
} while (0)

#define OS_READ_INSTRUCTION_THUMB32(position) \
    (*(UINT16 *)(position) + ((UINT32)(*(UINT16 *)((position) + 2)) << 16))
#define OS_WRITE_INSTRUCTION_THUMB32(position, value32) do {                 \
    *(UINT16 *)(position) = (UINT16)(value32);                               \
    *(UINT16 *)((position) + 2) = (UINT16)((value32) >> 16); \
} while (0)

#define GET_BITS(bitWide) (((UINTPTR)-1) >> ((sizeof(UINTPTR) * 8) - (bitWide)))

#define CLEAR_BITS_AREA(data, startBit, bitWide) do { \
    (data) &= ~(GET_BITS((bitWide)) << (startBit));   \
} while (0)

#define GET_BITS_AREA(data, startBit, bitWide) ((data) & (GET_BITS((bitWide)) << (startBit)))

#define OS_GET_PAGE_ADDR(expr) ((expr) & ~(UINTPTR)0xfff)

typedef struct {
    LOS_DL_LIST linkNode;
    UINTPTR symAddr;
} DynComSymInfo;

enum ElfType {
    ET_NONE = LD_ET_NONE,
    ET_OBJ = LD_ET_REL,
    ET_EXEC = LD_ET_EXEC,
    ET_SO = LD_ET_DYN
};

typedef struct {
    UINT32 strLen;
    UINT32 symNum;
    UINT32 strTotalLen;
    UINT32 symTotalNum;
    LDSymbol *symTbl;
    CHAR *strTbl;
} SymbolManage;

typedef struct {
    UINT32 *bucket;
    UINT32 bucketSize;
    UINT32 *chain;
    UINT32 chainSize;
} LDHashInfo;

typedef struct DynModuleInfo {
    LOS_DL_LIST manageList; /* Must comes first */
    LOS_DL_LIST comSymInfoList;
    UINTPTR segmentsAddr;
    UINTPTR segmentsSize;
    UINT32 moduleStatus;
    INT32 refCnt;
    INT32 headCnt;
    enum ElfType type;
    CHAR *moduleFileName;
    SymbolManage symManage;
#if defined(LOSCFG_DYNLOAD_DYN_FROM_MEM) || defined(LOSCFG_DYNLOAD_DYN_FROM_FS)
    struct DynModuleInfo *apDlNeeded[N_MAX_MODULES];
    LDHashInfo hashInfo;
#endif
    CHAR *strTab;
    LD_ELF_SYM *symTab;
} DynModuleInfo;

typedef struct {
    RelocationInfo rel;
    RelocationInfo rela;
    RelocationInfo jmpRel;
} RelocationInfoT;

#define RELOCATIONINFO_COUNT                (sizeof(RelocationInfoT) / sizeof(RelocationInfo))

typedef struct {
    LOS_DL_LIST dlLinkNode;

    UINTPTR loadStart;
    UINTPTR loadBias;

    UINTPTR minVaddr;  /* the minimum virtual address of load-segment. */

    DynModuleInfo *moduleHandle;

    LD_ELF_EHDR *elfHdr;

    LD_ELF_SHDR *scnHdrTbl;
    UINT32 scnNum;

    LD_ELF_PHDR *phdrTbl;
    UINT32 phNum;

    LD_ELF_DYN *dynamic;

    CHAR *strTab;
    UINTPTR strTabSize;

    LD_ELF_SYM *symTab;
    UINT32 symNum;

    union {
        RelocationInfoT relocations;
        RelocationInfo rellocationInfos[RELOCATIONINFO_COUNT];
    } relocation;
} DlInfo;

typedef struct {
    INT32 fd;
    const CHAR *fileBuf;
    UINT32 fileSize;
    off_t offset;
} SrcInfo;

typedef struct {
    CHAR *buf;
    UINT32 bufSize;
    UINT32 needSize;
} DestInfo;

typedef INT32 (*LoadFunc)(const SrcInfo *srcInfo, DlInfo *dlInfo, BOOL useHash);
typedef INT32 (*RelocFunc)(const DlInfo *dlInfo);

typedef enum {
    LD_MODE_FS,
    LD_MODE_MEM
} DYN_LOAD_MODE;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LOS_LD_TYPE_PRI_H */
