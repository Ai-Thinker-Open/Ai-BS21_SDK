/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides CAN driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-02-22, Create file. \n
 */
#ifndef CAN_H
#define CAN_H

#include <stdint.h>
#include <stdbool.h>
#include "errcode.h"
#include "common_def.h"
#include "can_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_can CAN
 * @ingroup  drivers_driver
 * @{
 */

#define build_can_fd_format_standard_data_frame(id, bit_rate_switch) { \
    .std_id = (id), \
    .extend_id = 0, \
    .rtr = 0, \
    .ide = 0, \
    .fdf = 1, \
    .brs = (bit_rate_switch), \
}

#define build_can_fd_format_extend_data_frame(id, ex_id, bit_rate_switch) { \
    .std_id = (id), \
    .extend_id = (ex_id), \
    .rtr = 0, \
    .ide = 1, \
    .fdf = 1, \
    .brs = (bit_rate_switch), \
}
#define build_can_standard_data_frame(id) { \
    .std_id = (id), \
    .extend_id = 0, \
    .rtr = 0, \
    .ide = 0, \
    .fdf = 0, \
    .brs = 0, \
}

#define build_can_extend_data_frame(id, ex_id) { \
    .std_id = (id), \
    .extend_id = (ex_id), \
    .rtr = 0, \
    .ide = 1, \
    .fdf = 0, \
    .brs = 0, \
}

#define build_can_standard_remote_frame(id) { \
    .std_id = (id), \
    .extend_id = 0, \
    .rtr = 1, \
    .ide = 0, \
    .fdf = 0, \
    .brs = 0, \
}

#define build_can_extend_remote_frame(id, ex_id) { \
    .std_id = (id), \
    .extend_id = (ex_id), \
    .rtr = 1, \
    .ide = 1, \
    .fdf = 0, \
    .brs = 0, \
}

/**
 * @if Eng
 * @brief  Standard CAN Baud rate.
 * @else
 * @brief  标准CAN协议波特率。
 * @endif
 */
typedef enum can_baud_rate {
    CAN_BPS_10K = 10,
    CAN_BPS_20K = 20,
    CAN_BPS_50K = 50,
    CAN_BPS_125K = 125,
    CAN_BPS_250K = 250,
    CAN_BPS_500K = 500,
    CAN_BPS_800K = 800,
    CAN_BPS_1M = 1000,
    CAN_BPS_MAX = 1000
} can_baud_rate_t;

/**
 * @if Eng
 * @brief  CAN-FD Data segment Baud rate.
 * @else
 * @brief  CAN-FD数据段波特率。
 * @endif
 */
typedef enum can_fd_baud_rate {
    CAN_FD_BPS_10K = 10,
    CAN_FD_BPS_20K = 20,
    CAN_FD_BPS_50K = 50,
    CAN_FD_BPS_125K = 125,
    CAN_FD_BPS_250K = 250,
    CAN_FD_BPS_500K = 500,
    CAN_FD_BPS_800K = 800,
    CAN_FD_BPS_1M = 1000,
    CAN_FD_BPS_2M = 2000,
    CAN_FD_BPS_4M = 4000,
    CAN_FD_BPS_5M = 5000,
    CAN_FD_BPS_8M = 8000,
    CAN_FD_BPS_10M = 10000,
    CAN_FD_BPS_MAX = 10000
} can_fd_baud_rate_t;

/**
 * @if Eng
 * @brief  CAN Sample point.
 * @else
 * @brief  CAN采样点。
 * @endif
 */
typedef enum can_sample_point {
    CAN_SAMPLE_PERCENT_75,
    CAN_SAMPLE_PERCENT_80,
    CAN_SAMPLE_PERCENT_85,
    CAN_SAMPLE_PERCENT_MAX
}can_sample_point_t;

/**
 * @if Eng
 * @brief  CAN Interrupt Status.
 * @else
 * @brief  CAN中断状态。
 * @endif
 */
typedef enum can_int_sts {
    CAN_FRAME_RECEIVED_INT,
    CAN_ERROR_PASSIVE_INT,
    CAN_BUS_OFF_INT,
} can_int_sts_t;

/**
 * @if Eng
 * @brief  CAN opreation mode.
 * @else
 * @brief  CAN 工作模式。
 * @endif
 */
typedef enum can_mode {
    NORMAL_OPREATION = 0x0,
    LOOP_BACK_MODE = 0x1
} can_mode_t;

/**
 * @if Eng
 * @brief  CAN filter type.
 * @else
 * @brief  CAN 滤波器格式。
 * @endif
 */
typedef enum filter_type {
    RANGE_FILTER = 0x0,
    DUAL_ID_FILTER,
    CLASSIC_FILTER = 0x3
} can_filter_type_t;

/**
 * @if Eng
 * @brief  CAN controller status.
 * @else
 * @brief  CAN 控制器状态。
 * @endif
 */
