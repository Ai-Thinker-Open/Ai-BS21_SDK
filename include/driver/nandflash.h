/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provide Nand Flash driver API.
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-05-12, Create file. \n
 */

#ifndef NANDFLASH_H
#define NANDFLASH_H

#include <stdint.h>
#include "errcode.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_nandflash Nand Flash
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Obtain the nandflash ID.
 * @param  [in]  id The pointer to store the returned ID.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  获取Nand Flash的ID。
 * @param  [in]  id 用于存储ID的数据指针。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_nandflash_read_id(uint16_t *id);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif