/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: ulp_gpio file \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-10-20, Create file. \n
 */

#ifndef ULP_GPIO_H
#define ULP_GPIO_H

#include "hal_gpio.h"
#include "pinctrl.h"
#include "pinctrl_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_ulp_gpio info.
 * @ingroup  drivers_ulp_gpio
 * @{
 */

typedef void (*ulp_gpio_irq_cb_t)(uint8_t ulp_gpio);

typedef enum {
    ULP_GPIO_INTERRUPT_LOW,
    ULP_GPIO_INTERRUPT_HIGH,
    ULP_GPIO_INTERRUPT_FALLING_EDGE,
    ULP_GPIO_INTERRUPT_RISING_EDGE,
    ULP_GPIO_INTERRUPT_DEDGE
} ulp_gpio_interrupt_t;

typedef enum {
    ULP_GPIO_WK0_MASK,
    ULP_GPIO_WK1_MASK
} ulp_gpio_wk_t;

typedef struct pin_pad_slp_hold_cfg {
    pin_t pin;
    bool output_enable;
    bool output_high;
} pin_pad_slp_hold_cfg_t;

typedef struct ulp_gpio_int_wkup_cfg {
    /* ulp_gpio共有8个(0-7) */
    uint8_t ulp_gpio;
    /**
    * 0-31：IO管脚，参考 pin_t 。
    * 32：swd_clk管脚
    * 33：swd_io管脚
    * 34：gpio或mask0，低电平：0，高电平：1，可以将多个低电平管脚绑定成或mask0，中断触发选上升沿或高电平，一个脚被拉高即触发中断。
    * 35：gpio与mask0，低电平：0，高电平：1，可以将多个高电平管脚绑定成与mask0，中断触发选下降沿或低电平，一个脚被拉低即触发中断。
    * 36：gpio或mask1，低电平：0，高电平：1，可以将多个低电平管脚绑定成或mask1，中断触发选上升沿或高电平，一个脚被拉高即触发中断。
    * 37：gpio与mask1，低电平：0，高电平：1，可以将多个高电平管脚绑定成与mask1，中断触发选下降沿或低电平，一个脚被拉低即触发中断。
    * 补充：mask管脚绑定可以使用接口 ulp_gpio_mask_pin_set。
    */
    uint8_t wk_mux;
    bool int_enable;
    ulp_gpio_interrupt_t trigger;
    ulp_gpio_irq_cb_t irq_cb;
} ulp_gpio_int_wkup_cfg_t;

void ulp_gpio_init(void);

void ulp_gpio_deinit(void);

void ulp_gpio_set_dir(uint8_t ulp_gpio, gpio_direction_t dir);

void ulp_gpio_set_val(uint8_t ulp_gpio, gpio_level_t level);

void ulp_gpio_enable_interrupt(uint8_t ulp_gpio);

void ulp_gpio_disable_interrupt(uint8_t ulp_gpio);

void ulp_gpio_clear_interrupt(uint8_t ulp_gpio);

void ulp_gpio_register_irq_func(uint8_t ulp_gpio, ulp_gpio_interrupt_t trigger, ulp_gpio_irq_cb_t cb);

void ulp_gpio_unregister_irq_func(uint8_t ulp_gpio);

void ulp_gpio_wk_src_sel(uint8_t ulp_gpio, uint8_t wk_mux);

/* 参数pin_map每个bit对应一个IO（bit0即s_mgpio0），对应bit为1即表示选定对应IO。 */
void ulp_gpio_mask_pin_set(ulp_gpio_wk_t wk_sel, uint32_t pin_map);

void pin_pad_out_config_during_sleep(pin_t pin, bool oe, bool out_high);

void ulp_gpio_int_wkup_config(ulp_gpio_int_wkup_cfg_t *cfg, uint8_t array_num);

void pm_aon_gpio_suspend(void);

void pm_aon_gpio_resume(void);

void pm_clr_ulp_gpio(void);

void ulp_gpio_register_interrupt(void);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif