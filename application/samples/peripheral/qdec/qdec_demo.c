/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: QDEC Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-09-20, Create file. \n
 */
#include "common_def.h"
#include "qdec.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"

#define QDEC_TASK_STACK_SIZE         0x1000
#define QDEC_TASK_PRIO               (osPriority_t)(17)

static qdec_config_t g_app_qdec_config = QDEC_DEFAULT_CONFIG;
static int32_t g_app_qdec_count = 0;

static int32_t app_qdec_report_callback(int argc, char *argv[])
{
    unused(argv);
    g_app_qdec_count += argc;
    osal_printk("current count is: %d.\r\n", g_app_qdec_count);
    return ERRCODE_SUCC;
}

static void *qdec_task(const char *arg)
{
    unused(arg);
    qdec_port_pinmux_init(13, 14);

    /* QDEC Init Config. */
    uapi_qdec_init(&g_app_qdec_config);

    if (uapi_qdec_register_callback(app_qdec_report_callback) == ERRCODE_SUCC) {
        osal_printk("qdec register callback succ!\r\n");
    }

    if (uapi_qdec_enable() == ERRCODE_SUCC) {
        osal_printk("qdec enable succ!\r\n");
    }

    return NULL;
}

static void qdec_entry(void)
{
    osThreadAttr_t attr;

    attr.name = "QdecTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = QDEC_TASK_STACK_SIZE;
    attr.priority = QDEC_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)qdec_task, NULL, &attr) == NULL) {
        /* Create task fail. */
    }
}

/* Run the qdec_entry. */
app_run(qdec_entry);