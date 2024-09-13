/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V151 HAL i2c \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-15, Create file. \n
 */

#ifndef HAL_I2C_V151_SLAVE_H
#define HAL_I2C_V151_SLAVE_H


#include <stdint.h>
#include "hal_i2c.h"
#include "hal_i2c_v151_comm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_i2c_v151_slave I2C V151 Slave
 * @ingroup  drivers_hal_i2c
 * @{
 */

/**
 * @if Eng
 * @brief  Initialize I2C bus as slave.
 * @param  [in]  bus The I2C bus. see @ref i2c_bus_t
 * @param  [in]  baudrate Baudrate to configure I2C SCL_CNT, slave is same as msater.
 * @param  [in]  addr I2C slave address.
 * @param  [in]  callback I2C interrupt callback function. see @ref hal_i2c_callback_t
 * @else
 * @brief  初始化I2C作为从机。
 * @param  [in]  bus I2C的索引。参考 @ref i2c_bus_t
 * @param  [in]  baudrate 配置I2C SCL_CNT所使用的波特率,从机与主机一致。
 * @param  [in]  addr I2C从机地址。
 * @param  [in]  callback I2C中断回调函数。参考 @ref hal_i2c_callback_t
 * @endif
 */
errcode_t hal_i2c_v151_slave_init(i2c_bus_t bus, uint32_t baudrate,
                                  uint16_t addr, hal_i2c_callback_t callback);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
