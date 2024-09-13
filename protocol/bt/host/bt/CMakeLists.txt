#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
# 定义BTH_PROJECT是为了将各平台不同方式项目名称定义转化为统一的bth内部的定义, 防止平台修改定义方式后bth内部散弹式修改cmake文件
# bs21为切换CodeHub源后的首个项目，平台采用全新的货架化架构，编译系统套件采用CFBB编译系统，与原gerrit上的编译套件不兼容
set(MODULE_NAME "bth")
set(AUTO_DEF_FILE_ID False)
if((${CHIP} MATCHES "bs25") AND (DEFINED ROM_COMPONENT))
    set(MODULE_NAME "bt")
    include(bt_rom.cmake)
    add_subdirectory_if_exist(ahi/ahi_b)
elseif("${CHIP}" STREQUAL "brandy" AND "bt_app" IN_LIST TARGET_COMPONENT)
    include(bt_app.cmake)
    add_subdirectory_if_exist(sdk)
    add_subdirectory_if_exist(bt_audio_wrapper)
    add_subdirectory_if_exist(bt_sample)
else()
    if("bt_app" IN_LIST TARGET_COMPONENT)
        include(bt_app.cmake)
    endif()
    if("bth_sdk" IN_LIST TARGET_COMPONENT)
        add_subdirectory_if_exist(sdk)
    endif()
    if("bt_host" IN_LIST TARGET_COMPONENT)
        include(bt_host.cmake)
    endif()
endif()
