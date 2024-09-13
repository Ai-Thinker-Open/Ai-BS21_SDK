/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides bs21 ulp_rtc API \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-08-31, Create file. \n
 */
#ifndef ULP_RTC_H
#define ULP_RTC_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup flash_recover_api Flash Recover
 * @ingroup flash_recover
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize the ulp_rtc.
 * @else
 * @brief  初始化ulp_rtc。
 * @endif
 */
void ulp_rtc_init(void);

/**
 * @if Eng
 * @brief  Deinitialize ulp_rtc.
 * @else
 * @brief  去初始化ulp_rtc。
 * @endif
 */
void ulp_rtc_deinit(void);

/**
 * @if Eng
 * @brief  Start ulp_rtc.
 * @param  [in]  time_ms Ulp_rtc expiration time.
 * @else
 * @brief  启动ulp_rtc定时器。
 * @param  [in]  time_ms 定时器超时时间。
 * @endif
 */
void ulp_rtc_start(uint32_t time_ms);

/**
 * @if Eng
 * @brief  Get current count of ulp_rtc.
 * @retval uint64_t  Current count.
 * @else
 * @brief  获取ulp_rtc当前的计数。
 * @retval uint64_t  当前的计数.
 * @endif
 */
uint64_t ulp_rtc_get_count(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif