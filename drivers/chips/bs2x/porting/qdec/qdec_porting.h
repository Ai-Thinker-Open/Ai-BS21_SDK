/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides qdec port template \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-13， Create file. \n
 */
#ifndef QDEC_PORTING_H
#define QDEC_PORTING_H

#include <stdint.h>
#include "pinctrl_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_qdec QDEC
 * @ingroup  drivers_port
 * @{
 */

#define M_CTL_QDEC_SAMPLEPER_REG                 0x52000240
#define QDEC_CLK_FREQ_BIT                        4
#define M_CTL_QDEC_CLK_CTL_REG                   0x52000270
#define QDEC_CLK_SEL_BIT                         0
#define QDEC_CLK_EN_BIT                          4

#define QDEC_CONFIG_REPORTPER    HAL_QDEC_REPORTPER_1
#define QDEC_CONFIG_SAMPLEPER    HAL_QDEC_SAMPLEPER_512US
#define QDEC_DEBOUNCE_NUM        HAL_QDEC_DEBOUNCE_NUM_2
#define QDEC_CONFIG_LEDPRE       256
#define QDEC_CONFIG_LEDPOL       HAL_QDEC_LED_POL_ACTIVE_HIGH
#define QDEC_CONFIG_DEFENCE      true
#define QDEC_CONFIG_SAMPLE_INTEN false
#define IRQ_QDEC                 88

#ifndef QDEC_A
#define QDEC_A                   S_MGPIO4
#endif
#ifndef QDEC_B
#define QDEC_B                   S_MGPIO3
#endif

#if defined(CONFIG_REDUCE_PERP_LS_FREQ)
#define QDEC_CLK_DIV_NUM        8
#else
#define QDEC_CLK_DIV_NUM        32
#endif

/**
 * @if Eng
 * @brief  Number of samples to generate an EVENT_REPORTRDY.
 * @else
 * @brief  触发上报事件所需的采样数
 * @endif
 */
typedef enum {
    HAL_QDEC_REPORTPER_1,
    HAL_QDEC_REPORTPER_10,
    HAL_QDEC_REPORTPER_40,
    HAL_QDEC_REPORTPER_100,
    HAL_QDEC_REPORTPER_160,
    HAL_QDEC_REPORTPER_220,
    HAL_QDEC_REPORTPER_280,
    HAL_QDEC_REPORTPER_360,
    HAL_QDEC_REPORTPER_DISABLED
} hal_qdec_report_per_t;

/**
 * @if Eng
 * @brief  Sample period.
 * @else
 * @brief  采样周期
 * @endif
 */
typedef enum {
    HAL_QDEC_SAMPLEPER_128US,
    HAL_QDEC_SAMPLEPER_256US,
    HAL_QDEC_SAMPLEPER_512US,
    HAL_QDEC_SAMPLEPER_1024US,
    HAL_QDEC_SAMPLEPER_2048US,
    HAL_QDEC_SAMPLEPER_4096US,
    HAL_QDEC_SAMPLEPER_8192US,
    HAL_QDEC_SAMPLEPER_16384US,
    HAL_QDEC_SAMPLEPER_32768US,
    HAL_QDEC_SAMPLEPER_65536US,
    HAL_QDEC_SAMPLEPER_131072US
} hal_qdec_sample_per_t;

/**
 * @if Eng
 * @brief  QDEC debounce number.
 * @else
 * @brief  QDEC防抖阈值
 * @endif
 */
typedef enum {
    HAL_QDEC_DEBOUNCE_NUM_1,
    HAL_QDEC_DEBOUNCE_NUM_2,
    HAL_QDEC_DEBOUNCE_NUM_3,
    HAL_QDEC_DEBOUNCE_NUM_4,
    HAL_QDEC_DEBOUNCE_NUM_5,
    HAL_QDEC_DEBOUNCE_NUM_6,
    HAL_QDEC_DEBOUNCE_NUM_7,
    HAL_QDEC_DEBOUNCE_NUM_8
} hal_qdec_defen_num_t;

/**
 * @if Eng
 * @brief  Active LED polarity.
 * @else
 * @brief  有源LED极性
 * @endif
 */
typedef enum {
    HAL_QDEC_LED_POL_ACTIVE_LOW,
    HAL_QDEC_LED_POL_ACTIVE_HIGH
} hal_qdec_led_pol_t;

/**
 * @if Eng
 * @brief  QDEC events structure.
 * @else
 * @brief  QDEC事件结构体
 * @endif
 */
typedef enum {
    HAL_QDEC_EVENT_STOPPED,             /*!< @if Eng QDEC stop event.
                                             @else   QDEC停止事件 @endif */
    HAL_QDEC_EVENT_ACCOF,               /*!< @if Eng QDEC count event.
                                             @else   QDEC计数事件 @endif */
    HAL_QDEC_EVENT_DBLRDY,              /*!< @if Eng QDEC duouble wheel error event.
                                             @else   QDEC双滚轮错误事件 @endif */
    HAL_QDEC_EVENT_REPORTRDY,           /*!< @if Eng QDEC reporting event.
                                             @else   QDEC样本报告事件 @endif */
    HAL_QDEC_EVENT_SAMPLERDY            /*!< @if Eng QDEC sampling event.
                                             @else   QDEC采样事件 @endif */
} hal_qdec_event_t;

/**
 * @if Eng
 * @brief  QDEC accumulators structure.
 * @else
 * @brief  QDEC计数结构体
 * @endif
 */
typedef enum {
    HAL_QDEC_ACCUMULATOR_ACC_ACCDBL,    /*!< @if Eng Quadrature encoder coded output value.
                                             @else   正交编码器编码输出值 @endif */
    HAL_QDEC_ACCUMULATOR_ACC,           /*!< @if Eng Accumulated value of encoding displacement of quadrature encoder.
                                             @else   正交编码器编码位移累加值 @endif */
    HAL_QDEC_ACCUMULATOR_ACCDBL         /*!< @if Eng Invalid transition sample accumulation.
                                             @else   无效过渡采样累加值 @endif */
} hal_qdec_accumulator_t;

/**
 * @if Eng
 * @brief  QDEC clk type.
 * @else
 * @brief  QDEC时钟类型
 * @endif
 */
typedef enum {
    QDEC_NOR_CLK,                        /*!< @if Eng QDEC 1M clock in normal mode.
                                             @else   QDEC在正常状态为1M时钟 @endif */
    QDEC_NOR_32K_CLK                     /*!< @if Eng QDEC 32K clock in normal mode.
                                             @else   QDEC在正常状态为32K时钟 @endif */
} qdec_clk_type_t;

/**
 * @if Eng
 * @brief  Get the base address of a specified QDEC.
 * @return The base address of specified QDEC.
 * @else
 * @brief  获取指定QDEC的基地址。
 * @return 指定QDEC的基地址。
 * @endif
 */
uintptr_t qdec_porting_base_addr_get(void);

/**
 * @if Eng
 * @brief  Get the base address of a specified QDEC clock driver.
 * @return The base address of specified QDEC clock driver.
 * @else
 * @brief  获取指定QDEC时钟频率寄存器的基地址。
 * @return 指定QDEC时钟频率寄存器的基地址。
 * @endif
 */
uintptr_t qdec_clk_div_porting_base_addr_get(void);

/**
 * @if Eng
 * @brief  Register hal funcs objects into hal_qdec module.
 * @else
 * @brief  将hal funcs对象注册到hal_qdec模块中
 * @endif
 */
void qdec_port_register_hal_funcs(void);

/**
 * @if Eng
 * @brief  Unregister hal funcs objects from hal_qdec module.
 * @else
 * @brief  从hal_qdec模块注销hal funcs对象
 * @endif
 */
void qdec_port_unregister_hal_funcs(void);

/**
 * @if Eng
 * @brief  Initialization qdec register.
 * @else
 * @brief  初始化QDEC寄存器
 * @endif
 */
void qdec_port_regs_init(void);

/**
 * @if Eng
 * @brief  Deinitialization qdec register.
 * @else
 * @brief  去初始化QDEC寄存器
 * @endif
 */
void qdec_port_regs_deinit(void);

/**
 * @if Eng
 * @brief  Register the interrupt of qdec.
 * @else
 * @brief  注册中断
 * @endif
 */
void qdec_port_register_irq(void);

/**
 * @if Eng
 * @brief  Ungister the interrupt of qdec.
 * @else
 * @brief  去注册中断
 * @endif
 */
void qdec_port_unregister_irq(void);

/**
 * @if Eng
 * @brief  Handler of the qdec interrupt request.
 * @else
 * @brief  中断请求处理程序
 * @endif
 */
void qdec_irq_handler(void);

/**
 * @if Eng
 * @brief  Qdec pinmux init.
 * @else
 * @brief  初始化qdec管脚复用
 * @endif
 */
void qdec_port_pinmux_init(pin_t qdec_a, pin_t qdec_b);

/**
 * @if Eng
 * @brief  Qdec clock source conversion between sleep mode and normal mode.
 * @else
 * @brief  qdec的时钟源设置
 * @endif
 */
void qdec_clk_sel_set(qdec_clk_type_t clk_type);

/**
 * @if Eng
 * @brief  QDEC set acc numbers per roll.
 * @else
 * @brief  配置滚轮滚动一次时ACC增加的实际数值
 * @endif
 */
void qdec_port_set_acc_per_roll(uint8_t acc_per_roll);

/**
 * @if Eng
 * @brief  QDEC set acc numbers per roll.
 * @return The actual acc numbers per roll.
 * @else
 * @brief  获取滚轮滚动一次时ACC增加的实际数值
 * @return 滚轮滚动一次时ACC增加的实际数值
 * @endif
 */
uint8_t qdec_port_get_acc_per_roll(void);
/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif