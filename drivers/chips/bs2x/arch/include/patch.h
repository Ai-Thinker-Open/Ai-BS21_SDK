/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides patch driver source \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-17, Create file. \n
 */

#ifndef PATCH_H
#define PATCH_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup device_susong_patch Patch
 * @ingroup  device_susong
 * @{
 */

#define PATCH_CMP_REG_NUM  128

#define writel(addr, d)                             (*(volatile uint32_t*)(uintptr_t)(addr) = (uint32_t)(d))

#define reg(base, offset)                           (*(volatile uint32_t *)(uintptr_t)((uint32_t)(base) + (offset)))

#define reg_setbit(base, offset, pos)               ((reg(base, offset)) |= ((uint32_t)(1) << (pos)))

#define reg_clrbit(base, offset, pos)               ((reg(base, offset)) &= ~((uint32_t)(1) << (pos)))

#define EXPORT_HARD_PATCH(old_sym, new_sym) \
    void* old_sym##$patch$##new_sym##_hard __attribute__((section("patch.hard"))) __attribute__((__used__)) = new_sym

#define EXPORT_SOFT_PATCH(sym) \
    void* sym##_soft __attribute__((section("patch.soft"))) __attribute__((__used__)) = sym

typedef struct {
    uint32_t cmp_start_addr;
    uint32_t remap_addr;
    bool off_region;   /*!< The jump range, false for within 1MB, true for out of the 1M range. */
    uint8_t flplacmp0_en;
    uint8_t flplacmp1_en;
} riscv_cfg_t;

 /**
 * @if Eng
 * @brief  Initialises the patch.
 * @param  [in]  patch_cfg patch configuration. see @ref riscv_cfg_t
 * @else
 * @brief  patch初始化.
 * @param  [in]  patch_cfg patch 配置参数， 参考 @ref riscv_cfg_t
 * @endif
 */
void patch_init(riscv_cfg_t *patch_cfg);

void func_patch_init(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif