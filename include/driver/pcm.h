/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides PCM driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-15， Create file. \n
 */

#ifndef PCM_H
#define PCM_H

#include <stdint.h>
#include <stdbool.h>
#include "errcode.h"
#include "hal_sio.h"
#include "sio_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_pcm PCM
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Definition of PCM RX data structure.
 * @else
 * @brief  PCM RX 传输结构体。
 * @endif
 */
typedef struct pcm_rx_data {
    uint32_t left_buff[DATA_LEN_MAX];           /*!< @if Eng Left data.
                                                     @else   左声道数据。 @endif */
    uint32_t right_buff[DATA_LEN_MAX];          /*!< @if Eng Right data.
                                                     @else   右声道数据。 @endif */
    uint32_t length;                            /*!< @if Eng Data length.
                                                     @else   数据长度。 @endif */
} pcm_rx_data_t;

/**
 * @if Eng
 * @brief  Definition of PCM TX data structure.
 * @else
 * @brief  PCM TX 传输结构体。
 * @endif
 */
typedef struct pcm_tx_data {
    uint32_t *left_data;                        /*!< @if Eng Data send through tx left fifo.
                                                     @else   通过tx 左fifo发送的数据。 @endif */
    uint32_t *right_data;                       /*!< @if Eng Data send through tx right fifo.
                                                     @else   通过tx 右fifo发送的数据。 @endif */
    uint32_t length;                            /*!< @if Eng Bytes of data need to send
                                                     @else   发送数据的个数 @endif */
} pcm_tx_data_t;

/**
 * @if Eng
 * @brief  Definition of PCM attributes.
 * @else
 * @brief  PCM 配置参数定义。
 * @endif
 */
typedef struct pcm_config {
    uint8_t drive_mode;                         /*!< @if Eng SIO divice modes.
                                                 *           - 0: SLAVE
                                                 *           - 1: MASTER
                                                 *   @else   SIO 设备模式。
                                                 *           - 0: 从模式
                                                 *           - 1: 主模式
                                                 *   @endif */
    uint8_t transfer_mode;                      /*!< @if Eng SIO transmission path modes.
                                                 *           - 0: Standard mode
                                                 *           - 1: Multichannel mode
                                                 *   @else   SIO SIO 传输路径模式。
                                                 *           - 0: 标准模式。
                                                 *           - 1: 多路模式。
                                                 *   @endif */
    uint8_t data_width;                         /*!< @if Eng SIO data width.
                                                 *           - 0: RESERVED
                                                 *           - 1: SIXTEEN_BIT
                                                 *           - 2: EIGHTEEN_BIT
                                                 *           - 3: TWENTY_BIT
                                                 *           - 4: TWENTY_FOUR_BIT
                                                 *           - 5: THIRTY_TWO_BIT
                                                 *   @else   SIO 数据宽度。
                                                 *           - 0: 保留
                                                 *           - 1: 16位
                                                 *           - 2: 18位
                                                 *           - 3: 20位
                                                 *           - 4: 24位
                                                 *           - 5: 32位
                                                 *   @endif */
    uint8_t channels_num;                        /*!< @if Eng SIO transmission Channels Number.
                                                 *           - 0: Two channel
                                                 *           - 1: Four channel
                                                 *           - 2: Eight channel
                                                 *           - 3: Sixteen channel
                                                 *   @else   SIO 传输通道数。
                                                 *           - 0: 2通道
                                                 *           - 1: 4通道
                                                 *           - 2: 8通道
                                                 *           - 3: 16通道
                                                 *   @endif */
    uint8_t timing;                             /*!< @if Eng SIO timing mode.
                                                 *           - 0: Standard timing mode
                                                 *           - 1: User-defined timing mode.
                                                 *   @else   SIO 时序模式
                                                 *           - 0: 标准时序模式。
                                                 *           - 1: 自定义时序模式。
                                                 *   @endif */
    uint8_t clk_edge;                           /*!< @if Eng SIO clock edge mode.
                                                 *           - 0: Falling edge
                                                 *           - 1: Rising edge
                                                 *   @else   SIO 时钟边沿模式。
                                                 *           - 0: 下降沿。
                                                 *           - 1: 上升沿。
                                                 *   @endif */
    uint8_t div_number;                         /*!< @if Eng Div number, see @ref pcm_config.data_width.
                                                     @else   分频系数，参考 @ref pcm_config.data_width 。 @endif */
    uint8_t number_of_channels;                 /*!< @if Eng Number of channels, see @ref pcm_config.channels_num.
                                                     @else   通道数，参考 @ref pcm_config.channels_num 。 @endif */
} pcm_config_t;

/**
 * @if Eng
 * @brief  Definition of PCM callback type.
 * @else
 * @brief  PCM 回调函数。
 * @endif
 */
typedef void (*pcm_callback_t)(uint32_t *left_buff, uint32_t *right_buff, uint32_t length);

/**
 * @if Eng
 * @brief  Initialize the PCM.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @param  [in]  callback PCM callback.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  初始化PCM。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @param  [in]  callback PCM回调函数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_init(sio_bus_t bus, pcm_callback_t callback);

/**
 * @if Eng
 * @brief  Deinitialize the PCM.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去初始化PCM。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_deinit(sio_bus_t bus);

/**
 * @if Eng
 * @brief  Configured PCM Device.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @param  [in]  config Configuration of the PCM device.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  配置PCM设备。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @param  [in]  config PCM设备的配置信息。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_set_config(sio_bus_t bus, const pcm_config_t *config);

/**
 * @if Eng
 * @brief  Get the configuration of PCM Device.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @param  [in]  config Configuration of the PCM device.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  获取PCM设备的配置信息。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @param  [in]  config PCM设备的配置信息。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_get_config(sio_bus_t bus, pcm_config_t *config);

/**
 * @if Eng
 * @brief  Write data to the PCM device.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @param  [in]  data Pointer to transfer data. @ref pcm_tx_data_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  写入数据到PCM设备。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @param  [in]  data 数据传输指针，参考 @ref pcm_tx_data_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_write_data(sio_bus_t bus, pcm_tx_data_t *data);

/**
 * @if Eng
 * @brief  Start to read data from the PCM device.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  开始从PCM设备中读取数据。
 * @param  [in]  bus 指定的SIO接口。参考 @ref sio_bus_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pcm_read_start(sio_bus_t bus);

#if defined(CONFIG_PCM_SUPPORT_LOOPBACK) && (CONFIG_PCM_SUPPORT_LOOPBACK == 1)
/**
 * @if Eng
 * @brief  Open loop mode of the PCM.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @param  [in]  en Enable loop back mode or not.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  打开自测模式。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @param  [in]  en 是否开启回环模式。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_loopback(sio_bus_t bus, bool en);
#endif  /* CONFIG_PCM_SUPPORT_LOOPBACK */

/**
 * @if Eng
 * @brief  Get the PCM received data.
 * @param  [in]  bus The SIO bus. For details, see @ref sio_bus_t.
 * @param  [in]  data Pointer to received data, see @ref pcm_rx_data_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  获取PCM接收数据。
 * @param  [in]  bus 指定的SIO接口，参考 @ref sio_bus_t 。
 * @param  [in]  data 接收数据指针，参考 @ref pcm_rx_data_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pcm_get_data(sio_bus_t bus, pcm_rx_data_t *data);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
