/*
 * Copyright (c) @CompanyNameMagicTag 2019-2020. All rights reserved.
 * File          ux_secure.h
 * Description:  Audio ux common secure interface
 */

#ifndef __UX_SECURE_H__
#define __UX_SECURE_H__

#include <autoconf.h>
#include <los_typedef.h>
#include "bt_device.h"
#include "hearing_aid_key_struct.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define SIGNATURE_SIZE               32
#define AES_BLOCK_SIZE               16
#define KV_KEY_SIZE                  64
#define BT_ADDR_PADDING_SIZE         16
#define ROOT_KEY_SIZE                16
#define UX_ERROR_CODE_READ_IV_FAILED (-2)
#define UX_UNUSED_PD_INDEX           (-1) // use in ux_decrypt_and_check_link_key when decrypt paired info
#define HA_SEC_IV_LEN                16
#define HA_SEC_WORKKEY_LEN           16

#ifdef CONFIG_SEC_ADV_KEY
#define ADV_KEY_PADDING_SIZE         48
#define ADV_KEY_SIGN_SIZE            32

#define PROPERTY_KEY_ADV_KEY_INFO      "system.sec_adv_key.info"
#define PROPERTY_KEY_ADV_KEY_SIGN_IV   "system.sec_adv_key.sign_iv"

typedef struct {
    uint8_t adv_key_sign[ADV_KEY_SIGN_SIZE];
    uint8_t adv_key_iv[HA_SEC_IV_LEN];
} ux_enc_and_dec_adv_key_sign_andlv;
#endif

#define PROPERTY_KEY_OLD_BT_NAME      "system.btname"
#define PROPERTY_KEY_BT_NAME          "user.btname"

typedef struct {
    CHAR enc_device_name[DEVICE_NAME_LEN];
    uint32_t name_size;
    uint32_t time_stamp;
    uint8_t iv[HA_SEC_IV_LEN];
} enc_device_name_info;

int32_t ux_encrypt_linkkey(UINT8* link_key, UINT8* enc_link_key, int32_t index,
    const uint8_t *pdl_work_key, uint32_t work_key_len);
int32_t ux_decrypt_and_check_link_key(UINT8* enc_link_key, UINT8* dec_link_key, int32_t index,
    const uint8_t *pdl_work_key, uint32_t work_key_len);
int32_t ux_encrypt_bt_addr(UINT8* bt_addr, UINT8* enc_bt_addr, int32_t index,
    const uint8_t *pdl_work_key, uint32_t work_key_len);
int32_t ux_decrypt_and_check_bt_addr(UINT8* bt_addr, int32_t index, const uint8_t *pdl_work_key, uint32_t work_key_len);
uint32_t ux_decrypt_link_key_and_bt_addr(service_to_bt_pd_data *pd_data, int32_t index,
    const uint8_t *pdl_work_key, uint32_t work_key_len);

/*
 * 1. param 'len' must be equal to DEVICE_NAME_LEN.
 * 2. time_stamp can be set to NULL, if you don't care about it.
 * 3. once the interface return SUCCESS, 'deviceName' must be a string ending with '\0'.
 */

int32_t ux_read_device_name(char *device_name, uint32_t len, uint32_t *timestamp);
int32_t ux_read_device_ble_name(char *device_name, uint32_t len);
errcode_t ux_read_ble_expand_val(ble_expand_t *expand_val);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif
