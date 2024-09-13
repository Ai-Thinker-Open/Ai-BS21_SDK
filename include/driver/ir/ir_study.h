/**
 * Copyright (c) @CompanyNameMagicTag 2024-2024. All rights reserved. \n
 *
 * Description: IR STUDY header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2024-02-02, Create file. \n
 */
#ifndef IR_STUDY_H
#define IR_STUDY_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

typedef enum {
    IR_STUDY_SUCCESS,
    IR_STUDY_OVERFLOW,
    IR_STUDY_FAILURE,
} ir_study_state_t;

/**
 * @if Eng
 * @brief  Typedef for the IR Callback.
 *         It returns the state of the ir study.
 * @param  [in] state the state of the ir study.
 * @else
 * @brief  IR回调的类型定义，它返回红外学习的状态。
 * @param  [in] state 红外学习的状态.
 * @endif
 */
typedef void (*ir_callback_t)(ir_study_state_t state);

/**
 * @if Eng
 * @brief  IR study.
 * @param  [in] key_value Key for IR learning.
 * @else
 * @brief  红外学习。
 * @param  [in] key_value 进行红外学习的按键。
 * @endif
 */
void uapi_ir_study_start(uint8_t key_value);

/**
 * @if Eng
 * @brief  Check whether the key have been learned.
 * @param  [in] key_value Keys to be checked.
 * @param  [out] len Length of the learned IR pattern array.
 * @retval The IR carrier frequency in Hertz.
 * @else
 * @brief  检查按键是否学习过。
 * @param  [in] key_value 要检查的按键。
 * @param  [out] len 学习后的红外数组的长度。
 * @retval IR载波频率（以赫兹为单位）。
 * @endif
 */
uint32_t uapi_ir_study_check(uint8_t key_value, uint32_t* len);

/**
 * @if Eng
 * @brief  IR TX port.
 * @param  [in] key_value Learned Key.
 * @param  [in] length Length of the learned IR pattern array.
 * @param  [in] freq The IR carrier frequency in Hertz.
 * @else
 * @brief  红外发送接口。
 * @param  [in] key_value 学习过的按键。
 * @param  [in] length 学习后的红外pattern数组的长度。
 * @param  [in] freq IR载波频率（以赫兹为单位）。
 * @endif
 */
void uapi_ir_study_send(uint8_t key_value, uint32_t length, uint32_t freq);

/**
 * @if Eng
 * @brief  Restore default settings.
 * @else
 * @brief  恢复默认设置。
 * @endif
 */
void uapi_ir_restore_default_setting(void);

/**
 * @if Eng
 * @brief  IR study.
 * @param  [in] key_value Key for IR learning(using comparator).
 * @else
 * @brief  红外学习。
 * @param  [in] key_value 进行红外学习的按键（使用比较器）。
 * @endif
 */
void uapi_ir_study_by_cmp_start(uint8_t key_value);

/**
 * @if Eng
 * @brief  register IR irq event callback.
 * @param  [in]  callback  Event callback.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  注册IR中断事件回调函数。
 * @param  [in]  callback 事件回调函数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_ir_register_irq_callback(ir_callback_t callback);

/**
 * @if Eng
 * @brief  unregister IR irq event callback.
 * @else
 * @brief  取消注册IR中断事件回调函数。
 * @endif
 */
void uapi_ir_unregister_irq_callback(void);
#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */


#endif