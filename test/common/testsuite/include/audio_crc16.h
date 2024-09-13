/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides crc16 uapi \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-10-19， Create file. \n
 */

#ifndef AUDIO_CRC16_H
#define AUDIO_CRC16_H

#include "common_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

uint16_t checksum_crc16(uint16_t crc_value, const uint8_t *ptr, uint16_t length);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif