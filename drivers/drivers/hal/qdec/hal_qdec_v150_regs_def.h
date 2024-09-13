/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides V150 qdec register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16, Create file. \n
 */
#ifndef HAL_QDEC_V150_REGS_DEF_H
#define HAL_QDEC_V150_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_qdec_v150_regs_def QDEC V150 Regs Definition
 * @ingroup  drivers_hal_qdec
 * @{
 */

/**
 * @brief  This union represents the bit fields in the module startup register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_task_start {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t start             : 1;    /*!< When the signal is activated, the module's sampling register
                                                         starts to sample continuously and accumulates the samples at
                                                         a given frequency. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_task_start_t;

/**
 * @brief  This union represents the bit fields in the module stop control register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_task_stop {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t stop              : 1;    /*!< When the signal triggers, the quadrature encoding block is
                                                         paused and the state of the internal register is retained. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_task_stop_t;

/**
 * @brief  This union represents the bit fields in the module read clear operation register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_task_readclr_acc {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t readclr_acc       : 1;    /*!< Read accumulation operation register of the module. After
                                                         triggering, read the accumulator ACC and ACCDBL results of
                                                         the current module and clear the accumulator. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_task_readclr_acc_t;

/**
 * @brief  This union represents the bit fields in the module accumulator ACC read clear operation register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_task_rd_clr_acc {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t rd_clr_acc        : 1;    /*!< Read accumulation operation register of the module. After
                                                         triggering, read the accumulator result of the current module
                                                         and clear the accumulator. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_task_rd_clr_acc_t;

/**
 * @brief  This union represents the bit fields in the module accumulator ACCDBL read clear operation register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_task_rd_clr_dbl {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t rd_clr_dbl        : 1;    /*!< Read accumulation operation register of the module. After
                                                     triggering, read the accumulator result of the current module
                                                     and clear the accumulator. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_task_rd_clr_dbl_t;

/**
 * @brief  This union represents the bit fields in the global enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_enable {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t en                : 1;    /*!< value1: enabled.
                                                         value0: disable the function and clear the system. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_enable_t;

/**
 * @brief  This union represents the bit fields in the interrupt status query register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_event_int_sts {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t events_stopped    : 1;    /*!< QDEC quadrature encoding modules are stopped. */
        volatile uint32_t acc_rdy           : 1;    /*!< An overflow occurs in the adder shared by the ACC and DBL. */
        volatile uint32_t dbl_rdy           : 1;    /*!< Indicates whether the accumulator accdbl is accumulated. */
        volatile uint32_t report_rdy        : 1;    /*!< Acc count reaches the threshold by the REPORTPER register. */
        volatile uint32_t sample_rdy        : 1;    /*!< The register is set to 1 when the encoder completes a sampling
                                                         and the sample value is written to the sampling register. */
        volatile uint32_t reserved5_15      : 11;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_event_int_sts_t;

/**
 * @brief  This union represents the bit fields in the interrupt enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_int_en {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t stopped           : 1;    /*!< Stop interrupt enable. */
        volatile uint32_t acc_en            : 1;    /*!< Acc interrupt enable. */
        volatile uint32_t dbl_en            : 1;    /*!< Accdbl interrupt enable. */
        volatile uint32_t report_en         : 1;    /*!< Report interrupt enable. */
        volatile uint32_t sample_en         : 1;    /*!< Sampling interrupt enable. */
        volatile uint32_t reserved5_15      : 11;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_int_en_t;

/**
 * @brief  This union represents the bit fields in the interrupt clear register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_int_clr {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t stop_int_clr      : 1;    /*!< Stop interrupt clear. */
        volatile uint32_t acc_clr           : 1;    /*!< Acc interrupt clear. */
        volatile uint32_t dbl_clr           : 1;    /*!< Accdbl interrupt clear. */
        volatile uint32_t report_clr        : 1;    /*!< Report interrupt clear. */
        volatile uint32_t sample_clr        : 1;    /*!< Sampling interrupt clear. */
        volatile uint32_t reserved5_15      : 11;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_int_clr_t;


/**
 * @brief  This union represents the bit fields in the LED polarity configuration register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_ledpol_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t pol               : 1;    /*!< LED polarity configuration register. */
        volatile uint32_t en                : 1;    /*!< Enables or disables the LED function. */
        volatile uint32_t reserved2_15      : 11;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_ledpol_data_t;

/**
 * @brief  This union represents the bit fields in the data sampling period configuration register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_sampleper_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t period            : 4;    /*!< Sampling period configuration, which is provided by the
                                                         internal counter of the module. */
        volatile uint32_t clk_freq          : 1;    /*!< This configuration indicates the frequency of the clock. */
        volatile uint32_t reserved5_15      : 11;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_sampleper_data_t;

/**
 * @brief  This union represents the bit fields in the report period configuration register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_reporter_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t samlple_repo_val  : 3;    /*!< Indicates the number of sampled values reported a time. */
        volatile uint32_t reserved3_15      : 13;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_reporter_data_t;

/**
 * @brief  This union represents the bit fields in the debounce filter configuration register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_defen_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t en                : 1;    /*!< Digital filter enable signal. */
        volatile uint32_t reserved1_3       : 3;    /*!< Reserved */
        volatile uint32_t defen_num         : 3;    /*!< The signal is stable for sampling period number. */
        volatile uint32_t reserved7_15      : 9;    /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_defen_data_t;

/**
 * @brief  This union represents the bit fields in the Number of cycles for enabling the LED signal in advance register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_ledpre_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t led_pre           : 10;   /*!< Number of cycles during which the LED indicator is turned on in
                                                        advance. */
        volatile uint32_t reserved10_15     : 6;    /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_ledpre_data_t;

/**
 * @brief  This union represents the bit fields in the quadrature encoded Value register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_sample_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t sample_val        : 3;    /*!< Sampling code value of the sample. */
        volatile uint32_t reserved3_15      : 13;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_sample_data_t;

/**
 * @brief  This union represents the bit fields in the quadrature coded displacement accumulation register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_acc_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t acc_rd_val        : 16;   /*!< Accumulated value of the encoding shift. */
    } b;                                            /*!< Register bits. */
} qdec_acc_data_t;

