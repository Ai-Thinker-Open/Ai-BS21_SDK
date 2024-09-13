/*
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Application core os initialize interface header for standard \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-27, Create file. \n
 */
#ifndef AUDIO_COMMON_H
#define AUDIO_COMMON_H
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "audio_codec.h"
#include "audio_profile_calc.h"
#include "securec.h"

#define AUDIO_FIFO_SIZE (1024)
#define AUDIO_PADDING_BUFFER_SIZE (960)
#define AUDIO_IN_FIFO_READ_DATA_LEN   512
#define AUDIO_OUT_FIFO_READ_DATA_LEN   256
#define AUDIO_DEC_IN_FIFO_READ_DATA_LEN   256
#define AUDIO_DEC_OUT_FIFO_READ_DATA_LEN   1024
#define AUDIO_MS_NUM_PER_SECOND 1000
#define AUDIO_10MS_NUM_PER_SECOND 100

#define AUDIO_CODEC_NUM1 1
#define AUDIO_CODEC_NUM2 2
#define AUDIO_CODEC_NUM3 3
#define AUDIO_CODEC_NUM4 4
#define AUDIO_CODEC_NUM8 8
#define AUDIO_CODEC_NUM32 32
#define AUDIO_CODEC_NUM128 128
#define AUDIO_CODEC_NUM512 512
#define AUDIO_CODEC_NUM1024 1024
#define AUDIO_SUCCESS 0
#define AUDIO_FAILURE (-1)
#define AUDIO_TRUE 0
#define AUDIO_FALSE (-1)

#define sys_check_null_ptr_return(ptr)       \
    do {                                     \
        if ((void *)(ptr) == NULL) {   \
            return ERR_SYS_NULL;         \
        }                                    \
    } while (0)

#define codec_max(a, b) ((a) > (b) ? (a) : (b))

typedef enum {
    HA_CODEC_ENDODER = 0,
    HA_CODEC_DECODER,
} ha_codec_tpye;

/* defines audio channels. */
typedef enum {
    AUDIO_CH_NULL = 0,
    AUDIO_CH_1 = 1,
    AUDIO_CH_MONO = AUDIO_CH_1,
    AUDIO_CH_2 = 2,
    AUDIO_CH_STEREO = AUDIO_CH_2,
    AUDIO_CH_4 = 4,
    AUDIO_CH_6 = 6,
    AUDIO_CH_8 = 8,
    AUDIO_CH_16 = 16,
    AUDIO_CH_MAX
} audio_channel;

typedef struct {
    uint32_t *data; /* Data Buffer */
    uint32_t in_size; /* Data Size */
    uint32_t *data_out_buffer;
    uint32_t out_buffer_size;
    uint32_t out_data_size;
    bool     eos;
    bool     pkg_loss; /* the packet loss CNcomment: 是否丢包 CNend */
} audio_stream_buf;

/* defines the audio frame. */
typedef struct {
    bool interleaved;  /* whether the data is interleaved */
    uint32_t channels;     /* Number of Channels */
    uint32_t bit_depth;    /* Bit Depth */
    uint32_t sample_rate;  /* Sampling Rate */
    int64_t pts;          /* presentation time stamp (PTS, unit: us) */
    int32_t *pcm_buffer;  /* pointer to the buffer for storing the pulse code modulation (PCM) data */
    int32_t *bits_buffer; /* pointer to the buffer for storing the stream data */
    uint32_t bits_bytes;   /* IEC61937 data size */
    uint32_t pcm_samples;  /* number of sampling points of the PCM data */
    uint32_t frame_index;  /* Frame ID */

    /* eos */
    /* CNcomment: eos */
    bool eos;
    /* the packet loss */
    /* CNcomment: 是否丢包 CNend */
    bool pkg_loss;
} audio_frame;

/* defines audio format */
typedef struct {
    uint32_t channels;    /* Number of channels */
    uint32_t bit_depth;   /* ::audio_bit_depth */
    uint32_t sample_rate; /* ::audio_sample_rate */
    uint32_t samples_per_frame;
} audio_pcm_format;

typedef struct {
    uint8_t *buffer;
    uint32_t read;
    uint32_t write;
    uint32_t valid_size;
    uint32_t total_size;
    uint32_t tail_flag;
} ring_buffer_t;

/* defines the bit depth during audio sampling. */
typedef enum {
    BIT_DEPTH_NULL = 0, /* unknown */
    BIT_DEPTH_8 = 8,    /* 8-bit depth */
    BIT_DEPTH_16X2_LH = 15,  /* 16-bit depth */
    BIT_DEPTH_16 = 16,  /* 16-bit depth */
    BIT_DEPTH_18 = 18,  /* 18-bit depth */
    BIT_DEPTH_20 = 20,  /* 20-bit depth */
    BIT_DEPTH_24 = 24,  /* 24-bit depth */
    BIT_DEPTH_32 = 32,  /* 32-bit depth */
    BIT_DEPTH_64 = 64,  /* 64-bit depth */

    BIT_DEPTH_MAX
} audio_bit_depth;

extern ring_buffer_t g_in_fifo[2];
extern ring_buffer_t g_out_fifo[2];

static inline ring_buffer_t* audio_get_in_fifo(ha_codec_tpye codec_type)
{
    return &g_in_fifo[codec_type];
}

static inline ring_buffer_t* audio_get_out_fifo(ha_codec_tpye codec_type)
{
    return &g_out_fifo[codec_type];
}

int32_t ring_buffer_init(ha_codec_tpye codec_type);
int32_t write_data_into_fifo(uint8_t *data, ring_buffer_t *fifo, uint32_t len);
int32_t read_data_from_fifo(uint8_t **data, ring_buffer_t *fifo, int32_t len);
void read_data_from_fifo_finish(ring_buffer_t *fifo, uint32_t len);
uint32_t calc_sample_size(uint32_t channels, uint32_t bit_depth);
uint32_t calc_frame_size_per_ms(const audio_pcm_format *pcm_format);

#endif
