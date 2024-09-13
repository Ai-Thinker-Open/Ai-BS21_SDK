/*
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
 * Description: dfx system init
 * This file should be changed only infrequently and with great care.
 */
#ifndef DFX_SYSTEM_INIT_H
#define DFX_SYSTEM_INIT_H

int32_t msg_process_proc(uint32_t msg_id, uint8_t *data, uint16_t size);
errcode_t dfx_system_init(void);

#endif