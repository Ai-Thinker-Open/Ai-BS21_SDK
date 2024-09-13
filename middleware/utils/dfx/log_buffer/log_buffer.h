/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  LOG BUFFER INTERFACE
 * Author: @CompanyNameTag
 * Create:  2018-10-15
 */

#ifndef NON_OS_LOG_BUFFER_H
#define NON_OS_LOG_BUFFER_H

#include <stdint.h>
#include "log_buffer_common.h"
#include "log_memory_section.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup connectivity_drivers_non_os_log LOG
 * @ingroup  connectivity_drivers_non_os
 * @{
 */

typedef enum {
    LOG_RET_OK,
    LOG_RET_ERROR_IN_PARAMETERS,
    LOG_RET_ERROR_NOT_ENOUGH_SPACE,
    LOG_RET_ERROR_CORRUPT_SHARED_MEMORY,
    LOG_RET_ERROR_OVERFLOW
} log_ret_t;

#ifdef FEATURE_PLT_LB_CHECK
typedef enum {
    LOG_BUF_RET_OK = 0,
    LOG_BUF_RLW_MAGIC_ERROR = 1,
    LOG_RET_RGW_TOEND_MAGIC_ERROR = 2,
    LOG_RET_RGW_LASTONE_MAGIC_ERROR = 3,
    LOG_RET_MEMCPY_ERROR = 4,
} log_buffer_check_error_t;
#endif

/**
 * @brief  Initialize the log buffer module to log in the given log memory region section.
 * @return LOG_RET_OK or an error value
 */
void log_buffer_init(log_memory_region_section_t logsec);

/**
 * @brief  Add data to the circular buffer with updating the write index.
 * @param  lb_header Header of the log buffer.
 * @param  buffer Pointer to the buffer.
 * @param  was_empty Was empty or not.
 */
void log_buffer_write(const log_buffer_header_t *lb_header, const uint8_t *buffer, bool *was_empty);

/**
 * @brief  Get the available space for the next message
 * @param  av available space will be stored here
 * @return LOG_RET_OK or an error code
 */
log_ret_t log_buffer_get_available_for_next_message(uint32_t *av);

#ifdef FEATURE_PLT_LB_CHECK
uint8_t log_buffer_check(void);
#endif

#if (USE_COMPRESS_LOG_INSTEAD_OF_SDT_LOG == YES)
log_ret_t compress_log_write(const uint8_t *data, uint32_t length);
#endif

/* 暂时兼容旧接口 */
void massdata_record_system_error(uint8_t event_id, uint8_t info1, uint8_t info2, uint32_t info3);
void massdata_record_system_event(uint8_t event_id, uint8_t info1, uint8_t info2, uint32_t info3);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @}
 */
#endif
