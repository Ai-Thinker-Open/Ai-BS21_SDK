/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  Memory Map configuration
 * Author: @CompanyNameTag
 * Create:  2018-10-15
 */

#ifndef NON_OS_MEMORY_CORE_H
#define NON_OS_MEMORY_CORE_H

#include "stdint.h"
#include "stdbool.h"
#include "platform_types.h"

/** 256 bit SHA for checking validity of the code image(s). Length in BYTES. */
#define CHECKSUM_LEN    32 // (256 / 8)

/**
 * @defgroup connectivity_drivers_non_os_memory_core MEMORY Core
 * @ingroup  connectivity_drivers_non_os
 * @{
 */
/**
 * @brief  Enum defining the available memory regions.
 * Represents a low -power mode for a specified region. to this only region 0 can be used for code,
 * as this is the only region that can address the full 1MB of FLASH.
 * The size of the Regions is different on different core or moudule.
 */
typedef enum {
    MEMORY_POWER_NORMAL = 0x0,      // !< Represents a the region is normal work power mode.
    MEMORY_POWER_LIGHTSLEEP = 0x1,  // !< Represents a the region is lightsleep power mode.but it not be support.
    MEMORY_POWER_DEEPSLEEP = 0x2,   // !< Represents a the region is deepsleep power mode.
    MEMORY_POWER_SHUTDOWN = 0x4,    // !< Represents a the region is shutdown power mode.
    MEMORY_POWER_NONE = 0x5,        // !< Represents a ERROR power mode.
} memory_power_mode_t;

typedef enum {
    MEMORY_STATE_NORMAL,  // !< Represents a the region is normal work state.
    MEMORY_STATE_SLEEP,   // !< Represents a the region is sleep work state.
} memory_state_t;

/**
 * @brief  BCPU RAM timing mode parameter.
 */
typedef enum {
    MEMORY_TIMING_0P8V = 0,
    MEMORY_TIMING_0P9V,
} memory_timing_mode_t;

/**
 * @brief  Memory timing cores.
 */
typedef enum {
    MEMORY_TIMING_DSP,
    MEMORY_TIMING_APP,
    MEMORY_TIMING_SHARE,
    MEMORY_TIMING_TMOD,
    MEMORY_TIMING_MAX,
} memory_timing_core_t;

typedef struct {
    uint32_t code_addr;                      // !< Address of FLASH segment corresponding to the CODE.
    uint32_t code_length;                    // !< Length in bytes of the CODE segment.
    uint32_t code_section_length;            // !< Maximum length of the CODE in the segment.

    uint16_t otp_start;                      // !< Start address of the OTP memory allocated for this core.
    uint16_t otp_length;                     // !< Length in bytes of the OTP memory allocated for this core.

    uint32_t ram_addr;                       // !< Location of this core's local RAM.
    uint32_t ram_length;                     // !< Length in bytes of the local RAM.
} memory_map;

/**
 * @brief  Cache memory maps, from KV store, for all cores
 */
bool memory_cache_all_core_maps(void);

/**
 * @brief  Write a cached memory map back to KV storage
 */
bool memory_write_back_core_map(core_images_e cimage);

/**
 * @brief  Ensure all cached memory maps are written back to KV storage
 */
bool memory_write_back_all_core_maps(void);

/**
 * @brief  Lookup the alias region configuration in KV storage.
 * @param  cimage Specifies which core image is being requested.
 * @return Pointer to data structure containing memory map.
 */
memory_map *memory_get_cached_core_map(core_images_e cimage);

/**
 * @brief  Update the cached CODE region for a given core.
 * @param  cimage Specifies which core image is being requested.
 * @param  start Specifies the physical start address of the mapped region.
 * @param  length Specifies the length (in bytes) of the mapped region.
 * @param  section_length Specifies the maximum possible region length (in bytes) that can be mapped
 */
void memory_update_cached_core_code_region(core_images_e cimage, uint32_t start,
                                           uint32_t length, uint32_t section_length);

/**
 * @brief  Update the cached RAM region for a given core.
 * @param  cimage Specifies which core image is being requested.
 * @param  start Specifies the physical start address of the mapped region.
 * @param  length Specifies the length (in bytes) of the mapped region.
 */
void mem_update_cached_core_ram_region(core_images_e cimage, uint32_t start, uint32_t length);

/**
 * @brief  Update the cached OTP region for a given core.
 * @param  cimage Specifies which core image is being requested.
 * @param  start Specifies the physical start address of the mapped region.
 * @param  length Specifies the length (in bytes) of the mapped region.
 */
void memory_update_cached_core_otp_region(core_images_e cimage, uint16_t start, uint16_t length);

/**
 * @}
 */
#endif
