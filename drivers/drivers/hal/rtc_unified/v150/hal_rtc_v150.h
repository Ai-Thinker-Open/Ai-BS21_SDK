/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V150 HAL rtc \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-12-08, Create file. \n
 */
#ifndef HAL_RTC_V150_H
#define HAL_RTC_V150_H

#include <stdint.h>
#include <stdbool.h>
#include "hal_rtc.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_rtc_v150 RTC V150
 * @ingroup  drivers_hal_rtc
 * @{
 */

/**
 * @if Eng
 * @brief  Definition of the rtc mode.
 * @else
 * @brief  Timer模式定义。
 * @endif
 */
typedef enum control_reg_mode_v150 {
    /** @if Eng  Timer mode: one shot mode(Same as RTC_V150_MODE_ONE_SHOT_1).
     *  @else    定时器控制模式：单触发模式（等同于RTC_V150_MODE_ONE_SHOT_1）。
     *  @endif */
    RTC_V150_MODE_ONE_SHOT,
    /** @if Eng  Timer mode: periodic mode.
     *  @else    定时器控制模式：周期触发模式。
     *  @endif */
    RTC_V150_MODE_PERIODIC,
    /** @if Eng  Timer mode: one shot mode(Same as RTC_V150_MODE_ONE_SHOT).
     *  @else    定时器控制模式：单触发模式（等同于RTC_V150_MODE_ONE_SHOT）。
     *  @endif */
    RTC_V150_MODE_ONE_SHOT_1,
    /** @if Eng  Timer mode: free run mode.
     *  @else    定时器控制模式：自由运行模式。
     *  @endif */
    RTC_V150_MODE_FREERUN
} control_reg_mode_v150_t;

/**
 * @if Eng
 * @brief  HAL RTC initialize interface.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @param  [in]  callback Callback of RTC.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t
 * @else
 * @brief  HAL层RTC的初始化接口。
 * @param  [in]  index 硬件定时器索引值，参考 @ref rtc_index_t 。
 * @param  [in]  callback RTC的回调函数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t hal_rtc_v150_init(rtc_index_t index, hal_rtc_callback_t callback);

/**
 * @if Eng
 * @brief  HAL RTC deinitialize interface.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @else
 * @brief  HAL层RTC的去初始化接口。
 * @param  [in]  index 硬件定时器索引值，参考 @ref rtc_index_t 。
 * @endif
 */
void hal_rtc_v150_deinit(rtc_index_t index);

/**
 * @if Eng
 * @brief  HAL RTC start the load count of hardware RTC interface.
 * @param  [in]  index Index of low layer RTC. For detail, see @ref rtc_index_t.
 * @else
 * @brief  HAL层启动硬件定时器计数的接口。
 * @param  [in]  index RTC底层索引值，参考 @ref rtc_index_t 。
 * @endif
 */
void hal_rtc_v150_start(rtc_index_t index);

/**
 * @if Eng
 * @brief  HAL RTC stop the load count of hardware RTC interface.
 * @param  [in]  index Index of low layer RTC. For detail, see @ref rtc_index_t.
 * @else
 * @brief  HAL层停止硬件定时器计数的接口。
 * @param  [in]  index rtc底层索引值，参考 @ref rtc_index_t 。
 * @endif
 */
void hal_rtc_v150_stop(rtc_index_t index);

/**
 * @if Eng
 * @brief  HAL RTC set the load count of hardware RTC interface.
 * @param  [in]  index Index of low layer RTC. For detail, see @ref rtc_index_t.
 * @param  [in]  delay_count Time for load count.
 * @else
 * @brief  HAL层设置硬件计时器计数的接口。
 * @param  [in]  index rtc底层索引值，参考 @ref rtc_index_t 。
 * @param  [in]  delay_count 计时的时间。
 * @endif
 */
void hal_rtc_v150_config_load(rtc_index_t index, uint64_t delay_count);

/**
 * @if Eng
 * @brief  HAL RTC get the current value of hardware RTC interface.
 * @param  [in]  index Index of low layer RTC. For detail, see @ref rtc_index_t.
 * @param  [in]  is_enable Hardware RTC enable status.
 * @return RTC load count.
 * @else
 * @brief  HAL层获取硬件当时计时器剩余计数的接口。
 * @param  [in]  index rtc底层索引值，参考 @ref rtc_index_t 。
 * @param  [in]  is_enable 硬件定时器使能状态 。
 * @return rtc计数值。
 * @endif
 */
uint64_t hal_rtc_v150_get_current_value(rtc_index_t index, bool *is_enable);

/**
 * @if Eng
 * @brief  HAL RTC get the count of RTC IRQ.
 * @return RTC irq count.
 * @else
 * @brief  HAL层获取RTC发生中断的次数的值。
 * @return rtc中断计数值。
 * @endif
 */
uint32_t hal_rtc_v150_get_int_cnt_record(void);

/**
 * @if Eng
 * @brief  HAL RTC get the current interrupt status of hardware RTC interface.
 * @param  [in]  index Index of low layer RTC. For detail, see @ref rtc_index_t.
 * @return RTC load count.
 * @else
 * @brief  HAL层获取硬件当时计时器中断状态。
 * @param  [in]  index rtc底层索引值，参考 @ref rtc_index_t 。
 * @return rtc计数值。
 * @endif
 */
uint32_t hal_rtc_v150_get_int_status(rtc_index_t index);

/**
 * @if Eng
 * @brief  Handler of the rtc interrupt request.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @else
 * @brief  rtc中断处理函数。
 * @param  [in]  index 硬件定时器索引值，参考 @ref rtc_index_t 。
 * @endif
 */
void hal_rtc_v150_irq_handler(rtc_index_t index);

/**
 * @if Eng
 * @brief  clear rtc interrupt.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @else
 * @brief  清除rtc模块内部的中断。
 * @param  [in]  index 硬件定时器索引值，参考 @ref rtc_index_t 。
 * @endif
 */
void hal_rtc_v150_interrupt_clear(rtc_index_t index);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif