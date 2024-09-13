/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides V150 HAL qdec \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-15, Create file. \n
 */
#ifndef HAL_QDEC_V150_H
#define HAL_QDEC_V150_H

#include "hal_qdec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_qdec_v150 QDEC_V150
 * @ingroup  drivers_hal_qdec
 * @{
 */

/**
 * @if Eng
 * @brief  QDEC interrupt tasks.
 * @else
 * @brief  QDEC中断任务
 * @endif
 */
typedef enum {
    HAL_QDEC_INT_STOPPED_TASK,
    HAL_QDEC_INT_ACCOF_TASK,
    HAL_QDEC_INT_DBLRDY_TASK,
    HAL_QDEC_INT_REPORTRDY_TASK,
    HAL_QDEC_INT_SAMPLERDY_TASK
} hal_qdec_int_task_t;

/**
 * @if Eng
 * @brief  QDEC report event data.
 * @else
 * @brief  QDEC事件上报数据
 * @endif
 */
typedef struct {
    int8_t acc;                     /*!< @if Eng Value of count accumulator.
                                         @else   累加器计数值 @endif */
    uint16_t accdbl;                /*!< @if Eng Value of double accumulator.
                                         @else   双滚轮错误累加值 @endif */
} hal_qdec_report_data_t;

/**
 * @if Eng
 * @brief  QDEC event handler structure.
 * @else
 * @brief  QDEC事件处理结构体
 * @endif
 */
typedef struct {
    hal_qdec_int_task_t type;       /*!< @if Eng Event type.
                                         @else   事件类型 @endif */
    int8_t sample;                  /*!< @if Eng Sample event data.
                                         @else   采样事件数据 @endif */
    hal_qdec_report_data_t report;  /*!< @if Eng Report event data.
                                         @else   报告事件数据 @endif */
} qdec_event_data_t;

/**
 * @if Eng
 * @brief  Get functions of the qdec v150.
 * @return The functions of the qdec v150.
 * @else
 * @brief  获取 qdec v150 的实例。
 * @return Qdec v150 的实例。
 * @endif
 */
hal_qdec_funcs_t *hal_qdec_v150_get_funcs(void);

/**
 * @if Eng
 * @brief  Handler of the qdec interrupt request.
 * @else
 * @brief  QDEC中断处理。
 * @endif
 */
void hal_qdec_irq_handler(void);

/**
 * @if Eng
 * @brief  Switch the clock divider of qdec.
 * @param  [in]  div_num Clock divider.
 * @else
 * @brief  QDEC时钟分频系数切换。
 * @param  [in]  div_num 时钟分频系数。
 * @endif
 */
void hal_qdec_freq_div(uint32_t div_num);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif