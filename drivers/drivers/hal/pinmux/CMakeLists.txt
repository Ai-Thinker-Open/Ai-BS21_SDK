#===============================================================================
# @brief    cmake make file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "hal_pinctrl")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/common

)

if(DEFINED CONFIG_PINCTRL_USING_V150)
elseif(DEFINED CONFIG_PINCTRL_USING_BS2X)
    list(APPEND PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/bs2x")
else()
    list(APPEND PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/${CHIP}")
endif()

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_HAL_PINCTRL
)

set(COMPONENT_CCFLAGS
)

set(WHOLE_LINK
    true
)
build_component()
