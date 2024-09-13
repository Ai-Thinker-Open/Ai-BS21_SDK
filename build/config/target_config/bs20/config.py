#!/usr/bin/env python3
# encoding=utf-8
# ============================================================================
# @brief    Target Definitions File
# Copyright CompanyNameMagicTag 2022-2022. All rights reserved.
# ============================================================================

target = {
    'standard-bs20-n1200': {
        'base_target_name': 'target_bs20_application_template',
        'pkg_chip': 'bs20-n1200',
        'defines': [
            'FLASH_1M', "USE_RSA3072_SIGN", 'SUPPORT_CFBB_UPG', 'BGLE_TASK_EXIST', 'SUPPORT_MULTI_LIBS',
            'SW_UART_DEBUG', 'AT_COMMAND', 'XO_32M_CALI', 'SUPPORT_CHIP_N1200',
        ],
        'ram_component': [
            # Application Region
            'samples', 'standard_porting',

             # pos algorithm
            'cal_dis',

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

            # use n1200 drivers.
            'tcxo_header', '-:tcxo', '-:hal_tcxo', '-:tcxo_port',
            'sfc_header', '-:sfc', '-:hal_sfc', '-:sfc_porting',
            'efuse_header', '-:efuse_port', '-:hal_efuse_v151', '-:efuse',
            'wdt_header', '-:watchdog', '-:hal_watchdog', '-:watchdog_port',
            'remote_lib',
        ],
        'rom_component': ['bgtp_rom', 'libboundscheck', 'bt_host_rom', 'bg_common_rom'],
        'ram_component_set' : [
            'efuse_v151', 'spi', 'qdec', 'pdm', 'sio_v151', 'dmav151', 'keyscan', 'std_common_lib',
            '-:connectivity', '-:time_set', 'pm_set', 'dfx_set', 'adc', 'pwm'
        ],
        'fixed_rom': True,
        'fixed_rom_path': '<root>/drivers/chips/bs2x/rom/rom_bin/rom_n1200/application_rom.bin',
        'rom_sym_path': "<root>/drivers/chips/bs2x/rom/rom_config/acore/acore_rom_n1200.sym",
        'bootrom_sym_path': "<root>/drivers/chips/bs2x/rom/rom_config/acore/remote_lib_app.sym",
        'rom_ram_compare': True,
        'loaderboot_cfg': 'loaderboot-bs20-n1200',
        'flashboot_cfg': 'flashboot-bs20-n1200',
    },
    'bs20-n1200-rcu': {
        'base_target_name': 'standard-bs20-n1200',
        'liteos_kconfig': 'bs21e_rcu',
        'sector_cfg': 'bs20-rcu',
    },
}

# custom copy rules, put it in target_group below and it takes effect.
# <root> means root path
# <out_root> means output_root path
# <pack_target> means target_group key_name (like pack_bs20_standard)
target_copy = {

}

target_group = {

}
