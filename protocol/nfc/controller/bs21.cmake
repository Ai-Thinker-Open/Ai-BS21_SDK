#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================
set(MODULE_NAME "nfc")
set(COMPONENT_NAME "nfc_controller")

set(NFC_CHIP_TYPE "nfc_tag")
set(NFC_HOST "bt")

set(NFC_HEADER_LIST "" CACHE INTERNAL "nfc header file list" FORCE)
set(NFC_RAM_LIST "" CACHE INTERNAL "nfc ram obj list" FORCE)

add_subdirectory_if_exist(chip)
add_subdirectory_if_exist(nfc_core)

if("${NFC_RAM_LIST}" STREQUAL "")
    set(NFC_RAM_LIST "__null__")
endif()
set(SOURCES
    ${NFC_RAM_LIST}
)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/nfc_core/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/nfc_core/tag/platform_bs21
)

set(PRIVATE_HEADER
    ${NFC_HEADER_LIST}
)

set(PRIVATE_DEFINES
    "PLAT_BT"
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

set(LIB_OUT_PATH ${BIN_DIR}/${CHIP}/libs/nfc/${TARGET_COMMAND})

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/nfc_core/inc/log_def_nfc.h)
set(LOG_DEF ${CMAKE_CURRENT_SOURCE_DIR}/nfc_core/inc/log_def_nfc.h)
endif()

build_component()
