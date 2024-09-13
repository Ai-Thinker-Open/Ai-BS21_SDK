/**
 * Copyright (c) @CompanyNameMagicTag 2022. All rights reserved. \n
 * Description: nfc hal T3T tag operations \n
 * Author: @CompanyNameTag \n
 * Date: 2022-11-15 \n
 */
/** @defgroup middleware_service_nfc_controller_hal_t3t NFC HAL T3T
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_HAL_T3T_H
#define NFC_HAL_T3T_H

#include "nfc_error_code.h"
#include "nfc_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Maximum number of services that is supported in a T3T command or response.
 * @else
 * @brief  一个T3T命令或响应支持的最大服务数量。
 * @endif
 */
#define T3T_SERVICES_MAX_NUM         12

/**
 * @if Eng
 * @brief  Maximum number of blocks that is read and written in a T3T command or response.
 * @else
 * @brief  一个T3T命令或响应支持的最大读写块数量。
 * @endif
 */
#define T3T_BLOCKS_MAX_NUM           13

/**
 * @if Eng
 * @brief  The byte length of a single T3T block.
 * @else
 * @brief  T3T单个块字节大小。
 * @endif
 */
#define T3T_BLOCK_SIZE               16

/**
 * @if Eng
 * @brief  Maximum number of bytes in service code list in a T3T command or response.
 * @else
 * @brief  一个T3T命令或响应中服务码列表的最大字节长度。
 * @endif
 */
#define T3T_SERVICE_CODE_LIST_MAX_SIZE       (T3T_SERVICES_MAX_NUM * 2)

/**
 * @if Eng
 * @brief  Maximum number of bytes in block list in a T3T command or response.
 * @else
 * @brief  一个T3T命令或响应中块列表的最大字节长度。
 * @endif
 */
#define T3T_BLOCK_LIST_MAX_SIZE             (T3T_BLOCKS_MAX_NUM * 3)

/**
 * @if Eng
 * @brief  Maximum number of bytes in blocks that are read and written in a T3T command or response.
 * @else
 * @brief  一个T3T命令或响应中支持读写的多个块的合计最长字节数。
 * @endif
 */
#define T3T_BLOCK_BUFF_MAX_LEN       (T3T_BLOCKS_MAX_NUM * T3T_BLOCK_SIZE)

/**
 * @if Eng
 * @brief  NFC HAL T3T update and check command parameters structure.
 * @else
 * @brief  NFC硬件抽象层T3T更新以及查询命令参数结构体。
 * @endif
*/
typedef struct NfcHalT3tCmdParamsStruct {
    /** @if Eng  NFCID2 data buffer. For length, see @ref NFCID2_LEN.
     *  @else    NFCID2的存储空间。长度参考 @ref NFCID2_LEN 。
     *  @endif */
    uint8_t nfcid2[NFCID2_LEN];
    /** @if Eng  The number of services in a T3T command.
     *  @else    一个T3T命令中服务的数量。
     *  @endif */
    uint8_t numberOfServices;
    /** @if Eng  Services code list buffer. For length, see @ref T3T_SERVICE_CODE_LIST_MAX_SIZE.
     *  @else    服务码列表的存储空间。长度参考 @ref T3T_SERVICE_CODE_LIST_MAX_SIZE 。
     *  @endif */
    uint8_t serviceCodeList[T3T_SERVICE_CODE_LIST_MAX_SIZE];
    /** @if Eng  The number of blocks that will be read or written in a T3T command.
     *  @else    一个T3T命令中读或写的块数量。
     *  @endif */
    uint8_t numberOfBlock;
    /** @if Eng  Block list buffer. For length, see @ref T3T_BLOCK_LIST_MAX_SIZE.
     *  @else    块列表的存储空间。长度参考 @ref T3T_BLOCK_LIST_MAX_SIZE 。
     *  @endif */
    uint8_t blockList[T3T_BLOCK_LIST_MAX_SIZE];
    /** @if Eng  The used byte length of block list buffer.
     *  @else    被使用的块列表的字节长度。
     *  @endif */
    uint8_t blockListLen;
} NfcHalT3tCmdParams;

/**
 * @if Eng
 * @brief  NFC HAL T3T parameters structure of check response.
 * @else
 * @brief  NFC硬件抽象层T3T查询命令的响应参数结构体。
 * @endif
*/
typedef struct NfcHalT3tCheckRspParamsStruct {
    /** @if Eng  NFCID2 data buffer. For length, see @ref NFCID2_LEN.
     *  @else    NFCID2的存储空间。长度参考 @ref NFCID2_LEN 。
     *  @endif */
    uint8_t nfcid2[NFCID2_LEN];
    /** @if Eng  The value of Flag 1 in CHECK response.
     *  @else    查询命令响应中第一个标记的值。
     *  @endif */
    uint8_t flag1;
    /** @if Eng  The value of Flag 2 in CHECK response.
     *  @else    查询命令响应中第二个标记的值。
     *  @endif */
    uint8_t flag2;
    /** @if Eng  The number of blocks in CHECK response.
     *  @else    查询命令响应中块的数量。
     *  @endif */
    uint8_t numberOfBlock;
    /** @if Eng  Blocks data buffer in CHECK response. For length, see @ref T3T_BLOCK_BUFF_MAX_LEN.
     *  @else    查询命令响应中的块数据存储空间。长度参考 @ref T3T_BLOCK_BUFF_MAX_LEN 。
     *  @endif */
    uint8_t blockData[T3T_BLOCK_BUFF_MAX_LEN];
} NfcHalT3tCheckRspParams;

/**
 * @if Eng
 * @brief  NFC HAL T3T parameters structure of update response.
 * @else
 * @brief  NFC硬件抽象层T3T更新命令的响应参数结构体。
 * @endif
*/
typedef struct NfcHalT3tUpdateRspParamsStruct {
    /** @if Eng  NFCID2 data buffer. For length, see @ref NFCID2_LEN.
     *  @else    NFCID2的存储空间。长度参考 @ref NFCID2_LEN 。
     *  @endif */
    uint8_t nfcid2[NFCID2_LEN];
    /** @if Eng  The value of Flag 1 in UPDATE response.
     *  @else    更新命令响应中第一个标记的值。
     *  @endif */
    uint8_t flag1;
    /** @if Eng  The value of Flag 2 in UPDATE response.
     *  @else    更新命令响应中第二个标记的值。
     *  @endif */
    uint8_t flag2;
} NfcHalT3tUpdateRspParams;

/**
 * @if Eng
 * @brief  T3T poller send CHECK command and receive response.
 * @param  [in]     cmdParams  The structure storing T3T CHECK command parameters. \n
 *                             For details, see @ref NfcHalT3tCmdParams.
 * @param  [out]    rspParams  The structure storing T3T response parameters of CHECK command. \n
 *                             For details, see @ref NfcHalT3tCheckRspParams.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T3T轮询设备发送查询命令并接收响应。
 * @param  [in]     cmdParams  查询命令所需参数结构体。 详情参考 @ref NfcHalT3tCmdParams 。
 * @param  [out]    rspParams  查询命令的响应参数结构体。 详情参考 @ref NfcHalT3tCheckRspParams 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T3TPollCheckCmd(NfcHalT3tCmdParams *cmdParams, NfcHalT3tCheckRspParams *rspParams);

/**
 * @if Eng
 * @brief  T3T poller send UPDATE command and receive response.
 * @param  [in]     cmdParams  The structure storing T3T UPDATE command parameters. \n
 *                             For details, see @ref NfcHalT3tCmdParams.
 * @param  [out]    rspParams  The structure storing T3T response parameters of UPDATE command. \n
 *                             For details, see @ref NfcHalT3tUpdateRspParams.
 * @param  [in]     writeData  Data buffer to write.
 * @param  [in]     writeDataLen  The byte length of data buffer.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T3T轮询设备发送更新命令并接收响应。
 * @param  [in]     cmdParams  更新命令所需参数结构体。 详情参考 @ref NfcHalT3tCmdParams 。
 * @param  [out]    rspParams  更新命令的响应参数结构体。 详情参考 @ref NfcHalT3tCheckRspParams 。
 * @param  [in]     writeData  要写入的内容。
 * @param  [in]     writeDataLen  要写入的长度。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_HAL_T3TPollUpdateCmd(NfcHalT3tCmdParams *cmdParams, NfcHalT3tUpdateRspParams *rspParams,
                                      const uint8_t *writeData, uint8_t writeDataLen);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */
