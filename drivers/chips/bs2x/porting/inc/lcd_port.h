/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: lcd pin config port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-04-04， Create file. \n
 */

#ifndef LCD_SPI_PORT_H
#define LCD_SPI_PORT_H

#include "pinctrl_porting.h"
#include "spi_porting.h"

#define LCD_SPI         SPI_BUS_2

#define SPI_PIN_MISO    S_MGPIO26
#define SPI_PIN_MOSI    S_MGPIO27
#define SPI_PIN_CLK     S_MGPIO28
#define SPI_PIN_CS      S_MGPIO29

#define LCD_TE          S_MGPIO0
#define LCD_RESERT      S_MGPIO1
#define LCD_DC          S_MGPIO2

#define LCD_POWN        S_MGPIO30
#define LCD_BACK        S_MGPIO31

#define SPI_PIN_MISO_PINMUX   HAL_PIO_SPI2_RXD
#define SPI_PIN_MOSI_PINMUX   HAL_PIO_SPI2_TXD
#define SPI_PIN_CLK_PINMUX    HAL_PIO_SPI2_CLK
#define SPI_PIN_CS_PINMUX     HAL_PIO_SPI2_CS0
#define dma_remap(addr) ((addr))

#endif