/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides V150 qdec register operation api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-17， Create file. \n
 */
#ifndef HAL_QDEC_V150_REGS_OP_H
#define HAL_QDEC_V150_REGS_OP_H

#include <stdint.h>
#include <stdbool.h>
#include "errcode.h"
#include "hal_qdec_v150_regs_def.h"
#include "qdec_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_qdec_v150_regs_op QDEC V150 Regs Operation
 * @ingroup  drivers_hal_qdec
 * @{
 */

extern qdec_regs_t *g_qdec_regs;
extern qdec_regs_clk_div_t *g_qdec_regs_clk_div;

#define QDEC_LED_NOT_CONNECTED  0xFFFFFFFF

/**
 * @brief  Init the qdec which will set the base address of registers.
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 */
errcode_t hal_qdec_v150_regs_init(void);

/**
 * @brief  Deinit the hal_qdec which will clear the base address of registers has been
 *         set by @ref hal_qdec_v150_regs_init.
 */
void hal_qdec_v150_regs_deinit(void);

/**
 * @brief  Soft reset.
 */
void hal_qdec_v150_regs_soft_rst(void);

/**
 * @brief  Set the value of @ref qdec_clk_div.num.
 * @param  [in]  div_num The value of @ref qdec_clk_div.num.
 */
static inline void hal_qdec_v150_regs_set_clk_div_num(uint32_t div_num)
{
    qdec_clk_div_t qdec_clk_div;
    qdec_clk_div.d32 = g_qdec_regs_clk_div->qdec_clk_div;
    qdec_clk_div.b.num = div_num;
    g_qdec_regs_clk_div->qdec_clk_div = qdec_clk_div.d32;
}

/**
 * @brief  Set the value of @ref qdec_clk_div.en.
 * @param  [in]  en The value of @ref qdec_clk_div.en and qdec_clk_div.load_en.
 */
static inline void hal_qdec_v150_regs_set_clk_div_en(bool en)
{
    qdec_clk_div_t qdec_clk_div;
    qdec_clk_div.d32 = g_qdec_regs_clk_div->qdec_clk_div;
    qdec_clk_div.b.en = en;
    qdec_clk_div.b.load_en = en;
    g_qdec_regs_clk_div->qdec_clk_div = qdec_clk_div.d32;
}

/**
 * @brief  Clear the value of @ref qdec_clk_ctl.sel.
 */
static inline void hal_qdec_v150_regs_clr_clk_ctl_sel(void)
{
    qdec_clk_ctl_t qdec_clk_ctl;
    qdec_clk_ctl.d32 = g_qdec_regs->qdec_clk_ctl;
    qdec_clk_ctl.b.sel = 0;
    g_qdec_regs->qdec_clk_ctl = qdec_clk_ctl.d32;
}

/**
 * @brief  Set the value of @ref qdec_clk_ctl.en.
 */
static inline void hal_qdec_v150_regs_set_clk_ctl_en(void)
{
    qdec_clk_ctl_t qdec_clk_ctl;
    qdec_clk_ctl.d32 = g_qdec_regs->qdec_clk_ctl;
    qdec_clk_ctl.b.en = 1;
    g_qdec_regs->qdec_clk_ctl = qdec_clk_ctl.d32;
}

/**
 * @brief  Set the value of @ref qdec_soft_rst.soft_rst.
 */
static inline void hal_qdec_v150_regs_set_soft_rst(void)
{
    qdec_soft_rst_t qdec_soft_rst;
    qdec_soft_rst.d32 = g_qdec_regs->qdec_soft_rst;
    qdec_soft_rst.b.soft_rst = 1;
    g_qdec_regs->qdec_soft_rst = qdec_soft_rst.d32;
}

/**
 * @brief  Set the value of @ref qdec_ledpol_data.en.
 */
static inline void hal_qdec_v150_regs_set_ledpol_en(void)
{
    qdec_ledpol_data_t qdec_ledpol_data;
    qdec_ledpol_data.d32 = g_qdec_regs->qdec_ledpol_data;
    qdec_ledpol_data.b.en = 1;
    g_qdec_regs->qdec_ledpol_data = qdec_ledpol_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_ledpol_data.pol.
 * @param  [in]  ledpol The value of @ref qdec_ledpol_data.pol.
 */
static inline void hal_qdec_v150_regs_set_ledpol_pol(hal_qdec_led_pol_t ledpol)
{
    qdec_ledpol_data_t qdec_ledpol_data;
    qdec_ledpol_data.d32 = g_qdec_regs->qdec_ledpol_data;
    qdec_ledpol_data.b.pol = ledpol;
    g_qdec_regs->qdec_ledpol_data = qdec_ledpol_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_ledpre_data.led_pre.
 */
static inline void hal_qdec_v150_regs_set_ledpre(uint32_t ledpre)
{
    qdec_ledpre_data_t qdec_ledpre_data;
    qdec_ledpre_data.d32 = g_qdec_regs->qdec_ledpre_data;
    qdec_ledpre_data.b.led_pre = ledpre;
    g_qdec_regs->qdec_ledpre_data = qdec_ledpre_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_defen_data.en.
 */
static inline void hal_qdec_v150_regs_defen_en(void)
{
    qdec_defen_data_t qdec_defen_data;
    qdec_defen_data.d32 = g_qdec_regs->qdec_defen_data;
    qdec_defen_data.b.en = 1;
    g_qdec_regs->qdec_defen_data = qdec_defen_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_defen_data.defen_num.
 * @param  [in]  defen_num The value of @ref qdec_defen_data.defen_num.
 */
static inline void hal_qdec_v150_regs_defen_num(hal_qdec_defen_num_t defen_num)
{
    qdec_defen_data_t qdec_defen_data;
    qdec_defen_data.d32 = g_qdec_regs->qdec_defen_data;
    qdec_defen_data.b.defen_num = defen_num;
    g_qdec_regs->qdec_defen_data = qdec_defen_data.d32;
}

/**
 * @brief  Clr the value of @ref qdec_ledpre_data.led_pre.
 */
static inline void hal_qdec_v150_regs_defen_off(void)
{
    qdec_defen_data_t qdec_defen_data;
    qdec_defen_data.d32 = g_qdec_regs->qdec_defen_data;
    qdec_defen_data.b.en = 0;
    g_qdec_regs->qdec_defen_data = qdec_defen_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_sampleper_data.period.
 * @param  [in]  sampleper The value of @ref qdec_sampleper_data.period.
 */
static inline void hal_qdec_v150_regs_set_sampleper(hal_qdec_sample_per_t sampleper)
{
    qdec_sampleper_data_t qdec_sampleper_data;
    qdec_sampleper_data.d32 = g_qdec_regs->qdec_sampleper_data;
    qdec_sampleper_data.b.period = sampleper;
    qdec_sampleper_data.b.clk_freq = 1;
    g_qdec_regs->qdec_sampleper_data = qdec_sampleper_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_reporter_data.samlple_repo_val.
 * @param  [in]  reportper The value of @ref qdec_reporter_data.samlple_repo_val.
 */
static inline void hal_qdec_v150_regs_set_reportper(hal_qdec_report_per_t reportper)
{
    qdec_reporter_data_t qdec_reporter_data;
    qdec_reporter_data.d32 = g_qdec_regs->qdec_reporter_data;
    qdec_reporter_data.b.samlple_repo_val = reportper;
    g_qdec_regs->qdec_reporter_data = qdec_reporter_data.d32;
}

/**
 * @brief  Set the value of @ref qdec_enable.en.
 */
static inline void hal_qdec_v150_regs_en(void)
{
    qdec_enable_t qdec_enable;
    qdec_enable.d32 = g_qdec_regs->qdec_enable;
    qdec_enable.b.en = 1;
    g_qdec_regs->qdec_enable = qdec_enable.d32;
}

/**
 * @brief  Clr the value of @ref qdec_enable.en.
 */
static inline void hal_qdec_v150_regs_clr_en(void)
{
    qdec_enable_t qdec_enable;
    qdec_enable.d32 = g_qdec_regs->qdec_enable;
    qdec_enable.b.en = 0;
    g_qdec_regs->qdec_enable = qdec_enable.d32;
}

/**
 * @brief  Set the value of @ref qdec_task_start.start.
 */
static inline void hal_qdec_v150_regs_start(void)
{
    qdec_task_start_t qdec_task_start;
    qdec_task_start.d32 = g_qdec_regs->qdec_task_start;
    qdec_task_start.b.start = 1;
    g_qdec_regs->qdec_task_start = qdec_task_start.d32;
}

/**
 * @brief  Set the value of @ref qdec_task_stop.stop.
 */
static inline void hal_qdec_v150_regs_stop(void)
{
    qdec_task_stop_t qdec_task_stop;
    qdec_task_stop.d32 = g_qdec_regs->qdec_task_stop;
    qdec_task_stop.b.stop = 1;
    g_qdec_regs->qdec_task_stop = qdec_task_stop.d32;
}

/**
 * @brief  Set the value of @ref qdec_int_en.acc_en.
 */
static inline void hal_qdec_v150_regs_set_acc_int_en(void)
{
    qdec_int_en_t qdec_int_en;
    qdec_int_en.d32 = g_qdec_regs->qdec_int_en;
    qdec_int_en.b.acc_en = 1;
    g_qdec_regs->qdec_int_en = qdec_int_en.d32;
}

/**
 * @brief  Set the value of @ref qdec_int_en.dbl_en.
 */
static inline void hal_qdec_v150_regs_set_dbl_int_en(void)
{
    qdec_int_en_t qdec_int_en;
    qdec_int_en.d32 = g_qdec_regs->qdec_int_en;
    qdec_int_en.b.dbl_en = 1;
    g_qdec_regs->qdec_int_en = qdec_int_en.d32;
}

/**
 * @brief  Set the value of @ref qdec_int_en.report_en.
 */
static inline void hal_qdec_v150_regs_set_report_int_en(void)
{
    qdec_int_en_t qdec_int_en;
    qdec_int_en.d32 = g_qdec_regs->qdec_int_en;
    qdec_int_en.b.report_en = 1;
    g_qdec_regs->qdec_int_en = qdec_int_en.d32;
}

/**
 * @brief  Set the value of @ref qdec_int_en.sample_en.
 */
static inline void hal_qdec_v150_regs_set_sample_int_en(void)
{
    qdec_int_en_t qdec_int_en;
    qdec_int_en.d32 = g_qdec_regs->qdec_int_en;
    qdec_int_en.b.sample_en = 1;
    g_qdec_regs->qdec_int_en = qdec_int_en.d32;
}

/**
 * @brief  Get the value of @ref qdec_acc_data.acc_rd_val.
 * @return The value of @ref qdec_acc_data.acc_rd_val.
 */
static inline int16_t hal_qdec_v150_regs_get_acc(void)
{
    qdec_acc_data_t qdec_acc_data;
    qdec_acc_data.d32 = g_qdec_regs->qdec_acc_data;
    return (int16_t)qdec_acc_data.b.acc_rd_val;
}

/**
 * @brief  Get the value of @ref qdec_accdbl_data.dbl_rd_val.
 * @return The value of @ref qdec_accdbl_data.dbl_rd_val.
 */
static inline int16_t hal_qdec_v150_regs_get_accdbl(void)
{
    qdec_accdbl_data_t qdec_accdbl_data;
    qdec_accdbl_data.d32 = g_qdec_regs->qdec_accdbl_data;
    return (int16_t)qdec_accdbl_data.b.dbl_rd_val;
}

/**
 * @brief  Pulse the value of @ref qdec_task_rd_clr_acc.rd_clr_acc.
 */
static inline void hal_qdec_v150_regs_rd_clr_acc(void)
{
    qdec_task_rd_clr_acc_t qdec_task_rd_clr_acc;
    qdec_task_rd_clr_acc.d32 = g_qdec_regs->qdec_task_rd_clr_acc;
    qdec_task_rd_clr_acc.b.rd_clr_acc = 1;
    g_qdec_regs->qdec_task_rd_clr_acc = qdec_task_rd_clr_acc.d32;
}

/**
 * @brief  Pulse the value of @ref qdec_task_rd_clr_dbl.rd_clr_dbl.
 */
static inline void hal_qdec_v150_regs_rd_clr_dbl(void)
{
    qdec_task_rd_clr_dbl_t qdec_task_rd_clr_dbl;
    qdec_task_rd_clr_dbl.d32 = g_qdec_regs->qdec_task_rd_clr_dbl;
    qdec_task_rd_clr_dbl.b.rd_clr_dbl = 1;
    g_qdec_regs->qdec_task_rd_clr_dbl = qdec_task_rd_clr_dbl.d32;
}

/**
 * @brief  Pulse the value of @ref qdec_int_clr.sample_clr.
 */
static inline void hal_qdec_v150_regs_sample_int_clr(void)
{
    qdec_int_clr_t qdec_int_clr;
    qdec_int_clr.d32 = g_qdec_regs->qdec_int_clr;
    qdec_int_clr.b.sample_clr = 1;
    g_qdec_regs->qdec_int_clr = qdec_int_clr.d32;
}

/**
 * @brief  Pulse the value of @ref qdec_int_clr.report_clr.
 */
static inline void hal_qdec_v150_regs_report_int_clr(void)
{
    qdec_int_clr_t qdec_int_clr;
    qdec_int_clr.d32 = g_qdec_regs->qdec_int_clr;
    qdec_int_clr.b.report_clr = 1;
    g_qdec_regs->qdec_int_clr = qdec_int_clr.d32;
}

/**
 * @brief  Pulse the value of @ref qdec_int_clr.dbl_clr.
 */
static inline void hal_qdec_v150_regs_dbl_int_clr(void)
{
    qdec_int_clr_t qdec_int_clr;
    qdec_int_clr.d32 = g_qdec_regs->qdec_int_clr;
    qdec_int_clr.b.dbl_clr = 1;
    g_qdec_regs->qdec_int_clr = qdec_int_clr.d32;
}

/**
 * @brief  Pulse the value of @ref qdec_int_clr.acc_clr.
 */
static inline void hal_qdec_v150_regs_acc_int_clr(void)
{
    qdec_int_clr_t qdec_int_clr;
    qdec_int_clr.d32 = g_qdec_regs->qdec_int_clr;
    qdec_int_clr.b.acc_clr = 1;
    g_qdec_regs->qdec_int_clr = qdec_int_clr.d32;
}

/**
 * @brief  Pulse the value of @ref qdec_int_clr.stop_int_clr.
 */
static inline void hal_qdec_v150_regs_stopped_int_clr(void)
{
    qdec_int_clr_t qdec_int_clr;
    qdec_int_clr.d32 = g_qdec_regs->qdec_int_clr;
    qdec_int_clr.b.stop_int_clr = 1;
    g_qdec_regs->qdec_int_clr = qdec_int_clr.d32;
}

/**
 * @brief  Read the value of @ref qdec_int_en.
 * @param  [in]  event  Corresponding bit of values by @ref qdec_int_en.
 * @return The value of @ref qdec_int_en.
 */
static inline uint32_t hal_qdec_regs_int_enable_check(uint32_t event)
{
    qdec_int_en_t qdec_int_en;
    qdec_int_en.d32 = g_qdec_regs->qdec_int_en;
    g_qdec_regs->qdec_int_en = qdec_int_en.d32;
    return (qdec_int_en.d32 >> event) & 1U;
}

/**
 * @brief  Read the value of @ref qdec_event_int_sts.
 * @param  [in]  event  Corresponding bit of values by @ref qdec_event_int_sts.
 * @return The value of @ref qdec_event_int_sts.
 */
static inline uint32_t hal_qdec_regs_int_event_check(uint32_t event)
{
    qdec_event_int_sts_t qdec_event_int_sts;
    qdec_event_int_sts.d32 = g_qdec_regs->qdec_event_int_sts;
    return (qdec_event_int_sts.d32 >> event) & 1U;
}

/**
 * @brief  Pulse the value of @ref qdec_int_clr.
 * @param  [in]  event  Corresponding bit of values by @ref qdec_int_clr.
 */
static inline void hal_qdec_regs_int_clr(uint8_t event)
{
    qdec_int_clr_t qdec_int_clr;
    qdec_int_clr.d32 = g_qdec_regs->qdec_int_clr;
    qdec_int_clr.d32 |= (1 << event);
    g_qdec_regs->qdec_int_clr = qdec_int_clr.d32;
}

/**
 * @brief  Read the value of @ref qdec_acc_data.
 * @return The value of @ref qdec_acc_data.
 */
static inline int8_t hal_qdec_regs_get_acc(void)
{
    qdec_acc_data_t qdec_acc;
    qdec_acc.d32 = g_qdec_regs->qdec_acc_data;
    return (int8_t)qdec_acc.b.acc_rd_val;
}

/**
 * @brief  Read the value of @ref qdec_acc_read.
 * @return The value of @ref qdec_acc_read.
 */
static inline int8_t hal_qdec_regs_get_accread(void)
{
    while (hal_qdec_regs_get_acc()) { }
    qdec_acc_read_t qdec_acc_read;
    qdec_acc_read.d32 = g_qdec_regs->qdec_acc_read;
    return (int8_t)qdec_acc_read.b.acc_rd_val_shadow;
}

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif