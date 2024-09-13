/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: diag debug
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_DEBUG_H
#define DIAG_DEBUG_H

#include "errcode.h"
#include "diag_common.h"
#include "diag_pkt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

void zdiag_debug_print_pkt_info(const char *str, uint8_t *pkt);
void zdiag_pkt_printf(const char *str, diag_pkt_handle_t *pkt);

uint32_t diag_get_debug_level(void);
void diag_set_debug_level(uint32_t level);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
