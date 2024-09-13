/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides HAL qdec \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-15, Create file. \n
 */
#ifndef HAL_QDEC_H
#define HAL_QDEC_H

#include <stdint.h>
#include <stdbool.h>
#include "errcode.h"
#include "platform_core.h"
#include "qdec_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_qdec_api QDEC
 * @ingroup  drivers_hal_qdec
 * @{
 */

/**
 * @if Eng
 * @brief  QDEC configuration structure.
 * @else
 * @brief  QDEC配置结构体
 * @endif
 */
typedef struct {
    hal_qdec_report_per_t reportper;            /*!< @if Eng Report period in samples.
                                                     @else   样本报告周期 @endif */
    hal_qdec_sample_per_t sampleper;            /*!< @if Eng Sampling period in microseconds.
                                                     @else   采样周期（微秒级） @endif */
    hal_qdec_defen_num_t  defen_num;            /*!< @if Eng Debounce num.
                                                     @else   去抖周期 @endif */
    uint32_t              psela;                /*!< @if Eng Pin number for A input.
                                                     @else   A输入的管脚编号 @endif */
    uint32_t              pselb;                /*!< @if Eng Pin number for B input.
                                                     @else   B输入的管脚编号 @endif */
    uint32_t              pselled;              /*!< @if Eng Pin number for LED output.
                                                     @else   LED输出的管脚编号 @endif */
    uint32_t              ledpre;               /*!< @if Eng Time of LED is switched on before sampling in microseconds
                                                     @else   采样前LED打开的时间（微秒级） @endif */
    hal_qdec_led_pol_t    ledpol;               /*!< @if Eng Active LED polarity.
                                                     @else   有源LED极性 @endif */
    bool                  defence;              /*!< @if Eng Switch of debouncing filter.
                                                     @else   去抖滤波器功能开关 @endif */
    bool                  sample_inten;         /*!< @if Eng Enabling sample ready interrupt.
                                                     @else   使能样本就绪中断 @endif */
    uint8_t               interrupt_priority;   /*!< @if Eng QDEC interrupt priority.
                                                     @else   QDEC中断优先级 @endif */
} qdec_config_t;

/**
 * @if Eng
 * @brief  QDEC default configuration.
 * @else
 * @brief  QDEC默认配置
 * @endif
 */
#define QDEC_DEFAULT_CONFIG                                              \
{                                                                        \
    .reportper           = QDEC_CONFIG_REPORTPER,                        \
    .sampleper           = QDEC_CONFIG_SAMPLEPER,                        \
    .defen_num           = QDEC_DEBOUNCE_NUM,                            \
    .psela               = QDEC_CONFIG_PIO_A,                            \
    .pselb               = QDEC_CONFIG_PIO_B,                            \
    .pselled             = QDEC_CONFIG_PIO_LED,                          \
    .ledpre              = QDEC_CONFIG_LEDPRE,                           \
    .ledpol              = QDEC_CONFIG_LEDPOL,                           \
    .defence             = QDEC_CONFIG_DEFENCE,                          \
    .sample_inten        = QDEC_CONFIG_SAMPLE_INTEN,                     \
    .interrupt_priority  = IRQ_QDEC,                                     \
}

/**
 * @if Eng
 * @brief  qdec callback function.
 * @param  [in]  argc Parameters of the callback function.
 * @param  [in]  argv Parameters of the callback function.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  qdec回调函数
 * @param  [in]  argc 回调参数
 * @param  [in]  argv 回调参数
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
typedef int32_t (*qdec_callback_t)(int argc, char *argv[]);

/**
 * @if Eng
 * @brief  Init device for hal qdec.
 * @param  [in]  config Structure for configuring qdec.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  HAL层QDEC的初始化接口
 * @param  [in]  config 用于配置qdec的结构体
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
typedef void (*hal_qdec_init_t)(qdec_config_t const *config);

/**
 * @if Eng
 * @brief  Deinit device for hal qdec.
 * @else
 * @brief  HAL层QDEC的去初始化接口
 * @endif
 */
typedef void (*hal_qdec_deinit_t)(void);

/**
 * @if Eng
 * @brief  Enable device for hal qdec.
 * @else
 * @brief  HAL层QDEC的使能接口
 * @endif
 */
typedef void (*hal_qdec_enable_t)(void);

/**
 * @if Eng
 * @brief  Disable device for hal qdec.
 * @else
 * @brief  HAL层QDEC去使能接口
 * @endif
 */
typedef void (*hal_qdec_disable_t)(void);

/**
 * @if Eng
 * @brief  Reads the values of acc and accdbl in the single transition data for hal qdec.
 * @param  [out]  acc Number of registration cumulative valid conversions.
 * @param  [out]  accdbl Indicates the number of repeated conversions detected during registration.
 * @else
 * @brief  HAL层读取单次跃迁数据acc和accdbl的值
 * @param  [out]  acc 注册累计有效转换的次数
 * @param  [out]  accdbl 注册累计检测到重复转换的次数
 * @endif
 */
typedef void (*hal_qdec_get_acc_dbl_t)(int16_t *acc, int16_t *accdbl);

 /**
 * @if Eng
 * @brief  QDEC callback function for hal.
 * @param  [in]  argc Variable parameter, which describes the number of parameters.
 * @param  [in]  argv Variable parameter, which used to describe the parameter content and the number of parameters.
 * @else
 * @brief  HAL层QDEC回调函数
 * @param  [in]  argc 可变参数，用于描述参数个数
 * @param  [in]  argv 可变参数，用于描述参数内容
 * @endif
 */
typedef int32_t (*hal_qdec_callback_t)(int argc, char *argv[]);

/**
 * @if Eng
 * @brief  Interrupt handling for hal qdec.
 * @param  [in]  callback QDEC callback function for hal.
 * @else
 * @brief  HAL层回调接口
 * @param  [in]  callback HAL层QDEC回调函数
 * @endif
 */
typedef void (*hal_qdec_register_callback_t)(hal_qdec_callback_t callback);

/**
 * @if Eng
 * @brief  Functions interface between qdec driver and qdec hal.
 * @else
 * @brief  Driver层QDEC和HAL层QDEC的函数接口
 * @endif
 */
typedef struct {
    hal_qdec_init_t                 init;                       /*!< @if Eng Init qdec interface.
                                                                     @else   HAL层QDEC的初始化接口 @endif */
    hal_qdec_deinit_t               deinit;                     /*!< @if Eng Deinit qdec interface.
                                                                     @else   HAL层QDEC去初始化接口 @endif */
    hal_qdec_enable_t               enable;                     /*!< @if Eng Enable qdec interface.
                                                                     @else   HAL层QDEC的使能接口 @endif */
    hal_qdec_disable_t              disable;                    /*!< @if Eng Disable qdec interface.
                                                                     @else   HAL层QDEC去使能接口 @endif */
    hal_qdec_get_acc_dbl_t          read_accumulators;          /*!< @if Eng Get the accaccumulators value interface.
                                                                     @else   HAL层获取accaccumulators数值接口 @endif */
    hal_qdec_register_callback_t    register_callback;          /*!< @if Eng Handle interrupt interface.
                                                                     @else   HAL层回调接口 @endif */
} hal_qdec_funcs_t;

/**
 * @if Eng
 * @brief  Register @ref hal_qdec_funcs_t into the g_hal_qdecs_funcs.
 * @param  [in]  funcs Interface between qdec driver and qdec hal.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  注册 @ref hal_qdec_funcs_t 到 g_hal_qdecs_funcs
 * @param  [in]  funcs Driver层QDEC和HAL层QDEC的接口实例
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
errcode_t hal_qdec_register_funcs(hal_qdec_funcs_t *funcs);

/**
 * @if Eng
 * @brief  Unregister @ref hal_qdec_funcs_t into the g_hal_qdecs_funcs.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  去注册 @ref hal_qdec_funcs_t 到 g_hal_qdecs_funcs
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
void hal_qdec_unregister_funcs(void);

/**
 * @if Eng
 * @brief  Get interface between qdec driver and qdec hal, see @ref hal_qdec_funcs_t.
 * @return Interface between qdec driver and qdec hal, see @ref hal_qdec_funcs_t.
 * @else
 * @brief  获取Driver层QDEC和HAL层QDEC的接口实例，参考 @ref hal_qdec_funcs_t.
 * @return Driver层QDEC和HAL层QDEC的接口实例，参考 @ref hal_qdec_funcs_t.
 * @endif
 */
hal_qdec_funcs_t *hal_qdec_get_funcs(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif