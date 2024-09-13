/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: RTC Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-07-18, Create file. \n
 */
#include "common_def.h"
#include "rtc.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"
#include "tcxo.h"

#define RTC_TASK_STACK_SIZE                   0x1000
#define RTC_TASK_PRIO (osPriority_t)(17)
#define RTC_TIMERS_NUM            4
#define RTC_INDEX                 2
#define RTC_IRQN                  51
#define RTC_PRIO                  1
#define RTC_DELAY_INT             5
#define RTC1_DELAY_1000MS         1000
#define RTC2_DELAY_2000MS         2000
#define RTC3_DELAY_3000MS         3000
#define RTC4_DELAY_4000MS         4000

typedef struct rtc_info {
    uint32_t start_time;
    uint32_t end_time;
    uint32_t delay_time;
} rtc_info_t;

static uint32_t g_rtc_int_count = 0;
static rtc_info_t g_rtcs_info[RTC_TIMERS_NUM] = {
    {0, 0, RTC1_DELAY_1000MS},
    {0, 0, RTC2_DELAY_2000MS},
    {0, 0, RTC3_DELAY_3000MS},
    {0, 0, RTC4_DELAY_4000MS}
};

/* Timed task callback function list. */
static void rtc_timeout_callback(uintptr_t data)
{
    uint32_t rtc_index = (uint32_t)data;
    g_rtcs_info[rtc_index].end_time = uapi_tcxo_get_ms();
    g_rtc_int_count++;
}

static void *rtc_task(const char *arg)
{
    unused(arg);
    rtc_handle_t rtc_index[RTC_TIMERS_NUM] = { 0 };
    uapi_rtc_init();
    uapi_rtc_adapter(RTC_INDEX, RTC_IRQN, RTC_PRIO);

    for (uint32_t i = 0; i < RTC_TIMERS_NUM; i++) {
        uapi_rtc_create(RTC_INDEX, &rtc_index[i]);
        g_rtcs_info[i].start_time = uapi_tcxo_get_ms();
        uapi_rtc_start(rtc_index[i], g_rtcs_info[i].delay_time, rtc_timeout_callback, i);
        osDelay(RTC_DELAY_INT);
    }

    while (g_rtc_int_count < RTC_TIMERS_NUM) {
        osDelay(RTC_DELAY_INT);
    }

    for (uint32_t i = 0; i < RTC_TIMERS_NUM; i++) {
        uapi_rtc_stop(rtc_index[i]);
        uapi_rtc_delete(rtc_index[i]);
        osal_printk("real time[%d] = %dms  ", i, (g_rtcs_info[i].end_time -  g_rtcs_info[i].start_time));
        osal_printk("  delay = %dms\r\n", g_rtcs_info[i].delay_time);
    }
    return NULL;
}

static void rtc_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "RTCTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = RTC_TASK_STACK_SIZE;
    attr.priority = RTC_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)rtc_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the rtc_entry. */
app_run(rtc_entry);