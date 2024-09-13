/*
 * Copyright (c) @CompanyNameMagicTag 2021-2023. All rights reserved.
 * Description: diag rx
 * This file should be changed only infrequently and with great care.
 */
#ifndef DIAG_RX_API_H
#define DIAG_RX_API_H

#include "diag_common.h"
#include "dfx_resource_id.h"

int32_t uapi_diag_channel_rx_mux_char_data(diag_channel_id_t id, uint8_t *data, uint16_t size);

#endif
