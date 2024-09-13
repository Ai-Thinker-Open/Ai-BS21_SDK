/**
 * Copyright (c) @CompanyNameMagicTag 2023. All rights reserved. \n
 * Description: NFC NDEF main process \n
 * Author: @CompanyNameTag \n
 * Date: 2023-03-22 \n
 */
/** @defgroup middleware_service_nfc_controller_ndef NFC NDEF Process
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_NDEF_H
#define NFC_NDEF_H

#include "nfc_hal_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  TAG NDEF reset process, which is used to reset the status of the TAG NDEF module.
 * @param  [in]     nfcIntfActInfo  NFC interface activation information structure. \n
 *                                  For details, see @ref NfcIntfActInfo.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  TAG NDEF重置流程，用于TAG NDEF模块状态重置。
 * @param  [in]     nfcIntfActInfo  NFC接口激活信息结构体。 参考 @ref NfcIntfActInfo 。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_NDEF_ResetProc(const NfcIntfActInfo *nfcIntfActInfo);

/**
 * @if Eng
 * @brief  TAG NDEF read process.
 * @param  [out]    ndefBuff  Data buffer used to receive data.
 * @param  [in,out] ndefLen  As input param, it indicates data buffer size. \n
 *                           As output param, it indicates the length of received NDEF data.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  TAG NDEF读流程。
 * @param  [out]    ndefBuff  用于接收数据的存储空间。
 * @param  [in,out] ndefLen  作为输入参数，代表存储空间的大小。 \n
 *                           作为输出参数，代表所读NDEF内容的大小。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_NDEF_ReadProc(uint8_t *ndefBuff, uint16_t *ndefLen);

/**
 * @if Eng
 * @brief  TAG NDEF write process.
 * @param  [in]     ndefBuff  Data buffer to write.
 * @param  [in]     ndefLen  Data length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  TAG NDEF写流程。
 * @param  [in]     ndefBuff  所要写入的内容。
 * @param  [in]     ndefLen  写入内容的大小。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_NDEF_WriteProc(const uint8_t *ndefBuff, uint16_t ndefLen);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */