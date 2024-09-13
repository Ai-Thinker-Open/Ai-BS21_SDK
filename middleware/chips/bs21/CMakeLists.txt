#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
#===============================================================================
add_subdirectory_if_exist(partition)
add_subdirectory_if_exist(nv)
add_subdirectory_if_exist(image_info)
add_subdirectory_if_exist(imu_wakeup)
