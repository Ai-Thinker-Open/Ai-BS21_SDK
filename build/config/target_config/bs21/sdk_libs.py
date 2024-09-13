#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Target Definitions File
# Copyright CompanyNameMagicTag 2022-2022. All rights reserved.
# ============================================================================
# sdk onetrack depend libs.
from ..bs20.sdk_libs import bs20_n1200_libs
from ..bs21e.sdk_libs import bs21e_1100e_libs
from ..bs22.sdk_libs import bs22_n1200_libs
from ..bs26.sdk_libs import bs26_n1200_libs

bs21_n1100_libs = {
    'bs21-n1100-sle-peripheral': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_SLE_PERIPHERAL', 'CONFIG_BT_SLE_ONLY']
    },
    'bs21-n1100-sle-ble-peripheral': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_SLE_BLE_PERIPHERAL']
    },
    'bs21-n1100-sle-central': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_SLE_CENTRAL', 'CONFIG_BT_SLE_ONLY']
    },
    'bs21-n1100-ble-peripheral': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_BLE_PERIPHERAL']
    },
    'bs21-n1100-sle-peripheral-release': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_SLE_PERIPHERAL', 'CONFIG_BT_SLE_ONLY',  'BT_USER_RELEASE']
    },
    'bs21-n1100-sle-ble-peripheral-release': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_SLE_BLE_PERIPHERAL', 'BT_USER_RELEASE']
    },
    'bs21-n1100-sle-central-release': {
        'components': ['bg_common', 'bth_gle', 'bgtp', 'bt_host', 'bth_sdk', 'bt_app'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_SLE_CENTRAL', 'CONFIG_BT_SLE_ONLY', 'BT_USER_RELEASE']
    },
    'bs21-n1100-ble-peripheral-release': {
        'components': ['bgtp', 'bg_common', 'bt_host', 'bt_app', 'bth_gle', 'bth_sdk'],
        'base_target_name': 'bs21-n1100-libgen',
        'defines': ['SUPPORT_BLE_PERIPHERAL', 'BT_USER_RELEASE']
    }
}

bs2x_ci_sdk_libs = {
    **bs21_n1100_libs, **bs21e_1100e_libs,
}

bs2x_sdk_libs = {
    **bs20_n1200_libs,
    **bs21_n1100_libs,
    **bs21e_1100e_libs,
    **bs22_n1200_libs,
    **bs26_n1200_libs,
}

bs2x_sdk_rm_bs26_libs = {
    **bs20_n1200_libs,
    **bs21_n1100_libs,
    **bs21e_1100e_libs,
    **bs22_n1200_libs,
}

