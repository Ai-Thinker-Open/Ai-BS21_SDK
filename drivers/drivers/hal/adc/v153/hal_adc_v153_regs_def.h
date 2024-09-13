/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides V153 adc register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-08-31， Create file. \n
 */

#ifndef HAL_ADC_V153_REGS_DEF_H
#define HAL_ADC_V153_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_adc_v153_regs_def ADC V153 Regs Definition
 * @ingroup  drivers_hal_adc
 * @{
 */

#define HAL_ADC_V153_CFG_DELAY_5    5
#define HAL_ADC_V153_CFG_DELAY_10   10
#define HAL_ADC_V153_CFG_DELAY_30   30
#define HAL_ADC_V153_CFG_DELAY_50   50
#define HAL_ADC_V153_CFG_DELAY_150  150
#define HAL_ADC_V153_CFG_DELAY_1000 1000
#define HAL_ADC_V153_CFG_DELAY_2000 2000

typedef enum adc_v153_data_mode {
    COUNT_MODE,
    CONTIUNE_MODE
} adc_v153_data_mode_t;

typedef enum adc_v153_gadc_channel_sel {
    AIN0  = 0UL,
    AIN1  = 1UL,
    AIN2  = 2UL,
    AIN3  = 3UL,
    AIN4  = 4UL,
    AIN5  = 5UL,
    AIN6  = 6UL,
    AIN7  = 7UL,
    VSSAFE3 = 8UL,
    VSSAFE1 = 9UL,
    VICMREF = 10UL
} adc_v153_gadc_channel_sel_t;

typedef enum adc_v153_diag_node {
    ADC_RAW_DATA_INPUT,
    ADC_WEIGHTED_OUTPUT,
    ADC_ACCUMULATED_AVERAGE_OUTPUT,
    ADC_COMPARATOR_OS_CORRECTION_VALUE,
    ADC_PREAMP_OS_CORRECTION_VALUE,
    ADC_RC_OS_CORRECTION_VALUE,
    ADC_SPEED_CALI_PULSE_WIDTH_VALUE,
    MAINTENANCE_CNT
} adc_v153_diag_node_t;

typedef enum adc_v153_compensation_mode {
    DIRECT_COMPENSATION,
    LUT_COMPENSATION,
    STATIC_CONFIGURATION
} adc_v153_compensation_mode_t;

/**
 * @brief  This union represents the bit fields in the AFE_DIG_PWR_EN. \n
 *         Read the register into the <i>d16</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union afe_dig_pwr_data {
    uint32_t d16;                               /*!< Raw register data. */
    struct {
        uint32_t afe_pwr_en                 :   1;
        uint32_t afe_iso_en                 :   1;
        uint32_t afe_pwr_ack                :   1;
    } b;                                        /*!< Register bits. */
} afe_dig_pwr_data_t;

/**
 * @brief  This union represents the bit fields in the ADLDO1_CFG/ADLDO2_CFG. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union afe_adlao_cfg_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t adldo_vset                 :   4;
        uint32_t adldo_ictr                 :   3;
        uint32_t reserved                   :   1;
        uint32_t adldo_sel                  :   2;
    } b;                                        /*!< Register bits. */
} afe_adlao_cfg_data_t;

/**
 * @brief  This union represents the bit fields in the 0x000. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_rstn_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_rstn_tst               :   1;
        uint32_t reserved1_3                :   3;
        uint32_t cfg_gadc_rstn_bc           :   1;
        uint32_t reserved5_7                :   3;
        uint32_t cfg_gadc_rstn_fc           :   1;
        uint32_t reserved9_11               :   3;
        uint32_t cfg_gadc_rstn_data         :   1;
        uint32_t reserved13_15              :   3;
        uint32_t cfg_gadc_rstn_ana          :   1;
    } b;                                        /*!< Register bits. */
} cfg_rstn_data_t;

/**
 * @brief  This union represents the bit fields in the 0x004. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_clken_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_clken_tst              :   1;
        uint32_t reserved1_3                :   3;
        uint32_t cfg_gadc_clken_bc          :   1;
        uint32_t reserved5_7                :   3;
        uint32_t cfg_gadc_clken_fc          :   1;
        uint32_t reserved9_11               :   3;
        uint32_t cfg_gadc_clken_byp         :   1;
        uint32_t reserved13_15              :   3;
        uint32_t cfg_gadc_clken_prechg      :   1;
        uint32_t reserved17_19              :   3;
        uint32_t cfg_gadc_clken_ctrl        :   1;
    } b;                                        /*!< Register bits. */
} cfg_clken_data_t;

/**
 * @brief  This union represents the bit fields in the 0x10. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_clk_div1 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t ana_div_th                 :   12;
        uint32_t prechg_div_th              :   12;
    } b;                                        /*!< Register bits. */
} cfg_clk_div1_t;

/**
 * @brief  This union represents the bit fields in the 0x008/0x00C. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_clk_div_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_adc_ana_div_th         :   8;
        uint32_t reserved8_15               :   8;
        uint32_t cfg_adc_ana_div_cyc        :   8;
    } b;                                        /*!< Register bits. */
} cfg_clk_div_data_t;

/**
 * @brief  This union represents the bit fields in the 0x05C. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_gadc_data0 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t data_num                   :   10;
        uint32_t reserved10_11              :   2;
        uint32_t wait_num                   :   3;
        uint32_t reserved15                 :   1;
        adc_v153_data_mode_t cont_mode      :   1;
    } b;                                        /*!< Register bits. */
} cfg_gadc_data0_t;

/**
 * @brief  This union represents the bit fields in the 0x060. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_gadc_data1 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t osr_len                    :   3;
        uint32_t reserved3                  :   1;
        uint32_t osr_sel                    :   3;
        uint32_t reserved7                  :   1;
        uint32_t osr_wait_num               :   6;
    } b;                                        /*!< Register bits. */
} cfg_gadc_data1_t;

/**
 * @brief  This union represents the bit fields in the 0x078. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_gadc_data4 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t adc_cdac_fc_scale_div      :   9;
        uint32_t reserved9_11               :   3;
        uint32_t adc_cdac_scale_div_sel     :   1;
    } b;                                        /*!< Register bits. */
} cfg_gadc_data4_t;

/**
 * @brief  This union represents the bit fields in the 0x134. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_cmp_os_code {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t adc_manual_cmp_os_code             :   7;
        uint32_t reserved7                          :   1;
        uint32_t adc_manual_cmp_os_update_en        :   1;
    } b;                                        /*!< Register bits. */
} cfg_cmp_os_code_t;

/**
 * @brief  This union represents the bit fields in the 0x134. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_cmp_os_12 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_manual_cmp_os_code             :   7;
        uint32_t reserved7                          :   1;
        uint32_t cfg_manual_cmp_os_update           :   1;
    } b;                                        /*!< Register bits. */
} cfg_cmp_os_12_t;

/**
 * @brief  This union represents the bit fields in the 0x154. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_cdac_fc0_data1 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_gadc_cdac_fc_cap_end           :   5;
        uint32_t reserved5_7                        :   3;
        uint32_t cfg_gadc_cdac_fc_cap_start         :   5;
    } b;                                        /*!< Register bits. */
} cfg_cdac_fc0_data1_t;

/**
 * @brief  This union represents the bit fields in the 0x22C. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_dcoc_cal_13 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_manual_preamp_os_code          :   6;
        uint32_t reserved6_7                        :   2;
        uint32_t cfg_manual_preamp_os_update        :   1;
    } b;                                        /*!< Register bits. */
} cfg_dcoc_cal_13_t;

/**
 * @brief  This union represents the bit fields in the 0x25C. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_sar_spd_6 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_manual_sar_spd_dly_code        :   3;
        uint32_t reserved3                          :   1;
        uint32_t cfg_manual_sar_spd_update          :   1;
    } b;                                        /*!< Register bits. */
} cfg_sar_spd_6_t;

/**
 * @brief  This union represents the bit fields in the 0x2C4. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_amux_1 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t amuxn_sensor_ch_sel                :   11;
        uint32_t amuxn_devide_disable               :   1;
        uint32_t amuxp_sensor_ch_sel                :   11;
        uint32_t amuxp_devide_disable               :   1;
    } b;                                        /*!< Register bits. */
} cfg_amux_1_t;

/**
 * @brief  This union represents the bit fields in the 0x2C8. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_amux_2 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_amuxn_audio_ch_sel             :   4;
        uint32_t cfg_amuxp_audio_ch_sel             :   4;
    } b;                                        /*!< Register bits. */
} cfg_amux_2_t;

/**
 * @brief  This union represents the bit fields in the AFE_ADC_LDO_CFG. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union afe_ldo_cfg_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t s2d_afeldo3_en_dly         :   1;
        uint32_t s2d_afeldo3_en             :   1;
        uint32_t s2d_afeldo2_en_dly         :   1;
        uint32_t s2d_afeldo2_en             :   1;
        uint32_t s2d_afeldo1_en_dly         :   1;
        uint32_t s2d_afeldo1_en             :   1;
        uint32_t s2d_afeldo_iso_en_n        :   1;
    } b;                                        /*!< Register bits. */
} afe_ldo_cfg_data_t;

/**
 * @brief  This union represents the bit fields in the AFE_GADC_CFG. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union afe_gadc_cfg_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t s2d_gadc_en               :   1;
        uint32_t s2d_gadc_mux_en           :   1;
        uint32_t s2d_gadc_iso_en           :   1;
        uint32_t d2s_gadc_alarm            :   1;
        uint32_t d2s_gadc_done             :   1;
    } b;                                        /*!< Register bits. */
} afe_gadc_cfg_data_t;

/**
 * @brief  This union represents the bit fields in the 0x040. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_adc_cali_ctrl {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_adc_monitor_start    :   1;
        uint32_t reserved1_3              :   3;
        uint32_t cfg_adc_cal_en           :   1;
    } b;                                        /*!< Register bits. */
} cfg_adc_cali_ctrl_t;

/**
 * @brief  This union represents the bit fields in the 0x3D4. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_ana_0 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_topbias_en             :   1;
        uint32_t reserved1_3                :   3;
        uint32_t cfg_vrefldo_en_test        :   1;
        uint32_t reserved5_7                :   3;
        uint32_t cfg_vrefldo_en_sw          :   1;
        uint32_t reserved9_11               :   3;
        uint32_t cfg_vrefldo_en_hiz         :   1;
        uint32_t reserved13_15              :   3;
        uint32_t cfg_vrefldo_en_dly         :   1;
        uint32_t reserved17_19              :   3;
        uint32_t cfg_vrefldo_en             :   1;
        uint32_t reserved21_23              :   3;
        uint32_t cfg_clk_rstn               :   1;
    } b;                                        /*!< Register bits. */
} cfg_ana_0_t;

/**
 * @brief  This union represents the bit fields in the 0x3D8. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_ana_1 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_preamp_os_dac_en       :   1;
        uint32_t reserved1_3                :   3;
        uint32_t cfg_pga_vcm_en             :   1;
        uint32_t reserved5_7                :   3;
        uint32_t cfg_pga_en                 :   1;
        uint32_t reserved9_11               :   3;
        uint32_t cfg_preamp_vcm_en          :   1;
        uint32_t reserved13_15              :   3;
        uint32_t cfg_preamp_en              :   1;
        uint32_t reserved17_19              :   3;
        uint32_t cfg_tsensor_en             :   1;
        uint32_t reserved21_23              :   3;
        uint32_t cfg_bufp_en                :   1;
        uint32_t reserved25_27              :   3;
        uint32_t cfg_bufn_en                :   1;
    } b;                                        /*!< Register bits. */
} cfg_ana_1_t;

/**
 * @brief  This union represents the bit fields in the 0x3DC. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_ana_2 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_cmp_vin_rdac_code      :   6;
        uint32_t reserved6_7                :   2;
        uint32_t cfg_cmp_vin_rdac_ref_sel   :   3;
        uint32_t reserved11                 :   1;
        uint32_t cfg_cmp_en                 :   1;
    } b;                                        /*!< Register bits. */
} cfg_ana_2_t;

/**
 * @brief  This union represents the bit fields in the 0x3E8. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_ana_5 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_afe_adcldo_vset         :   4;
        uint32_t cfg_afe_adcldo_rpoly_trim   :   4;
        uint32_t cfg_afe_adcldo_idummy_trim  :   2;
        uint32_t reserved10_11               :   2;
        uint32_t cfg_afe_adcldo_ictr_trim    :   3;
        uint32_t reserved15                  :   1;
        uint32_t cfg_afe_adcldo_en_test      :   1;
        uint32_t reserved17_19               :   3;
        uint32_t cfg_afe_adcldo_en_sw        :   1;
        uint32_t reserved21_23               :   3;
        uint32_t cfg_afe_adcldo_en_hiz       :   1;
        uint32_t reserved25_27               :   3;
        uint32_t cfg_afe_adcldo_en_dly       :   1;
        uint32_t reserved29_31               :   3;
    } b;                                        /*!< Register bits. */
} cfg_ana_5_t;

