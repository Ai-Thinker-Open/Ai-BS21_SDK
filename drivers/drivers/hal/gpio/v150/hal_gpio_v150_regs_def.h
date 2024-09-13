/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides V150 gpio register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-27, Create file. \n
 */
#ifndef HAL_GPIO_V150_REGS_H
#define HAL_GPIO_V150_REGS_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_gpio_v150_regs_def GPIO V150 Regs Definition
 * @ingroup  drivers_hal_gpio
 * @{
 */

#define RESERVED_MAX_NUM 2

/**
 * @brief  GPIO pin group definition. A GPIO channel contains a maximum of 8 groups of pin.
 */
typedef enum {
    GPIO_GROUP_0 = 0,
    GPIO_GROUP_1,
    GPIO_GROUP_2,
    GPIO_GROUP_3,
    GPIO_GROUP_4,
    GPIO_GROUP_5,
    GPIO_GROUP_6,
    GPIO_GROUP_7,
    GPIO_GROUP_MAX_NUM
} gpio_group_t;

/**
 * @brief  GPIO pin definition in group. Each GPIO group contains a maximum of 32 pins.
 */
typedef enum {
    GPIO_GROUP_PIN_00 = 0,
    GPIO_GROUP_PIN_01,
    GPIO_GROUP_PIN_02,
    GPIO_GROUP_PIN_03,
    GPIO_GROUP_PIN_04,
    GPIO_GROUP_PIN_05,
    GPIO_GROUP_PIN_06,
    GPIO_GROUP_PIN_07,
    GPIO_GROUP_PIN_08,
    GPIO_GROUP_PIN_09,
    GPIO_GROUP_PIN_10,
    GPIO_GROUP_PIN_11,
    GPIO_GROUP_PIN_12,
    GPIO_GROUP_PIN_13,
    GPIO_GROUP_PIN_14,
    GPIO_GROUP_PIN_15,
    GPIO_GROUP_PIN_16,
    GPIO_GROUP_PIN_17,
    GPIO_GROUP_PIN_18,
    GPIO_GROUP_PIN_19,
    GPIO_GROUP_PIN_20,
    GPIO_GROUP_PIN_21,
    GPIO_GROUP_PIN_22,
    GPIO_GROUP_PIN_23,
    GPIO_GROUP_PIN_24,
    GPIO_GROUP_PIN_25,
    GPIO_GROUP_PIN_26,
    GPIO_GROUP_PIN_27,
    GPIO_GROUP_PIN_28,
    GPIO_GROUP_PIN_29,
    GPIO_GROUP_PIN_30,
    GPIO_GROUP_PIN_31,
    GPIO_GROUP_PIN_MAX_NUM
} gpio_group_pin_t;

/**
 * @brief  GPIO pin idx info, including the channel, the group, and group pin number to which this pin belongs.
 */
typedef struct gpio_idx_info {
    uint8_t channel;
    uint8_t group;
    uint8_t group_pin;
    uint8_t rsv;
} gpio_idx_info_t;

/**
 * @brief  Register definition of each GPIO group.
 */
typedef struct gpio_info_regs {
    volatile uint32_t gpio_sw_out;                      /*!< (0x00) : port A data register */
    volatile uint32_t gpio_sw_oen;                      /*!< (0x04) : port A data direction register */
    volatile uint32_t gpio_sw_ctl;                      /*!< (0x08) : Port A data source register */
    volatile uint32_t gpio_int_en;                      /*!< (0x0C) : Interrupt enable */
    volatile uint32_t gpio_int_mask;                    /*!< (0x10) : Interrupt mask */
    volatile uint32_t gpio_int_type;                    /*!< (0x14) : Interrupt type */
    volatile uint32_t gpio_int_polarity;                /*!< (0x18) : Interrupt polarity */
    volatile uint32_t gpio_int_dedge;                   /*!< (0x1C) : Interrupt double edge type */
    volatile uint32_t gpio_int_debounce;                /*!< (0x20) : Interrupt debounce enable */
    volatile uint32_t gpio_int_raw;                     /*!< (0x24) : Raw interrupt status */
    volatile uint32_t gpio_intr;                        /*!< (0x28) : Interrupt status */
    volatile uint32_t gpio_int_eoi;                     /*!< (0x2C) : Clear interrupt */
    volatile uint32_t gpio_data_set;                    /*!< (0x30) : Data set */
    volatile uint32_t gpio_data_clr;                    /*!< (0x34) : Data clear */
#ifdef CONFIG_GPIO_SUPPORT_MULTISYSTEM
    volatile uint32_t gpio_id;                          /*!< (0x38) : GPIO version register */
    volatile uint32_t gpio_data_oen_set;                /*!< (0x3C) : data direction register set */
    volatile uint32_t gpio_data_oen_clr;                /*!< (0x40) : data direction register clr */
    volatile uint32_t gpio_sw_ctl_set;                  /*!< (0x44) : control mode register set */
    volatile uint32_t gpio_sw_ctl_clr;                  /*!< (0x48) : control mode register clr */
    volatile uint32_t gpio_int_en_set;                  /*!< (0x4C) : Interrupt enable set */
    volatile uint32_t gpio_int_en_clr;                  /*!< (0x50) : Interrupt enable clr */
    volatile uint32_t gpio_int_mask_set;                /*!< (0x54) : Interrupt mask set */
    volatile uint32_t gpio_int_mask_clr;                /*!< (0x58) : Interrupt mask clr */
    volatile uint32_t gpio_int_type_set;                /*!< (0x5C) : Interrupt type set */
    volatile uint32_t gpio_int_type_clr;                /*!< (0x60) : Interrupt type clr */
    volatile uint32_t gpio_int_polarity_set;            /*!< (0x64) : Interrupt polarity set */
    volatile uint32_t gpio_int_polarity_clr;            /*!< (0x68) : Interrupt polarity clr */
    volatile uint32_t gpio_int_dedge_set;               /*!< (0x6C) : Interrupt double edge type set */
    volatile uint32_t gpio_int_dedge_clr;               /*!< (0x70) : Interrupt double edge type clr */
    volatile uint32_t gpio_int_debounce_set;            /*!< (0x74) : Interrupt debounce enable set */
    volatile uint32_t gpio_int_debounce_clr;            /*!< (0x78) : Interrupt debounce enable clr */
#else
    volatile uint32_t reserved[RESERVED_MAX_NUM];       /*!< (0x38) : Reserved */
#endif
} gpio_group_regs_t;

/**
 * @brief  Register definition of GPIO channel.
 *         A GPIO channel contains a maximum of 8 groups of pin.
 *         Each GPIO group contains a maximum of 32 pins.
 */
typedef struct gpio_v150_regs {
    volatile gpio_group_regs_t gpio_group_cfg[GPIO_GROUP_MAX_NUM];  /*!< (0x00)  : gpio config register */
    volatile uint32_t gpio_lock;                                    /*!< (0x200) : gpio lock register */
    volatile uint32_t gpio_lp_state;                                /*!< (0x204) : gpio low power state */
} gpio_v150_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif

