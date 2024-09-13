/*
 * Copyright (c) CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: diag secure.
 * This file should be changed only infrequently and with great care.
 */
#ifndef DIAG_SECURE_H
#define DIAG_SECURE_H
#ifdef CONFIG_DIAG_WITH_SECURE
#include "errcode.h"
#include "diag.h"
#include "srp.h"
#include "mbedtls/aes.h"
#include "mbedtls/gcm.h"
#include "stdio.h"
#include "dfx_adapt_layer.h"
#ifndef DIAG_SECURE_TEST
#define DIAG_SECURE_TEST 1
#endif

#define CONN_FSM_NONE 0
#define CONN_FSM_WAIT_PUB_A 1
#define CONN_FSM_WAIT_REQ_M1 2
#define CONN_FSM_WAIT_CONN 3
#define CONN_FSM_CONNECTED 4
#define CONN_FSM_WAIT_HEART_BEAT_CNF 5

#define AES_GCM_IV_LENGTH 12
#define AES_GCM_TAG_LENGTH 16
#define AES_GCM_EXT_SIZE (AES_GCM_IV_LENGTH + AES_GCM_TAG_LENGTH)
#define AES128_KEY_LEN 16
#define AES256_KEY_LEN 32

#define SRP_RANDOM_SIZE 32

typedef struct {
    bignum *pub_a;
    bignum *pub_b;
    bignum *rand_b;
    uint8_t key[AES128_KEY_LEN];
    uint8_t conn_fsm;
    uint8_t pad1;
    uint16_t pad2;
} diag_conn_srp_info_t;

#define DIAG_CONN_AUTH_MAX_TRY_TIME 5
#define DIAG_CONN_AUTH_MAX_LOCK_SEC 300
#define DIAG_SECURE_SRP_TIMEOUT (5 * 1000) /* ms */
typedef struct {
    bool is_locked;   /* is locked */
    uint8_t max_try_times; /* max try times */
    uint8_t cur_try_times; /* current fail times */
    uint8_t pad1;          /* pad1 */
    uint16_t max_lock_sec; /* max lock time */
    uint16_t pad2;         /* pad2 */
    uint32_t lock_sec;     /* begin lock time */
} diag_conn_auth_ctrl_ctx_t;

typedef struct {
    diag_conn_srp_info_t srp_info;
    diag_conn_auth_ctrl_ctx_t auth_ctrl_ctx;
    mbedtls_gcm_context gcm_ctx;
    dfx_timer diag_secure_timer;
    bool init_flag;
} diag_secure_ctx_t;

diag_secure_ctx_t *diag_get_secure_ctx(void);
errcode_t diag_secure_ctx_init(void);
void diag_secure_ctx_deinit(void);
bool diag_need_secure(uint16_t cmd_id);
void diag_srp_connect_info_reset(void);
uint32_t diag_aes_gcm_setkey(uint8_t *aes_key, uint32_t aes_key_len);
uint32_t diag_aes_gcm_encrypt_inplace(uint8_t *plain_data, uint32_t data_len,
    uint8_t out_iv[AES_GCM_IV_LENGTH], uint8_t out_tag[AES_GCM_TAG_LENGTH]);
uint32_t diag_aes_gcm_decrypt_inplace(uint8_t *secure_data, uint32_t data_len,
    uint8_t in_iv[AES_GCM_IV_LENGTH], uint8_t in_tag[AES_GCM_TAG_LENGTH]);
#endif
#endif