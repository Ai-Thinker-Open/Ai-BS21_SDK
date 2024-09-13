/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: diag usr adapt
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_ADAPT_LAYER_H
#define DIAG_ADAPT_LAYER_H

#include "time.h"
#include "diag_config.h"
#include "diag_common.h"
#include "diag_channel.h"
#include "dfx_adapt_layer.h"

#define DIAG_HSO_MAX_MUX_PKT_SIZE 512
#define DIAG_HSO_VER_DEFAULT 0
#define DIAG_HSO_THIS_VER 0x11

#define USER_CMD_LIST_NUM 10 /* Maximum number of non-system command lists */

static inline uint32_t diag_adapt_get_msg_time(void)
{
    return dfx_get_cur_second();
}

static inline uint64_t diag_adapt_get_msg_time_ms(void)
{
    uint64_t time_ms = (uint64_t)dfx_get_cur_second() * 1000; /* 1 second = 1000 milliseconds */
    return time_ms;
}

uint32_t diag_adapt_get_msg_local_time(void);

static inline errcode_t diag_adapt_sync_tx_sem_wait(void)
{
    return ERRCODE_FAIL;
}

static inline void diag_adapt_sync_tx_sem_signal(void)
{
    return;
}

static inline uint32_t diag_adapt_get_default_dst(void)
{
    return DIAG_FRAME_FID_UART;
}

static inline diag_channel_id_t diag_adapt_addr_2_channel_id(diag_frame_fid_t addr)
{
    if (addr == DIAG_FRAME_FID_UART) {
        return DIAG_CHANNEL_ID_0;
    }
#if defined(CONFIG_BT_UPG_ENABLE) && (CONFIG_BT_UPG_ENABLE == 1)
    if (addr == DIAG_FRAME_FID_BLE_GATT) {
        return DIAG_CHANNEL_ID_1;
    }
#endif
#if defined(CONFIG_SLE_UPG_ENABLE) && (CONFIG_SLE_UPG_ENABLE == 1)
    if (addr == DIAG_FRAME_FID_SLE) {
        return DIAG_CHANNEL_ID_2;
    }
#endif
    return DIAG_CHANNEL_ID_INVALID;
}

static inline diag_frame_fid_t diag_adapt_channel_id_2_addr(diag_channel_id_t id)
{
    if (id == DIAG_CHANNEL_ID_0) {
        return DIAG_FRAME_FID_UART;
    }
#if defined(CONFIG_BT_UPG_ENABLE) && (CONFIG_BT_UPG_ENABLE == 1)
    if (id == DIAG_CHANNEL_ID_1) {
        return DIAG_FRAME_FID_BLE_GATT;
    }
#endif
#if defined(CONFIG_SLE_UPG_ENABLE) && (CONFIG_SLE_UPG_ENABLE == 1)
    if (id == DIAG_CHANNEL_ID_2) {
        return DIAG_FRAME_FID_SLE;
    }
#endif
    return DIAG_FRAME_FID_MAX;
}

static inline diag_frame_fid_t diag_adapt_get_local_addr(void)
{
    return DIAG_FRAME_FID_LOCAL;
}

static inline bool diag_adapt_is_in_unblocking_context(void)
{
    return false;
}

#endif /* DIAG_ADAPT_LAYER_H */
