/*
 * Copyright (c) @CompanyNameMagicTag 2021-2022. All rights reserved.
 * Description: tma525b touch driver.
 * Author: @CompanyNameTag
 * Create: 2022-04-12
 */

#ifndef TMA525B_CTRL_H
#define TMA525B_CTRL_H

#include "stdio.h"
#include "debug_print.h"
#include "stdint.h"
#include "td_base.h"
#include "platform_core.h"
#include "tma525b_touch1.h"

/* host peripheral definitions */
#if CHIP_ASIC
#define TMA525B_I2C_BUS            I2C_BUS_1
#define TMA525B_INT_GPIO           S_AGPIO_R5
#define TMA525B_RESET_GPIO         S_AGPIO_R4
#else
#define TMA525B_I2C_BUS            I2C_BUS_5
#define TMA525B_INT_GPIO           S_MGPIO11
#define TMA525B_RST_REG            0x5600201c
#define TMA525B_RST_HIGH           3
#define TMA525B_RST_LOW            0
#endif

#define TMA525B_I2C_ADDR           0x1c
#define TMA525B_I2C_SPEED          I2C_SPEED_MODE_SS
#define TMA525B_REG_BYTE_LEN       2
#define OFFSET_8_BITS              8
#define TMA525B_REG_WRITE_LEN      4
#define TMA525B_CMD_SEND_LEN       2
#define TMA525B_REG_DATA_LEN       2
#define TMA525B_I2C_TIME_MAX       3

#define TMA525B_I2C_SEND_INDEX0    0
#define TMA525B_I2C_SEND_INDEX1    1
#define TMA525B_I2C_SEND_INDEX2    2
#define TMA525B_I2C_SEND_INDEX3    3
typedef struct {
    uint32_t int_gpio;
    i2c_bus_t i2c_id;
    uint32_t i2c_speed;
} tma525b_ctrl_attr;

typedef ext_errno (*tma525b_bus_init)(tma525b_ctrl_attr *attr);
typedef ext_errno (*tma525b_register_irq)(void *private_data);

typedef struct {
    tma525b_ctrl_attr attr;
    tma525b_bus_init bus_init;
} tma525b_ctrl_ops;

ext_errno tma525b_host_peripheral_init(tma525b_ctrl_attr *attr);
ext_errno tma525b_register_handle(tma525b_ctrl_ops *peri_data, touch_callback func);
ext_errno tma525b_unregister_handle(tma525b_ctrl_ops *peri_data);
ext_errno tma525b_reset(void);
void tma525b_resume_reset(void);
void tma525b_delay(uint32_t ms);

ext_errno tp_i2c_data_read(uint16_t reg_addr, uint8_t *data_buf, uint32_t data_len);
ext_errno tp_i2c_cmd_write(uint16_t cmd);
ext_errno tp_i2c_reg_write(uint16_t reg_addr, uint16_t reg_cfg);
ext_errno tp_i2c_data_write(uint16_t reg_addr, uint8_t *data_buf, uint32_t data_len);

#endif