typedef enum can_controller_sts {
    CAN_STS_ERROR_ACTIVE,
    CAN_STS_ERROR_PASSIVE,
    CAN_STS_BUS_OFF,
    CAN_BUS_NOT_INIT
} can_controller_sts_t;

/**
 * @if Eng
 * @brief  Nominal and Data bit time config.
 * @else
 * @brief  配置标称位时间和数据段位时间。
 * @endif
 */
typedef struct can_global_config {
    uint32_t std_baud_rate;            /*!< @if Eng Standard CAN Baud rate. @ref can_baud_rate_t
                                            @else 标准CAN协议波特率。 @ref can_baud_rate_t @endif */
    uint32_t fd_baud_rate;             /*!< @if Eng CAN-FD Data segment Baud rate. @ref can_fd_baud_rate_t
                                            @else CAN-FD数据段波特率。 @ref can_fd_baud_rate_t @endif */
    uint8_t point;                     /*!< @if Eng CAN Sample point. @ref can_sample_point_t
                                            @else CAN采样点。 @ref can_sample_point_t @endif */
    uint8_t can_mode;                  /*!< @if Eng CAN opreation mode. @ref can_sample_point_t
                                            @else CAN采样点。 @ref can_sample_point_t @endif */
} can_global_config_t;

/**
 * @if Eng
 * @brief  CAN filter structure.
 * @else
 * @brief  CAN滤波结构。
 * @endif
 */
typedef struct can_filter {
    uint32_t fid1;                     /*!< @if Eng First ID of the filter.
                                            @else   滤波器的首要ID @endif */
    uint32_t fid2;                     /*!< @if Eng Second ID of the filter, which can be used as a mask,
                                                    secondary identifier, or right boundary.
                                            @else   滤波器的次要ID，可作为掩码、次要标识符或右边界。 @endif */
    uint8_t fifo_id;                   /*!< @if Eng Index of the Rx-FIFO bound to the filter.
                                                    Interrupt priorities are sorted by index in ASC order.
                                            @else   滤波器绑定的Rx-FIFO索引。中断优先级按索引升序排列。 @endif */
    uint8_t filter_type;               /*!< @if Eng Filter type.
                                            @else   滤波器模式 @endif */
} can_filter_t;

typedef struct can_filter_list {
    can_filter_t *filters;             /*!< @if Eng Filter list.
                                            @else 滤波器列表。 @endif */
    uint8_t filter_num;                /*!< @if Eng Filter number.
                                            @else 滤波器个数。 @endif */
} can_filter_list_t;

/**
 * @if Eng
 * @brief  Structure of the CAN frame Arbitration field.
 * @else
 * @brief  CAN帧仲裁域结构。
 * @endif
 */
typedef struct can_msg_attr {
    uint32_t std_id;                   /*!< @if Eng Standard identifier.
                                            @else   标准标识符。 @endif */
    uint32_t extend_id;                /*!< @if Eng Extra identifier.
                                            @else   扩展标识符。 @endif */
    uint8_t rtr;                       /*!< @if Eng Remote frame flag.
                                            @else   远程帧标志。 @endif */
    uint8_t ide;                       /*!< @if Eng Extended format flag.
                                            @else   扩展格式标志。 @endif */
    uint8_t fdf;                       /*!< @if Eng FD format flag.
                                            @else   FD帧格式标志。 @endif */
    uint8_t brs;                       /*!< @if Eng Bit rate switch.
                                            @else   波特率切换标志。 @endif */
} can_msg_attr_t;

/**
 * @if Eng
 * @brief  CAN interrupt callback function.
 * @param  [in]  bus CAN bus line select.
 * @param  [in]  status CAN Interrupt Status. @ref can_int_sts_t
 * @param  [in]  received_msg Arbitration field of the received CAN frame.
 * @param  [in]  data Received data.
 * @param  [in]  length Received data length.
 * @else
 * @brief  CAN中断回调函数。
 * @param  [in]  bus CAN总线选择。
 * @param  [in]  status CAN中断状态。 @ref can_int_sts_t
 * @param  [in]  received_msg 接收到的CAN帧仲裁域。
 * @param  [in]  data 接收到的数据。
 * @param  [in]  length 接收到的数据长度。
 * @endif
 */
typedef void (*can_callback_t)(can_int_sts_t status, can_msg_attr_t *received_msg,
                               uint8_t *data, uint8_t length);

