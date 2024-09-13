/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides v150 keyscan register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-16， Create file. \n
 */
#ifndef HAL_KEYSCAN_V150_REGS_DEF_H
#define HAL_KEYSCAN_V150_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_keyscan_v150_regs_def Keyscan V150 Regs Definition
 * @ingroup  drivers_hal_keyscan
 * @{
 */

/**
 * @brief  This union represents the bit fields in the keyscan_lp_ctl register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_lp_ctl_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t alow_slp               : 1;    /*!< If this bit is 1, the keyscan enters the sleepinh state. */
        uint32_t reserved1_3            : 3;    /*!< Reserved */
        uint32_t slp_req                : 1;    /*!< If the alow_slp is 1, then this bit can be set to 1 to clear the
                                                     internal state machine */
        uint32_t reserved5_7            : 3;    /*!< Reserved */
        uint32_t slp_ack                : 1;    /*!< If this bit is 1, then clocks can be closed and switched. */
        uint32_t reserved9_15           : 7;    /*!< Reserved */
    } b;                                        /*!< Register bits. */
} keyscan_lp_ctl_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_enable_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t ena                    : 1;    /*!< If this bit is set to 1, the module enters the working state. */
        uint32_t reserved1_15           : 15;   /*!< Reserved */
    } b;                                        /*!< Register bits. */
} keyscan_enable_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_clk_ena register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_clk_ena_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t fifo_rd_clken          : 1;    /*!< If this bit is set to 1.
                                                     Asynchronous FIFO read clock controller. */
        uint32_t reserved1_15           : 15;   /*!< Reserved */
    } b;                                        /*!< Register bits. */
} keyscan_clk_ena_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_start register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_start_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t task_start             : 1;    /*!< If this bit is set to 1, the module starts to work. */
        uint32_t reserved1_15           : 15;   /*!< Reserved */
    } b;                                        /*!< Register bits. */
} keyscan_start_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_int_en register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_int_en_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t event_fifo_full_int_en         : 1;    /*!< If this bit is set to 1,
                                                             fifo full event interrupt enable. */
        uint32_t event_key_press_int_en         : 1;    /*!< If this bit is set to 1, button press event enable. */
        uint32_t event_key_release_int_en       : 1;    /*!< If this bit is set to 1, key release enable. */
        uint32_t event_key_value_rdy_int_en     : 1;    /*!< If this bit is 1, event enabled with key value report. */
        uint32_t event_key_stopped_int_en       : 1;    /*!< If this bit is set to 1, module Stop Interrupt Enable. */
        uint32_t event_keyscan_one_int_en       : 1;    /*!< If this bit is set to 1,
                                                             the module completes a scan interrupt enable. */
        uint32_t event_fifo_afull_int_en        : 1;    /*!< If this bit is 1,
                                                             fifo will be full event interrupt enable. */
        uint32_t event_key_press_aon_int_en     : 1;    /*!< If this bit is 1,
                                                             keyboard matrix key event interrupt enable. */
        uint32_t reserved8_15                   : 8;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_int_en_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_event_clr register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_event_clr_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t event_fifo_full_clr            : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t event_key_press_clr            : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t event_key_release_clr          : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t event_key_value_rdy_clr        : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t event_key_stopped_clr          : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t event_keyscan_one_clr          : 1;   /*!< If this bit is set to 1, clear the value. */
        uint32_t event_fifo_afull_clr           : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t event_key_press_aon_clr        : 1;    /*!< If this bit is set to 1, clear the value. */
        uint32_t reserved8_15                   : 8;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_event_clr_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_event_sts register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_event_sts_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t event_fifo_full                : 1;    /*!< After the key coordinate value fifo is filled,
                                                             the signal will be triggered. */
        uint32_t event_key_press                : 1;    /*!< When a button press event occurs,
                                                             this register will be set to 1. */
        uint32_t event_key_release              : 1;    /*!< When all the keys inside the ip are released, the long key
                                                             detection process is also ended, and this register will be
                                                             set to 1. */
        uint32_t event_key_value_rdy            : 1;    /*!< When there is a value in the fifo, the event will be
                                                             triggered. */
        uint32_t event_key_stopped              : 1;    /*!< When the module is triggered by task_stop, the module
                                                             starts to stop, and the signal is triggered after the stop
                                                             is completed. */
        uint32_t event_keyscan_one              : 1;   /*!< This signal is triggered when the module completes a round
                                                             of scanning. */
        uint32_t event_fifo_afull               : 1;    /*!< FIFO near full event. */
        uint32_t event_key_press_aon            : 1;    /*!< The keyboard matrix is ​​interrupted by a key event, and it
                                                             is used with low power consumption. */
        uint32_t reserved8_15                   : 8;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_event_sts_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_pin_num register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_pin_num_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t clo_pin_en                     : 3;    /*!< The valid values ​​of the 8 column pins that control the
                                                             keyboard scan module are 0-7. */
        uint32_t reserved3                      : 1;    /*!< Reserved */
        uint32_t row_pin_en                     : 5;    /*!< The valid values ​​of the 18 column pins that control the
                                                             keyboard scan module are 0-17. */
        uint32_t reserved9_15                   : 7;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_pin_num_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_mode register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_mode_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t scan_dir                       : 1;    /*!< If this bit is set to 1, represents row scan mode.
                                                             If this bit is set to 0,
                                                             represents the column scan mode. */
        uint32_t reserved1_3                    : 3;    /*!< Reserved */
        uint32_t scan_mode                      : 2;    /*!< Scan mode configuration register,
                                                             a total of 4 modes. */
        uint32_t reserved6_15                   : 10;   /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_mode_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_pulse register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_pulse_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t tpulse                         : 2;    /*!< If this bit is set to 1, set keyscan value freeze.
                                                             If this bit is set to 0, set keyscan value release. */
        uint32_t reserved2_3                    : 2;    /*!< If this bit is set to 1, set keyscan value clear. */
        uint32_t ttern                          : 2;    /*!< Reserved */
        uint32_t reserved                       : 2;    /*!< If this bit is 1, keyscan value is cleared */
        uint32_t tidle                          : 3;    /*!< If this bit is 1, keyscan value is cleared */
        uint32_t reserved11_15                  : 5;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_pulse_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_de register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_de_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t scan_num                       : 2;    /*!< By configuring this parameter and Tidle time, ensure that
                                                             the total time of the whole several sampling is greater
                                                             than the jitter time. */
        uint32_t reserved                       : 2;    /*!< Reserved */
        uint32_t ghost                          : 1;    /*!< If this bit is 1, enable ghost key detection algorithm.
                                                             If this bit is 0, turn off the detection algorithm. */
        uint32_t reserved7_5                    : 3;    /*!< Reserved */
        uint32_t io_de                          : 1;    /*!< If this bit is 1, filter out glitches less than 1us. */
        uint32_t reserved9_11                   : 3;    /*!< Reserved */
        uint32_t key_num_sel                    : 2;    /*!< The keyboard scanning module can identify the number of
                                                             key values ​​in one round. */
        uint32_t rep_all_key                    : 1;    /*!< If this bit is 1, enable all keys report. */
        uint32_t reserved15                     : 1;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_de_data_t;

/**
 * @brief  This union represents the bit fields in the key_value_fifo register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union key_value_fifo_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t key_value                      : 9;    /*!< Key_value_fifo. */
        uint32_t reserved9_15                   : 7;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} key_value_fifo_data_t;

/**
 * @brief  This union represents the bit fields in the clk_key_h_div register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union clk_key_h_div_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t clk_key_h_div_num              : 7;    /*!< Clock divier keyscann factor of clk_key_h. */
        uint32_t clk_key_h_div_load_en          : 1;    /*!< Frequency divier keyscan factor enable of clk_key_h. */
        uint32_t clk_key_h_div_en               : 1;    /*!< Divider enable of clk_key_h. */
        uint32_t reserved9_11                   : 3;    /*!< Reserved */
        uint32_t clk_key_hen                    : 1;    /*!< Keyboard Clock Enable Switch of clk_key_h. */
        uint32_t reserved13_15                  : 3;    /*!< Reserved */
    } b;                                                /*!< Register bits. */
} clk_key_h_div_data_t;

#if defined (CONFIG_KEYSCAN_USE_LP)
/**
 * @brief  This union represents the bit fields in the key_int_lp_int_en register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union key_int_lp_int_en_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t key_int_lp_int_en              : 1;    /*!< Switch of key_int_lp interrupt enable. */
        uint32_t reserved1_15                   : 15;   /*!< Reserved */
    } b;                                                /*!< Register bits. */
} key_int_lp_int_en_data_t;
#endif

/**
 * @brief  This union represents the bit fields in the clk_key_l_div register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union clk_key_l_div_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t clk_key_l_div_num              : 4;    /*!< Clock divier keyscann factor of clk_key_l. */
        uint32_t clk_key_l_div_load_en          : 1;    /*!< Frequency divier keyscann factor enable of clk_key_l */
        uint32_t clk_key_l_div_en               : 1;    /*!< Divider enable of clk_key_l. */
        uint32_t reserved6_15                   : 10;   /*!< Reserved */
    } b;                                                /*!< Register bits. */
} clk_key_l_div_data_t;

