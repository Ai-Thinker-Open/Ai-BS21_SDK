/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description:  Default memory configurations
 * Author: @CompanyNameTag
 * Create: 2023-02-013
 */
#ifndef MEMORY_CONFIG_H
#define MEMORY_CONFIG_H

#include "memory_config_common.h"

#ifdef SUPPORT_CHIP_N1200
#define BOOT_ROM_DATA_LENGTH 0x118
#else
#define BOOT_ROM_DATA_LENGTH 0
#endif
#endif
