/**
 * Copyright (c) @CompanyNameMagicTag 2022. All rights reserved. \n
 * Description: nfc hal T2T tag operations \n
 * Author: @CompanyNameTag \n
 * Date: 2022-11-15 \n
 */
/** @defgroup middleware_service_nfc_controller_hal_t2t NFC HAL T2T
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_HAL_T2T_H
#define NFC_HAL_T2T_H

#include "nfc_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Number of bytes that can be read at one time from a T2T card.
 * @else
 * @brief  T2T卡每次读取的字节数。
 * @endif
 */
#define T2T_READ_DATA_LEN   16

/**
 * @if Eng
 * @brief  Number of bytes that can be written at one time to a T2T card.
 * @else
 * @brief  T2T卡每次写入的字节数。
 * @endif
 */
#define T2T_WRITE_DATA_LEN  4

/**
 * @if Eng
 * @brief  T2T Poller send read command and get response.
 * @param  [in]     blockNo  The index number of the block to be read.
 * @param  [out]    readData  Data buffer used to receive data.
 * @param  [in]     dataBuffSize  Data buffer size. It should not be less than @ref T2T_READ_DATA_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T2T轮询设备发送读命令并接收回复。
 * @param  [in]     blockNo  所要读取的块编号。
 * @param  [out]    readData  用于接收数据的存储空间。
 * @param  [in]     dataBuffSize  用于接收数据的存储空间的总大小。该值不应小于 @ref T2T_READ_DATA_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T2TPollerProcRead(uint8_t blockNo, uint8_t *readData, uint16_t dataBuffSize);

/**
 * @if Eng
 * @brief  T2T Poller send write command and get response.
 * @param  [in]     blockNo  The index number of the block to be written.
 * @param  [in]     writeData  Data buffer to write.
 * @param  [in]     dataLen  Data length. It should be equal to @ref T2T_WRITE_DATA_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T2T轮询设备发送写命令并接收回复。
 * @param  [in]     blockNo  所要写入的块编号。
 * @param  [in]     writeData  所要写入的内容。
 * @param  [in]     dataLen  写入内容的大小。该值应等于 @ref T2T_WRITE_DATA_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T2TPollerProcWrite(uint8_t blockNo, const uint8_t *writeData, uint8_t dataLen);

/**
 * @if Eng
 * @brief  T2T Poller send SECTOR_SELECT command and get response.
 * @param  [in]     secNo  The index number of the sector to change to.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T2T轮询设备发送扇区选择命令并接收回复。
 * @param  [in]     secNo  将要变更至的扇区编号.
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T2TPollerProcSelectSector(uint8_t secNo);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */