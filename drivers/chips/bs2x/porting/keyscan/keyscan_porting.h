/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides keyscan port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-15， Create file. \n
 */

#ifndef KEYSCAN_PORTING_H
#define KEYSCAN_PORTING_H

#include <stdint.h>
#include <stdbool.h>
#include "hal_keyscan_v150_regs_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define KEYSCAN_PIN_SEL_BASE_ADDR                   0x52000910
#define KEYSCAN_PIN_SEL_COL_REG                     KEYSCAN_PIN_SEL_BASE_ADDR
#define KEYSCAN_PIN_SEL_ROW0_REG                    0x52000920
#define KEYSCAN_PIN_SEL_ROW1_REG                    0x52000924
#define KEYSCAN_VALUE_LEN                           5
#define EVEN_SEL_BIT                                0
#define ODD_SEL_BIT                                 8
#define BIT_SEL_LEN                                 5
#define NUM_OF_CFG_PIN_REGS                         12
#define INTERVAL_OF_REGS                            4
#define KEYSCAN_ALOW_SLEEP                          0
#define KEYSCAN_SLEEP_REQUIRE                       4
#define KEYSCAN_SLEEP_ACK                           8
#define REQ_WAIT_FOR_ACK                            30
#define KEYSCAN_MARX_ADDR                           0x5208D0A0

#if defined(CONFIG_REDUCE_PERP_LS_FREQ)
#define CLK_HIGH_DIV 0xA
#else
#define CLK_HIGH_DIV 0x28
#endif
#define CLK_LOW_DIV  0xa

/* 发送键值，str方式输入 */
uint8_t uapi_ble_hid_keyboard_input_str(int key_num, char *key_list[]);

/**
 * @defgroup drivers_port_keyscan Keyscan
 * @ingroup  drivers_port
 * @{
 */

/**
 * @brief  Key scan interrupts.
 */
typedef enum {
    KEYSCAN_INT_FIFO_FULL,             /*!< Fifo full interrupt */
    KEYSCAN_INT_PRESS,                 /*!< Button press interrupt */
    KEYSCAN_INT_RELEASE,               /*!< Key release interrupt */
    KEYSCAN_INT_VALUE_RDY,             /*!< Key value report interrupt */
    KEYSCAN_INT_STOPPED,               /*!< Stop interrupt interrupt */
    KEYSCAN_INT_SCAN_ONE,              /*!< Completes a scan interrupt */
    KEYSCAN_INT_AFIFO_FULL,            /*!< Fifo will be full interrupt */
    KEYSCAN_INT_PRESS_AON,             /*!< Keyboard matrix key interrupt */
    KEYSCAN_INT_MAX_NUM,               /*!< KEYSCAN num */
} keyscan_int_t;

/**
 * @brief  Key scan direction.
 */
typedef enum {
    ROW_SCAN_DIR,                        /*!< 0: Row is configured as output, Column is configured as input */
    COL_SCAN_DIR                         /*!< 1: Column is configured as output, Row is configured as input */
} keyscan_dir_t;

/**
 * @brief  Key scan mode.
 */
typedef enum {
    HAL_KEYSCAN_MODE_0,                 /*!< Input=0 Output=1 Pull down Output while scanning, scan high level */
    HAL_KEYSCAN_MODE_1,                 /*!< Input=1 Output=0 Pull up Output while scanning, scan low level */
    HAL_KEYSCAN_MODE_2,                 /*!< Input=0 Output=1 Pull up Input while scanning, scan low level */
    HAL_KEYSCAN_MODE_3                  /*!< Input=1 Output=0 Pull down Input while scanning, scan high level */
} keyscan_mode_t;

/**
 * @brief  Key scan pulse time.
 */
