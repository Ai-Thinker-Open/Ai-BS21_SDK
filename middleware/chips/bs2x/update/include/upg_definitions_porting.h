/*
 * Copyright (c) @CompanyNameMagicTag. 2023-2023. All rights reserved.
 * Description: UPG product definitions header file
 */

#ifndef UPG_DEFINITIONS_PORTING_H
#define UPG_DEFINITIONS_PORTING_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup middleware_chips_bs21_update_api update
 * @ingroup  middleware_chips
 * @{
 */

/**
 * @if Eng
 * @brief  FLASHBOOT signature image ids.
 * @else
 * @brief  FLASHBOOT签名镜像ID
 * @endif
 */
#define FLASHBOOT_IMAGE_KEY_AREA_ID                  0x4B1E3C1E

/**
 * @if Eng
 * @brief  Image ids.
 * @else
 * @brief  FLASHBOOT镜像ID
 * @endif
 */
#define FLASHBOOT_IMAGE_ID                           0x4B1E3C2D

/**
 * @if Eng
 * @brief  Application signature image ids.
 * @else
 * @brief  Application签名镜像ID
 * @endif
 */
#define APPLICATION_IMAGE_KEY_AREA_ID          0x4B0F2D1E

/**
 * @if Eng
 * @brief  Application image ids.
 * @else
 * @brief  Application镜像ID
 * @endif
 */
#define APPLICATION_IMAGE_ID                   0x4B0F2D2D

/**
 * @if Eng
 * @brief  Slp image ids.
 * @else
 * @brief  Slp镜像ID
 * @endif
 */
#define SLP_IMAGE_ID                           0x4B0F2D2F

/**
 * @if Eng
 * @brief  key area reserved length.
 * @else
 * @brief  key区保留字段长度
 * @endif
 */
#define KEY_AREA_RESERVED_LEN 176

/**
 * @if Eng
 * @brief  info area user defined length.
 * @else
 * @brief  info区用户字段长度
 * @endif
 */
#define INFO_AREA_USER_LEN 176

/**
 * @if Eng
 * @brief  signature length.
 * @else
 * @brief  签名字段长度
 * @endif
 */
#define SIG_LEN         512

/**
 * @if Eng
 * @brief  FOTA external public key.
 * @else
 * @brief  FOTA二级公钥长度
 * @endif
 */
#define PUBLIC_KEY_LEN 516

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

/**
 * @}
 */

#endif /* UPG_DEFINITIONS_PORTING_H */