#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(MODULE_NAME "app")
set(AUTO_DEF_FILE_ID TRUE)

add_subdirectory_if_exist(ux_common)
add_subdirectory_if_exist(ux_commu)
add_subdirectory_if_exist(ux_audio)
add_subdirectory_if_exist(ux_bt)
add_subdirectory_if_exist(ux_sensor)
add_subdirectory_if_exist(ux_spp)
add_subdirectory_if_exist(ux_tone)
add_subdirectory_if_exist(tlv)
add_subdirectory_if_exist(ux_manager)
add_subdirectory_if_exist(ux_led)
add_subdirectory_if_exist(ux_lpc)
add_subdirectory_if_exist(include)
add_subdirectory_if_exist(ux_haid)
add_subdirectory_if_exist(ux_protocol)
add_subdirectory_if_exist(ux_cmd)
add_subdirectory_if_exist(ux_factory)
add_subdirectory_if_exist(ux_module)