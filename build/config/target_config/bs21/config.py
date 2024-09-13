#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Target Definitions File
# Copyright CompanyNameMagicTag 2022-2022. All rights reserved.
# ============================================================================

try:
    from .sdk_libs import bs2x_sdk_libs, bs2x_ci_sdk_libs, bs2x_sdk_rm_bs26_libs
except ImportError:
    print("[Warning]:sdk libs import failed.")

target = {
    'standard-bs21-n1100': {
        'base_target_name': 'target_bs21_application_template',
        'pkg_chip': 'bs21-n1100',
        'defines': [
            'SUPPORT_CFBB_UPG', 'BGLE_TASK_EXIST', 'SUPPORT_MULTI_LIBS', 'SW_UART_DEBUG', 'AT_COMMAND', 'XO_32M_CALI', 'SUPPORT_SFC_IRQ_LOCK'
        ],
        'ram_component': [
            'demo',
            # Application Region
            'samples', 'standard_porting',

            # Middleware Region
            'dfx_porting', 'algorithm', 'app_init', 'lzma_21.07',
            'dfx_file_operation', 'pm_sys', 'codec',
            'update_common', 'update_local', 'update_storage', 'update_common_porting', 'update_storage_porting',
            'ota_upgrade', 

            # Stack Region
            'bg_common', 'bt_host', 'bth_sdk', 'bts_header', 'bth_gle',
            'bt_app', 'bgtp', 'nfc_controller', 'nfc_header',

            # Drivers Region
            'mips', 'drv_timer', 'hal_timer', 'timer_port', 'i2s',
            'systick_port', 'tcxo_port', 'sfc_porting', 'std_rom_lds_porting',
            'rtc_unified', 'hal_rtc_unified', 'rtc_unified_port', 'ir', 'ir_port',

            # OS Region
            'liteos_208_6_0_b017',

            # Deleted Region
            '-:libboundscheck', '-:test_usb_unified',
        ],
        'rom_component': ['bgtp_rom', 'libboundscheck', 'bt_host_rom', 'bg_common_rom'],
        'ram_component_set' : [
            'efuse_v151', 'spi', 'qdec', 'pdm', 'sio_v151', 'dmav151', 'keyscan', 'std_common_lib',
            '-:connectivity', '-:time_set', 'pm_set', 'dfx_set', 'sfc_flash', 'adc', 'flash', 'pm_clock_set', 'pwm'
        ],
        'upg_pkg': ['application'],
    },
    'bs21-n1100-rcu': {
        'base_target_name': 'standard-bs21-n1100',
        'defines': [
            'SUPPORT_SLE_PERIPHERAL', 'CONFIG_BT_SLE_ONLY'
        ],
        'liteos_kconfig': 'bs21_rcu',
        'sector_cfg': 'bs21-rcu',
        'nv_cfg': 'bs21_nv_rcu',
    },
}

# custom copy rules, put it in target_group below and it takes effect.
# <root> means root path
# <out_root> means output_root path
# <pack_target> means target_group key_name (like pack_bs21_standard)
target_copy = {

}

target_group = {

}