/**
 * @brief  This union represents the bit fields in the invalid transition sample accumulation register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_accdbl_data {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t dbl_rd_val        : 4;    /*!< Stores the cumulative value of invalid transition. */
        volatile uint32_t reserved4_15      : 12;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_accdbl_data_t;

/**
 * @brief  This union represents the bit fields in the accumulated value read register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_acc_read {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t acc_rd_val_shadow : 16;   /*!< Accumulated value of the encoding shift. */
    } b;                                            /*!< Register bits. */
} qdec_acc_read_t;

/**
 * @brief  This union represents the bit fields in the invalid transition sample accumulation value read register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_accdbl_read {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t dbl_rd_val_shadow : 4;    /*!< Stores the cumulative value of invalid transition. */
        volatile uint32_t reserved4_15      : 12;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_accdbl_read_t;

/**
 * @brief  This union represents the bit fields in the count event register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_acc_event {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t acc_event_cnt     : 9;    /*!< acc count event. */
        volatile uint32_t reserved9_15      : 7;    /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_acc_event_t;

/**
 * @brief  This union represents the bit fields in the select I/O source under the FPGA version register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_fpga_io_sel {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t fpga_io_src       : 1;    /*!< PAD input source select of the QDEC in FPGA mode. */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_fpga_io_sel_t;

/**
 * @brief  This union represents the bit fields in the QDEC clock control register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_clk_ctl {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t sel               : 1;    /*!< QDEC clock switching. */
        volatile uint32_t reserved1_3       : 3;    /*!< Reserved */
        volatile uint32_t en                : 1;    /*!< QDEC clock enable */
        volatile uint32_t reserved5_15      : 11;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_clk_ctl_t;

/**
 * @brief  This union represents the bit fields in the soft reset register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_soft_rst {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t soft_rst          : 1;    /*!< QDEC soft reset */
        volatile uint32_t reserved1_15      : 15;   /*!< Reserved */
    } b;                                            /*!< Register bits. */
} qdec_soft_rst_t;

