#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2023-2023. All rights reserved.
#===============================================================================
if (${CHIP} MATCHES "bs21|bs21a|bs21e|bs20")
    add_subdirectory_if_exist(cal_dis_bs21)
else()
    add_subdirectory_if_exist(cal_dis)
endif()