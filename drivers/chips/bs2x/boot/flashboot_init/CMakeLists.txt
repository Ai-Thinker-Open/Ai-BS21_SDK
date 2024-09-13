#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2024-2024. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "flashboot_init_porting")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/flashboot_init.c
)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(PRIVATE_HEADER
)

if(DEFINED CONFIG_DRIVERS_USB_DFU_GADGET)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/dfu/usb_dfu.c)
    list(APPEND PRIVATE_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/dfu)
endif()

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