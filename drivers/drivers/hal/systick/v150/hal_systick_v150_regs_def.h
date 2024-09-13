/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V150 systick register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-01, Create file. \n
 */
#ifndef HAL_SYSTICK_V150_REGS_DEF_H
#define HAL_SYSTICK_V150_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_systick_v150_regs_def Systick V150 Regs Definition
 * @ingroup  drivers_hal_systick
 * @{
 */

/**
 * @brief  This union represents the bit fields in the cfg register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union cfg_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t frz                    : 1;    /*!< If this bit is set to 1, set systick value freeze.
                                                     If this bit is set to 0, set systick value release. */
        uint32_t stz                    : 1;    /*!< If this bit is set to 1, set systick value clear. */
        uint32_t reserved2_3            : 2;    /*!< Reserved */
        uint32_t clr                    : 1;    /*!< If this bit is 1, systick value is cleared */
        uint32_t reserved5_15           : 11;   /*!< Reserved */
    } b;                                        /*!< Register bits. */
} cfg_data_t;

/**
 * @brief  This union represents the bit fields in the value register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union value_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        #ifdef CONFIG_SYSTICK_WITH_TWO_DATA_REGS
        uint32_t data                   : 32;   /*!< 32-bit value value. \n
                                                      value1(63~32 bits) \n
                                                      value0(31~0 bits) */
        #else
        uint32_t data                   : 16;   /*!< 16-bit value value. \n
                                                      value3(63~48 bits) \n
                                                      value2(47~32 bits) \n
                                                      value1(31~16 bits) \n
                                                      value0(15~0 bits) */
        #endif
    } b;                                        /*!< Register bits. */
} value_data_t;

/**
 * @brief  Registers associated with Systick.
 */
typedef struct systick_regs {
    volatile uint32_t cfg;                      /*!< cfg.     <i>Offset: 00h</i>. */
    volatile uint32_t value0;                   /*!< value0.  <i>Offset: 04h</i>. */
    volatile uint32_t value1;                   /*!< value1.  <i>Offset: 08h</i>. */
    volatile uint32_t value2;                   /*!< value2.  <i>Offset: 0Ch</i>. */
    volatile uint32_t value3;                   /*!< value3.  <i>Offset: 10h</i>. */
} systick_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif