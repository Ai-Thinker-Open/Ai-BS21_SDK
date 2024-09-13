/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides flash port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-10-26， Create file. \n
 */
#ifndef FLASH_CONFIG_COMMON_PORTING_H
#define FLASH_CONFIG_COMMON_PORTING_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @ingroup  drivers_port_flash_config
 * @{
 */

/**
 * @if Eng
 * @brief  supported flash.
 * @else
 * @brief  支持的flash。
 * @endif
 */
typedef enum flash_support_manufacturer {
    FLASH_MXIC_MX25R80,
    FLASH_PUYA_P25Q80SU,
    FLASH_GIGADIVICE_GD25Q80C,
    FLASH_MANUFACTURER_MAX
} flash_support_manufacturer_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
