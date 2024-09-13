/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides trng port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-06， Create file. \n
 */
#ifndef TRNG_PORTING_H
#define TRNG_PORTING_H

#include <stdint.h>
#include "hal_trng.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_port_trng Trng
 * @ingroup  drivers_port
 * @{
 */

#define TRNG_DATA_BLOCKS      0xfff // data blocks is no more than 4095, ref value is : 0xfff
#define TRNG_SAMPLE_CYCLES    0x1
#define TRNG_READ_TIMEOUT     0x0
#define TRNG_SAMPLE_DIV       0x0
#define TRNG_NOISE_BLOCKS     0x10

#define TRNG_DATA_HALF_LENGTH 0x100 // median of trng shared memory

#ifdef USE_CMSIS_OS
#define TRNG_DATA_HALF_START   (TRNG_DATA_REGION_START + TRNG_DATA_HALF_LENGTH)
#endif

/**
 * @brief  Unregister hal funcs objects from hal_trng module.
 */
void trng_port_register_hal_funcs(void);

/**
 * @brief  Unregister hal funcs objects from hal_trng module.
 */
void trng_port_unregister_hal_funcs(void);

/**
 * @brief  Get the hal funcs of trng.
 * @return the hal funcs of trng, see @ref hal_trng_funcs_t
 */
hal_trng_funcs_t *trng_port_get_funcs(void);

/**
 * @brief  Get the base addr of trng.
 * @return the base addr of trng
 */
uintptr_t trng_get_base_addr(void);

/**
 * @brief trng set clock en
 * @param [in] clken clock en ctrl
 */
void trng_port_set_clk_en(uint32_t clken);

/**
 * @brief trng set clock en
 * @param [in] soft_reset soft_reset ctrl
 */
void trng_port_set_soft_reset(uint32_t soft_reset);

/**
 * @brief trng sample clock en
 * @param [in] clk_en sample clock en
 */
void trng_port_set_clk_sample_en(uint32_t clk_en);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif