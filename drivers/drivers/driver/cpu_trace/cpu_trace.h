/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:   CPU Trace Driver Header File
 * Author: @CompanyNameTag
 * Create:
 */
#ifndef CPU_TRACE_H
#define CPU_TRACE_H

#include "hal_cpu_trace.h"
#include "errcode.h"
#include "core.h"

/**
 * @defgroup connectivity_drivers_non_os_cpu_trace CPU Trace
 * @ingroup  connectivity_drivers_non_os
 * @{
 */
#define CPUTRACE_MEM var_segment("cputrace_mem")
#define NONE_CPU_TRACE 0
#define BCPU_TRACE_MASK 1
#define MCPU_TRACE_MASK 2
#define GCPU_TRACE_MASK 4
#define SCPU_TRACE_MASK 8
#define WCPU_TRACE_MASK 16

typedef enum {
    CPU_TRACE_TRACED_BCPU = 0,  // trace BCPU
    CPU_TRACE_TRACED_MCPU = 1,  // trace MCPU
    CPU_TRACE_TRACED_GCPU = 2,  // trace GNSS CPU
    CPU_TRACE_TRACED_SCPU = 3,  // trace Security CPU
    CPU_TRACE_TRACED_WCPU = 4,  // trace Security CPU
} cpu_trace_traced_cpu_t;

typedef enum {
    CPU_TRACE_SAMPLE_MODE_ONCE = 0,  // store until full
    CPU_TRACE_SAMPLE_MODE_REPEAT,    // repeat store
} cpu_trace_sample_mode_t;

typedef enum {
    CPU_TRACE_TRACED_EXCEPTION_XIP = 0,
    CPU_TRACE_TRACED_EXCEPTION_HARDFAULT = 1,
    CPU_TRACE_TRACED_EXCEPTION_MAX,
} cpu_trace_traced_exception_t;

typedef struct _cpu_trace_item_ {
    uint32_t time;
    uint32_t lr;
    uint32_t pc;
} cpu_trace_item_t;

/**
 * @brief  Enable CPU_Trace, only can be used by BT.
          Every three words is a group, the frist word is cpu timestep, the second word is LR, the third is PC.
          when trace mode is CPU_TRACE_SAMPLE_MODE_REPEAT, addr len % 3 must be 0.
 * @param  cpu CPU_TRACE_TRACED_BCPU or CPU_TRACE_TRACED_MCPU or CPU_TRACE_TRACED_GCPU or CPU_TRACE_TRACED_SCPU
 * @param  sample_mode cpu trace mode CPU_TRACE_SAMPLE_MODE_ONCE or CPU_TRACE_SAMPLE_MODE_REPEAT
 * @param  start_addr The start address to store cpu trace sample, start address range is share memory.
 * @param  end_addr The end address to store cpu trace sample, end address range is share memory.
 * @return true or false
 */
bool cpu_trace_enable(cpu_trace_traced_cpu_t cpu, cpu_trace_sample_mode_t sample_mode,
                      uint32_t start_addr, uint32_t end_addr);

/**
 * @brief  Disable CPU Trace.
 */
void cpu_trace_disable(void);

/**
 * @brief  Enable BCPU Trace in repeat mode.
 */
void cpu_trace_enable_bcpu_repeat(void);

/**
 * @brief  Enable MCPU Trace in repeat mode, and only one cpu can be enable.
 */
void cpu_trace_enable_mcpu_repeat(void);

/**
 * @brief  Enable GCPU Trace in repeat mode, and only one cpu can be enable.
 */
void cpu_trace_enable_gcpu_repeat(void);

/**
 * @brief  Enable MCPU Trace in repeat mode, and only one cpu can be enable.
 */
void cpu_trace_enable_scpu_repeat(void);

/**
 * @brief  Enable WCPU Trace in repeat mode, and only one cpu can be enable.
 */
void cpu_trace_enable_wcpu_repeat(void);

/**
 * @brief  Save pc lr and sp of cpu.
 * @param  exception The exception to save pc lr and sp of cpu.
 */
void cpu_trace_save_cpu_info(cpu_trace_traced_exception_t exception);

/**
 * @brief  Store current PC and LR.
 * @param  cpu Which core need to get.
 */
void cpu_trace_lock_pclr(cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get stored PC.
 * @return PC pointer.
 */
uint32_t cpu_trace_get_locked_pc(cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get stored lr.
 * @param  cpu Which core need to get.
 * @return LR pointer.
 */
uint32_t cpu_trace_get_locked_lr(cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get stack.
 * @param  cpu Which core need to get.
 * @return stack pointer.
 */
uint32_t cpu_trace_get_locked_sp(cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get stored lr & pc.
 * @param  cpu Which core need to get.
 * @param  pc PC pointer.
 * @param  lr LR pointer.
 * @param  sp SP pointer.
 * @return true or false
 */
bool cpu_trace_get_locked_regs(hal_cpu_trace_traced_cpu_t cpu, uint32_t *pc, uint32_t *lr, uint32_t *sp);

#if defined(CONFIG_CPU_TRACE_SUPPORT_LPM)
/**
 * @brief  Suspend all of the MCPU trace channels.
 * @param  [in]  arg Argument for suspend.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 */
errcode_t cpu_trace_suspend(uintptr_t arg);

/**
 * @brief  Resume all of the MCPU trace channels.
 * @param  [in]  arg Argument for resume, Which core need to resume.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 */
errcode_t cpu_trace_resume(uintptr_t arg);
#endif

/**
 * @}
 */
#endif
