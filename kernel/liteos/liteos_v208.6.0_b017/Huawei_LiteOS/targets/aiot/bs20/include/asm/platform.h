/* ----------------------------------------------------------------------------
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: platform config \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-04-10, Create file. \n
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

#ifndef _ASM_PLATFORM_H
#define _ASM_PLATFORM_H

#include "los_typedef.h"
#include "asm/interrupt_config.h"
#include "asm/register_config.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define LOS_EMG_LEVEL   0
#define HZ              100

/* 内核心跳时钟主频:32M */
#if defined(CONFIG_REDUCE_PERP_LS_FREQ)
#define OS_SYS_CLOCK_CONFIG           8000000
#else
#define OS_SYS_CLOCK_CONFIG           32000000
#endif
#define OS_SYS_CLOCK                  OS_SYS_CLOCK_CONFIG
// #define get_bus_clk()                 32000000

extern void osal_printk(const char *fmt, ...);

#define PRINT_EXC(fmt, arg...)      osal_printk(fmt, ##arg)
#define LOS_PANIC(fmt, args...)     osal_printk(fmt, ##args)
#undef PRINT_INFO
#define PRINT_INFO(fmt, args...)    osal_printk(fmt, ##args)
#define PRINT_WARN(fmt, args...)    osal_printk(fmt, ##args)
#define PRINT_ERR(fmt, args...)     osal_printk(fmt, ##args)
#define PRINTK(fmt, args...)        osal_printk(fmt, ##args)
#define PRINT_EMG(fmt, args...)     osal_printk(fmt, ##args)
#define PRINT_RELEASE(fmt, args...) osal_printk(fmt, ##args)

extern VOID BoardConfig(VOID);
extern UINT32 oal_get_sleep_ticks(VOID);
extern VOID oal_ticks_restore(UINT32 ticks);
#ifdef LOSCFG_PLATFORM_OSAPPINIT
extern VOID app_init(VOID);
#endif

extern VOID os_tick_timer_disable(VOID);
extern VOID os_tick_timer_enable(VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _ASM_PLATFORM_H */
