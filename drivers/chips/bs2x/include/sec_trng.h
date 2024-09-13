/*
 * Copyright (c) @CompanyNameMagicTag 2020-2020. All rights reserved.
 * Description: SEC TRNG
 * Author: @CompanyNameTag
 * Create: 2020-01-20
 */

#ifndef SEC_TRNG_H
#define SEC_TRNG_H

#include "stdint.h"

typedef enum {
    SEC_TRNG_RET_OK = 0,
    SEC_TRNG_RET_ERROR = 1,
    SEC_TRNG_RET_TOO_LONG = 2,
} sec_trng_ret_t;

/**
 * @brief  Apps core to get random.
 * @param  trng_buffer        Addresses requiring random numbers.
 * @param  trng_buffer_length The length of the random number required.
 * @return return get random success or not, see defination of sec_trng2_ret_t.
 */
sec_trng_ret_t sec_trng_random_get(uint8_t *trng_buffer, uint32_t trng_buffer_length);

/**
 * @}
 */
#endif
