/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides hal trng v1 regs def\n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-01, Create file. \n
 */
#ifndef HAL_TRNG_V1_REGS_DEF_H
#define HAL_TRNG_V1_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_hal_trng_v1_regs_def Regs Definition
 * @ingroup  drivers_hal_trng_v1
 * @{
 */

/**
 * @brief  This union represents the bit fields in the trng ctrl register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_ctrl {
    struct {
        uint32_t    health_test_en        : 1;             /*!< Indicates whether the health test is enabled.
                                                                By default, the health test is disabled. */
        uint32_t    online_test_en        : 1;             /*!< Online test enable. This function is enabled by
                                                                default. */
        uint32_t    post_proc_en          : 1;             /*!< Raw register data. */
        uint32_t    rnd_chk_en            : 1;             /*!< Indicates whether to enable failure detection.
		                                                        This function is enabled by default. */
        uint32_t    lfsr_reseed_en        : 1;             /*!< LFSR supplementation enable. This function is enabled
                                                                by default. */
        uint32_t    private_en            : 1;             /*!< Private channel enable. This function is enabled by
                                                                default. */
        uint32_t    reserved_0            : 26;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_ctrl_t;

/**
 * @brief  This union represents the bit fields in the trng src sel register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_src_sel {
    struct {
        uint32_t    trng_sel              : 2;             /*!< Entropy source selection:
                                                                2'b00: RO ring entropy source output
                                                                2'b01: The tero ring entropy source is selected
                                                                for output. The tero ring generates random numbers
                                                                slowly.
                                                                2'b10: Select the output of the fro ring entropy
                                                                source. 2'b11: Selects the XOR output of all entropy
                                                                sources. */
        uint32_t    reserved_0            : 30;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_src_sel_t;

/**
 * @brief  This union represents the bit fields in the trng frp sel register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fro_sel {
    struct {
        uint32_t    fro_sel               : 5;             /*!< Entropy source selection:
		                                                        5'h0: Selects the output of fro ring 0
                                                                5'h1: Selects the output of fro ring 1.
                                                                ......
                                                                5'hf: selects the output of fro ring 15.
                                                                Others: Select the XOR output of all fro rings. */
        uint32_t    reserved_0            : 27;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fro_sel_t;

/**
 * @brief  This union represents the bit fields in the trng all reg lock register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_all_reg_lock {
    struct {
        uint32_t    trng_all_reg_lock     : 1;             /*!< TRNG global latch register
		                                                        (after the latch is valid, it can be unlocked only by
                                                                reset):
                                                                0x0: The latch is invalid.
                                                                0x1: The latch is valid. Only offset addresses 0x100,
                                                                0x104, and 0x108 can be read. Other registers cannot
                                                                be read or written, and the return value is 0. */
        uint32_t    reserved_0            : 31;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_all_reg_lock_t;

/**
 * @brief  This union represents the bit fields in the trng low power enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_low_power_enable {
    struct {
        uint32_t    trng_low_power_enable : 1;             /*!< Low power consumption enable. This function is enabled
		                                                        by default. */
        uint32_t    reserved_0            : 31;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_low_power_enable_t;

/**
 * @brief  This union represents the bit fields in the trng ring enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_ring_en {
    struct {
        uint32_t    ro_en                 : 1;             /*!< RO ring oscillation enable. This function
                                                                is enabled by default. */
        uint32_t    tero_en               : 1;             /*!< Indicates whether to enable the ERO ring oscillation.
		                                                        This function is enabled by default. */
        uint32_t    fro_en                : 1;             /*!< Fro ring flapping enable. By default,
                                                                this function is disabled. */
        uint32_t    reserved_0            : 29;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_ring_en_t;

/**
 * @brief  This union represents the bit fields in the trng ro timer count register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_ro_timer_cnt {
    struct {
        uint32_t    ro_timer_cnt          : 16;            /*!< Configured value of the output timing sampling
                                                                ounter of the RO ring noise source(to ensure
                                                                that the rates of the RO ring noise source are
                                                                close to those of the RO ring noise source).
                                                                0x0: The RO ring is not controlled. 0x1: When the
                                                                internal counter is 1, the noise source of the RO
                                                                ring is gated to the output.
                                                                ............
                                                                0xffff: When the internal counter is 0xffff,
                                                                the noise source output of the RO ring is gated. */
        uint32_t    reserved_0            : 16;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_ro_timer_cnt_t;

/**
 * @brief  This union represents the bit fields in the trng tero bit select register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_tero_bit_sel {
    struct {
        uint32_t    tero_bit_sel          : 2;             /*!< tero ring counter output bit select
                                                                2'b00: Bit 0 of the counter is selected as
                                                                the random number output.
                                                                2'b01: Bit 1 of the counter is selected as the
                                                                random number output.
                                                                Others: Bit 2 of the counter is selected as the
                                                                random number output. */
        uint32_t    reserved_0            : 30;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_tero_bit_sel_t;

/**
 * @brief  This union represents the bit fields in the trng tero vctr cfg register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_tero_vctr_cfg {
    struct {
        uint32_t    tero_vctr_low_cfg     : 16;            /*!< v_ctr low-level time configuration */
        uint32_t    tero_vctr_cfg         : 16;            /*!< V_ctr high-level time configuration. The value ranges
		                                                        from 0x20 to 0xffff. If the value exceeds the value
                                                                range,
                                                                the default value is used. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_tero_vctr_cfg_t;

/**
 * @brief  This union represents the bit fields in the trng online test fail check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_online_test_fail_ck_th {
    struct {
        uint32_t    online_test_fail_ck_cnt : 4;           /*!< Indicates the threshold for consecutive online test
                                                                failures. When the number of consecutive online test
                                                                failures reaches the threshold, an alarm is
                                                                reported.. */
        uint32_t    reserved_0            : 28;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_online_test_fail_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng monobit test check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_monobit_test_ck_th {
    struct {
        uint32_t    mono_ck_low           : 7;             /*!< Minimum threshold of the monobit test. */
        uint32_t    reserved_0            : 9;             /*!< reserved. */
        uint32_t    mono_ck_hig           : 7;             /*!< Maximum threshold of the monobit test. */
        uint32_t    reserved_1            : 9;             /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_monobit_test_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng long run test check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_long_run_test_ck_th {
    struct {
        uint32_t    long_run_hig          : 8;             /*!< Maximum threshold of the long run test. */
        uint32_t    reserved_0            : 24;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_long_run_test_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng run1 test check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_run1_test_ck_th {
    struct {
        uint32_t    run_0_ck_low          : 7;             /*!< Minimum threshold for run test(1'b0). */
        uint32_t    reserved_0            : 1;             /*!< reserved. */
        uint32_t    run_0_ck_hig          : 7;             /*!< Maximum threshold of run test(1'b0). */
        uint32_t    reserved_1            : 1;             /*!< reserved. */
        uint32_t    run_1_ck_low          : 7;             /*!< Minimum threshold for run test(1'b1). */
        uint32_t    reserved_2            : 1;             /*!< reserved. */
        uint32_t    run_1_ck_hig          : 7;             /*!< Maximum threshold of run test(1'b1). */
        uint32_t    reserved_3            : 1;             /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_run1_test_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng run2 test check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_run2_test_ck_th {
    struct {
        uint32_t    run_00_ck_low         : 6;             /*!< Minimum threshold for run test (2'b00). */
        uint32_t    reserved_0            : 2;             /*!< reserved. */
        uint32_t    run_00_ck_hig         : 6;             /*!< Maximum threshold for run test (2'b00). */
        uint32_t    reserved_1            : 2;             /*!< reserved. */
        uint32_t    run_11_ck_low         : 6;             /*!< Minimum threshold for run test (2'b11). */
        uint32_t    reserved_2            : 2;             /*!< reserved. */
        uint32_t    run_11_ck_hig         : 6;             /*!< Maximum threshold of run test (2'b11). */
        uint32_t    reserved_3            : 2;             /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_run2_test_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng poker test check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_poker_test_ck_th {
    struct {
        uint32_t    poker_ck_hig          : 11;            /*!< Maximum threshold of the poker test. */
        uint32_t    reserved_0            : 21;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_poker_test_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng rpt test check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_rpt_test_th {
    struct {
        uint32_t    rpt_cnt_test          : 8;             /*!< Threshold for comparison of repetition count:
		                                                        The value ranges from 1 to 255. If the value is 0,
                                                                the value is forcibly set to 254. */
        uint32_t    reserved_0            : 24;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_rpt_test_th_t;

/**
 * @brief  This union represents the bit fields in the trng rpt adapt check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_adapt_test_th {
    struct {
        uint32_t    adapt_low_test        : 10;            /*!< Indicates the minimum threshold for the adaptive
                                                                ratio test. */
        uint32_t    reserved_0            : 6;             /*!< reserved. */
        uint32_t    adapt_hig_test        : 10;            /*!< Maximum threshold of the adaptive proportion test. */
        uint32_t    reserved_1            : 6;             /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_adapt_test_th_t;

/**
 * @brief  This union represents the bit fields in the trng total failure check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_total_failure_test_ck_th {
    struct {
        uint32_t    total_failure_ck_hig  : 11;            /*!< Maximum threshold for complete failure test. */
        uint32_t    reserved_0            : 21;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_total_failure_test_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng rnd test failure check thread register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_rnd_test_fail_ck_th {
    struct {
        uint32_t    rnd_fail_ck_cnt       : 3;             /*!< Threshold for consecutive failures in the random
                                                                number invalidation test. When the number of
                                                                consecutive failures in the invalidation test reaches
                                                                this threshold, an alarm is reported. The value ranges
                                                                from 1 to 7. If the value exceeds the value range,
                                                                the value is 7. */
        uint32_t    reserved_0            : 29;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_rnd_test_fail_ck_th_t;

/**
 * @brief  This union represents the bit fields in the trng fifo ready register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fifo_ready {
    struct {
        uint32_t    trng_ready            : 1;             /*!< Check whether a valid random number exists in
                                                                 the random number FIFO. */
        uint32_t    trng_done             : 1;             /*!< Indicates whether a random number has been
                                                                 generated by the TRNG. */
        uint32_t    reserved_0            : 30;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fifo_ready_t;

/**
 * @brief  This union represents the bit fields in the trng data status register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_data_st {
    struct {
        uint32_t    rng_fifo_real_cnt     : 5;             /*!< Number of random numbers in the FIFO. */
        uint32_t    reserved_0            : 27;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_data_st_t;

/**
 * @brief  This union represents the bit fields in the trng alarm register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarm {
    struct {
        uint32_t    rpt_test_alarm        : 1;             /*!< repetition count test alarm. */
        uint32_t    adapt_test_alarm      : 1;             /*!< adaptive proportion test alarm. */
        uint32_t    total_failure_test_alarm : 1;          /*!< Chi-square test alarm. */
        uint32_t    online_test_alarm     : 1;             /*!< Online test alarm. */
        uint32_t    rn_chk_alarm          : 1;             /*!< Random number failure test alarm. */
        uint32_t    crc_alarm             : 1;             /*!< CRC check error alarm. */
        uint32_t    prt_alarm             : 1;             /*!< Key Signal Robustness Alarm. */
        uint32_t    reserved_0            : 25;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_alarm_t;

/**
 * @brief  This union represents the bit fields in the trng alarm post register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarm_post {
    struct {
        uint32_t    rpt_test_alarm_post   : 1;             /*!< Masked repetition count  Test Alarms. */
        uint32_t    adapt_test_alarm_post : 1;             /*!< Masked adaptive proportion Test Alarms. */
        uint32_t    total_failure_test_alarm_post : 1;     /*!< Masked chi-square failure test alarm. */
        uint32_t    online_test_alarm_post : 1;            /*!< Masked online test alarms. */
        uint32_t    rn_chk_alarm_post     : 1;             /*!< Masked random number failure test alarm. */
        uint32_t    crc_alarm_post        : 1;             /*!< Masked CRC error alarm. */
        uint32_t    prt_alarm_post        : 1;             /*!< Masked Key Signal Robustness Alarm. */
        uint32_t    reserved_0            : 25;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_alarm_post_t;

/**
 * @brief  This union represents the bit fields in the trng alarm mask register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarm_mask {
    struct {
        uint32_t    trng_alarm_mask       : 5;             /*!< [0]: Whether to mask the complete failure test alarm
                                                                [1]: Indicates whether to enable the online test alarm
                                                                mask function.
                                                                [2]: Whether to mask the random number failure test
                                                                alarm.
                                                                [3]: Indicates whether to mask CRC error alarms.
                                                                [4]: The key signal robustness alarm mask is enabled.
                                                                1'b1 indicates that the mask is valid. By default,
                                                                the mask is enabled and valid.
                                                                1'b0 indicates that the mask is invalid. */
        uint32_t    reserved_0            : 27;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_alarm_mask_t;

/**
 * @brief  This union represents the bit fields in the trng alarm clear register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarm_clr {
    struct {
        uint32_t    trng_alarm_clr        : 1;             /*!< Internal alarm clearance register of
                                                                the TRNG module. */
        uint32_t    reserved_0            : 31;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_alarm_clr_t;

/**
 * @brief  This union represents the bit fields in the trng tero count sel register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_tero_cnt_sel {
    struct {
        uint32_t    tero_cnt_sel          : 4;             /*!< 0: The counter of ERO ring 0 is selected...
                                                                7: The counter of tero ring 7 is selected. */
        uint32_t    reserved_0            : 28;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_tero_cnt_sel_t;

/**
 * @brief  This union represents the bit fields in the trng tero ring count register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_tero_ring_cnt {
    struct {
        uint32_t    tero_ring_cnt         : 16;            /*!< Count value of the tero ring counter. */
        uint32_t    reserved_0            : 16;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_tero_ring_cnt_t;

/**
 * @brief  This union represents the bit fields in the trng fro force reset register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fro_force_rst {
    struct {
        uint32_t    fro_force_rst_n       : 1;             /*!< Forcible reset control of the fro ring:
                                                                1'b0: reset 1'b1: not reset */
        uint32_t    reserved_0            : 31;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fro_force_rst_t;

/**
 * @brief  This union represents the bit fields in the trng fro sample clk sel register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fro_sample_clk_sel {
    struct {
        uint32_t    fro_sample_clk_sel    : 1;             /*!< Sampling clock select of the fro ring:
                                                                1'b0: Select the sampling clock input by the TRNG
                                                                externally.
                                                                1'b1: selects the clock output by the internal fro
                                                                ring. */
        uint32_t    reserved_0            : 31;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fro_sample_clk_sel_t;

/**
 * @brief  This union represents the bit fields in the trng fro div count register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fro_div_cnt {
    struct {
        uint32_t    fro_div_cnt           : 8;             /*!< Internal fro ring frequency divider:
		                                                        0: divide-by-2
		                                                        1: divide-by-four
		                                                        2: divide-by-6 */
        uint32_t    reserved_0            : 24;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fro_div_cnt_t;

/**
 * @brief  This union represents the bit fields in the trng fro count select register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fro_cnt_sel {
    struct {
        uint32_t    fro_cnt_sel           : 5;             /*!< 5'h0: selects the counter of fro ring 0 ...
                                                                5'hf: selects the counter of fro ring 15 . */
        uint32_t    reserved_0            : 27;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fro_cnt_sel_t;

/**
 * @brief  This union represents the bit fields in the trng fro ring count register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_fro_ring_cnt {
    struct {
        uint32_t    fro_cnt_n             : 16;            /*!< Count value of the falling edge counter of the
                                                                fro ring. */
        uint32_t    fro_cnt_p             : 16;            /*!< Count value of the rising edge counter of the
                                                                fro ring. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_fro_ring_cnt_t;

/**
 * @brief  This union represents the bit fields in the trng real clock enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_real_clock_en {
    struct {
        uint32_t    low_power_en          : 6;             /*!< Clock (low-power control) enable  */
        uint32_t    reserved_0            : 26;            /*!< reserved. */
    } b;
    uint32_t    d32;                                       /*!< Raw register data. */
} trng_real_clock_en_t;

/**
 * @brief  Registers associated with trng.
 */
typedef struct trng_regs_v1 {
    volatile trng_ctrl_t        trng_ctrl;                                    /*!< TRNG control information. */
    volatile trng_src_sel_t     trng_src_sel;                                 /*!< TRNG Entropy Source Selection. */
    volatile trng_fro_sel_t     trng_fro_sel;                                 /*!< Selection of FRO Ring Entropy Source
                                                                                   for TRNG. */
    volatile uint32_t           reserved_0;                                   /*!< reserved. */
    volatile trng_all_reg_lock_t   trng_all_reg_lock;                         /*!< All latch signals of the TRNG
                                                                                   register. */
    volatile uint32_t           reserved_1[3];                                /*!< reserved. */
    volatile trng_low_power_enable_t   trng_low_power_enable;                 /*!< TRNG low power consumption enable
                                                                                   control. */
    volatile trng_ring_en_t   trng_ring_en;                                   /*!< TRNG RO ring timing sampling
                                                                                   counter. */
    volatile uint32_t           reserved_2[2];                                /*!< reserved. */
    volatile trng_ro_timer_cnt_t   trng_ro_timer_cnt;                         /*!< TRNG RO ring timing sampling
                                                                                   counter. */
    volatile uint32_t           reserved_3[3];                                /*!< reserved. */
    volatile trng_tero_bit_sel_t   trng_tero_bit_sel;                         /*!< Output bit select of the TRNG
                                                                                   TERO ring counter. */
    volatile trng_tero_vctr_cfg_t   trng_tero_vctr_cfg;                       /*!< High/low level time configuration
                                                                                   of the TRNG TERO ring control
                                                                                   signal v_ctr. */
    volatile uint32_t           reserved_4[6];                                /*!< reserved. */
    volatile trng_online_test_fail_ck_th_t   trng_online_test_fail_ck_th;     /*!< Threshold for consecutive failures
                                                                                   in the TRNG online test. */
    volatile trng_monobit_test_ck_th_t   trng_monobit_test_ck_th;             /*!< Monobit test threshold
                                                                                   configuration. */
    volatile trng_long_run_test_ck_th_t   trng_long_run_test_ck_th;           /*!< Long run test threshold
                                                                                   configuration. */
    volatile trng_run1_test_ck_th_t   trng_run1_test_ck_th;                   /*!< Run1 test threshold configuration. */
    volatile trng_run2_test_ck_th_t   trng_run2_test_ck_th;                   /*!< Run2 test threshold configuration. */
    volatile trng_poker_test_ck_th_t   trng_poker_test_ck_th;                 /*!< Configuring the poker test
                                                                                   threshold. */
    volatile trng_rpt_test_th_t   trng_rpt_test_th;                           /*!< Threshold of Repetition count in the
                                                                                   HEALTH TEST. */
    volatile trng_adapt_test_th_t   trng_adapt_test_th;                       /*!< Threshold of Adaptive Proportion in
                                                                                   HEALTH TEST. */
    volatile trng_total_failure_test_ck_th_t   trng_total_failure_test_ck_th; /*!< Total Failure Test Threshold
                                                                                   Configuration. */
    volatile trng_rnd_test_fail_ck_th_t   trng_rnd_test_fail_ck_th;           /*!< Threshold for consecutive failures
                                                                                   in the TRNG random number
                                                                                   invalidation test. */
    volatile uint32_t           reserved_5[30];                               /*!< reserved. */
    volatile uint32_t           trng_fifo_data;                               /*!< TRNG FIFO data register. */
    volatile trng_fifo_ready_t   trng_fifo_ready;                             /*!< TRNG random number status. */
    volatile trng_data_st_t   trng_data_st;                                   /*!< TRNG random number FIFO status. */
    volatile uint32_t           reserved_6;                                   /*!< reserved. */
    volatile trng_alarm_t   trng_alarm;                                       /*!< TRNG alarm source. */
    volatile trng_alarm_post_t   trng_alarm_post;                             /*!< Alarm Source After TRNG Masking. */
    volatile trng_alarm_mask_t   trng_alarm_mask;                             /*!< TRNG Alarm Shielding
                                                                                   Configuration. */
    volatile trng_alarm_clr_t   trng_alarm_clr;                               /*!< Alarm source and masked alarm
                                                                                   source status clear register. */
    volatile uint32_t           reserved_7[16];                               /*!< reserved. */
    volatile trng_tero_cnt_sel_t   trng_tero_cnt_sel;                         /*!< TRNG TERO ring counter selection
                                                                                   configuration. */
    volatile trng_tero_ring_cnt_t   trng_tero_ring_cnt;                       /*!< Count value of TRNG's TERO ring
                                                                                   counter. */
    volatile uint32_t           reserved_8[2];                                /*!< reserved. */
    volatile trng_fro_force_rst_t   trng_fro_force_rst;                       /*!< TRNG FRO ring reset control. */
    volatile trng_fro_sample_clk_sel_t   trng_fro_sample_clk_sel;             /*!< TRNG FRO ring sampling clock
                                                                                   select. */
    volatile trng_fro_div_cnt_t   trng_fro_div_cnt;                           /*!< Frequency divider of the output
                                                                                   clock of the internal FRO ring of
                                                                                   the TRNG. */
    volatile trng_fro_cnt_sel_t   trng_fro_cnt_sel;                           /*!< TRNG FRO ring counter selection
                                                                                   configuration. */
    volatile trng_fro_ring_cnt_t   trng_fro_ring_cnt;                         /*!< Count value of the TRNG FRO ring
                                                                                   counter. */
    volatile uint32_t           trng_fro_div_clk_cnt;                         /*!< Counter for the frequency division
                                                                                   clock of the FRO ring inside the
                                                                                   TRNG. */
    volatile uint32_t           trng_fro_cnt_clk_cnt;                         /*!< Counter of the FRO ring count clock
                                                                                   inside the TRNG. */
    volatile uint32_t           reserved_9[21];                               /*!< reserved. */
    volatile trng_real_clock_en_t   trng_real_clock_en;                       /*!< TRNG real clock enable. */
    volatile uint32_t           reserved_10[7];                               /*!< reserved. */
    volatile uint32_t           trng_ver_num;                                 /*!< TRNG version number. */
} trng_regs_v1_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif