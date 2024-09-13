/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Application core os initialize interface header for standard \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-27, Create file. \n
 */
#ifndef AUDIO_DEC_CODEC_H
#define AUDIO_DEC_CODEC_H
#include "audio_common.h"

typedef struct {
    bool eos;
    bool format_changed;
    uint32_t frame_pms;
    uint32_t frame_size;
    uint32_t frame_cnt;

    uint32_t max_pcm_out_size;
    uint32_t not_enough_data_cnt;

    ha_codec_id codec_id;
    audio_pcm_format pcm_attr;
    cps_profile profile;
    void *h_dec;
    ha_codec_decode *codec;
    ha_codec_dec_in_packet in_pkt;
    ha_codec_dec_out_packet out_pkt;

    /* spend status */
    uint32_t last_dec_time;      /* start pts of last decode frame(us) */
    uint32_t cur_dec_interval;   /* current decode interval(us) */
    uint32_t max_dec_interval;   /* maximum decode interval(us) */
    uint32_t min_dec_interval;   /* minimum decode interval(us) */
    uint64_t total_dec_interval; /* total decode interval(us) */
    uint32_t cur_dec_consume;    /* current decode consume(us) */
    uint32_t max_dec_consume;    /* maximum decode consume(us) */
    uint32_t min_dec_consume;    /* minimum decode consume(us) */
    uint64_t total_dec_consume;  /* total decode consume(us) */

    /* run status */
    uint32_t acquire_fail_cnt;
    uint32_t dec_fail_cnt;
    uint32_t dec_success_cnt;
    uint32_t info_change_cnt;
} audio_adec_inst;

typedef struct {
    ha_codec_id codec_id;
    ha_codec_dec_param open_param; /* Decoder open param */
} adec_attr;

int32_t adec_decode_frame(uint32_t pkg_loss);
int32_t adec_open_codec(int32_t codecid, ha_codec_dec_param *open_param);
void adec_close_codec(void);
uint32_t audio_get_decoder_consume_data_size(void);
uint32_t audio_get_decoder_product_data_size(void);
void audio_set_decoder_consume_data_size(uint32_t data_size);
void audio_decoder_fifo_info_display(void);
#endif
