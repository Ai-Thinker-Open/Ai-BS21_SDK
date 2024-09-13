/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  BT KEY VALUE NON VOLATILE STORAGE MODULE INTERFACE
 * Author: @CompanyNameTag
 * Create:
 */

#ifndef BT_CONFIG_H
#define BT_CONFIG_H

/**
 * @defgroup connectivity_drivers_non_os_config SEC Config
 * @ingroup  connectivity_drivers_non_os
 * @{
 */
/**
 * @brief  Security config driver API return values
 */
typedef enum {
    BT_CONFIG_RET_OK,
    BT_CONFIG_RET_ERROR,
} security_config_ret;

/**
 * @brief  Store a key
 * @param  key key to associate kvalue to
 * @param  kvalue value to store
 * @param  kvalue_length length of kvalue in bytes
 * @return BT_CONFIG_RET_OK or an error code
 */
security_config_ret security_config_set(uint16_t key, const uint8_t *kvalue, uint16_t kvalue_length);

/**
 * @brief  Get a value associated with a specific key in a group
 * @param  key key of the value to get
 * @param  kvalue the pointer to the kvalue is returned here
 * @param  kvalue_max_length max length of the kvalue
 * @param  kvalue_length length of the value
 * @return BT_CONFIG_RET_OK or an error code
 */
security_config_ret security_config_get(uint16_t key, uint8_t *kvalue,
                                        uint16_t kvalue_max_length, uint16_t *kvalue_length);

/**
 * @}
 */
#endif
