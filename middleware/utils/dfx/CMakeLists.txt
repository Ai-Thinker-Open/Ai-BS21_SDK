#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
#===============================================================================

add_subdirectory_if_exist(dfx_reboot/cpu_utils)
add_subdirectory_if_exist(dfx_reboot/reboot)
add_subdirectory_if_exist(diag_dfx_cmd)
add_subdirectory_if_exist(file_operation)

set(COMPONENT_NAME "dfx_diag")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

if(NOT "SUPPORT_DIAG_V2_PROTOCOL" IN_LIST DEFINES)
    set(PUBLIC_HEADER
        ${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/dfx_include
        ${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/include
        ${CMAKE_CURRENT_SOURCE_DIR}/write_interface/include
        ${CMAKE_CURRENT_SOURCE_DIR}/zdiag
        ${CMAKE_CURRENT_SOURCE_DIR}/zdiag/dfx_include
        ${CMAKE_CURRENT_SOURCE_DIR}/zdiag/include
        ${CMAKE_CURRENT_SOURCE_DIR}/zdiag/diag_system_cmd/dfx_include
        ${CMAKE_CURRENT_SOURCE_DIR}/zdiag/diag_system_cmd/include
    )
else()
    set(PUBLIC_HEADER
        ${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/dfx_include
        ${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/include
        ${CMAKE_CURRENT_SOURCE_DIR}/write_interface/include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag
        ${CMAKE_CURRENT_SOURCE_DIR}/diag/dfx_include
        ${CMAKE_CURRENT_SOURCE_DIR}/soc_log/include
        ${CMAKE_CURRENT_SOURCE_DIR}/log_file/include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag/include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag/diag_cmd_router/include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag/diag_system_cmd/dfx_include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag/diag_system_cmd/include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag_transmit/include
        ${CMAKE_CURRENT_SOURCE_DIR}/diag_transmit/dfx_include
    )
endif()

if(NOT "SUPPORT_DIAG_V2_PROTOCOL" IN_LIST DEFINES)
    set(PRIVATE_HEADER
    )

else()
    set(PRIVATE_HEADER
        ${CMAKE_CURRENT_SOURCE_DIR}/diag_transmit/
    )
endif()

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

if(NOT "SUPPORT_DIAG_V2_PROTOCOL" IN_LIST DEFINES)
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/zdiag/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/zdiag/dfx_include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/zdiag/diag_system_cmd/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/zdiag/diag_system_cmd/dfx_include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/write_interface/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/dfx_include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/include/" "*.h")
else()
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag/dfx_include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag/diag_cmd_router/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag/diag_system_cmd/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag/diag_system_cmd/dfx_include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/diag_transmit/dfx_include/" "transmit_st.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/write_interface/include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/dfx_include/" "*.h")
    install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/dfx_os/include/" "*.h")
endif()

build_component()


set(COMPONENT_NAME "soc_log")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/soc_log/include
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_PANIC
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/soc_log/include/" "*.h")

build_component()


set(COMPONENT_NAME "log_file")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/log_file/include
)

set(PRIVATE_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/log_file/
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_PANIC
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/log_file/include/" "*.h")

build_component()


set(COMPONENT_NAME "boot_msg")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/boot_msg/include
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_PANIC
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/boot_msg/include/" "*.h")

build_component()


set(COMPONENT_NAME "dfx_panic")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/panic/private
    ${CMAKE_CURRENT_SOURCE_DIR}/panic/public
)

if(NOT "SUPPORT_DIAG_V2_PROTOCOL" IN_LIST DEFINES)
    set(PRIVATE_HEADER
        ${CMAKE_CURRENT_SOURCE_DIR}/zdiag/include
    )
else()
    set(PRIVATE_HEADER
        ${CMAKE_CURRENT_SOURCE_DIR}/diag/include
    )
endif()

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_PANIC
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/panic/public/" "*.h")

build_component()

set(COMPONENT_NAME "dfx_preserve")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/preserve/public
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_PRESERVE
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/preserve/public/" "*.h")

build_component()

set(COMPONENT_NAME "dfx_log")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/log/include
    ${CMAKE_CURRENT_SOURCE_DIR}/log_buffer
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_LOG
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/log/include/" "*.h")
install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/log_buffer/" "*.h")

build_component()


set(COMPONENT_NAME "dfx_log_reader")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/log_reader/include
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_LOG
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/log_reader/include/" "*.h")

build_component()


set(COMPONENT_NAME "dfx_printer")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/dfx_print/
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

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/dfx_print/" "*.h")

build_component()


set(COMPONENT_NAME "dfx_massdata")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/massdata
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
)

set(PUBLIC_DEFINES
    SUPPORT_DFX_LOG
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

install_sdk_by_sh("${CMAKE_CURRENT_SOURCE_DIR}/massdata/" "*.h")

build_component()