/**
 * @brief  This union represents the bit fields in the 0x3F0. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_ana_7 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_afe_afeldo_vset         :   4;
        uint32_t cfg_afe_afeldo_rpoly_trim   :   4;
        uint32_t cfg_afe_afeldo_idummy_trim  :   2;
        uint32_t reserved10_11               :   2;
        uint32_t cfg_afe_afeldo_ictr_trim    :   3;
        uint32_t reserved15                  :   1;
        uint32_t cfg_afe_afeldo_en_test      :   1;
        uint32_t reserved17_19               :   3;
        uint32_t cfg_afe_afeldo_en_sw        :   1;
        uint32_t reserved21_23               :   3;
        uint32_t cfg_afe_afeldo_en_hiz       :   1;
        uint32_t reserved25_27               :   3;
        uint32_t cfg_afe_afeldo_en_dly       :   1;
        uint32_t reserved29_31               :   3;
    } b;                                        /*!< Register bits. */
} cfg_ana_7_t;

/**
 * @brief  This union represents the bit fields in the 0x3F4. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_0 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_vrefldo_ictr_trim      :   3;
        uint32_t cfg_vrefldo_idummy_trim    :   2;
        uint32_t cfg_vrefldo_rpoly_trim     :   4;
        uint32_t cfg_vrefldo_vset_trim      :   4;
        uint32_t cfg_vrefldo_reserved       :   3;
    } b;                                        /*!< Register bits. */
} cfg_freg_0_t;

/**
 * @brief  This union represents the bit fields in the 0x400. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_3 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_preamp_gain_sel        :   8;
        uint32_t cfg_preamp_bypass_en       :   1;
        uint32_t cfg_preamp_rc_en           :   1;
        uint32_t cfg_preamp_vip_short       :   1;
        uint32_t cfg_preamp_vin_short       :   1;
    } b;                                        /*!< Register bits. */
} cfg_freg_3_t;

/**
 * @brief  This union represents the bit fields in the 0x404. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_4 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_preamp_vocm_ref_sel    :   4;
        uint32_t cfg_preamp_vicm_ref_sel    :   2;
        uint32_t cfg_preamp_ibias_sel       :   1;
        uint32_t cfg_preamp_rz_sel          :   1;
        uint32_t cfg_preamp_cc_sel          :   1;
    } b;                                        /*!< Register bits. */
} cfg_freg_4_t;

/**
 * @brief  This union represents the bit fields in the 0x408. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_5 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_pga_gain_sel        :   4;
        uint32_t cfg_pga_chop_mode_sel   :   2;
        uint32_t cfg_pga_bypass_en       :   1;
        uint32_t cfg_pga_rc_en           :   1;
    } b;                                        /*!< Register bits. */
} cfg_freg_5_t;

/**
 * @brief  This union represents the bit fields in the 0x40C. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_6 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_pga_vocm_ref_sel   :   3;
        uint32_t cfg_pga_ibias_sel      :   2;
        uint32_t cfg_pga_rz_sel         :   2;
        uint32_t cfg_pga_cc_sel         :   3;
    } b;                                        /*!< Register bits. */
} cfg_freg_6_t;

/**
 * @brief  This union represents the bit fields in the 0x410. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_7 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_idac_sel_pga           :   1;
        uint32_t cfg_idac_sel_preamp        :   1;
        uint32_t cfg_chopclk_div_dly_sel    :   2;
        uint32_t cfg_chopclk_div_freq_sel   :   2;
        uint32_t cfg_topbias_trim           :   10;
    } b;                                        /*!< Register bits. */
} cfg_freg_7_t;

/**
 * @brief  This union represents the bit fields in the 0x41C. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_10 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_gadc_short_mode        :   1;
        uint32_t cfg_gadc_vcm_mode          :   1;
        uint32_t cfg_gadc_dly2inject        :   1;
        uint32_t cfg_gadc_dly2convrstn      :   2;
        uint32_t cfg_gadc_dly2convstart     :   2;
        uint32_t cfg_gadc_dly2srwidth       :   2;
        uint32_t cfg_gadc_chop_en           :   3;
        uint32_t cfg_gadc_chop_freq         :   1;
        uint32_t cfg_gadc_lsbrpts_en        :   1;
        uint32_t cfg_gadc_r_sel_fall        :   1;
    } b;                                        /*!< Register bits. */
} cfg_freg_10_t;

/**
 * @brief  This union represents the bit fields in the 0x420. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_freg_11 {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_gadc_r_sel_rise        :   3;
        uint32_t cfg_gadc_meta_det_en       :   1;
        uint32_t cfg_gadc_meta_det_trim     :   2;
        uint32_t cfg_gadc_os_range_sel      :   1;
        uint32_t reserved7_14               :   8;
        uint32_t cfg_dreg_iso_enb           :   1;
    } b;                                        /*!< Register bits. */
} cfg_freg_11_t;

/**
 * @brief  This union represents the bit fields in the CFG_MCU_DIAG_SAMPLE_MODE. \n
 *         Read the register into the <i>d16</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union diag_sample_mode_data {
    uint32_t d16;                               /*!< Raw register data. */
    struct {
        uint32_t cfg_mcu_diag_sample_mode       :   2;
        uint32_t reserved2_7                    :   6;
        uint32_t cfg_mcu_diag_sample_en         :   1;
        uint32_t cfg_mcu_diag_sample_sync       :   1;
    } b;                                        /*!< Register bits. */
} diag_sample_mode_data_t;

/**
 * @brief  Registers associated with ADC.
 */

/**
 * @brief  AFE config registers.
 */
