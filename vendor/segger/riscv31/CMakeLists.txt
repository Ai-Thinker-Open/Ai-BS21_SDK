#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
#===============================================================================
if("segger_b007" IN_LIST TARGET_COMPONENT)
    add_subdirectory(b007)
elseif("segger_b050" IN_LIST TARGET_COMPONENT)
    add_subdirectory(b050)
endif()
add_subdirectory_if_exist(b040)
add_subdirectory_if_exist(b090)
