/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: ls cmd header file
 * This file should be changed only infrequently and with great care.
 */
#ifndef __TRANSMIT_CMD_LS_H__
#define __TRANSMIT_CMD_LS_H__

#include "diag.h"
#include "dfx_feature_config.h"

#if (CONFIG_DFX_SUPPORT_FILE_SYSTEM == DFX_YES)
errcode_t transmit_cmd_ls(uint8_t cmd_id, void *cmd_param, uint16_t cmd_param_size, diag_option_t *option,
                          bool from_upper_machine);
#endif

#endif
