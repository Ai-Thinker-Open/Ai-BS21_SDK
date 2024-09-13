/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provide PDM V150 register operation API. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-31, Create file. \n
 */
#ifndef HAL_PDM_V150_REGS_OP_H
#define HAL_PDM_V150_REGS_OP_H

#include "hal_pdm_v150_regs_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_pdm_v150_regs_op PDM V150 Regs Operation
 * @ingroup  drivers_hal_pdm
 * @{
 */

#define HAL_PDM_V150_FIFO_OFFSET 0x80
#define HAL_PDM_V150_FIFO_DEEPTH 32

extern uintptr_t g_hal_pdm_regs;

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.pdm_dp_rst_n.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.pdm_dp_rst_n.
 */
static inline void hal_pdm_v150_clk_rst_en_set_pdm_dp_rst_n(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.pdm_dp_rst_n = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.clk_freq_sel.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.clk_freq_sel.
 */
static inline void hal_pdm_v150_clk_rst_en_set_clk_freq_sel(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.clk_freq_sel = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.func_up_en.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.func_up_en.
 */
static inline void hal_pdm_v150_clk_rst_en_set_func_up_en(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.func_up_en = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.dmic_clken.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.dmic_clken.
 */
static inline void hal_pdm_v150_clk_rst_en_set_dmic_clken(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.dmic_clken = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.saradc_clken.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.saradc_clken.
 */
static inline void hal_pdm_v150_clk_rst_en_set_saradc_clken(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.saradc_clken = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.ckdiv_6144k_clken.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.ckdiv_6144k_clken.
 */
static inline void hal_pdm_v150_clk_rst_en_set_ckdiv_6144k_clken(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.ckdiv_6144k_clken = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.up_fifo_clken.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.up_fifo_clken.
 */
static inline void hal_pdm_v150_clk_rst_en_set_up_fifo_clken(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.up_fifo_clken = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.func_up_ch_en_0.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.func_up_ch_en_0.
 */
static inline void hal_pdm_v150_clk_rst_en_set_func_up_ch_en_0(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.func_up_ch_en_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.func_up_ch_en_1.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.func_up_ch_en_1.
 */
static inline void hal_pdm_v150_clk_rst_en_set_func_up_ch_en_1(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.func_up_ch_en_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.cic_clken_0.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.cic_clken_0.
 */
static inline void hal_pdm_v150_clk_rst_en_set_cic_clken_0(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.cic_clken_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.cic_clken_1.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.cic_clken_1.
 */
static inline void hal_pdm_v150_clk_rst_en_set_cic_clken_1(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.cic_clken_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.compd_clken_0.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.compd_clken_0.
 */
static inline void hal_pdm_v150_clk_rst_en_set_compd_clken_0(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.compd_clken_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.compd_clken_1.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.compd_clken_1.
 */
static inline void hal_pdm_v150_clk_rst_en_set_compd_clken_1(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.compd_clken_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.hpf_clken_0.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.hpf_clken_0.
 */
static inline void hal_pdm_v150_clk_rst_en_set_hpf_clken_0(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.hpf_clken_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.hpf_clken_1.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.hpf_clken_1.
 */
static inline void hal_pdm_v150_clk_rst_en_set_hpf_clken_1(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.hpf_clken_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.srcdn_clken_0.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.srcdn_clken_0.
 */
static inline void hal_pdm_v150_clk_rst_en_set_srcdn_clken_0(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.srcdn_clken_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_clk_rst_en_data.srcdn_clken_1.
 * @param  [in]  val The value of @ref pdm_v150_clk_rst_en_data.srcdn_clken_1.
 */
static inline void hal_pdm_v150_clk_rst_en_set_srcdn_clken_1(uint32_t val)
{
    pdm_v150_clk_rst_en_data_t clk_rst_en;
    clk_rst_en.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en;
    clk_rst_en.b.srcdn_clken_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->clk_rst_en = clk_rst_en.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_ch_ctrl_data.mic_sel.
 * @param  [in]  val The value of @ref pdm_v150_ch_ctrl_data.mic_sel.
 */
static inline void hal_pdm_v150_ch_ctrl_set_mic_sel(uint32_t val)
{
    pdm_v150_ch_ctrl_data_t ch_ctrl;
    ch_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->ch_ctrl;
    ch_ctrl.b.mic_sel = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->ch_ctrl = ch_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_ch_ctrl_data.up_fs_sel_0.
 * @param  [in]  val The value of @ref pdm_v150_ch_ctrl_data.up_fs_sel_0.
 */
static inline void hal_pdm_v150_ch_ctrl_set_up_fs_sel_0(uint32_t val)
{
    pdm_v150_ch_ctrl_data_t ch_ctrl;
    ch_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->ch_ctrl;
    ch_ctrl.b.up_fs_sel_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->ch_ctrl = ch_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_ch_ctrl_data.up_fs_sel_1.
 * @param  [in]  val The value of @ref pdm_v150_ch_ctrl_data.up_fs_sel_1.
 */
static inline void hal_pdm_v150_ch_ctrl_set_up_fs_sel_1(uint32_t val)
{
    pdm_v150_ch_ctrl_data_t ch_ctrl;
    ch_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->ch_ctrl;
    ch_ctrl.b.up_fs_sel_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->ch_ctrl = ch_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_mic_ctrl_data.dmic_clk_sel.
 * @param  [in]  val The value of @ref pdm_v150_mic_ctrl_data.dmic_clk_sel.
 */
static inline void hal_pdm_v150_mic_ctrl_set_dmic_clk_sel(uint32_t val)
{
    pdm_v150_mic_ctrl_data_t mic_ctrl;
    mic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl;
    mic_ctrl.b.dmic_clk_sel = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl = mic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_mic_ctrl_data.dmic_mode.
 * @param  [in]  val The value of @ref pdm_v150_mic_ctrl_data.dmic_mode.
 */
static inline void hal_pdm_v150_mic_ctrl_set_dmic_mode(uint32_t val)
{
    pdm_v150_mic_ctrl_data_t mic_ctrl;
    mic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl;
    mic_ctrl.b.dmic_mode = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl = mic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_mic_ctrl_data.dmic_reverse.
 * @param  [in]  val The value of @ref pdm_v150_mic_ctrl_data.dmic_reverse.
 */
static inline void hal_pdm_v150_mic_ctrl_set_dmic_reverse(uint32_t val)
{
    pdm_v150_mic_ctrl_data_t mic_ctrl;
    mic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl;
    mic_ctrl.b.dmic_reverse = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl = mic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_mic_ctrl_data.saradc_gain.
 * @param  [in]  val The value of @ref pdm_v150_mic_ctrl_data.saradc_gain.
 */
static inline void hal_pdm_v150_mic_ctrl_set_saradc_gain(uint32_t val)
{
    pdm_v150_mic_ctrl_data_t mic_ctrl;
    mic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl;
    mic_ctrl.b.saradc_gain = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->mic_ctrl = mic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_cic_ctrl_data.cic_en_0.
 * @param  [in]  val The value of @ref pdm_v150_cic_ctrl_data.cic_en_0.
 */
static inline void hal_pdm_v150_cic_ctrl_set_cic_en_0(uint32_t val)
{
    pdm_v150_cic_ctrl_data_t cic_ctrl;
    cic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl;
    cic_ctrl.b.cic_en_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl = cic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_cic_ctrl_data.cic_en_1.
 * @param  [in]  val The value of @ref pdm_v150_cic_ctrl_data.cic_en_1.
 */
static inline void hal_pdm_v150_cic_ctrl_set_cic_en_1(uint32_t val)
{
    pdm_v150_cic_ctrl_data_t cic_ctrl;
    cic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl;
    cic_ctrl.b.cic_en_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl = cic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_cic_ctrl_data.cic_gain_0.
 * @param  [in]  val The value of @ref pdm_v150_cic_ctrl_data.cic_gain_0.
 */
static inline void hal_pdm_v150_cic_ctrl_set_cic_gain_0(uint32_t val)
{
    pdm_v150_cic_ctrl_data_t cic_ctrl;
    cic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl;
    cic_ctrl.b.cic_gain_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl = cic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_cic_ctrl_data.cic_gain_1.
 * @param  [in]  val The value of @ref pdm_v150_cic_ctrl_data.cic_gain_1.
 */
static inline void hal_pdm_v150_cic_ctrl_set_cic_gain_1(uint32_t val)
{
    pdm_v150_cic_ctrl_data_t cic_ctrl;
    cic_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl;
    cic_ctrl.b.cic_gain_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->cic_ctrl = cic_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_compd_ctrl_data.compd_bypass_en_0.
 * @param  [in]  val The value of @ref pdm_v150_compd_ctrl_data.compd_bypass_en_0.
 */
static inline void hal_pdm_v150_compd_ctrl_set_compd_bypass_en_0(uint32_t val)
{
    pdm_v150_compd_ctrl_data_t compd_ctrl;
    compd_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->compd_ctrl;
    compd_ctrl.b.compd_bypass_en_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->compd_ctrl = compd_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_compd_ctrl_data.compd_bypass_en_1.
 * @param  [in]  val The value of @ref pdm_v150_compd_ctrl_data.compd_bypass_en_1.
 */
static inline void hal_pdm_v150_compd_ctrl_set_compd_bypass_en_1(uint32_t val)
{
    pdm_v150_compd_ctrl_data_t compd_ctrl;
    compd_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->compd_ctrl;
    compd_ctrl.b.compd_bypass_en_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->compd_ctrl = compd_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_hpf_ctrl_data.hpf_bypass_en.
 * @param  [in]  mic The mic need to configure.
 * @param  [in]  val The value of @ref pdm_v150_hpf_ctrl_data.hpf_bypass_en.
 */
static inline void hal_pdm_v150_hpf_ctrl_set_hpf_bypass_en(uint8_t mic, uint32_t val)
{
    pdm_v150_hpf_ctrl_data_t hpf_ctrl;
    hpf_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->hpf_ctrl[mic];
    hpf_ctrl.b.hpf_bypass_en = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->hpf_ctrl[mic] = hpf_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_hpf_ctrl_data.hpf_fs_sel.
 * @param  [in]  mic The mic need to configure.
 * @param  [in]  val The value of @ref pdm_v150_hpf_ctrl_data.hpf_fs_sel.
 */
static inline void hal_pdm_v150_hpf_ctrl_set_hpf_fs_sel(uint8_t mic, uint32_t val)
{
    pdm_v150_hpf_ctrl_data_t hpf_ctrl;
    hpf_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->hpf_ctrl[mic];
    hpf_ctrl.b.hpf_fs_sel = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->hpf_ctrl[mic] = hpf_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_hpf_ctrl_data.hpf_adc_dc.
 * @param  [in]  mic The mic need to configure.
 * @param  [in]  val The value of @ref pdm_v150_hpf_ctrl_data.hpf_adc_dc.
 */
static inline void hal_pdm_v150_hpf_ctrl_set_hpf_adc_dc(uint8_t mic, uint32_t val)
{
    pdm_v150_hpf_ctrl_data_t hpf_ctrl;
    hpf_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->hpf_ctrl[mic];
    hpf_ctrl.b.hpf_adc_dc = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->hpf_ctrl[mic] = hpf_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_srcdn_ctrl_data.srcdn_bypass_en_0.
 * @param  [in]  val The value of @ref pdm_v150_srcdn_ctrl_data.srcdn_bypass_en_0.
 */
static inline void hal_pdm_v150_srcdn_ctrl_set_srcdn_bypass_en_0(uint32_t val)
{
    pdm_v150_srcdn_ctrl_data_t srcdn_ctrl;
    srcdn_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl;
    srcdn_ctrl.b.srcdn_bypass_en_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl = srcdn_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_srcdn_ctrl_data.srcdn_bypass_en_1.
 * @param  [in]  val The value of @ref pdm_v150_srcdn_ctrl_data.srcdn_bypass_en_1.
 */
static inline void hal_pdm_v150_srcdn_ctrl_set_srcdn_bypass_en_1(uint32_t val)
{
    pdm_v150_srcdn_ctrl_data_t srcdn_ctrl;
    srcdn_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl;
    srcdn_ctrl.b.srcdn_bypass_en_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl = srcdn_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_srcdn_ctrl_data.srcdn_mode_0.
 * @param  [in]  val The value of @ref pdm_v150_srcdn_ctrl_data.srcdn_mode_0.
 */
static inline void hal_pdm_v150_srcdn_ctrl_set_srcdn_mode_0(uint32_t val)
{
    pdm_v150_srcdn_ctrl_data_t srcdn_ctrl;
    srcdn_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl;
    srcdn_ctrl.b.srcdn_mode_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl = srcdn_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_srcdn_ctrl_data.srcdn_mode_1.
 * @param  [in]  val The value of @ref pdm_v150_srcdn_ctrl_data.srcdn_mode_1.
 */
static inline void hal_pdm_v150_srcdn_ctrl_set_srcdn_mode_1(uint32_t val)
{
    pdm_v150_srcdn_ctrl_data_t srcdn_ctrl;
    srcdn_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl;
    srcdn_ctrl.b.srcdn_mode_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl = srcdn_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_srcdn_ctrl_data.srcdn_fifo_clr_0.
 * @param  [in]  val The value of @ref pdm_v150_srcdn_ctrl_data.srcdn_fifo_clr_0.
 */
static inline void hal_pdm_v150_srcdn_ctrl_set_srcdn_fifo_clr_0(uint32_t val)
{
    pdm_v150_srcdn_ctrl_data_t srcdn_ctrl;
    srcdn_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl;
    srcdn_ctrl.b.srcdn_fifo_clr_0 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl = srcdn_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_srcdn_ctrl_data.srcdn_fifo_clr_1.
 * @param  [in]  val The value of @ref pdm_v150_srcdn_ctrl_data.srcdn_fifo_clr_1.
 */
static inline void hal_pdm_v150_srcdn_ctrl_set_srcdn_fifo_clr_1(uint32_t val)
{
    pdm_v150_srcdn_ctrl_data_t srcdn_ctrl;
    srcdn_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl;
    srcdn_ctrl.b.srcdn_fifo_clr_1 = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->srcdn_ctrl = srcdn_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_ctrl_data.up_fifo_aempty_th.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_ctrl_data.up_fifo_aempty_th.
 */
static inline void hal_pdm_v150_up_fifo_ctrl_set_up_fifo_aempty_th(uint32_t val)
{
    pdm_v150_up_fifo_ctrl_data_t up_fifo_ctrl;
    up_fifo_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_ctrl;
    up_fifo_ctrl.b.up_fifo_aempty_th = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_ctrl = up_fifo_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_ctrl_data.up_fifo_afull_th.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_ctrl_data.up_fifo_afull_th.
 */
static inline void hal_pdm_v150_up_fifo_ctrl_set_up_fifo_afull_th(uint32_t val)
{
    pdm_v150_up_fifo_ctrl_data_t up_fifo_ctrl;
    up_fifo_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_ctrl;
    up_fifo_ctrl.b.up_fifo_afull_th = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_ctrl = up_fifo_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_full_int_en.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_full_int_en.
 */
static inline void hal_pdm_v150_up_fifo_st_ctrl_set_up_fifo_full_int_en(uint32_t val)
{
    pdm_v150_up_fifo_st_ctrl_data_t up_fifo_st_ctrl;
    up_fifo_st_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl;
    up_fifo_st_ctrl.b.up_fifo_full_int_en = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl = up_fifo_st_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_afull_int_en.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_afull_int_en.
 */
static inline void hal_pdm_v150_up_fifo_st_ctrl_set_up_fifo_afull_int_en(uint32_t val)
{
    pdm_v150_up_fifo_st_ctrl_data_t up_fifo_st_ctrl;
    up_fifo_st_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl;
    up_fifo_st_ctrl.b.up_fifo_afull_int_en = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl = up_fifo_st_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_empty_int_en.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_empty_int_en.
 */
static inline void hal_pdm_v150_up_fifo_st_ctrl_set_up_fifo_empty_int_en(uint32_t val)
{
    pdm_v150_up_fifo_st_ctrl_data_t up_fifo_st_ctrl;
    up_fifo_st_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl;
    up_fifo_st_ctrl.b.up_fifo_empty_int_en = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl = up_fifo_st_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_aempty_int_en.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_ctrl_data.up_fifo_aempty_int_en.
 */
static inline void hal_pdm_v150_up_fifo_st_ctrl_set_up_fifo_aempty_int_en(uint32_t val)
{
    pdm_v150_up_fifo_st_ctrl_data_t up_fifo_st_ctrl;
    up_fifo_st_ctrl.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl;
    up_fifo_st_ctrl.b.up_fifo_aempty_int_en = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_ctrl = up_fifo_st_ctrl.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_full_int_clr.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_full_int_clr.
 */
static inline void hal_pdm_v150_up_fifo_st_clr_set_up_fifo_full_int_clr(uint32_t val)
{
    pdm_v150_up_fifo_st_clr_data_t up_fifo_st_clr;
    up_fifo_st_clr.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr;
    up_fifo_st_clr.b.up_fifo_full_int_clr = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr = up_fifo_st_clr.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_afull_int_clr.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_afull_int_clr.
 */
static inline void hal_pdm_v150_up_fifo_st_clr_set_up_fifo_afull_int_clr(uint32_t val)
{
    pdm_v150_up_fifo_st_clr_data_t up_fifo_st_clr;
    up_fifo_st_clr.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr;
    up_fifo_st_clr.b.up_fifo_afull_int_clr = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr = up_fifo_st_clr.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_empty_int_clr.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_empty_int_clr.
 */
static inline void hal_pdm_v150_up_fifo_st_clr_set_up_fifo_empty_int_clr(uint32_t val)
{
    pdm_v150_up_fifo_st_clr_data_t up_fifo_st_clr;
    up_fifo_st_clr.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr;
    up_fifo_st_clr.b.up_fifo_empty_int_clr = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr = up_fifo_st_clr.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_aempty_int_clr.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_aempty_int_clr.
 */
static inline void hal_pdm_v150_up_fifo_st_clr_set_up_fifo_aempty_int_clr(uint32_t val)
{
    pdm_v150_up_fifo_st_clr_data_t up_fifo_st_clr;
    up_fifo_st_clr.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr;
    up_fifo_st_clr.b.up_fifo_aempty_int_clr = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr = up_fifo_st_clr.d32;
}

/**
 * @brief  Set the value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_clr.
 * @param  [in]  val The value of @ref pdm_v150_up_fifo_st_clr_data.up_fifo_clr.
 */
static inline void hal_pdm_v150_up_fifo_st_clr_set_up_fifo_clr(uint32_t val)
{
    pdm_v150_up_fifo_st_clr_data_t up_fifo_st_clr;
    up_fifo_st_clr.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr;
    up_fifo_st_clr.b.up_fifo_clr = val;
    ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st_clr = up_fifo_st_clr.d32;
}

/**
 * @brief  Get the value of @ref pdm_v150_up_fifo_st_data.up_fifo_full_int.
 * @return The value of @ref pdm_v150_up_fifo_st_data.up_fifo_full_int.
 */
static inline uint32_t hal_pdm_v150_up_fifo_st_get_up_fifo_full_int(void)
{
    pdm_v150_up_fifo_st_data_t up_fifo_st;
    up_fifo_st.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st;
    return up_fifo_st.b.up_fifo_full_int;
}

/**
 * @brief  Get the value of @ref pdm_v150_up_fifo_st_data.up_fifo_afull_int.
 * @return The value of @ref pdm_v150_up_fifo_st_data.up_fifo_afull_int.
 */
static inline uint32_t hal_pdm_v150_up_fifo_st_get_up_fifo_afull_int(void)
{
    pdm_v150_up_fifo_st_data_t up_fifo_st;
    up_fifo_st.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st;
    return up_fifo_st.b.up_fifo_afull_int;
}

/**
 * @brief  Get the value of @ref pdm_v150_up_fifo_st_data.up_fifo_empty_int.
 * @return The value of @ref pdm_v150_up_fifo_st_data.up_fifo_empty_int.
 */
static inline uint32_t hal_pdm_v150_up_fifo_st_get_up_fifo_empty_int(void)
{
    pdm_v150_up_fifo_st_data_t up_fifo_st;
    up_fifo_st.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st;
    return up_fifo_st.b.up_fifo_empty_int;
}

/**
 * @brief  Get the value of @ref pdm_v150_up_fifo_st_data.up_fifo_aempty_int.
 * @return The value of @ref pdm_v150_up_fifo_st_data.up_fifo_aempty_int.
 */
static inline uint32_t hal_pdm_v150_up_fifo_st_get_up_fifo_aempty_int(void)
{
    pdm_v150_up_fifo_st_data_t up_fifo_st;
    up_fifo_st.d32 = ((pdm_v150_regs_t *)g_hal_pdm_regs)->up_fifo_st;
    return up_fifo_st.b.up_fifo_aempty_int;
}

/**
 * @brief  Get the FIFO address of PDM.
 */
static inline uintptr_t hal_pdm_v150_fifo_get_addr(void)
{
    return g_hal_pdm_regs + HAL_PDM_V150_FIFO_OFFSET;
}

/**
 * @brief  Get the FIFO deepth of PDM.
 */
static inline uint32_t hal_pdm_v150_fifo_get_deepth(void)
{
    return HAL_PDM_V150_FIFO_DEEPTH;
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