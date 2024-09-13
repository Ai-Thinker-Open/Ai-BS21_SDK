/*
 * Copyright (c) CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description: BUILD VERSION INFORMATION API
 * Author:
 * Create:
 */
#ifndef BUILD_VERSION_H
#define BUILD_VERSION_H

#include "stdint.h"
#include "chip_definitions.h"

/**
 * @defgroup connectivity_libs_build_version BUILD Version
 * @ingroup  connectivity_libs
 * @{
 */
/* Change the matching definition in the build system, tools/Scons/VersionInfo.py, when changing this limit */
#define FIRMWARE_VERSION_STRING_MAX_LENGTH 40
#define PARTITION_INFO_STRING_MAX_LENGTH 4

#define FIRMWARE_GIT_HASH_LENGTH   20
#define BUILD_VERSION_INFO_VERSION 2 // ssb image version used in libra rom to avoid verion revert
#define BUILD_VERSION_MAGIC_NUMBER 0x0DD0FECA
#define BUILD_VERSION_CHANGE_ID_STR_HEAD_LEN 4

/* BUILD version identifier */
typedef struct {
    const uint32_t version;
    const uint32_t build_version_info_magic;  // 32-bits to match rom version - could be 16-bits
    const uint16_t build_version_info_version;
    const uint16_t pad;
    const uint32_t epoch;
    const char string[FIRMWARE_VERSION_STRING_MAX_LENGTH];
    const uint16_t partition_info[PARTITION_INFO_STRING_MAX_LENGTH];
    const char hash[FIRMWARE_GIT_HASH_LENGTH];
} build_version_info;

/* BUILD version identifier used for rom */
typedef struct {
    const uint32_t version;
    const uint32_t epoch;
    const char string[];
} build_version_info_rom;

const build_version_info *build_version_get_info(void);

/**
 * @brief  return a pointer to version string
 * @return pointer to version string
 */
const char *get_version_string(void);

/**
 * @brief  return a pointer to git hash
 * @return pointer to git hash or null if not defined
 */
const char *get_git_hash(void);

#if !defined(BUILD_APPLICATION_ROM)
/**
 * @brief  return a pointer to version branch
 * @return pointer to version branch or null if not defined
 */
const char *get_version_branch(void);

/**
 * @brief  return a pointer to version branch
 * @return pointer to version branch or null if not defined
 */
const char *get_version_branch_dsp(void);

/**
 * @brief  return a pointer to version change id
 * @return pointer to version change id or null if not defined
 */
const char *get_version_change_id(void);

/**
 * @brief  return a pointer to dsp version change id
 * @return pointer to version change id or null if not defined
 */
const char *get_version_change_id_dsp(void);

/**
 * @brief  return a pointer to version id
 * @return pointer to version change id or null if not defined
 */
const char *get_version_id(void);

/**
 * @brief  return a pointer to dsp version id
 * @return pointer to version change id or null if not defined
 */
const char *get_version_id_dsp(void);

/**
 * @brief  return a pointer to version build mode
 * @return pointer to version build mode or null if not defined
 */
const char *get_version_build_mode(void);
#endif

const char *uapi_get_sdk_version(void);
const char *uapi_get_version(void);

void uapi_set_ssb_version(uint32_t version);
#if (CHIP_SW39 == 1)
const char *uapi_get_ssb_version(void);
#else
uint16_t uapi_get_ssb_version(void);
#endif

uint16_t uapi_get_ssb_sdk_version(void);

const char *uapi_get_bt_version(void);

/**
 * @}
 */
#endif
