/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: file operation
 * This file should be changed only infrequently and with great care.
 */
#ifndef __TRANSMIT_DEBUG_H__
#define __TRANSMIT_DEBUG_H__

#include "transmit_item.h"
#include "dfx_adapt_layer.h"

#if defined DEBUG_TRANSMIT
void transmit_printf_item(char *info, transmit_item_t *item);
void transmit_printf_receive_frame(uint16_t cmd_id, void *cmd_param, uint16_t cmd_param_size, diag_option_t *option,
    bool from_upper_machine);
void transmit_printf_send_frame(uint16_t cmd_id, void *cmd_param, uint16_t cmd_param_size, diag_option_t *option,
    bool down_machine);
#else
static inline void transmit_printf_item(const char *info, const transmit_item_t *item)
{
    unused(info);
    unused(item);
    return;
}
static inline void transmit_printf_receive_frame(uint16_t cmd_id, const void *cmd_param, uint16_t cmd_param_size,
    const diag_option_t *option, bool from_upper_machine)
{
    unused(cmd_id);
    unused(cmd_param);
    unused(cmd_param_size);
    unused(option);
    unused(from_upper_machine);
    return;
}
static inline void transmit_printf_send_frame(uint16_t cmd_id, const void *cmd_param, uint16_t cmd_param_size,
    const diag_option_t *option, bool down_machine)
{
    unused(cmd_id);
    unused(cmd_param);
    unused(cmd_param_size);
    unused(option);
    unused(down_machine);
    return;
}
#endif
#endif
