/**
 * Copyright (c)@CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides hal trng v1 regs opeartion header file\n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-01, Create file. \n
 */
#ifndef HAL_TRNG_V1_REGS_OP_H
#define HAL_TRNG_V1_REGS_OP_H

#include <stdint.h>
#include "hal_trng_v1_regs_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_hal_trng_v1_regs_op Regs Operation
 * @ingroup  drivers_hal_trng_v1
 * @{
 */

extern trng_regs_v1_t *g_trng_v1_regs;

/**
 * @brief  Init the trng which will set the base address of registers.
 * @return 0 indicates the base address of registers has been configured success, -1 indicates failure.
 */
int32_t hal_trng_v1_regs_init(void);

/**
 * @brief  Deinit the hal trng which will clear the base address of registers has been
 *         set by @ref hal_trng_v1_regs_init.
 */
void hal_trng_v1_regs_deinit(void);

/**
 * @brief  Set the value of @ref trng_ctrl.health_test_en.
 * @param  [in]  health_test_en The value of @ref trng_ctrl.health_test_en
 */
static inline void hal_set_trng_ctrl_health_test_en(uint32_t health_test_en)
{
    trng_ctrl_t trng_ctrl;
    trng_ctrl.d32 = g_trng_v1_regs->trng_ctrl.d32;
    trng_ctrl.b.health_test_en = health_test_en;
    g_trng_v1_regs->trng_ctrl.d32 = trng_ctrl.d32;
}

/**
 * @brief  Set the value of @ref trng_ctrl.online_test_en.
 * @param  [in]  online_test_en The value of @ref trng_ctrl.online_test_en
 */
static inline void hal_set_trng_ctrl_online_test_en(uint32_t online_test_en)
{
    trng_ctrl_t trng_ctrl;
    trng_ctrl.d32 = g_trng_v1_regs->trng_ctrl.d32;
    trng_ctrl.b.online_test_en = online_test_en;
    g_trng_v1_regs->trng_ctrl.d32 = trng_ctrl.d32;
}

/**
 * @brief  Set the value of @ref trng_ctrl.post_proc_en.
 * @param  [in]  post_proc_en The value of @ref trng_ctrl.post_proc_en
 */
static inline void hal_set_trng_ctrl_post_proc_en(uint32_t post_proc_en)
{
    trng_ctrl_t trng_ctrl;
    trng_ctrl.d32 = g_trng_v1_regs->trng_ctrl.d32;
    trng_ctrl.b.post_proc_en = post_proc_en;
    g_trng_v1_regs->trng_ctrl.d32 = trng_ctrl.d32;
}

/**
 * @brief  Set the value of @ref trng_ctrl.rnd_chk_en.
 * @param  [in]  rnd_chk_en The value of @ref trng_ctrl.rnd_chk_en
 */
static inline void hal_set_trng_ctrl_rnd_chk_en(uint32_t rnd_chk_en)
{
    trng_ctrl_t trng_ctrl;
    trng_ctrl.d32 = g_trng_v1_regs->trng_ctrl.d32;
    trng_ctrl.b.rnd_chk_en = rnd_chk_en;
    g_trng_v1_regs->trng_ctrl.d32 = trng_ctrl.d32;
}

/**
 * @brief  Set the value of @ref trng_ctrl.lfsr_reseed_en.
 * @param  [in]  lfsr_reseed_en The value of @ref trng_ctrl.lfsr_reseed_en
 */
static inline void hal_set_trng_ctrl_lfsr_reseed_en(uint32_t lfsr_reseed_en)
{
    trng_ctrl_t trng_ctrl;
    trng_ctrl.d32 = g_trng_v1_regs->trng_ctrl.d32;
    trng_ctrl.b.lfsr_reseed_en = lfsr_reseed_en;
    g_trng_v1_regs->trng_ctrl.d32 = trng_ctrl.d32;
}

/**
 * @brief  Set the value of @ref trng_ctrl.private_en.
 * @param  [in]  private_en The value of @ref trng_ctrl.private_en
 */
static inline void hal_set_trng_ctrl_private_en(uint32_t private_en)
{
    trng_ctrl_t trng_ctrl;
    trng_ctrl.d32 = g_trng_v1_regs->trng_ctrl.d32;
    trng_ctrl.b.private_en = private_en;
    g_trng_v1_regs->trng_ctrl.d32 = trng_ctrl.d32;
}

/**
 * @brief  Set the value of @ref trng_src_sel.trng_sel.
 * @param  [in]  trng_sel The value of @ref trng_src_sel.trng_sel.
 */
static inline void hal_set_trng_src_sel_trng_sel(uint32_t trng_sel)
{
    trng_src_sel_t trng_src_sel;
    trng_src_sel.d32 = g_trng_v1_regs->trng_src_sel.d32;
    trng_src_sel.b.trng_sel = trng_sel;
    g_trng_v1_regs->trng_src_sel.d32 = trng_src_sel.d32;
}

/**
 * @brief  Set the value of @ref trng_fro_sel.fro_sel.
 * @param  [in]  fro_sel The value of @ref trng_fro_sel.fro_sel
 */
static inline void hal_set_trng_fro_sel_fro_sel(uint32_t fro_sel)
{
    trng_fro_sel_t trng_fro_sel;
    trng_fro_sel.d32 = g_trng_v1_regs->trng_fro_sel.d32;
    trng_fro_sel.b.fro_sel = fro_sel;
    g_trng_v1_regs->trng_fro_sel.d32 = trng_fro_sel.d32;
}

/**
 * @brief  Set the value of @ref trng_all_reg_lock.trng_all_reg_lock.
 * @param  [in]  trng_all_reg_lock The value of @ref trng_all_reg_lock.trng_all_reg_lock
 */
static inline void hal_set_trng_all_reg_lock_trng_all_reg_lock(uint32_t trng_all_reg_lock)
{
    trng_all_reg_lock_t trng_all_reg_lock_tmp;
    trng_all_reg_lock_tmp.d32 = g_trng_v1_regs->trng_all_reg_lock.d32;
    trng_all_reg_lock_tmp.b.trng_all_reg_lock = trng_all_reg_lock;
    g_trng_v1_regs->trng_all_reg_lock.d32 = trng_all_reg_lock_tmp.d32;
}

/**
 * @brief  Set the value of @ref trng_low_power_enable.trng_low_power_enable.
 * @param  [in]  low_power_enable The value of @ref trng_low_power_enable.trng_low_power_enable
 */
static inline void hal_set_trng_low_power_enable_trng_low_power_enable(uint32_t low_power_enable)
{
    trng_low_power_enable_t trng_low_power_enable;
    trng_low_power_enable.d32 = g_trng_v1_regs->trng_low_power_enable.d32;
    trng_low_power_enable.b.trng_low_power_enable = low_power_enable;
    g_trng_v1_regs->trng_low_power_enable.d32 = trng_low_power_enable.d32;
}

/**
 * @brief  Set the value of @ref trng_ring_en.ro_en.
 * @param  [in]  ro_en The value of @ref trng_ring_en.ro_en
 */
static inline void hal_set_trng_ring_en_ro_en(uint32_t ro_en)
{
    trng_ring_en_t trng_ring_en;
    trng_ring_en.d32 = g_trng_v1_regs->trng_ring_en.d32;
    trng_ring_en.b.ro_en = ro_en;
    g_trng_v1_regs->trng_ring_en.d32 = trng_ring_en.d32;
}

/**
 * @brief  Set the value of @ref trng_ring_en.tero_en.
 * @param  [in]  tero_en The value of @ref trng_ring_en.tero_en.
 */
static inline void hal_set_trng_ring_en_tero_en(uint32_t tero_en)
{
    trng_ring_en_t trng_ring_en;
    trng_ring_en.d32 = g_trng_v1_regs->trng_ring_en.d32;
    trng_ring_en.b.tero_en = tero_en;
    g_trng_v1_regs->trng_ring_en.d32 = trng_ring_en.d32;
}

/**
 * @brief  Set the value of @ref trng_ring_en.fro_en.
 * @param  [in]  fro_en The value of @ref trng_ring_en.fro_en
 */
static inline void hal_set_trng_ring_en_fro_en(uint32_t fro_en)
{
    trng_ring_en_t trng_ring_en;
    trng_ring_en.d32 = g_trng_v1_regs->trng_ring_en.d32;
    trng_ring_en.b.fro_en = fro_en;
    g_trng_v1_regs->trng_ring_en.d32 = trng_ring_en.d32;
}

/**
 * @brief  Set the value of @ref trng_ro_timer_cnt.ro_timer_cnt.
 * @param  [in]  ro_timer_cnt The value of @ref trng_ro_timer_cnt.ro_timer_cnt
 */
static inline void hal_set_trng_ro_timer_cnt_ro_timer_cnt(uint32_t ro_timer_cnt)
{
    trng_ro_timer_cnt_t trng_ro_timer_cnt;
    trng_ro_timer_cnt.d32 = g_trng_v1_regs->trng_ro_timer_cnt.d32;
    trng_ro_timer_cnt.b.ro_timer_cnt = ro_timer_cnt;
    g_trng_v1_regs->trng_ro_timer_cnt.d32 = trng_ro_timer_cnt.d32;
}

/**
 * @brief  Set the value of @ref trng_tero_bit_sel.tero_bit_sel.
 * @param  [in]  tero_bit_sel The value of @ref trng_tero_bit_sel.tero_bit_sel.
 */
static inline void hal_set_trng_tero_bit_sel_tero_bit_sel(uint32_t tero_bit_sel)
{
    trng_tero_bit_sel_t trng_tero_bit_sel;
    trng_tero_bit_sel.d32 = g_trng_v1_regs->trng_tero_bit_sel.d32;
    trng_tero_bit_sel.b.tero_bit_sel = tero_bit_sel;
    g_trng_v1_regs->trng_tero_bit_sel.d32 = trng_tero_bit_sel.d32;
}

/**
 * @brief  Set the value of @ref trng_tero_vctr_cfg.tero_vctr_low_cfg.
 * @param  [in]  tero_vctr_low_cfg The value of @ref trng_tero_vctr_cfg.tero_vctr_low_cfg
 */
static inline void hal_set_trng_tero_vctr_cfg_tero_vctr_low_cfg(uint32_t tero_vctr_low_cfg)
{
    trng_tero_vctr_cfg_t trng_tero_vctr_cfg;
    trng_tero_vctr_cfg.d32 = g_trng_v1_regs->trng_tero_vctr_cfg.d32;
    trng_tero_vctr_cfg.b.tero_vctr_low_cfg = tero_vctr_low_cfg;
    g_trng_v1_regs->trng_tero_vctr_cfg.d32 = trng_tero_vctr_cfg.d32;
}

/**
 * @brief  Set the value of @ref trng_tero_vctr_cfg.tero_vctr_low_cfg.
 * @param  [in]  tero_vctr_cfg The value of @ref trng_tero_vctr_cfg.tero_vctr_cfg
 */
static inline void hal_set_trng_tero_vctr_cfg_tero_vctr_cfg(uint32_t tero_vctr_cfg)
{
    trng_tero_vctr_cfg_t trng_tero_vctr_cfg;
    trng_tero_vctr_cfg.d32 = g_trng_v1_regs->trng_tero_vctr_cfg.d32;
    trng_tero_vctr_cfg.b.tero_vctr_cfg = tero_vctr_cfg;
    g_trng_v1_regs->trng_tero_vctr_cfg.d32 = trng_tero_vctr_cfg.d32;
}

/**
 * @brief  Set the value of @ref trng_online_test_fail_ck_th.online_test_fail_ck_cnt.
 * @param  [in]  online_test_fail_ck_cnt The value of @ref trng_online_test_fail_ck_th.online_test_fail_ck_cnt
 */
static inline void hal_set_trng_online_test_fail_ck_th_online_test_fail_ck_cnt(uint32_t online_test_fail_ck_cnt)
{
    trng_online_test_fail_ck_th_t trng_online_test_fail_ck_th;
    trng_online_test_fail_ck_th.d32 = g_trng_v1_regs->trng_online_test_fail_ck_th.d32;
    trng_online_test_fail_ck_th.b.online_test_fail_ck_cnt = online_test_fail_ck_cnt;
    g_trng_v1_regs->trng_online_test_fail_ck_th.d32 = trng_online_test_fail_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_monobit_test_ck_th.mono_ck_low.
 * @param  [in]  mono_ck_low The value of @ref trng_monobit_test_ck_th.mono_ck_low
 */
static inline void hal_set_trng_monobit_test_ck_th_mono_ck_low(uint32_t mono_ck_low)
{
    trng_monobit_test_ck_th_t trng_monobit_test_ck_th;
    trng_monobit_test_ck_th.d32 = g_trng_v1_regs->trng_monobit_test_ck_th.d32;
    trng_monobit_test_ck_th.b.mono_ck_low = mono_ck_low;
    g_trng_v1_regs->trng_monobit_test_ck_th.d32 = trng_monobit_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_monobit_test_ck_th.mono_ck_hig.
 * @param  [in]  mono_ck_hig The value of @ref trng_monobit_test_ck_th.mono_ck_hig
 */
static inline void hal_set_trng_monobit_test_ck_th_mono_ck_hig(uint32_t mono_ck_hig)
{
    trng_monobit_test_ck_th_t trng_monobit_test_ck_th;
    trng_monobit_test_ck_th.d32 = g_trng_v1_regs->trng_monobit_test_ck_th.d32;
    trng_monobit_test_ck_th.b.mono_ck_hig = mono_ck_hig;
    g_trng_v1_regs->trng_monobit_test_ck_th.d32 = trng_monobit_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_long_run_test_ck_th.long_run_hig.
 * @param  [in]  long_run_hig The value of @ref trng_long_run_test_ck_th.long_run_hig
 */
static inline void hal_set_trng_long_run_test_ck_th_long_run_hig(uint32_t long_run_hig)
{
    trng_long_run_test_ck_th_t trng_long_run_test_ck_th;
    trng_long_run_test_ck_th.d32 = g_trng_v1_regs->trng_long_run_test_ck_th.d32;
    trng_long_run_test_ck_th.b.long_run_hig = long_run_hig;
    g_trng_v1_regs->trng_long_run_test_ck_th.d32 = trng_long_run_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run1_test_ck_th.run_0_ck_low.
 * @param  [in]  run_0_ck_low The value of @ref trng_run1_test_ck_th.run_0_ck_low
 */
static inline void hal_set_trng_run1_test_ck_th_run_0_ck_low(uint32_t run_0_ck_low)
{
    trng_run1_test_ck_th_t trng_run1_test_ck_th;
    trng_run1_test_ck_th.d32 = g_trng_v1_regs->trng_run1_test_ck_th.d32;
    trng_run1_test_ck_th.b.run_0_ck_low = run_0_ck_low;
    g_trng_v1_regs->trng_run1_test_ck_th.d32 = trng_run1_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run1_test_ck_th.run_0_ck_hig.
 * @param  [in]  run_0_ck_hig The value of @ref trng_run1_test_ck_th.run_0_ck_hig
 */
static inline void hal_set_trng_run1_test_ck_th_run_0_ck_hig(uint32_t run_0_ck_hig)
{
    trng_run1_test_ck_th_t trng_run1_test_ck_th;
    trng_run1_test_ck_th.d32 = g_trng_v1_regs->trng_run1_test_ck_th.d32;
    trng_run1_test_ck_th.b.run_0_ck_hig = run_0_ck_hig;
    g_trng_v1_regs->trng_run1_test_ck_th.d32 = trng_run1_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run1_test_ck_th.run_1_ck_low.
 * @param  [in]  run_1_ck_low The value of @ref trng_run1_test_ck_th.run_1_ck_low
 */
static inline void hal_set_trng_run1_test_ck_th_run_1_ck_low(uint32_t run_1_ck_low)
{
    trng_run1_test_ck_th_t trng_run1_test_ck_th;
    trng_run1_test_ck_th.d32 = g_trng_v1_regs->trng_run1_test_ck_th.d32;
    trng_run1_test_ck_th.b.run_1_ck_low = run_1_ck_low;
    g_trng_v1_regs->trng_run1_test_ck_th.d32 = trng_run1_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run1_test_ck_th.run_1_ck_hig.
 * @param  [in]  run_1_ck_hig The value of @ref trng_run1_test_ck_th.run_1_ck_hig
 */
static inline void hal_set_trng_run1_test_ck_th_run_1_ck_hig(uint32_t run_1_ck_hig)
{
    trng_run1_test_ck_th_t trng_run1_test_ck_th;
    trng_run1_test_ck_th.d32 = g_trng_v1_regs->trng_run1_test_ck_th.d32;
    trng_run1_test_ck_th.b.run_1_ck_hig = run_1_ck_hig;
    g_trng_v1_regs->trng_run1_test_ck_th.d32 = trng_run1_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run2_test_ck_th.run_00_ck_low.
 * @param  [in]  run_00_ck_low The value of @ref trng_run2_test_ck_th.run_00_ck_low
 */
static inline void hal_set_trng_run2_test_ck_th_run_00_ck_low(uint32_t run_00_ck_low)
{
    trng_run2_test_ck_th_t trng_run2_test_ck_th;
    trng_run2_test_ck_th.d32 = g_trng_v1_regs->trng_run2_test_ck_th.d32;
    trng_run2_test_ck_th.b.run_00_ck_low = run_00_ck_low;
    g_trng_v1_regs->trng_run2_test_ck_th.d32 = trng_run2_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run2_test_ck_th.run_00_ck_hig.
 * @param  [in]  run_00_ck_hig The value of @ref trng_run2_test_ck_th.run_00_ck_hig
 */
static inline void hal_set_trng_run2_test_ck_th_run_00_ck_hig(uint32_t run_00_ck_hig)
{
    trng_run2_test_ck_th_t trng_run2_test_ck_th;
    trng_run2_test_ck_th.d32 = g_trng_v1_regs->trng_run2_test_ck_th.d32;
    trng_run2_test_ck_th.b.run_00_ck_hig = run_00_ck_hig;
    g_trng_v1_regs->trng_run2_test_ck_th.d32 = trng_run2_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run2_test_ck_th.run_11_ck_low.
 * @param  [in]  run_11_ck_low The value of @ref trng_run2_test_ck_th.run_11_ck_low
 */
static inline void hal_set_trng_run2_test_ck_th_run_11_ck_low(uint32_t run_11_ck_low)
{
    trng_run2_test_ck_th_t trng_run2_test_ck_th;
    trng_run2_test_ck_th.d32 = g_trng_v1_regs->trng_run2_test_ck_th.d32;
    trng_run2_test_ck_th.b.run_11_ck_low = run_11_ck_low;
    g_trng_v1_regs->trng_run2_test_ck_th.d32 = trng_run2_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_run2_test_ck_th.run_11_ck_hig.
 * @param  [in]  run_11_ck_hig The value of @ref trng_run2_test_ck_th.run_11_ck_hig
 */
static inline void hal_set_trng_run2_test_ck_th_run_11_ck_hig(uint32_t run_11_ck_hig)
{
    trng_run2_test_ck_th_t trng_run2_test_ck_th;
    trng_run2_test_ck_th.d32 = g_trng_v1_regs->trng_run2_test_ck_th.d32;
    trng_run2_test_ck_th.b.run_11_ck_hig = run_11_ck_hig;
    g_trng_v1_regs->trng_run2_test_ck_th.d32 = trng_run2_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_poker_test_ck_th.poker_ck_hig.
 * @param  [in]  poker_ck_hig The value of @ref trng_poker_test_ck_th.poker_ck_hig
 */
static inline void hal_set_trng_poker_test_ck_th_poker_ck_hig(uint32_t poker_ck_hig)
{
    trng_poker_test_ck_th_t trng_poker_test_ck_th;
    trng_poker_test_ck_th.d32 = g_trng_v1_regs->trng_poker_test_ck_th.d32;
    trng_poker_test_ck_th.b.poker_ck_hig = poker_ck_hig;
    g_trng_v1_regs->trng_poker_test_ck_th.d32 = trng_poker_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_rpt_test_th.rpt_cnt_test.
 * @param  [in]  rpt_cnt_test The value of @ref trng_rpt_test_th.rpt_cnt_test
 */
static inline void hal_set_trng_rpt_test_th_rpt_cnt_test(uint32_t rpt_cnt_test)
{
    trng_rpt_test_th_t trng_rpt_test_th;
    trng_rpt_test_th.d32 = g_trng_v1_regs->trng_rpt_test_th.d32;
    trng_rpt_test_th.b.rpt_cnt_test = rpt_cnt_test;
    g_trng_v1_regs->trng_rpt_test_th.d32 = trng_rpt_test_th.d32;
}

/**
 * @brief  Set the value of @ref trng_adapt_test_th.adapt_low_test.
 * @param  [in]  adapt_low_test The value of @ref trng_adapt_test_th.adapt_low_test
 */
static inline void hal_set_trng_adapt_test_th_adapt_low_test(uint32_t adapt_low_test)
{
    trng_adapt_test_th_t trng_adapt_test_th;
    trng_adapt_test_th.d32 = g_trng_v1_regs->trng_adapt_test_th.d32;
    trng_adapt_test_th.b.adapt_low_test = adapt_low_test;
    g_trng_v1_regs->trng_adapt_test_th.d32 = trng_adapt_test_th.d32;
}

/**
 * @brief  Set the value of @ref trng_adapt_test_th.adapt_hig_test.
 * @param  [in]  adapt_hig_test The value of @ref trng_adapt_test_th.adapt_hig_test
 */
static inline void hal_set_trng_adapt_test_th_adapt_hig_test(uint32_t adapt_hig_test)
{
    trng_adapt_test_th_t trng_adapt_test_th;
    trng_adapt_test_th.d32 = g_trng_v1_regs->trng_adapt_test_th.d32;
    trng_adapt_test_th.b.adapt_hig_test = adapt_hig_test;
    g_trng_v1_regs->trng_adapt_test_th.d32 = trng_adapt_test_th.d32;
}

/**
 * @brief  Set the value of @ref trng_total_failure_test_ck_th.total_failure_ck_hig.
 * @param  [in]  total_failure_ck_hig The value of @ref trng_total_failure_test_ck_th.total_failure_ck_hig
 */
static inline void hal_set_trng_total_failure_test_ck_th_total_failure_ck_hig(uint32_t total_failure_ck_hig)
{
    trng_total_failure_test_ck_th_t trng_total_failure_test_ck_th;
    trng_total_failure_test_ck_th.d32 = g_trng_v1_regs->trng_total_failure_test_ck_th.d32;
    trng_total_failure_test_ck_th.b.total_failure_ck_hig = total_failure_ck_hig;
    g_trng_v1_regs->trng_total_failure_test_ck_th.d32 = trng_total_failure_test_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_rnd_test_fail_ck_th.rnd_fail_ck_cnt.
 * @param  [in]  rnd_fail_ck_cnt The value of @ref trng_rnd_test_fail_ck_th.rnd_fail_ck_cnt
 */
static inline void hal_set_trng_rnd_test_fail_ck_th_rnd_fail_ck_cnt(uint32_t rnd_fail_ck_cnt)
{
    trng_rnd_test_fail_ck_th_t trng_rnd_test_fail_ck_th;
    trng_rnd_test_fail_ck_th.d32 = g_trng_v1_regs->trng_rnd_test_fail_ck_th.d32;
    trng_rnd_test_fail_ck_th.b.rnd_fail_ck_cnt = rnd_fail_ck_cnt;
    g_trng_v1_regs->trng_rnd_test_fail_ck_th.d32 = trng_rnd_test_fail_ck_th.d32;
}

/**
 * @brief  Set the value of @ref trng_alarm_mask.trng_alarm_mask
 * @param  [in]  alarm_mask The value of @ref trng_alarm_mask.trng_alarm_mask
 */
static inline void hal_set_trng_alarm_mask_trng_alarm_mask(uint32_t alarm_mask)
{
    trng_alarm_mask_t trng_alarm_mask;
    trng_alarm_mask.d32 = g_trng_v1_regs->trng_alarm_mask.d32;
    trng_alarm_mask.b.trng_alarm_mask = alarm_mask;
    g_trng_v1_regs->trng_alarm_mask.d32 = trng_alarm_mask.d32;
}

/**
 * @brief  Set the value of @ref trng_alarm_clr.trng_alarm_clr
 * @param  [in]  alarm_clr The value of @ref trng_alarm_clr.trng_alarm_clr
 */
static inline void hal_set_trng_alarm_clr_trng_alarm_clr(uint32_t alarm_clr)
{
    trng_alarm_clr_t trng_alarm_clr;
    trng_alarm_clr.d32 = g_trng_v1_regs->trng_alarm_clr.d32;
    trng_alarm_clr.b.trng_alarm_clr = alarm_clr;
    g_trng_v1_regs->trng_alarm_clr.d32 = trng_alarm_clr.d32;
}

/**
 * @brief  Set the value of @ref trng_tero_cnt_sel.tero_cnt_sel
 * @param  [in]  tero_cnt_sel The value of @ref trng_tero_cnt_sel.tero_cnt_sel
 */
static inline void hal_set_trng_tero_cnt_sel_tero_cnt_sel(uint32_t tero_cnt_sel)
{
    trng_tero_cnt_sel_t trng_tero_cnt_sel;
    trng_tero_cnt_sel.d32 = g_trng_v1_regs->trng_tero_cnt_sel.d32;
    trng_tero_cnt_sel.b.tero_cnt_sel = tero_cnt_sel;
    g_trng_v1_regs->trng_tero_cnt_sel.d32 = trng_tero_cnt_sel.d32;
}

/**
 * @brief  Set the value of @ref trng_fro_force_rst.fro_force_rst_n
 * @param  [in]  fro_force_rst_n The value of @ref trng_fro_force_rst.fro_force_rst_n
 */
static inline void hal_set_trng_fro_force_rst_fro_force_rst_n(uint32_t fro_force_rst_n)
{
    trng_fro_force_rst_t trng_fro_force_rst;
    trng_fro_force_rst.d32 = g_trng_v1_regs->trng_fro_force_rst.d32;
    trng_fro_force_rst.b.fro_force_rst_n = fro_force_rst_n;
    g_trng_v1_regs->trng_fro_force_rst.d32 = trng_fro_force_rst.d32;
}

/**
 * @brief  Set the value of @ref trng_fro_sample_clk_sel.fro_sample_clk_sel
 * @param  [in]  fro_sample_clk_sel The value of @ref trng_fro_sample_clk_sel.fro_sample_clk_sel
 */
static inline void hal_set_trng_fro_sample_clk_sel_fro_sample_clk_sel(uint32_t fro_sample_clk_sel)
{
    trng_fro_sample_clk_sel_t trng_fro_sample_clk_sel;
    trng_fro_sample_clk_sel.d32 = g_trng_v1_regs->trng_fro_sample_clk_sel.d32;
    trng_fro_sample_clk_sel.b.fro_sample_clk_sel = fro_sample_clk_sel;
    g_trng_v1_regs->trng_fro_sample_clk_sel.d32 = trng_fro_sample_clk_sel.d32;
}

/**
 * @brief  Set the value of @ref trng_fro_div_cnt.fro_div_cnt
 * @param  [in]  fro_div_cnt The value of @ref trng_fro_div_cnt.fro_div_cnt
 */
static inline void hal_set_trng_fro_div_cnt_fro_div_cnt(uint32_t fro_div_cnt)
{
    trng_fro_div_cnt_t trng_fro_div_cnt;
    trng_fro_div_cnt.d32 = g_trng_v1_regs->trng_fro_div_cnt.d32;
    trng_fro_div_cnt.b.fro_div_cnt = fro_div_cnt;
    g_trng_v1_regs->trng_fro_div_cnt.d32 = trng_fro_div_cnt.d32;
}

/**
 * @brief  Set the value of @ref trng_fro_cnt_sel.fro_cnt_sel
 * @param  [in]  fro_cnt_sel The value of @ref trng_fro_cnt_sel.fro_cnt_sel
 */
static inline void hal_set_trng_frocnt_sel_fro_cnt_sel(uint32_t fro_cnt_sel)
{
    trng_fro_cnt_sel_t trng_fro_cnt_sel;
    trng_fro_cnt_sel.d32 = g_trng_v1_regs->trng_fro_cnt_sel.d32;
    trng_fro_cnt_sel.b.fro_cnt_sel = fro_cnt_sel;
    g_trng_v1_regs->trng_fro_cnt_sel.d32 = trng_fro_cnt_sel.d32;
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
