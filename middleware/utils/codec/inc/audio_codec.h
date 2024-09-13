/*
 * Copyright (c) CompanyNameMagicTag. 2020-2021. All rights reserved.
 * Description: header file for audio decoders and encoders
 * Author: audio
 */

#ifndef __HA_CODEC_H__
#define __HA_CODEC_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* Define audio codec common command ID */
/* CNcomment:定义音频 codec 公共CMD ID */
#define HA_CODEC_COMMON_CMD_ID 0xffff

/* Define  codec get codec output delay ms */
/* CNcomment:定义获取解码器输出延时CMD ID */
#define HA_CODEC_OUTPUT_DELAY_GET_CMD ((((uint32_t)HA_CODEC_COMMON_CMD_ID) << 16) | 0x100B)

/* Define  codec get codec output */
/* CNcomment:定义获取编解码器参数 */
#define ACODEC_PRIVATE_PARAM_GET_CMD ((((uint32_t)HA_CODEC_COMMON_CMD_ID) << 16) | 0x100C)
#define ACODEC_IN_FRAME_SIZE_GET_CMD ((((uint32_t)HA_CODEC_COMMON_CMD_ID) << 16) | 0x100D)
#define ACODEC_OUT_FRAME_SIZE_GET_CMD ((((uint32_t)HA_CODEC_COMMON_CMD_ID) << 16) | 0x100E)
#define ACODEC_SET_PLC_OFF_THR_CMD ((((uint32_t)HA_CODEC_COMMON_CMD_ID) << 16) | 0x1010)
#define ACODEC_GET_PLC_OFF_THR_CMD ((((uint32_t)HA_CODEC_COMMON_CMD_ID) << 16) | 0x1011)

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE (!FALSE)
#endif

#ifndef NULL
#define NULL (void *)0
#endif

#define AUDIO_SUCCESS 0
#define AUDIO_FAILURE (-1)

/* CNcomment: 定义音频采样率枚举 */
typedef enum {
    HA_CODEC_SAMPLE_RATE_UNKNOWN = 0, /* Unknown */                  /* CNcomment: 未知采样频率 */
    HA_CODEC_SAMPLE_RATE_8K = 8000, /* 8 kHz sampling rate */        /* CNcomment: 8K采样频率 */
    HA_CODEC_SAMPLE_RATE_12K = 12000, /* 12 kHz sampling rate */     /* CNcomment: 12K采样频率 */
    HA_CODEC_SAMPLE_RATE_16K = 16000, /* 16 kHz sampling rate */     /* CNcomment: 16K采样频率 */
    HA_CODEC_SAMPLE_RATE_24K = 24000, /* 24 kHz sampling rate */     /* CNcomment: 24K采样频率 */
    HA_CODEC_SAMPLE_RATE_32K = 32000, /* 32 kHz sampling rate */     /* CNcomment: 32K采样频率 */
    HA_CODEC_SAMPLE_RATE_44K = 44100, /* 44.1 kHz sampling rate */   /* CNcomment: 44.1K采样频率 */
    HA_CODEC_SAMPLE_RATE_48K = 48000, /* 48 kHz sampling rate */     /* CNcomment: 48K采样频率 */

    HA_CODEC_SAMPLE_RATE_MAX
} ha_codec_sample_rate;

/* defines the channels. */
/* CNcomment: 定义音频通道枚举 */
typedef enum {
    HA_CODEC_CH_NUM_1 = 1,
    HA_CODEC_CH_NUM_2 = 2,
    HA_CODEC_CH_NUM_3 = 3,
    HA_CODEC_CH_NUM_4 = 4,
    HA_CODEC_CH_NUM_5 = 5,
    HA_CODEC_CH_NUM_6 = 6,
    HA_CODEC_CH_NUM_7 = 7,
    HA_CODEC_CH_NUM_8 = 8,

    HA_CODEC_CH_NUM_MAX,
} ha_codec_ch_num;

/* defines the bit depth during audio sampling. */
/* CNcomment: 定义音频采样位宽枚举 */
typedef enum {
    HA_CODEC_BIT_DEPTH_UNKNOWN = 0, /* Unknown */  /* CNcomment: 未知采样位宽 */
    HA_CODEC_BIT_DEPTH_8 = 8, /* 8-bit depth */    /* CNcomment: 8位采样位宽  */
    HA_CODEC_BIT_DEPTH_16 = 16, /* 16-bit depth */ /* CNcomment: 16位采样位宽 */
    HA_CODEC_BIT_DEPTH_18 = 18, /* 18-bit depth */ /* CNcomment: 18位采样位宽 */
    HA_CODEC_BIT_DEPTH_20 = 20, /* 20-bit depth */ /* CNcomment: 20位采样位宽 */
    HA_CODEC_BIT_DEPTH_24 = 24, /* 24-bit depth */ /* CNcomment: 24位采样位宽 */
    HA_CODEC_BIT_DEPTH_32 = 32, /* 32-bit depth */ /* CNcomment: 32位采样位宽 */

    HA_CODEC_BIT_DEPTH_MAX
} ha_codec_bit_depth;

/* Audio hacodec error no: [0x8000_5320,0x8000_533f) */
typedef enum {
    ERR_HACODEC_INVALID_PARAM = 0x80005320,
    ERR_HACODEC_INVALID_SAMPLERATE = 0x80005321,
    ERR_HACODEC_INVALID_BITDEPTH = 0x80005322,
    ERR_HACODEC_INVALID_CHANNEL = 0x80005323,
    ERR_HACODEC_NULL_PTR = 0x80005324,
    ERR_HACODEC_STREAM_CORRUPT = 0x80005325,
    ERR_HACODEC_NOT_ENOUGH_DATA = 0x80005326,
    ERR_HACODEC_NOT_SUPPORT = 0x80005327,
    ERR_HACODEC_INIT_FAILED = 0x80005328,
    ERR_HACODEC_ENCODE_FAILED = 0x80005329,
    ERR_HACODEC_DECODE_FAILED = 0x8000532a,
    ERR_HACODEC_WRONG_HEADER = 0x8000532b,
    ERR_HACODEC_ALLOC_MEM_FAILED = 0x8000532c,
    ERR_HACODEC_MEM_COPY_FAILED = 0x8000532d,
    ERR_HACODEC_NOT_ENOUGH_OUT_BUFFER_SIZE = 0x8000532e,
    ERR_HACODEC_NOT_ENOUGH_SCRATCH_BUFFER_SIZE = 0x8000532f,
    ERR_HACODEC_READ_FIFO_NOT_ENOUGH_DATA = 0x80005330,
    ERR_HACODEC_WRITE_FIFO_OVERFLOW = 0x80005331,
} hacodec_errno;

/* audio codec ID definition */
/* CNcomment:音频编解码器ID定义 */
typedef enum {
    HA_CODEC_ID_SBC,
    HA_CODEC_ID_MSBC,
    HA_CODEC_ID_OPUS,
    HA_CODEC_ID_L2HC,
    HA_CODEC_ID_MAX,
} ha_codec_id;

/* Define get param of codec. */
/* CNcomment:定义 codec 获取参数 */
typedef struct {
    uint32_t codec_id;
    void *private_data; /* codec external data */
    uint32_t private_data_size;
    void *private_attr; /* codec internal attr */
    uint32_t private_attr_size;
} acodec_get_private_param;

/* Configuration parameters required by an  codec for creating devices. */
/* CNcomment:解码器创建设备的配置参数 */
typedef struct {
    /* expected output channels.
     * If the number of original channels is not equal to the number of expected output channels,
     * the decoded automatically performs down-mixing or up-mixing,
     * In this way, the number of output channels is equal to the value of desired_out_channels,
     * 1: mono; 2: stereo.
     */
    uint32_t channels;

    /* Bit width of the PCM data.Only 16-bit or 24-bit width is supported.
     * For the data of 16-bit width, 16-bit memory is used
     * For the data of 24-bit width, 32-bit memory is used
     * The active bits of the 24-bit PCM data are upper bits, and the lower eight bits are 0.
     */
    uint32_t bit_depth;

    uint32_t sample_rate; /* expected output sampling rate. */

    /* Input, pointer to private data.If the decoder does not contain private data, this parameter is set to 0. */
    /* CNcomment:IN  指向私有配置结构体的指针，如果解码器没有私有配置，设置为0 */
    void *private_data;

    /* Input, size of the private data.If the decoder does not contain private data, this parameter is set to 0. */
    /* CNcomment:IN 私有结构体大小, 如果解码器没有私有配置，设置为0 */
    uint32_t private_data_size;
} ha_codec_dec_param;

/* Input streams of an decoder. */
/* CNcomment:解码器输入码流结构体 */
typedef struct {
    int64_t pts;
    /* Input/output, pointer to input streams.The decoder update this pointer after decoding. */
    /* CNcomment:IN/OUT 输入码流指针，解码完成后解码器更新该指针 */
    uint8_t *data;

    /* Input, size (in byte) of input streams. */
    /* CNcomment:IN 输入码流大小. unit: Byte */
    uint32_t size;

    /* Input, the last frame or not. */
    /* CNcomment:IN 是否最后一帧 */
    bool eos;
    /* Input, the packet loss. */
    /* CNcomment:IN 是否丢包 */
    bool pkg_loss;
} ha_codec_dec_in_packet;

/* Definition of the decoder output pts information. */
/* CNcomment:pts输出信息 */
typedef struct {
    union {
        /* left bytes of software decoder. */
        /* CNcomment:软解剩余字节数 */
        uint32_t sw_decoder_bytes_left;

        /* pts read position of software decoder. */
        /* CNcomment:硬解pts读位置 */
        uint32_t hw_decoder_pts_read_pos;
    } un_pts;

    union {
        /* ad left bytes of software decoder. */
        /* CNcomment:软解ad剩余字节数 */
        uint32_t sw_decoder_bytes_left;

        /* ad pts read position of software decoder. */
        /* CNcomment:硬解ad pts读位置 */
        uint32_t hw_decoder_pts_read_pos;
    } un_ad_pts;
} ha_codec_out_pts_info;

/* Output structure of the decoder. */
/* CNcomment:解码器输出结构体 */
typedef struct {
    /* Input, pointer to the decoded PCM data.
    Note: 1) pcm_out_buf must be 32-word aligned.
          2) pcm_out_buf is NULL when the decoder is working in HD_DEC_MODE_THRU mode. */
    /* CNcomment:IN 指向PCM 解码输出的指针. */
    int32_t *pcm_out_buf;

    /* Input, size (in byte) of the buffer for storing the decoded PCM data
    Note: u32PcmOutBufSize is 0 when the decoder is working in HD_DEC_MODE_THRU mode. */
    /* CNcomment:IN  PCM 解码输出缓冲区大小. unit:Byte */
    uint32_t pcm_out_buf_size;

    /* Input, pointer to the decoded passthrough data.
    Note: 1) ps32BitsOutBuf must be 32-word aligned.
          2) ps32BitsOutBuf is NULL when the decoder is working in HD_DEC_MODE_RAWPCM mode. */
    /* CNcomment:IN 指向透传解码输出的指针. */
    int32_t *bits_out_buf;

    /* Input, size (in byte) of the buffer for storing the decoded passthrough data (IEC61937)
    Note: u32BitsOutBufSize is 0 when the decoder is working in HD_DEC_MODE_RAWPCM mode. */
    /* CNcomment:IN 透传(IEC61937) 解码输出缓冲区大小. unit:Byte */
    uint32_t bits_out_buf_size;

    /* Output, number of output sampling points after the PCM data is decoded. */
    /* CNcomment:OUT. 解码Pcm 输出样点数 */
    uint32_t pcm_out_samples;

    /* Output, interleaved mode for PCM decoding. */
    /* CNcomment:OUT PCM  解码交织模式 */
    bool interleaved;

    /* Output, bit per sampling. */
    /* CNcomment:OUT 位宽 */
    uint32_t bit_per_sample;

    /* Output, size (in byte) of the passthrough frame. */
    /* CNcomment:OUT 透传输出帧大小. unit: Byte */
    uint32_t bits_out_bytes;

    /* Output, number of output channels. */
    /* CNcomment:OUT 输出声道数 */
    uint32_t out_channels;

    /* Output, output sampling rate. */
    /* CNcomment:OUT. 输出采样频率 */
    uint32_t out_sample_rate;

    /* Output, number of original channels. */
    /* CNcomment:OUT 码流原始声道数 */
    uint32_t org_channels;

    /* Output, original sampling rate. */
    /* CNcomment:OUT 码流原始采样频率 */
    uint32_t org_sample_rate;

    /* Output, bit rate (in bit/s) of the compressed streams. */
    /* CNcomment:OUT 码流压缩率unit: bit/S */
    uint32_t bit_rate;

    /* Output, pts information. */
    /* CNcomment:OUT. pts信息 */
    ha_codec_out_pts_info pts_info;

    /* Output, output frame index. */
    /* CNcomment:OUT. 输出帧序号 */
    uint32_t frame_index;
} ha_codec_dec_out_packet;

