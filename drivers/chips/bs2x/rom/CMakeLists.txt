#===============================================================================
# @brief    cmake make file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
add_subdirectory_if_exist(driver)
add_subdirectory_if_exist(hal)
add_subdirectory_if_exist(porting)
add_subdirectory_if_exist(osal)
add_subdirectory_if_exist(common)

set(COMPONENT_NAME "sfc_header")
set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/porting/sfc
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/sfc
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/sfc
)
set(PUBLIC_DEFINES
    CONFIG_SFC_SUPPORT_LPM=1
)
build_component()

set(COMPONENT_NAME "tcxo_header")
set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/porting/tcxo
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/tcxo
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/tcxo
)
set(PUBLIC_DEFINES
    CONFIG_TCXO_SUPPORT_LPM=1
)
build_component()

set(COMPONENT_NAME "efuse_header")
set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/porting/efuse
    ${CMAKE_CURRENT_SOURCE_DIR}/halefuse
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/efuse
)
build_component()

set(COMPONENT_NAME "wdt_header")
set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/porting/watchdog
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/watchdog
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/watchdog
)
set(PUBLIC_DEFINES
    CONFIG_WATCHDOG_SUPPORT_LPM=1
)
build_component()

set(COMPONENT_NAME "pinmux_header")
set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/porting/pinctrl
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/pinmux
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/pinmux
)
build_component()

set(COMPONENT_NAME "uart_header")
set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/porting/uart
    ${CMAKE_CURRENT_SOURCE_DIR}/hal/uart
    ${CMAKE_CURRENT_SOURCE_DIR}/driver/uart
)
build_component()

if("SUPPORT_CHIP_N1200" IN_LIST DEFINES)
    add_subdirectory_if_exist(rom_config)
else()
    add_subdirectory_if_exist(rom_info)
endif()