typedef struct adc_regs {
    volatile uint32_t cfg_rstn;               /*!< CFG_RSTN.           <i>Offset: 000h</i>. */
    volatile uint32_t cfg_clken;              /*!< CFG_CLKEN.          <i>Offset: 004h</i>. */
    volatile uint32_t cfg_prechg_lead;        /*!< CFG_PRECHG_LEAD.    <i>Offset: 008h</i>. */
    volatile uint32_t cfg_clk_div_0;          /*!< CFG_CLK_DIV_0.      <i>Offset: 00Ch</i>. */
    volatile uint32_t cfg_clk_div_1;          /*!< CFG_CLK_DIV_1.      <i>Offset: 010h</i>. */
    volatile uint32_t cfg_manual_clk_0;       /*!< CFG_MANUAL_CLK_0.   <i>Offset: 014h</i>. */
    volatile uint32_t cfg_manual_clk_1;       /*!< CFG_MANUAL_CLK_1.   <i>Offset: 018h</i>. */
    volatile uint32_t cfg_iso;                /*!< CFG_ISO.            <i>Offset: 01Ch</i>. */
    volatile uint32_t reserved0[4];           /*!< Reserved.           <i>Offset: 020h</i>. */
    volatile uint32_t cfg_gadc_ctrl_0;        /*!< CFG_GADC_CTRL_0.    <i>Offset: 030h</i>. */
    volatile uint32_t cfg_gadc_ctrl_1;        /*!< CFG_GADC_CTRL_1.    <i>Offset: 034h</i>. */
    volatile uint32_t cfg_gadc_ctrl_2;        /*!< CFG_GADC_CTRL_2.    <i>Offset: 038h</i>. */
    volatile uint32_t cfg_gadc_ctrl_3;        /*!< CFG_GADC_CTRL_3.    <i>Offset: 03Ch</i>. */
    volatile uint32_t cfg_gadc_ctrl_4;        /*!< CFG_GADC_CTRL_4.    <i>Offset: 040h</i>. */
    volatile uint32_t rpt_gadc_ctrl_0;        /*!< RPT_GADC_CTRL_0.    <i>Offset: 044h</i>. */
    volatile uint32_t cfg_gadc_ctrl_5;        /*!< CFG_GADC_CTRL_5.    <i>Offset: 048h</i>. */
    volatile uint32_t cfg_gadc_ctrl_6;        /*!< CFG_GADC_CTRL_6.    <i>Offset: 04Ch</i>. */
    volatile uint32_t rpt_gadc_ctrl_1;        /*!< RPT_GADC_CTRL_1.    <i>Offset: 050h</i>. */
    volatile uint32_t cfg_gadc_ctrl_7;        /*!< CFG_GADC_CTRL_7.    <i>Offset: 054h</i>. */
    volatile uint32_t rpt_gadc_ctrl_2;        /*!< RPT_GADC_CTRL_2.    <i>Offset: 058h</i>. */
    volatile uint32_t cfg_gadc_data_0;        /*!< CFG_GADC_DATA_0.    <i>Offset: 05Ch</i>. */
    volatile uint32_t cfg_gadc_data_1;        /*!< CFG_GADC_DATA_1.    <i>Offset: 060h</i>. */
    volatile uint32_t rpt_gadc_data_0;        /*!< RPT_GADC_DATA_0.    <i>Offset: 064h</i>. */
    volatile uint32_t rpt_gadc_data_1;        /*!< RPT_GADC_DATA_1.    <i>Offset: 068h</i>. */
    volatile uint32_t rpt_gadc_data_2;        /*!< RPT_GADC_DATA_2.    <i>Offset: 06Ch</i>. */
    volatile uint32_t rpt_gadc_data_3;        /*!< RPT_GADC_DATA_3.    <i>Offset: 070h</i>. */
    volatile uint32_t cfg_gadc_data_3;        /*!< CFG_GADC_DATA_3.    <i>Offset: 074h</i>. */
    volatile uint32_t cfg_gadc_data_4;        /*!< CFG_GADC_DATA_4.    <i>Offset: 078h</i>. */
    volatile uint32_t rpt_gadc_data_4;        /*!< RPT_GADC_DATA_4.    <i>Offset: 07Ch</i>. */
    volatile uint32_t cfg_gadc_data_5;        /*!< CFG_GADC_DATA_5.    <i>Offset: 080h</i>. */
    volatile uint32_t cfg_gadc_data_6;        /*!< CFG_GADC_DATA_6.    <i>Offset: 084h</i>. */
    volatile uint32_t cfg_gadc_data_7;        /*!< CFG_GADC_DATA_7.    <i>Offset: 088h</i>. */
    volatile uint32_t cfg_gadc_data_8;        /*!< CFG_GADC_DATA_8.    <i>Offset: 08Ch</i>. */
    volatile uint32_t cfg_gadc_data_9;        /*!< CFG_GADC_DATA_9.    <i>Offset: 090h</i>. */
    volatile uint32_t cfg_gadc_data_10;       /*!< CFG_GADC_DATA_10.   <i>Offset: 094h</i>. */
    volatile uint32_t cfg_gadc_data_11;       /*!< CFG_GADC_DATA_11.   <i>Offset: 098h</i>. */
    volatile uint32_t cfg_gadc_data_12;       /*!< CFG_GADC_DATA_12.   <i>Offset: 09Ch</i>. */
    volatile uint32_t cfg_gadc_data_13;       /*!< CFG_GADC_DATA_13.   <i>Offset: 0A0h</i>. */
    volatile uint32_t cfg_gadc_data_14;       /*!< CFG_GADC_DATA_14.   <i>Offset: 0A4h</i>. */
    volatile uint32_t cfg_gadc_data_15;       /*!< CFG_GADC_DATA_15.   <i>Offset: 0A8h</i>. */
    volatile uint32_t cfg_gadc_data_16;       /*!< CFG_GADC_DATA_16.   <i>Offset: 0ACh</i>. */
    volatile uint32_t cfg_gadc_data_17;       /*!< CFG_GADC_DATA_17.   <i>Offset: 0B0h</i>. */
    volatile uint32_t cfg_gadc_data_18;       /*!< CFG_GADC_DATA_18.   <i>Offset: 0B4h</i>. */
    volatile uint32_t cfg_gadc_data_19;       /*!< CFG_GADC_DATA_19.   <i>Offset: 0B8h</i>. */
    volatile uint32_t cfg_gadc_data_20;       /*!< CFG_GADC_DATA_20.   <i>Offset: 0BCh</i>. */
    volatile uint32_t cfg_gadc_data_21;       /*!< CFG_GADC_DATA_21.   <i>Offset: 0C0h</i>. */
    volatile uint32_t cfg_gadc_data_22;       /*!< CFG_GADC_DATA_22.   <i>Offset: 0C4h</i>. */
    volatile uint32_t cfg_gadc_data_23;       /*!< CFG_GADC_DATA_23.   <i>Offset: 0C8h</i>. */
    volatile uint32_t cfg_gadc_data_24;       /*!< CFG_GADC_DATA_24.   <i>Offset: 0CCh</i>. */
    volatile uint32_t cfg_gadc_data_25;       /*!< CFG_GADC_DATA_25.   <i>Offset: 0D0h</i>. */
    volatile uint32_t rpt_gadc_data_5;        /*!< RPT_GADC_DATA_5.    <i>Offset: 0D4h</i>. */
    volatile uint32_t rpt_gadc_data_6;        /*!< RPT_GADC_DATA_6.    <i>Offset: 0D8h</i>. */
    volatile uint32_t rpt_gadc_data_7;        /*!< RPT_GADC_DATA_7.    <i>Offset: 0DCh</i>. */
    volatile uint32_t rpt_gadc_data_8;        /*!< RPT_GADC_DATA_8.    <i>Offset: 0E0h</i>. */
    volatile uint32_t rpt_gadc_data_9;        /*!< RPT_GADC_DATA_9.    <i>Offset: 0E4h</i>. */
    volatile uint32_t rpt_gadc_data_10;       /*!< RPT_GADC_DATA_10.   <i>Offset: 0E8h</i>. */
    volatile uint32_t rpt_gadc_data_11;       /*!< RPT_GADC_DATA_11.   <i>Offset: 0ECh</i>. */
    volatile uint32_t rpt_gadc_data_12;       /*!< RPT_GADC_DATA_12.   <i>Offset: 0F0h</i>. */
    volatile uint32_t rpt_gadc_data_13;       /*!< RPT_GADC_DATA_13.   <i>Offset: 0F4h</i>. */
    volatile uint32_t reserved1[2];           /*!< Reserved.           <i>Offset: 0F8h</i>. */
    volatile uint32_t cfg_cmp_os_0;           /*!< CFG_CMP_OS_0.       <i>Offset: 100h</i>. */
    volatile uint32_t cfg_cmp_os_1;           /*!< CFG_CMP_OS_1.       <i>Offset: 104h</i>. */
    volatile uint32_t cfg_cmp_os_2;           /*!< CFG_CMP_OS_2.       <i>Offset: 108h</i>. */
    volatile uint32_t cfg_cmp_os_3;           /*!< CFG_CMP_OS_3.       <i>Offset: 10Ch</i>. */
    volatile uint32_t cfg_cmp_os_4;           /*!< CFG_CMP_OS_4.       <i>Offset: 110h</i>. */
    volatile uint32_t cfg_cmp_os_5;           /*!< CFG_CMP_OS_5.       <i>Offset: 114h</i>. */
    volatile uint32_t cfg_cmp_os_6;           /*!< CFG_CMP_OS_6.       <i>Offset: 118h</i>. */
    volatile uint32_t cfg_cmp_os_7;           /*!< CFG_CMP_OS_7.       <i>Offset: 11Ch</i>. */
    volatile uint32_t cfg_cmp_os_8;           /*!< CFG_CMP_OS_8.       <i>Offset: 120h</i>. */
    volatile uint32_t cfg_cmp_os_9;           /*!< CFG_CMP_OS_9.       <i>Offset: 124h</i>. */
    volatile uint32_t cfg_cmp_os_10;          /*!< CFG_CMP_OS_10.      <i>Offset: 128h</i>. */
    volatile uint32_t rpt_cmp_os_0;           /*!< RPT_CMP_OS_0.       <i>Offset: 12Ch</i>. */
    volatile uint32_t cfg_cmp_os_11;          /*!< CFG_CMP_OS_11.      <i>Offset: 130h</i>. */
    volatile uint32_t cfg_cmp_os_12;          /*!< CFG_CMP_OS_12.      <i>Offset: 134h</i>. */
    volatile uint32_t rpt_cmp_os_2;           /*!< RPT_CMP_OS_2.       <i>Offset: 138h</i>. */
    volatile uint32_t reserved2[5];           /*!< Reserved.           <i>Offset: 13Ch</i>. */
    volatile uint32_t cfg_cdac_fc0_0;         /*!< CFG_CDAC_FC0_0.     <i>Offset: 150h</i>. */
    volatile uint32_t cfg_cdac_fc0_1;         /*!< CFG_CDAC_FC0_1.     <i>Offset: 154h</i>. */
    volatile uint32_t cfg_cdac_fc0_2;         /*!< CFG_CDAC_FC0_2.     <i>Offset: 158h</i>. */
    volatile uint32_t cfg_cdac_fc0_3;         /*!< CFG_CDAC_FC0_3.     <i>Offset: 15Ch</i>. */
    volatile uint32_t cfg_cdac_fc0_4;         /*!< CFG_CDAC_FC0_4.     <i>Offset: 160h</i>. */
    volatile uint32_t cfg_cdac_fc0_5;         /*!< CFG_CDAC_FC0_5.     <i>Offset: 164h</i>. */
    volatile uint32_t rpt_cdac_fc0_0;         /*!< RPT_CDAC_FC0_0.     <i>Offset: 168h</i>. */
    volatile uint32_t cfg_cdac_fc0_6;         /*!< CFG_CDAC_FC0_6.     <i>Offset: 16Ch</i>. */
    volatile uint32_t cfg_cdac_fc0_7;         /*!< CFG_CDAC_FC0_7.     <i>Offset: 170h</i>. */
    volatile uint32_t cfg_cdac_fc0_8;         /*!< CFG_CDAC_FC0_8.     <i>Offset: 174h</i>. */
    volatile uint32_t cfg_cdac_fc0_9;         /*!< CFG_CDAC_FC0_9.     <i>Offset: 178h</i>. */
    volatile uint32_t cfg_cdac_fc0_10;        /*!< CFG_CDAC_FC0_10.    <i>Offset: 17Ch</i>. */
    volatile uint32_t cfg_cdac_fc0_11;        /*!< CFG_CDAC_FC0_11.    <i>Offset: 180h</i>. */
    volatile uint32_t cfg_cdac_fc0_12;        /*!< CFG_CDAC_FC0_12.    <i>Offset: 184h</i>. */
    volatile uint32_t cfg_cdac_fc0_13;        /*!< CFG_CDAC_FC0_13.    <i>Offset: 188h</i>. */
    volatile uint32_t cfg_cdac_fc0_14;        /*!< CFG_CDAC_FC0_14.    <i>Offset: 18Ch</i>. */
    volatile uint32_t cfg_cdac_fc1_0;         /*!< CFG_CDAC_FC1_0.     <i>Offset: 190h</i>. */
    volatile uint32_t cfg_cdac_fc1_1;         /*!< CFG_CDAC_FC1_1.     <i>Offset: 194h</i>. */
    volatile uint32_t cfg_cdac_fc1_2;         /*!< CFG_CDAC_FC1_2.     <i>Offset: 198h</i>. */
    volatile uint32_t cfg_cdac_fc1_3;         /*!< CFG_CDAC_FC1_3.     <i>Offset: 19Ch</i>. */
    volatile uint32_t rpt_cdac_fc1_0;         /*!< RPT_CDAC_FC1_0.     <i>Offset: 1A0h</i>. */
    volatile uint32_t rpt_cdac_fc1_3;         /*!< RPT_CDAC_FC1_3.     <i>Offset: 1A4h</i>. */
    volatile uint32_t rpt_cdac_fc3_1;         /*!< RPT_CDAC_FC3_1.     <i>Offset: 1A8h</i>. */
    volatile uint32_t rpt_cdac_fc3_2;         /*!< RPT_CDAC_FC3_2.     <i>Offset: 1ACh</i>. */
    volatile uint32_t rpt_cdac_fc3_3;         /*!< RPT_CDAC_FC3_3.     <i>Offset: 1B0h</i>. */
    volatile uint32_t rpt_cdac_fc3_4;         /*!< RPT_CDAC_FC3_4.     <i>Offset: 1B4h</i>. */
    volatile uint32_t rpt_cdac_fc3_5;         /*!< RPT_CDAC_FC3_5.     <i>Offset: 1B8h</i>. */
    volatile uint32_t rpt_cdac_fc3_6;         /*!< RPT_CDAC_FC3_6.     <i>Offset: 1BCh</i>. */
    volatile uint32_t rpt_cdac_fc3_7;         /*!< RPT_CDAC_FC3_7.     <i>Offset: 1C0h</i>. */
    volatile uint32_t rpt_cdac_fc3_8;         /*!< RPT_CDAC_FC3_8.     <i>Offset: 1C4h</i>. */
    volatile uint32_t rpt_cdac_fc3_9;         /*!< RPT_CDAC_FC3_9.     <i>Offset: 1C8h</i>. */
    volatile uint32_t rpt_cdac_fc3_10;        /*!< RPT_CDAC_FC3_10.    <i>Offset: 1CCh</i>. */
    volatile uint32_t rpt_cdac_fc3_11;        /*!< RPT_CDAC_FC3_11.    <i>Offset: 1D0h</i>. */
    volatile uint32_t rpt_cdac_fc3_12;        /*!< RPT_CDAC_FC3_12.    <i>Offset: 1D4h</i>. */
    volatile uint32_t rpt_cdac_fc3_13;        /*!< RPT_CDAC_FC3_13.    <i>Offset: 1D8h</i>. */
    volatile uint32_t rpt_cdac_fc3_14;        /*!< RPT_CDAC_FC3_14.    <i>Offset: 1DCh</i>. */
    volatile uint32_t rpt_cdac_fc3_15;        /*!< RPT_CDAC_FC3_15.    <i>Offset: 1E0h</i>. */
    volatile uint32_t rpt_cdac_fc3_16;        /*!< RPT_CDAC_FC3_16.    <i>Offset: 1E4h</i>. */
    volatile uint32_t rpt_cdac_fc3_17;        /*!< RPT_CDAC_FC3_17.    <i>Offset: 1E8h</i>. */
    volatile uint32_t rpt_cdac_fc3_18;        /*!< RPT_CDAC_FC3_18.    <i>Offset: 1ECh</i>. */
    volatile uint32_t reserved3[4];           /*!< Reserved.           <i>Offset: 1F0h</i>. */
    volatile uint32_t cfg_dcoc_cal_0;         /*!< CFG_DCOC_CAL_0.     <i>Offset: 200h</i>. */
    volatile uint32_t cfg_dcoc_cal_1;         /*!< CFG_DCOC_CAL_1.     <i>Offset: 204h</i>. */
    volatile uint32_t cfg_dcoc_cal_2;         /*!< CFG_DCOC_CAL_2.     <i>Offset: 208h</i>. */
    volatile uint32_t cfg_dcoc_cal_3;         /*!< CFG_DCOC_CAL_3.     <i>Offset: 20Ch</i>. */
    volatile uint32_t cfg_dcoc_cal_4;         /*!< CFG_DCOC_CAL_4.     <i>Offset: 210h</i>. */
    volatile uint32_t cfg_dcoc_cal_5;         /*!< CFG_DCOC_CAL_5.     <i>Offset: 214h</i>. */
    volatile uint32_t cfg_dcoc_cal_6;         /*!< CFG_DCOC_CAL_6.     <i>Offset: 218h</i>. */
    volatile uint32_t cfg_dcoc_cal_7;         /*!< CFG_DCOC_CAL_7.     <i>Offset: 21Ch</i>. */
    volatile uint32_t cfg_dcoc_cal_8;         /*!< CFG_DCOC_CAL_8.     <i>Offset: 220h</i>. */
    volatile uint32_t rpt_dcoc_cal_0;         /*!< RPT_DCOC_CAL_0.     <i>Offset: 224h</i>. */
    volatile uint32_t cfg_dcoc_cal_12;        /*!< CFG_DCOC_CAL_12.    <i>Offset: 228h</i>. */
    volatile uint32_t cfg_dcoc_cal_13;        /*!< CFG_DCOC_CAL_13.    <i>Offset: 22Ch</i>. */
    volatile uint32_t rpt_dcoc_cal_1;         /*!< RPT_DCOC_CAL_1.     <i>Offset: 230h</i>. */
    volatile uint32_t reserved4[3];           /*!< Reserved.           <i>Offset: 234h</i>. */
    volatile uint32_t cfg_sar_spd_0;          /*!< CFG_SAR_SPD_0.      <i>Offset: 240h</i>. */
    volatile uint32_t cfg_sar_spd_1;          /*!< CFG_SAR_SPD_1.      <i>Offset: 244h</i>. */
    volatile uint32_t cfg_sar_spd_2;          /*!< CFG_SAR_SPD_2.      <i>Offset: 248h</i>. */
    volatile uint32_t cfg_sar_spd_3;          /*!< CFG_SAR_SPD_3.      <i>Offset: 24Ch</i>. */
    volatile uint32_t cfg_sar_spd_4;          /*!< CFG_SAR_SPD_4.      <i>Offset: 250h</i>. */
    volatile uint32_t rpt_sar_spd_0;          /*!< RPT_SAR_SPD_0.      <i>Offset: 254h</i>. */
    volatile uint32_t rpt_sar_spd_1;          /*!< RPT_SAR_SPD_1.      <i>Offset: 258h</i>. */
    volatile uint32_t cfg_sar_spd_6;          /*!< CFG_SAR_SPD_6.      <i>Offset: 25Ch</i>. */
    volatile uint32_t rpt_sar_spd_2;          /*!< RPT_SAR_SPD_2.      <i>Offset: 260h</i>. */
    volatile uint32_t reserved5[7];           /*!< Reserved.           <i>Offset: 264h</i>. */
    volatile uint32_t cfg_rc_cal_0;           /*!< CFG_RC_CAL_0.       <i>Offset: 280h</i>. */
    volatile uint32_t cfg_rc_cal_1;           /*!< CFG_RC_CAL_1.       <i>Offset: 284h</i>. */
    volatile uint32_t cfg_rc_cal_2;           /*!< CFG_RC_CAL_2.       <i>Offset: 288h</i>. */
    volatile uint32_t cfg_rc_cal_3;           /*!< CFG_RC_CAL_3.       <i>Offset: 28Ch</i>. */
    volatile uint32_t cfg_rc_cal_4;           /*!< CFG_RC_CAL_4.       <i>Offset: 290h</i>. */
    volatile uint32_t rpt_rc_cal_0;           /*!< RPT_RC_CAL_0.       <i>Offset: 294h</i>. */
    volatile uint32_t rpt_rc_cal_1;           /*!< RPT_RC_CAL_1.       <i>Offset: 298h</i>. */
    volatile uint32_t cfg_rc_cal_5;           /*!< CFG_RC_CAL_5.       <i>Offset: 29Ch</i>. */
    volatile uint32_t cfg_rc_cal_6;           /*!< CFG_RC_CAL_6.       <i>Offset: 2A0h</i>. */
    volatile uint32_t cfg_rc_cal_7;           /*!< CFG_RC_CAL_7.       <i>Offset: 2A4h</i>. */
    volatile uint32_t cfg_rc_cal_8;           /*!< CFG_RC_CAL_8.       <i>Offset: 2A8h</i>. */
    volatile uint32_t rpt_rc_cal_2;           /*!< RPT_RC_CAL_2.       <i>Offset: 2ACh</i>. */
    volatile uint32_t rpt_rc_cal_3;           /*!< RPT_RC_CAL_3.       <i>Offset: 2B0h</i>. */
    volatile uint32_t reserved6[3];           /*!< Reserved.           <i>Offset: 2B4h</i>. */
    volatile uint32_t cfg_amux_0;             /*!< CFG_AMUX_0.         <i>Offset: 2C0h</i>. */
    volatile uint32_t cfg_amux_1;             /*!< CFG_AMUX_1.         <i>Offset: 2C4h</i>. */
    volatile uint32_t cfg_amux_2;             /*!< CFG_AMUX_2.         <i>Offset: 2C8h</i>. */
    volatile uint32_t cfg_amux_3;             /*!< CFG_AMUX_3.         <i>Offset: 2CCh</i>. */
    volatile uint32_t cfg_amux_4;             /*!< CFG_AMUX_4.         <i>Offset: 2D0h</i>. */
    volatile uint32_t cfg_amux_5;             /*!< CFG_AMUX_5.         <i>Offset: 2D4h</i>. */
    volatile uint32_t rpt_amux_0;             /*!< RPT_AMUX_0.         <i>Offset: 2D8h</i>. */
    volatile uint32_t reserved7[5];           /*!< Reserved.           <i>Offset: 2DCh</i>. */
    volatile uint32_t cfg_tst_0;              /*!< CFG_TST_0.          <i>Offset: 2F0h</i>. */
    volatile uint32_t cfg_tst_1;              /*!< CFG_TST_1.          <i>Offset: 2F4h</i>. */
    volatile uint32_t cfg_cmp_0;              /*!< CFG_CMP_0.          <i>Offset: 2F8h</i>. */
    volatile uint32_t cfg_cmp_1;              /*!< CFG_CMP_1.          <i>Offset: 2FCh</i>. */
    volatile uint32_t rpt_cmp_0;              /*!< RPT_CMP_0.          <i>Offset: 300h</i>. */
    volatile uint32_t rpt_cmp_1;              /*!< RPT_CMP_1.          <i>Offset: 304h</i>. */
} adc_regs_t;

