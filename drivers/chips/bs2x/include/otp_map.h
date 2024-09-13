/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description:  zhangqian OTP map
 * Author: @CompanyNameTag
 * Create:  2021-06-16
 */
#ifndef OTP_MAP_H
#define OTP_MAP_H

#include "chip_definitions.h"
#include "chip_io.h"

/**
 * @defgroup connectivity_config_otp OTP
 * @ingroup  connectivity_config
 * @{
 */
/*
 * OTP address map provides start addresses and lengths
 */
// EFUSE0 256byte(2048bit)
// ATE  0~17
#define OTP_ATE_START                   0
#define OTP_ATE_DIEID_START             0
#define OTP_ATE_DIEID_LENGTH            18

// PMU_TRIM  18~26
#define OTP_PMU_TRIM_START              18
#define OTP_PMU_TRIM_LENGTH             9

// CMU_TRIM  27~32
#define OTP_CMU_TRIM_START              27
#define OTP_CMU_TRIM_LENGTH             6

// XO CORE CTRIM  33
#define XO_CORE_CTRIM                   30

// PMU_TRIM_2  34
#define OTP_TRIM_AUXLDO_RFPA            34
#define OTP_TRIM_AUXLDO_BIT             4
#define OTP_TRIM_AUXLDO_LEN             4
#define OTP_TRIM_RF_BIT                 0
#define OTP_TRIM_RF_LEN                 4

// DEBUG FUSED  35
#define OTP_DEBUG_FUSED                 35
#define OTP_DEBUG_FUSED_SWD_CONFIG_BIT  0
#define OTP_DEBUG_FUSED_SWD_EN_BIT      1
#define OTP_DEBUG_FUSED_DSP_JTAG_EN_BIT 2
#define OTP_DEBUG_FUSED_SSI_EN_BIT      3
#define OTP_DEBUG_FUSED_SECURIY_KEY_EN_ACCESS_BIT 4
#define OTP_DEBUG_FUSED_SEC_SUB_JTAG_BIT 5
#define OTP_DEBUG_FUSED_SEC_SUB_PC_LR_CAP_EN_BIT 6

// HUK_KEY_CHECK_BIT 36
#define OTP_HUK_KEY_CHECK  36

// GID_KEY_CHECK_BIT 37
#define OTP_GID_KEY_CHECK 37

// SEC_SHARE_RAM_DIV 38
/* bit 0-2 :
 * 0: 0KB for SCPU
 * 1: L2MEM_0_1 128KB for SCPU
 * 2: L2MEM_2_3 256KB for SCPU
 * 3: L2MEM_4_5 384KB for SCPU
 * 4: L2MEM_6_7 512KB for SCPU
 * 5: L2MEM_8_9 640KB for SCPU
 * bit 3-7: reserved
 */
#define OTP_SEC_SHARE_RAM_DIV 38

// Reserved 39-51
// RF TRIM
#define OTP_RF_TRIM_START 52
// 7-0 -> cfg_rx_iq_comp_p_val[7:0]: rx iq compensation
#define OTP_BT_RX_IQ_COMP_P_VAL1 52

// 7-1 -> Reserved
// 0   -> cfg_rx_iq_comp_p_val[8]: rx iq compensation
#define OTP_BT_RX_IQ_COMP_P_VAL2 53

// 7-0 -> cfg_rx_iq_comp_e_val[7:0]: rx iq compensation
#define OTP_BT_RX_IQ_COMP_E_VAL 54

// 7-0 -> buffer_gain_i[7:0]:I channel PDET gain
#define OTP_BT_BUFFER_GAIN_I 55

// 7-0 -> buffer_gain_i[7:0]:Q channel PDET gain
#define OTP_BT_BUFFER_GAIN_Q 56

// RF Reserved 57-58
#define OTP_BT_BUFFER_LNA_TRIM 59

// RF Reserved  60-61
#define OTP_RF_TRIM_LENGTH 10

#define OTP_IS_CHIP_TRIMED 0
#define OTP_TRIM_FLAG      62
#define OTP_TRIM_VERSION   63

// BT KEY HUK 64~95
#define OTP_BT_KEY_HUK_START  64
#define OTP_BT_KEY_HUK_LENGTH 32
// BT KEY GID 96~127
#define OTP_BT_KEY_GID_START  96
#define OTP_BT_KEY_GID_LENGTH 32

// APP USED 128~255
#define OTP_APP_USED_START    128
#define OTP_APP_USED_LENGTH   0

// EFUSE1 128byte(1024bit)
// McuRootPubKey hash 128~160
#define OTP_MCU_ROOT_PUBKEY_SHA256_START  128
#define OTP_MCU_ROOT_PUBKEY_SHA256_LENGTH 32
#define OTP_MCU_ROOT_PUBKEY_SHA256_CRC    160

// McuSubkeyIdMask 161-165
#define OTP_MCU_SUBKEY_ID_MASK_START      161
#define OTP_MCU_SUBKEY_ID_MASK_LENGTH     4
#define OTP_MCU_SUBKEY_ID_MASK_CRC        165

// McuSubkeyCategory 166-170
#define OTP_MCU_SUBKEY_CATEGORY_START     166
#define OTP_MCU_SUBKEY_CATEGORY_LENGTH    4
#define OTP_MCU_SUBKEY_CATEGORY_CRC       170

// SSB VERSION COUNTER 171-175
#define OTP_SSB_VERSION_COUNTER_START     171
#define OTP_SSB_VERSION_LENGTH            4
#define OTP_SSB_VERSION_LENGTH_BIT        32

// SEC_BOOT_DEBUG 175
#define OTP_SEC_BOOT_DEBUG_FLAG           175
#define OTP_SEC_BOOT_DEBUG_FLAG_LENGTH    1
#define OTP_SEC_BOOT_EN_BIT               0
#define OTP_SEC_BOOT_DEBUG_BIT            1
#define OTP_SEC_BOOT_KEY_CHECK_EN_BIT     2
#define OTP_SEC_BOOT_AES_EN_BIT           3

// APP Codeloader 176
#define OTP_CODELOADER_FLAGS_BYTE                           176
#define OTP_CODELOADER_FLAGS_LOCKED_CORES_BT_CORE_BIT       0
#define OTP_CODELOADER_FLAGS_LOCKED_CORES_PROTOCOL_CORE_BIT 1
#define OTP_CODELOADER_FLAGS_LOCKED_CORES_APPS_CORE_BIT     2
#define OTP_QSPI_BAUD_CLK_DIV_2_EN_BIT                      3

// FSB Bootloader 177
#define OTP_BOOTLOADER_BYTE                       177
#define OTP_BOOTLOADER_FSB_MINIMAL_ROM_BIT        0
#define OTP_BOOTLOADER_FSB_EN_SSB_HASH_BIT        1
#define OTP_BOOTLOADER_FSB_DIS_ATE_MODE_BIT       2
#define OTP_BOOTLOADER_FSB_DIS_PKCS1_ALG_BIT      3
#define OTP_BOOTLOADER_FSB_DIS_CODELOADER_BIT     4
#define OTP_BOOTLOADER_FSB_NON_EFLASH_BIT         5
#define OTP_BOOTLOADER_FSB_EN_UART_RX_BIT         6   // enable UARTH0 single RX
#define OTP_BOOTLOADER_FSB_DIS_UART_RX_BIT        7   // disable UARTH0 single RX

// FSB Bootloader1 178
#define OTP_BOOTLOADER_BYTE_1                     178
#define OTP_BOOTLOADER_FSB_EN_WAIT_BIT            0
#define OTP_BOOTLOADER_FSB_DIS_WAIT_BIT           1
#define OTP_PIO_DRIVE_QSPI_DRIVE_EN_BIT           2
#define OTP_PIO_DRIVE_UART_DRIVE_EN_BIT           3
#define OTP_PIO_DRIVE_UART_DATA_OFFSET            4U
#define OTP_PIO_DRIVE_UART_DATA_0_BIT             4
#define OTP_PIO_DRIVE_UART_DATA_1_BIT             5
#define OTP_PIO_DRIVE_UART_DATA_2_BIT             6
#define OTP_PIO_DRIVE_UART_DATA_3_BIT             7

// FSB Bootloader Double Check 179 same as OTP_BOOTLOADER_BYTE
#define OTP_BOOTLOADER_DOUBLE_BYTE        179

// FSB Bootloader Double Check 180 same as OTP_SEC_BOOT_DEBUG_FLAG
#define OTP_SEC_BOOT_DEBUG_DOUBLE_FLAG    180

// IO drive 181
#define OTP_PIO_DRIVE_BYTE                181
#define OTP_PIO_DRIVE_QSPI_DATA_0_BIT     0
#define OTP_PIO_DRIVE_QSPI_DATA_1_BIT     1
#define OTP_PIO_DRIVE_QSPI_DATA_2_BIT     2
#define OTP_PIO_DRIVE_QSPI_DATA_3_BIT     3

#define OTP_PIO_DRIVE_QSPI_CLK_OFFSET     4U
#define OTP_PIO_DRIVE_QSPI_CLK_0_BIT      4
#define OTP_PIO_DRIVE_QSPI_CLK_1_BIT      5
#define OTP_PIO_DRIVE_QSPI_CLK_2_BIT      6
#define OTP_PIO_DRIVE_QSPI_CLK_3_BIT      7

// FSB EN_Flash 182
#define OTP_BOOTLOADER_FLASH_BYTE           182
#define OTP_BOOTLOADER_FSB_EN_EFLASH_BIT    0
#define OTP_BOOTLOADER_FSB_DIS_EFLASH_BIT   1

// FSB EN_Flash double 183
#define OTP_BOOTLOADER_FLASH_DOUBLE_BYTE    183

// SSB Image Data  184~187
#define OTP_SSB_CODE_SIZE_START           184
#define OTP_SSB_CODE_SIZE_LENGTH          3
#define OTP_SSB_CODE_CRC                  187

#define OTP_SSB_SHA256_START              188
#define OTP_SSB_SHA256_LENGTH             32
#define OTP_SSB_SHA256_CRC                220

// reserve 221~241
// PMU1_RRIM 242~246
#define OTP_PMU1_TRIM_START  242
#define OTP_PMU1_TRIM_LENGTH 5

// USB_PHY 247
#define OTP_USB_PHY          247

// CVS0 248~249
// CVS1 250~251
// CVS6 252~253
#define OTP_CVS_START       248
#define OTP_CVS_LENGTH      6

// reserve 254
// ATE CRC
#define OTP_ATE_CRC                       255
/**
 * @}
 */
#endif
