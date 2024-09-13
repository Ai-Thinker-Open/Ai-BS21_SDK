/**
 * Copyright (c) @CompanyNameMagicTag 2022. All rights reserved. \n
 * Description: nfc hal T1T tag operations \n
 * Author: @CompanyNameTag \n
 * Date: 2022-11-11 \n
 */
/** @defgroup middleware_service_nfc_controller_hal_t1t NFC HAL T1T
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_HAL_T1T_H
#define NFC_HAL_T1T_H

#include "nfc_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  The UID-echo frame length (4 lower bytes of UID) for T1T Tag.
 * @else
 * @brief  T1T卡片命令中携带的UID-echo部分的长度，是取UID的4个低字节。
 * @endif
 */
#define T1T_UID_ECHO_LEN                4

/**
 * @if Eng
 * @brief  The data length of T1T RID response.
 * @else
 * @brief  T1T读标志信息操作的回复的数据长度。
 * @endif
 */
#define T1T_RID_RES_LEN                 6

/**
 * @if Eng
 * @brief  The data length of T1T RALL response.
 * @else
 * @brief  T1T读所有静态存储空间内容的操作的回复的数据长度。
 * @endif
 */
#define T1T_RALL_RES_LEN                122

/**
 * @if Eng
 * @brief  The data length of T1T Read-Segment response.
 * @else
 * @brief  T1T读数据段操作回复的数据长度。
 * @endif
 */
#define T1T_RSEG_RES_DATA_LEN           128

/**
 * @if Eng
 * @brief  The data length of T1T Read 8 bytes response.
 * @else
 * @brief  T1T读8字节操作的回复的数据长度。
 * @endif
 */
#define T1T_READ8_RES_DATA_LEN          8

/**
 * @if Eng
 * @brief  The data byte length in T1T Write-Erase 8 bytes command.
 * @else
 * @brief  T1T带擦除的写8字节的命令里携带的数据长度。
 * @endif
 */
#define T1T_WRITE_E8_DATA_LEN           8

/**
 * @if Eng
 * @brief  The data byte length in T1T Write-No-Erase 8 bytes command.
 * @else
 * @brief  T1T不带擦除的写8字节的命令里携带的数据长度。
 * @endif
 */
#define T1T_WRITE_NE8_DATA_LEN          8

/**
 * @if Eng
 * @brief  Make address byte with block and byte index for T1T static memory.
 * @else
 * @brief  对于T1T静态存储空间，根据块号和块内字节序号，生成地址字节。
 * @endif
 */
#define MAKE_ADD(blk, byte)             ((((blk) & 0x0F) << 3) | ((byte) & 0x07))

/**
 * @if Eng
 * @brief  Make address byte with segment index for T1T dynamic memory.
 * @else
 * @brief  对于T1T动态存储空间，根据段序号，生成地址字节。
 * @endif
 */
#define MAKE_ADDS(seg)                  (((seg) & 0x0F) << 4)

/**
 * @if Eng
 * @brief  Make address byte with block index for T1T dynamic memory.
 * @else
 * @brief  对于T1T动态存储空间，根据块序号，生成地址字节。
 * @endif
 */
#define MAKE_ADD8(blk)                  (blk)

/**
 * @if Eng
 * @brief  T1T RID response structure.
 * @else
 * @brief  T1T RID命令的响应回复数据结构体。
 * @endif
 */
typedef struct {
    /** @if Eng  T1T header ROM byte 0.
     *  @else    T1T存储空间头部的字节0。
     *  @endif */
    uint8_t hr0;
    /** @if Eng  T1T header ROM byte 1.
     *  @else    T1T存储空间头部的字节1。
     *  @endif */
    uint8_t hr1;
    /** @if Eng  T1T UID-echo 4 bytes array.
     *  @else    T1T UID低四字节。
     *  @endif */
    uint8_t uid[T1T_UID_ECHO_LEN];
} NfcHalT1TRidRes;

/**
 * @if Eng
 * @brief  Send T1T RID command and get response.
 * @param  [out]    res  RID response information structure. For details, see @ref NfcHalT1TRidRes.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T读标记信息命令，并返回响应结果信息。
 * @param  [out]    res  读到的标记信息结构体。参考 @ref NfcHalT1TRidRes 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcRid(NfcHalT1TRidRes *res);

/**
 * @if Eng
 * @brief  Send T1T RALL command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [out]    rxBuff  Receive buffer for response data.
 * @param  [in]     buffSize  Receive buffer size. For mininum size, see @ref T1T_RALL_RES_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T读所有静态存储内容的命令，并返回响应结果的数据信息。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [out]    rxBuff  接收存储空间。
 * @param  [in]     buffSize  接收存储空间的大小。最小长度参考 @ref T1T_RALL_RES_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcRall(const uint8_t *uid, uint8_t *rxBuff, uint16_t buffSize);

/**
 * @if Eng
 * @brief  Send T1T READ command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addr  READ command address. For details, see @ref MAKE_ADD.
 * @param  [out]    data  The data address to store read back one byte value.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T读单一字节的命令，并返回响应结果的数据信息。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addr  读单一字节命令的地址。参考 @ref MAKE_ADD 。
 * @param  [out]    data  读取到的单一字节的存放地址。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcRead(const uint8_t *uid, uint8_t addr, uint8_t *data);

/**
 * @if Eng
 * @brief  Send T1T Write-Erase command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addr  Write-Erase command address. For details, see @ref MAKE_ADD.
 * @param  [in]     data  The data byte to write.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T带擦除的写单一字节的命令，并返回响应结果。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addr  写单一字节命令的地址。参考 @ref MAKE_ADD 。
 * @param  [in]     data  需要写入的单一字节的内容。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcWriteE(const uint8_t *uid, uint8_t addr, uint8_t data);

/**
 * @if Eng
 * @brief  Send T1T Write-No-Erase command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addr  Write-No-Erase command address. For details, see @ref MAKE_ADD.
 * @param  [in]     data  The data byte to write.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T不带擦除的写单一字节的命令，并返回响应结果。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addr  写单一字节命令的地址。参考 @ref MAKE_ADD 。
 * @param  [in]     data  需要写入的单一字节的内容。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcWriteNE(const uint8_t *uid, uint8_t addr, uint8_t data);

/**
 * @if Eng
 * @brief  Send T1T RSEG command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addrS  Read segment command address. For details, see @ref MAKE_ADDS.
 * @param  [out]    rxBuff  The buffer to store received segment data.
 * @param  [in]     buffSize  The buffer size. For minimum length, see @ref T1T_RSEG_RES_DATA_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T读数据段的命令，并返回响应结果的数据信息。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addrS  读数据段的命令的地址。参考 @ref MAKE_ADDS 。
 * @param  [out]    rxBuff  用来存储接收到的数据段的空间。
 * @param  [in]     buffSize  存储空间大小。最小长度参考 @ref T1T_RSEG_RES_DATA_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcRseg(const uint8_t *uid, uint8_t addrS, uint8_t *rxBuff, uint16_t buffSize);

/**
 * @if Eng
 * @brief  Send T1T READ8 command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addr8  Read 8-byte command address. For details, see @ref MAKE_ADD8.
 * @param  [out]    rxBuff  The buffer to store received 8 bytes data.
 * @param  [in]     buffSize  The buffer size. For minimum length, see @ref T1T_READ8_RES_DATA_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T读8字节数据的命令，并返回响应结果的数据信息。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addr8  读8字节数据的命令的地址。参考 @ref MAKE_ADD8 。
 * @param  [out]    rxBuff  用来存储接收到的8字节数据的空间。
 * @param  [in]     buffSize  存储空间大小。最小长度参考 @ref T1T_READ8_RES_DATA_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcRead8(const uint8_t *uid, uint8_t addr8, uint8_t *rxBuff, uint16_t buffSize);

/**
 * @if Eng
 * @brief  Send T1T WRITE-E8 command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addr8  Write-Erase 8-byte command address. For details, see @ref MAKE_ADD8.
 * @param  [in]     buff  The 8 bytes data buffer to write.
 * @param  [in]     buffLen  The data buffer length. For correct length, see @ref T1T_WRITE_E8_DATA_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T带擦除的写8字节数据的命令，并返回响应结果。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addr8  写8字节数据的命令的地址。参考 @ref MAKE_ADD8 。
 * @param  [in]     buff  准备写入的8字节数据。
 * @param  [in]     buffLen  数据长度。正确数据长度参考 @ref T1T_WRITE_E8_DATA_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcWriteE8(const uint8_t *uid, uint8_t addr8, const uint8_t *buff, uint16_t buffLen);

/**
 * @if Eng
 * @brief  Send T1T WRITE-NE8 command and get response.
 * @param  [in]     uid  UID-echo, 4 lower bytes of T1T UID.
 * @param  [in]     addr8  Write-No-Erase 8-byte command address.  For details, see @ref MAKE_ADD8.
 * @param  [in]     buff  The 8 bytes data buffer to write.
 * @param  [in]     buffLen  The data buffer length. For correct length, see @ref T1T_WRITE_NE8_DATA_LEN.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  发送T1T不带擦除的写8字节数据的命令，并返回响应结果。
 * @param  [in]     uid  T1T UID低4字节。
 * @param  [in]     addr8  写8字节数据的命令的地址。参考 @ref MAKE_ADD8 。
 * @param  [in]     buff  准备写入的8字节数据。
 * @param  [in]     buffLen  数据长度。正确数据长度参考 @ref T1T_WRITE_NE8_DATA_LEN 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T1TPollerProcWriteNE8(const uint8_t *uid, uint8_t addr8, const uint8_t *buff, uint16_t buffLen);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */