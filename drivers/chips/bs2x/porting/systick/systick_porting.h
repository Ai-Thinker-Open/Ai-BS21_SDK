/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides systick port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-30， Create file. \n
 */
#ifndef SYSTICK_PORTING_H
#define SYSTICK_PORTING_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_systick Systick
 * @ingroup  drivers_port
 * @{
 */

#define SYSTICK_SPEED_SHIFT 15
/* 32768 */
#define SYSTICK_SPEED (1 << SYSTICK_SPEED_SHIFT)

#define ms_to_systick(ms) ((((uint64_t)(ms) << SYSTICK_SPEED_SHIFT) / 1000) + 1)

#define HAL_SYSTICK_SPEED 32768
#define MS_PER_S                    1000
#define US_PER_MS                   1000
#define convert_s_2_count(s)        ((s) * HAL_SYSTICK_SPEED)
#define convert_count_2_s(count)    ((count) / HAL_SYSTICK_SPEED)
#define convert_ms_2_count(ms)      ((ms) * HAL_SYSTICK_SPEED / MS_PER_S)
#define convert_count_2_ms(count)   ((count) * MS_PER_S / HAL_SYSTICK_SPEED)
#define convert_us_2_count(us)      ((us) * HAL_SYSTICK_SPEED / (MS_PER_S * US_PER_MS))
#define convert_count_2_us(count)   ((count) * (MS_PER_S * US_PER_MS) / HAL_SYSTICK_SPEED)

/**
 * @if Eng
 * @brief  Get the base address of a specified systick.
 * @return The base address of specified systick.
 * @else
 * @brief  获取指定SYSTICK的基地址。
 * @return 指定SYSTICK的基地址。
 * @endif
 */
uintptr_t systick_porting_base_addr_get(void);

/**
 * @if Eng
 * @brief  Cali XCLK.
 * @else
 * @brief  修正XCLK时钟
 * @endif
 */
void systick_port_cali_xclk(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
