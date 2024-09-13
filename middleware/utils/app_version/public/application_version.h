/*
 * Copyright (c) CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:   Application version table interface.
 * Author:
 * Create:
 */

#ifndef APPLICATION_VERSION_H
#define APPLICATION_VERSION_H
#include <stdint.h>
#include "product.h"
#include "chip_core_definition.h"
#ifdef EPMU_EVENT_SSB_TO_APP
#include "epmu.h"
#endif
/**
 * @defgroup connectivity_libs_app_version APP Version
 * @ingroup  connectivity_libs
 * @{
 */
#define APPLICATION_CORE_FLASH_BUILD  (1u << 31)
#define APPLICATION_CORE_ROM_BUILD    (0u << 31)
#define APPLICATION_CORE_VERSION_MASK 0x7FFFFFFF

/**
 * @brief  Security version return codes
 */
typedef enum {
    APPLICATION_VERSION_RETURN_CODE_SUCCESS,     // The operation completed successfully
    APPLICATION_VERSION_RETURN_CODE_LENGTH,      // The length fields are not as expected
    APPLICATION_VERSION_RETURN_CODE_CHECK_WORD,  // The table contents do not match the check word
} application_version_return_code_t;

#define SSB_VERSION_B180 2
#define SSB_VERSION_B200 3

#define SSB_TO_APPLICATION_LEN                        0
#define SSB_TO_APPLICATION_SSB_VSN                    1
#define SSB_TO_APPLICATION_CHECKSUM                   2
#define SSB_TO_APPLICATION_DATA_START                 3
#define SSB_TO_APPLICATION_CHECKSUM_B180              5
#define SSB_TO_APPLICATION_CHECKSUM_B200_INCOMPATIBLE 6

#define startup_table_get_major_version(x) ((x) >> 16)
#define startup_table_get_minor_version(x) ((x) & 0x00FF)
#define startup_table_set_major_version(x) ((x) << 16)

typedef struct {
    uint32_t ssb_to_application_length;
    uint32_t ssb_to_application_ssb_version;  // must be 3
    uint32_t ssb_to_application_checksum;
    uint32_t ssb_to_application_codeloader_version;  // codeloader version from SSB
    uint32_t ssb_to_application_reboot_cause;
    uint32_t ssb_to_application_security_valid;
    uint32_t ssb_to_application_protocol_valid;
    uint32_t ssb_to_application_mcu_freq;
#ifndef APP_SUPPORT_READ_FLASH_ID
    uint32_t ssb_to_application_flash_id;
    uint32_t ssb_to_application_flash_unique_id;
#endif
#if ((defined EMBED_FLASH_EXIST) && (EMBED_FLASH_EXIST == YES))
    uint32_t ssb_to_application_embed_flash_exist;
#endif
#ifdef EPMU_EVENT_SSB_TO_APP
    epmu_event_t ssb_to_application_epmu_event;
#endif
} startup_table;

#define SSB_TO_BT_MAX sizeof(startup_table)

#if (defined BUILD_APPLICATION_SSB)
/**
 * @brief  Creates the table that the ssb will copy to the security core
 * @param  reboot_cause_var The reason that we reset
 */
void create_ssb_to_application_table(uint32_t reboot_cause_var);

/**
 * @brief  Set the ssb_to_application_security_valid and  ssb_to_application_protocol_valid
 * to security startup arguments table
 */
void set_ssb_to_application_image_vaild(uint32_t security_valid, uint32_t protocol_valid);

/**
 * @brief  Set the ssb_to_application_ssb_freq to startup arguments table
 * @param  ssb_freq The mcu core frequency of ssb.
 */
void set_ssb_to_application_mcu_freq(uint32_t ssb_freq);

/**
 * @brief  Get the ssb to security core table addr and length
 * @param  table_addr The table addr
 * @param  table_length The table length
 */
void get_ssb_application_table(uint32_t **table_addr, uint32_t *table_length);
#endif

/**
 * @brief  Gets a pointer to the security table
 * @return NULL if the table is invalid, non-null for a pointer to the table
 */
startup_table *application_version_get_table(void);

/**
 * @}
 */
#endif
