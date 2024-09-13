#===============================================================================
# @brief    cmake file
# Copyright (c) CompanyNameMagicTag 2022-2023. All rights reserved.
#===============================================================================
set(COMPONENT_NAME "cal_dis")

return_if_not_build()

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/KDE.c
    ${CMAKE_CURRENT_SOURCE_DIR}/basicMath.c
    ${CMAKE_CURRENT_SOURCE_DIR}/disalg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/smooth.c
    ${CMAKE_CURRENT_SOURCE_DIR}/alg_smooth_dis.c
)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/
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


set(LIBS
${CMAKE_CURRENT_SOURCE_DIR}/libf2c.a
${CMAKE_CURRENT_SOURCE_DIR}/lapack_LINUX.a
${CMAKE_CURRENT_SOURCE_DIR}/tmglib_LINUX.a
${CMAKE_CURRENT_SOURCE_DIR}/blas_LINUX.a
)

execute_process(
    COMMAND ${CP} ${LIBS} ${BIN_DIR}/${CHIP}/libs/bluetooth/btc/${TARGET_COMMAND}
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

set(PUBLIC_DEFINES

)

set(PRIVATE_DEFINES
)
install_sdk(${CMAKE_CURRENT_SOURCE_DIR} "*.h")
set(LIB_OUT_PATH ${BIN_DIR}/${CHIP}/libs/bluetooth/btc/${TARGET_COMMAND})
build_component()
