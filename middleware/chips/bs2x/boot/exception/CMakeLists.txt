#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "boot_exception")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/boot_exception_riscv.s
    ${CMAKE_CURRENT_SOURCE_DIR}/boot_exception_riscv.c
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
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

build_component()


return_if_not_build()
install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}" "*.h")