typedef struct adc_ana_regs {
    volatile uint32_t cfg_rx_scratch;         /*!< CFG_RX_SCRATCH.     <i>Offset: 3D0h</i>. */
    volatile uint32_t cfg_ana_0;              /*!< CFG_ANA_0.          <i>Offset: 3D4h</i>. */
    volatile uint32_t cfg_ana_1;              /*!< CFG_ANA_1.          <i>Offset: 3D8h</i>. */
    volatile uint32_t cfg_ana_2;              /*!< CFG_ANA_2.          <i>Offset: 3DCh</i>. */
    volatile uint32_t cfg_ana_3;              /*!< CFG_ANA_3.          <i>Offset: 3E0h</i>. */
    volatile uint32_t cfg_ana_4;              /*!< CFG_ANA_4.          <i>Offset: 3E4h</i>. */
    volatile uint32_t cfg_ana_5;              /*!< CFG_ANA_5.          <i>Offset: 3E8h</i>. */
    volatile uint32_t cfg_ana_6;              /*!< CFG_ANA_6.          <i>Offset: 3ECh</i>. */
    volatile uint32_t cfg_ana_7;              /*!< CFG_ANA_7.          <i>Offset: 3F0h</i>. */
    volatile uint32_t cfg_freg_0;             /*!< CFG_FREG_0.         <i>Offset: 3F4h</i>. */
    volatile uint32_t cfg_freg_1;             /*!< CFG_FREG_1.         <i>Offset: 3F8h</i>. */
    volatile uint32_t cfg_freg_2;             /*!< CFG_FREG_2.         <i>Offset: 3FCh</i>. */
    volatile uint32_t cfg_freg_3;             /*!< CFG_FREG_3.         <i>Offset: 400h</i>. */
    volatile uint32_t cfg_freg_4;             /*!< CFG_FREG_4.         <i>Offset: 404h</i>. */
    volatile uint32_t cfg_freg_5;             /*!< CFG_FREG_5.         <i>Offset: 408h</i>. */
    volatile uint32_t cfg_freg_6;             /*!< CFG_FREG_6.         <i>Offset: 40Ch</i>. */
    volatile uint32_t cfg_freg_7;             /*!< CFG_FREG_7.         <i>Offset: 410h</i>. */
    volatile uint32_t cfg_freg_8;             /*!< CFG_FREG_8.         <i>Offset: 414h</i>. */
    volatile uint32_t cfg_freg_9;             /*!< CFG_FREG_9.         <i>Offset: 418h</i>. */
    volatile uint32_t cfg_freg_10;            /*!< CFG_FREG_10.        <i>Offset: 41Ch</i>. */
    volatile uint32_t cfg_freg_11;            /*!< CFG_FREG_11.        <i>Offset: 420h</i>. */
} adc_ana_regs_t;

