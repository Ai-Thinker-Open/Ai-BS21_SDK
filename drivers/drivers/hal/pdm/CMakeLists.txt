#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "hal_pdm")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(DEFINED CONFIG_PDM_USING_V151)
    list(APPEND PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/v151")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/v151" "*.h")
endif()

if(DEFINED CONFIG_PDM_USING_V150)
    list(APPEND PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/v150")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/v150" "*.h")
endif()

if(NOT DEFINED CONFIG_PDM_USING_V150 AND NOT DEFINED CONFIG_PDM_USING_V151)
    list(APPEND PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/v150")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/v150" "*.h")
endif()

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
)

set(COMPONENT_CCFLAGS
)

set(WHOLE_LINK
    true
)
install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}" "*.h")

build_component()