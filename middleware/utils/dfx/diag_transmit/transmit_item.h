/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: transmit data
 * This file should be changed only infrequently and with great care.
 */
#ifndef TRANSMIT_ITEM_H
#define TRANSMIT_ITEM_H

#include "transmit_st.h"
#include "diag.h"
#include "dfx_adapt_layer.h"
#include "transmit.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define TRANSMIT_OUT_TIME           30 /* 单位秒 */
#define TRANSMIT_RETRY_TIME         1  /* 单位秒 */

#define DEFAULT_TRANSMIT_BLOCK_NUMBER   8       /* 默认每次请求的数据包数量 */
#define DEFAULT_TRANSMIT_BLOCK_SIZE     0x100   /* 默认每个包发送数据最大值 */

typedef enum {
    TRANSMIT_LOCAL_TYPE_SAVE_FILE,
    TRANSMIT_LOCAL_TYPE_READ_FILE,
    TRANSMIT_LOCAL_TYPE_READ_DATA,
    TRANSMIT_LOCAL_TYPE_WRITE_DATA,
    TRANSMIT_LOCAL_TYPE_SAVE_OTA_IMG,
    TRANSMIT_LOCAL_TYPE_READ_OTA_IMG,
} transmit_local_type_t;

typedef enum {
    TRANSMIT_STEP_START,
    TRANSMIT_STEP_TRANSMIT,
} transmit_step_t;

typedef enum {
    TRANSMIT_DISABLE_TIME_OUT,
    TRANSMIT_DISABLE_RECV_INVALID_ID,
    TRANSMIT_DISABLE_RECV_FINISH,
    TRANSMIT_DISABLE_RECV_ALL_DATA,
    TRANSMIT_DISABLE_USER_STOP,
} transmit_disable_reason_t;

typedef struct transmit_item_t {
    uint32_t transmit_id;
    uint32_t used : 1;
    uint32_t init_fail : 1;   /* init fail,may get resource fail */
    uint32_t permanent : 1;   /* not need free resource */
    uint32_t local_start : 1; /* 本地为上位机置1 */
    uint32_t local_src : 1;   /* 本地为源端（数据发送方）置1 */
    uint32_t remote_type : 4; /* see transmit_type_t */
    uint32_t local_type : 4;  /* see transmit_local_type_t */
    uint32_t down_machine : 1;
    uint32_t enable : 1;
    uint32_t step : 2;
    uint32_t re_trans : 1;
    uint32_t pm_veto : 1;
    uint32_t resvered : 13;

    uint16_t data_block_number;     /* 每组传输次数 */
    uint16_t data_block_size;       /* 每次传输数据大小 */
    uint32_t received_size;
    uint32_t request_size;
    uint32_t total_size;
    uintptr_t write_read;   /* see transmit_write_hook and transmit_read_hook */
    uintptr_t usr_wr_data;
    uint32_t bus_addr;
    char *file_name;
    int32_t  file_fd;
    uint32_t expiration;
    uint32_t last_rcv_pkt_time;
    uint32_t last_send_pkt_time;
    diag_option_t option;
    uintptr_t result_hook; /* transmit_result_hook */
} transmit_item_t;

typedef struct {
    uint32_t  id_start;
    uint32_t  id_end;
    uintptr_t hook;
} transmit_msg_proc_t;

typedef int32_t (*transmit_write_hook)(uintptr_t usr_data, uint32_t offset, uint8_t *buf, uint32_t size);
typedef int32_t (*transmit_read_hook)(uintptr_t usr_data, uint32_t offset, uint8_t *buf, uint32_t size);
typedef errcode_t (*transmit_register_hook)(uint32_t msg_id, const uint8_t *msg, uint32_t msg_len);

transmit_item_t *transmit_item_match_id(uint32_t transmit_id);
transmit_item_t *transmit_item_match_type_and_dst(transmit_type_t transmit_type, diag_addr dst);

/* init functions */
transmit_item_t *transmit_item_init(uint32_t transmit_id);

static inline void transmit_item_init_permanent(transmit_item_t *item, bool permanent)
{
    dfx_assert(item);
    item->permanent = permanent;
}

static inline void transmit_item_init_local_start(transmit_item_t *item, bool local_start)
{
    dfx_assert(item);
    item->local_start = local_start;
}

static inline void transmit_item_init_local_src(transmit_item_t *item, bool local_src)
{
    dfx_assert(item);
    item->local_src = local_src;
}

static inline void transmit_item_init_remote_type(transmit_item_t *item, transmit_type_t remote_type)
{
    dfx_assert(item);
    item->remote_type = remote_type;
}

static inline void transmit_item_init_local_type(transmit_item_t *item, transmit_local_type_t local_type)
{
    dfx_assert(item);
    item->local_type = local_type;
}

static inline void transmit_item_init_write_handler(transmit_item_t *item, transmit_write_hook handler,
                                                    uintptr_t usr_data)
{
    dfx_assert(item);
    item->write_read = (uintptr_t)handler;
    item->usr_wr_data = usr_data;
}

static inline void transmit_item_init_read_handler(transmit_item_t *item, transmit_read_hook handler,
                                                   uintptr_t usr_data)
{
    dfx_assert(item);
    item->write_read = (uintptr_t)handler;
    item->usr_wr_data = usr_data;
}

static inline void transmit_item_init_result_handler(transmit_item_t *item, transmit_result_hook handler,
                                                     uintptr_t usr_data)
{
    dfx_assert(item);
    unused(usr_data);
    item->result_hook = (uintptr_t)handler;
}

static inline void transmit_item_init_local_bus_addr(transmit_item_t *item, uint32_t bus_addr)
{
    dfx_assert(item);
    item->bus_addr = bus_addr;
}

void transmit_item_init_file_name(transmit_item_t *item, const char *file_name, uint16_t name_len);

static inline void transmit_item_init_option(transmit_item_t *item, diag_option_t *option)
{
    dfx_assert(item);
    item->option = *option;
}

static inline void transmit_item_init_down_machine(transmit_item_t *item, bool down_machine)
{
    dfx_assert(item);
    item->down_machine = down_machine;
}

static inline void transmit_item_init_received_size(transmit_item_t *item, uint32_t offset)
{
    dfx_assert(item);
    item->received_size = offset;
}

static inline void transmit_item_init_total_size(transmit_item_t *item, uint32_t total_size)
{
    dfx_assert(item);
    item->total_size = total_size;
}

static inline void transmit_item_init_re_trans(transmit_item_t *item, bool re_trans)
{
    dfx_assert(item);
    item->re_trans = re_trans;
}

static inline void transmit_item_init_data_block_size(transmit_item_t *item, uint16_t data_block_size)
{
    dfx_assert(item);
    item->data_block_size = data_block_size;
}

static inline void transmit_item_init_data_block_number(transmit_item_t *item, uint16_t data_block_number)
{
    dfx_assert(item);
    item->data_block_number = data_block_number;
}

static inline bool transmit_item_init_is_success(const transmit_item_t *item)
{
    dfx_assert(item);
    if (item->init_fail != 0) {
        return false;
    }
    return true;
}

void transmit_item_deinit(transmit_item_t *item);

/* en-disable process of this item */
void transmit_item_disable(transmit_item_t *item, transmit_disable_reason_t reason);
void transmit_item_enable(transmit_item_t *item);
void transmit_item_finish(transmit_item_t *item, transmit_disable_reason_t reason);

/* send pkt functions */
errcode_t transmit_send_invalid_id(uint32_t transmit_id, diag_option_t *option, bool down_machine);
errcode_t transmit_send_finish_pkt(uint32_t transmit_id, diag_option_t *option, bool down_machine);
errcode_t transmit_send_failed_pkt(uint32_t transmit_id, diag_option_t *option, bool down_machine);

/* process pkt frame */
void transmit_item_process_notify_frame(transmit_state_notify_pkt_t *pkt, diag_option_t *option,
    bool from_upper_machine);

/* get pkt buf functions */
void *transmit_item_get_pkt_buf(const transmit_item_t *item, uint32_t buf_size);
void transmit_item_free_pkt_buf(const transmit_item_t *item, const void *buf);

errcode_t transmit_item_module_init(void);
#if defined(CONFIG_DFX_SUPPORT_TRANSMIT_FILE_HOOK) && (CONFIG_DFX_SUPPORT_TRANSMIT_FILE_HOOK == DFX_YES)
errcode_t transmit_msg_proc_hook_register(uint32_t msg_id_start, uint32_t msg_id_end, transmit_register_hook hook);
errcode_t transmit_msg_proc_hook_unregister(transmit_register_hook hook);
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* TRANSMIT_ITEM_H */
