/**
 * Copyright (c) @CompanyNameMagicTag 2024. All rights reserved.
 * Description: SLE Device Manager, module.
 */

/**
 * @defgroup sle_device_manager Device Manager API
 * @ingroup  SLE
 * @{
 */

#ifndef SLE_DEVICE_MANAGER
#define SLE_DEVICE_MANAGER

#include <stdint.h>
#include "errcode.h"
#include "sle_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief Enum of SLE power status.
 * @else
 * @brief SLE上电状态枚举.
 * @endif
 */
typedef enum {
    SLE_POWER_ON_SUCCESS,       /*!< @if Eng SLE power on success.
                                     @else   SLE上电成功. @endif */
    SLE_POWER_ON_FAIL,          /*!< @if Eng SLE power on fail.
                                     @else   SLE上电失败. @endif */
} sle_power_on_status_t;

/**
 * @if Eng
 * @brief Enum of SLE enable/disable status.
 * @else
 * @brief SLE使能/去使能状态枚举.
 * @endif
 */
typedef enum {
    SLE_ENABLE_DISABLE_SUCCESS,       /*!< @if Eng SLE enable/disable success.
                                           @else   SLE使能/去使能成功. @endif */
    SLE_ENABLE_DISABLE_FAIL,          /*!< @if Eng SLE enable/disable fail.
                                           @else   SLE使能/去使能失败. @endif */
} sle_enable_disable_status_t;

/**
 * @if Eng
 * @brief Callback invoked when device power on.
 * @par Callback invoked when device power on.
 * @attention 1.This function is called in SLE service context,should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the SLE service automatically.
 * @param [in] status error code.
 * @retval void no return value.
 * @par Dependency:
 * @li  sle_common.h
 * @see sle_dev_manager_callbacks_t
 * @else
 * @brief  SLE设备上电。
 * @par    SLE设备上电。
 * @attention  1. 该回调函数运行于SLE service线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLE service申请内存，也由SLE service释放，回调中不应释放。
 * @param [in] status 执行结果错误码。
 * @retval 无返回值。
 * @par 依赖:
 * @li  sle_common.h
 * @see sle_dev_manager_callbacks_t
 * @endif
 */
typedef void (*sle_power_on_callback)(uint8_t status);

/**
 * @if Eng
 * @brief Callback invoked when SLE stack enable.
 * @par Callback invoked when SLE stack enable.
 * @attention 1.This function is called in SLE service context,should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the SLE service automatically.
 * @param [in] status enable status, { @ref sle_enable_disable_status_t }.
 * @retval void no return value.
 * @par Dependency:
 * @li  sle_common.h
 * @see sle_dev_manager_callbacks_t
 * @else
 * @brief  SLE协议栈使能。
 * @par    SLE协议栈使能。
 * @attention  1. 该回调函数运行于SLE service线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLE service申请内存，也由SLE service释放，回调中不应释放。
 * @param [in] status 使能状态, { @ref sle_enable_disable_status_t }.
 * @retval 无返回值。
 * @par 依赖:
 * @li  sle_common.h
 * @see sle_dev_manager_callbacks_t
 * @endif
 */
typedef void (*sle_enable_callback)(uint8_t status);

/**
 * @if Eng
 * @brief Callback invoked when SLE stack disable.
 * @par Callback invoked when SLE stack disable.
 * @attention 1.This function is called in SLE service context,should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the SLE service automatically.
 * @param [in] status disable status, { @ref sle_enable_disable_status_t }.
 * @retval void no return value.
 * @par Dependency:
 * @li  sle_common.h
 * @see sle_dev_manager_callbacks_t
 * @else
 * @brief  SLE协议栈去使能。
 * @par    SLE协议栈去使能。
 * @attention  1. 该回调函数运行于SLE service线程，不能阻塞或长时间等待。
 * @attention  2. 指针由SLE service申请内存，也由SLE service释放，回调中不应释放。
 * @param [in] status 去使能状态, { @ref sle_enable_disable_status_t }.
 * @retval 无返回值。
 * @par 依赖:
 * @li  sle_common.h
 * @see sle_dev_manager_callbacks_t
 * @endif
 */
typedef void (*sle_disable_callback)(uint8_t status);

/**
 * @if Eng
 * @brief Struct of SLE device announce callback function.
 * @else
 * @brief SLE 设备公开回调函数接口定义。
 * @endif
 */
typedef struct {
    sle_power_on_callback sle_power_on_cb;                  /*!< @if Eng SLE device power on callback.
                                                                 @else   SLE设备上电回调函数。 @endif */
    sle_enable_callback sle_enable_cb;                      /*!< @if Eng SLE stack enable callback.
                                                                 @else   SLE协议栈使能回调函数。 @endif */
    sle_disable_callback sle_disable_cb;                    /*!< @if Eng SLE stack disable callback.
                                                                 @else   SLE协议栈去使能回调函数。 @endif */
} sle_dev_manager_callbacks_t;

/**
 * @if Eng
 * @brief  Enable SLE stack.
 * @par Description: Enable SLE stack.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @par Depends:
 * @li sle_common.h
 * @else
 * @brief  使能SLE协议栈。
 * @par Description: 使能SLE协议栈。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @par 依赖：
 * @li sle_common.h
 * @endif
 */
errcode_t enable_sle(void);

/**
 * @if Eng
 * @brief  Disable SLE stack.
 * @par Description: Disable SLE stack.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @par Depends:
 * @li sle_common.h
 * @else
 * @brief  关闭SLE协议栈。
 * @par Description: 关闭SLE协议栈。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @par 依赖：
 * @li sle_common.h
 * @endif
 */
errcode_t disable_sle(void);

/**
 * @if Eng
 * @brief  Register SLE device manager callbacks.
 * @par Description: Register SLE device manager callbacks.
 * @param [in] func Callback function.
 * @retval error code.
 * @else
 * @brief  注册SLE设备管理回调函数。
 * @par Description: 注册SLE设备管理回调函数。
 * @param [in] func 回调函数。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t sle_dev_manager_register_callbacks(sle_dev_manager_callbacks_t *func);

#ifdef __cplusplus
}
#endif
#endif /* SLE_DEVICE_MANAGER */
/**
 * @}
 */
