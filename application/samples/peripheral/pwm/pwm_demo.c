/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: PWM Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-06-27, Create file. \n
 */
#include "pinctrl.h"
#include "pwm.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"
#include "tcxo.h"

#define PWM_CHANNEL                0
#define PWM_GROUP_ID               0
#define TEST_MAX_TIMES             5
#define DALAY_MS                   100
#define TEST_TCXO_DELAY_1000MS     1000
#define PWM_TASK_STACK_SIZE        0x1000
#define PWM_TASK_PRIO              (osPriority_t)(17)

static void *pwm_task(const char *arg)
{
    UNUSED(arg);
    pwm_config_t cfg_no_repeat = {
        200,
        50,
        0,
        0,
        true
    };

    uapi_pin_set_mode(CONFIG_PWM_PIN, HAL_PIO_PWM0);
    uapi_pwm_init();

    uapi_tcxo_delay_ms((uint32_t)TEST_TCXO_DELAY_1000MS);

    uint8_t channel = PWM_CHANNEL;
    uapi_pwm_set_group(PWM_GROUP_ID, &channel, 1);
    uapi_pwm_open(PWM_CHANNEL, &cfg_no_repeat);
    uapi_pwm_config_preload(PWM_GROUP_ID, channel, &cfg_no_repeat);
    uapi_pwm_start(PWM_GROUP_ID);


    uapi_tcxo_delay_ms((uint32_t)TEST_TCXO_DELAY_1000MS);

    uapi_pwm_close(PWM_CHANNEL);


    uapi_tcxo_delay_ms((uint32_t)TEST_TCXO_DELAY_1000MS);
    uapi_pwm_deinit();
    return NULL;
}

static void pwm_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "PWMTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = PWM_TASK_STACK_SIZE;
    attr.priority = PWM_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)pwm_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the pwm_entry. */
app_run(pwm_entry);