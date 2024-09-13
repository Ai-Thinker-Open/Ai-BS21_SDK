#===============================================================================
# @brief    cmake make file
# Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "pm_core")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core_ballot/pm_core_ballot.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core_fsm/pm_core_fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core_int/pm_core_int.c
)

set(PRIVATE_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core_ballot
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core_fsm
    ${CMAKE_CURRENT_SOURCE_DIR}/pm_core_int
)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
)

set(COMPONENT_CCFLAGS
)

set(WHOLE_LINK
    true
)
build_component()
