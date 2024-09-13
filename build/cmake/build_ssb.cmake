#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved.
#===============================================================================

if(DEFINED APPLICATION)
if(${APPLICATION} STREQUAL "ssb")
add_custom_target(ADD_SHA_TO_SSB ALL
    COMMAND ${Python3_EXECUTABLE} ${BUILD_UTILS} add_len_and_sha256_info_to_ssb ${TARGET_NAME}.bin ${CHIP}
    COMMENT "add ssb length and sha256 info into ssb.bin"
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS GENERAT_BIN
)
if (${UPDATE_BIN})
string(REPLACE "_" "-" TARGET_DIR ${BUILD_TARGET_NAME})
if (NOT EXISTS ${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin)
    file(MAKE_DIRECTORY ${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin)
endif()
if (NOT EXISTS ${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${TARGET_DIR})
    file(MAKE_DIRECTORY ${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${TARGET_DIR})
endif()
add_custom_target(COPY_SSB_BIN ALL
    COMMAND ${CP} ${ROOT_DIR}/output/${CHIP}/acore/${TARGET_DIR}/ssb.bin ${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${TARGET_DIR}/ssb.bin
    COMMENT "copy bin file"
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    DEPENDS ADD_SHA_TO_SSB
)
endif()
endif()
endif()

if(NOT "${SSB_CFG}" STREQUAL "")
add_custom_target(COPY_PKG_SSB_BIN ALL
    COMMAND ${CP} ${ROOT_DIR}/interim_binary/${CHIP}/bin/boot_bin/${SSB_CFG}/ssb.bin ${ROOT_DIR}/interim_binary/${CHIP}/bin/ssb.bin
    COMMENT "copy ssb bin file"
    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
)
endif()
