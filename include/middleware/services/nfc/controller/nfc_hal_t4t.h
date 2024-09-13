/**
 * Copyright (c) @CompanyNameMagicTag 2022. All rights reserved. \n
 * Description: nfc hal T4T tag operations \n
 * Author: @CompanyNameTag \n
 * Date: 2022-11-15 \n
 */
/** @defgroup middleware_service_nfc_controller_hal_t4t NFC HAL T4T
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_HAL_T4T_H
#define NFC_HAL_T4T_H

#include <stdbool.h>
#include "nfc_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Maximum number of bytes that can be read/written at one time from/to a T4T card.
 * @else
 * @brief  T4T卡片单次读写支持的最大字节数。
 * @endif
 */
#define T4T_DATA_MAX_LEN            240

/**
 * @if Eng
 * @brief  Maximum offset in bytes from the beginning of the NDEF File.
 * @else
 * @brief  相对于NDEF文件开头的最大偏移量。
 * @endif
 */
#define T4T_MAX_OFFEST              0x7FFF

/**
 * @if Eng
 * @brief  File identifier of Capability Container (CC) file.
 * @else
 * @brief  功能容器（CC）文件的文件标识符。
 * @endif
 */
#define T4T_CC_FILE_ID              0xE103

/**
 * @if Eng
 * @brief  Command execution completion status word 1.
 * @else
 * @brief  命令执行完成状态字1。
 * @endif
 */
#define CMD_COMPLETE_SW1            0x90

/**
 * @if Eng
 * @brief  Command execution completion status word 2.
 * @else
 * @brief  命令执行完成状态字2。
 * @endif
 */
#define CMD_COMPLETE_SW2            0x00

/**
 * @if Eng
 * @brief  Minimum Capability Container (CC) file length of T4T card.
 * @else
 * @brief  T4T 功能容器（CC）文件最小大小。
 * @endif
 */
#define T4T_MIN_CC_LEN              0x0F

/**
 * @if Eng
 * @brief  Supported T4T card memory mapping version.
 * @else
 * @brief  支持的T4T卡的内存空间映射版本。
 * @endif
 */
#define T4T_MAP_VER                 0x20

/**
 * @if Eng
 * @brief  Type id of NDEF file control TLV.
 * @else
 * @brief  NDEF文件控制TLV的类型id值。
 * @endif
 */
#define T4T_NDEF_FILE_CTRL_TLV      0x04

/**
 * @if Eng
 * @brief  Nfc Hal T4T response APDU structure.
 * @else
 * @brief  NFC硬件抽象层T4T 回复APDU内容结构体。
 * @endif
*/
typedef struct {
    /** @if Eng  Data buffer used to receive data.
     *  @else    用于接收数据的存储空间。
     *  @endif */
    uint8_t *data;
    /** @if Eng  Data buffer size.
     *  @else    用于接收数据的存储空间的总大小。
     *  @endif */
    uint16_t dataBuffSize;
    /** @if Eng  Length of received data.
     *  @else    所接收的数据大小。
     *  @endif */
    uint16_t dataLen;
    /** @if Eng  Status word 1.
     *  @else    状态字1。
     *  @endif */
    uint8_t sw1;
    /** @if Eng  Status word 2.
     *  @else    状态字2。
     *  @endif */
    uint8_t sw2;
} NfcHalT4tRApdu;

/**
 * @if Eng
 * @brief  Check status words in response to see if command execution result is successful.
 * @param  [in]     sw1  Status word byte 1.
 * @param  [in]     sw2  Status word byte 2.
 * @retval true     T4T status word is a success.
 * @retval false    T4T status word is a failure.
 * @else
 * @brief  通过检查返回的状态字，确认命令是否执行成功。
 * @param  [in]     sw1  状态字的第一个字节。
 * @param  [in]     sw2  状态字的第二个字节。
 * @retval true     T4T状态字是成功。
 * @retval false    T4T状态字是失败。
 * @endif
 */
static inline bool NFC_HAL_IsT4TSwSucc(uint8_t sw1, uint8_t sw2)
{
    return ((sw1 == CMD_COMPLETE_SW1) && (sw2 == CMD_COMPLETE_SW2));
}

/**
 * @if Eng
 * @brief  T4T Poller send select NDEF tag application by AID command and get response.
 * @param  [in,out] rApduInfo  T4T response APDU structure. For details, see @ref NfcHalT4tRApdu.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T4T轮询设备发送根据AID选择NDEF应用命令并接收回复。
 * @param  [in,out] rApduInfo  T4T 回复APDU内容结构体。 参考 @ref NfcHalT4tRApdu 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T4TPollerSelectAid(NfcHalT4tRApdu *rApduInfo);

/**
 * @if Eng
 * @brief  T4T Poller send select file by FID command and get response.
 * @param  [in]     fid  File id.
 * @param  [in,out] rApduInfo  T4T response APDU structure. For details, see @ref NfcHalT4tRApdu.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T4T轮询设备发送根据FID选择文件命令并接收回复。
 * @param  [in]     fid  文件标识符。
 * @param  [in,out] rApduInfo  T4T 回复APDU内容结构体。 参考 @ref NfcHalT4tRApdu 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T4TPollerSelectFile(uint16_t fid, NfcHalT4tRApdu *rApduInfo);

/**
 * @if Eng
 * @brief  T4T Poller send READ_BINARY command and get response.
 * @param  [in]     offset  The address offset in bytes from the beginning of the NDEF File to start reading.
 * @param  [in]     expRspLen  Expected response length. \n
 *                  It indicates the maximum length of the data field in the response APDU. \n
 *                  It should not be greater than dataBuffSize in @ref NfcHalT4tRApdu and @ref T4T_DATA_MAX_LEN.
 * @param  [in,out] rApduInfo  T4T response APDU structure. For details, see @ref NfcHalT4tRApdu.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T4T轮询设备发送读数据命令并接收回复。
 * @param  [in]     offset  相较于NDEF文件开头，读取位置的地址偏移量。
 * @param  [in]     expRspLen  期望接收回复的大小。 \n
 *                  该值表示回复APDU中数据域的最大长度。 \n
 *                  该值不应大于 @ref NfcHalT4tRApdu 中的dataBuffSize，以及 @ref T4T_DATA_MAX_LEN 。
 * @param  [in,out] rApduInfo  T4T 回复APDU内容结构体。 参考 @ref NfcHalT4tRApdu 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T4TPollerReadData(uint16_t offset, uint8_t expRspLen, NfcHalT4tRApdu *rApduInfo);

/**
 * @if Eng
 * @brief  T4T Poller send UPDATE_BINARY command and get response.
 * @param  [in]     offset  The address offset in bytes from the beginning of the NDEF File to start writing.
 * @param  [in]     data  Data buffer to write.
 * @param  [in]     dataLen  Data length. For maximum length, see @ref T4T_DATA_MAX_LEN.
 * @param  [in,out] rApduInfo  T4T response APDU structure. For details, see @ref NfcHalT4tRApdu.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T4T轮询设备发送写数据命令并接收回复。
 * @param  [in]     offset  相较于从NDEF文件开头，写入位置的地址偏移量。
 * @param  [in]     data  所要写入的内容。
 * @param  [in]     dataLen  写入内容的大小。最大值参考 @ref T4T_DATA_MAX_LEN 。
 * @param  [in,out] rApduInfo  T4T 回复APDU内容结构体。 参考 @ref NfcHalT4tRApdu 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T4TPollerWriteData(uint16_t offset, const uint8_t *data, uint8_t dataLen,
                                        NfcHalT4tRApdu *rApduInfo);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */

