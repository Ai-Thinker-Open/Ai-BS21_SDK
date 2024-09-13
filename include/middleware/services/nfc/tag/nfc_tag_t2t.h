/**
 * Copyright (c) @CompanyNameMagicTag 2021. All rights reserved. \n
 * Description: NFC TAG T2T API \n
 * Author: @CompanyNameTag \n
 * Create: 2021-09-06 \n
 * 该文件为nfc tag模块接口文件，其中事件、操作、函数接口定义为nfc tag模块功能全集 \n
 * 调用者可以根据自身需要，仅处理关心的事件 \n
 */
/** @defgroup middleware_service_nfc_tag_t2t NFC TAG T2T
  * @ingroup middleware_service_nfc_tag
  * @{
  */
#ifndef NFC_TAG_T2T_H
#define NFC_TAG_T2T_H

/**
 * 1 Other Header File Including
 */
#include <stdint.h>
#include "nfc_tag_error.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @if Eng
 * @brief  The maximum NDEF data length inside T2T tag.
 * @else
 * @brief  tag支持的最大NDEF数据长度。
 * @endif
 */
#define NFC_T2T_MAX_NDEF_SIZE        992

/**
 * @if Eng
 * @brief  The enum of event that tag module can notify host.
 * @else
 * @brief  tag模块可以上报的事件。
 * @endif
*/
typedef enum {
    /** @if Eng  Not used.
     *  @else    不使用。
     *  @endif */
    NFC_T2T_EVENT_NONE,
    /** @if Eng  Detect field on.
     *  @else    读卡器靠近，感知到起场事件。
     *  @endif */
    NFC_T2T_EVENT_FIELD_ON,
    /** @if Eng  Detect field off.
     *  @else    读卡器离开，感知到断场事件。
     *  @endif */
    NFC_T2T_EVENT_FIELD_OFF,
    /** @if Eng  Enter lowpower sleep state.
     *  @else    进入低功耗睡眠状态。
     *  @endif */
    NFC_T2T_EVENT_ENTER_SLEEP = 0xA0,
} NfcT2TEvt;

/**
 * @if Eng
 * @brief  The enum of param id that can be set.
 * @else
 * @brief  tag模块可配置的参数id。
 * @endif
*/
typedef enum {
    /** @if Eng  Reserve for use.
     *  @else    预留。
     *  @endif */
    NFC_T2T_PARAM_RFU,
    /** @if Eng  UID.
     *  @else    UID。
     *  @endif */
    NFC_T2T_PARAM_NFCID,
} NfcT2TParamId;

/**
 * @if Eng
 * @brief  Event callback function that is used to inform user what happend.
 * @param  [in]  event  Event identification. For details, see @ref NfcT2TEvt.
 * @param  [in]  data   Details of the event.
 * @param  [in]  len    Length of data.
 * @else
 * @brief  TAG 模块发生事件时，通过回调函数通知用户。
 * @param  [in]  event  发生的事件。参考 @ref NfcT2TEvt 。
 * @param  [in]  data   事件携带的数据。
 * @param  [in]  len    数据的长度。
 * @endif
 */
typedef void (*NfcT2tCallback)(uint32_t event, const uint8_t *data, uint16_t len);

/**
 * @if Eng
 * @brief  The function is used to initialize the T2T module.
 * @param  [in]  handle  Callback function, if user don't care, can be set to NULL.
 * @else
 * @brief  TAG 模块初始化函数。
 * @param  [in]  handle  回调函数句柄，若用户不关心事件，可以设置为NULL。
 * @endif
 */
void NFC_T2T_Init(NfcT2tCallback handle);

/**
 * @if Eng
 * @brief  The function is used to set T2T parameters.
 * @param  [in]  id    Parameter Id.
 * @param  [in]  data  Details of parameter.
 * @param  [in]  len   Length of data.
 * @retval NFC_OK      Success.
 * @retval Other       Failure. For details, see @ref NfcTagError.
 * @else
 * @brief  设置 TAG 参数
 * @param  [in]  id    参数ID。
 * @param  [in]  data  参数值。
 * @param  [in]  len   参数长度。
 * @retval NFC_OK      成功。
 * @retval Other       失败。 参考 @ref NfcTagError 。
 * @endif
 */
NfcTagError NFC_T2T_SetConfig(uint8_t id, const uint8_t *data, uint8_t len);

/**
 * @if Eng
 * @brief  The function is used to open field detection.
 * @retval NFC_OK      Success.
 * @retval Other       Failure. For details, see @ref NfcTagError.
 * @else
 * @brief  启动RF场检测。
 * @retval NFC_OK      成功。
 * @retval Other       失败。 参考 @ref NfcTagError 。
 * @endif
 */
NfcTagError NFC_T2T_StartEmulation(void);

/**
 * @if Eng
 * @brief  The function is used to close field detection.
 * @retval NFC_OK      Success.
 * @retval Other       Failure. For details, see @ref NfcTagError.
 * @else
 * @brief  关闭RF场检测。
 * @retval NFC_OK      成功。
 * @retval Other       失败。 参考 @ref NfcTagError 。
 * @endif
 */
NfcTagError NFC_T2T_StopEmulation(void);

/**
 * @if Eng
 * @brief  The function is used to set NDEF message in t2t area.
 * @param  [in]  data  NDEF message.
 * @param  [in]  len   Length of data.
 * @retval NFC_SUCC    Success.
 * @retval Other       Failure. For details, see @ref NfcTagError.
 * @else
 * @brief  设置NDEF messgae，由TAG模块组成NDEF-TLV。
 * @param  [in]  data  NDEF数据。
 * @param  [in]  len   NDEF长度。
 * @retval NFC_SUCC    成功。
 * @retval Other       失败。 参考 @ref NfcTagError 。
 * @endif
 */
NfcTagError NFC_T2T_SetNdef(const uint8_t *data, uint16_t len);

/**
 * @if Eng
 * @brief  The function is used to set the memory address storing tag module.
 * @param  [in]  buff  The data buffer contains T2T tag data to set.
 * @param  [in]  len   Length of buffer, which should be no longer than @ref NFC_T2T_MAX_NDEF_SIZE Bytes.
 * @retval NFC_OK      Success.
 * @retval Other       Failure. For details, see @ref NfcTagError.
 * @else
 * @brief  设置TAG存储区。
 * @param  [in]  buff  tag数据缓存地址。
 * @param  [in]  len   tag数据长度, 最大长度 @ref NFC_T2T_MAX_NDEF_SIZE 。
 * @retval NFC_OK      成功。
 * @retval Other       失败。 参考 @ref NfcTagError 。
 * @endif
 */
NfcTagError NFC_T2T_SetTagArea(uint8_t *buff, uint16_t len);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* NFC_TAG_T2T_H */
/**
 * @}
 */