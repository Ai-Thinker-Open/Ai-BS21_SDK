/*
 * Copyright (c) @CompanyNameMagicTag 2021-2022. All rights reserved.
 * Description: ztw523 touch driver.
 * Author: @CompanyNameTag
 * Create: 2022-04-12
 */

#ifndef ZTW523_CTRL_H
#define ZTW523_CTRL_H

#include "stdio.h"
#include "debug_print.h"
#include "stdint.h"
#include "td_base.h"
#include "platform_core.h"
#include "ztw523_touch1.h"

/* host peripheral definitions */
#if CHIP_ASIC
#define ZTW523_I2C_BUS            I2C_BUS_1
#define ZTW523_INT_GPIO           S_AGPIO_R5
#define ZTW523_RESET_GPIO         S_AGPIO_R4
#else
#define ZTW523_I2C_BUS            I2C_BUS_5
#define ZTW523_INT_GPIO           S_MGPIO11
#define ZTW523_RST_REG            0x5600201c
#define ZTW523_RST_HIGH           3
#define ZTW523_RST_LOW            0
#endif

#define ZTW523_I2C_ADDR           0x20
#define ZTW523_I2C_SPEED          I2C_SPEED_MODE_SS
#define ZTW523_REG_BYTE_LEN       2
#define OFFSET_8_BITS             8
#define ZTW523_REG_WRITE_LEN      4
#define ZTW523_CMD_SEND_LEN       2
#define ZTW523_REG_DATA_LEN       2
#define ZTW523_I2C_TIME_MAX       3

#define ZTW523_I2C_SEND_INDEX0    0
#define ZTW523_I2C_SEND_INDEX1    1
#define ZTW523_I2C_SEND_INDEX2    2
#define ZTW523_I2C_SEND_INDEX3    3
typedef struct {
    uint32_t int_gpio;
    i2c_bus_t i2c_id;
    uint32_t i2c_speed;
} ztw523_ctrl_attr;

typedef ext_errno (*ztw523_bus_init)(ztw523_ctrl_attr *attr);

typedef struct {
    ztw523_ctrl_attr attr;
    ztw523_bus_init bus_init;
} ztw523_ctrl_ops;

ext_errno ztw523_host_peripheral_init(ztw523_ctrl_attr *attr);
ext_errno ztw523_register_handle(const ztw523_ctrl_ops *peri_data, touch_callback func);
ext_errno ztw523_unregister_handle(const ztw523_ctrl_ops *peri_data);
ext_errno ztw523_reset(void);
void ztw523_resume_reset(void);
void ztw523_delay(uint32_t ms);

ext_errno tp_i2c_data_read(uint16_t reg_addr, uint8_t *data_buf, uint32_t data_len);
ext_errno tp_i2c_cmd_write(uint16_t cmd);
ext_errno tp_i2c_reg_write(uint16_t reg_addr, uint16_t reg_cfg);
ext_errno tp_i2c_data_write(uint16_t reg_addr, uint8_t *data_buf, uint32_t data_len);

#endif