/**
 * @brief  Main registers associated with Qdec.
 */
typedef struct qdec_regs {
    volatile uint32_t reseved1;                      /*!< reserved.       <i>Offset: 00h</i>. */
    volatile uint32_t qdec_task_start;               /*!< start.          <i>Offset: 04h</i>. */
    volatile uint32_t qdec_task_stop;                /*!< stop.           <i>Offset: 08h</i>. */
    volatile uint32_t qdec_task_readclr_acc;         /*!< readclr acc.    <i>Offset: 0Ch</i>. */
    volatile uint32_t qdec_task_rd_clr_acc;          /*!< rd clr acc.     <i>Offset: 10h</i>. */
    volatile uint32_t qdec_task_rd_clr_dbl;          /*!< rd clr dbl.     <i>Offset: 14h</i>. */
    volatile uint32_t qdec_enable;                   /*!< enable.         <i>Offset: 18h</i>. */
    volatile uint32_t reserve2;                      /*!< reserved.       <i>Offset: 1Ch</i>. */
    volatile uint32_t qdec_event_int_sts;            /*!< int status.     <i>Offset: 20h</i>. */
    volatile uint32_t reserve3[4];                   /*!< reserved.       <i>Offset: 24h</i>. */
    volatile uint32_t qdec_int_en;                   /*!< int enable.     <i>Offset: 34h</i>. */
    volatile uint32_t qdec_int_clr;                  /*!< int clear.      <i>Offset: 38h</i>. */
    volatile uint32_t qdec_ledpol_data;              /*!< ledpol data.    <i>Offset: 3Ch</i>. */
    volatile uint32_t qdec_sampleper_data;           /*!< sampleper data. <i>Offset: 40h</i>. */
    volatile uint32_t qdec_reporter_data;            /*!< reporter data.  <i>Offset: 44h</i>. */
    volatile uint32_t qdec_defen_data;               /*!< defen data.     <i>Offset: 48h</i>. */
    volatile uint32_t qdec_ledpre_data;              /*!< ledpre data.    <i>Offset: 4Ch</i>. */
    volatile uint32_t qdec_sample_data;              /*!< sample data.    <i>Offset: 50h</i>. */
    volatile uint32_t qdec_acc_data;                 /*!< acc data.       <i>Offset: 54h</i>. */
    volatile uint32_t qdec_accdbl_data;              /*!< accdbl data.    <i>Offset: 58h</i>. */
    volatile uint32_t qdec_acc_read;                 /*!< acc read.       <i>Offset: 5Ch</i>. */
    volatile uint32_t qdec_accdbl_read;              /*!< accdbl read.    <i>Offset: 60h</i>. */
    volatile uint32_t qdec_acc_event;                /*!< acc event.      <i>Offset: 64h</i>. */
    volatile uint32_t qdec_fpga_io_sel;              /*!< fpga io sel.    <i>Offset: 68h</i>. */
    volatile uint32_t reserve4;                      /*!< reserved.       <i>Offset: 6Ch</i>. */
    volatile uint32_t qdec_clk_ctl;                  /*!< clk ctl.        <i>Offset: 70h</i>. */
    volatile uint32_t qdec_soft_rst;                 /*!< soft rst.       <i>Offset: 74h</i>. */
} qdec_regs_t;

/**
 * @brief  This union represents the bit fields in the clock divider register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union qdec_clk_div {
    volatile uint32_t d32;                                   /*!< Raw register data. */
    struct {
        volatile uint32_t num                       : 7;    /*!< QDEC clock divider number */
        volatile uint32_t load_en                   : 1;    /*!< QDEC clock divider load enable */
        volatile uint32_t en                        : 1;    /*!< QDEC clock divider enable */
        volatile uint32_t reserved9_15              : 7;    /*!< Reserved */
    } b;                                                    /*!< Register bits. */
} qdec_clk_div_t;

/**
 * @brief  Clock driver register for Qdec.
 */
typedef struct qdec_regs_clk_div {
    volatile uint32_t qdec_clk_div;                  /*!< clock driver.   <i>Offset: 00h</i>. */
} qdec_regs_clk_div_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
