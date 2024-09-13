/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ux_manager_common_log.h
 * Description:  Audio ux manager common log define
 */

#ifndef __UX_MANAGER_COMMON_LOG_H__
#define __UX_MANAGER_COMMON_LOG_H__

#include "ha_common.h"

#define ux_manager_print_err(log_num, fmt, args...)  ha_base_print_err(0, fmt, ##args)
#define ux_manager_print_warn(log_num, fmt, args...) ha_base_print_warn(0, fmt, ##args)
#define ux_manager_print_info(log_num, fmt, args...) ha_base_print_info(0, fmt, ##args)
#define ux_manager_print_debug(log_num, fmt, args...) ha_base_print_debug(0, fmt, ##args)

typedef enum {
    UX_MANAGER_LOG_NUM_0,
    UX_MANAGER_LOG_NUM_1,
    UX_MANAGER_LOG_NUM_2,
    UX_MANAGER_LOG_NUM_3,
    UX_MANAGER_LOG_NUM_4,
    UX_MANAGER_LOG_NUM_5,
    UX_MANAGER_LOG_NUM_6,
    UX_MANAGER_LOG_NUM_7,
    UX_MANAGER_LOG_NUM_8,
    UX_MANAGER_LOG_NUM_9,
    UX_MANAGER_LOG_NUM_10,
    UX_MANAGER_LOG_NUM_11,
    UX_MANAGER_LOG_NUM_12,
    UX_MANAGER_LOG_NUM_13,
    UX_MANAGER_LOG_NUM_14,
    UX_MANAGER_LOG_NUM_15,
    UX_MANAGER_LOG_NUM_16,
    UX_MANAGER_LOG_NUM_17,
    UX_MANAGER_LOG_NUM_18,
    UX_MANAGER_LOG_NUM_19,
    UX_MANAGER_LOG_NUM_20,
    UX_MANAGER_LOG_NUM_21,
    UX_MANAGER_LOG_NUM_22,
    UX_MANAGER_LOG_NUM_23,
    UX_MANAGER_LOG_NUM_24,
    UX_MANAGER_LOG_NUM_25,
    UX_MANAGER_LOG_NUM_26,
    UX_MANAGER_LOG_NUM_27,
    UX_MANAGER_LOG_NUM_28,
    UX_MANAGER_LOG_NUM_29,
    UX_MANAGER_LOG_NUM_30,
    UX_MANAGER_LOG_NUM_31,
    UX_MANAGER_LOG_NUM_32,
    UX_MANAGER_LOG_NUM_33,
    UX_MANAGER_LOG_NUM_34,
    UX_MANAGER_LOG_NUM_35,
    UX_MANAGER_LOG_NUM_36,
    UX_MANAGER_LOG_NUM_37,
    UX_MANAGER_LOG_NUM_38,
    UX_MANAGER_LOG_NUM_39,
    UX_MANAGER_LOG_NUM_40,
    UX_MANAGER_LOG_NUM_41,
    UX_MANAGER_LOG_NUM_42,
    UX_MANAGER_LOG_NUM_43,
    UX_MANAGER_LOG_NUM_44,
    UX_MANAGER_LOG_NUM_45,
    UX_MANAGER_MAX_LOG_NUM,
} ux_manager_log_num_enum;


#endif

