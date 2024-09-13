/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides pwm port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16， Create file. \n
 */

#ifndef PWM_PORTING_H
#define PWM_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "pwm.h"
#include "platform_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_pwm PWM
 * @ingroup  drivers_port
 * @{
 */

extern uintptr_t g_pwm_base_addr;

typedef enum {
    PWM_GROUP_0,                  /* < PWM Peripheral 0 */
    PWM_GROUP_1,                  /* < PWM Peripheral 1 */
    PWM_GROUP_2,                  /* < PWM Peripheral 2 */
    PWM_GROUP_3,                  /* < PWM Peripheral 3 */
    PWM_GROUP_4,                  /* < PWM Peripheral 4 */
    PWM_GROUP_5,                  /* < PWM Peripheral 5 */
    PWM_GROUP_6,                  /* < PWM Peripheral 6 */
    PWM_GROUP_7,                  /* < PWM Peripheral 7 */
    PWM_GROUP_8,                  /* < PWM Peripheral 8 */
    PWM_GROUP_9,                  /* < PWM Peripheral 9 */
    PWM_GROUP_10,                 /* < PWM Peripheral 10 */
    PWM_GROUP_11,                 /* < PWM Peripheral 11 */
    PWM_GROUP_NONE
} pwm_v151_group_t;

/**
 * @brief  Get the base address of a specified PWM.
 * @return The base address of specified PWM.
 */
uintptr_t pwm_porting_base_addr_get(void);

/**
 * @brief  Register hal funcs objects into hal_pwm module.
 */
void pwm_port_register_hal_funcs(void);

/**
 * @brief  Unregister hal funcs objects from hal_pwm module.
 */
void pwm_port_unregister_hal_funcs(void);

/**
 * @brief  Register the interrupt of pwm.
 * @param [in] channel PWM device
 */
void pwm_port_register_irq(pwm_channel_t channel);

/**
 * @brief  Unregister the interrupt of pwm.
 * @param [in] channel PWM device
 */
void pwm_port_unregister_irq(pwm_channel_t channel);

/**
 * @brief  Set the divider number of the peripheral device clock.
 * @param [in] on Enable or disable.
 */
void pwm_port_clock_enable(bool on);

/**
 * @brief  Get pwm clock value.
 * @param  [in]  channel PWM device.
 */
uint32_t pwm_port_get_clock_value(pwm_channel_t channel);

/**
 * @if Eng
 * @brief  PWM param check.
 * @param  [in]  cfg Config set to the PWM device. For details, see @ref pwm_config_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  PWM参数检查。
 * @param  [in]  cfg PWM设备的配置信息，参考 @ref pwm_config_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t pwm_port_param_check(const pwm_config_t *cfg);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif