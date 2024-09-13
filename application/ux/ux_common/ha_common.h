/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * File          ha_common.h
 * Description:  Audio plagtform bsp API common head file definition
 */
#ifndef HA_COMMON_H
#define HA_COMMON_H

#include <autoconf.h>
#include "soc_diag_util.h"

#define SUCCESS         0
#define FAIL            (-1)

#define OS_NO_WAIT              0x0U

#define ha_base_print_err(logCode, fmt, args...) \
    do {uapi_diag_error_log(0, fmt, ##args); \
    } while (0)

#define ha_base_print_warn(logCode, fmt, args...) \
    do {uapi_diag_warning_log(0, fmt, ##args); \
    } while (0)

#define ha_base_print_info(logCode, fmt, args...) \
    do {uapi_diag_info_log(0, fmt, ##args); \
    } while (0)

#define ha_base_print_debug(logCode, fmt, args...) \
    do {uapi_diag_debug_log(0, fmt, ##args); \
    } while (0)

#endif