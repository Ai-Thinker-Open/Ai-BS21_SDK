/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-12， Create file. \n
 */
#ifndef PM_PORTING_H
#define PM_PORTING_H

#include "tcxo.h"
#include "gpio.h"
#include "pinctrl.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_chips_pm_port PM port
 * @ingroup  middleware_chips_pm
 * @{
 */

#define PM_GET_CURRENT_MS   uapi_tcxo_get_ms()

typedef struct gpio_info_cfg {
    pin_t pin;
    gpio_direction_t dir;
    pin_pull_t pull_type;
    gpio_level_t level;
} gpio_info_cfg_t;

void pm_record_time_before_sleep(void);

void pm_record_time_after_sleep(void);

uint64_t pm_get_time_before_sleep(void);

uint32_t pm_get_total_work_time(void);

uint64_t pm_get_time_after_sleep(void);

uint32_t pm_get_total_idle_time(void);

void pm_auto_cg_config(bool on);

void pm_set_protocol_wakeup_advance_time(uint16_t advance_time);

uint16_t pm_get_protocol_wakeup_advance_time(void);

void pm_set_protocol_work_advance_time(uint16_t advance_time);

uint16_t pm_get_protocol_work_advance_time(void);

typedef void (*pm_usb_cbk_t)(void);

void pm_usb_suspend_cbk(void);

void pm_usb_resume_cbk(void);

void pm_usb_register_suspend_cbk(pm_usb_cbk_t suspend);

void pm_usb_register_resume_cbk(pm_usb_cbk_t resume);

int pm_usb_wkup_host(void);

void pm_gpio_state_print(void);

void pm_gpio_group_config(gpio_info_cfg_t *cfg, uint8_t array_num);

bool pm_is_xo_32k_enabled(void);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif