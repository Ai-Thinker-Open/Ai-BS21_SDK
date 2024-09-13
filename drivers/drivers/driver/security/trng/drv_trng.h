/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides trng driver header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-09, Create file. \n
 */
#ifndef DRV_TRNG_H
#define DRV_TRNG_H

#include <stdint.h>
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @if Eng
 * @brief  obtaining hardware random numbers.
 * @note   random number of the size of the uint32_t type,generate random numbers of other sizes, which need to be
           called cyclically.
 * @param  [out] buffer Pointer to the buffer where the generated random number is stored.
 * @param  [in]  buffer_len Buffer size.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t .
 * @else
 * @brief  获取硬件随机数。
 * @note   生成uint32_t类型大小的随机数,生成其他大小的随机数,需要循环调用该接口。
 * @param  [out] buffer 指向存储生成的随机数的缓冲区的指针。
 * @param  [in]  buffer_len 缓冲区大小。
 * @retval ERRCODE_SUCC 成功
 * @retval Other        失败，参考 @ref errcode_t
 * @endif
 */
errcode_t drv_cipher_trng_get_random(uint8_t *buffer, uint32_t buffer_len);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
