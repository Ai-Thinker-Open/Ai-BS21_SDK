/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides flash driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-11-15， Create file. \n
 */
#ifndef FLASH_H
#define FLASH_H

#include <common_def.h>
#include <stdbool.h>
#include <stdint.h>
#include "flash_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_flash FLASH
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Basic information of Flash.
 * @else
 * @brief  Flash 基本信息.
 * @endif
 */
typedef struct flash_info {
    uint32_t flash_id;                      /*!< @if Eng Flash manufacture id.
                                                 @else Flash 制造ID。@endif */
    uint32_t flash_size;                    /*!< @if Eng Flash_size.
                                                 @else Flash 大小。@endif */
    uint32_t flash_unique_id;               /*!< @if Eng Flash unique id.
                                                 @else Flash 唯一id。@endif */
} flash_info_t;

/**
 * @if Eng
 * @brief  Initialise external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  初始化flash。
 * @retval ERRCODE_SUCC 成功。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_init(flash_id_t id);

/**
 * @if Eng
 * @brief  De-Initialise external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  去初始化flash。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_deinit(flash_id_t id);

/**
 * @if Eng
 * @brief  Write data into external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  addr The external flash write address.
 * @param  [in]  src Write data address.
 * @param  [in]  length Write data length.
 * @retval Write data count
 * @else
 * @brief  Flash写入数据
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [in]  addr flash写入地址
 * @param  [in]  src 数据地址
 * @param  [in]  length 数据长度
 * @retval 写入数据长度
 * @endif
 */
uint32_t uapi_flash_write_data(flash_id_t id, uint32_t addr, const uint8_t *src, uint32_t length);

/**
 * @if Eng
 * @brief  Write data into external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  addr The external flash write address.
 * @param  [in]  src Write data address.
 * @param  [in]  length Write data length.
 * @retval Write data count
 * @else
 * @brief  Flash写入数据
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [in]  addr flash写入地址
 * @param  [in]  src 数据地址
 * @param  [in]  length 数据长度
 * @retval 写入数据长度
 * @endif
 */
uint32_t uapi_flash_write_data_without_align(flash_id_t id, uint32_t addr, const uint8_t *src, uint32_t length);

/**
 * @if Eng
 * @brief  Read data from external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t.
 * @param  [in]  addr The external flash read address.
 * @param  [out] dst Read data address.
 * @param  [in]  length Read data length.
 * @retval Read data count.
 * @else
 * @brief  Flash读取数据。
 * @param  [in]  id 指定的flash ID。 参考 @ref flash_id_t 。
 * @param  [in]  addr flash写入地址。
 * @param  [out] dst 数据地址。
 * @param  [in]  length 数据长度。
 * @retval 读取数据长度。
 * @endif
 */
uint32_t uapi_flash_read_data(flash_id_t id, uint32_t addr, uint8_t *dst, uint32_t length);

/**
 * @if Eng
 * @brief  Read data from external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t.
 * @param  [in]  addr The external flash read address.
 * @param  [out] dst Read data address.
 * @param  [in]  length Read data length.
 * @retval Read data count.
 * @else
 * @brief  Flash读取数据。
 * @param  [in]  id 指定的flash ID。 参考 @ref flash_id_t 。
 * @param  [in]  addr flash写入地址。
 * @param  [out] dst 数据地址。
 * @param  [in]  length 数据长度。
 * @retval 读取数据长度。
 * @endif
 */
uint32_t uapi_flash_read_data_without_align(flash_id_t id, uint32_t addr, uint8_t *dst, uint32_t length);

/**
 * @if Eng
 * @brief  Erase external flash all chip.
 * @param  [in]  id The flash ID. see @ref flash_id_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  Flash擦除整片数据。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_chip_erase(flash_id_t id);

/**
 * @if Eng
 * @brief  Erase external flash in block.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  addr The external flash erase address.
 * @param  [in]  length Erase data length.
 * @param  [in]  is_wait Whether to judge the erasure is complete.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash按块擦除数据。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [in]  addr 擦除地址。
 * @param  [in]  length 擦除长度。
 * @param  [in]  is_wait 是否判断擦除完成。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_block_erase(flash_id_t id, uint32_t addr, uint32_t length, bool is_wait);

/**
 * @if Eng
 * @brief  Erase external flash in sector.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  addr The external flash erase address.
 * @param  [in]  is_wait Whether to judge the erasure is complete.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash按扇区擦除数据。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [in]  addr 擦除地址。
 * @param  [in]  is_wait 是否等待擦除完成。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_sector_erase(flash_id_t id, uint32_t addr, bool is_wait);

/**
 * @if Eng
 * @brief  Suspend external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash休眠。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_suspend(flash_id_t id);

/**
 * @if Eng
 * @brief  Resume external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash休眠唤醒。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_resume(flash_id_t id);

/**
 * @if Eng
 * @brief  Switch external flash into power down state.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash进入掉电模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_switch_to_deeppower(flash_id_t id);

/**
 * @if Eng
 * @brief  Resume external flash from power down state.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash掉电模式唤醒。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_resume_from_deeppower(flash_id_t id);

/**
 * @if Eng
 * @brief  Read security reg status of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [out]  read_data The flash security reg status.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  读取flash安全寄存器状态。
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [out]  read_data Flash 安全寄存器状态。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_read_security_status(flash_id_t id, uint8_t *read_data);

/**
 * @if Eng
 * @brief  Send command to external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  cmd_exe The flash ID. see @ref flash_cmd_exe_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  发送flash命令。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [in]  cmd_exe Flash 命令。see @ref flash_cmd_exe_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_send_cmd_exe(flash_id_t id, flash_cmd_exe_t *cmd_exe);

/**
 * @if Eng
 * @brief  Get the current information of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  flash_info The flash information. see @ref flash_info_t
 * @else
 * @brief  获取flash当前信息。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [in]  flash_info flash 当前信息。see @ref flash_info_t
 * @endif
 */