typedef enum {
    EVERY_ROW_PULSE_10_US,               /*!< KEYSCAN every row pulse 10 us */
    EVERY_ROW_PULSE_20_US,               /*!< KEYSCAN every row pulse 20 us */
    EVERY_ROW_PULSE_30_US,               /*!< KEYSCAN every row pulse 30 us */
    EVERY_ROW_PULSE_40_US                /*!< KEYSCAN every row pulse 40 us */
} keyscan_pulse_time_t;

/**
 * @brief  Key scan change row/col waiting time, contain CBB external observation time and internal path time.
 */
typedef enum {
    WAITING_5_AND_5_US,                  /*!< KEYSCAN waiting 5 and 5 us */
    WAITING_10_AND_5_US,                 /*!< KEYSCAN waiting 10 and 5 us */
    WAITING_20_AND_5_US,                 /*!< KEYSCAN waiting 20 and 5 us */
    WAITING_30_AND_5_US                  /*!< KEYSCAN waiting 30 and 5 us */
} keyscan_wait_time_t;

/**
 * @brief  Key scan idle time.
 */
typedef enum {
    IDLE_1_MS_AFTER_SCAN,                /*!< KEYSCAN idle 1 ms after scan */
    IDLE_3_MS_AFTER_SCAN,                /*!< KEYSCAN idle 3 ms after scan */
    IDLE_5_MS_AFTER_SCAN,                /*!< KEYSCAN idle 5 ms after scan */
    IDLE_7_MS_AFTER_SCAN,                /*!< KEYSCAN idle 7 ms after scan */
    IDLE_10_MS_AFTER_SCAN,               /*!< KEYSCAN idle 10 ms after scan */
    IDLE_13_MS_AFTER_SCAN,               /*!< KEYSCAN idle 13 ms after scan */
    IDLE_16_MS_AFTER_SCAN,               /*!< KEYSCAN idle 16 ms after scan */
    IDLE_20_MS_AFTER_SCAN                /*!< KEYSCAN idle 20 ms after scan */
} keyscan_idle_time_t;

/**
 * @brief  Key scan sample defence num.
 */
typedef enum {
    SAMPLE_NONE_DEFENCE,                 /*!< KEYSCAN sample none defence */
    SAMPLE_2TIMES_DEFENCE,               /*!< KEYSCAN sample 2times defence */
    SAMPLE_3TIMES_DEFENCE,               /*!< KEYSCAN sample 3times defence */
    SAMPLE_4TIMES_DEFENCE                /*!< KEYSCAN sample 4times defence */
} key_defence_num_t;

/**
 * @brief  Key scan select num per scan.
 */
typedef enum {
    SELECT_SIX_KEYS_PER_SCAN,            /*!< KEYSCAN select six keys per scan */
    SELECT_SEVEN_KEYS_PER_SCAN,          /*!< KEYSCAN select seven keys per scan */
    SELECT_EIGHT_KEYS_PER_SCAN,          /*!< KEYSCAN select eight keys per scan */
    SELECT_TEN_KEYS_PER_SCAN             /*!< KEYSCAN select ten keys per scan */
} key_select_num_t;

/**
 * @brief  Key scan keys type.
 */
typedef enum {
    FULL_KEYS_TYPE,                        /*!< KEYSCAN full keys keyboard */
    SIX_KEYS_TYPE,                         /*!< KEYSCAN six keys keyboard */
    USER_CONFIG_TYPE                       /*!< KEYSCAN user config keyboard */
} keyscan_keys_type_t;

/**
 * @brief  KEYSCAN default configuration.
 */
#define KEYSCAN_DEFAULT_CONFIG                       \
{                                                    \
    .direction         = ROW_SCAN_DIR,               \
    .scan_mode         = HAL_KEYSCAN_MODE_0,         \
    .pulse_time        = EVERY_ROW_PULSE_10_US,      \
    .wait_time         = WAITING_30_AND_5_US,        \
    .idle_time         = IDLE_3_MS_AFTER_SCAN,       \
    .defence_time      = SAMPLE_NONE_DEFENCE,        \
    .ghost_check       = false,                      \
    .io_de             = true,                       \
}

/**
 * @if Eng
 * @brief  KEYSCAN configuration structure.
 * @else
 * @brief  KEYSCAN配置结构
 * @endif
 */
typedef struct {
    keyscan_dir_t direction;           /*!< @if Eng Indicate whether row or column be output, the other be input.
                                            @else   表明当行或列其中一个为输出时，另一个为输入 @endif */
    keyscan_mode_t scan_mode;          /*!< @if Eng Indicate level of input and output in initial state and scanning.
                                            @else   声明初始状态和扫描过程的输入、输出电平 @endif */
    keyscan_pulse_time_t pulse_time;   /*!< @if Eng Duration of the pulse as each row is scanning,
                                                   depends on the load.
                                            @else   每行扫描时脉冲的持续时间，取决于负载 @endif */
    keyscan_wait_time_t wait_time;     /*!< @if Eng Key scan change row/col waiting time.
                                            @else   键扫描更改行/列等待时间 @endif */
    keyscan_idle_time_t idle_time;     /*!< @if Eng No scanning during this time, keys restoring the initial state.
                                            @else   在此期间不进行扫描，按键恢复初始状态 @endif */
    key_defence_num_t defence_time;    /*!< @if Eng Sample defence nums, get the same coordinate means its vaild
                                                   Config defence_time and idle_time to confirm that
                                                   scanning time is bigger than jitter time.
                                            @else   采样防御数，获取相同坐标表示其有效配置防御时间和空闲时间，
                                                   以确认扫描时间大于抖动时间 @endif */
    bool ghost_check;                  /*!< @if Eng If three keys form a rectangle, only report two keys' coordinates.
                                            @else   如果三个键组成一个矩形，只报告两个键的坐标 @endif */
    bool io_de;                        /*!< @if Eng Enable the I/O port anti-jitter.
                                                   Glitch signals less than 1 μs will be filtered.
                                            @else   当行或列其中一个为输出时，另一个为输入 @endif */
    keyscan_int_t event_type;          /*!< @if Eng Interrupt source type selection.
                                            @else   中断源类型选择 @endif */
} keyscan_config_t;

/**
 * @brief  Get the base address of a specified keyscan.
 * @return The base address of specified keyscan.
 */
uintptr_t keyscan_porting_base_addr_get(void);

/**
 * @brief  Get the base address of a specified keyscan m ctrl.
 * @return The base address of specified keyscan m ctrl.
 */
uintptr_t keyscan_m_ctl_porting_base_addr_get(void);

/**
 * @brief  Register hal funcs objects into hal_keyscan module.
 */
void keyscan_port_register_hal_funcs(void);

/**
 * @brief  Unregister hal funcs objects from hal_keyscan module.
 */
void keyscan_port_unregister_hal_funcs(void);

/**
 * @brief  Register the interrupt of keyscan.
 * @param  [in]  int_id The interrupt number of keyscan.
 */
void keyscan_port_register_irq(uint32_t int_id);

/**
 * @brief  Unregister the interrupt of keyscan.
 * @param  [in]  int_id The interrupt number of keyscan.
 */
void keyscan_port_unregister_irq(uint32_t int_id);

#if defined (CONFIG_KEYSCAN_SUPPORT_LPM)
/**
 * @brief  Config the pins for deep sleep.
 */
void keyscan_porting_suspend_pin_set(void);
#endif

/**
 * @brief  Set Keyscan gpio.
 * @param  [in]  user_gpio_map The keyboard pin, col berofe row.
 * @return Keyscan pin set config status.
*/
int keyscan_porting_set_gpio(uint8_t *user_gpio_map);

/**
 * @brief  Config the pins for different keyboard.
 */
void keyscan_porting_config_pins(void);

/**
 * @brief  Config the keyscan pin mode.
 */
void keyscan_porting_pin_set(uint8_t row, uint8_t col);

/**
 * @brief  Resume the config of keyscan pin mode.
 */
void keyscan_porting_pin_resume(void);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif