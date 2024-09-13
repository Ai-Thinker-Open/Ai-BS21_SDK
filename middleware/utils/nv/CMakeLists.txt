#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "nv")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${ROOT_DIR}/include/middleware/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/nv_storage_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/nv_storage_app
)

set(PRIVATE_HEADER
    ${ROOT_DIR}/drivers/drivers/driver/security/hash
    ${ROOT_DIR}/middleware/chips/${chip}/nv/include
    ${ROOT_DIR}/middleware/utils/update/inner_include
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