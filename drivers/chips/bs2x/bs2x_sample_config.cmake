#===============================================================================
# @brief    cmake file
# Copyright (c) @CompanyNameMagicTag 2024-2024. All rights reserved.
#===============================================================================

# bs2x rcu sample depends defines
if(DEFINED CONFIG_SAMPLE_SUPPORT_RCU)
    list(APPEND DEFINES
        "NO_BOOT_BACKUP"
        "USE_OSAL_INSTEAD_CMSIS"
    )
    list(APPEND PUBLIC_DEFINES
        "NO_BOOT_BACKUP"
        "USE_OSAL_INSTEAD_CMSIS"
    )
    list(REMOVE_ITEM DEFINES
        "AT_COMMAND"
    )
endif()

if(DEFINED CONFIG_ULTRA_DEEP_SLEEP_ENABLE)
    list(APPEND DEFINES
        "CONFIG_ULTRA_DEEP_SLEEP_ENABLE"
    )
    list(APPEND PUBLIC_DEFINES
        "CONFIG_ULTRA_DEEP_SLEEP_ENABLE"
    )
endif()

if(DEFINED CONFIG_SAMPLE_SUPPORT_AIR_MOUSE)
    list(APPEND DEFINES
        "SUPPORT_SLEM_PERIPHERAL"
        "CONFIG_BT_SLE_ONLY"
    )
    list(APPEND PUBLIC_DEFINES
        "SUPPORT_SLEM_PERIPHERAL"
        "CONFIG_BT_SLE_ONLY"
    )
endif()

if(DEFINED CONFIG_SAMPLE_SUPPORT_AIR_MOUSE_DONGLE)
    list(APPEND DEFINES
        "SUPPORT_SLEM_CENTRAL"
        "CONFIG_BT_SLE_ONLY"
    )
    list(APPEND PUBLIC_DEFINES
        "SUPPORT_SLEM_CENTRAL"
        "CONFIG_BT_SLE_ONLY"
    )
endif()

if(DEFINED CONFIG_SAMPLE_SUPPORT_SLE_MEASURE_DIS)
    list(APPEND DEFINES
        "SLEM_CARKEY"
        "MEASURE_DIS"
        "EM_32K_SUPPORT"
    )
    list(APPEND PUBLIC_DEFINES
        "SLEM_CARKEY"
        "MEASURE_DIS"
        "EM_32K_SUPPORT"
    )
endif()

if(DEFINED CONFIG_SUPPORT_LOG_THREAD)
    list(APPEND DEFINES
        "CONFIG_SUPPORT_LOG_THREAD"
    )
    list(APPEND PUBLIC_DEFINES
        "CONFIG_SUPPORT_LOG_THREAD"
    )
endif()

set(DEFINES ${DEFINES} CACHE INTERNAL "" FORCE)