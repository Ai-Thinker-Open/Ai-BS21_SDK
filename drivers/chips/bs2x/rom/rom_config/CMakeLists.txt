#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
#===============================================================================

set(COMPONENT_NAME "rom_callback")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/${CORE}/output/rom_callback.S
    ${CMAKE_CURRENT_SOURCE_DIR}/${CORE}/output/rom_callback_weak.c
)

if(DEFINED ROM_SYM_PATH)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${CORE}/rom_data.c)
endif()

if(NOT EXISTS ${ROOT_DIR}/protocol/bt/host/bg_common OR NOT EXISTS ${ROOT_DIR}/protocol/bt/controller/bgtp/chip)
if(EXISTS ${BIN_DIR}/${CHIP}/libs/rom_config/${TARGET_COMMAND}/librom_callback.a)
    set(SOURCES)
    set(LIBS ${BIN_DIR}/${CHIP}/libs/rom_config/${TARGET_COMMAND}/librom_callback.a)
endif()
endif()

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

if(${BUILD_ROM_CALLBACK} OR rom_callback IN_LIST TARGET_COMPONENT)
    execute_process(
        COMMAND ${CP} ${CMAKE_CURRENT_SOURCE_DIR}/${CORE}/output/function.lds ${CMAKE_BINARY_DIR}
        COMMAND ${CP} ${CMAKE_CURRENT_SOURCE_DIR}/${CORE}/output/data.lds ${CMAKE_BINARY_DIR}
    )
endif()

if(rom_callback IN_LIST TARGET_COMPONENT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/${CORE}/output/rom_callback_wrap.cmake)
    file(WRITE ${CMAKE_BINARY_DIR}/rom_cb_flag.srp "${CMAKE_CB_FLGAS}")
    target_link_options(${TARGET_NAME}
        PRIVATE
        @${CMAKE_BINARY_DIR}/rom_cb_flag.srp
    )
endif()
set(LIB_OUT_PATH ${BIN_DIR}/${CHIP}/libs/rom_config/${TARGET_COMMAND})
build_component()

install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/acore "*.sym")
install_sdk(${CMAKE_CURRENT_SOURCE_DIR}/acore/output "*.lds")
