/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: diag cmd process
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_CMD_DST_H
#define DIAG_CMD_DST_H

#include "errcode.h"
#include "diag.h"
#include "diag_common.h"
#include "diag_service.h"
errcode_t diag_pkt_router_run_cmd(diag_ser_data_t *data, diag_option_t *option);
#endif
