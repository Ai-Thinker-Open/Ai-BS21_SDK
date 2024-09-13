/**
 * Copyright (c) @CompanyNameMagicTag 2023. All rights reserved. \n
 * Description: NFC NDEF process for T4T \n
 * Author: @CompanyNameTag \n
 * Date: 2023-03-22 \n
 */
/** @defgroup middleware_service_nfc_controller_ndef_t4t NFC NDEF T4T
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_NDEF_T4T_H
#define NFC_NDEF_T4T_H

#include "nfc_hal_core.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  T4T NDEF reset process, which is used to reset the status of the T4T NDEF module.
 * @else
 * @brief  T4T NDEF 重置流程，用于T4T NDEF模块状态重置。
 * @endif
 */
void NFC_NDEF_T4TResetProc(void);

/**
 * @if Eng
 * @brief  T4T NDEF read process.
 * @param  [out]    readBuff  Data buffer used to receive data.
 * @param  [in,out] readLen  As input param, it indicates data buffer size. \n
 *                           As output param, it indicates the length of received NDEF data.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T4T NDEF读流程。
 * @param  [out]    readBuff  用于接收数据的存储空间。
 * @param  [in,out] readLen  作为输入参数，代表存储空间的大小。 \n
 *                           作为输出参数，代表所读NDEF内容的大小。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_NDEF_T4TReadProc(uint8_t *readBuff, uint16_t *readLen);

/**
 * @if Eng
 * @brief  T4T NDEF write process.
 * @param  [in]     writeBuff  Data buffer to write.
 * @param  [in]     writeLen  Data length.
 * @retval NFC_OK   Success.
 * @retval Other    Failure. For details, see @ref NfcErrorCode.
 * @else
 * @brief  T4T NDEF写流程。
 * @param  [in]     writeBuff  所要写入的内容。
 * @param  [in]     writeLen  写入内容的大小。
 * @retval NFC_OK   成功。
 * @retval Other    失败。 参考 @ref NfcErrorCode 。
 * @endif
 */
NfcErrorCode NFC_NDEF_T4TWriteProc(const uint8_t *writeBuff, uint16_t writeLen);

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */