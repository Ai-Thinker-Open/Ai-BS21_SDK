/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Mouse pin config port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-04-04， Create file. \n
 */

#ifndef MOUSE_SENSOR_PORT_H
#define MOUSE_SENSOR_PORT_H

#include "pinctrl_porting.h"

#undef QDEC_A
#undef QDEC_B

#if defined(PRODUCT_CD26_MOUSE) || defined(PRODUCT_CD23_MOUSE)
#define PIN_LEFT        S_MGPIO17  // S_MGPIO27 is adapted to CD26, currently CD23 is higher priority.
#define PIN_RIGHT       S_MGPIO18  // S_MGPIO19 is adapted to CD26, currently CD23 is higher priority.
#define PIN_MID         S_MGPIO19  // S_MGPIO22 is adapted to CD26, currently CD23 is higher priority.

#define QDEC_A          S_MGPIO9
#define QDEC_B          S_MGPIO10

#define SPI_PIN_MISO    S_MGPIO13
#define SPI_PIN_MOSI    S_MGPIO11
#define SPI_PIN_CLK     S_MGPIO12
#define SPI_PIN_CS      S_MGPIO14

#else
#define PIN_LEFT        S_MGPIO21
#define PIN_RIGHT       S_MGPIO22
#define PIN_MID         S_MGPIO2

#define QDEC_A          S_MGPIO4
#define QDEC_B          S_MGPIO3

#define SPI_PIN_MISO    S_MGPIO31
#define SPI_PIN_MOSI    S_MGPIO30
#define SPI_PIN_CLK     S_MGPIO28
#define SPI_PIN_CS      S_MGPIO27
#endif

#define MOUSE_SPI SPI_BUS_0

#define SPI_PIN_MISO_PINMUX   HAL_PIO_SPI0_RXD
#define SPI_PIN_MOSI_PINMUX   HAL_PIO_SPI0_TXD
#define SPI_PIN_CLK_PINMUX    HAL_PIO_SPI0_SCLK
#define SPI_PIN_CS_PINMUX     HAL_PIO_SPI0_CS0

#endif