/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  CPU Trace HAL Header file for CPU Trace driver
 * Author: @CompanyNameTag
 * Create: 2018-10-15
 */
#ifndef HAL_CPU_TRACE_H
#define HAL_CPU_TRACE_H

#include <stdint.h>
#include "std_def.h"
#include "chip_definitions.h"

/** @defgroup connectivity_drivers_hal_cpu_trace CPU Trace
  * @ingroup  connectivity_drivers_hal
  * @{
  */
typedef enum {
    HAL_CPU_TRACE_TRACED_BCPU = 0,  // trace BCPU
    HAL_CPU_TRACE_TRACED_MCPU = 1,  // trace MCPU
#if CHIP_LIBRA
    HAL_CPU_TRACE_TRACED_GCPU = 2,  // trace GNSS CPU
    HAL_CPU_TRACE_TRACED_SCPU = 3,  // trace Security CPU
#endif
    HAL_CPU_TRACE_TRACED_WCPU = 4,  // trace Security CPU
} hal_cpu_trace_traced_cpu_t;

typedef enum {
    HAL_CPU_TRACE_SAMPLE_MODE_ONCE = 0,  // store until full
    HAL_CPU_TRACE_SAMPLE_MODE_REPEAT,    // repeat store
} hal_cpu_trace_sample_mode_t;

typedef enum {
    DIAG_FUNCTION_NONE = 0,  // Default value
    DIAG_FUNCTION_BT = 2,    // Config diag to bt sample
    DIAG_FUNCTION_DSP = 4,   // Config diag to dsp sample
    DIAG_FUNCTION_TEST = 8,  // Config diag to test
} diag_function_t;

/**
 * @brief  Enable CPU Trace
 * @param  cpu The cpu to enable
 * @param  sample_mode The CPU trace sample mode.
 * @param  start_addr The start address to store cpu trace sample, define at memory config.
 * @param  end_addr The end address to store cpu trace sample, define at memory config.
 * @return true of false
 */
bool hal_cpu_trace_enable(hal_cpu_trace_traced_cpu_t cpu, hal_cpu_trace_sample_mode_t sample_mode,
                          uint32_t start_addr, uint32_t end_addr);

/**
 * @brief  Disable CPU Trace
 */
void hal_cpu_trace_disable(void);

/**
 * @brief  Enable CPU Trace clock
 */
void hal_cpu_trace_clock_enable(void);

/**
 * @brief  Disable CPU Trace clock
 */
void hal_cpu_trace_clock_disable(void);

/**
 * @brief  Set CPU Trace sample_mode
 * @param  sample_mode HAL_CPU_TRACE_SAMPLE_MODE_ONCE or HAL_CPU_TRACE_SAMPLE_MODE_REPEAT
 */
void hal_cpu_trace_set_sample_mode(hal_cpu_trace_sample_mode_t sample_mode);

/**
 * @brief  Set CPU Trace address range
 * @param  start_addr The start address to store cpu trace sample
 * @param  end_addr The end address to store cpu trace sample
 * @return true or false
 */
bool hal_cpu_trace_set_sample_addr(uint32_t start_addr, uint32_t end_addr);

/**
 * @brief  Enable cpu lock
 * @param  cpu The cpu to get pointer
 */
void hal_cpu_trace_lock_enable(hal_cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Lock cpu pc and lr
 * @param  cpu The cpu to get pointer
 */
void hal_cpu_trace_lock_pclr(hal_cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get locked pc
 * @param  cpu The cpu to get pointer
 * @return pc
 */
uint32_t hal_cpu_trace_get_locked_pc(hal_cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get locked lr
 * @param  cpu The cpu to get pointer
 * @return lr
 */
uint32_t hal_cpu_trace_get_locked_lr(hal_cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get stack pointer
 * @param  cpu HAL_CPU_TRACE_TRACED_GCPU or HAL_CPU_TRACE_TRACED_MCPU
 * @return stack pointer value
 */
uint32_t hal_cpu_trace_get_locked_sp(hal_cpu_trace_traced_cpu_t cpu);

/**
 * @brief  Get locked LR & PC
 * @param  cpu The core need to get
 * @param  pc The PC pointer
 * @param  lr The LR pointer
 * @param  sp The SP pointer
 * @return true or false
 */
bool hal_cpu_trace_get_locked_regs(hal_cpu_trace_traced_cpu_t cpu, uint32_t *pc, uint32_t *lr, uint32_t *sp);

/**
 * @brief  Config cpu trace sample sync bit
 */
void hal_cpu_trace_sample_sync_bit_config(void);
/**
  * @}
  */

bool hal_cpu_trace_is_running(void);
#endif
