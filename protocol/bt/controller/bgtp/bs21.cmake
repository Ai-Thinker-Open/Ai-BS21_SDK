#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(MODULE_NAME "bt")
set(COMPONENT_NAME "bgtp")
set(BTC_RAM_LIST  "" CACHE INTERNAL "" FORCE)
set(BTC_ROM_LIST  "" CACHE INTERNAL "" FORCE)
set(BTC_HEADER_LIST  "" CACHE INTERNAL "" FORCE)

if(DEFINED ROM_COMPONENT OR DEFINED ROM_SYM_PATH)
    set(BT_ROM_VERSION true)
else()
    set(BT_ROM_VERSION false)
endif()


if("DEVICE_ONLY" IN_LIST DEFINES)
    set(BGTP_DEVICE_ONLY true)
else()
    set(BGTP_DEVICE_ONLY false)
endif()

if(BGTP_DEVICE_ONLY)
    set(BT_ONETRACK false)
else()
    set(BT_ONETRACK true)
endif()

MESSAGE("BGTP_PROJECT=" ${BGTP_PROJECT})
MESSAGE("BGTP_ROM_VERSION=" ${BT_ROM_VERSION})
MESSAGE("BGTP_DEVICE_ONLY=" ${BGTP_DEVICE_ONLY})

add_subdirectory_if_exist(chip)

if("${BTC_RAM_LIST}" STREQUAL "")
    if(DEFINED CONFIG_SLE_BLE_SUPPORT AND SUPPORT_MULTI_LIBS IN_LIST DEFINES)
        set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/${PKG_CHIP}-${CONFIG_SLE_BLE_SUPPORT}/lib${COMPONENT_NAME}.a)
    elseif(DEFINED CONFIG_SUPPORT_SLE_BLE_CENTRAL_DEFAULT)
        set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_COMMAND}/lib${COMPONENT_NAME}.a)
    else()
        set(BTC_RAM_LIST "__null__")
    endif()
endif()

if(BT_ROM_VERSION)
    set(SOURCES
        ${BTC_RAM_LIST}
    )
else()
    set(SOURCES
        ${BTC_RAM_LIST}
        ${BTC_ROM_LIST}
    )
endif()

set(GMSSL_PATH ${PROJECT_SOURCE_DIR}/open_source/GmSSL3.0)

set(GMSSL_HEADER_LIST
    ${GMSSL_PATH}/include/
    ${GMSSL_PATH}/include/gmssl/
    ${GMSSL_PATH}/src/
)

set(PUBLIC_HEADER
    ${BTC_HEADER_LIST}
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/ble
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/gle
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/comm
)

set(PRIVATE_HEADER
    ${GMSSL_HEADER_LIST}
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    "BTC_SYS_PART=100"
)

# use this when you want to add ccflags like -include xxx
set(COMPONENT_PUBLIC_CCFLAGS
)

set(COMPONENT_CCFLAGS
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/log_def_btc.h)
set(LOG_DEF
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/log_def_btc.h
)
endif()


set(LIB_OUT_PATH ${BIN_DIR}/${CHIP}/libs/bluetooth/btc/${TARGET_COMMAND})
# MESSAGE("BGTP_RAM_SRC_LIST=" ${BTC_RAM_LIST})
# MESSAGE("BGTP_ROM_SRC_LIST=" ${BTC_ROM_LIST})
# MESSAGE("BGTP_PRIVATE_HDR_LIST=" ${PRIVATE_HEADER})
# MESSAGE("BGTP_HDR_LIST=" ${BTC_HEADER_LIST})

build_component()

if(BT_ROM_VERSION)
    set(COMPONENT_NAME "bgtp_rom")

    if("${BTC_ROM_LIST}" STREQUAL "")
        set(BTC_ROM_LIST "__null__")
    endif()

    set(SOURCES
        ${BTC_ROM_LIST}
    )

    set(GMSSL_HEADER_LIST
    ${GMSSL_PATH}/include
    ${GMSSL_PATH}/include/openssl
    )

    set(PUBLIC_HEADER
        ${BTC_HEADER_LIST}
        ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm
        ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def
        ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/ble
        ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/gle
        ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/comm
    )

    set(PRIVATE_HEADER
        ${GMSSL_HEADER_LIST}
    )

    set(PRIVATE_DEFINES
    )

    set(PUBLIC_DEFINES
        "BTC_SYS_PART=100"
    )

    set(COMPONENT_PUBLIC_CCFLAGS
    )

    set(COMPONENT_CCFLAGS
    )

    set(WHOLE_LINK
        true
    )

    set(MAIN_COMPONENT
        false
    )
    build_component()
endif()

set(COMPONENT_NAME "bgtp_ate")

set(SOURCES

    ## BTC
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/src/bt_ate.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/main/bt_main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/ble/test_mode/lm_ble_test_mode.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/ble/test_mode/lm_ble_test_mode_fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/ble/test_mode/lm_ble_test_mode_act.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/gle/test_mode/lm_gle_test_mode.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/gle/test_mode/lm_gle_test_mode_fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/gle/test_mode/lm_gle_test_mode_act.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/ble/test_mode/lm_ble_test_mode_fsm_tbl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/gle/test_mode/lm_gle_test_mode_fsm_tbl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/service/L3/dm/gle/dm_gle.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/service/L2/evt_task/evt_task_ble_test_mode.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/ble/test_mode/evt_task_ble_test_mode_isr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/service/L2/evt_task/evt_task_gle_test_mode.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/ble/test_mode/evt_task_ble_test_mode_fsm_tbl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/gle/test_mode/evt_task_gle_test_mode_fsm_tbl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/gle/test_mode/evt_task_gle_test_mode_isr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/comm/evt_task_comm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/comm/evt_task_fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_prog/evt_prog.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_prog/evt_prog_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_sched/evt_sched.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_sched/evt_sched_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_sched/evt_sched_util.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_sched/evt_sched_util_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_sched/evt_sched_policy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_sched/evt_sched_mgr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_sched/evt_sched_mgr_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_sched/evt_sched_calc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L1/dpc/dpc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/service/L1/isr/ble_isr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/service/L1/isr/gle_isr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/util/lib/list/co_list.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/comm/fsm/fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/comm/fsm/fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/btc_timer/btc_timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/fronted_hal/cali/src/cali_reg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/fronted_hal/cali/src/cali_entrance.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/fronted_hal/cali/src/cali_state.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/em_mgr/em_tx_buff_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/em_mgr/em_tx_desc_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_gle_rx_desc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_mgr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_sed.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_rx_buff.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_rx_desc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_tx_buff.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/em_tx_desc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config/bt_hal_control.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config/bt_cbb_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config/bt_rf_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config/bt_rf_table.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config/mpw_poweron.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/cali_rx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/cali_tx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/cali_list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/cali_bt_data.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/cali_adpll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/cali_dll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/src/hal_bt_cali.c
    # ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/phy/src/bt_productline.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/phy/src/bt_chr_handle.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/phy/src/bt_dbg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/phy/src/bt_adpll.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/phy/src/bt_path.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/hw/hal/alg/src/rf_calibration_alg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/accumulator/src/rf_accumulation.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/src/bt_hal_interface.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/lowpower/bgtp_pmu_hw.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/lowpower/bgtp_pmu_hw_ram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/pwr_ctrl_cfg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/em_map/em_map.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/sed_adapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/coex/coex_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/coex/adapter/bgtp/coex_adapter.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/bt_onetrack/pub_if.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/dts_mem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/dts_mac_reg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/dts_interrupt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/dts_config.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/dts_interrupt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/dts_thread.c


)

set(PUBLIC_HEADER

    ## BTC
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/main/inc
    #dts_macro_cfg.h
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/util/comm/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/ble/test_mode
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/ble/test_mode/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/gle/test_mode
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/lm/gle/test_mode/inc
    # ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/dm/gle
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/service/L3/dm/gle
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L3/dm/gle/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/ble/test_mode
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/ble/test_mode/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_prog
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/gle/test_mode
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/gle/test_mode/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_prog/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_sched
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_sched/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L1/dpc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L1/dpc/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L1/isr
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L1/isr/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/util/lib/list
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/util/lib/list/inc
    # ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/comm/fsm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/comm/fsm/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/btc_timer
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/btc_timer/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/fronted_hal/cali/src
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/em_mgr
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/service/comm/em_mgr
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/service/comm/em_mgr/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/config/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/cali/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/phy/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/hw/hal/alg/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/hw/hal/alg//inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/accumulator/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/hal/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/lowpower/pmu/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/lowpower
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/coex
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/coex/adapter/bgtp
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/reg
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/dts/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/dts/bs21/product/tag
    # ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/bt
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/em_map/product/tag
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/dts/bs21/hal
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/dts/bs21/ble
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/gle
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/fronted_hal/cali/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/comm/em_mgr
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/ble
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/ble
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/gle
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/comm/bt_onetrack
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L3/dm/comm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/dts
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/rom/service/L2/evt_sched
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/comm/hci_def/ble
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/chnl_scan
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/service/L2/evt_task/evt_coex
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ate/comm/fsm
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/reg
    ${CMAKE_CURRENT_SOURCE_DIR}/chip/bs21/ram/hw/reg/soc_reg
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
)

# use this when you want to add ccflags like -include xxx
set(COMPONENT_PUBLIC_CCFLAGS
)

set(COMPONENT_CCFLAGS
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

build_component()