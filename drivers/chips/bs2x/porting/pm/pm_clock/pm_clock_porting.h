/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm clock port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-07-29， Create file. \n
 */
#ifndef PM_CLOCK_PORTING_H
#define PM_CLOCK_PORTING_H

#include <stdbool.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_pm_clock PM clock
 * @ingroup  drivers_port_pm
 * @{
 */

typedef enum clock_crg_id {
    CLOCK_CRG_ID_MCU_CORE,
    CLOCK_CRG_ID_MCU_PERP_LS,
    CLOCK_CRG_ID_MCU_PERP_UART,
    CLOCK_CRG_ID_MCU_PERP_SPI,
    CLOCK_CRG_ID_NFC_SUB,
    CLOCK_CRG_ID_I2S,
    CLOCK_CRG_ID_XIP_QSPI,
    CLOCK_CRG_ID_MAX,
} clock_crg_id_t;

#define CLOCK_CRG_ID_BT_CPU CLOCK_CRG_ID_MAX

typedef enum clock_clken_id {
    CLOCK_CLKEN_ID_MCU_CORE,
    CLOCK_CLKEN_ID_MCU_PERP_LS,
    CLOCK_CLKEN_ID_MCU_PERP_UART,
    CLOCK_CLKEN_ID_MCU_PERP_SPI,
    CLOCK_CLKEN_ID_NFC_BUS,
    CLOCK_CLKEN_ID_I2S,
    CLOCK_CLKEN_ID_XIP_QSPI,
    CLOCK_CLKEN_ID_MAX,
} clock_clken_id_t;

typedef enum clock_clksel_id {
    CLOCK_CLKSEL_ID_MAX,
} clock_clksel_id_t;

typedef enum clock_clkdiv_id {
    CLOCK_CLKDIV_ID_MAX,
} clock_clkdiv_id_t;

typedef enum clock_clk_src {
    CLOCK_CLK_SRC_RC = 0,
    CLOCK_CLK_SRC_TCXO = 1,
    CLOCK_CLK_SRC_TCXO_2X = 2,
    CLOCK_CLK_SRC_32K = 3,
    CLOCK_CLK_SRC_NONE,
    CLOCK_CLK_SRC_MAX = CLOCK_CLK_SRC_NONE,
} clock_clk_src_t;

typedef enum clock_control_type {
    CLOCK_CONTROL_FREQ_LEVEL_CONFIG,    /* For clock frequency configuration, see @ref clock_freq_level_t */
    CLOCK_CONTROL_BTC_FREQ_CONFIG,      /* For clock frequency configuration, see @ref clock_freq_level_t */
    CLOCK_CONTROL_BTH_FREQ_CONFIG,      /* For clock frequency configuration, see @ref clock_freq_level_t */
    CLOCK_CONTROL_MCLKEN_ENABLE,        /* For the parameter types, see @ref clock_mclken_aperp_type_t */
    CLOCK_CONTROL_MCLKEN_DISABLE,       /* For the parameter types, see @ref clock_mclken_aperp_type_t */
    CLOCK_CONTROL_GLB_CLKEN_ENABLE,     /* For the parameter types, see @ref clock_glb_clken_type_t */
    CLOCK_CONTROL_GLB_CLKEN_DISABLE,    /* For the parameter types, see @ref clock_glb_clken_type_t */
    CLOCK_CONTROL_XO_OUT_ENABLE,        /* For the parameter types, see @ref clock_xo_out_type_t */
    CLOCK_CONTROL_XO_OUT_DISABLE,       /* For the parameter types, see @ref clock_xo_out_type_t */
#if defined(CLOCK_TEST_ENABLE)
    CLOCK_CONTROL_32K_TEST_ENABLE,      /* For the parameter types, see @ref pin_t */
    CLOCK_CONTROL_32K_TEST_DISABLE,     /* For the parameter types, see @ref pin_t */
#endif
    CLOCK_CONTROL_TYPE_MAX,
} clock_control_type_t;

typedef enum clock_xo_out_type {
    CLOCK_XO2ADPLL  = 0,
    CLOCK_XO2ADC    = 1,
    CLOCK_XO2USB    = 3,
    CLOCK_XO2AFE    = 4,
    CLOCK_XO2DIE    = 5,
} clock_xo_out_type_t;

typedef enum clock_glb_clken_type {
    CLOCK_GLB_CLKEN_MCU_PERP_LS     = 1,
    CLOCK_GLB_CLKEN_CAN_BUS         = 4,
    CLOCK_GLB_CLKEN_NFC_SUB         = 5,
    CLOCK_GLB_CLKEN_XO_CALI         = 6,
    CLOCK_GLB_CLKEN_XIP_QSPI        = 7,
    CLOCK_GLB_CLKEN_USB_PHY         = 8,
    CLOCK_GLB_CLKEN_USB_BUS         = 9,
    CLOCK_GLB_CLKEN_PDM             = 10,
    CLOCK_GLB_CLKEN_I2S             = 11,
} clock_glb_clken_type_t;

typedef enum clock_mclken_aperp_type {
    // M_CLKEN0
    CLOCK_APERP_TRNG_CLKEN              = 0,
    CLOCK_APERP_MDIAG_CLKEN             = 1,
    CLOCK_APERP_I2S_CLKEN               = 2,
    CLOCK_APERP_MTOP_GLUE_TRIGGER_CLKEN = 6,
    CLOCK_APERP_UART_L1_CLKEN           = 8,
    CLOCK_APERP_UART_L0_CLKEN           = 9,
    CLOCK_APERP_UART_H0_CLKEN           = 10,
    // M_CLKEN1
    CLOCK_APERP_MTIMER_CLKEN            = 16,
    CLOCK_APERP_SPI0_M_CLKEN            = 17,
    CLOCK_APERP_SPI1_M_CLKEN            = 18,
    CLOCK_APERP_SPI2_M_CLKEN            = 19,
    CLOCK_APERP_PULSE_CAPTURE_CLKEN     = 20,
    CLOCK_APERP_I2C0_CLKEN              = 23,
    CLOCK_APERP_I2C1_CLKEN              = 24,
    CLOCK_APERP_BT_TGTWS_CLKEN          = 31,
    // M_CLKEN2
    CLOCK_APERP_MTIMER_PERP_CLKEN       = 32,
} clock_mclken_aperp_type_t;

typedef enum clock_freq_level {
    CLOCK_FREQ_LEVEL_LOW_POWER,         // MCU: 32M
    CLOCK_FREQ_LEVEL_HIGH,              // MCU: 64M
} clock_freq_level_t;

typedef enum clock_vset_level {
    CLOCK_VSET_LEVEL_1V0,
    CLOCK_VSET_LEVEL_1V1,
} clock_vset_level_t;

typedef enum clock_ccrg_spi_used {
    CLOCK_CCRG_SPI_USED_SPI0 = 0,
    CLOCK_CCRG_SPI_USED_SPI1,
    CLOCK_CCRG_SPI_USED_SPI2,
} clock_ccrg_spi_used_t;

/**
 * @brief  Enable of disable ccrg_clk_spi.
 * @param  dev Device of using ccrg_clk_spi.
 * @param  en true: enable, false: disable.
 */
void clock_ccrg_spi_enable(clock_ccrg_spi_used_t dev, bool en);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif