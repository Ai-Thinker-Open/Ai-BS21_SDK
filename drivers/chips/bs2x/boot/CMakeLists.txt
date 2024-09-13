#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
#===============================================================================
add_subdirectory_if_exist(boot_config)
add_subdirectory_if_exist(boot_porting)
add_subdirectory_if_exist(provision_init)
add_subdirectory_if_exist(flashboot_init)
