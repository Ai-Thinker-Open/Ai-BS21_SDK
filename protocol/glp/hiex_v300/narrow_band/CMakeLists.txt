cmake_minimum_required(VERSION 3.14)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../../open_source/libboundscheck/include")
    set(LIBC_SEC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../open_source/libboundscheck/include")
    set(SIMULATOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../test/glp/hiex_v300/simulator")
else()
    set(LIBC_SEC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../platform/hi1106/libc_sec")
    set(SIMULATOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../llt/glp/hiex_v300/simulator")
endif()

if(${project_name} MATCHES "hi1162")
    if ("SUPPORT_SLP_CLIENT" IN_LIST defines)
        include("compile_target_${project_name}.cmake")
    endif()
endif()

if(${CHIP} MATCHES "bs21|bs25")
    add_subdirectory(glp_client)
endif()

if(BUILD_SIMULATOR)
    include("compile_target_simulator.cmake")
endif()