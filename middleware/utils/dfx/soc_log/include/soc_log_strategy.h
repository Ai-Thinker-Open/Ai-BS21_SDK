/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: dfx soc log strategy
 * This file should be changed only infrequently and with great care.
 */

#ifndef SOC_LOG_STRATEGY_H
#define SOC_LOG_STRATEGY_H

#include "dfx_write_interface.h"
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define SOC_LOG_DEFAULT_LEVEL SOC_TRACE_LEVEL_INFO
#define SOC_LOG_INVALID_LINE 0xFFFFFFFF
#define SOC_LOG_DEFAULT_MODULE_ID 0xFFFF

typedef struct {
    uint8_t type;
    uint8_t level;
    uint16_t module_id;
    const char *fn_name;
    uint32_t line_num;
} soc_log_param_t;

typedef enum {
    SOC_LOG_TYPE_INVALID,
    SOC_LOG_TYPE_PRINT,
    SOC_LOG_TYPE_SIMPLE_PRINT,
    SOC_LOG_TYPE_KEY_TRACE,
} soc_log_type_t;

errcode_t soc_log_register_write_impl(dfx_write_data_interface_t *impl);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif // !SOC_LOG_STRATEGY_H
