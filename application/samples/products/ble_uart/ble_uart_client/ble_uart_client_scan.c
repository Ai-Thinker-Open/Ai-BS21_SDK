/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: BLE uart client scan source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-07-26, Create file. \n
 */
#include "errcode.h"
#include "bts_def.h"
#include "bts_le_gap.h"
#include "ble_uart_client_scan.h"

static uint16_t g_uart_scan_interval = 0x48;
static uint16_t g_uart_scan_window = 0x48;
static uint8_t g_uart_scan_type = 0x00;
static uint8_t g_uart_scan_phy = 0x01;
static uint8_t g_uart_scan_filter_policy = 0x00;

errcode_t ble_uart_set_scan_parameters(void)
{
    gap_ble_scan_params_t ble_uart_scan_params = { 0 };
    ble_uart_scan_params.scan_interval = g_uart_scan_interval;
    ble_uart_scan_params.scan_window = g_uart_scan_window;
    ble_uart_scan_params.scan_type = g_uart_scan_type;
    ble_uart_scan_params.scan_phy = g_uart_scan_phy;
    ble_uart_scan_params.scan_filter_policy = g_uart_scan_filter_policy;
    return gap_ble_set_scan_parameters(&ble_uart_scan_params);
}

errcode_t ble_uart_start_scan(void)
{
    return gap_ble_start_scan();
}