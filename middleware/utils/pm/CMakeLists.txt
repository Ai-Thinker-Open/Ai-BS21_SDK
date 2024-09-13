#===============================================================================
# @brief    cmake make file
# Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
#===============================================================================
add_subdirectory_if_exist(pm_dev)
add_subdirectory_if_exist(pm_fsm)
add_subdirectory_if_exist(pm_veto)
add_subdirectory_if_exist(pm_sleep)
add_subdirectory_if_exist(pm_dfx)
add_subdirectory_if_exist(pm_core)

set(COMPONENT_NAME "pm")

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
)

build_component()