#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Target Definitions File
# Copyright CompanyNameMagicTag 2022-2022. All rights reserved.
# ============================================================================

bs22_n1200_libs = {
    'bs22-n1200-sle-peripheral': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs22-n1200-libgen',
        'defines': ['SUPPORT_SLE_PERIPHERAL', 'CONFIG_BT_SLE_ONLY']
    },
    'bs22-n1200-sle-ble-peripheral': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs22-n1200-libgen',
        'defines': ['SUPPORT_SLE_BLE_PERIPHERAL']
    },
    'bs22-n1200-sle-central': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs22-n1200-libgen',
        'defines': ['SUPPORT_SLE_CENTRAL', 'CONFIG_BT_SLE_ONLY']
    },
    'bs22-n1200-ble-peripheral': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs22-n1200-libgen',
        'defines': ['SUPPORT_BLE_PERIPHERAL']
    }
}