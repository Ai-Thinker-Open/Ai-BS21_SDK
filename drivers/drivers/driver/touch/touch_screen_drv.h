/*
 * Copyright (c) @CompanyNameMagicTag 2021-2022. All rights reserved.
 * Description: header of touch screen driver.
 * Author: @CompanyNameTag
 * Create: 2022-04-12
 */

#ifndef TOUCH_SCREEN_DRV_H
#define TOUCH_SCREEN_DRV_H

#include "soc_osal.h"
#include "touch_screen_queue1.h"

struct ts_driver_data {
    osal_task *task_handle;
    osal_event event;
    ts_queue_t *queue;
    osal_wait wait;
    struct ts_ops *ops;
    touch_peripheral_api *touch_api;
    void *private_data;
};

struct ts_ops {
    /* private operation */
    uint32_t (*priv_operator)(struct ts_driver_data *udd);
};

ext_errno touch_screen_module_init(void);
ext_errno touch_screen_module_deinit(void);

#endif