/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V150 rtc register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-12-07, Create file. \n
 */
#ifndef HAL_RTC_V150_REGS_DEF_H
#define HAL_RTC_V150_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_rtc_v150_regs_def RTC V150 Regs Definition
 * @ingroup  drivers_hal_rtc
 * @{
 */

#define TIME_CHGI_VMID_NUM      8
#define TIME_CHGI_IDX_NUM       16

/**
 * @brief  This union represents the bit fields in the Control
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union rtc_v150_control_reg_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t enable         : 1;    /*!< RTC enable bit. */
        uint32_t mode           : 2;    /*!< RTC mode bit. */
        uint32_t int_mask       : 1;    /*!< RTC interrupt mask bit. */
        uint32_t rstfsm         : 1;    /*!< RTC reset signal bit. */
        uint32_t cnt_req        : 1;    /*!< RTC count lock request signal bit. */
        uint32_t cnt_lock       : 1;    /*!< RTC count lock signal bit. */
        uint32_t reserved_25    : 25;
    } b;                                /*!< Register bits. */
} rtc_v150_control_reg_data_t;

/**
 * @brief  This union represents the bit fields in the  End-of-Interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union rtc_v150_eoi_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t eoi            : 1;    /*!< Reading from this register returns zeroes(0) and clear the interrupt. */
        uint32_t reserved1_31   : 31;
    } b;                                /*!< Register bits. */
} rtc_v150_eoi_data_t;

/**
 * @brief  This union represents the bit fields in the Interrupt Status
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union rtc_v150_int_status_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t int_status     : 1;    /*!< Contains the interrupt status for RTC. */
        uint32_t reserved1_31   : 31;
    } b;                                /*!< Register bits. */
} rtc_v150_int_status_data_t;

/**
 * @brief  Registers associated with common rtc.
 */
typedef struct rtcs_v150_regs {
    volatile uint32_t     lock;                           /*!< RTC write lock/unlock registers. <i>Offset: 00h</i>. */
    volatile uint32_t     vmid_en;                        /*!< RTC vmid enable check registers. <i>Offset: 04h</i>. */
    volatile uint32_t     comm_vmid;                      /*!< RTC COMM vmid permission check registers.
                                                               <i>Offset: 08h</i>. */
    volatile uint32_t     comm_reserved;                  /*!< reserved. <i>Offset: 0Ch</i>. */
    volatile uint32_t     chgi_vmid[TIME_CHGI_VMID_NUM];  /*!< RTC vmid permission check registers for channel group.
                                                               <i>Offset: 10h</i>. */
    volatile uint32_t     chgi_idx[TIME_CHGI_IDX_NUM];    /*!< RTC n channel group ID. <i>Offset: 30h</i>. */
    volatile uint32_t     abnor_intr_raw;                 /*!< RTC raw interrupt registers in vimd check.
                                                               <i>Offset: 60h</i>. */
    volatile uint32_t     abnor_imsk;                     /*!< RTC vmid check error mask interrupt registers.
                                                               <i>Offset: 64h</i>. */
    volatile uint32_t     abnor_intr_stat;                /*!< RTC vmid check error interrupt status registers.
                                                               <i>Offset: 68h</i>. */
    volatile uint32_t     abnor_reserved1;                /*!< reserved. <i>Offset: 6Ch</i>. */
    volatile uint32_t     abnor_reserved2;                /*!< reserved. <i>Offset: 70h</i>. */
    volatile uint32_t     intr_wth;                       /*!< RTC interrupt width registers. <i>Offset: 74h</i>. */
    volatile uint32_t     eoi_ren;                        /*!< All rtc interrupt clear registers.
                                                               <i>Offset: 78h</i>. */
    volatile uint32_t     raw_intr_stat;                  /*!< All rtc raw interrupt status registers.
                                                               <i>Offset: 7Ch</i>. */
    volatile uint32_t     intr_stat;                      /*!< All rtc interrupt status after mask.
                                                               <i>Offset: 80h</i>. */
    volatile uint32_t     lp_state;                       /*!< Low power status indicator registers.
                                                               <i>Offset: 84h</i>. */
    volatile uint32_t     status;                         /*!< Low power status registers. <i>Offset: 88h</i>. */
} rtcs_v150_regs_t;

/**
 * @brief  Registers associated with rtc.
 */
typedef struct rtc_v150_regs {
    volatile uint32_t     load_count0;               /*!< RTC n load count(low 32bit). <i>Offset: 1000h</i>. */
    volatile uint32_t     load_count1;               /*!< RTC m load count(high 32bit). <i>Offset: 1004h</i>. */
    volatile uint32_t     current_value0;            /*!< RTC n value(low 32bit). <i>Offset: 1008h</i>. */
    volatile uint32_t     current_value1;            /*!< RTC m value(high 32bit). <i>Offset: 100Ch</i>. */
    volatile uint32_t     control;                   /*!< RTC control registers. <i>Offset: 1010h</i>. */
    volatile uint32_t     eoi_ren;                   /*!< RTC interrupt clear registers. <i>Offset: 1014h</i>. */
    volatile uint32_t     raw_intr;                  /*!< RTC raw interrupt status registers. <i>Offset: 1018h</i>. */
    volatile uint32_t     intr;                      /*!< RTC interrupt status after mask. <i>Offset: 101Ch</i>. */
} rtc_v150_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif