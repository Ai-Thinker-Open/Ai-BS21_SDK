/*================================================================
* Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
*
* Description: the common interface using by secure storage.
* Author: @CompanyNameTag
* History:
* 2023-10-11， Create file.
================================================================*/

#pragma once
#ifndef STORAGE_COMMON_H
#define STORAGE_COMMON_H

#define STORAGE_PRINT             printf
#define storage_log_err(fmt, ...) storage_log_fmt("ERROR", fmt, ##__VA_ARGS__)
#define storage_log_fmt(LOG_LEVEL_LABEL, fmt, ...)                        \
    STORAGE_PRINT("[%s:%d]" LOG_LEVEL_LABEL ": " fmt, __func__, __LINE__, \
                  ##__VA_ARGS__)

/* Error Check. */
#define storage_chk_return(cond, err_ret, ...)             \
    do {                                                   \
        if (cond) {                                        \
            storage_log_err("%s:%d:", __func__, __LINE__); \
            storage_log_err(__VA_ARGS__);                  \
            return err_ret;                                \
        }                                                  \
    } while (0)

#define storage_chk_goto(cond, label, ...)                 \
    do {                                                   \
        if (cond) {                                        \
            storage_log_err("%s:%d:", __func__, __LINE__); \
            storage_log_err(__VA_ARGS__);                  \
            goto label;                                    \
        }                                                  \
    } while (0)

#endif  // _STORAGE_H_
