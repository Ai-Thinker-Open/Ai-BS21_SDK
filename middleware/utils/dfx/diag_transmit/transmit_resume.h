/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: dfx transmit resume transfer
 * This file should be changed only infrequently and with great care.
 */

#ifndef TRANSMIT_RESUME_H
#define TRANSMIT_RESUME_H
#include <stdint.h>
#include "errcode.h"

int32_t transmit_flash_read(int32_t fd, uint32_t offset, uint8_t *buf, uint32_t size);

int32_t transmit_flash_write(int fd, unsigned offset, const uint8_t *buf, uint32_t size);

errcode_t transmit_record_progress(uint16_t transmit_type, uint32_t offset);

errcode_t transmit_get_progress(uint16_t transmit_type, uint32_t *offset);

errcode_t transmit_erase_progress(uint16_t transmit_type);
#endif