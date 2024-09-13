/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: get cpup function
 */
#ifndef DIAG_CMD_GET_CPUP_H
#define DIAG_CMD_GET_CPUP_H

#include "errcode.h"
#include "diag.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define CPUP_DIAG_REPORT_CNT    30
#define CPUP_MAX_IRQ_CNT        90

errcode_t diag_cmd_get_cpup(uint16_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size, diag_option_t *option);
errcode_t diag_cmd_set_cpup_enable(uint16_t cmd_id, uint8_t *cmd_param, uint16_t cmd_param_size,
    diag_option_t *option);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif // !DIAG_CMD_GET_CPUP_H