void uapi_flash_get_info(flash_id_t id, flash_info_t *flash_info);

#if defined(CONFIG_FLASH_SUPPORT_XIP) && (CONFIG_FLASH_SUPPORT_XIP == 1)
/**
 * @if Eng
 * @brief  Check if the external flash is supports xip mode or not.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  flash_unique_id Flash unique id.
 * @else
 * @brief  检查Flash是否支持xip模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [in]  flash_unique_id 唯一id。
 * @endif
 */
void uapi_flash_config_cmd_at_xip_mode(flash_id_t id, uint8_t flash_unique_id);

/**
 * @if Eng
 * @brief  Switch external flash into xip mode.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash进入xip模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_switch_to_xip_mode(flash_id_t id);

/**
 * @if Eng
 * @brief  Exit external flash from xip mode.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash退出xip模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_exit_from_xip_mode(flash_id_t id);

/**
 * @if Eng
 * @brief  Switch external flash into xip force bypass mode.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash进入xip旁路模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_switch_to_force_bypass_mode(flash_id_t id);

/**
 * @if Eng
 * @brief  Switch external flash into xip cache mode.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash进入xip缓存模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_switch_to_cache_mode(flash_id_t id);
#endif

/**
 * @if Eng
 * @brief  Switch external flash to qspi mode.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash进入qspi模式。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_switch_to_qspi_init(flash_id_t id);

/**
 * @if Eng
 * @brief  Flash reset.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  Flash复位。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_reset(flash_id_t id);

/**
 * @if Eng
 * @brief  Check if the external flash is in processing or not.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @retval true Success.
 * @retval false not processing.
 * @else
 * @brief  Flash是否正在工作。
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @retval true 正在工作。
 * @retval false 未在工作。
 * @endif
 */
bool uapi_flash_is_processing(flash_id_t id);

/**
 * @if Eng
 * @brief  Read manufacture id of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [out]  manufacture_id The flash manufacture id.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  读取flash制造id。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [out]  manufacture_id Flash 制造id。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_read_id(flash_id_t id, uint32_t *manufacture_id);

/**
 * @if Eng
 * @brief  Read unique id of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [out]  unique_id The flash unique id.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  读取flash唯一id。
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [out]  unique_id Flash 唯一id。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_read_unique_id(flash_id_t id, uint8_t *unique_id);

/**
 * @if Eng
 * @brief  Read device id of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [out]  device_id The flash device id.
 * @retval flash device id.
 * @else
 * @brief  读取flash设备id。
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [out]  device_id Flash 设备id。
 * @retval flash 设备id
 * @endif
 */
errcode_t uapi_flash_read_device_id(flash_id_t id, uint16_t *device_id);

/**
 * @if Eng
 * @brief  Read status of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [out]  status The flash status.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  读取flash状态。
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [out]  status Flash 状态。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_flash_read_status(flash_id_t id, uint8_t *status);

/**
 * @if Eng
 * @brief  Save manufacturer id of external flash.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  manufacture_id The flash manufacture id.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  保存flash制造id。
 * @param  [in]  id 指定的flash ID. 参考 @ref flash_id_t
 * @param  [in]  manufacture_id Flash 制造id。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t flash_save_manufacturer(flash_id_t id, uint32_t manufacture_id);

/**
 * @if Eng
 * @brief  Set the baudrate of SPI.
 * @param  [in]  id The flash ID. see @ref flash_id_t
 * @param  [in]  bus_clk The bus clock.
 * @param  [in]  freq_mhz The frequency of SPI.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  设置spi波特率。
 * @param  [in]  id 指定的flash ID。参考 @ref flash_id_t
 * @param  [in]  bus_clk 总线时钟。
 * @param  [in]  freq_mhz SPI的工作频率。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
void uapi_flash_set_spi_baud(flash_id_t id, uint32_t bus_clk, uint32_t freq_mhz);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
