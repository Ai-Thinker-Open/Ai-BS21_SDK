#===============================================================================
# @brief    nfc cmake file
# Copyright (c) CompanyNameMagicTag 2023. All rights reserved.
#===============================================================================

set(COMPONENT_NAME "nfc_header")

set(SOURCES
)

if(DEFINED CONFIG_ENABLE_NFC_CONTROLLER_SAMPLE)
    add_subdirectory_if_exist(controller)
endif()

if(DEFINED CONFIG_ENABLE_NFC_TAG_SAMPLE)
	set(PUBLIC_HEADER "${PUBLIC_HEADER}"
		${CMAKE_CURRENT_SOURCE_DIR}/tag
	)
endif()

set(PUBLIC_DEFINES
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
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

build_component()