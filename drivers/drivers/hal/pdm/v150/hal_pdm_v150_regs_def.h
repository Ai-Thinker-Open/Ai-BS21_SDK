/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides PDM V150 register. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-31, Create file. \n
 */
#ifndef HAL_PDM_V150_REGS_DEF_H
#define HAL_PDM_V150_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_pdm_v150_regs_def PDM V150 Regs Definition
 * @ingroup  drivers_hal_pdm
 * @{
 */

/**
 * @brief  This union represents the bit fields in the CLK_RST_EN. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_clk_rst_en_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t pdm_dp_rst_n           :   1;  /*!< Reset the digtal channel.
                                                        - 0: Active
                                                        - 1: Inactive */
        uint32_t clk_freq_sel           :   1;  /*!< Configuring the INPUT clock devider.
                                                        - 0: 24/125 (XO: 32MHz)
                                                        - 1: 1/4 (RC: 24.576MHz) */
        uint32_t func_up_en             :   1;  /*!< Enable or disable UP channel.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t dmic_clken             :   1;  /*!< Enable or disable the DMIC clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t saradc_clken           :   1;  /*!< Enable or disable the SAR ADC clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t ckdiv_6144k_clken      :   1;  /*!< Enable or disable the 6.144MHz clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t up_fifo_clken          :   1;  /*!< Enable or disable the UP FIFO clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved7              :   1;
        uint32_t func_up_ch_en_0        :   1;  /*!< Enable or disable the Channel[0/1] clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t cic_clken_0            :   1;  /*!< Enable or disable the CIC clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t compd_clken_0          :   1;  /*!< Enable or disable the COMPD clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t hpf_clken_0            :   1;  /*!< Enable or disable the HPF clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t srcdn_clken_0          :   1;  /*!< Enable or disable the SRCDN clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved13_15          :   3;

        uint32_t func_up_ch_en_1        :   1;  /*!< Enable or disable the Channel[0/1] clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t cic_clken_1            :   1;  /*!< Enable or disable the CIC clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t compd_clken_1          :   1;  /*!< Enable or disable the COMPD clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t hpf_clken_1            :   1;  /*!< Enable or disable the HPF clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t srcdn_clken_1          :   1;  /*!< Enable or disable the SRCDN clock.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved22_24          :   3;

        uint32_t reserved24_31          :   8;
    } b;                                        /*!< Register bits. */
} pdm_v150_clk_rst_en_data_t;

/**
 * @brief  This union represents the bit fields in the CH_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_ch_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t mic_sel                :   1;  /*!< Switch the INPUT MIC source of CH0.
                                                        - 0: DMIC
                                                        - 1: AMIC (SAR MIC) */
        uint32_t reserved1_3            :   3;
        uint32_t up_fs_sel_0            :   1;  /*!< Output audio sampling rate of the uplink channel CH0.
                                                        - 0: 16K
                                                        - 1: 8K */
        uint32_t up_fs_sel_1            :   1;  /*!< Output audio sampling rate of the uplink channel CH1.
                                                        - 0: 16K
                                                        - 1: 8K */
        uint32_t reserved6_31           :  26;
    } b;                                        /*!< Register bits. */
} pdm_v150_ch_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the MIC_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_mic_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t dmic_clk_sel           :   2;  /*!< Select the DMIC sampling clock frequency.
                                                        - 2'b00: 3.072MHz
                                                        - 2'b01: 1.536MHz
                                                        - 2'b10: 0.768MHz
                                                        - Others: 0.768MHz */
        uint32_t dmic_mode              :   1;  /*!< Configuring the DMIC channels.
                                                        - 0: Dont switch the Left and Right channels.
                                                        - 1: Switch the Left and Right channels. */
        uint32_t dmic_reverse           :   1;  /*!< Configuring the DMIC INPUT code.
                                                        - 0: 0 -> +4, 1 -> -4
                                                        - 1: 0 -> -4, 1 -> +4 */
        uint32_t reserved4_7            :   4;
        uint32_t saradc_gain            :   8;  /*!< SAR ADC Channel Digital Gain. */
        uint32_t reserved16_31          :  16;
    } b;                                        /*!< Register bits. */
} pdm_v150_mic_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the CIC_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_cic_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cic_en_0               :   1;  /*!< Enable or disable the DMIC CIC CH0.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t cic_en_1               :   1;  /*!< Enable or disable the DMIC CIC CH1.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved2_7            :   6;
        uint32_t cic_gain_0             :   8;  /*!< DMIC CIC Gain CH0. */
        uint32_t cic_gain_1             :   8;  /*!< DMIC CIC Gain CH1. */
        uint32_t reserved24_31          :   8;
    } b;                                        /*!< Register bits. */
} pdm_v150_cic_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the COMPD_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_compd_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t compd_bypass_en_0      :   1;  /*!< Enable or disable the bypass of compd CH0.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t compd_bypass_en_1      :   1;  /*!< Enable or disable the bypass of compd CH1.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved2_31           :  30;
    } b;                                        /*!< Register bits. */
} pdm_v150_compd_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the HPF_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_hpf_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t hpf_bypass_en          :   1;  /*!< Enable or disable bypass of hpf.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t hpf_fs_sel             :   1;  /*!< HPF Sampling Rate Control.
                                                        - 0: 96KHz
                                                        - 1: 32KHz */
        uint32_t reserved2_7            :   6;
        uint32_t hpf_adc_dc             :  24;  /*!< HPF DC offset configuration. */
    } b;                                        /*!< Register bits. */
} pdm_v150_hpf_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the SRCDN_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_srcdn_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t srcdn_bypass_en_0      :   1;  /*!< Enable or disable the bypass of srcdn CH0.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t srcdn_bypass_en_1      :   1;  /*!< Enable or disable the bypass of srcdn CH1.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved2_3            :   2;
        uint32_t srcdn_mode_0           :   2;  /*!< SRC down-sampling decimation multiple configuration CH0.
                                                     (AMIC: 32KHz, DMIC: 96KHz.)
                                                        - 2'b00: 2x: 32KHz -> 16KHz
                                                        - 2'b01: 4x: 32KHz -> 8KHz
                                                        - 2'b10: 6x: 96KHz -> 16KHz
                                                        - 2'b11: 12x: 96KHz -> 8KHz */
        uint32_t srcdn_mode_1           :   2;  /*!< SRC down-sampling decimation multiple configuration CH1.
                                                     (AMIC: 32KHz, DMIC: 96KHz.)
                                                        - 2'b00: 2x: 32KHz -> 16KHz
                                                        - 2'b01: 4x: 32KHz -> 8KHz
                                                        - 2'b10: 6x: 96KHz -> 16KHz
                                                        - 2'b11: 12x: 96KHz -> 8KHz */
        uint32_t srcdn_fifo_clr_0       :   1;  /*!< FIFO Clear Signal CH0.
                                                        - 0: Dont clear FIFO
                                                        - 1: Clear FIFO */
        uint32_t srcdn_fifo_clr_1       :   1;  /*!< FIFO Clear Signal CH1.
                                                        - 0: Dont clear FIFO
                                                        - 1: Clear FIFO */
        uint32_t reserved10_31          :  22;
    } b;                                        /*!< Register bits. */
} pdm_v150_srcdn_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the UP_FIFO_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_up_fifo_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t up_fifo_aempty_th      :   5;  /*!< FIFO will be empty threshold. */
        uint32_t reserved5_7            :   3;
        uint32_t up_fifo_afull_th       :   5;  /*!< FIFO will be full threshold. */
        uint32_t reserved13_31          :  29;
    } b;                                        /*!< Register bits. */
} pdm_v150_up_fifo_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the UP_FIFO_ST_CTRL. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_up_fifo_st_ctrl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t up_fifo_full_int_en    :   1;  /*!< Enable or disbale FIFO full status interrupt.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t up_fifo_afull_int_en   :   1;  /*!< Enable or disbale FIFO almost full status interrupt.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t up_fifo_empty_int_en   :   1;  /*!< Enable or disbale FIFO empty status interrupt.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t up_fifo_aempty_int_en  :   1;  /*!< Enable or disbale FIFO almost empty status interrupt.
                                                        - 0: Disable
                                                        - 1: Enable */
        uint32_t reserved4_31           :  28;
    } b;                                        /*!< Register bits. */
} pdm_v150_up_fifo_st_ctrl_data_t;

/**
 * @brief  This union represents the bit fields in the UP_FIFO_ST_CLR. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_up_fifo_st_clr_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t up_fifo_full_int_clr   :   1;  /*!< Clear FIFO full status interrupt.
                                                        - 0: Dont clear
                                                        - 1: Clear */
        uint32_t up_fifo_afull_int_clr  :   1;  /*!< Clear FIFO almost full status interrupt.
                                                        - 0: Dont clear
                                                        - 1: Clear */
        uint32_t up_fifo_empty_int_clr  :   1;  /*!< Clear FIFO empty status interrupt.
                                                        - 0: Dont clear
                                                        - 1: Clear */
        uint32_t up_fifo_aempty_int_clr :   1;  /*!< Clear FIFO almost empty status interrupt.
                                                        - 0: Dont clear
                                                        - 1: Clear */
        uint32_t up_fifo_clr            :   1;  /*!< CLear UP FIFO.
                                                        - 0: Dont clear
                                                        - 1: Clear */
        uint32_t reserved5_31           :  27;
    } b;                                        /*!< Register bits. */
} pdm_v150_up_fifo_st_clr_data_t;

/**
 * @brief  This union represents the bit fields in the UP_FIFO_ST. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union pdm_v150_up_fifo_st_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t up_fifo_full_int       :   1;  /*!< FIFO full status interrupt. */
        uint32_t up_fifo_afull_int      :   1;  /*!< FIFO almost full status interrupt. */
        uint32_t up_fifo_empty_int      :   1;  /*!< FIFO empty status interrupt. */
        uint32_t up_fifo_aempty_int     :   1;  /*!< FIFO almost empty status interrupt. */
        uint32_t reserved4_31           :  28;
    } b;                                        /*!< Register bits. */
} pdm_v150_up_fifo_st_data_t;

/**
 * @brief  Registers associated with PDM V150.
 */
typedef struct pdm_v150_regs {
    volatile uint32_t version;                  /*!< This register contain version information. <i>Offset: 00h</i>. */
    volatile uint32_t clk_rst_en;               /*!< This register reset the clocks and ip. <i>Offset: 04h</i>. */
    volatile uint32_t ch_ctrl;                  /*!< This register control the channel. <i>Offset: 08h</i>. */
    volatile uint32_t mic_ctrl;                 /*!< This register control the MIC. <i>Offset: 0Ch</i>. */
    volatile uint32_t cic_ctrl;                 /*!< This register control the CIC. <i>Offset: 10h</i>. */
    volatile uint32_t compd_ctrl;               /*!< This register control the COMPD. <i>Offset: 14h</i>. */
    volatile uint32_t hpf_ctrl[CONFIG_MIC_CH_NUM];  /*!< This register control the HPF foreach channel.
                                                         <i>Offset: 4h * MicChnnelNum + 18h </i>. */
    volatile uint32_t srcdn_ctrl;               /*!< This register control the SRCDN. <i>Offset: 20h</i>. */
    volatile uint32_t up_fifo_ctrl;             /*!< This register control the UP FIFO. <i>Offset: 24h</i>. */
    volatile uint32_t up_fifo_st_ctrl;          /*!< This register control the UP FIFO interrupt. <i>Offset: 28h</i>. */
    volatile uint32_t up_fifo_st_clr;           /*!< This register clear the UP FIFO interrupt. <i>Offset: 2Ch</i>. */
    volatile uint32_t up_fifo_st;               /*!< This register store the status of UP FIFO interrupt.
                                                     <i>Offset: 30h</i>. */
} pdm_v150_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif