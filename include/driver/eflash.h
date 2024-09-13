/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides EFLASH driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-02-6， Create file. \n
 */
#ifndef EMBED_FLASH_H
#define EMBED_FLASH_H
#include <stdint.h>
#include "hal_eflash.h"
#include "eflash_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_eflash EFLASH
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize the EFLASH.
 * @param  [in]  region The region of EFLASH, see @ref eflash_region_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  初始化EFLASH。
 * @param  [in]  region 指定的EFLASH块，参考 @ref eflash_region_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_init(eflash_region_t region);

/**
 * @if Eng
 * @brief  Deinitialize the EFLASH.
 * @param  [in]  region The region of EFLASH, see @ref eflash_region_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  去初始化EFLASH。
 * @param  [in]  region 指定的EFLASH块，参考 @ref eflash_region_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_deinit(eflash_region_t region);

/**
 * @if Eng
 * @brief  Set EFLASH frequency.
 * @param  [in]  region The region of EFLASH, see @ref eflash_region_t.
 * @param  [in]  freq   The frequency.
 * @else
 * @brief  设置EFLASH的时钟频率。
 * @param  [in]  region 指定的EFLASH块，参考 @ref eflash_region_t 。
 * @param  [in]  freq   频率。
 * @endif
 */
void uapi_eflash_set_freq(eflash_region_t region, eflash_frequency_t freq);

/**
 * @if Eng
 * @brief  Read data of EFLASH(The EFLASH must be initialised).
 * @note   It is more efficient to read if addr & value is 4-byte aligned.
 * @param  [in]   addr  The EFLASH read address.
 * @param  [out]  value Ponter to the buffer to store the reading data.
 * @param  [in]   len   Length of the buffer to store the reading data.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  读EFLASH的值(EFLASH块必须被初始化过)。
 * @note   addr 和 value是4字节对齐时，读取效率比不对齐高。
 * @param  [in]   addr  EFLASH读取地址。
 * @param  [out]  value 用于存储读取到数据的指针。
 * @param  [in]   len   存储读取到数据的Buffer长度。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_read(uint32_t addr, uint32_t *value, uint32_t len);

/**
 * @if Eng
 * @brief  Erase the entire EFLASH data(The EFLASH must be initialised).
 * @param  [in]  region The region of EFLASH, see @ref eflash_region_t.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  擦除EFLASH整片数据(EFLASH块必须被初始化过)。
 * @param  [in]  region 指定的EFLASH块，参考 @ref eflash_region_t 。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_chip_erase(eflash_region_t region);

/**
 * @if Eng
 * @brief  Erase EFLASH data by block(The EFLASH must be initialised).
 * @param  [in]  addr The EFLASH erase address.
 * @param  [in]  len  Erase data length.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  按块擦除EFLASH数据(EFLASH块必须被初始化过)。
 * @param  [in]  addr 擦除地址。
 * @param  [in]  len  擦除长度。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_erase(uint32_t addr, uint32_t len);

/**
 * @if Eng
 * @brief  Write data into EFLASH(The EFLASH must be initialised).
 * @note   It is more efficient to write if addr & value is 4-byte aligned
 * @param  [in]  addr  The EFLASH write address.
 * @param  [in]  value Ponter to the write data.
 * @param  [in]  len   Length of the write data.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  写EFLASH的值(EFLASH块必须被初始化过)。
 * @note   addr 和 value是4字节对齐时，写入效率比不对齐高。
 * @param  [in]  addr  EFLASH写入地址。
 * @param  [in]  value 数据地址。
 * @param  [in]  len   数据长度。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_write(uint32_t addr, const uint32_t *value, uint32_t len);

/**
 * @if Eng
 * @brief  Suspend the EFLASH(The EFLASH must be initialised).
 * @param  [in]  arg Argument for suspend.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  挂起EFLASH，进入休眠状态(EFLASH块必须被初始化过)。
 * @param  [in]  arg 挂起所需要的参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_suspend(uintptr_t arg);

/**
 * @if Eng
 * @brief  Resume the EFLASH(The EFLASH must be initialised).
 * @param  [in]  arg Argument for resume.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  恢复EFLASH，从休眠状态唤醒(EFLASH块必须被初始化过)。
 * @param  [in]  arg 恢复所需要的参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_resume(uintptr_t arg);

/**
 * @if Eng
 * @brief  Read data of USER FLASH(The EFLASH must be initialised).
 * @note   It is more efficient to read if addr & value is 4-byte aligned.
 * @param  [in]   addr  The EFLASH read address.
 * @param  [out]  value Ponter to the buffer to store the reading data.
 * @param  [in]   len   Length of the buffer to store the reading data.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  读用户 EFLASH的值(EFLASH块必须被初始化过)。
 * @note   addr 和 value是4字节对齐时，读取效率比不对齐高。
 * @param  [in]   addr  EFLASH读取地址。
 * @param  [out]  value 用于存储读取到数据的指针。
 * @param  [in]   len   存储读取到数据的Buffer长度。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_user_read(uint32_t addr, uint32_t *value, uint32_t len);

/**
 * @if Eng
 * @brief  Erase USER EFLASH data by block(The EFLASH must be initialised).
 * @param  [in]  addr The EFLASH erase address.
 * @param  [in]  len  Erase data length.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  按块擦除用户EFLASH数据(EFLASH块必须被初始化过)。
 * @param  [in]  addr 擦除地址。
 * @param  [in]  len  擦除长度。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_user_erase(uint32_t addr, uint32_t len);

/**
 * @if Eng
 * @brief  Write data into USER EFLASH(The EFLASH must be initialised).
 * @note   It is more efficient to write if addr & value is 4-byte aligned
 * @param  [in]  addr  The EFLASH write address.
 * @param  [in]  value Ponter to the write data.
 * @param  [in]  len   Length of the write data.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  写用户EFLASH的值(EFLASH块必须被初始化过)。
 * @note   addr 和 value是4字节对齐时，写入效率比不对齐高。
 * @param  [in]  addr  EFLASH写入地址。
 * @param  [in]  value 数据地址。
 * @param  [in]  len   数据长度。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_eflash_user_write(uint32_t addr, const uint32_t *value, uint32_t len);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
