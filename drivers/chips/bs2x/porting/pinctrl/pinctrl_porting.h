/**
 * Copyright (c) @CompanyNameMagicTag 2023-2024. All rights reserved. \n
 *
 * Description: Provides pinctrl port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2024-04-10， Create file. \n
 */
#ifndef PINCTRL_PORTING_H
#define PINCTRL_PORTING_H

#include "securec.h"
#include "platform_core.h"
#include "chip_io.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_pinctrl Pinctrl
 * @ingroup  drivers_port
 * @{
 */

#define HAL_PIO_FUNC_INVALID        HAL_PIO_FUNC_MAX

/**
 * @brief  Definition of mode-multiplexing.
 */
typedef enum {
    PIN_MODE_0        = 0,
    PIN_MODE_1        = 1,
    PIN_MODE_2        = 2,
    PIN_MODE_3        = 3,
    PIN_MODE_4        = 4,
    PIN_MODE_5        = 5,
    PIN_MODE_6        = 6,
    PIN_MODE_7        = 7,
    PIN_MODE_8        = 8,
    PIN_MODE_9        = 9,
    PIN_MODE_10       = 10,
    PIN_MODE_11       = 11,
    PIN_MODE_12       = 12,
    PIN_MODE_13       = 13,
    PIN_MODE_14       = 14,
    PIN_MODE_15       = 15,
    PIN_MODE_16       = 16,
    PIN_MODE_17       = 17,
    PIN_MODE_18       = 18,
    PIN_MODE_19       = 19,
    PIN_MODE_20       = 20,
    PIN_MODE_21       = 21,
    PIN_MODE_22       = 22,
    PIN_MODE_23       = 23,
    PIN_MODE_24       = 24,
    PIN_MODE_25       = 25,
    PIN_MODE_26       = 26,
    PIN_MODE_27       = 27,
    PIN_MODE_28       = 28,
    PIN_MODE_29       = 29,
    PIN_MODE_30       = 30,
    PIN_MODE_31       = 31,
    PIN_MODE_32       = 32,
    PIN_MODE_33       = 33,
    PIN_MODE_34       = 34,
    PIN_MODE_35       = 35,
    PIN_MODE_36       = 36,
    PIN_MODE_37       = 37,
    PIN_MODE_38       = 38,
    PIN_MODE_39       = 39,
    PIN_MODE_40       = 40,
    PIN_MODE_41       = 41,
    PIN_MODE_42       = 42,
    PIN_MODE_43       = 43,
    PIN_MODE_44       = 44,
    PIN_MODE_45       = 45,
    PIN_MODE_46       = 46,
    PIN_MODE_47       = 47,
    PIN_MODE_48       = 48,
    PIN_MODE_49       = 49,
    PIN_MODE_50       = 50,
    PIN_MODE_51       = 51,
    PIN_MODE_53       = 53,
    PIN_MODE_52       = 52,
    PIN_MODE_54       = 54,
    PIN_MODE_55       = 55,
    PIN_MODE_56       = 56,
    PIN_MODE_57       = 57,
    PIN_MODE_58       = 58,
    PIN_MODE_59       = 59,
    PIN_MODE_60       = 60,
    PIN_MODE_61       = 61,
    PIN_MODE_62       = 62,
    PIN_MODE_63       = 63,
    PIN_MODE_64       = 64,
    PIN_MODE_65       = 65,
    PIN_MODE_66       = 66,
    PIN_MODE_67       = 67,
    PIN_MODE_68       = 68,
    PIN_MODE_69       = 69,
    PIN_MODE_70       = 70,
    PIN_MODE_125      = 125,
    PIN_MODE_MAX      = 126
} pin_mode_t;

/**
 * @brief  Definition of drive-strength.
 */
typedef enum {
    PIN_DS_0    = 0,
    PIN_DS_1    = 1,
    PIN_DS_2    = 2,
    PIN_DS_3    = 3,
    PIN_DS_MAX
} pin_drive_strength_t;

typedef enum {
    PIN_IE_0    = 0,
    PIN_IE_1    = 1,
    PIN_IE_MAX
} pin_input_enable_t;

/**
 * @brief  Definition of pull-up/pull-down.
 */
typedef enum {
    PIN_PULL_NONE = 0,
    PIN_PULL_UP   = 1,
    PIN_PULL_DOWN = 2,
    PIN_PULL_MAX
} pin_pull_t;


typedef enum {
    /* pinmux mode 0 funciton */
    HAL_PIO_FUNC_GPIO           = 0,
    HAL_PIO_SPI0_RXD            = 1,
    HAL_PIO_SPI0_TXD            = 2,
    HAL_PIO_SPI0_SCLK           = 3,
    HAL_PIO_SPI0_CS0            = 4,
    HAL_PIO_SPI0_CS1            = 5,
    HAL_PIO_SPI1_RXD            = 6,
    HAL_PIO_SPI1_TXD            = 7,
    HAL_PIO_SPI1_CS0            = 8,
    HAL_PIO_SPI1_CS1            = 9,
    HAL_PIO_SPI1_CLK            = 10,
    HAL_PIO_SPI2_RXD            = 11,
    HAL_PIO_SPI2_TXD            = 12,
    HAL_PIO_SPI2_CS0            = 13,
    HAL_PIO_SPI2_CS1            = 14,
    HAL_PIO_SPI2_CLK            = 15,
    HAL_PIO_UART_L0_RXD         = 16,
    HAL_PIO_UART_L0_TXD         = 17,
    HAL_PIO_UART_L1_RTS         = 18,
    HAL_PIO_UART_L1_TXD         = 19,
    HAL_PIO_UART_L1_CTS         = 20,
    HAL_PIO_UART_L1_RXD         = 21,
    HAL_PIO_UART_H0_CTS         = 22,
    HAL_PIO_UART_H0_RTS         = 23,
    HAL_PIO_UART_H0_RXD         = 24,
    HAL_PIO_UART_H0_TXD         = 25,
    HAL_PIO_I2C0_CLK            = 26,
    HAL_PIO_I2C0_DATA           = 27,
    HAL_PIO_I2C1_CLK            = 28,
    HAL_PIO_I2C1_DATA           = 29,
    HAL_PIO_QDEC_A              = 30,
    HAL_PIO_QDEC_B              = 31,
    HAL_PIO_QDEC_LED_OUT        = 32,
    HAL_PIO_DMIC_DIN            = 33,
    HAL_PIO_DMIC_CLK            = 34,
    HAL_PIO_I2S_SCLK            = 35,
    HAL_PIO_I2S_WS              = 36,
    HAL_PIO_I2S_DOUT            = 37,
    HAL_PIO_I2S_DIN             = 38,
    HAL_PIO_I2S_MCLK            = 39,
    HAL_PIO_PWM0                = 40,
    HAL_PIO_PWM1                = 41,  // HAL_PIO_PWM0_COMP = 41
    HAL_PIO_PWM2                = 42,  // HAL_PIO_PWM1 = 42
    HAL_PIO_PWM3                = 43,  // HAL_PIO_PWM1_COMP = 43
    HAL_PIO_PWM4                = 44,  // HAL_PIO_PWM2 = 44
    HAL_PIO_PWM5                = 45,  // HAL_PIO_PWM2_COMP = 45
    HAL_PIO_PWM6                = 46,  // HAL_PIO_PWM20 = 46
    HAL_PIO_PWM7                = 47,  // HAL_PIO_PWM20_COMP = 47
    HAL_PIO_PWM8                = 48,  // HAL_PIO_PWM30 = 48
    HAL_PIO_PWM9                = 49,  // HAL_PIO_PWM30_COMP = 49
    HAL_PIO_PWM10               = 50,  // HAL_PIO_PWM40 = 50
    HAL_PIO_PWM11               = 51,  // HAL_PIO_PWM40_COMP = 51
    HAL_PIO_PLUSE_CAPTURE       = 53,
    HAL_PIO_KEY_SCAN            = 52,
    HAL_PIO_EXTLNA_RX_EN        = 54,
    HAL_PIO_BT_ACTIVE           = 55,
    HAL_PIO_BT_FREQ             = 56,
    HAL_PIO_WLAN_ACTIVE         = 57,
    HAL_PIO_BTS_SAMPLE          = 58,
    HAL_PIO_BT_WIFI_SW          = 59,
    HAL_PIO_BT_SP_SAMP_P        = 60,
    HAL_PIO_BT_GLP_SYNC         = 61,
    HAL_PIO_BT_STATUS           = 62,
    HAL_PIO_ANT_SEL             = 63,
    HAL_PIO_FRAME_SYNC          = 64,
    HAL_PIO_EXTLNA_CTRL         = 65,
    HAL_PIO_CAN_TX              = 66,
    HAL_PIO_CAN_RX              = 67,
    HAL_PIO_BT_FAME_RX_EN       = 68,
    HAL_PIO_BT_FAME_TX_EN       = 69,
    HAL_PIO_CLK_REQ             = 70,
    HAL_PIO_FUNC_DEFAULT_HIGH_Z,
    HAL_PIO_FUNC_MAX
} hal_pio_func_t;

typedef enum {
    HAL_PIO_PULL_NONE,  //!< No pull down or pull up enabled.
    HAL_PIO_PULL_UP,  //!< Pull down enabled for this pin.
    HAL_PIO_PULL_DOWN,    //!< Pull up enabled for this pin.
    HAL_PIO_PULL_MAX,
} hal_pio_pull_t;

typedef enum {
    HAL_PIO_DRIVE_0 =  0,   //!< lowest pio current dirve strength.
    HAL_PIO_DRIVE_1 =  1,
    HAL_PIO_DRIVE_2 =  2,
    HAL_PIO_DRIVE_3 =  3,
    HAL_PIO_DRIVE_4 =  3,
    HAL_PIO_DRIVE_5 =  3,
    HAL_PIO_DRIVE_6 =  3,
    HAL_PIO_DRIVE_7 =  3,
    HAL_PIO_DRIVE_8 =  3,
    HAL_PIO_DRIVE_9 =  3,
    HAL_PIO_DRIVE_10 = 3,
    HAL_PIO_DRIVE_11 = 3,
    HAL_PIO_DRIVE_12 = 3,
    HAL_PIO_DRIVE_13 = 3,
    HAL_PIO_DRIVE_14 = 3,
    HAL_PIO_DRIVE_15 = 3,  //!< highest pio current dirve strength.
    HAL_PIO_DRIVE_MAX,
} hal_pio_drive_t;

typedef struct {
    hal_pio_func_t func;
    hal_pio_drive_t drive;
    hal_pio_pull_t pull;
    pin_input_enable_t ie;
} hal_pio_config_t;

/**
 * @brief  Check whether the mode configured for the pin is valid.
 * @param  [in]  pin  The index of pins. see @ref pin_t
 * @param  [in]  mode The Multiplexing mode. see @ref pin_mode_t
 * @return The value 'true' indicates that the mode is valid and the value 'false' indicates that the mode is invalid.
 */
bool pin_check_mode_is_valid(pin_t pin, pin_mode_t mode);

/**
 * @brief  Register hal funcs objects into hal_pinctrl module.
 */
void pin_port_register_hal_funcs(void);

/**
 * @brief  Unregister hal funcs objects from hal_pinctrl module.
 */
void pin_port_unregister_hal_funcs(void);

void get_pio_func_config(size_t *pin_num, hal_pio_config_t **pin_func_array);

/**
 * @brief  Get the gpio configuration of all of the pins.
 * @return The value indicates the gpio configuration of all of the pins.
 */
uint32_t pin_gpio_mode_get(void);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif