/*
 * Copyright (c) @CompanyNameMagicTag 2021-2024. All rights reserved.
 * Description:  Default memory configurations
 * Author: @CompanyNameTag
 * Create:  2021-06-16
 */

#ifndef MEMORY_CONFIG_COMMON_H
#define MEMORY_CONFIG_COMMON_H

#include "product.h"
#include "chip_definitions.h"
#include "chip_core_definition.h"

/**
 * @defgroup connectivity_config_memory MEMORY
 * @ingroup  connectivity_config
 * @{
 */
/* Standard lengths */
#define VERSION_LENGTH        88
#define CHANGE_ID_LENGTH      16

#define FILL_4_BYTE           4

/*
 * ********************* ROM ALLOCATION ***********************
 *
 * Used solely by the BT Core ROM image built into the chip.
 */
/* 32K ROM */
#define BOOTROM_START  0x10000
#ifdef SUPPORT_CHIP_N1200
#define BOOTROM_LENGTH 0x5c00
#else
#define BOOTROM_LENGTH 0x5400
#endif

#define ROM_START      (BOOTROM_START + BOOTROM_LENGTH)
#if defined(BUILD_APPLICATION_STANDARD) && !defined(_PRE_FEATURE_VENEER_ROM)
#define ROM_LENGTH     0x2cc00
#else
#ifdef SUPPORT_CHIP_N1200
#define ROM_LENGTH     0x2a400
#else
#define ROM_LENGTH     0x2ac00
#endif
#endif


/* APP ITCM config */
#if defined(BUILD_APPLICATION_STANDARD) && !defined(_PRE_FEATURE_VENEER_ROM)
#define APP_ITCM_ORIGIN 0x42000
#else
#define APP_ITCM_ORIGIN 0x40000
#endif

#if defined(SLEM_CARKEY)
#define APP_ITCM_LENGTH 0x10000
#else
#define APP_ITCM_LENGTH 0x14000
#endif

/* APP DTCM config */
#define APP_DTCM_ORIGIN 0x20000000
#define APP_DTCM_LENGTH 0x10000

/*
 * ********************* FLASH ALLOCATION *********************
 * Flash is shared between the cores, and also handles a limited number of
 * non-volatile storage areas.
 *
 * Flash is split into 2 main areas
 * IMAGE Area
 *  Managed by the Application core
 *  This contains, in order from the bottom of Flash:
 *      Partition image    - Partition image starting at the bottom of flash.
 *      FlashbootA Image   - starts in the page after the Partition image.
 *      FlashbootB Image   - starts in the page after the FlashbootB Image.
 *      APP Image          - starts in the page after the FlashbootB Image.
 *      System On-demand region - dynamically allocated flash for FOTA etc
 * NV Area
 *  Ends at the last page of flash, is configurable in size above a minimum allocation.
 *  NV Area, of 2 pages, is allocated, from the lowest address:
 *      2 pages for APP core use (last 2 pages in Flash)
 *          1 page for APP Core NV
 *          1 page for APP Core NV defragmentation
 */
#define FLASH_START     0x90100000
#ifdef FLASH_1M
#define FLASH_LEN       0x100000
#else
#define FLASH_LEN       0x80000
#endif

#define SFC_FLASH_START     0x90100000
#ifdef FLASH_1M
#define SFC_FLASH_LEN       0x100000
#else
#define SFC_FLASH_LEN       0x80000
#endif
#define SFC_FLASH_MAX_END   (SFC_FLASH_START + SFC_FLASH_LEN)
#define FLASH_PAGE_SIZE 4096
/* APP ITCM config */
#define MCU_ITCM_END    (APP_ITCM_ORIGIN + APP_ITCM_LENGTH)

#define PARTITION_REGION_LENGTH  (PARTITION_IMAGE_PAGES * FLASH_PAGE_SIZE)
/* MCU Flashboot Region */
#define FLASHBOOT_REGION_START  (SFC_FLASH_START + PARTITION_REGION_LENGTH)
#define FLASHBOOTA_REGION_LENGTH  (FLASHBOOT_A_IMAGE_PAGES * FLASH_PAGE_SIZE)
#define FLASHBOOTB_REGION_LENGTH  (FLASHBOOT_B_IMAGE_PAGES * FLASH_PAGE_SIZE)

/* NV Region Defines */
#define NV_STATR_ADDR           (SFC_FLASH_START + SFC_FLASH_LEN - NV_LENGTH)
#define NV_LENGTH               (NV_IMAGE_PAGES * FLASH_PAGE_SIZE)

/* IR Region */
#define IR_FLASH_LENGTH         (IR_STUDY_PAGES * FLASH_PAGE_SIZE)
#define IR_FLASH_OFFSET         (NV_STATR_ADDR - IR_FLASH_LENGTH - SFC_FLASH_START)

/* CUSTOMER Region */
#define CUSTOMER_FLASH_LENGTH   (CUSTOMER_USED_PAGES * FLASH_PAGE_SIZE)
#define CUSTOMER_FLASH_OFFSET   (IR_FLASH_OFFSET - CUSTOMER_FLASH_LENGTH)


#ifdef USE_RSA3072_SIGN
#define CODE_INFO_OFFSET        0x800
#else
#define CODE_INFO_OFFSET        0x300
#endif

/* FOTA Region LENGTH */
#define FOTA_DATA_LENGTH        (FOTA_DATA_PAGES * FLASH_PAGE_SIZE)
#define FOTA_DATA_OFFSET        FOTA_IMAGE_START


#define APP_PROGRAM_ORIGIN      (FLASHBOOT_REGION_START + FLASHBOOTA_REGION_LENGTH + \
                                FLASHBOOTB_REGION_LENGTH + CODE_INFO_OFFSET)

#define APP_PROGRAM_LENGTH      (SFC_FLASH_MAX_END - APP_PROGRAM_ORIGIN - NV_LENGTH - IR_FLASH_LENGTH - \
                                CUSTOMER_FLASH_LENGTH - FOTA_DATA_LENGTH)

/*
 * ********************* RAM ALLOCATION *********************
 *
 * 'APP' RAM include 'ITCM' for code and 'DTCM' for DATA.
 */
/* ----------------------------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------------------- */
/* APP RAM defines
 * APP has base 80K ITCM (Instruction TCM) for code
 *              64K DTCM (Data TCM) for DATA.
 * APP ITCM                 VECTORS TABLE
 *                          RAM TEXT
 *
 * APP DTCM                 STACK
 *                          RAM
 */

/* 80K ITCM for APP core code, start at end of vectors table */
#ifdef CONFIG_ULTRA_DEEP_SLEEP_ENABLE
#ifdef ROM_EC
/* 32K ITCM for retention(exclude ROM data) */
#define RETENTION_RAM_ORIGIN (APP_ITCM_ORIGIN + BOOT_ROM_DATA_LENGTH)
#define RETENTION_RAM_LENGTH (0x8000 - BOOT_ROM_DATA_LENGTH)
#else /* ROM_EC */
#define RETENTION_RAM_ORIGIN (APP_ITCM_ORIGIN)
#define RETENTION_RAM_LENGTH (0x8000)
#endif /* !ROM_EC */
#define APP_RAMTEXT_ORIGIN (RETENTION_RAM_ORIGIN + RETENTION_RAM_LENGTH)
#define APP_RAMTEXT_LENGTH (APP_ITCM_LENGTH - 0x8000)
#else /* CONFIG_ULTRA_DEEP_SLEEP_ENABLE */
#define APP_RAMTEXT_ORIGIN (APP_ITCM_ORIGIN)
#define APP_RAMTEXT_LENGTH (APP_ITCM_LENGTH)
#endif /* !CONFIG_ULTRA_DEEP_SLEEP_ENABLE */

/* 64K DTCM for APP core data */
/* stack for normal 1.5k */
#define APP_USER_STACK_BASEADDR APP_DTCM_ORIGIN
#define APP_USER_STACK_LEN      0x600
#define APP_USER_STACK_LIMIT    (APP_USER_STACK_BASEADDR + APP_USER_STACK_LEN)

/* stack for irq 2k */
#define APP_IRQ_STACK_BASEADDR APP_USER_STACK_LIMIT
#if defined(SLEM_CARKEY)
#define APP_IRQ_STACK_LEN      0xC00
#else
#define APP_IRQ_STACK_LEN      0x800
#endif
#define APP_IRQ_STACK_LIMIT    (APP_IRQ_STACK_BASEADDR + APP_IRQ_STACK_LEN)

/* stack for exception 0.5k */
#define APP_EXCP_STACK_BASEADDR APP_IRQ_STACK_LIMIT
#define APP_EXCP_STACK_LEN      0x200
#define APP_EXCP_STACK_LIMIT    (APP_EXCP_STACK_BASEADDR + APP_EXCP_STACK_LEN)

/* stack for nmi 0.5k */
#define APP_NMI_STACK_BASEADDR APP_EXCP_STACK_LIMIT
#define APP_NMI_STACK_LEN      0x200
#define APP_NMI_STACK_LIMIT    (APP_NMI_STACK_BASEADDR + APP_NMI_STACK_LEN)
/* 12*N bytes for cpu trace, trace line is 12 bytes, 1020 bytes */
#define MCPU_TRACE_MEM_REGION_START 0x52006000
#define CPU_TRACE_MEM_REGION_LENGTH 0x3FC

/* 256 bytes for preserve region */
#define PRESERVED_REGION_ORIGIN (APP_DTCM_ORIGIN + APP_DTCM_LENGTH - PRESERVED_REGION_LENGTH)
#define PRESERVED_REGION_LENGTH 0x100

/* LOG Region */
/* APP - 3K */
#define LOGGING_REGION_START  APP_NMI_STACK_LIMIT
#define LOGGING_REGION_LENGTH APP_LOGGING_LENGTH

#define TRANSMIT_OTA_INFO_SIZE    (0x1000 - 0x20)
#define TRANSMIT_OTA_INFO_START   0xF0000
#define TRANSMIT_OTA_INFO_END     (0xF1000 - 0x20) // 1M flash
#define TRANSMIT_OTA_DATA_START   0x90000 // 1M flash

#define OTA_FOTA_DATA_START        0x90000
#define OTA_TRANSMIT_INFO_START    0xF0000
#define OTA_HASH_START             (0xF1000 - 0x20)
#define OTA_TRANSMIT_INFO_LEN      0x1000
#define OTA_HASH_INFO_SIZE         0x20
#define EXTERN_FLASH_PARTITION_OFFSET         0x80000

/**
 * @}
 */
#endif
