/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: zdiag dfx
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_DFX_H
#define DIAG_DFX_H

#include "errcode.h"
#include "diag_dfx_st.h"
#include "diag.h"
#include "dfx_feature_config.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
diag_dfx_stat_t *uapi_diag_get_dfx_stat(void);
#endif

static inline void diag_dfx_channel_receive_data(uint32_t chan_id, uint32_t cnt)
{
    unused(chan_id);
    unused(cnt);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    if (chan_id < DIAG_DFX_SUPPORT_MAX_CHANNEL) {
        dfx_stat->channel_receive_data_cnt[chan_id] += cnt;
    }
#endif
}

static inline void diag_dfx_channel_receive_frame(uint32_t chan_id, uint32_t cnt)
{
    unused(chan_id);
    unused(cnt);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    if (chan_id < DIAG_DFX_SUPPORT_MAX_CHANNEL) {
        dfx_stat->channel_receive_frame_cnt[chan_id] += cnt;
    }
#endif
}

static inline void diag_dfx_alloc_pkt(uint32_t pkt_type, uint32_t size)
{
    unused(pkt_type);
    unused(size);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    if (pkt_type < DIAG_DFX_SUPPORT_MAX_PKT_MEM_TYPE) {
        dfx_stat->mem_pkt_alloc_size[pkt_type] += size;
    }
#endif
}

static inline void diag_dfx_free_pkt(uint32_t pkt_type, uint32_t size)
{
    unused(pkt_type);
    unused(size);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    if (pkt_type < DIAG_DFX_SUPPORT_MAX_PKT_MEM_TYPE) {
        dfx_stat->mem_pkt_free_size[pkt_type] += size;
    }
#endif
}

static inline void zdiag_dfx_put_msg_2_cache_fail(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->put_msg_2_cache_fail_times++;
#endif
}

static inline void diag_dfx_msg_process_time(uint32_t time)
{
    unused(time);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    if (dfx_stat->dfx_msg_process_max_time < time) {
        dfx_stat->dfx_msg_process_max_time = time;
    }
#endif
}

static inline void diag_transmit_msg_process_time(uint32_t time)
{
    unused(time);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    if (dfx_stat->transmit_msg_process_max_time < time) {
        dfx_stat->transmit_msg_process_max_time = time;
    }
#endif
}

static inline void zdiag_dfx_send_local_q_success(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->send_local_q_success++;
#endif
}

static inline void zdiag_dfx_send_local_q_fail(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->send_local_q_fail++;
#endif
}

static inline void zdiag_dfx_rev_msg(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->msg_rev_cnt++;
#endif
}

static inline void diag_dfx_transmit_rev_msg(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->transmit_msg_rev_cnt++;
#endif
}

static inline void zdiag_dfx_rev_pkt_msg(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->diag_pkt_msg_rev_cnt++;
#endif
}

static inline void zdiag_dfx_rev_beat_herat_msg(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->beat_heart_msg_rev_cnt++;
#endif
}

static inline void zdiag_dfx_conn_except(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->conn_excep_cnt++;
#endif
}

static inline void zdiag_dfx_conn_bu_inc(void)
{
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->conn_bu_cnt++;
#endif
}

static inline void diag_dfx_mem_alloc(uint32_t size)
{
    unused(size);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->alloc_mem_size += size;
    if (dfx_stat->alloc_mem_size > dfx_stat->alloc_mem_peak_size) {
        dfx_stat->alloc_mem_peak_size = dfx_stat->alloc_mem_size;
    }
#endif
}

static inline void diag_dfx_mem_free(uint32_t size)
{
    unused(size);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->alloc_mem_size -= size;
#endif
}

static inline void diag_dfx_current_msg_num(uint16_t msg_num)
{
    unused(msg_num);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->dfx_msg_q_num = msg_num;
    if (msg_num > dfx_stat->dfx_msg_q_peak_num) {
        dfx_stat->dfx_msg_q_peak_num = msg_num;
    }
#endif
}

static inline void diag_dfx_current_transmit_msg_num(uint16_t msg_num)
{
    unused(msg_num);
#if defined(CONFIG_DFX_STATS) && (CONFIG_DFX_STATS == DFX_YES)
    diag_dfx_stat_t *dfx_stat = uapi_diag_get_dfx_stat();
    dfx_stat->transmit_msg_q_num = msg_num;
    if (msg_num > dfx_stat->transmit_msg_q_peak_num) {
        dfx_stat->transmit_msg_q_peak_num = msg_num;
    }
#endif
}

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* DIAG_DFX_H */
