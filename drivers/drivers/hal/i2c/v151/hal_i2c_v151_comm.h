/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V151 HAL i2c \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-15, Create file. \n
 */
#ifndef HAL_I2C_V151_COMM_H
#define HAL_I2C_V151_COMM_H

#include <stdint.h>
#include "common_def.h"
#include "hal_i2c.h"
#include "hal_i2c_v151_regs_op.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_i2c_v151_comm I2C V151 Common
 * @ingroup  drivers_hal_i2c
 * @{
 */

#define HAL_I2C_V151_MAX_FIFO_DEEPTH   256      /*!< RX/TX buffer max depth. */
#define HAL_I2C_V151_DEFAULT_FIFO_DEEPTH   8    /*!< RX/TX buffer default depth. */
#define HAL_I2C_V151_MIN_FIFO_DEEPTH   2        /*!< RX/TX buffer min depth. */
#define HAL_I2C_V151_TX_DMA_TL                0x4
#define HAL_I2C_V151_RX_DMA_TL                0x4

/**
 * @if Eng
 * @brief  Definition of I2C addr width.
 * @else
 * @brief  I2C地址位宽定义
 * @endif
 */
typedef enum hal_i2c_v151_addr_width {
    I2C_V151_7_BITS_ADDR,           /*!< @if Eng I2C start transfers in 7-bit addressing mode.
                                         @else   I2C以7位寻址模式开始传输。 @endif */
    I2C_V151_10_BITS_ADDR,          /*!< @if Eng I2C start transfers in 10-bit addressing mode.
                                         @else   I2C以10位寻址模式开始传输。 @endif */
    I2C_V151_INVALID_BITS_ADDR
} hal_i2c_v151_addr_width_t;

/**
 * @if Eng
 * @brief  Definition of I2C addr type.
 * @else
 * @brief  I2C地址类型定义
 * @endif
 */
typedef enum hal_i2c_v151_addr_type {
    I2C_V151_ADDR_TYPE_FOR_GC,           /*!< @if Eng I2C genernal call address, only invalid for receive.
                                              @else   I2C广播地址，只读。 @endif */
    I2C_V151_ADDR_TYPE_FOR_CBUS,         /*!< @if Eng I2C cbus address, v151_i2c ignores these accesses.
                                              @else   I2Ccbus 地址，v151 不响应。 @endif */
    I2C_V151_ADDR_TYPE_FOR_HS_MODE,      /*!< @if Eng I2C hs mode code, can't used for target address.
                                              @else   I2C高速模式的码子，不能用于目标地址。 @endif */
    I2C_V151_ADDR_TYPE_FOR_I2C_TARGET,   /*!< @if Eng I2C valid target address .
                                              @else   I2C有效的目标地址。 @endif */
    I2C_V151_ADDR_TYPE_FOR_RESERVED,     /*!< @if Eng I2C reserved address, make sure I2C components support.
                                              @else   I2C的保留地址，v151不限制使用，但需要确保总线上其余组件的兼容。 @endif */
    I2C_V151_ADDR_TYPE_INVALID           /*!< @if Eng I2C invalid address, can't be used.
                                              @else   I2C的无效地址，不可使用。 @endif */
} hal_i2c_v151_addr_type_t;

/**
 * @if Eng
 * @brief  Definition of I2C addr permission.
 * @else
 * @brief  I2C地址操作权限
 * @endif
 */
typedef enum hal_i2c_v151_addr_permission {
    I2C_V151_ADDR_PERMISION_INVALID,     /*!< @if Eng I2C invalid address.
                                         @else   I2C无效地址。 @endif */
    I2C_V151_ADDR_PERMISION_MASTER = 1 << 0,
                                    /*!< @if Eng I2C adress send permission, invalid for general call.
                                         @else   I2C是否可以往该地址进行发送，对于广播模式是无效的。 @endif */
    I2C_V151_ADDR_PERMISION_SLAVE = 1 << 1,
                                    /*!< @if Eng I2C adress receive permission, invalid for CBUS.
                                         @else   I2C是否可以从该地址接收数据，对于CBUS是无效的。 @endif */
    I2C_V151_ADDR_PERMISION_MASTER_SLAVE = I2C_V151_ADDR_PERMISION_MASTER | I2C_V151_ADDR_PERMISION_SLAVE
                                    /*!< @if Eng I2C adress send and receive permission.
                                         @else   I2C可以从该地址发送和接收数据。 @endif */
} hal_i2c_v151_addr_permission_t;

/**
 * @if Eng
 * @brief  Definition of I2C addr region.
 * @else
 * @brief  I2C的地址区间
 * @endif
 */
typedef struct hal_i2c_v151_addr_region {
    uint16_t min_addr;              /*!< @if Eng I2C min value of addr region, include this.
                                         @else   I2C的地址区间的最小值，包含此值。 @endif */
    uint16_t max_addr;              /*!< @if Eng I2C max value of addr region, include this.
                                         @else   I2C的地址区间的最大值，包含此值。 @endif */
} hal_i2c_v151_addr_region_t;

/**
 * @if Eng
 * @brief  Definition of I2C scl min value.
 * @else
 * @brief  I2C的scl的最小值
 * @endif
 */
typedef struct hal_i2c_v151_scl_region {
    uint16_t lcnt;                  /*!< @if Eng I2C min value of scl lcnt.
                                         @else   I2C的lcnt的最小值, 包含此值 @endif */
    uint16_t hcnt;                  /*!< @if Eng I2C min value of scl hcnt.
                                         @else   I2C的hcnt的最小值, 包含此值 @endif */
} hal_i2c_v151_scl_region_t;

/**
 * @if Eng
 * @brief  Definition of I2C addr attr.
 * @else
 * @brief  I2C的地址属性
 * @endif
 */
typedef struct hal_i2c_v151_addr_attr {
    uint8_t type;                   /*!< @if Eng I2C address type. see @ref hal_i2c_v151_addr_type_t
                                         @else   I2C的地址类型。参考 @ref hal_i2c_v151_addr_type_t @endif */
    uint8_t width;                  /*!< @if Eng I2C address width. see @ref hal_i2c_v151_addr_width_t
                                         @else   I2C的地址位宽。参考 @ref hal_i2c_v151_addr_width_t @endif */
    uint8_t permission;             /*!< @if Eng I2C address permission. see @ref hal_i2c_v151_addr_permission_t
                                         @else   I2C的地址操作权限。参考 @ref hal_i2c_v151_addr_permission_t @endif */
    uint8_t res;
} hal_i2c_v151_addr_attr_t;

/**
 * @if Eng
 * @brief  Definition of I2C address region attr.
 * @else
 * @brief  I2C的地址区间属性
 * @endif
 */
typedef struct hal_i2c_v151_addr_region_attr {
    hal_i2c_v151_addr_region_t region;   /*!< @if Eng I2C address region. @ref hal_i2c_v151_addr_region_t.
                                         @else   I2C 的地址区间。参考 @ref hal_i2c_v151_addr_region_t @endif */
    hal_i2c_v151_addr_attr_t attr;       /*!< @if Eng I2C address attr. @ref hal_i2c_v151_addr_attr_t.
                                         @else   I2C 的地址属性。参考 @ref hal_i2c_v151_addr_attr_t @endif */
} hal_i2c_v151_addr_region_attr_t;

/**
 * @if Eng
 * @brief  Definition of I2C addr cfg attr.
 * @else
 * @brief  I2C的地址配置属性
 * @endif
 */
typedef struct hal_i2c_v151_addr_cfg_attr {
    uint16_t real_addr;             /*!< @if Eng I2C real value of address.
                                         @else   I2C地址识别的真实值。 @endif */
    uint8_t addr_type;              /*!< @if Eng I2C address type. @ref hal_i2c_v151_addr_type_t
                                         @else   I2C的地址类型。参考 @ref hal_i2c_v151_addr_type_t @endif */
    uint8_t addr_width;             /*!< @if Eng I2C address width. @ref hal_i2c_v151_addr_width_t
                                         @else   I2C的地址位宽。参考 @ref hal_i2c_v151_addr_width_t @endif */
} hal_i2c_v151_addr_cfg_attr_t;

/**
 * @if Eng
 * @brief  Definition of I2C scl cnt calc input.
 * @else
 * @brief  I2C的计算scl cnt的入参数据结构定义
 * @endif
 */
typedef struct hal_i2c_v151_scl_cnt_calc_input {
    uint32_t freq;                  /*!< @if Eng I2C clk frequency.
                                         @else   I2C的时钟频率。 @endif */
    uint32_t speed_mode;            /*!< @if Eng I2C speed mode.
                                         @else   I2C的速率模式 @endif */
    uint32_t baudrate;              /*!< @if Eng I2C baudrate.
                                         @else   I2C的波特率 @endif */
} hal_i2c_v151_scl_cnt_calc_input_t;

/**
 * @if Eng
 * @brief  Definition of I2C scl cnt calc output.
 * @else
 * @brief  I2C的计算scl cnt的出参数据结构定义
 * @endif
 */
typedef struct hal_i2c_v151_scl_cnt_calc_output {
    uint32_t hcnt;                  /*!< @if Eng I2C scl high count.
                                         @else   I2C SCL的高时钟计数。 @endif */
    uint32_t lcnt;                  /*!< @if Eng I2C scl low count.
                                         @else   I2C SCL的低时钟计数。 @endif */
} hal_i2c_v151_scl_cnt_calc_output_t;

/**
 * @if Eng
 * @brief  Definition of hal I2C ctrl information.
 * @else
 * @brief  HAL层I2C的控制信息数据结构定义
 * @endif
 */
typedef struct hal_i2c_v151_ctrl_info {
    uint16_t rx_tl;                 /*!< @if Eng I2C rx fifo waterline.
                                         @else   I2C rx fifo 水线。 @endif */
    uint16_t tx_tl;                 /*!< @if Eng I2C tx fifo waterline.
                                         @else   I2C tx fifo 水线。 @endif */
    uint16_t rx_fifo_max_deepth;    /*!< @if Eng I2C rx fifo max deepth.
                                         @else   I2C rx fifo 最大深度。 @endif */
    uint16_t tx_fifo_max_deepth;    /*!< @if Eng I2C tx fifo max deepth.
                                         @else   I2C tx fifo 最大深度。 @endif */
    uint8_t write_operate_type;     /*!< @if Eng I2C current write operate type.
                                         @else   I2C 当前的写数据方式。 @endif */
    uint8_t read_operate_type;      /*!< @if Eng I2C current read operate type.
                                         @else   I2C 当前的读数据方式。 @endif */
} hal_i2c_v151_ctrl_info_t;

/**
 * @if Eng
 * @brief  Control interface for hal I2C.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param Parameter pointer for callback.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  HAL层I2C控制接口。
 * @param  [in]  bus I2C索引。参考 @ref i2c_bus_t
 * @param  [in]  param 传递给控制回调的参数指针。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
typedef errcode_t (*hal_i2c_inner_ctrl_t)(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Load the I2C control handler.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  func_table The I2C ctrl function table. see @ref hal_i2c_inner_ctrl_t
 * @else
 * @brief  加载I2C的控制函数。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  func_table i2c的控制函数表。参考 @ref hal_i2c_inner_ctrl_t
 * @endif
 */
void hal_i2c_v151_load_ctrl_func(i2c_bus_t bus, hal_i2c_inner_ctrl_t *func_table);

/**
 * @if Eng
 * @brief  Unload the I2C ctrl handler.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  卸载I2C的控制函数。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_unload_ctrl_func(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Get the I2C control information.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @return The pointer of I2C control information. see @ref hal_i2c_v151_ctrl_info_t
 * @else
 * @brief  获取I2C控制信息数据。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @return I2C控制信息数据指针。参考 @ref hal_i2c_v151_ctrl_info_t
 * @endif
 */
hal_i2c_v151_ctrl_info_t *hal_i2c_v151_get_ctrl_info(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Register I2C callback function.
 * @param  [in]  callback The I2C callback function. see @ref hal_i2c_callback_t
 * @else
 * @brief  注册I2C回调函数。
 * @param  [in]  callback I2C回调函数。参考 @ref hal_i2c_callback_t
 * @endif
 */
void hal_i2c_v151_register_callback(hal_i2c_callback_t callback);

/**
 * @if Eng
 * @brief  Get I2C address configuration attribute.
 * @param  [in]  addr The I2C address.
 * @param  [in]  permission The I2C address permission. see @ref hal_i2c_v151_addr_permission_t
 * @param  [in]  cfg_attr The I2C address configuration attribute. see @ref hal_i2c_v151_addr_cfg_attr_t
 * @return The value of whether the address and permission match.
 *         - true: match and get configuration attribute
 *         - false: not match, can not get configuration attribute
 * @else
 * @brief  获取I2C地址配置属性。
 * @param  [in]  addr I2C地址。
 * @param  [in]  permission I2C地址的权限。参考 @ref hal_i2c_v151_addr_permission_t
 * @param  [in]  cfg_attr I2C地址的配置属性指针。参考 @ref hal_i2c_v151_addr_cfg_attr_t
 * @return 地址和权限是否匹配。
 *         - true：匹配并且可以获得配置属性
 *         - false：不匹配并且无法获得配置属性
 * @endif
 */
bool hal_i2c_v151_get_address_cfg(uint16_t addr, hal_i2c_v151_addr_permission_t permission,
                                  hal_i2c_v151_addr_cfg_attr_t *cfg_attr);

/**
 * @if Eng
 * @brief  Handler of the I2C interrupt request.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断处理函数。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_irq_handler(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Clear all I2C interrupt.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  清除所有I2C的中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_com_clr_int(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Unmask interrupts before I2C interrupt transfer.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断传输前打开中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_com_prepare_int(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Mask interrupts after I2C interrupt transfer.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断传输后屏蔽中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_com_restore_int(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Unmask interrupts before I2C send in interrupt mode.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断模式下发送数据前打开中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_prepare_int_tx(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Mask interrupts after I2C send in interrupt mode.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断模式下发送数据后屏蔽中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_restore_int_tx(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Unmask interrupts before I2C receive in interrupt mode.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断模式下接收数据前打开中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_prepare_int_rx(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Mask interrupts after I2C receive in interrupt mode
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  I2C中断模式下接收数据后屏蔽中断。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_restore_int_rx(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Update receive threshold level.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  rx_tl Receive threshold level.
 * @else
 * @brief  更新接收阈值。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  rx_tl 接收阈值。
 * @endif
 */
void hal_i2c_v151_update_rx_tl(i2c_bus_t bus, uint32_t rx_tl);

/**
 * @if Eng
 * @brief  Check I2C tx status.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param Record transmit abort status pointer.
 *               - 0: not abort
 *               - 1: abort
 * @retval ERRCODE_SUCC Success.
 * @else
 * @brief  检查发送异常状态。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 记录发送异常状态指针。
 *               - 0：正常
 *               - 1：异常
 * @retval ERRCODE_SUCC 成功。
 * @endif
 */
errcode_t hal_i2c_v151_check_transmit_abrt(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Get the number byte can be sent.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param The pointer of recording send number.
 * @retval ERRCODE_SUCC Success.
 * @else
 * @brief  获取可以发送的字节数
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 记录可以发送的字节个数的指针。
 * @retval ERRCODE_SUCC 成功。
 * @endif
 */
errcode_t hal_i2c_v151_get_write_num(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Get the number byte can be read.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param The pointer of recording read number.
 * @retval ERRCODE_SUCC Success.
 * @else
 * @brief  获取可以读取的字节数。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 记录可以读取的字节个数的指针。
 * @retval ERRCODE_SUCC 成功。
 * @endif
 */
errcode_t hal_i2c_v151_get_read_num(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Check receive available status.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param The pointer of recording receive available status.
 * @retval ERRCODE_SUCC Success.
 * @else
 * @brief  检查接收数据状态。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 记录是否可以接收数据状态的指针。
 * @retval ERRCODE_SUCC 成功。
 * @endif
 */
errcode_t hal_i2c_v151_check_rx_available(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Check tx transmit end status.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param The pointer of recording tx transmit end status.
 * @retval ERRCODE_SUCC Success.
 * @else
 * @brief  检查发送结束状态。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 记录是否发送结束的指针
 * @retval ERRCODE_SUCC 成功。
 * @endif
 */
errcode_t hal_i2c_v151_check_tx_transmit_end(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Deinitialize I2C bus.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @retval ERRCODE_SUCC Success.
 * @else
 * @brief  去初始化I2C。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @retval ERRCODE_SUCC 成功。
 * @endif
 */
errcode_t hal_i2c_v151_deinit(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  I2C bus write.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  data Send data buffer and send attribute. see @ref hal_i2c_buffer_wrap_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  I2C发送数据。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  data 要发送的数据及发送的属性。参考 @ref hal_i2c_buffer_wrap_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_i2c_v151_write(i2c_bus_t bus, hal_i2c_buffer_wrap_t *data);

/**
 * @if Eng
 * @brief  I2C bus read.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  data Read data buffer and Read attribute. see @ref hal_i2c_buffer_wrap_t
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  I2C读取数据。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  data 要读取的数据及读取的属性。参考 @ref hal_i2c_buffer_wrap_t
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_i2c_v151_read(i2c_bus_t bus, hal_i2c_buffer_wrap_t *data);

/**
 * @if Eng
 * @brief  I2C control according to control id.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  id I2C control ID. see @ref hal_i2c_ctrl_id_t
 * @param  [in]  param The pointer to record.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  根据控制ID执行I2C控制。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  id I2C控制ID。
 * @param  [in]  param 用于记录的指针。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_i2c_v151_ctrl(i2c_bus_t bus, hal_i2c_ctrl_id_t id, uintptr_t param);

/**
 * @if Eng
 * @brief  Initialize I2C component parameter.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @else
 * @brief  初始化I2C组件参数。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @endif
 */
void hal_i2c_v151_init_comp_param(i2c_bus_t bus);

/**
 * @if Eng
 * @brief  Get I2C data register.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param The pointer to record.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  获取I2C数据寄存器。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 用于记录的指针
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_i2c_v151_get_data_addr(i2c_bus_t bus, uintptr_t param);

/**
 * @if Eng
 * @brief  Get I2C data register.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  param The pointer to record.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  获取I2C数据寄存器。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  param 用于记录的指针
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_i2c_v151_check_tx_fifo_empty(i2c_bus_t bus, uintptr_t param);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
