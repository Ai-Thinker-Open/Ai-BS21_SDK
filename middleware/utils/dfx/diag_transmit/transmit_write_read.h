/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: transmit
 * This file should be changed only infrequently and with great care.
 */
#ifndef __TRANSMIT_WRITE_READ_H__
#define __TRANSMIT_WRITE_READ_H__

#include "transmit_item.h"

int32_t buf_read_data(uintptr_t usr_data, uint32_t offset, uint8_t *buf, uint32_t len);
int32_t buf_write_data(uintptr_t usr_data, uint32_t offset, uint8_t *buf, uint32_t len);
int32_t file_read_data(uintptr_t usr_data, uint32_t offset, uint8_t *buf, uint32_t len);
int32_t file_write_data(uintptr_t usr_data, uint32_t offset, uint8_t *buf, uint32_t len);

#endif