/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: transmit header file
 * This file should be changed only infrequently and with great care.
 */
#ifndef __TRANSMIT_ST_H__
#define __TRANSMIT_ST_H__

#include <stdint.h>

typedef enum {
    TRANSMIT_STATE_NOTIFY_INVALID_ID = 10,
    TRANSMIT_STATE_NOTIFY_FINISH,
    TRANSMIT_STATE_NOTIFY_FINISH_2,
    TRANSMIT_STATE_NOTIFY_DUPLICATE_ID,
    TRANSMIT_STATE_NOTIFY_STOP_ID = 16,
    TRANSMIT_STATE_NOTIFY_SAVE_FAILED_ID,
} transmit_state_notify_code_t;

typedef enum {
    TRANSMIT_TYPE_READ_FILE,    /* 读文件，目的端发起START */
    TRANSMIT_TYPE_DUMP,         /* dump内容，目的端发起START */
    TRANSMIT_TYPE_SAVE_FILE,    /* 写通用文件，源端发起START */
    TRANSMIT_TYPE_SAVE_OTA_IMG, /* 写升级文件，源端发起START */
    TRANSMIT_TYPE_READ_MEMORY,  /* 读内存数据，目的端发起START */
    TRANSMIT_TYPE_WRITE_MEMORY, /* 写内存数据，源端发起START */
    TRANSMIT_TYPE_READ_FLASH,   /* 读Flash数据，目的端发起START */
    TRANSMIT_TYPE_WRITE_FLASH,  /* 写Flash数据，源端发起START */
    TRANSMIT_TYPE_MAX,
} transmit_type_t;

typedef struct {
    uint8_t type;
    uint8_t len;
    uint8_t data[0];
} transmit_pkt_tlv_t;

typedef struct {
    uint32_t offset;
    uint32_t size;
} transmit_data_request_item_t;

typedef struct {
    uint32_t transmit_id;
    uint32_t cnt;
    transmit_data_request_item_t item[0];
} transmit_data_request_pkt_t;

typedef struct {
    uint32_t transmit_id;
    uint32_t offset;
    uint32_t size;
    uint8_t data[0];
} transmit_data_reply_pkt_t;

typedef struct {
    uint32_t transmit_id;
    uint32_t state_code; /* see transmit_state_notify_code_t */
    uint32_t len;
    uint8_t data[0];
} transmit_state_notify_pkt_t;

typedef struct {
    uint16_t name_size;       /* 文件名长度或地址长度 */
    uint16_t pad;
    char file_name[0];        /* 文件名或读写地址 */
} transmit_save_info_t; /* transmit type is TRANSMIT_TYPE_SAVE_FILE */

typedef struct {
    uint32_t start_addr;     /* 读取Flash数据的起始地址 */
    uint32_t size;           /* 读取Flash数据的长度 */
} transmit_save_data_info_t; /* transmit type is TRANSMIT_TYPE_READ_FLASH */

typedef struct {
    uint32_t transmit_id;
    uint16_t src_send   : 1;        /* 0 传输方向：上位机发送1，单板发送0 */
    uint16_t struct_ver : 2;        /* 结构体版本 */
    uint16_t re_trans   : 1;        /* 是否使能断电续传，默认为0 */
    uint16_t bitmap_enable : 1;     /* 是否使能位域，默认为0 */
    uint16_t pad        : 11;
    uint16_t transmit_type;         /* transmit_type_t */
    uint32_t total_size;
    uint32_t info_size;
    uint8_t info[0];
} transmit_start_pkt_t;

typedef struct {
    uint32_t transmit_id;
    uint16_t src_send   : 1;        /* 0 传输方向：上位机发送1，单板发送0 */
    uint16_t struct_ver : 2;        /* 结构体版本 */
    uint16_t re_trans   : 1;        /* 是否使能断电续传，默认为0 */
    uint16_t bitmap_enable : 1;     /* 是否使能位域，默认为0 */
    uint16_t pad        : 11;
    uint16_t transmit_type;         /* transmit_type */
    uint32_t total_size;
    uint16_t data_block_number;     /* 每组传输次数 */
    uint16_t data_block_size;       /* 每次传输数据大小 */
    uint32_t info_size;             /* 当前赋值0 */
    uint8_t info[0];
} transmit_negotiate_pkt_t;

typedef struct {
    uint32_t transmit_id;
    uint16_t data_block_number;     /* 每组传输次数 */
    uint16_t data_block_size;       /* 每次传输数据大小 */
    uint32_t info_size;             /* 当前赋值0 */
    uint8_t info[0];
} transmit_negotiate_ack_pkt_t;

typedef struct {
    uint32_t transmit_id;
    uint32_t reason;
} transmit_stop_pkt_t;

#endif
