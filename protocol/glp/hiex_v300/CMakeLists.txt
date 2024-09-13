# 选择适配哪种窄带系统
set(BUILD_NB_WIFI OFF)
set(BUILD_NB_GLE ON)
set(BUILD_NB_HRF_FSK OFF)
set(BUILD_NB_HRF_OFDM OFF)
set(BUILD_NB_HRF_OQPSK OFF)

if(${CHIP} MATCHES "bs21|bs25")
    option(BUILD_HICFBB_GLP "Option for build hicfbb glp" ON) # 基于hicfbb平台编译glp
    include(bs2x.cmake)
endif()

if(BUILD_SIMULATOR)
    add_subdirectory(wide_band)
    add_subdirectory(narrow_band)
endif()