/* Definition of the lib version. */
/* CNcomment: lib 版本定义 */
typedef union {
    struct {
        uint8_t version_major; /* Major version. */ /* CNcomment:主版本号 */
        uint8_t version_minor; /* Minor version. */ /* CNcomment:副版本号 */
        uint8_t revision; /* Revision version. */   /* CNcomment:修订版本 */
        uint8_t step; /* Step version. */           /* CNcomment:阶段性版本 */
    } bits;
    uint32_t version;
} audio_lib_version;

/* Definition of the decoder. */
/* CNcomment:解码器设备定义 */
typedef struct ha_codec_decode {
    /* Input, description information about a decoder, such as MP3 or AAC. */
    /* CNcomment:IN 解码器描述名字，如MP3,AAC */
    const char *name;

    /* Input, decoder ID.Note: This ID is the identifier of a decoder, and must be unique. */
    /* CNcomment:IN 解码器标识，注意: 此标识作为解码器唯一身份标识，必须唯一而不能有重复 */
    const uint32_t codec_id;

    /* Input, decoder version. */
    /* CNcomment:IN 解码器版本描述 */
    const audio_lib_version version;

    /* Input, detailed information about a decoder. */
    /* CNcomment:IN 解码器详细描述信息 */
    const char *description;

    /* Output, pointer to the next decoder.This member variable is maintained by the client that calls the  codec,
    Therefore, the developers of the decoder can ignore this member variable. */
    /* CNcomment:OUT  指向下个解码器设备的指针. 该成员变量由调用Codec 的客户端维护,
    解码器开发者可以忽略该成员 */
    struct ha_codec_decode *next;

    /* Output, pointer to the dll symbol of an decoder,
    This member variable is maintained by the client that calls the  codec,
    Therefore, the developers of the decoder can ignore this member variable. */
    /* CNcomment:OUT 该成员变量由调用Codec 的客户端维护, 解码器开发者可以忽略该成员 */
    void *module;

    /*
    \brief Initializes a decoder. CNcomment:初始化解码器 CNend
    \attention
    \param[in] open_param pointer of the open params CNcomment:open参数结构体指针 CNend
    \param[out] decoder   pointer of the decoder handle CNcomment:解码器句柄指针 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*init)(void **decoder, const ha_codec_dec_param *open_param);

    /*
    \brief DeInitializes a decoder. CNcomment:去初始化解码器 CNend
    \attention
    \param[in] decoder   pointer of the decoder handle CNcomment:解码器句柄指针 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*deinit)(void *decoder);

    /*
    \brief Configure a decoder dynamically. You can call this API when a decoder works.
    CNcomment:解码器动态配置方法，用户可以在解码器运行时调用该接口 CNend
    \attention
    \param[in] decoder   the decoder handle CNcomment:解码器句柄 CNend
    \param[in] cmd   the cmd code CNcomment:命令字 CNend
    \param[in] config pointer to application allocated structure to be used for initialization by the decoder
    CNcomment:解码器初始化结构体 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*send_cmd)(void *decoder, uint32_t cmd, void *arg);

    /*
    \brief Maximum size of the buffer required for storing the PCM data decoded by the decoder,
    The memory needs to be allocated based on the size on the client.
    CNcomment:解码器PCM输出所需最大缓冲区size. 客户端需要根据该方法分配内存 CNend
    \attention
    \param[in] decoder   the decoder handle CNcomment:解码器句柄 CNend
    \param[out] out_size pointer to the max size of the pcm audio frame. unit:Byte
    CNcomment:最大PCM输出缓冲区大小 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*get_max_pcm_out_size)(void *decoder, uint32_t *out_size);

    /*
    \brief Maximum size of the buffer required for storing the passthrough data decoded by the decoder,
    The memory needs to be allocated based on the size on the client.
    CNcomment:解码器透传输出所需最大缓冲区size.客户端需要根据该方法分配内存 CNend
    \attention
    \param[in] decoder   the decoder handle CNcomment:解码器句柄 CNend
    \param[out] out_size pointer to the max size of the iec61937 audio frame. unit:Byte
    CNcomment:最大透传输出缓冲区大小 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*get_max_bits_out_size)(void *decoder, uint32_t *out_size);

    /*
    \brief This method is used to decode a frame. CNcomment:解码器解码一帧方法 CNend
    \attention
    \param[in] h_decoder   the decoder handle CNcomment:解码器句柄 CNend
    \param[in] apkt pointer to audio stream packet CNcomment:音频输入流指针 CNend
    \param[out] a_out pointer to audio output CNcomment:音频输出流指针 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*decode_frame)(void *decoder, ha_codec_dec_in_packet *in_pkt, ha_codec_dec_out_packet *out_pkt);
} ha_codec_decode;

/* Parameters for creating an encoder. */
/* CNcomment:编码器创建配置参数 */
typedef struct {
    /* IN interleave or not. */
    /* CNcomment:交织模式 */
    bool interleaved;

    /* IN Number of channels (e.g 2 for stereo). */
    /* CNcomment:声道数 */
    uint32_t channels;

    /* IN bitwidth per sample. */
    /* CNcomment:位宽 */
    int32_t bit_depth;

    /* IN desired samplerate. */
    /* CNcomment:期望采样率 */
    uint32_t sample_rate;

    /* IN Pcm samples per frame for encoder. */
    /* CNcomment:每帧采样点 */
    uint32_t samples_per_frame;

    /* Pointer of decoder private open parameters
     * note: set NULL if there is no private parameters
     */
    /* CNcomment: 解码器私有参数 */
    void *private_data;

    /* Size of decoder private open parameters
     * note: set to 0 if there is no private parameters
     */
    /* CNcomment: 解码器私有参数大小 */
    uint32_t private_data_size;
} ha_codec_enc_param;

/* input pcm packet struct */
/* CNcomment: 解码器输入pcm数据结构体 */
typedef struct {
    /* IN PTS (unit:us) Note: encoder should discard this information. */
    /* CNcomment:PTS，单位:微秒 */
    int64_t pts;

    /* IN/OUT pointer to input auduo pcm data note: encoder would update data after encode. */
    /* CNcomment:输入数据指针 */
    uint8_t *data;

    /* IN/OUT size of the input auduo data. unit: Byte. */
    /* CNcomment:输入数据大小 */
    uint32_t size;
} ha_codec_enc_in_packet;

/* encoder output struct. */
/* CNcomment:编码器输出结构体 */
typedef struct {
    /* the pointer to encoded bitstream output buffer note: ps32BitsOutBuf must  be word32-aligned. */
    /* CNcomment:编码数据输出buffer */
    int32_t *bits_out_buf;

    /* the buffer size of bitstream output buffer. unit:Byte. */
    /* CNcomment:编码器输出buffer大小 */
    uint32_t bits_out_buf_size;

    /* size of the encoded audio data frame, unit: Byte. */
    /* CNcomment:编码数据帧大小，单位:Byte */
    uint32_t bits_out_bytes;

    /* compress bit rate of the audio stream. */
    /* CNcomment:比特率 */
    uint32_t bit_rate;
} ha_codec_enc_out_packet;

/* encoder struct define. */
/* CNcomment:定义编码器结构体 */
typedef struct ha_codec_encode {
    /* Input, description information about audio encoder. */
    /* CNcomment:IN 编码器描述名字 */
    const char *name;

    /* encoder ID. Note: This ID is the identifier of a encoder, and must be unique. */
    /* CNcomment:IN 编码器标识，注意: 此标识作为编码器唯一身份标识，必须唯一而不能有重复 */
    const uint32_t codec_id;

    /* Input, encoder version. */
    /* CNcomment:IN 编码器版本描述 */
    const audio_lib_version version;

    /* Input, Description information of the audio encoder. */
    /* CNcomment:IN 编码器详细描述信息 */
    const char *description;

    /* OUT pointer to next encoder.manager by client.
    client:The layer of software that invokes the methods of the encoder. */
    /* CNcomment:OUT 下个编码器结构体指针，由客户管理 */
    struct ha_codec_encode *next;

    /* Output, pointer to the dll symbol of an encoder.
    This member variable is maintained by the client that calls the  codec Therefore,
    the developers of the encoder can ignore this member variable. */
    /* CNcomment:OUT 该成员变量由调用Codec 的客户端维护, 编码器开发者可以忽略该成员 */
    void *module;

    /*
    \brief Initializes a encoder. CNcomment:初始化编码器 CNend
    \attention
    \param[in] open_param pointer of the open params CNcomment:open参数结构体指针 CNend
    \param[out] ph_encoder   pointer of the encoder handle CNcomment:编码器句柄指针 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*init)(void **encoder, const ha_codec_enc_param *open_param);

    /*
    \brief DeInitializes a encoder. CNcomment:去初始化编码器 CNend
    \attention
    \param[in] h_encoder   pointer of the encoder handle CNcomment:编码器句柄 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*deinit)(void *encoder);

    /*
    \brief Configure a encoder dynamically. You can call this API before a encoder works.
    CNcomment:编码器动态配置方法，用户可以在编码器运行前调用该接口 CNend
    \attention
    \param[in] encoder   the encoder handle CNcomment:编码器句柄 CNend
    \param[in] cmd   the cmd code CNcomment:命令字 CNend
    \param[in] config pointer to application allocated structure to be used for initialization by the encoder
    CNcomment:编码器初始化结构体 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*send_cmd)(void *encoder, uint32_t cmd, void *arg);

    /*
    \brief Maximum output size of an encoded bitstream CNcomment:编码器输出所需最大缓冲区size CNend
    \attention
    \param[in] encoder   the encoder handle CNcomment:解码器句柄 CNend
    \param[out] out_size pointer to the max size of the encoded audio frame. unit:Byte
    CNcomment:最大编码帧输出缓冲区大小 CNend \retval ::0  SUCCESS CNcomment:成功 CNend \retval
    ::s32 FAILURE CNcomment:失败 CNend \see N/A
    */
    int32_t (*get_max_bits_out_size)(void *encoder, uint32_t *out_size);

    /*
    \brief This method is used to encode a frame. CNcomment:编码器编码一帧方法 CNend
    \attention
    \param[in] encoder   the encoder handle CNcomment:编码器句柄 CNend
    \param[in] in_pkt pointer to audio stream packet CNcomment:音频输入流指针 CNend
    \param[out] out_pkt pointer to audio output CNcomment:音频输出流指针 CNend
    \retval ::0  SUCCESS CNcomment:成功 CNend
    \retval ::s32 FAILURE CNcomment:失败 CNend
    \see
    N/A
    */
    int32_t (*encode_frame)(void *encoder, ha_codec_enc_in_packet *in_pkt, ha_codec_enc_out_packet *out_pkt);
} ha_codec_encode;

/* ptr check function */
#define check_null_ptr(ptr)                  \
    do {                                     \
        if ((ptr) == NULL) {              \
            return ERR_HACODEC_NULL_PTR;    \
        }                                    \
    } while (0)
/* align function */
#define size_align(size, align) (((size) + ((align) - 1)) & ~((align) - 1))

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* __HA_CODEC_H__ */
