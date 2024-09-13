#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "hal_sio")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

if(DEFINED CONFIG_SIO_USING_V150)
endif()

if(DEFINED CONFIG_SIO_USING_V151)

endif()

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/hal_sio_v150
    ${CMAKE_CURRENT_SOURCE_DIR}/hal_sio_v151
    ${CMAKE_CURRENT_SOURCE_DIR}
)

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