/**
 * @brief  PMU registers associated with AFE.
 */
typedef struct adc_pmu_regs {
        volatile uint32_t afe_adc_rst_n;          /*!< AFE_ADC_RST_N.    <i>Offset: 00h</i>. */
        volatile uint32_t afe_adc_ldo_cfg;        /*!< AFE_ADC_LDO_CFG.  <i>Offset: 04h</i>. */
        volatile uint32_t afe_gadc_cfg;           /*!< AFE_GADC_CFG.     <i>Offset: 08h</i>. */
        volatile uint32_t afe_gadc_data_l;        /*!< AFE_GADC_DATA_L.  <i>Offset: 0Ch</i>. */
        volatile uint32_t afe_gadc_data_h;        /*!< AFE_GADC_DATA_H.  <i>Offset: 10h</i>. */
        volatile uint32_t afe_hadc_cfg;           /*!< AFE_HADC_CFG.     <i>Offset: 14h</i>. */
        volatile uint32_t afe_hadc_data_l;        /*!< AFE_HADC_DATA_L.  <i>Offset: 18h</i>. */
        volatile uint32_t afe_hadc_data_h;        /*!< AFE_HADC_DATA_H.  <i>Offset: 1Ch</i>. */
        volatile uint32_t afe_dig_pwr_en;         /*!< AFE_DIG_PWR_EN.   <i>Offset: 20h</i>. */
        volatile uint32_t afe_soft_rst;           /*!< AFE_SOFT_RST.     <i>Offset: 24h</i>. */
        volatile uint32_t afe_clk_en;             /*!< AFE_CLK_EN.       <i>Offset: 28h</i>. */
        volatile uint32_t afe_cmp_alarm_en;       /*!< AFE_CMP_ALARM_EN. <i>Offset: 2ch</i>. */
        volatile uint32_t afe_iso_cfg;            /*!< AFE_ISO_CFG.      <i>Offset: 30h</i>. */
} adc_pmu_regs_t;

