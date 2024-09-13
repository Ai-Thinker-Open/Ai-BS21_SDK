/*
 * Copyright (c) @CompanyNameMagicTag 2018-2023. All rights reserved.
 * Description:  CLOCKS TYPES HEADER
 * Author: @CompanyNameTag
 * Create:
 */
#ifndef CLOCKS_TYPES_H
#define CLOCKS_TYPES_H

#include <stdint.h>
#include "chip_core_definition.h"
#include "chip_definitions.h"

/** @addtogroup connectivity_drivers_non_os_clocks_core
  * @{
  */
/**
 * @brief  Clock div cfg define
 */
#define CLOCK_DIV_0     0
#define CLOCK_DIV_1     1
#define CLOCK_DIV_2     2
#define CLOCK_DIV_3     3
#define CLOCK_DIV_4     4
#define CLOCK_DIV_5     5
#define CLOCK_DIV_6     6
#define CLOCK_DIV_7     7
#define CLOCK_DIV_8     8
#define CLOCK_DIV_9     9
#define CLOCK_DIV_10    10

/**
 * @brief System clock config enum.
 */
typedef enum {
    CLOCKS_ALL_TCXO_32M,
    CLOCKS_ALL_TCXO_64M,
    CLOCKS_CONFIG_MAX,
} system_clocks_config_t;

/**
  * @}
  */
#endif
