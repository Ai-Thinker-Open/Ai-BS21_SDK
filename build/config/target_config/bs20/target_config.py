#!/usr/bin/env python3
# encoding=utf-8
# =========================================================================
# @brief    Target Definitions File
# Copyright CompanyNameMagicTag 2022-2022. All rights reserved.
# =========================================================================
import os
import copy

target_template = {
    'target_bs20_application_template': {
        'chip': 'bs20',
        'chip_family': 'bs2x',
        'core': 'acore',
        'board': 'evb',
        'tool_chain': 'riscv32_musl_b010_fp',
        'build_type': 'COMPILE',
        'os': 'liteos',
        'std_libs': [],
        'CONFIG_TIMER_USING_V150': 'y',
        'CONFIG_I2C_USING_V151': 'y',
        'defines': ['-:CHIP_BS20=1', 'LIBCPU_UTILS', 'LIBLIB_UTILS', 'PRE_ASIC', 'LIBPANIC', 'LIBAPP_VERSION',
                    'VERSION_STANDARD', 'LIBBUILD_VERSION', "CONFIG_UART_FIFO_DEPTH=64", 'FLASH_1M',
                    'LIBTEST_COMMON', '_ALL_SOURCE', 'LOSCFG_MEM_TASK_STAT', 'SUPPORT_CXX', 'BS20_PRODUCT_EVB',
                    'LIBLOG', 'LIBLOG_READER', 'USE_LITEOS', 'USE_VECTORS', 'BUILD_APPLICATION_STANDARD', 'CMD_ENABLE',
                    '__LITEOS__', '__ARMEB__=0', 'LIBCPU_LOAD', 'LOSCFG_DRIVERS_EMMC', 'UART_DRIVER_CONFIG_USE_VETOS_IN_STEAD_OF_TIMERS',
                    'USE_CMSIS_OS', 'LIBCMD', 'LITEOS_ONETRACK', 'LIBCONNECTIVITY', 'LOSCFG_FS_FAT_CACHE', 'DUMP_MEM_SUPPORT',
                    "CONFIG_NV_SUPPORT_SINGLE_CORE_SYSTEM", 'CONFIG_NV_FEATURE_SUPPORT', 'FLASH_SECBOOT_SIZE=0x1000',
                    'LIBUTIL_COMPAT', "LITEOS_208", "BTH_LOG_BUG_FIX", 'OSALLOG_DISABLE', 'SUPPORT_DIAG_V2_PROTOCOL', 'SUPPORT_CPU_TRACE_PRINT',
                    'SUPPORT_HEAP_PRINT'],
        'defines_set': ['libsec_defines', 'chip_defines', 'version_defines'],
        'ram_component': ['main_init_porting', 'arch_port', 'pmu_porting', 'libboundscheck', 'non_os', 'board_config', 'ulp_aon', 'osal',
                          'clocks_porting', 'error_code', 'hal_mips', 'mem_config_porting',
                          'dfx_exception', 'lpm', 'chip_porting', 'cmn_header', 'driver_header',
                          'hal_uart', 'uart', 'uart_port', '-:connectivity', 'app_info',
                          'gmssl_hmac_sm3', 'systick', 'tcxo', 'hal_systick', 'hal_tcxo', '-:lib_utils', 'porting_inc',
                          'segger_b090_fp', 'usb_class', 'usb_class_open', 'usb_class_header', 'test_usb_unified',
                           'trng_port', 'trng', 'hal_trng', 'nv', 'nv_porting', 'partition', 'partition_porting',
                          'at', 'at_cmd_port', 'at_plt_cmd', 'at_btc_cmd', 'sfc_patch'],
        'ram_component_set': ['cpu', 'i2c', 'lpc', 'cpu_trace', 'gpio_v150', 'time_set', 'mem',
                              'watchdog', 'pinctrl', 'pm_set', 'usb_unified', 'pmp_set', 'pm_clock_set', 'pm_pmu_set'],
        'rom_component': [
        ],
        'bin_name': 'application',
        'ccflags': [
            '-:-mabi=ilp32', '-:-march=rv32imc', '-mabi=ilp32f', '-march=rv32imfc', '-madjust-regorder', '-madjust-const-cost', '-freorder-commu-args', '-fimm-compare-expand',
            '-frmv-str-zero', '-mfp-const-opt', '-:-mswitch-jump-table', '-frtl-sequence-abstract',
            '-frtl-hoist-sink', '-fsafe-alias-multipointer', '-finline-optimize-size', '--short-enums',
            '-fmuliadd-expand', '-mlli-expand', '-Wa,-mcjal-expand', '-foptimize-reg-alloc', '-fsplit-multi-zero-assignments',
            '-floop-optimize-size',  '-mpattern-abstract', '-foptimize-pro-and-epilogue', '-:-Wno-type-limits'
        ],
        'rom_ccflags': [
            '-:-mabi=ilp32', '-:-march=rv32imc', '-mabi=ilp32f', '-march=rv32imfc', '-madjust-regorder', '-madjust-const-cost', '-freorder-commu-args', '-fimm-compare-expand',
            '-frmv-str-zero', '-mfp-const-opt', '-frtl-sequence-abstract',
            '-frtl-hoist-sink', '-fsafe-alias-multipointer', '-finline-optimize-size',
            '-fmuliadd-expand', '-mlli-expand', '-Wa,-mcjal-expand', '-foptimize-reg-alloc', '-fsplit-multi-zero-assignments',
            '-floop-optimize-size', '-foptimize-pro-and-epilogue', '--short-enums',
            "-fno-inline-functions-called-once", "-fno-inline-small-functions", '-:-Wno-type-limits'
        ],
        'linkflags': [
            # '-Wl,--jal-transfer',
            '-Wl,--cjal-relax',
            '-Wl,--dslf',
        ],
        'application': 'standard',
        'hso_enable_bt': True,
        'hso_enable': True,
        'gen_parse_tool': False,
        'build_rom_callback': True,
        'fixed_rom': True,
        'fixed_rom_path': '<root>/drivers/chips/bs2x/rom/rom_bin/rom_n1100/application_rom.bin',
        'rom_sym_path': '<root>/drivers/chips/bs2x/rom/rom_info/acore/acore.sym',
        'rom_ram_check': True,
        'rom_ram_compare': True,
        'packet': True,
        'patch': True,
        'auto_patch_cfg': True,
        'arch': 'riscv31',
        'sector_cfg': 'bs20-standard',
        'nv_cfg': 'bs20_nv_default',
        # 编译时重新生成kconfig，保证.config与最新kconfig框架同步
        'reload_kconfig': True,
        'image_version': 'bs20h',
        'gen_sec_bin': True,
        'loaderboot_cfg': 'loaderboot-bs20-n1100',
        'flashboot_cfg': 'flashboot-bs20-n1100',
    },
}
