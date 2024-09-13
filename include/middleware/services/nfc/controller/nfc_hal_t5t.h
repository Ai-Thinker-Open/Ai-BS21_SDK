/**
 * Copyright (c) @CompanyNameMagicTag 2022. All rights reserved. \n
 * Description: nfc hal T5T tag operations \n
 * Author: @CompanyNameTag \n
 * Date: 2022-11-15 \n
 */
/** @defgroup middleware_service_nfc_controller_hal_t5t NFC HAL T5T
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_HAL_T5T_H
#define NFC_HAL_T5T_H

#include <stdbool.h>
#include "nfc_error_code.h"
#include "nfc_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Maximum number of bytes that can be stored in each block of T5T card.
 * @else
 * @brief  T5T卡每个块能存储的最大字节数。
 * @endif
 */
#define T5T_MAX_BLOCK_LEN           32

/**
 * @if Eng
 * @brief  Maximum number of bytes that can be read at one time from a T5T card.
 * @else
 * @brief  T5T卡单次读取的最大字节数。
 * @endif
 */
#define T5T_MAX_READ_LEN            254

/**
 * @if Eng
 * @brief  If the magic number is set to this value, the 1-byte address mode and extended commands are supported.
 * @else
 * @brief  魔法数字为此值时表示支持1字节地址模式及扩展命令。
 * @endif
 */
#define T5T_1BYTE_ADDR_MODE_SUPPORT 0xE1

/**
 * @if Eng
 * @brief  If the magic number is set to this value, the 2-byte address mode and extended commands are supported.
 * @else
 * @brief  魔法数字为此值时表示支持2字节地址模式及扩展命令。
 * @endif
 */
#define T5T_2BYTE_ADDR_MODE_SUPPORT 0xE2

/**
 * @if Eng
 * @brief  NFC HAL T5T request flag structure.
 * @else
 * @brief  NFC硬件抽象层T5T请求命令标志位结构体。
 * @endif
*/
typedef struct {
    /** @if Eng  T5T OPTION FLAG (OF). For read-alike cmd, it indicates whether read security status. \n
     *           For write-alike cmd, it indicates whether use special frame.
     *  @else    T5T OPTION FLAG (OF)标志位。对于读类命令，该标志位决定是否读取安全状态。 \n
     *           对于写类命令，决定是否使用特殊帧格式。
     *  @endif */
    bool isOptionFlag;
    /** @if Eng  Address Mode Selector. It indicates whether commands have UID. \n
     *           For select command & sleep V command, isAms should be true.
     *  @else    地址模式标志。决定命令中是否包含UID。 \n
     *           对于选定和睡眠命令，该标志必须为true。
     *  @endif */
    bool isAms;
    /** @if Eng  Selected Mode Selector. It indicates whether to work in selected mode.
     *  @else    选择模式标志。决定是否工作在选择模式。
     *  @endif */
    bool isSms;
} NfcHalT5TReqFlag;

/**
 * @if Eng
 * @brief  Nfc Hal T5T RW information structure. This structure contains read/write information used for framing. \n
 *         These params should be set valid according to different command type before used.
 * @else
 * @brief  NFC硬件抽象层T5T读写信息结构体。这个结构体包含用于组帧的读写信息。于使用前，对于不同命令，这些信息应当被正确设置。
 * @endif
*/
typedef struct {
    /** @if Eng  NFC HAL T5T request flag structure. For details, see @ref NfcHalT5TReqFlag.
     *  @else    NFC硬件抽象层T5T请求命令标志位结构体。参考 @ref NfcHalT5TReqFlag 。
     *  @endif */
    NfcHalT5TReqFlag reqFlag;
    /** @if Eng  UID array. This is optional based on isAms in @ref NfcHalT5TReqFlag. For length, see @ref UID_LEN.
     *  @else    UID的存储数组。UID是可选的，根据 @ref NfcHalT5TReqFlag 中的isAms来定。长度参考 @ref UID_LEN 。
     *  @endif */
    uint8_t uid[UID_LEN];
    /** @if Eng  Number of bytes stored in each block. For maximum length, see @ref T5T_MAX_BLOCK_LEN.
     *  @else    每个块存储的字节数。最大长度参考 @ref T5T_MAX_BLOCK_LEN 。
     *  @endif */
    uint8_t blockLen;
    /** @if Eng  Block index number of the block to be read/write.
     *  @else    需要读写的块的编号。
     *  @endif */
    uint16_t blockNo;
} NfcHalT5TRWInfo;

/**
 * @if Eng
 * @brief  Nfc Hal T5T read response structure.
 * @else
 * @brief  NFC硬件抽象层T5T读命令所收到回复内容结构体。
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
    /** @if Eng  Status buffer used to receive response status.
     *  @else    用于接收回复的状态信息的存储空间。
     *  @endif */
    uint8_t *status;
    /** @if Eng  Status buffer size.
     *  @else    用于接收回复的状态信息的存储空间的总大小。
     *  @endif */
    uint16_t statusBuffSize;
    /** @if Eng  Received byte length of status. \n
     *           If isOptionFlag in @ref NfcHalT5TReqFlag is set to true, it should be equal to the number of blocks \n
     *           to be read because every block to be read has one byte of status information. \n
     *           If isOptionFlag in @ref NfcHalT5TReqFlag is set to false, it should be 0.
     *  @else    所接收的状态信息大小。 \n
     *           如果 @ref NfcHalT5TReqFlag 中的isOptionFlag 值为true，由于每个要读取的块对应一个字节的状态值，所以该值等于要读取的块数。 \n
     *           如果 @ref NfcHalT5TReqFlag 中的isOptionFlag 值为false，该值为0。
     *  @endif */
    uint16_t statusLen;
} NfcHalT5TReadRes;

/**
 * @if Eng
 * @brief  T5T Poller send read single block command and get response.
 * @param  [in]     rwInfo  Read information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @param  [out]    readRes  T5T read response structure. For details, see @ref NfcHalT5TReadRes.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送读单个块命令并接收回复。
 * @param  [in]     rwInfo  读操作相关的参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @param  [out]    readRes  T5T读命令所收到回复内容结构体。 参考 @ref NfcHalT5TReadRes 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TReadSingleBlock(NfcHalT5TRWInfo *rwInfo, NfcHalT5TReadRes *readRes);

/**
 * @if Eng
 * @brief  T5T Poller send write single block command and get response.
 * @param  [in]     rwInfo  Write information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @param  [in]     buff  Data buffer to write.
 * @param  [in]     buffLen  Data length. It should be equal to block length, see blockLen inside @ref NfcHalT5TRWInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送写单个块命令并接收回复。
 * @param  [in]     rwInfo  写操作的相关参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @param  [in]     buff  所要写的内容。
 * @param  [in]     buffLen  所要写的内容大小。该值应等于单个块存储的字节数，参考 @ref NfcHalT5TRWInfo 中的blockLen。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TWriteSingleBlock(NfcHalT5TRWInfo *rwInfo, const uint8_t *buff, uint16_t buffLen);

/**
 * @if Eng
 * @brief  T5T Poller send lock single block command and get response.
 * @param  [in]     rwInfo  Lock information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送锁定单个块命令并接收回复。
 * @param  [in]     rwInfo  锁定操作相关的参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TLockSingleBlock(NfcHalT5TRWInfo *rwInfo);

/**
 * @if Eng
 * @brief  T5T Poller send read multiple block command and get response.
 * @param  [in]     rwInfo  Read information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @param  [out]    readRes  T5T read response structure. For details, see @ref NfcHalT5TReadRes.
 * @param  [in]     numberOfBlock  Number of additional blocks to read.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送读多个块命令并接收回复。
 * @param  [in]     rwInfo  读操作相关的参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @param  [out]    readRes  T5T读命令所收到回复内容结构体。 参考 @ref NfcHalT5TReadRes 。
 * @param  [in]     numberOfBlock  额外读取的块的数量。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TReadMultBlock(NfcHalT5TRWInfo *rwInfo, NfcHalT5TReadRes *readRes, uint16_t numberOfBlock);

/**
 * @if Eng
 * @brief  T5T Poller send extended read single block command and get response.
 * @param  [in]     rwInfo  Read information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @param  [out]    readRes  T5T read response structure. For details, see @ref NfcHalT5TReadRes.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送扩展读单个块命令并接收回复。
 * @param  [in]     rwInfo  读操作相关的参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @param  [out]    readRes  T5T读命令所收到回复内容结构体。 参考 @ref NfcHalT5TReadRes 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TEXReadSingleBlock(NfcHalT5TRWInfo *rwInfo, NfcHalT5TReadRes *readRes);

/**
 * @if Eng
 * @brief  T5T Poller send extended write single block command and get response.
 * @param  [in]     rwInfo  Write information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @param  [in]     buff  Data buffer to write.
 * @param  [in]     buffLen  Data length. It should be equal to block length, see blockLen inside @ref NfcHalT5TRWInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送扩展写单个块命令并接收回复。
 * @param  [in]     rwInfo  写操作的相关参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @param  [in]     buff  所要写的内容。
 * @param  [in]     buffLen  所要写的内容大小。该值应等于单个块存储的字节数，参考 @ref NfcHalT5TRWInfo 中的blockLen。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TEXWriteSingleBlock(NfcHalT5TRWInfo *rwInfo, const uint8_t *buff, uint16_t buffLen);

/**
 * @if Eng
 * @brief  T5T Poller send extended lock single block command and get response.
 * @param  [in]     rwInfo  Lock information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送扩展锁定单个块命令并接收回复。
 * @param  [in]     rwInfo  锁定操作相关的参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TEXLockSingleBlock(NfcHalT5TRWInfo *rwInfo);

/**
 * @if Eng
 * @brief  T5T Poller send extended read multiple block command and get response.
 * @param  [in]     rwInfo  Read information used for framing. For details, see @ref NfcHalT5TRWInfo.
 * @param  [out]    readRes  T5T read response structure. For details, see @ref NfcHalT5TReadRes.
 * @param  [in]     numberOfBlock  Number of additional blocks to read.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送扩展读多个块命令并接收回复。
 * @param  [in]     rwInfo  读操作相关的参数信息。 参考 @ref NfcHalT5TRWInfo 。
 * @param  [out]    readRes  T5T读命令所收到回复内容结构体。 参考 @ref NfcHalT5TReadRes 。
 * @param  [in]     numberOfBlock  额外读取的块的数量。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TEXReadMultBlock(NfcHalT5TRWInfo *rwInfo, NfcHalT5TReadRes *readRes, uint16_t numberOfBlock);

/**
 * @if Eng
 * @brief  T5T Poller send select command and get response.
 * @param  [in]     rwInfo  Select information used for framing. \n
 *                          The UID inside this structure should be valid. For details, see @ref NfcHalT5TRWInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送选定命令并接收回复。
 * @param  [in]     rwInfo  选定操作的相关参数信息。使用本接口时，需要包含有效的UID。 参考 @ref NfcHalT5TRWInfo 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TSelect(NfcHalT5TRWInfo *rwInfo);

/**
 * @if Eng
 * @brief  T5T Poller send sleep V command and get response.
 * @param  [in]     rwInfo  Sleep V information used for framing. \n
 *                          The UID inside this structure should be valid. For details, see @ref NfcHalT5TRWInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T5T轮询设备发送睡眠命令并接收回复。
 * @param  [in]     rwInfo  睡眠操作的相关参数信息。使用本接口时，需要包含有效的UID。 参考 @ref NfcHalT5TRWInfo 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T5TSlpV(NfcHalT5TRWInfo *rwInfo);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */