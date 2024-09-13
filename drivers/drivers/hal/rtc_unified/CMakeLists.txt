#===============================================================================
# @brief    cmake make file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "hal_rtc_unified")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)



set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(DEFINED CONFIG_RTC_USING_V150)
list(APPEND PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/v150
)
else()
list(APPEND PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/v100
)
endif()

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
)

# use this when you want to add ccflags like -include xxx
set(COMPONENT_PUBLIC_CCFLAGS
)

set(COMPONENT_CCFLAGS
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)


build_component()
return_if_not_build()
install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/  "*.h")
