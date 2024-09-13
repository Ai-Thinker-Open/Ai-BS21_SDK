/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023.All rights reserved. \n
 *
 * Description: Provides efuse port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-3-4， Create file. \n
 */

#ifndef EFUSE_PORTING_H
#define EFUSE_PORTING_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_efuse Efuse
 * @ingroup  drivers_port
 * @{
 */

#define EFUSE_REGION_NUM                    1
#define EFUSE_REGION_MAX_BITS               1024
#define EFUSE_REGION_MAX_BYTES              (EFUSE_REGION_MAX_BITS >> 3)  // MAX_BIT / 8
#define EFUSE_MAX_BITS                      (EFUSE_REGION_MAX_BITS * EFUSE_REGION_NUM)
#define EFUSE_MAX_BYTES                     (EFUSE_MAX_BITS >> 3)  // MAX_BIT / 8
#define EFUSE_MAX_BIT_POS                   8U

#define EFUSE_PMU_CLKLDO_VSET_MASK          0x78
#define EFUSE_PMU_CLKLDO_OFFSET             3
#define EFUSE_TRIM_VERSION_DEFAULT_VALUE    1
#define EFUSE_CHAR_BIT_WIDE                 8
#define EFUSE_CALC_CRC_MAX_LEN              32

#define EFUSE_TRIM_FLAG                     50
#define EFUSE_IS_CHIP_TRIMED                0
// 7-0 -> Version of the trim
#define EFUSE_TRIM_VERSION                  51
// 2-0 -> vset_bbldo[3:1]
// 6-3 -> vset_clkldo[3:0]
#define EFUSE_PMU_TRIM_VSET                 25
#define EFUSE_DIE_ID_BASE_BYTE_ADDR         0

typedef enum {
    HAL_EFUSE_REGION_0,
    HAL_EFUSE_REGION_MAX,
} hal_efuse_region_t;

/**
 * @if Eng
 * @brief  Base address for the EFUSE boot done.
 * @else
 * @brief  EFUSE的上电完成地址
 * @endif
 */
extern uint32_t g_efuse_boot_done_addr;

/**
 * @if Eng
 * @brief  Base address for the IP.
 * @else
 * @brief  IP的基地址
 * @endif
 */
extern uint32_t g_efuse_base_addr[CONFIG_EFUSE_REGION_NUM];

#if defined(CONFIG_EFUSE_SWITCH_EN)
/**
 * @if Eng
 * @brief  Base address for the EFUSE switch enable.
 * @else
 * @brief  EFUSE的上电开关地址
 * @endif
 */
extern uint32_t g_efuse_switch_en_addr;
#endif

/**
 * @if Eng
 * @brief  Base read address for the IP.
 * @else
 * @brief  IP的读基地址
 * @endif
 */
extern uint32_t g_efuse_region_read_address[CONFIG_EFUSE_REGION_NUM];

/**
 * @if Eng
 * @brief  Base write address for the IP.
 * @else
 * @brief  IP的写基地址
 * @endif
 */
extern uint32_t g_efuse_region_write_address[CONFIG_EFUSE_REGION_NUM];

/**
 * @if Eng
 * @brief  Register hal funcs objects into hal_efuse module.
 * @else
 * @brief  将hal funcs对象注册到hal_efuse模块中
 * @endif
 */
void efuse_port_register_hal_funcs(void);

/**
 * @if Eng
 * @brief  Unregister hal funcs objects from hal_efuse module.
 * @else
 * @brief  从hal_efuse模块注销hal funcs对象
 * @endif
 */
void efuse_port_unregister_hal_funcs(void);

/**
 * @brief  Get the region of a otp byte address
 * @param  byte_addr the addr of the byte to get register
 * @retval region The region of otp
 * @else
 * @brief  获取otp字节地址的区域
 * @param  byte_addr 要获取寄存器的字节的地址
 * @retval 区域OTP的区域
 */
hal_efuse_region_t hal_efuse_get_region(uint32_t byte_addr);

/**
 * @brief  Get the offset addr of a otp byte address
 * @param  byte_addr the addr of the byte to get register
 * @retval address
 * @else
 * @brief  获取otp字节地址的偏移地址
 * @param  byte_addr 要获取寄存器的字节的地址
 * @retval 偏移地址
 */
uint16_t hal_efuse_get_byte_offset(uint32_t byte_addr);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif