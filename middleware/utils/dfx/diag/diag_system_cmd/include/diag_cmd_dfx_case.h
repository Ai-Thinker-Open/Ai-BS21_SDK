/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: diag dfx cmd
 */

#ifndef DIAG_CMD_DFX_CASE_H
#define DIAG_CMD_DFX_CASE_H

#include "errcode.h"
#include "diag.h"

errcode_t diag_dfx_cmd(uint16_t cmd_id, void *cmd_param, uint16_t cmd_param_size, diag_option_t *option);

#endif /* DIAG_CMD_DFX_CASE_H */
