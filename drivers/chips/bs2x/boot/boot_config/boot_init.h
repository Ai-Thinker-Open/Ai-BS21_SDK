/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: Common Boot for Standard Application Core
 * Author: @CompanyNameTag
 * Create: 2023-01-09
 */

#ifndef _BOOT_INIT_H_
#define _BOOT_INIT_H_

#define EXECUTE_CODE_HEAD                   0x40006f
#define FLASH_HEAD_ADDR                     0x90100000
#define FLASH_MEM_SIZE                      0x00100000
#define FLASH_MEM_SIZE_ROM                  0x80000  /* rom default 512kb */

#define KERNEL_START_ADDR                   0x90108000

#define BOOT_HEAD_ADDR                      0x00000000
#if defined (USE_RSA3072_SIGN) && defined (SUPPORT_CHIP_N1200)
#define LOAD_BOOT_ADDR                      0x41000  /* use itcm start addr + 0x1000 load loaderboot. */
#else
#define LOAD_BOOT_ADDR                      0x40000  /* use itcm start addr load loaderboot. */
#endif

#define BOOT_PORTING_RESET_REG              0x57004600
#define BOOT_PORTING_RESET_VALUE            0

#define PMU_WATCH_DOG_EN                    0x5702C930
#define PMU_WATCH_DOG_FEED                  0x5702C934

#define STATUS_DEBUG_REG_ADDR               0x57000010
#define STATUS_ATE_REG_ADDR                 0x5702C010
#define STATUS_ATE_MASK                     0x1
#define ATE_RAM_CODE_ADDR                   LOAD_BOOT_ADDR

#define HIBURN_DEFAULT_UART                 UART_BUS_0

#define UART_ROMBOOT_INT_TIMEOUT_64MS       64
#define UART_ROMBOOT_INT_TIMEOUT_32MS       32
#define UART_ROMBOOT_INT_TIMEOUT_16MS       16
#define UART_ROMBOOT_INT_TIMEOUT_4MS        4
#define UART_ROMBOOT_INT_TIMEOUT_NUM        4

#define FLASHBOOT_MAX_SIZE                  0x10000
#if defined(BUILD_ROMBOOT)
#define LOAD_MIN_SIZE                       0x300     /* 0x100(key area) + 0x200(code info area) + 0x0(code image) */
#else
#define LOAD_MIN_SIZE                       0x0       /* 0x100(key area) + 0x200(code info area) + 0x0(code image) */
#endif
#define LOAD_MAX_SIZE                       0x1000000   /* load cmd support max 16M */

#define LOAD_RAM_MIN_SIZE                   0x0
#define LOAD_RAM_MAX_SIZE                   0x14000

/* boot efuse bit define */
#define BOOT_EFUSE_SEC_BYTE                 60
#define BOOT_EFUSE_SEC_BYTE_WIDTH           0x1
#define BOOT_EFUSE_LOADBOOT_HASH_EN         0x1
#define BOOT_EFUSE_FLASHBOOT_HASH_EN        0x2
#define BOOT_EFUSE_SEC_DEFAULT_VAL          0x0

#define BOOT_EFUSE_UART_TIMEOUT_BYTE        61
#define BOOT_EFUSE_UART_TIMEOUT_WIDTH       1
#define BOOT_EFUSE_UART_TIMEOUT_MASK        0x3

#define BOOT_EFUSE_UART_PIN_BYTE            62
#define BOOT_EFUSE_UART_PIN_WIDTH           1

#define BOOT_EFUSE_UART_DS_BYTE             63
#define BOOT_EFUSE_UART_DS_WIDTH            1
#define BOOT_EFUSE_UART_DS_EN               0x3
#define BOOT_EFUSE_UART_DS_MASK             0xc

#define BOOT_EFUSE_SFC_DS_BYTE              64
#define BOOT_EFUSE_SFC_DS_WIDTH             1
#define BOOT_EFUSE_SFC_DS_EN                0x3
#define BOOT_EFUSE_SFC_CLK_DS_MASK          0xc
#define BOOT_EFUSE_SFC_DATA_CS_DS_MASK      0x30

#define BOOT_EFUSE_JLINK_ID_BYTE            65
#define BOOT_EFUSE_JLINK_ID_WIDTH           1
#define BOOT_EFUSE_JLINK_ID_FLAG            0x3

#define BOOT_EFUSE_HASH_EN_BYTE             65
#define BOOT_EFUSE_HASH_EN_WIDTH            1
#define BOOT_EFUSE_HASH_EN_MASK             0x30

#define BOOT_EFUSE_BOOT_HASH_BYTE           76
#define BOOT_EFUSE_BOOT_HASH_WIDTH          32

#define BOOT_EFUSE_JLINK_ID_VAL_BYTE        66
#define BOOT_EFUSE_JLINK_ID_VAL_WIDTH       4

#ifdef CONFIG_LOADERBOOT_SUPPORT_READ_VERSION
#define VERSION_STR_ADDR    0x90111528
#define VERSION_STR_LEN     40
#endif

#endif