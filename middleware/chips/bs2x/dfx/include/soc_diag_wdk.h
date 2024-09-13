/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: define file id and module id
 */

#ifndef SOC_DIAG_WDK_H
#define SOC_DIAG_WDK_H

#include "soc_module.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @ingroup  hct_diag
 * enumeration for file id
 */
typedef enum {
    /* DIAG */
    DIAG_FILE_ID_DIAG_MSG_C                     = 10000,
    DIAG_FILE_ID_DIAG_CMD_C                     = 10001,

    /* TEST */
    DIAG_FILE_ID_TEST_DIAG_C                    = 16300,
    DIAG_FILE_ID_TEST_DIAG_D                    = 16301,
    /* THE MAX VALUE OF FILE_ID */
    DIAG_FILE_ID_MAX                            = 16383,
} diag_file_id_t;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* end of soc_diag_wdk.h */