/**
 * @brief  DIAG registers associated with AFE.
 */
typedef struct adc_diag_regs0 {
        volatile uint32_t cfg_monitor_sel;                  /*!< CFG_MONITOR_SEL.                <i>Offset: 00h</i>. */
        volatile uint32_t cfg_mcu_diag_trace_save_sel;      /*!< CFG_MCU_DIAG_TRACE_SAVE_SEL.    <i>Offset: 04h</i>. */
        volatile uint32_t cfg_mcu_diag_cpu_trace;           /*!< CFG_MCU_DIAG_CPU_TRACE.         <i>Offset: 08h</i>. */
        volatile uint32_t cfg_mcu_diag_monitor_clock;       /*!< CFG_MCU_DIAG_MONITOR_CLOCK.     <i>Offset: 0ch</i>. */
} adc_diag_regs0_t;

typedef struct adc_diag_regs1 {
        volatile uint32_t cfg_mcu_diag_sample_sel;          /*!< MCU_DIAG_SAMPLE_SEL.            <i>Offset: 100h</i>. */
        volatile uint32_t cfg_mcu_diag_sample_mode;         /*!< MCU_DIAG_SAMPLE_MODE.           <i>Offset: 104h</i>. */
        volatile uint32_t cfg_mcu_diag_sample_length_l;     /*!< MCU_DIAG_SAMPLE_LENGTH_L.       <i>Offset: 108h</i>. */
        volatile uint32_t cfg_mcu_diag_sample_length_h;     /*!< MCU_DIAG_SAMPLE_LENGTH_H.       <i>Offset: 10ch</i>. */
        volatile uint32_t cfg_mcu_diag_sample_start_addr_l; /*!< MCU_DIAG_SAMPLE_START_ADDR_L.   <i>Offset: 110h</i>. */
        volatile uint32_t cfg_mcu_diag_sample_start_addr_h; /*!< MCU_DIAG_SAMPLE_START_ADDR_H.   <i>Offset: 114h</i>. */
        volatile uint32_t cfg_mcu_diag_sample_end_addr_l;   /*!< MCU_DIAG_SAMPLE_END_ADDR_L.     <i>Offset: 118h</i>. */
        volatile uint32_t cfg_mcu_diag_sample_end_addr_h;   /*!< MCU_DIAG_SAMPLE_END_ADDR_H.     <i>Offset: 11ch</i>. */
        volatile uint32_t mcu_diag_sample_done_addr_l;      /*!< MCU_DIAG_SAMPLE_DONE_ADDR_L.    <i>Offset: 120h</i>. */
        volatile uint32_t mcu_diag_sample_done_addr_h;      /*!< MCU_DIAG_SAMPLE_DONE_ADDR_H.    <i>Offset: 124h</i>. */
        volatile uint32_t mcu_diag_sample_done;             /*!< MCU_DIAG_SAMPLE_DONE.           <i>Offset: 128h</i>. */
        volatile uint32_t cfg_aux_adc_sample_period;        /*!< CFG_AUX_ADC_SAMPLE_PERIOD.      <i>Offset: 12ch</i>. */
        volatile uint32_t cfg_adc_dig_pin;                  /*!< CFG_ADC_DIG_PIN.                <i>Offset: 130h</i>. */
} adc_diag_regs1_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif