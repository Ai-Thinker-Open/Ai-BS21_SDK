/**
 * Copyright (c) @CompanyNameMagicTag 2024. All rights reserved.
 *
 * Description: BTS low latency module.
 */
#ifndef BTS_LOW_LATENCY
#define BTS_LOW_LATENCY

#include <stdint.h>
#include "errcode.h"

/**
 * @if Eng
 * @brief Struct of set em data event.
 * @else
 * @brief 设置em data事件上报。
 * @endif
 */
typedef struct {
    uint8_t status;                 /*!< @if Eng Status result.
                                         @else   状态结果。 @endif */
    uint16_t conn_handle;             /*!< @if Eng Connection handle.
                                         @else   连接句柄。 @endif */
} low_latency_set_em_data_t;

/**
 * @if Eng
 * @brief Definition of the low-latency mouse callback function interface.
 * @else
 * @brief Mouse侧发送low latency数据回调。
 * @endif
 */
typedef uint8_t *(*ble_low_latency_hid_data_callback)(uint8_t *length, uint16_t *att_handle, uint16_t conn_handle);

/**
 * @if Eng
 * @brief Callback invoked when ble em data is set.
 * @par Callback invoked when ble em data is set.
 * @attention 1.This function is called in SLE service context, should not be blocked or do long time waiting.
 * @attention 2.The memories of pointer are requested and freed by the SLE service automatically.
 * @param [in] conn_handle  connection handle.
 * @param [in] status     error code.
 * @retval #void no return value.
 * @else
 * @brief  设置ble em数据结果的回调函数。
 * @par    设置ble em数据结果的回调函数。
 * @attention  1. 该回调函数运行于BLE service线程，不能阻塞或长时间等待。
 * @attention  2. 指针由BLE service申请内存，也由BLE service释放，回调中不应释放。
 * @param [in] conn_handle  连接句柄。
 * @param [in] status     执行结果错误码。
 * @retval 无返回值。
 * @endif
 */
typedef void (*ble_low_latency_set_em_data_callback)(uint16_t conn_handle, uint8_t status);

/**
 * @if Eng
 * @brief Struct of BLE low latency callback function.
 * @else
 * @brief BLE low latency 管理回调函数接口定义。
 * @endif
 */
typedef struct {
    ble_low_latency_hid_data_callback hid_data_cb;              /*!< @if Eng BLE low latency get data callback.
                                                                     @else   BLE低时延数据获取回调函数。 @endif */
    ble_low_latency_set_em_data_callback ble_set_em_data_cb;    /*!< @if Eng Set em data callback.
                                                                     @else   设置em数据结果回调函数。 @endif */
} ble_low_latency_callbacks_t;

/**
 * @if Eng
 * @brief  BLE low latency callbacks register.
 * @par Description: BLE low latency callbacks register.
 * @param [in] cbks  Callback functions.
 * @retval error code.
 * @else
 * @brief  注册BLE低时延回调。
 * @par Description: 注册BLE低时延回调。
 * @param [in] cbks  回调函数。
 * @retval error code.
 * @endif
 */
errcode_t ble_low_latency_register_callbacks(ble_low_latency_callbacks_t *cbks);

/**
 * @if Eng
 * @brief  BLE set low latency mode.
 * @par Description: BLE set low latency mode.
 * @param [in] conn_handle  connection handle.
 * @param [in] enable  enable or disable.
 * @retval error code.
 * @else
 * @brief  BLE设置低时延模式。
 * @par Description: BLE设置低时延模式。
 * @param [in] conn_handle  connection handle.
 * @param [in] enable  enable or disable.
 * @retval error code.
 * @endif
 */
errcode_t ble_low_latency_set_em_data(uint16_t conn_handle, uint8_t enable);

#endif /* BTS_LOW_LATENCY */