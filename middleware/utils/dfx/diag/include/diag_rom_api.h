/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: diag romable
 * This file should be changed only infrequently and with great care.
 */
#ifndef DIAG_ROM_API_H
#define DIAG_ROM_API_H

#include "diag.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef errcode_t (*diag_report_sys_msg_handler)(uint32_t module_id, uint32_t msg_id, const uint8_t *buf,
    uint16_t buf_size, uint8_t level);

typedef struct {
    diag_report_sys_msg_handler report_sys_msg;
} diag_rom_api_t;

void diag_rom_api_register(const diag_rom_api_t *api);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* DIAG_ROM_API_H */