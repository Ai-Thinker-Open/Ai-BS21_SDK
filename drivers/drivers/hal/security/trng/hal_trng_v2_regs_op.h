/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides trng v2 regs operation \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-05, Create file. \n
 */
#ifndef HAL_TRNG_V2_REGS_OP_H
#define HAL_TRNG_V2_REGS_OP_H

#include <stdint.h>
#include "hal_trng_v2_regs_def.h"
#include "trng_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_hal_trng_v2_regs_op Regs Operation
 * @ingroup  drivers_hal_trng_v2
 * @{
 */

extern trng_regs_v2_t *g_trng_v2_regs;

/**
 * @brief  Init the trng which will set the base address of registers.
 * @return 0 indicates the base address of registers has been configured success, -1 indicates failure.
 */
int32_t hal_trng_v2_regs_init(void);

/**
 * @brief  Deinit the hal trng which will clear the base address of registers has been
 *         set by @ref hal_trng_v2_regs_init.
 */
void hal_trng_v2_regs_deinit(void);

/**
 * @brief  Set the value of @ref trng_status.ready.
 * @param  [in]  ready The value of @ref trng_status.ready
 */
static inline void hal_set_trng_status_ready(uint32_t ready)
{
    trng_status_t trng_status;
    trng_status.d32 = g_trng_v2_regs->trng_status.d32;
    trng_status.b.ready = ready;
    g_trng_v2_regs->trng_status.d32 = trng_status.d32;
}

/**
 * @brief  Set the value of @ref trng_control.ready_mask.
 * @param  [in]  ready_mask The value of @ref trng_control.ready_mask
 */
static inline void hal_set_trng_control_ready_mask(uint32_t ready_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.ready_mask = ready_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.shutdown_oflo_mask.
 * @param  [in]  shutdown_oflo_mask The value of @ref trng_control.shutdown_oflo_mask
 */
static inline void hal_set_trng_control_shutdown_oflmask(uint32_t shutdown_oflo_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.shutdown_oflo_mask = shutdown_oflo_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.stuck_out_mask.
 * @param  [in]  stuck_out_mask The value of @ref trng_control.stuck_out_mask
 */
static inline void hal_set_trng_control_stuck_out_mask(uint32_t stuck_out_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.stuck_out_mask = stuck_out_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.noise_fail_mask.
 * @param  [in]  noise_fail_mask The value of @ref trng_control.noise_fail_mask
 */
static inline void hal_set_trng_control_noise_fail_mask(uint32_t noise_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.noise_fail_mask = noise_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.run_fail_mask.
 * @param  [in]  run_fail_mask The value of @ref trng_control.run_fail_mask
 */
static inline void hal_set_trng_control_run_fail_mask(uint32_t run_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.run_fail_mask = run_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.long_run_fail_mask.
 * @param  [in]  long_run_fail_mask The value of @ref trng_control.long_run_fail_mask
 */
static inline void hal_set_trng_control_long_run_fail_mask(uint32_t long_run_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.long_run_fail_mask = long_run_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.poker_fail_mask.
 * @param  [in]  poker_fail_mask The value of @ref trng_control.poker_fail_mask
 */
static inline void hal_set_trng_control_poker_fail_mask(uint32_t poker_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.poker_fail_mask = poker_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.monobit_fail_mask.
 * @param  [in]  monobit_fail_mask The value of @ref trng_control.monobit_fail_mask
 */
static inline void hal_set_trng_control_monobit_fail_mask(uint32_t monobit_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.monobit_fail_mask = monobit_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.test_mode.
 * @param  [in]  test_mode The value of @ref trng_control.test_mode
 */
static inline void hal_set_trng_control_test_mode(uint32_t test_mode)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.test_mode = test_mode;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.stuck_nrbg_mask.
 * @param  [in]  stuck_nrbg_mask The value of @ref trng_control.stuck_nrbg_mask
 */
static inline void hal_set_trng_control_stuck_nrbg_mask(uint32_t stuck_nrbg_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.stuck_nrbg_mask = stuck_nrbg_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.enable_trng.
 * @param  [in]  enable_trng The value of @ref trng_control.enable_trng
 */
static inline void hal_set_trng_control_enable_trng(uint32_t enable_trng)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.enable_trng = enable_trng;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.drbg_en.
 * @param  [in]  drbg_en The value of @ref trng_control.drbg_en
 */
static inline void hal_set_trng_control_drbg_en(uint32_t drbg_en)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.drbg_en = drbg_en;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.repcnt_fail_mask.
 * @param  [in]  repcnt_fail_mask The value of @ref trng_control.repcnt_fail_mask
 */
static inline void hal_set_trng_control_repcnt_fail_mask(uint32_t repcnt_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.repcnt_fail_mask = repcnt_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.aprop_fail_mask.
 * @param  [in]  aprop_fail_mask The value of @ref trng_control.aprop_fail_mask
 */
static inline void hal_set_trng_control_aprop_fail_mask(uint32_t aprop_fail_mask)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.aprop_fail_mask = aprop_fail_mask;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.re_seed.
 * @param  [in]  re_seed The value of @ref trng_control.re_seed
 */
static inline void hal_set_trng_control_re_seed(uint32_t re_seed)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.re_seed = re_seed;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.request_data.
 * @param  [in]  request_data The value of @ref trng_control.request_data
 */
static inline void hal_set_trng_control_request_data(uint32_t request_data)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.request_data = request_data;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_control.data_blocks.
 * @param  [in]  data_blocks The value of @ref trng_control.data_blocks
 */
static inline void hal_set_trng_control_data_blocks(uint32_t data_blocks)
{
    trng_control_t trng_control;
    trng_control.d32 = g_trng_v2_regs->trng_control.d32;
    trng_control.b.data_blocks = data_blocks;
    trng_control.b.request_data = 0x1;
    g_trng_v2_regs->trng_control.d32 = trng_control.d32;
}

/**
 * @brief  Set the value of @ref trng_config.noise_blocks.
 * @param  [in]  noise_blocks The value of @ref trng_config.noise_blocks
 */
static inline void hal_set_trng_config_noise_blocks(uint32_t noise_blocks)
{
    trng_config_t trng_config;
    trng_config.d32 = g_trng_v2_regs->trng_config.d32;
    trng_config.b.noise_blocks = noise_blocks;
    g_trng_v2_regs->trng_config.d32 = trng_config.d32;
}

/**
 * @brief  Set the value of @ref trng_config.sample_div.
 * @param  [in]  sample_div The value of @ref trng_config.sample_div
 */
static inline void hal_set_trng_config_sample_div(uint32_t sample_div)
{
    trng_config_t trng_config;
    trng_config.d32 = g_trng_v2_regs->trng_config.d32;
    trng_config.b.sample_div = sample_div;
    g_trng_v2_regs->trng_config.d32 = trng_config.d32;
}

/**
 * @brief  Set the value of @ref trng_config.read_timeout.
 * @param  [in]  read_timeout The value of @ref trng_config.read_timeout
 */
static inline void hal_set_trng_config_read_timeout(uint32_t read_timeout)
{
    trng_config_t trng_config;
    trng_config.d32 = g_trng_v2_regs->trng_config.d32;
    trng_config.b.read_timeout = read_timeout;
    g_trng_v2_regs->trng_config.d32 = trng_config.d32;
}

/**
 * @brief  Set the value of @ref trng_config.sample_cycles.
 * @param  [in]  sample_cycles The value of @ref trng_config.sample_cycles
 */
static inline void hal_set_trng_config_sample_cycles(uint32_t sample_cycles)
{
    trng_config_t trng_config;
    trng_config.d32 = g_trng_v2_regs->trng_config.d32;
    trng_config.b.sample_cycles = sample_cycles;
    g_trng_v2_regs->trng_config.d32 = trng_config.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmcnt.alarm_threshold.
 * @param  [in]  alarm_threshold The value of @ref trng_alarmcnt.alarm_threshold
 */
static inline void hal_set_trng_alarmcnt_alarm_threshold(uint32_t alarm_threshold)
{
    trng_alarmcnt_t trng_alarmcnt;
    trng_alarmcnt.d32 = g_trng_v2_regs->trng_alarmcnt.d32;
    trng_alarmcnt.b.alarm_threshold = alarm_threshold;
    g_trng_v2_regs->trng_alarmcnt.d32 = trng_alarmcnt.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmcnt.stall_run_poker.
 * @param  [in]  stall_run_poker The value of @ref trng_alarmcnt.stall_run_poker
 */
static inline void hal_set_trng_alarmcnt_stall_run_poker(uint32_t stall_run_poker)
{
    trng_alarmcnt_t trng_alarmcnt;
    trng_alarmcnt.d32 = g_trng_v2_regs->trng_alarmcnt.d32;
    trng_alarmcnt.b.stall_run_poker = stall_run_poker;
    g_trng_v2_regs->trng_alarmcnt.d32 = trng_alarmcnt.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmcnt.shutdown_threshold.
 * @param  [in]  shutdown_threshold The value of @ref trng_alarmcnt.shutdown_threshold
 */
static inline void hal_set_trng_alarmcnt_shutdown_threshold(uint32_t shutdown_threshold)
{
    trng_alarmcnt_t trng_alarmcnt;
    trng_alarmcnt.d32 = g_trng_v2_regs->trng_alarmcnt.d32;
    trng_alarmcnt.b.shutdown_threshold = shutdown_threshold;
    g_trng_v2_regs->trng_alarmcnt.d32 = trng_alarmcnt.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmcnt.shutdown_fatal.
 * @param  [in]  shutdown_fatal The value of @ref trng_alarmcnt.shutdown_fatal
 */
static inline void hal_set_trng_alarmcnt_shutdown_fatal(uint32_t shutdown_fatal)
{
    trng_alarmcnt_t trng_alarmcnt;
    trng_alarmcnt.d32 = g_trng_v2_regs->trng_alarmcnt.d32;
    trng_alarmcnt.b.shutdown_fatal = shutdown_fatal;
    g_trng_v2_regs->trng_alarmcnt.d32 = trng_alarmcnt.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmcnt.shutdown_count.
 * @param  [in]  shutdown_count The value of @ref trng_alarmcnt.shutdown_count
 */
static inline void hal_set_trng_alarmcnt_shutdown_count(uint32_t shutdown_count)
{
    trng_alarmcnt_t trng_alarmcnt;
    trng_alarmcnt.d32 = g_trng_v2_regs->trng_alarmcnt.d32;
    trng_alarmcnt.b.shutdown_count = shutdown_count;
    g_trng_v2_regs->trng_alarmcnt.d32 = trng_alarmcnt.d32;
}

/**
 * @brief  Set the value of @ref trng_froenable.fro_enables.
 * @param  [in]  fro_enables The value of @ref trng_froenable.fro_enables
 */
static inline void hal_set_trng_froenable_frenables(uint32_t fro_enables)
{
    trng_froenable_t trng_froenable;
    trng_froenable.d32 = g_trng_v2_regs->trng_froenable.d32;
    trng_froenable.b.fro_enables = fro_enables;
    g_trng_v2_regs->trng_froenable.d32 = trng_froenable.d32;
}

/**
 * @brief  Set the value of @ref trng_frodetune.fro_detunes.
 * @param  [in]  fro_detunes The value of @ref trng_frodetune.fro_detunes
 */
static inline void hal_set_trng_frodetune_frdetunes(uint32_t fro_detunes)
{
    trng_frodetune_t trng_frodetune;
    trng_frodetune.d32 = g_trng_v2_regs->trng_frodetune.d32;
    trng_frodetune.b.fro_detunes = fro_detunes;
    g_trng_v2_regs->trng_frodetune.d32 = trng_frodetune.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmmask.fro_alarmmasks.
 * @param  [in]  fro_alarmmasks The value of @ref trng_alarmmask.fro_alarmmasks
 */
static inline void hal_set_trng_alarmmask_fralarmmasks(uint32_t fro_alarmmasks)
{
    trng_alarmmask_t trng_alarmmask;
    trng_alarmmask.d32 = g_trng_v2_regs->trng_alarmmask.d32;
    trng_alarmmask.b.fro_alarmmasks = fro_alarmmasks;
    g_trng_v2_regs->trng_alarmmask.d32 = trng_alarmmask.d32;
}

/**
 * @brief  Set the value of @ref trng_alarmstop.fro_alarmstops.
 * @param  [in]  fro_alarmstops The value of @ref trng_alarmstop.fro_alarmstops
 */
static inline void hal_set_trng_alarmstop_fralarmstops(uint32_t fro_alarmstops)
{
    trng_alarmstop_t trng_alarmstop;
    trng_alarmstop.d32 = g_trng_v2_regs->trng_alarmstop.d32;
    trng_alarmstop.b.fro_alarmstops = fro_alarmstops;
    g_trng_v2_regs->trng_alarmstop.d32 = trng_alarmstop.d32;
}

/**
 * @brief  Set the value of @ref trng_oscl.oscl_en.
 * @param  [in]  oscl_en The value of @ref trng_oscl.oscl_en
 */
static inline void hal_set_trng_oscl_oscl_en(uint32_t oscl_en)
{
    trng_oscl_t trng_oscl;
    trng_oscl.d32 = g_trng_v2_regs->trng_oscl.d32;
    trng_oscl.b.oscl_en = oscl_en;
    g_trng_v2_regs->trng_oscl.d32 = trng_oscl.d32;
}

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
