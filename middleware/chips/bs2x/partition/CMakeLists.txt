#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2024. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "partition_porting")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${ROOT_DIR}/middleware/chips/${CHIP}/partition/include
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
)

set(COMPONENT_CCFLAGS
"-Wno-incompatible-pointer-types"
)

set(WHOLE_LINK
true
)

build_component()
