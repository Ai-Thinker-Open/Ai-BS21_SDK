/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: touch screen common definition.
 * Author: @CompanyNameTag
 * Create: 2022-04-12
 */

#ifndef TOUCH_SCREEN_DEF_H
#define TOUCH_SCREEN_DEF_H

#include "stdio.h"
#include "soc_errno.h"
#include "osal_ioctl.h"
#include "input_manager.h"
#include "debug_print.h"
#if defined(SUPPORT_POWER_MANAGER)
#include "power_display_service.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define INPUT_TOUCH_MODULE_ID  0x61
#define CMD_GET_TOUCH_INFO     0
#define TOUCH_SCREEN_GET_EVENT _IOWR(INPUT_TOUCH_MODULE_ID, CMD_GET_TOUCH_INFO, input_event_info)

/* common definitions */
#define tp_mem_free(sz)                   \
    do {                                  \
        if ((sz) != NULL) {            \
            osal_kfree((sz));                \
        }                                 \
        (sz) = NULL;                   \
    } while (0)

#ifdef TP_DEBUG
#define tp_print(fmt, ...)                    \
    do {                                      \
        PRINT(fmt"\r\n", ##__VA_ARGS__);     \
    } while (0)
#else
#define tp_print(ftm, ...)
#endif

#define tp_err(x, ...) \
    do { \
        PRINT("[ERROR]%s(%d): "x"\r\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define tp_warning(x, ...) \
    do { \
        PRINT("[WARNING]%s(%d): "x"\r\n", __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while (0)

#define TP_FIGURE_NUM_SUPPORT  1

typedef enum {
    MC_TP_PRESS = 0,
    MC_TP_RELEASE = 1,
    MC_TP_MOVE = 2,
    MC_TP_COVER = 3,
    MC_TP_SHORT_CLICK = 4,
    MC_TP_DOUBLE_CLICK = 5,
    MC_TP_SLIDE_UP = 6,
    MC_TP_SLIDE_DOWN = 7,
    MC_TP_INVALID,
} tp_event_type;

typedef struct {
    uint32_t x_axis[TP_FIGURE_NUM_SUPPORT];
    uint32_t y_axis[TP_FIGURE_NUM_SUPPORT];
    uint32_t z_axis[TP_FIGURE_NUM_SUPPORT];
} tp_dev_info;

typedef struct {
    tp_dev_info tp_event_info;
    tp_event_type tp_event;
    uint32_t finger_id;
    uint32_t point_num;
    uint32_t tv_usec;
} input_event_info;

typedef void (*touch_callback)(void);

typedef struct {
    ext_errno (*touch_init)(void *attr);
    ext_errno (*touch_deinit)(void);
    ext_errno (*touch_get_tpinfo)(uint8_t *data, uint8_t data_len);
    ext_errno (*touch_suspend)(void);
    ext_errno (*touch_resume)(void);
    ext_errno (*touch_sleep)(void);
    ext_errno (*touch_reset)(void);
    ext_errno (*touch_bus_init)(void *private_data);
    ext_errno (*register_callback)(void *peri_data, touch_callback func);
    ext_errno (*unregister_callback)(void *peri_data);
} touch_peripheral_api;

uint32_t ts_register_report_event_cb(report_event_cb callback);
uint32_t ts_unregister_report_event_cb(void);
uint32_t ts_init(void);
uint32_t ts_close(void);
uint32_t ts_read(const input_dev_data_t* data);
#if defined(SUPPORT_POWER_MANAGER)
uint32_t ts_register_power_manager_cb(event_callback_func callback);
#endif

#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif
