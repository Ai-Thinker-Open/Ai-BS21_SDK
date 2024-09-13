/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: Dma HeadFile
 * Author: @CompanyNameTag
 * Create:  2023-01-10
 */

#ifndef _DMA_H
#define _DMA_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

extern void dma_cache_clean(uintptr_t start, uintptr_t end);
extern void dma_cache_inv(uintptr_t start, uintptr_t end);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _DMA_H */
