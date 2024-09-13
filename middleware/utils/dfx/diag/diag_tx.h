/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: diag tx
 * This file should be changed only infrequently and with great care.
 */

#ifndef ZDIAG_TX_H
#define ZDIAG_TX_H

#include "diag_common.h"
#include "diag_pkt_router.h"

errcode_t diag_pkt_router_output(diag_pkt_handle_t *pkt, const diag_pkt_process_param_t *process_param);
#endif
