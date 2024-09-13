#!/usr/bin/env python3bs20
# encoding=utf-8
# ============================================================================
# @brief    Target Definitions File
# Copyright CompanyNameMagicTag 2022-2022. All rights reserved.
# ============================================================================

bs20_n1200_libs = {
    'bs20-n1200-sle-peripheral': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs20-n1200-libgen',
        'defines': ['SUPPORT_SLE_PERIPHERAL', 'CONFIG_BT_SLE_ONLY']
    },
    'bs20-n1200-sle-ble-peripheral': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs20-n1200-libgen',
        'defines': ['SUPPORT_SLE_BLE_PERIPHERAL']
    },
    'bs20-n1200-sle-central': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs20-n1200-libgen',
        'defines': ['SUPPORT_SLE_CENTRAL', 'CONFIG_BT_SLE_ONLY']
    },
    'bs20-n1200-ble-peripheral': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs20-n1200-libgen',
        'defines': ['SUPPORT_BLE_PERIPHERAL']
    },
    'bs20-n1200-sle-measure-dis': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk', 'cal_dis'],
        'base_target_name': 'bs20-n1200-libgen-dis',
        'defines': ['PRODUCT_SLE_MEASURE_DIS',
                    'SLEM_CARKEY', 'MEASURE_DIS', 'EM_32K_SUPPORT']
    },
}