#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
add_subdirectory_if_exist(${CHIP})

if (${CHIP} MATCHES "bs20|bs21|bs21a|bs21e|bs22|bs26")
    add_subdirectory_if_exist(bs2x)
endif()