/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides v150 keyscan register operation api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16， Create file. \n
 */
#ifndef HAL_KEYSCAN_V150_REGS_OP_H
#define HAL_KEYSCAN_V150_REGS_OP_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "securec.h"
#include "hal_keyscan_v150_regs_def.h"
#include "keyscan_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_keyscan_v150_regs_op Keyscan V150 Regs Operation
 * @ingroup  drivers_hal_keyscan
 * @{
 */

extern keyscan_regs_t *g_keyscan_regs;

/**
 * @brief  Init the keyscan which will set the base address of registers.
 */
void hal_keyscan_v150_regs_init(void);

/**
 * @brief  Soft reset keyscan module.
 */
void hal_keyscan_soft_rst(void);

#if defined (CONFIG_KEYSCAN_USE_LP)
/**
 * @brief  Control the enable of keyscan interrupt in sleep mode.
 * @param  [in]  en 1 means enable the key_int_lp_int_en, 0 means disable the key_int_lp_int_en.
 */
void hal_keyscan_regs_set_key_int_lp_en(bool en);

/**
 * @brief  Set the value of @ref keyscan_int_en_data_t.
 * @param  [in]  en 1 means enable the clk_key_h, 0 means disable the clk_key_h.
 */
void hal_keyscan_regs_set_clk_key_h_en(bool en);
#endif

#if defined (CONFIG_KEYSCAN_SUPPORT_SLEEP)
/**
 * @brief  Set the keyscan sleep require.
 * @param  [in]  en 1 means set the keyscan sleep require, 0 means clear the keyscan sleep require.
 */
void hal_keyscan_regs_set_slp_req(bool en);

/**
 * @brief  Get the step status of keyscan sleep progress.
 * @param  [in]  slp_step The step of keyscan sleep progress.
 * @return The value of @ref keyscan_lp_ctl_data_t.d32
 */
uint32_t hal_keyscan_regs_get_slp_step_sta(uint32_t slp_step);
#endif

/**
 * @brief  Choose to switch the keyscan clock to 32k or not.
 * @param  [in]  en 1 means switch the clock to 32k, 0 means not to do.
 */
void hal_keyscan_regs_set_clk_keep(bool en);

/**
 * @brief  Set the value of @ref keyscan_de_data_t.key_num_sel.
 * @param  [in]  sel The num of coordinates that can be identified by once scanning.
                 @ref keyscan_de_data_t.key_num_sel
 */
void hal_keyscan_config_key_select_num(uint32_t sel);

/**
 * @brief  Set the value of @ref keyscan_enable_data_t.ena.
 * @param  [in]  num 1 means the module enters the working state, 0 means doesn't. @ref keyscan_enable_data_t.ena
 */
static inline void hal_keyscan_regs_set_enable(uint32_t num)
{
    keyscan_enable_data_t keyscan_enable;
    keyscan_enable.d32 = g_keyscan_regs->keyscan_enable;
    keyscan_enable.b.ena = num;
    g_keyscan_regs->keyscan_enable = keyscan_enable.d32;
}

/**
 * @brief  Set the value of @ref keyscan_clk_ena_data_t.fifo_rd_clken.
 * @param  [in]  num 1 means enable the read clock controller for asynchronous fifo, 0 means doesn't.
                 @ref keyscan_clk_ena_data_t.fifo_rd_clken
 */
static inline void hal_keyscan_regs_set_clk_ena(uint32_t num)
{
    keyscan_clk_ena_data_t keyscan_clk_ena;
    keyscan_clk_ena.d32 = g_keyscan_regs->keyscan_clk_ena;
    keyscan_clk_ena.b.fifo_rd_clken = num;
    g_keyscan_regs->keyscan_clk_ena = keyscan_clk_ena.d32;
}

/**
 * @brief  Set the value of @ref keyscan_start_data_t.task_start.
 */
static inline void hal_keyscan_regs_set_start(void)
{
    keyscan_start_data_t keyscan_start;
    keyscan_start.d32 = g_keyscan_regs->keyscan_start;
    keyscan_start.b.task_start = 1;
    g_keyscan_regs->keyscan_start = keyscan_start.d32;
}

/**
 * @brief  Set the value of @ref keyscan_int_en_data_t.
 * @param  [in]  int_type Int to enable. @ref keyscan_int_en_data_t
 */
static inline void hal_keyscan_enable_int(uint32_t int_type)
{
    keyscan_int_en_data_t keyscan_int_en;
    keyscan_int_en.d32 = g_keyscan_regs->keyscan_int_en;
    keyscan_int_en.d32 = int_type;
    g_keyscan_regs->keyscan_int_en = keyscan_int_en.d32;
}

/**
 * @brief  Get the value of @ref keyscan_int_en_data_t.d32.
 * @return The total value of @ref keyscan_int_en_data_t.d32
 */
static inline uint32_t hal_keyscan_get_enabled_int_val(void)
{
    keyscan_int_en_data_t keyscan_int_en;
    keyscan_int_en.d32 = g_keyscan_regs->keyscan_int_en;
    g_keyscan_regs->keyscan_int_en = keyscan_int_en.d32;
    return keyscan_int_en.d32;
}

/**
 * @brief  Set the value of @ref keyscan_event_clr_data_t.
 * @param  [in]  event Int to clear. @ref keyscan_event_clr_data_t
 */
static inline void hal_keyscan_clr_int(uint32_t event)
{
    keyscan_event_clr_data_t keyscan_event_clr;
    keyscan_event_clr.d32 = g_keyscan_regs->keyscan_event_clr;
    keyscan_event_clr.d32 = event;
    g_keyscan_regs->keyscan_event_clr = keyscan_event_clr.d32;
}

/**
 * @brief  Get the value of @ref keyscan_int_en_data_t.d32.
 * @param  [in]  event  Event to check.
 * @return The value of @ref keyscan_int_en_data_t.d32
 */
static inline uint32_t hal_keyscan_int_enable_check(uint32_t event)
{
    keyscan_int_en_data_t keyscan_int_en;
    keyscan_int_en.d32 = g_keyscan_regs->keyscan_int_en;
    g_keyscan_regs->keyscan_int_en = keyscan_int_en.d32;
    return (keyscan_int_en.d32 >> event) & 1U;
}

/**
 * @brief  Get the value of @ref keyscan_event_sts_data_t.d32.
 * @param  [in]  event Event to check.
 * @return The value of @ref keyscan_event_sts_data_t.d32
 */
static inline uint32_t hal_keyscan_int_check(uint32_t event)
{
    keyscan_event_sts_data_t keyscan_event_sts;
    keyscan_event_sts.d32 = g_keyscan_regs->keyscan_event_sts;
    g_keyscan_regs->keyscan_event_sts = keyscan_event_sts.d32;
    return (keyscan_event_sts.d32 >> event) & 1U;
}

/**
 * @brief  Set the value of @ref keyscan_pin_num_data_t.row_pin_en, @ref keyscan_pin_num_data_t.clo_pin_en.
 * @note   Valid value of row is from 0x0 to 0xf. Valid value of column is from 0x0 to 0xf.
           Invalid value will disable all rows or columns.
 * @param  [in]  row Rows to enable. @ref keyscan_pin_num_data_t.row_pin_en
 * @param  [in]  col Columns to enable. @ref keyscan_pin_num_data_t.clo_pin_en
 */
static inline void hal_keyscan_pin_enable(uint8_t row, uint8_t col)
{
    keyscan_pin_num_data_t keyscan_pin_num;
    keyscan_pin_num.d32 = g_keyscan_regs->keyscan_pin_num;
    keyscan_pin_num.b.row_pin_en = (uint32_t)row;
    keyscan_pin_num.b.clo_pin_en = (uint32_t)col;
    g_keyscan_regs->keyscan_pin_num = keyscan_pin_num.d32;
}

/**
 * @brief  Get the value of @ref keyscan_pin_num_data_t.row_pin_en.
 * @return The total value of @ref keyscan_pin_num_data_t.row_pin_en
 */
static inline uint32_t hal_keyscan_get_row_pin_enable(void)
{
    keyscan_pin_num_data_t keyscan_pin_num;
    keyscan_pin_num.d32 = g_keyscan_regs->keyscan_pin_num;
    g_keyscan_regs->keyscan_pin_num = keyscan_pin_num.d32;
    return keyscan_pin_num.b.row_pin_en;
}

/**
 * @brief  Get the value of @ref keyscan_pin_num_data_t.clo_pin_en.
 * @return The total value of @ref keyscan_pin_num_data_t.clo_pin_en
 */
static inline uint32_t hal_keyscan_get_clo_pin_enable(void)
{
    keyscan_pin_num_data_t keyscan_pin_num;
    keyscan_pin_num.d32 = g_keyscan_regs->keyscan_pin_num;
    g_keyscan_regs->keyscan_pin_num = keyscan_pin_num.d32;
    return keyscan_pin_num.b.clo_pin_en;
}

/**
 * @brief  Get the value of @ref key_value_fifo_data_t.key_value.
 * @return The value of @ref key_value_fifo_data_t.key_value, when fifo is empty, return 0x0FF.
 */
static inline uint16_t hal_keyscan_get_key_value(void)
{
    key_value_fifo_data_t key_value_fifo;
    key_value_fifo.d32 = g_keyscan_regs->key_value_fifo;
    return (uint16_t)key_value_fifo.b.key_value;
}

/**
 * @brief  Set the value of @ref keyscan_mode_data_t.scan_dir.
 * @param  [in]  dir 0 means ROW_SCAN, 1 means COL_SCAN. @ref keyscan_mode_data_t.scan_dir
 */
static inline void hal_keyscan_config_direction(uint32_t dir)
{
    keyscan_mode_data_t keyscan_mode;
    keyscan_mode.d32 = g_keyscan_regs->keyscan_mode;
    keyscan_mode.b.scan_dir = dir;
    g_keyscan_regs->keyscan_mode = keyscan_mode.d32;
}

/**
 * @brief  Set the value of @ref keyscan_mode_data_t.scan_mode.
 * @param  [in]  sc_mo Scan mode to config. @ref keyscan_mode_data_t.scan_mode
 */
static inline void hal_keyscan_config_mode(uint32_t sc_mo)
{
    keyscan_mode_data_t keyscan_mode;
    keyscan_mode.d32 = g_keyscan_regs->keyscan_mode;
    keyscan_mode.b.scan_mode = sc_mo;
    g_keyscan_regs->keyscan_mode = keyscan_mode.d32;
}

/**
 * @brief  Set the value of @ref keyscan_pulse_data_t.tpulse.
 * @param  [in]  pul Duration of the keyscan_pulse when scanning each line (depending on the load).
                 @ref keyscan_pulse_data_t.tpulse
 */
static inline void hal_keyscan_config_pulse_time(uint32_t pul)
{
    keyscan_pulse_data_t keyscan_pulse;
    keyscan_pulse.d32 = g_keyscan_regs->keyscan_pulse;
    keyscan_pulse.b.tpulse = pul;
    g_keyscan_regs->keyscan_pulse = keyscan_pulse.d32;
}

/**
 * @brief  Set the value of @ref keyscan_pulse_data_t.ttern.
 * @param  [in]  wait Wait time when scanning column/row switch, complete the row-to-col switching during this time.
                 @ref keyscan_pulse_data_t.ttern
 */
static inline void hal_keyscan_config_wait_time(uint32_t wait)
{
    keyscan_pulse_data_t keyscan_pulse;
    keyscan_pulse.d32 = g_keyscan_regs->keyscan_pulse;
    keyscan_pulse.b.ttern = wait;
    g_keyscan_regs->keyscan_pulse = keyscan_pulse.d32;
}

/**
 * @brief  Set the value of @ref keyscan_pulse_data_t.tidle.
 * @note   Config value not in hal_keyscan_idle_time_t will set idle time as 10ms.
 * @param  [in]  idle Key scan idle in the time, and the pin returns to the initial state.
                 @ref keyscan_pulse_data_t.tidle
 */
static inline void hal_keyscan_config_idle_time(uint32_t idle)
{
    keyscan_pulse_data_t keyscan_pulse;
    keyscan_pulse.d32 = g_keyscan_regs->keyscan_pulse;
    keyscan_pulse.b.tidle = idle;
    g_keyscan_regs->keyscan_pulse = keyscan_pulse.d32;
}

/**
 * @brief  Set the value of @ref keyscan_de_data_t.scan_num.
 * @param  [in]  def Scan defen-jitter nums. @ref keyscan_de_data_t.scan_num
 */
static inline void hal_keyscan_config_defence_num(uint32_t def)
{
    keyscan_de_data_t keyscan_de;
    keyscan_de.d32 = g_keyscan_regs->keyscan_de;
    keyscan_de.b.scan_num = def;
    g_keyscan_regs->keyscan_de = keyscan_de.d32;
}

/**
 * @brief  Set the value of @ref keyscan_de_data_t.ghost.
 * @param  [in]  gho 1 means enable the ghost check. 0 means do not enable the ghost check.
                 @ref keyscan_de_data_t.ghost
 */
static inline void hal_keyscan_config_ghost_check(bool gho)
{
    keyscan_de_data_t keyscan_de;
    keyscan_de.d32 = g_keyscan_regs->keyscan_de;
    keyscan_de.b.ghost = gho;
    g_keyscan_regs->keyscan_de = keyscan_de.d32;
}

/**
 * @brief  Set the value of @ref keyscan_de_data_t.io_de.
 * @param  [in]  iode Enable the I/O port defen-jitter function and filter out glitch signals less than 1 us.
                 @ref keyscan_de_data_t.io_de
 */
static inline void hal_keyscan_config_io_de(bool iode)
{
    keyscan_de_data_t keyscan_de;
    keyscan_de.d32 = g_keyscan_regs->keyscan_de;
    keyscan_de.b.io_de = iode;
    g_keyscan_regs->keyscan_de = keyscan_de.d32;
}

/**
 * @brief  Enable @ref keyscan_de_data_t.rep_all_key.
 */
static inline void hal_keyscan_control_key_all_report(void)
{
    keyscan_de_data_t keyscan_de;
    keyscan_de.d32 = g_keyscan_regs->keyscan_de;
    keyscan_de.b.rep_all_key = 1;
    g_keyscan_regs->keyscan_de = keyscan_de.d32;
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