#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
# 定义BTH_PROJECT是为了将各平台不同方式项目名称定义转化为统一的bth内部的定义, 防止平台修改定义方式后bth内部散弹式修改cmake文件
# xxxx为切换CodeHub源后的首个项目，平台采用全新的货架化架构，编译系统套件采用CFBB编译系统，与原gerrit上的编译套件不兼容
set(MODULE_NAME "bth")
if((${CHIP} MATCHES "bs25") AND (${CORE} MATCHES "bt_core"))
set(MODULE_NAME "bt")
endif()

if("gle_app" IN_LIST TARGET_COMPONENT)
    include(gle_app.cmake)
endif()
if("bth_gle" IN_LIST TARGET_COMPONENT)
    include(bth_gle.cmake)
endif()
if("gle_host" IN_LIST TARGET_COMPONENT)
    include(gle_host.cmake)
endif()
if(${CHIP} MATCHES "GLE_LINUX_CONFIG")
    include(gle_linux.cmake)
endif()
