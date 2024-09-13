/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: ADC Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-07-06, Create file. \n
 */
#include "pinctrl.h"
#include "gpio.h"
#include "adc.h"
#include "adc_porting.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"
#include "pm_pmu.h"

#define ADC_TASK_STACK_SIZE               0x1000
#define ADC_TASK_PRIO                     (osPriority_t)(17)
#define ADC_AUTO_SAMPLE_TEST_TIMES        1000

#define GAFE_SAMPLE_VALUE_SIGN_BIT        17
#define ADC_REFERENCE_VOLTAGE_MV          1500
#define ADC_REF_VOL_DIFFERENCE_MULT       2
#define ADC_TICK2VOL_REF_VOLTAGE_MV       (ADC_REFERENCE_VOLTAGE_MV * ADC_REF_VOL_DIFFERENCE_MULT)


static void adc_set_io(uint8_t channel)
{
    pin_t adc_pin[] = {S_MGPIO2, S_MGPIO3, S_MGPIO4, S_MGPIO5, S_MGPIO28, S_MGPIO29, S_MGPIO30, S_MGPIO31};

    uapi_pin_set_mode(adc_pin[channel], PIN_MODE_0);
    uapi_gpio_set_dir(adc_pin[channel], GPIO_DIRECTION_INPUT);
    uapi_pin_set_pull(adc_pin[channel], PIN_PULL_NONE);
#if defined(CONFIG_PINCTRL_SUPPORT_IE)
    uapi_pin_set_ie(adc_pin[channel], PIN_IE_1);
#endif
}


static void *adc_task(const char *arg)
{
    UNUSED(arg);

    uapi_pmu_control(PMU_CONTROL_MICLDO_POWER, PMU_CONTROL_POWER_ON);
    uapi_pmu_ldo_set_voltage(PMU_LDO_ID_MICLDO, PMU_MICLDO_VSET_1V5);  //在MLDO脚产生一个1.5V的电压便以测试

    osal_printk("start adc sample test");
    uapi_adc_init(ADC_CLOCK_NONE);
    adc_set_io(GADC_CHANNEL_0);
    uapi_adc_open_channel(GADC_CHANNEL_0);  //GPIO02
    uapi_adc_power_en(AFE_GADC_MODE, true);
    adc_calibration(AFE_GADC_MODE, true, true, true);

    while (1)
    {
        int gadc_value = 0;
        gadc_value =  uapi_adc_auto_sample(GADC_CHANNEL_0);
        osal_printk("gadc: %dmv\n", (gadc_value * ADC_TICK2VOL_REF_VOLTAGE_MV) >> GAFE_SAMPLE_VALUE_SIGN_BIT);
        osDelay(1000);
    }
    return NULL;
}

static void adc_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "ADCTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = ADC_TASK_STACK_SIZE;
    attr.priority = ADC_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)adc_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the adc_entry. */
app_run(adc_entry);