/**
 * @if Eng
 * @brief  Initialize and Configure CAN-FD.
 * @param  [in]  bus CAN bus line select.
 * @param  [in]  global_config CAN-FD global configuration, including Baud rate and operating mode configuration.
 * @param  [in]  std_filter Filtering configuration of the CAN-FD standard identifier.
 * @param  [in]  ex_filter Filtering configuration of the CAN-FD extended identifier.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  初始化并配置CAN-FD。
 * @param  [in]  bus CAN总线选择。
 * @param  [in]  global_config CAN-FD全局配置，包含波特率和工作模式配置。
 * @param  [in]  std_filter CAN-FD 标准标识符滤波配置。
 * @param  [in]  ex_filter CAN-FD 扩展标识符滤波配置。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_can_init(uint8_t bus, can_global_config_t *global_config, can_filter_list_t *std_filter,
                        can_filter_list_t *ex_filter);

/**
 * @if Eng
 * @brief  Deinitialize CAN-FD.
 * @param  [in]  bus CAN bus line select.
 * @else
 * @brief  去初始化CAN-FD。
 * @param  [in]  bus CAN总线选择。
 * @endif
 */
void uapi_can_deinit(uint8_t bus);

/**
 * @if Eng
 * @brief  CAN-FD request to send frames.
 * @param  [in]  bus CAN bus line select.
 * @param  [in]  can_msg Expected attribute field CAN data frames or remote frames to be transmitted.
 * @param  [in]  data Expected data to be sent.
 * @param  [in]  length Data length.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  CAN-FD 请求发送报文。
 * @param  [in]  bus CAN总线选择。
 * @param  [in]  can_msg 预计发送的CAN数据帧和远程帧的仲裁域。
 * @param  [in]  data 预计发送的数据。
 * @param  [in]  length 数据长度。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_can_send_msg(uint8_t bus, can_msg_attr_t *can_msg, uint8_t *data, uint8_t length);

/**
 * @if Eng
 * @brief  CAN-FD read Rx-FIFO for CAN frames.
 * @param  [in]  bus CAN bus line select.
 * @param  [in]  fifo_index Expected fifo index to be transmitted.
 * @param  [out] receive_msg Arbitration field CAN data frames or remote frames to be received.
 * @param  [out] data Buffer for receiving data.
 * @param  [out] length Received data length.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  CAN-FD 从Rx-FIFO中读取CAN帧。
 * @param  [in]  bus CAN总线选择。
 * @param  [in]  fifo_index 接收fifo的索引。
 * @param  [out] receive_msg 预计接收到的CAN帧仲裁域。
 * @param  [out] data 接受数据的缓冲区。
 * @param  [out] length 接收到的数据真实长度。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_can_receive_msg(uint8_t bus, uint8_t fifo_index,
                               can_msg_attr_t *receive_msg, uint8_t *data, uint32_t *length);

/**
 * @if Eng
 * @brief  Register the callback function for receiving interrupts.
 * @param  [in]  bus CAN bus line select.
 * @param  [in]  can_callback CAN interrupt callback function. @ref can_callback_t
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  接收中断回调函数注册。
 * @param  [in]  bus CAN总线选择。
 * @param  [in]  can_callback CAN中断回调函数。 @ref can_callback_t
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_can_callback_register(uint8_t bus, can_callback_t can_callback);

/**
 * @if Eng
 * @brief  Unregister the callback function for receiving interrupts.
 * @param  [in]  bus CAN bus line select.
 * @retval ERRCODE_SUCC   Success.
 * @retval Other          Failure. For details, see @ref errcode_t.
 * @else
 * @brief  接收中断回调函数解注册。
 * @param  [in]  bus CAN总线选择。
 * @retval ERRCODE_SUCC   成功。
 * @retval Other          失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_can_callback_unregister(uint8_t bus);

/**
 * @if Eng
 * @brief  Query the error status of the CAN controller.
 * @param  [in]  bus CAN bus line select.
 * @retval For details, see @ref can_controller_sts_t.
 * @else
 * @brief  查询CAN控制器错误状态。
 * @param  [in]  bus CAN总线选择。
 * @retval 参考 @ref can_controller_sts_t 。
 * @endif
 */
can_controller_sts_t uapi_can_get_controller_sts(uint8_t bus);

/**
 * @if Eng
 * @brief  Query the Transmit error count of the CAN controller.
 * @param  [in]  bus CAN bus line select.
 * @retval Transmit error count of the CAN controller.
 * @else
 * @brief  查询CAN控制器发送错误计数。
 * @param  [in]  bus CAN总线选择。
 * @retval CAN控制器发送错误计数。
 * @endif
 */
uint8_t uapi_can_get_transmit_error_count(uint8_t bus);

/**
 * @if Eng
 * @brief  Query the Receive error count of the CAN controller.
 * @param  [in]  bus CAN bus line select.
 * @retval Receive error count of the CAN controller.
 * @else
 * @brief  查询CAN控制器接收错误计数。
 * @param  [in]  bus CAN总线选择。
 * @retval CAN控制器接收错误计数。
 * @endif
 */
uint8_t uapi_can_get_receive_error_count(uint8_t bus);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif