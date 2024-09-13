/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Application core os initialize interface header for standard \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-27, Create file. \n
 */
#ifndef AUDIO_ENC_CODEC_H
#define AUDIO_ENC_CODEC_H

#include "audio_common.h"

typedef struct {
    bool eos;
    uint32_t frame_pms;
    uint32_t frame_size;

    uint32_t max_bit_out_size;
    uint32_t not_enough_data_cnt;

    ha_codec_id codec_id;
    cps_profile profile;
    audio_pcm_format pcm_attr;

    void *h_enc;
    ha_codec_encode *codec;
    ha_codec_enc_in_packet in_pkt;
    ha_codec_enc_out_packet out_pkt;
} audio_aenc_inst;

typedef struct {
    ha_codec_id codec_id;
    ha_codec_enc_param open_param; /* Encoder open param */
} aenc_attr;

int32_t aenc_encode_frame(void);
int32_t aenc_open_codec(int32_t codecid, ha_codec_enc_param *open_param);
void aenc_close_codec(void);
uint32_t audio_get_encoder_consume_data_size(void);
uint32_t audio_get_encoder_product_data_size(void);
void audio_set_encoder_consume_data_size(uint32_t data_size);
void audio_encoder_fifo_info_display(void);
#endif