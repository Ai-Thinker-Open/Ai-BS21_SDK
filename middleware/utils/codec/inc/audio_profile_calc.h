/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Application core os initialize interface header for standard \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-07-27, Create file. \n
 */
#ifndef AUDIO_PROFILE_CALC_H
#define AUDIO_PROFILE_CALC_H

#include <sys/time.h>

#define CONVERT_LEVEL 1000000
typedef struct {
    unsigned long start_cycles;
    unsigned long stop_cycles;
    unsigned long cycles;
#ifdef CYCLE_FLOAT
    float peak;
    float ave;
    float sum;
    float curr;
#else
    uint32_t peak;
    uint32_t ave;
    uint32_t sum;
    uint32_t curr;
#endif
    uint32_t peak_frame;
    uint32_t frame;
} cps_profile;

__attribute__((__gnu_inline__, __always_inline__, __artificial__))
static inline unsigned long rdcycle(void)
{
    unsigned long dst;
    asm volatile ("rdcycle %0" : "=r" (dst));
    return dst;
}

static inline uint32_t audio_osal_gettime_us(void)
{
    struct timeval times;
    uint32_t time_us;

    gettimeofday(&times, NULL);

    time_us = (uint32_t)(times.tv_sec * CONVERT_LEVEL + times.tv_usec);

    return time_us;
}

static inline uint32_t audio_osal_cali_time_diff_us(uint32_t begin_us, uint32_t end_us)
{
    return (end_us - begin_us);
}

void cps_profile_init(cps_profile *profile);
void cps_profile_start(cps_profile *profile);
void cps_profile_stop(cps_profile *profile, uint32_t sample_rate, uint32_t samples);

#endif
