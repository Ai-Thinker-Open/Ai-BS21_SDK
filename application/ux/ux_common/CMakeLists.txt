#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "ux_common")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_manager_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_multiple_device.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_config_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_config_tws.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_secure.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_state_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_state_tws.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_tws_product_config.c
)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
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
    -fno-common -fmessage-length=0 -fno-exceptions -nostdinc
    -fsigned-char -fno-aggressive-loop-optimizations -fno-isolate-erroneous-paths-dereference -fsingle-precision-constant
    -Wdouble-promotion -Wno-float-conversion -fdiagnostics-color=auto
    -fstack-protector-strong
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/  "ux_product_interface.h")
install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/  "ux_manager_common.h")
install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/  "ha_common.h")

build_component()
