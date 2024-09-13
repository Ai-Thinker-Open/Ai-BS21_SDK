#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
include("${CMAKE_CURRENT_SOURCE_DIR}/bs2x_sample_config.cmake")
add_subdirectory_if_exist(porting)
add_subdirectory_if_exist(rom)
add_subdirectory_if_exist(boot)
add_subdirectory_if_exist(test_suite_stub)
set(COMPONENT_NAME "chip_porting")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
${CMAKE_CURRENT_SOURCE_DIR}/arch/include
${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}/boot
)

if(DEFINED OS AND NOT ${OS} STREQUAL "non-os")

list(APPEND PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/liteos)
endif()

if(${CHIP} MATCHES "bs20|bs21|bs21e|bs21a|bs22|bs26")
set(PUBLIC_DEFINES
CHIP_BS2X=1
)
else()
set(PUBLIC_DEFINES
CHIP_BS2X=0
)
endif()

set(WHOLE_LINK
true
)

set(MAIN_COMPONENT
false
)

build_component()

set(COMPONENT_NAME "mini_chip_porting")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
${CMAKE_CURRENT_SOURCE_DIR}/arch/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/boot
)

if(DEFINED OS AND NOT ${OS} STREQUAL "non-os")
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/arch/src/oam_trace.c)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/interrupt/interrupt_os_adapter.c)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${OS}/idle_config.c)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${OS}/tick_timer.c)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${OS}/memory_info.c)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${OS}/os_dfx.c)
    list(APPEND PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/liteos)
endif()

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

build_component()

set(COMPONENT_NAME "clocks_porting")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/clocks/
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_CLOCKS
    SUPPORT_CLOCKS_CORE
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

set(COMPONENT_NAME "pmu_porting")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/pmu
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_CLOCKS
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

set(COMPONENT_NAME "main_init_porting")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/main_init
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_CLOCKS
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

install_sdk("${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin" "*.bin")

if(NOT ${LOADERBOOT_CFG} EQUAL "")
install_sdk("${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${LOADERBOOT_CFG}" "*.bin")
endif()

if(NOT ${FLASHBOOT_CFG} EQUAL "")
install_sdk("${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${FLASHBOOT_CFG}" "*.bin")
endif()

if(NOT ${SEC_BOOT} EQUAL "")
install_sdk("${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${SEC_BOOT}" "*.bin")
endif()