/*
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 * Description: Application Core Platform Definitions
 * Author: @CompanyNameTag
 * Create:  2022-06-16
 */

#ifndef PLATFORM_CORE_H
#define PLATFORM_CORE_H

#include "product.h"
#include "chip_core_definition.h"
#include "memory_config_common.h"

/**
 * @defgroup DRIVER_PLATFORM_CORE CHIP Platform CORE Driver
 * @ingroup DRIVER_PLATFORM
 * @{
 */
#define GLB_CTL_M_RB_BASE        0x57000000
#define GLB_CTL_A_RB_BASE        0x57000400
#define GLB_CTL_D_RB_BASE        0x57000800
#define DISPLAY_CTL_RB_BASE      0x56000000
#define GPU_BASE_ADDR            0x56200000
#define DSS_BASE_ADDR            0x56100000

#define B_CTL_RB_BASE            0x59000000
#define M_CTL_RB_BASE            0x52000000
#define COM_CTL_RB_BASE          0x55000000
#define PMU1_CTL_RB_BASE         0x57004000
#define PMU2_CMU_CTL_RB_BASE     0x57008000
#define ULP_AON_CTL_RB_ADDR      0x5702c000
#define PMU_D_CORE_RB_ADDR       0x5702E000
#define FUSE_CTL_RB_ADDR         0x57028000
#define XO_CORE_TRIM_REG         0x57028308
#define XO_CORE_CTRIM_REG        0x5702D028
#define XIP_CACHE_CTL            0xA3006000
#define NMI_CTL_REG_BASE_ADDR    0x52000700

#define DMA_BASE_ADDR  0x52070000 /* M_DMA */
#define SDMA_BASE_ADDR 0x520A0000 /* S_DMA */

/* I2C reg base addr */
#define I2C_BUS_0_BASE_ADDR 0x52083000
#define I2C_BUS_1_BASE_ADDR 0x52084000

/* spi reg base addr */
#define SPI_BUS_0_BASE_ADDR 0x52087000 // SPI_M0
#define SPI_BUS_1_BASE_ADDR 0x52088000 // SPI_MS_1
#define SPI_BUS_2_BASE_ADDR 0x52089000 // SPI_MS_2

#define I2S_BUS_0_BASE_ADDR 0x5203003c

#define DMA_HANDSHAKE_I2C_BUS_0_TX HAL_DMA_HANDSHAKING_I2C0_TX
#define DMA_HANDSHAKE_I2C_BUS_0_RX HAL_DMA_HANDSHAKING_I2C0_RX
#define DMA_HANDSHAKE_I2C_BUS_1_TX HAL_DMA_HANDSHAKING_I2C1_TX
#define DMA_HANDSHAKE_I2C_BUS_1_RX HAL_DMA_HANDSHAKING_I2C1_RX

#define HAL_SPI_DEVICE_MODE_SET_REG   (0x52000728)
#define HAL_SPI3_MODE_SET_REG         (M_CTL_RB_BASE + 0x950)

/* PWM reg base addr */
#define PWM_0_BASE 0x52090000

/* PWM INTR REG */
#define PWM_INTR_ENABLE_REG (*(volatile unsigned short *)0x52000900)
#define PWM_INTR_CLEAR_REG  (*(volatile unsigned short *)0x52000904)
#define PWM_INTR_STATUS_REG (*(volatile unsigned short *)0x52000908)

// GPIO regs
#define GPIO0_BASE_ADDR 0x57010000
#define GPIO1_BASE_ADDR 0x57014000
#define GPIO2_BASE_ADDR 0x57018000
#define GPIO3_BASE_ADDR 0x5701C000
#define GPIO4_BASE_ADDR 0x57020000
#define ULP_GPIO_BASE_ADDR 0x57030000 // ULP GPIO

// GPIO select core
#define HAL_GPIO_D_CORE_SET_REG             0x570001B0
#define HAL_GPIO_NON_D_CORE_SET_REG         0x57000180
#define HAL_GPIO_CORE_SET_CHANNEL_OFFSET    0x08
#define HAL_GPIO_CORE_SET_REG_OFFSET        2
#define HAL_GPIO_CORE_SET_GPIOS             16

// ULP GPIO int clk config
#define HAL_GPIO_ULP_AON_GP_REG                 0x5702C010
#define HAL_GPIO_ULP_AON_PCLK_INT_EN_BIT        0
#define HAL_GPIO_ULP_AON_PCLK_INT_CLK_SEL_BIT   1
#define HAL_GPIO_ULP_PCLK_INTR_STATUS_BITS      0x3

#define RTC_TIMER_BASE_ADDR 0x57024000

#define SYSTICK_BASE_ADDR 0x5702C330

#define TCXO_COUNT_BASE_ADDR 0x57000200
#define WDT_BASE_ADDR 0x52003000
#define CHIP_WDT_BASE_ADDRESS 0x57034000

#define HAL_SOFT_RST_CTL_BASE               (GLB_CTL_M_RB_BASE)
#define HAL_GLB_CTL_M_ATOP1_L_REG_OFFSET    0x168
#define HAL_CHIP_WDT_ATOP1_RST_BIT          1

// SEC BASE ADDR
#define SEC_CTL_RB_BASE 0x52009000
#define RSAV2_S_RB_BASE 0x52009900

#define TRNG_RB_BASE    0x52009000

// Timer reg base addr.
#define TIMER_BASE_ADDR                         0x52002000
#define TIMER_0_BASE_ADDR                       (TIMER_BASE_ADDR + 0x100)
#define TIMER_1_BASE_ADDR                       (TIMER_BASE_ADDR + 0x200)
#define TIMER_2_BASE_ADDR                       (TIMER_BASE_ADDR + 0x300)
#define TIMER_3_BASE_ADDR                       (TIMER_BASE_ADDR + 0x400)
#define TICK_TIMER_BASE_ADDR                    TIMER_3_BASE_ADDR
// cpu trace memory
#define TRACE_MEM_REGION_START                  MCPU_TRACE_MEM_REGION_START
#define TRACE_MEM_REGION_LENGTH                 CPU_TRACE_MEM_REGION_LENGTH

/*
 * Maximum I2C buses
 * Defined here rather than in the uart_bus_t enum, due to needing to use it for conditional compilation
 * BS2x chip supports a maximum of 2 buses. By default, we only config it to 1 bus;
 * If you want to use 2 I2C bus, you need config it by menuconfig;
 */
#ifdef CONFIG_I2C_BUS_MAX_NUM
#define I2C_BUS_MAX_NUMBER  CONFIG_I2C_BUS_MAX_NUM  // !< Max number of I2C available
#else
#define I2C_BUS_MAX_NUMBER  1  // !< set I2C bus to 1 by default
#endif
#define TIMER_MAX_AVAILABLE_NUMBER    4  // !< Max number of timer available
#define RTC_MAX_AVAILABLE_NUMBER      4  // !< Max number of rtc available

/*
 * Maximum SPI buses
 * BS2x chip supports a maximum of 3 buses. By default, we only config it to 1 bus;
 * If you want to use more one SPI bus, you need config it by menuconfig;
 */
#ifdef CONFIG_SPI_BUS_MAX_NUM
#define SPI_BUS_MAX_NUMBER  CONFIG_SPI_BUS_MAX_NUM  // !< Max number of SPI available
#else
#define SPI_BUS_MAX_NUMBER  1  // !< set SPI bus to 1 by default
#endif

#define GPIO_MAX_NUMBER     3  // !< Max number of GPIO available
#define I2S_MAX_NUMBER      1

#define PDM_PIN_DATA          S_MGPIO10
#define PDM_PIN_CLK           S_MGPIO14

#define PDM_PIO_FUNC_DATA     HAL_PIO_DMIC_DIN
#define PDM_PIO_FUNC_CLK      HAL_PIO_DMIC_CLK

#define QDEC_CONFIG_PIO_A     S_MGPIO16
#define QDEC_CONFIG_PIO_B     S_MGPIO17
#define QDEC_CONFIG_PIO_LED   S_MGPIO18

#define QDEC_CONFIG_PINMUX_A     HAL_PIO_QDEC_A
#define QDEC_CONFIG_PINMUX_B     HAL_PIO_QDEC_B
#define QDEC_CONFIG_PINMUX_LED   HAL_PIO_QDEC_LED_OUT

#define S_DMA_CHANNEL_MAX_NUM    4  // !< Max number of SM_DMA available
#define B_DMA_CHANNEL_MAX_NUM    8  // !< Max number of M_DMA available

#define DMA_CHANNEL_MAX_NUM      (S_DMA_CHANNEL_MAX_NUM + B_DMA_CHANNEL_MAX_NUM)

#define CHIP_BCPU_SWDDIO  0
#define CHIP_BCPU_SWDCLK  0

#define TEST_SUITE_UART_BUS UART_BUS_0 // UART L0
#define TEST_SUITE_UART_TX_PIN S_MGPIO31
#define TEST_SUITE_UART_RX_PIN S_MGPIO30

#ifdef PRE_ASIC
#ifdef SW_UART_DEBUG
    #define CHIP_FIXED_RX_PIN S_MGPIO30
    #define CHIP_FIXED_TX_PIN S_MGPIO31
#else
    #define CHIP_FIXED_RX_PIN S_MGPIO19
    #define CHIP_FIXED_TX_PIN S_MGPIO20
#endif

#else
    #define CHIP_FIXED_RX_PIN S_MGPIO30
    #define CHIP_FIXED_TX_PIN S_MGPIO31
#endif
#ifdef BUILD_ROMBOOT
#define UART_BUS_MAX_NUMBER 1
#elif defined(PRODUCT_SLE_MOUSE)
#define UART_BUS_MAX_NUMBER 2
#else
#define UART_BUS_MAX_NUMBER 3
#endif
#define UART0_BASE     0x52081000 /* UART_L0 */
#define UART1_BASE     0x52080000 /* UART_H0 */
#define UART2_BASE     0x52082000 /* UART_L1 */

#define SW_DEBUG_UART_BUS UART_BUS_0
#define CHIP_FIXED_UART_BUS UART_BUS_0
#define WVT_FIXED_UART_BAUDRATE 230400

#define CODELOADER_UART_BUS UART_BUS_0
#define CODELOADER_UART_RX_PIN S_MGPIO30
#define CODELOADER_UART_TX_PIN S_MGPIO31

#define LOGR_UART_BUS UART_BUS_1
#define LOG_UART_RX_PIN S_MGPIO27
#define LOG_UART_TX_PIN S_MGPIO26

#if defined(PRODUCT_AIR_MOUSE)
#define LOG_UART_BUS       UART_BUS_2
#else
#define LOG_UART_BUS       UART_BUS_1
#endif

#define QSPI_MAX_NUMBER    2
#define FLASH_QSPI_ID      QSPI_BUS_1
#define QSPI_0_BASE_ADDR   0xA3000000
#define QSPI_1_BASE_ADDR   0xA3002000

/* !< QSPI bus */
typedef enum {
    QSPI_BUS_0 = 0,
    QSPI_BUS_1,
    QSPI_BUS_NONE = QSPI_MAX_NUMBER
} qspi_bus_t;

/**
 * @brief  I2C bus.
 */
typedef enum {
    I2C_BUS_0,               // !< I2C0
    I2C_BUS_1,               // !< I2C1
    I2C_BUS_NONE = I2C_BUS_MAX_NUMBER
} i2c_bus_t;

/**
 * @brief  Definition of SPI bus index.
 */
typedef enum {
    SPI_BUS_0 = 0,
    SPI_BUS_1,
    SPI_BUS_2,
    SPI_BUS_NONE = SPI_BUS_MAX_NUMBER
} spi_bus_t;

/**
 * @brief  PWM device.
 */
typedef enum {
    PWM_0,                  /* < PWM Peripheral 0 */
    PWM_1,                  /* < PWM Peripheral 1 */
    PWM_2,                  /* < PWM Peripheral 2 */
    PWM_3,                  /* < PWM Peripheral 3 */
    PWM_4,                  /* < PWM Peripheral 4 */
    PWM_5,                  /* < PWM Peripheral 5 */
    PWM_6,                  /* < PWM Peripheral 6 */
    PWM_7,                  /* < PWM Peripheral 7 */
    PWM_8,                  /* < PWM Peripheral 8 */
    PWM_9,                  /* < PWM Peripheral 9 */
    PWM_10,                 /* < PWM Peripheral 10 */
    PWM_11,                 /* < PWM Peripheral 11 */
    PWM_NONE
} pwm_channel_t;

/**
 * @brief SIO(I2S/PCM) Bus.
 *
 */
typedef enum {
    SIO_BUS_0,
    SIO_NONE = I2S_MAX_NUMBER
} sio_bus_t;

typedef enum {
    UART_BUS_0 = 0,  // !< UART L | UART L0
#if UART_BUS_MAX_NUMBER > 1
    UART_BUS_1 = 1,  // !< UART H | UART H0
#endif
#if UART_BUS_MAX_NUMBER > 2
    UART_BUS_2 = 2,  // !< M UART | UART L1
#endif
    UART_BUS_NONE = UART_BUS_MAX_NUMBER  // !< Value used as invalid/unused UART number
} uart_bus_t;

/* !< SLAVE CPU */
typedef enum {
    SLAVE_CPU_BT,
    SLAVE_CPU_MAX_NUM,
} slave_cpu_t;

/**********************************************************************/
/************************* MPU config base addr ***********************/
/**********************************************************************/
// config register region
#define MPU_REG_ADDR0_BASE           0x50000000
#define MPU_REG_ADDR0_LEN            0x10000000

#define MPU_REG_ADDR1_BASE           0xA3000000
#define MPU_REG_ADDR1_LEN            0x01000000

// ROM region
#define MPU_ROM_ADDR_BASE               0x0
#define MPU_ROM_ADDR_LEN                0x8000

// ITCM region
#define MPU_ITCM_ADDR_BASE              0x80000
#define MPU_ITCM_ADDR_LEN               0x80000

// L2ram region
#define MPU_L2RAM_ADDR0_BASE            0x100000
#define MPU_L2RAM_ADDR0_LEN             0x100000
#define MPU_L2RAM_ADDR1_BASE            0x200000
#define MPU_L2RAM_ADDR1_LEN             0x100000

// XIP PSRAM read & execute region
#define MPU_XIP_PSRAM_RO_ADDR_BASE      0x08000000
#define MPU_XIP_PSRAM_RO_ADDR_LEN       0x04000000

// XIP PSRAM bypass(read/write) region
#define MPU_XIP_PSRAM_RW_ADDR_BASE      0x0C000000
#define MPU_XIP_PSRAM_RW_ADDR_LEN       0x04000000

// XIP NorFlash region
#define MPU_XIP_FLASE_RO_ADDR_BASE      0x10000000
#define MPU_XIP_FLASE_RO_ADDR_LEN       0x10000000

// Sharemem region
#define MPU_SHAREMEM_ADDR_BASE          0x87000000
#define MPU_SHAREMEM_ADDR_LEN           0x10000

// MDMA(m0) address judge
#define MEM_X2P_MEMORY_START    0xA3000000
#define MEM_X2P_MEMORY_END      0xA3008FFF
#define L2RAM_MEMORY_START      0x00100000
#define L2RAM_MEMORY_END        0x0035FFFF
#define QSPI_XIP_MEMORY_START   0x08000000
#define QSPI_XIP_MEMORY_END     0x1FFFFFFF

// CHIP RESET offset address
#define CHIP_RESET_OFF   0x600

// Power on the flash memory on the FPGA
#define PMU_RESERV1      0x5700814c

// Sfc addr
#define HI_SFC_REG_BASE             0x90000000
#define HI_SFC_FLASH1_BASE          0x90100000
#define HI_SFC_MEM_SIZE             0x00200000

/**
 * @brief Definition of pin.
 */
typedef enum {
    S_MGPIO0  = 0,         // GPIO0_0   C_PINMUX_CTL offset: 0x0300
    S_MGPIO1  = 1,         // GPIO0_1   C_PINMUX_CTL
    S_MGPIO2  = 2,         // GPIO0_2   C_PINMUX_CTL
    S_MGPIO3  = 3,         // GPIO0_3   C_PINMUX_CTL
    S_MGPIO4  = 4,         // GPIO0_4   C_PINMUX_CTL
    S_MGPIO5  = 5,         // GPIO0_5   C_PINMUX_CTL
    S_MGPIO6  = 6,         // GPIO0_6   C_PINMUX_CTL
    S_MGPIO7  = 7,         // GPIO0_7   C_PINMUX_CTL
    S_MGPIO8  = 8,         // GPIO0_8   C_PINMUX_CTL
    S_MGPIO9  = 9,         // GPIO0_9   C_PINMUX_CTL
    S_MGPIO10 = 10,        // GPIO0_10  C_PINMUX_CTL
    S_MGPIO11 = 11,        // GPIO0_11  C_PINMUX_CTL
    S_MGPIO12 = 12,        // GPIO0_12  C_PINMUX_CTL
    S_MGPIO13 = 13,        // GPIO0_13  C_PINMUX_CTL
    S_MGPIO14 = 14,        // GPIO0_14  C_PINMUX_CTL
    S_MGPIO15 = 15,        // GPIO0_15  C_PINMUX_CTL
    S_MGPIO16 = 16,        // GPIO0_16  C_PINMUX_CTL
    S_MGPIO17 = 17,        // GPIO0_17  C_PINMUX_CTL
    S_MGPIO18 = 18,        // GPIO0_18  C_PINMUX_CTL
    S_MGPIO19 = 19,        // GPIO0_19  C_PINMUX_CTL
    S_MGPIO20 = 20,        // GPIO0_20  C_PINMUX_CTL
    S_MGPIO21 = 21,        // GPIO0_21  C_PINMUX_CTL
    S_MGPIO22 = 22,        // GPIO0_22  C_PINMUX_CTL
    S_MGPIO23 = 23,        // GPIO0_23  C_PINMUX_CTL
    S_MGPIO24 = 24,        // GPIO0_24  C_PINMUX_CTL
    S_MGPIO25 = 25,        // GPIO0_25  C_PINMUX_CTL
    S_MGPIO26 = 26,        // GPIO0_26  C_PINMUX_CTL
    S_MGPIO27 = 27,        // GPIO0_27  C_PINMUX_CTL
    S_MGPIO28 = 28,        // GPIO0_28  C_PINMUX_CTL offset: 0x031C
    S_MGPIO29 = 29,        // GPIO0_29  C_PINMUX_CTL
    S_MGPIO30 = 30,        // GPIO0_30  C_PINMUX_CTL
    S_MGPIO31 = 31,        // GPIO0_31  C_PINMUX_CTL
    PIN_NONE =  32,       // used as invalid/unused PIN number
    ULP_PIN = PIN_NONE,
} pin_t;

#define TCXO_COUNT_ENABLE                 YES

#define PIN_MAX_NUMBER                    PIN_NONE // value USED to iterate in arrays

#define WATCHDOG_ROM_ENABLE               YES

#define GPIO_WITH_ULP                     YES
#define GPIO_FUNC                         HAL_PIO_FUNC_GPIO

#define I2C_AUTO_SEND_STOP_CMD            NO
#define I2C_WITH_BUS_RECOVERY             YES

#define SPI_WITH_OPI                      NO
#define SPI_DMA_TRANSFER_NUM_BY_BYTE      NO

#define DMA_TRANSFER_DEBUG                YES
#define DMA_USE_HIDMA                     NO
#define DMA_WITH_SMDMA                    YES // Small dma
#define DMA_WITH_MDMA                     NO // Small dma
#define DMA_TRANS_BY_LLI                  NO

#define XIP_WITH_OPI                      YES
#define XIP_INT_BY_NMI                    YES
#define FLASH_SLAVE_NOTIFY_MASTER_BOOTUP YES

#define ENABLE_CPU_TRACE                  2
#define ADC_WITH_AUTO_SCAN                YES

#define OTP_HAS_READ_PERMISSION           YES
#define OTP_HAS_WRITE_PERMISSION          YES
#define OTP_HAS_CLKLDO_VSET               NO

#define SEC_IAMGE_AES_DECRYPT_EN          NO
#define SEC_BOOT_SIGN_CHECK_EN            YES
#define SEC_SUB_RST_BY_SECURITY_CORE      NO
#define TRNG_WITH_SEC_COMMON              YES
#define IS_MAIN_CORE                      YES
#define EXTERNAL_CLOCK_CALIBRATION        YES
#define AON_SPECIAL_PIO                   YES

#define SUPPORT_HI_EMMC_PHY               NO

#define OPI_PIN_FIX_DM1_DRIVER            NO
#define OPI_USE_MCU_HS_CLK                NO
#define QSPI0_FUNC  HAL_PIO_SPI0_RXD
#define QSPI0_D0    S_MGPIO0
#define QSPI0_D1    S_MGPIO1
#define QSPI0_D2    S_MGPIO2
#define QSPI0_D3    S_MGPIO3
#define QSPI0_CLK   S_MGPIO4
#define QSPI0_CS    S_MGPIO5

#ifdef ATE_FLASH_CHECK
#define QSPI1_FUNC  HAL_PIO_FUNC_QSPI0
#define QSPI1_D0    S_MGPIO0
#define QSPI1_D1    S_MGPIO1
#define QSPI1_D2    S_MGPIO2
#define QSPI1_D3    S_MGPIO3
#define QSPI1_CLK   S_MGPIO4
#define QSPI1_CS    S_MGPIO5
#else
#define QSPI1_FUNC  HAL_PIO_FUNC_QSPI1
#define QSPI1_D0    S_MGPIO6
#define QSPI1_D1    S_MGPIO7
#define QSPI1_D2    S_MGPIO8
#define QSPI1_D3    S_MGPIO9
#define QSPI1_CLK   S_MGPIO10
#define QSPI1_CS    S_MGPIO11
#endif

#define XIP_EXIST                         YES
#define CHIP_FLASH_ID                     0
#define USE_XIP_INDEX                     1
#define BCPU_INT0_ID                      26
#define UART_BAUD_RATE_DIV_8              NO
#define FIXED_IN_ROM                      NO
#define PMU_LPM_WAKEUP_SRC_NUM            16
#define ENABLE_GPIO_INTERRUPT             YES
#define CLK_AUTO_CG_ENABLE                NO
#if defined(BUILD_APPLICATION_ROM)
#define BOOT_ROM_DFR_PRINT                NO
#else
#define BOOT_ROM_DFR_PRINT                NO
#endif
#define FLASH_WRITE_CLK_DIV_AUTO_ADJ     NO
#define DMA_WITH_MUX_CHANNEL              YES
#define CRITICAL_INT_RESTORE              YES
#define SUPPORT_SEC_TRNG                  NO
#define TCXO_CLK_DYN_ADJUST              NO
#define DCACHE_IS_ENABLE                  NO
#define CODELOADER_SINGLE_PARTITION_EXP   YES
#define AUXLDO_ENABLE_FLASH               NO
/**
 * @}
 */
#endif