/**
 * @brief  This union represents the bit fields in the keyscan_soft_rst register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union keyscan_soft_rst_data {
    uint32_t d32;                                       /*!< Raw register data. */
    struct {
        uint32_t soft_rst_key_n                 : 1;    /*!< System-wide soft reset of keyscan. */
        uint32_t soft_rst_key_dp_n              : 1;    /*!< Datapath Soft Reset of keyscan. */
        uint32_t reserved2_15                   : 14;   /*!< Reserved */
    } b;                                                /*!< Register bits. */
} keyscan_soft_rst_data_t;

/**
 * @brief  This union represents the bit fields in the key_scan_aon_clk_cfg register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union aon_clk_cfg_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t aon_en                         :   1;
        uint32_t reserved1_3                    :   3;
        uint32_t aon_sel                        :   1;
    } b;                                        /*!< Register bits. */
} aon_clk_cfg_data_t;

#ifdef CONFIG_KEYSCAN_ENABLE_REP_ALL_KEY
/**
 * @brief  This union represents the bit fields in the marx_check2 register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union marx_check2_data {
    uint32_t d32;                               /*!< Raw register data. */
    struct {
        uint32_t key_row_press                  :   9;
        uint32_t reserved9_11                   :   3;
        uint32_t ghost_st                       :   1;
    } b;                                        /*!< Register bits. */
} marx_check2_data_t;
#endif

/**
 * @brief  Registers associated with keyscan.
 */
typedef struct keyscan_regs {
    volatile uint32_t reserved0;                        /*!< Reserved.                <i>Offset: 00h</i>. */
    volatile uint32_t keyscan_lp_ctl;                   /*!< keyscan_lp_ctl.          <i>Offset: 04h</i>. */
    volatile uint32_t keyscan_enable;                   /*!< keyscan_enable.          <i>Offset: 08h</i>. */
    volatile uint32_t keyscan_clk_ena;                  /*!< keyscan_clk_ena.         <i>Offset: 0Ch</i>. */
    volatile uint32_t keyscan_start;                    /*!< keyscan_start.           <i>Offset: 10h</i>. */
    volatile uint32_t reserved[3];                      /*!< Reserved.                <i>Offset: 14-1ch</i>. */
    volatile uint32_t keyscan_int_en;                   /*!< keyscan_int_en.          <i>Offset: 20h</i>. */
    volatile uint32_t keyscan_event_clr;                /*!< keyscan_event_clr.       <i>Offset: 24h</i>. */
    volatile uint32_t keyscan_event_sts;                /*!< keyscan_event_sts.       <i>Offset: 28h</i>. */
    volatile uint32_t reserved2c;                       /*!< Reserved.                <i>Offset: 2Ch</i>. */
    volatile uint32_t keyscan_pin_num;                  /*!< keyscan_pin_num.         <i>Offset: 30h</i>. */
    volatile uint32_t keyscan_mode;                     /*!< keyscan_mode.            <i>Offset: 34h</i>. */
    volatile uint32_t keyscan_pulse;                    /*!< keyscan_pulse.           <i>Offset: 38h</i>. */
    volatile uint32_t reserved1[5];                     /*!< Reserved.                <i>Offset: 3C-4Ch</i>. */
    volatile uint32_t keyscan_de;                       /*!< keyscan_de.              <i>Offset: 50h</i>. */
    volatile uint32_t reserved2[16];                    /*!< Reserved.                <i>Offset: 54-90h</i>. */
    volatile uint32_t key_value_fifo;                   /*!< key_value_fifo.          <i>Offset: 94h</i>. */
} keyscan_regs_t;

#if defined (CONFIG_KEYSCAN_USE_LP)
/**
 * @brief  Registers associated with key_int.
 */
typedef struct keyscan_key_int_regs {
    volatile uint32_t key_int_lp_int_en;        /*!< key_int_lp_int_en.   <i>Offset: 0h</i>. */
} keyscan_key_int_regs_t;
#endif

/**
 * @brief  Registers associated with m_ctl.
 */
typedef struct keyscan_m_ctl_regs {
    volatile uint32_t clk_key_h_div;            /*!< clk_key_h_div.     <i>Offset: 0h</i>. */
    volatile uint32_t clk_key_l_div;            /*!< clk_key_l_div.     <i>Offset: 4h</i>. */
    volatile uint32_t keyscan_soft_rst;         /*!< keyscan_soft_rst.  <i>Offset: 8h</i>. */
    volatile uint32_t aon_clk_cfg;              /*!< aon_clk_cfg.       <i>Offset: Ch</i>. */
} keyscan_m_ctl_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif