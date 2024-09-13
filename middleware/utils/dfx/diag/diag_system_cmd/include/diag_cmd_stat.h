/*
 * Copyright (c) CompanyNameMagicTag 2022-2023. All rights reserved.
 * Description: diag stat query cmd.
 */

#ifndef DIAG_CMD_STAT_H
#define DIAG_CMD_STAT_H

#include "errcode.h"
#include "diag.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define DFX_STAT_ID_BASE_SYS    0x0557 /* SYS STAT packet ID range: [0xA000, 0xF000) */
#define DFX_STAT_ID_MAX_SYS     0x055E

typedef struct {
    uint32_t id;
} diag_dbg_stat_query_t;

errcode_t diag_cmd_stat_query(uint16_t cmd_id, void *cmd_param, uint16_t cmd_param_size, diag_option_t *option);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
