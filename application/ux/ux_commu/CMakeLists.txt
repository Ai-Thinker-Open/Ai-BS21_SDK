#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "ux_commu")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_box_event.c
    ${CMAKE_CURRENT_SOURCE_DIR}/ux_commu_event.c
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

install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/  "ux_box_event.h")

build_component()
