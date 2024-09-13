#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "osal")

if(NOT DEFINED OS)
    return()
endif()

if(${OS} STREQUAL "non-os")
    set(src_sub nonos)
elseif(${OS} STREQUAL "liteos")
    set(src_sub liteos)
elseif(${OS} STREQUAL "freertos")
    set(src_sub freertos)
elseif(${OS} STREQUAL "alios")
    set(src_sub alios)
endif()

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/atomic
    ${CMAKE_CURRENT_SOURCE_DIR}/include/debug
    ${CMAKE_CURRENT_SOURCE_DIR}/include/device
    ${CMAKE_CURRENT_SOURCE_DIR}/include/drvbox
    ${CMAKE_CURRENT_SOURCE_DIR}/include/event
    ${CMAKE_CURRENT_SOURCE_DIR}/include/fileops
    ${CMAKE_CURRENT_SOURCE_DIR}/include/interrupt
    ${CMAKE_CURRENT_SOURCE_DIR}/include/lock
    ${CMAKE_CURRENT_SOURCE_DIR}/include/math
    ${CMAKE_CURRENT_SOURCE_DIR}/include/memory
    ${CMAKE_CURRENT_SOURCE_DIR}/include/msgqueue
    ${CMAKE_CURRENT_SOURCE_DIR}/include/proc
    ${CMAKE_CURRENT_SOURCE_DIR}/include/schedule
    ${CMAKE_CURRENT_SOURCE_DIR}/include/semaphore
    ${CMAKE_CURRENT_SOURCE_DIR}/include/string
    ${CMAKE_CURRENT_SOURCE_DIR}/include/time
    ${CMAKE_CURRENT_SOURCE_DIR}/adapt/include
    ${CMAKE_CURRENT_SOURCE_DIR}/test/alios
    ${CMAKE_CURRENT_SOURCE_DIR}/test/src
    
)

set(PRIVATE_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/src/${src_sub}
)

if(${OS} STREQUAL "alios")
    list(APPEND PRIVATE_HEADER
        ${ROOT_DIR}/kernel/alios/alios_v3.3.0/components/osal_aos/rhino/include
        ${ROOT_DIR}/kernel/alios/alios_v3.3.0/components/osal_aos/include/aos
        ${ROOT_DIR}/kernel/alios/alios_v3.3.0/components/osal_aos/include
    )
endif()

set(PRIVATE_DEFINES
    CONFIG_LIB_SUPPORT_COMPAT_LINUX
)

set(PUBLIC_DEFINES
)

# use this when you want to add ccflags like -include xxx
set(COMPONENT_PUBLIC_CCFLAGS
)

set(COMPONENT_CCFLAGS

    -Wno-unused-parameter
    -Wno-implicit-function-declaration
    -Wno-sign-compare
    -Wno-visibility
)

if(${ARCH} STREQUAL "riscv70")
set(COMPONENT_CCFLAGS
    ${COMPONENT_CCFLAGS}
    -Wno-typedef-redefinition
)
endif()

if (${ARCH} STREQUAL "cortex_m7")
set(COMPONENT_CCFLAGS
    ${COMPONENT_CCFLAGS}
    -Wno-error=cast-function-type
)
endif()

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

build_component()

if (${CHIP} STREQUAL "socmn1")
    add_subdirectory_if_exist(test)
endif()

if(syschannel_host_ko IN_LIST TARGET_COMPONENT)
install_sdk(${CMAKE_SOURCE_DIR}/kernel/osal/src/linux "*") 
endif()