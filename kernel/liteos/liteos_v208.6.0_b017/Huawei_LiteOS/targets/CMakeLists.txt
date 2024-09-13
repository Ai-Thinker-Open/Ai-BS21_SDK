
STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
set(MODULE_NAME ${CURRENT_FOLDER})


# add global include, compile macro and options to public target #
set(PLATFORM_INCLUDE
    ${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/include
)

if(LOSCFG_SAFETY_KERNEL AND LOSCFG_BOX)
    list(APPEND PLATFORM_INCLUDE ${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/box/boxes_cfg)
    list(APPEND PLATFORM_INCLUDE ${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/box/usrdrvlib)
if(LOSCFG_TEST)
    include(${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/box/boxes_cfg/test/boxes.cmake)
else()
    include(${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/box/boxes_cfg/boxes.cmake)
endif()
endif()

if(LOSCFG_LIB_LIBC)
    list(APPEND PLATFORM_INCLUDE ${LITEOSTOPDIR}/lib/liteos_libc/time)
endif()

set(MODULE_INCLUDE_PUB ${PLATFORM_INCLUDE})
set(MODULE_CXXINCLUDE_PUB ${PLATFORM_INCLUDE})
set(MODULE_COPTS_PUB)
set(MODULE_ASOPTS_PUB)
set(MODULE_CXXOPTS_PUB)
set(MODULE_CMACRO_PUB)
set(MODULE_ASMACRO_PUB)
set(MODULE_CXXMACRO_PUB)


# add local include, compile macro and options to private target #
set(MODULE_INCLUDE_PRI
    ${LITEOSTOPDIR}/kernel/extended/include/
)

if(LOSCFG_PERF_HW_PMU)
    list(APPEND MODULE_INCLUDE_PRI ${LITEOSTOPDIR}/kernel/extended/perf)
endif()

set(MODULE_COPTS_PRI)
set(MODULE_ASOPTS_PRI)
set(MODULE_CXXOPTS_PRI)
set(MODULE_CMACRO_PRI)
set(MODULE_ASMACRO_PRI)
set(MODULE_CXXMACRO_PRI)

if(LOSCFG_BOX)
set(BOX_CFG_SRC_DIR ${LITEOS_PLATFORM}/box/boxes_cfg)
endif()

# add srcs to private target #
set(LOCAL_SRCS_y)
set(LOCAL_DIRS_y
    ${LITEOS_PLATFORM}
    ${LITEOS_PLATFORM}/extcmd
    ${LITEOS_PLATFORM}/flash
    ${BOX_CFG_SRC_DIR}
)

if(LOSCFG_BOX AND PERBOX_FILE)
if(NOT EXISTS ${PERBOX_FILE})
    file(WRITE ${PERBOX_FILE})
endif()
list(APPEND LOCAL_SRCS_y ${PERBOX_FILE})
endif()

list(APPEND LOCAL_SRCS_${LOSCFG_PLATFORM_ADAPT}
    ${LITEOS_PLATFORM}/os_adapt/os_adapt.c
)

file(GLOB LOCAL_ASMSRCS_LIST_TEMP RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        "${LITEOS_PLATFORM}/*.S"
)
list(REMOVE_ITEM LOCAL_ASMSRCS_LIST_TEMP ${LITEOS_PLATFORM}/board.ld.S)
if(NOT LOSCFG_LASLR)
list(REMOVE_ITEM LOCAL_ASMSRCS_LIST_TEMP ${LITEOS_PLATFORM}/aslr_func.S)
endif()
list(APPEND LOCAL_SRCS_y ${LOCAL_ASMSRCS_LIST_TEMP})

# add board special configuration #
if(NOT ${LOSCFG_FAMILY} STREQUAL "")
    set(FAMILY_CMAKE_PATH ${LITEOSTOPDIR}/targets/${LOSCFG_FAMILY}/family.cmake)
    if(EXISTS ${FAMILY_CMAKE_PATH})
        include(${FAMILY_CMAKE_PATH})
    endif()
else()
    set(BOARD_CMAKE_PATH ${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/board.cmake)
    if(EXISTS ${BOARD_CMAKE_PATH})
        include(${BOARD_CMAKE_PATH})
    endif()
endif()

FOREACH(CUR_DIR ${LOCAL_DIRS_y})
    aux_source_directory(${CUR_DIR} LOCAL_SRCS_y)
ENDFOREACH(CUR_DIR)

# set(LOCAL_SRCS ${LOCAL_SRCS_y})  # module.cmake will sort LOCAL_SRCS files
include(${MODULE})
