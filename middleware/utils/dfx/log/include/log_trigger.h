/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description: LOG TRIGGER MODULE INTERRFACE
 * Author: @CompanyNameTag
 * Create:
 */

#ifndef SRC_LIB_LOG_PRIVATE_LOG_TRIGGER_H
#define SRC_LIB_LOG_PRIVATE_LOG_TRIGGER_H

/**
 * @addtogroup connectivity_libs_log
 * @{
 */
#include "core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define CORE_LOGGING APPS
typedef void (*log_trigger_callback_t)(void);

/**
 * @brief  Ensure the log reader will be triggered.
 * This function should be called when the logger has detected it has written to an empty buffer.
 */
void log_trigger(void);

/**
 * @brief  Ensure the log trigger should be registered.
 * This function should be called when the log module init.
 * @param  callback: should match the type<log_trigger_callback_t>.
 */
void register_log_trigger(log_trigger_callback_t callback);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
