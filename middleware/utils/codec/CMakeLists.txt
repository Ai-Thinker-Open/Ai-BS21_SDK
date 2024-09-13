#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "codec")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
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

if(DEFINED CONFIG_CODEC_ENABLE_L2HC)
    set(LIBS
        ${CMAKE_CURRENT_SOURCE_DIR}/l2hc/libl2hc_dec_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/l2hc/libl2hc_dec_itcm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/l2hc/libl2hc_enc.a
    )
endif()
if(DEFINED CONFIG_CODEC_ENABLE_OPUS)
    set(LIBS
        ${CMAKE_CURRENT_SOURCE_DIR}/opus/libopus_dec_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opus/libopus_dec_itcm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opus/libopus_enc_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opus/libopus_enc_itcm.a
    )
endif()
if(DEFINED CONFIG_CODEC_ENABLE_SBC OR DEFINED CONFIG_CODEC_ENABLE_MSBC)
    set(LIBS
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_dec_all_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_dec_all_itcm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_dec_all_flash.a

        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_enc_all_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_enc_all_itcm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_enc_all_flash.a

        # 下面不重复添加会编译不过
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_dec_all_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_dec_all_itcm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_dec_all_flash.a

        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_enc_all_flash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_enc_all_itcm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/sbc_msbc/libsbc_enc_all_flash.a
    )
endif()

set(WHOLE_LINK
    false
)

set(MAIN_COMPONENT
    false
)

build_component()
