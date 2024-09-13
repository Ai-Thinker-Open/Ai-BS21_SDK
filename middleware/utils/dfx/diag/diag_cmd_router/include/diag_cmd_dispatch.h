/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: diag cmd dispatch
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_CMD_DISPATCH_H
#define DIAG_CMD_DISPATCH_H

#include "errcode.h"
#include "diag.h"
#include "diag_common.h"
#include "diag_service.h"

errcode_t uapi_zdiag_cmd_process(diag_ser_data_t *data);
#endif
