#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "ux_spp")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_common.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_interface.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_tws.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_resend.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_header.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_intelligent.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_tool.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_dev.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_spp_ios.c
)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
   RUN_WITHOUT_BOX
)

set(PUBLIC_DEFINES
   CONFIG_SYSTEM_MU0101
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

install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/  "ux_spp_ios.h")

build_component()
