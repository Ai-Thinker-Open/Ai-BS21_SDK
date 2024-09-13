/**
 * Copyright (c) @CompanyNameMagicTag 2023. All rights reserved. \n
 * Description: NFC TAG error code \n
 * Author: @CompanyNameTag \n
 * Create: 2023-07-24 \n
 */
/** @defgroup middleware_service_nfc_tag_error_code NFC TAG ERROR CODE
 * @ingroup middleware_service_nfc_tag
 * @{
 */
#ifndef NFC_TAG_ERROR_H
#define NFC_TAG_ERROR_H

#include <stdint.h>

/**
 * 1 Other Header File Including
 */
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @if Eng
 * @brief  NFC module error code type definition.
 * @else
 * @brief  NFC TAG模块的错误码类型定义。
 * @endif
 */
typedef uint32_t NfcTagError;

/**
 * @if Eng
 * @brief  NFC tag module return error code value.
 * @else
 * @brief  NFC tag模块返回的错误码值。
 * @endif
*/
enum {
    /** @if Eng NFC success.
     *  @else   NFC执行成功。 @endif */
    NFC_OK = 0,

    /** @if Eng NFC tag error code valid range is [0x80005F00, 0x80006000), 0x80005F00 is first valid code.
     *  @else   NFC标签的错误码有效范围是[0x80005F00, 0x80006000)，0x80005F00是第一个有效码值。 @endif */
    NFC_ERR_CODE_BEGIN = 0x80005F00,

    /* NFC tag error code. */
    /** @if Eng There is a null pointer among input parameters.
     *  @else   输入参数中有空指针。 @endif */
    NFC_ERR_PTR_NULL = NFC_ERR_CODE_BEGIN,
    /** @if Eng The input length parameter is invalid.
     *  @else   输入参数中有空指针。 @endif */
    NFC_ERR_INVALID_LENGTH,
    /** @if Eng There is an invalid input parameter.
     *  @else   输入参数中有非法参数。 @endif */
    NFC_ERR_INVALID_PARAM,
    /** @if Eng NFC tag is in an invalid state.
     *  @else   NFC标签处于非法状态。 @endif */
    NFC_ERR_INVALID_STATE,
    /** @if Eng Memory copy failure.
     *  @else   内存拷贝失败。 @endif */
    NFC_ERR_MEMCPY_FAIL,

    /** @if Eng NFC tag error code end, valid NFC tag error code should be added above this line.
     *  @else   NFC标签错误码结尾，有效的NFC标签错误码应该在本枚举值之前定义。 @endif */
    NFC_ERR_CODE_END = 0x80006000
};

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* NFC_TAG_ERROR_H */
/**
 * @}
 */