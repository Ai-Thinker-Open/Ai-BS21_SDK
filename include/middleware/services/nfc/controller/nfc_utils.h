/**
 * Copyright (c) @CompanyNameMagicTag 2023. All rights reserved. \n
 * Description: nfc utility \n
 * Author: @CompanyNameTag \n
 * Date: 2023-07-20 \n
 */
/** @defgroup middleware_service_nfc_controller_utility NFC UTILITY
 * @ingroup middleware_service_nfc_controller
 * @{
 */
#ifndef NFC_UTILITY_H
#define NFC_UTILITY_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @if Eng
 * @brief  Return the minimum number of two input values.
 * @param  [in]     x  1st input value.
 * @param  [in]     y  2nd input value.
 * @return An int32_t value equals to the minimum value.
 * @else
 * @brief  返回输入两个数值的较小值。
 * @param  [in]     x  第一个输入值。
 * @param  [in]     y  第二个输入值。
 * @return int32_t类型的较小数值。
 * @endif
 */
static inline int32_t UTIL_Min(int32_t x, int32_t y)
{
    return x > y ? y : x;
}

/**
 * @if Eng
 * @brief  Return the maximum number of two input values.
 * @param  [in]     x  1st input value.
 * @param  [in]     y  2nd input value.
 * @return An int32_t value equals to the maximum value.
 * @else
 * @brief  返回输入两个数值的较大值。
 * @param  [in]     x  第一个输入值。
 * @param  [in]     y  第二个输入值。
 * @return int32_t类型的较大数值。
 * @endif
 */
static inline int32_t UTIL_Max(int32_t x, int32_t y)
{
    return x > y ? x : y;
}

/**
 * @if Eng
 * @brief  Combine two 8-bits value into a 16-bits value.
 * @param  [in]     b1  Higher byte value.
 * @param  [in]     b0  Lower byte value.
 * @return An uint16_t value that is combined.
 * @else
 * @brief  将2个8bit数组合为1个16bit数。
 * @param  [in]     b1  高位字节。
 * @param  [in]     b0  低位字节。
 * @return uint16_t类型的组合数值。
 * @endif
 */
static inline uint16_t UTIL_Combine8bitTo16bit(uint8_t b1, uint8_t b0)
{
    return (uint16_t)((b1 << 8) | b0); /* 8:8bit */
}

/**
 * @if Eng
 * @brief  Combine four 8-bits value into a 32-bits value.
 * @param  [in]     b3  Highest byte value.
 * @param  [in]     b2  Second-highest byte value.
 * @param  [in]     b1  Second-lowest byte value.
 * @param  [in]     b0  Lowest byte value.
 * @return An uint32_t value that is combined.
 * @else
 * @brief  将4个8bit数组合为1个32bit数。
 * @param  [in]     b3  最高位字节。
 * @param  [in]     b2  次高位字节。
 * @param  [in]     b1  次低位字节。
 * @param  [in]     b0  最低位字节。
 * @return uint32_t类型的组合数值。
 * @endif
 */
static inline uint32_t UTIL_Combine8bitTo32bit(uint8_t b3, uint8_t b2, uint8_t b1, uint8_t b0)
{
    return (uint32_t)((b3 << 24) | (b2 << 16) | (b1 << 8) | b0); /* 24,16,8:24bit,16bit,8bit */
}

/**
 * @if Eng
 * @brief  Get the highest byte value from a input uint32 value.
 * @param  [in]     val  Input value.
 * @return An uint8_t value equals to the highest byte value.
 * @else
 * @brief  获取32bit无符号整型的最高字节。
 * @param  [in]     val  输入数值。
 * @return uint8_t类型的最高字节。
 * @endif
 */
static inline uint8_t UTIL_Byte3(uint32_t val)
{
    return (uint8_t)(val >> 24); /* 24:24bit */
}

/**
 * @if Eng
 * @brief  Get the 2nd highest byte value from a input uint32 value.
 * @param  [in]     val  Input value.
 * @return An uint8_t value equals to the 2nd highest byte value.
 * @else
 * @brief  获取32bit无符号整型的次高字节。
 * @param  [in]     val  输入数值。
 * @return uint8_t类型的次高字节。
 * @endif
 */
static inline uint8_t UTIL_Byte2(uint32_t val)
{
    return (uint8_t)(val >> 16); /* 16:16bit */
}

/**
 * @if Eng
 * @brief  Get the 2nd lowest byte value from a input uint32 value.
 * @param  [in]     val  Input value.
 * @return An uint8_t value equals to the 2nd lowest byte value.
 * @else
 * @brief  获取32bit无符号整型的次低字节。
 * @param  [in]     val  输入数值。
 * @return uint8_t类型的次低字节。
 * @endif
 */
static inline uint8_t UTIL_Byte1(uint32_t val)
{
    return (uint8_t)(val >> 8); /* 8:8bit */
}

/**
 * @if Eng
 * @brief  Get the lowest byte value from a input uint32 value.
 * @param  [in]     val  Input value.
 * @return An uint8_t value equals to the lowest byte value.
 * @else
 * @brief  获取32bit无符号整型的最低字节。
 * @param  [in]     val  输入数值。
 * @return uint8_t类型的最低字节。
 * @endif
 */
static inline uint8_t UTIL_Byte0(uint32_t val)
{
    return (uint8_t)val;
}

#ifdef __cplusplus
}
#endif

#endif
/**
 * @}
 */