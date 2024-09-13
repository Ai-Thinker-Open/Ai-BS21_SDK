/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: transmit data
 * This file should be changed only infrequently and with great care.
 */
#ifndef TRANSMIT_API_H
#define TRANSMIT_API_H

#include "diag_config.h"
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef void (*save_file_result_hook)(int32_t len, uintptr_t usr_data);
errcode_t soc_dfx_save_file_async(const char *file_name, uint8_t *buf, uint32_t size, save_file_result_hook handler,
    uintptr_t usr_data);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* TRANSMIT_API_H */