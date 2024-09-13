/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides Calendar driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-20， Create file. \n
 */
#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdint.h>
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_calendar Calendar
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Definition of Calendar data structure.
 * @else
 * @brief  日历数据结构定义。
 * @endif
 */
typedef struct calendar {
    uint32_t sec;           /*!< @if Eng Second, 0 ~ 59.
                                 @else   秒  0 ~ 59 @endif */
    uint32_t min;           /*!< @if Eng Minute, 0 ~ 59.
                                 @else   分钟  0 ~ 59 @endif */
    uint32_t hour;          /*!< @if Eng Hour, 0 ~ 23.
                                 @else   小时，0 ~ 23。 @endif */
    uint32_t day;           /*!< @if Eng Day, Max day of month.
                                 @else   日，月的最大天数。 @endif */
    uint32_t mon;           /*!< @if Eng Month, 1 ~ 12.
                                 @else   月，1 ~ 12。 @endif */
    uint32_t year;          /*!< @if Eng Year, 1970 ~ 2099.
                                 @else   年，1970 ~ 2099。 @endif */
} calendar_t;

/**
 * @if Eng
 * @brief  Initialize the Calendar module.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  初始化Calendar模块。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_calendar_init(void);

/**
 * @if Eng
 * @brief  Deinitialize the Calendar module.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去初始化Calendar模块。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_calendar_deinit(void);

/**
 * @if Eng
 * @brief  Set the Calendar basic time.
 * @param  date Calendar basic time.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  设置日历基础时间。
 * @param  date 日历基础时间。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_calendar_set_datetime(const calendar_t *date);

/**
 * @if Eng
 * @brief  Get the Calendar current time.
 * @param  date Calendar current time.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  获取日历当前时间。
 * @param  date 日历当前时间。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_calendar_get_datetime(calendar_t *date);

/**
 * @if Eng
 * @brief  Set the Calendar timestamp.
 * @param  timestamp timestamp value.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  设置日历时间戳。
 * @param  timestamp 日历时间戳值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_calendar_set_timestamp(const uint64_t timestamp);

/**
 * @if Eng
 * @brief  Get the Calendar current timestamp.
 * @param  timestamp Calendar timestamp value.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  获取当前时间戳。
 * @param  timestamp 当前时间戳值。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_calendar_get_timestamp(uint64_t *timestamp);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif