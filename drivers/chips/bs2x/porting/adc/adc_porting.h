/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides adc port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16， Create file. \n
 */

#ifndef ADC_PORTING_H
#define ADC_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "adc.h"
#include "platform_core.h"
#include "errcode.h"
#include "osal_interrupt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_adc ADC
 * @ingroup  drivers_port
 * @{
 */

/**
 * @brief  device_bs21_port_adc ADC
 */

#define ADC_BASE_ADDR               0x57036000
#define ADC_ANA_OFFSET              0x3D0
#define ADC_PMU_BASE_ADDR           0x57008700
#define ADC_AON_OFFSET              0x220
#define MCU_DIAG_CTL_BASE_ADDR      0x52004000
#define ADC_DIAG_BASE_ADDR          MCU_DIAG_CTL_BASE_ADDR
#define ADC_DIAG_OFFSET             0x100
#define ADC_REFERENCE_VOLTAGE_MV    1500
#define ADC_REF_VOL_DIFFERENCE_MULT 2
#define ADC_TICK2VOL_REF_VOLTAGE_MV (ADC_REFERENCE_VOLTAGE_MV * ADC_REF_VOL_DIFFERENCE_MULT)

#define AFE_ENABLE_INTERRUPT 0

#define COMMON_DEFAULT_CONFIG                           \
{                                                       \
    .ana_div_cyc = 0x27,                                \
    .cfg_clk_div1.b.ana_div_th = 0x4,                   \
    .cfg_clk_div1.b.prechg_div_th = 0x19,               \
    .cfg_gadc_data0.b.data_num = 0x4,                   \
    .cfg_gadc_data0.b.wait_num = 0x4,                   \
    .cfg_gadc_data0.b.cont_mode = CONTIUNE_MODE,        \
    .cfg_gadc_data1.b.osr_len= 5,                       \
    .cfg_gadc_data1.b.osr_sel= 5,                       \
    .cfg_gadc_data1.b.osr_wait_num= 0x12,               \
    .cfg_gadc_data4.b.adc_cdac_fc_scale_div= 0x80,      \
    .cfg_gadc_data4.b.adc_cdac_scale_div_sel= 0x1,      \
    .cfg_freg_10.b.cfg_gadc_short_mode = 1,             \
    .cfg_freg_10.b.cfg_gadc_dly2inject = 1,             \
    .cfg_freg_10.b.cfg_gadc_dly2convstart = 3,          \
    .cfg_freg_10.b.cfg_gadc_dly2srwidth = 2,            \
    .cfg_freg_10.b.cfg_gadc_lsbrpts_en = 1,             \
    .cfg_freg_11.b.cfg_gadc_r_sel_rise = 3,             \
    .cfg_freg_11.b.cfg_gadc_os_range_sel = 1,           \
    .cfg_freg_11.b.reserved7_14 = 3,                    \
    .cfg_freg_11.b.cfg_dreg_iso_enb = 1,                \
}

#define GADC_DEFAULT_CONFIG                             \
{                                                       \
    .diag_node = ADC_ACCUMULATED_AVERAGE_OUTPUT,        \
    .os_cali = true,                                    \
    .cfg_adc_data0.b.data_num = 0xF,                    \
    .cfg_adc_data0.b.wait_num = 4,                      \
    .cfg_adc_data0.b.cont_mode = COUNT_MODE,            \
    .cfg_adc_data1.b.osr_len = 3,                       \
    .cfg_adc_data1.b.osr_sel = 3,                       \
    .cdac_cali = false,                                 \
}

#define AMIC_DEFAULT_CONFIG                             \
{                                                       \
    .diag_node = ADC_ACCUMULATED_AVERAGE_OUTPUT,        \
    .pga_gain = 0x8,                                    \
    .os_cali = true,                                    \
    .cdac_cali = true,                                  \
    .dcoc_cali = true,                                  \
}

/**
 * @brief  ADC channels definition.
 */
typedef enum adc_channel {
    GADC_CHANNEL_0,
    GADC_CHANNEL_1,
    GADC_CHANNEL_2,
    GADC_CHANNEL_3,
    GADC_CHANNEL_4,
    GADC_CHANNEL_5,
    GADC_CHANNEL_6,
    GADC_CHANNEL_7,
    AMIC_CHANNEL_0 = GADC_CHANNEL_6,
    AMIC_CHANNEL_1 = GADC_CHANNEL_7,
    ADC_CHANNEL_MAX_NUM = 8,
    ADC_CHANNEL_NONE = ADC_CHANNEL_MAX_NUM
} adc_channel_t;

/**
 * @if Eng
 * @brief  ADC auto scan frequency which is public used for all channel.
 * @else
 * @brief  adc自动扫描频率，用于所有通道。
 * @endif
 */
typedef enum {
    HAL_ADC_SCAN_FREQ_2HZ,
    HAL_ADC_SCAN_FREQ_4HZ,
    HAL_ADC_SCAN_FREQ_8HZ,
    HAL_ADC_SCAN_FREQ_16HZ,
    HAL_ADC_SCAN_FREQ_32HZ,
    HAL_ADC_SCAN_FREQ_64HZ,
    HAL_ADC_SCAN_FREQ_128HZ,
    HAL_ADC_SCAN_FREQ_256HZ,
    HAL_ADC_SCAN_FREQ_MAX,
    HAL_ADC_SCAN_FREQ_NONE = HAL_ADC_SCAN_FREQ_MAX
} port_adc_scan_freq_t;

/**
 * @brief  AFE interrupt source.
 */
typedef struct adc_irq {
    uint32_t done_irqn;
    uint32_t alarm_irqn;
} adc_irq_t;

#define AFE_INFO_RESERVED 51
// AFE config total 128 bytes
typedef struct {
    uint32_t    rpt_wcal_c17;                        // gadc cdac cal 0x0D4
    uint32_t    rpt_wcal_c16;                        // gadc cdac cal 0x0D8
    uint32_t    rpt_wcal_c15;                        // gadc cdac cal 0x0DC
    uint32_t    rpt_wcal_c14;                        // gadc cdac cal 0x0E0
    uint32_t    rpt_wcal_c13;                        // gadc cdac cal 0x0E4
    uint32_t    rpt_wcal_c12;                        // gadc cdac cal 0x0E8
    uint32_t    rpt_wcal_c11;                        // gadc cdac cal 0x0EC
    uint32_t    rpt_wcal_c10;                        // gadc cdac cal 0x0F0
    uint32_t    rpt_wcal_c9;                         // gadc cdac cal 0x0F4

    uint32_t    cmp_os_code;                         // gadc os cal 0x138

    uint32_t    preamp_os_code;                      // gadc dcoc cal 0x230

    uint32_t    spd_dly_code;                        // gadc spd cal 0x260
} afe_config_t;

/**
 * @brief  Register hal funcs objects into hal_adc module.
 */
void adc_port_register_hal_funcs(void);

/**
 * @brief  Unregister hal funcs objects from hal_adc module.
 */
void adc_port_unregister_hal_funcs(void);

/**
 * @brief  Set the divider number of the peripheral device clock.
 * @param [in] clock The clock which is used for adc sample, adc source clock is 2MHz.
 */
void adc_port_init_clock(adc_clock_t clock);

/**
 * @brief  Set the divider number of the peripheral device clock.
 * @param [in] on Enable or disable.
 */
void adc_port_clock_enable(bool on);

/**
 * @brief  Register the interrupt of adc.
 * @param [in] afe_scan_mode AFE mode to use.
 */
void adc_port_register_irq(afe_scan_mode_t afe_scan_mode);

/**
 * @brief  Unregister the interrupt of adc.
 * @param [in] afe_scan_mode AFE mode which is using.
 */
void adc_port_unregister_irq(afe_scan_mode_t afe_scan_mode);

/**
 * @brief  Power on or power off the peripheral device.
 * @param [in] on Power on or Power off.
 */
void adc_port_power_on(bool on);

/**
 * @brief  Lock of the interrupt.
 * @return The irq status.
 */
inline uint32_t adc_irq_lock(void)
{
    return osal_irq_lock();
}

/**
 * @brief  Unlock of the interrupt.
 * @param [in] irq_sts The irq status to restore.
 */
inline void adc_irq_unlock(uint32_t irq_sts)
{
    osal_irq_restore(irq_sts);
}

/**
 * @brief Set adc calibration code into ADC_BASE_ADDR.
 * @param [in] afe_scan_mode AFE mode to set calibration code.
 * @param [in] afe_config ADC calibration code.
 * @return errcode_t Write result.
 */
errcode_t adc_set_cali_code(afe_scan_mode_t afe_scan_mode, afe_config_t *afe_config);

/**
 * @brief ADC calibration api.
 * @param [in]  afe_scan_mode AFE mode to use.
 * @param [in]  os_cali OS calibration enable.
 * @param [in]  cdac_cali CDAC calibration enable.
 * @param [in]  dcoc_cali DCOC calibration enable(Only enable for HADC).
 * @return errcode_t  Calibration result.
 */
errcode_t adc_calibration(afe_scan_mode_t afe_scan_mode, bool os_cali, bool cdac_cali, bool dcoc_cali);

#if defined(CONFIG_ADC_SUPPORT_QUERY_REGS)
/**
 * @brief  get adc all regs value.
 */
void adc_port_get_regs_value(void);
#endif

/**
 * @brief  ADC ldo manager.
 * @param [in]  enable ADC ldo status.
 */
void adc_port_ldo_enable(bool enable);

/**
 * @brief  Read AFELDO\ADCLDO\VREFLDO trim value from efuse and write to ADC.
 */
void hal_adc_ldo_trim(void);

/**
 * @brief  Trim comparator t0 discrete value.
 */
void adc_port_comparator_t0_trim(void);

/**
 * @brief  Restart cpu trace after ADC sample done.
 */
void hal_cpu_trace_restart(void);

void adc_port_afe_iso_enable(bool en);

/**
 * @brief ADC record calibration code, save calibration code before power off.
 */
afe_config_t adc_get_cali_code(void);

/**
 * @brief ADC set recorded calibration code, refresh calibration code after power on.
 * @param [in]  afe_scan_mode AFE mode to use.
 * @param [in]  afe_config Recorded calibration code.
 */
errcode_t adc_set_cali_code(afe_scan_mode_t afe_scan_mode, afe_config_t *afe_config);

/**
 * @brief ADC entirely open process.
 * @param [in]  channel The ADC channel.
 * @param [in]  self_cali True calibrate currently, False use recorded code.
 */
errcode_t adc_port_gadc_entirely_open(adc_channel_t channel, bool self_cali);

/**
 * @brief ADC entirely sample process.
 * @param [in]  channel The ADC channel.
 * @retval ADC sample millivolt(mV) value.
 */
int32_t adc_port_gadc_entirely_sample(adc_channel_t channel);

/**
 * @brief ADC entirely close process.
 * @param [in]  channel The ADC channel.
 */
errcode_t adc_port_gadc_entirely_close(adc_channel_t channel);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif