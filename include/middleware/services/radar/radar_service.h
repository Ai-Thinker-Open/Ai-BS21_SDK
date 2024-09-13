/**
* @file radar_service.h
*
* Copyright (c) CompanyNameMagicTag 2023-2023.All rights reserved. \n
* Description: header file for radar service api. \n
* Author: CompanyName \n
* History: \n
* 2023-11-27，初始化该文件 \n
*/

#ifndef SERVICE_RADAR_SERVICE_H
#define SERVICE_RADAR_SERVICE_H

#include <stdint.h>
#include "errcode.h"

#ifdef __cplusplus
extern "C" {
#endif

#define RADAR_RANGE_BIN_NUM 20
#define RADAR_RAW_DATA_NUM (2 * RADAR_RANGE_BIN_NUM)

/**
 * @defgroup middleware_service_radar_service RADAR Service
 * @ingroup  middleware_service_radar
 * @{
 */

/**
 * @if Eng
 * @brief  radar status set.
 * @else
 * @brief  雷达状态配置。
 * @endif
 */
typedef enum {
    RADAR_STATUS_STOP = 0,  /*!< @if Eng radar status set: stop
                                @else   雷达状态配置停止 @endif */
    RADAR_STATUS_START,     /*!< @if Eng radar status set: start
                                @else   雷达状态配置启动 @endif */
    RADAR_STATUS_RESET,     /*!< @if Eng radar status set: rst
                                @else   雷达状态配置复位 @endif */
    RADAR_STATUS_RESUME,    /*!< @if Eng radar status set: resume
                                @else   雷达状态配置状态恢复 @endif */
} radar_set_sts_t;

/**
 * @if Eng
 * @brief  radar status.
 * @else
 * @brief  雷达状态。
 * @endif
 */
typedef enum {
    RADAR_STATUS_IDLE = 0,  /*!< @if Eng radar status: idle
                                @else   雷达状态未工作 @endif */
    RADAR_STATUS_RUNNING,   /*!< @if Eng radar status: running
                                @else   雷达状态工作 @endif */
} radar_get_sts_t;

/**
 * @if Eng
 * @brief  radar result.
 * @else
 * @brief  雷达结果。
 * @endif
 */
typedef struct {
    uint32_t lower_boundary;    /*!< @if Eng radar result: lower boundary
                                    @else   雷达结果靠近检测下边界 @endif */
    uint32_t upper_boundary;    /*!< @if Eng radar result: upper boundary
                                    @else   雷达结果靠近检测上边界 @endif */
    uint8_t is_human_presence;  /*!< @if Eng radar result: human presence
                                    @else   雷达结果有无人体存在 @endif */
    uint8_t reserved_0;
    uint8_t reserved_1;
    uint8_t reserved_2;
} radar_result_t;

/**
 * @if Eng
 * @brief Callback invoked when the radar detection is complete and the result changes.
 * @par Callback invoked when the radar detection is complete and the result changes.
 * @attention This callback function runs on the radar feature thread.
 * @attention It cannot be blocked or wait for a long time or use a large stack space.
 * @param [in] res radar detect result.
 * @else
 * @brief  雷达检测完成并且结果出现变化时的回调函数。
 * @par    雷达检测完成并且结果出现变化时的回调函数。
 * @attention  该回调函数运行于radar feature线程, 不能阻塞或长时间等待, 不能使用较大栈空间。
 * @param [in] res 雷达检测结果。
 * @endif
 */
typedef void (*radar_result_cb_t)(radar_result_t *result);

/**
 * @if Eng
 * @brief  radar raw data.
 * @attention IQ alternate storage.
 * @else
 * @brief  雷达原始数据。
 * @attention IQ交替存储。
 * @endif
 */
typedef struct {
    int32_t data[RADAR_RAW_DATA_NUM];
} radar_raw_data_t;

/**
 * @if Eng
 * @brief Callback function when radar echo reception is complete.
 * @par Callback function when radar echo reception is complete.
 * @attention This callback function runs on the radar driver thread.
 * @attention It cannot be blocked or wait for a long time or use a large stack space.
 * @param [in] res radar detect raw data.
 * @else
 * @brief  雷达回波接收完成时的回调函数。
 * @par    雷达回波接收完成时的回调函数。
 * @attention  该回调函数运行于radar driver线程, 不能阻塞或长时间等待, 不能使用较大栈空间。
 * @param [in] res 雷达检测原始数据。
 * @endif
 */
typedef void (*radar_raw_data_cb_t)(radar_raw_data_t *raw_data);

/**
 * @if Eng
 * @brief  Set status of radar.
 * @par Description: Set status of radar.
 * @param [in] sts status of radar, see @ref radar_set_sts_t.
 * @retval error code.
 * @else
 * @brief  设置雷达状态。
 * @par Description: 设置雷达状态。
 * @param [in] sts 雷达状态。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_set_status(uint8_t sts);

/**
 * @if Eng
 * @brief  Get status of radar.
 * @par Description: Get status of radar.
 * @param [in] *sts status of radar, see @ref radar_get_sts_t.
 * @retval error code.
 * @else
 * @brief  获取雷达状态。
 * @par Description: 获取雷达状态。
 * @param [in] *sts 雷达状态。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_get_status(uint8_t *sts);

/**
 * @if Eng
 * @brief  Radar result callback registration function.
 * @par Description: Radar result callback registration function.
 * @param [in] cb callback function.
 * @retval error code.
 * @else
 * @brief  雷达结果回调注册函数。
 * @par Description: 雷达结果回调注册函数。
 * @param [in] cb 回调函数。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_register_result_cb(radar_result_cb_t cb);

/**
 * @if Eng
 * @brief  Radar raw data callback registration function.
 * @par Description: Radar raw data callback registration function.
 * @param [in] cb callback function.
 * @retval error code.
 * @else
 * @brief  雷达原始数据回调注册函数。
 * @par Description: 雷达原始数据回调注册函数。
 * @param [in] cb 回调函数。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_register_raw_data_cb(radar_raw_data_cb_t cb);

/**
 * @if Eng
 * @brief  Set quit delay time of radar.
 * @par Description: Set quit delay time of radar.
 * @param [in] time quit delay time of radar.
 * @retval error code.
 * @else
 * @brief  设置退出延迟时间。
 * @par Description: 设置退出延迟时间。
 * @param [in] time 退出延迟时间。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_set_delay_time(uint16_t time);

/**
 * @if Eng
 * @brief  Get quit delay time of radar.
 * @par Description: Get quitdelay time of radar.
 * @param [in] *time quit delay time of radar.
 * @retval error code.
 * @else
 * @brief  获取退出延迟时间。
 * @par Description: 获取退出延迟时间。
 * @param [in] *time 退出延迟时间。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_get_delay_time(uint16_t *time);

/**
 * @if Eng
 * @brief  Get isolation infomation of radar.
 * @par Description: Get isolation infomation of radar.
 * @param [in] *iso isolation infomation of radar.
 * @retval error code.
 * @else
 * @brief  获取天线隔离度信息。
 * @par Description: 获取天线隔离度信息。
 * @param [in] *iso 天线隔离度信息。
 * @retval 执行结果错误码。
 * @endif
 */
errcode_t uapi_radar_get_isolation(uint16_t *iso);

#ifdef __cplusplus
}
#endif
#endif
/**
 * @}
 */
