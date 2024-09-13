/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: UPG debug functions header file
 */

#ifndef UPG_DEBUG_H
#define UPG_DEBUG_H

#include "upg_config.h"
#include "upg_definitions.h"
#include "stdio.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#if (UPG_CFG_DEBUG_PRINT_ENABLED == YES)

#define upg_log_info(...)
#define upg_log_err(...)

#else

#define upg_log_info(...)
#define upg_log_err(...)

#endif /* UPG_CFG_DEBUG_PRINT_ENABLED */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* UPG_DEBUG_H */
