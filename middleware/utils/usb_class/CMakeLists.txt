set(MODULE_NAME usb_class)
set(COMPONENT_NAME "usb_class")

set(USB_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../)
get_filename_component(ROOT_DIR  "${PROJECT_SOURCE_DIR}" ABSOLUTE)
set(OPENSOURCE_PATH ${ROOT_DIR}/kernel/liteos/liteos_v208.6.0_b017/Huawei_LiteOS/open_source)

set(FREEBSD_USB_PATH ${OPENSOURCE_PATH}/freebsd/liteos/drivers/usb)
set(NUTTX_USB_PATH ${OPENSOURCE_PATH}/incubator-nuttx/liteos/drivers/usb)
set(NUTTX_USB_GADGET_PATH ${NUTTX_USB_PATH}/gadget)
set(NUTTX_USB_HEAD_PATH ${ROOT_DIR}/kernel/liteos/liteos_v208.6.0_b017/Huawei_LiteOS/compat/nuttx/include)

set(ADAPT_OS adapt_liteos)
set(ADAPT_OS_PATH ${USB_ROOT_PATH}/${ADAPT_OS})
set(ADAPT_OS_FREEBSD_USB_PATH ${FREEBSD_USB_PATH}/${ADAPT_OS})

# add global include, compile macro and options to public target #
set(MODULE_INCLUDE_PUB)
set(MODULE_CXXINCLUDE_PUB)
set(MODULE_COPTS_PUB)
set(MODULE_ASOPTS_PUB)
set(MODULE_CXXOPTS_PUB)
set(MODULE_CMACRO_PUB)
set(MODULE_ASMACRO_PUB)
set(MODULE_CXXMACRO_PUB)

# add local include, compile macro and options to private target #
set(MODULE_INCLUDE_PRI
    ${USB_ROOT_PATH}
    ${ADAPT_OS_PATH}
    ${NUTTX_USB_PATH}
    ${NUTTX_USB_HEAD_PATH}
    ${NUTTX_USB_GADGET_PATH}
)

if(CONFIG_DRIVERS_USB_HOST_DRIVER)
    list(APPEND MODULE_INCLUDE_PRI
        ${FREEBSD_USB_PATH}
        ${ADAPT_OS_FREEBSD_USB_PATH}
    )
endif()

set(MODULE_COPTS_PRI ${LITEOS_SUGGESTED_COMPILE_OPTS})
set(MODULE_ASOPTS_PRI)
set(MODULE_CXXOPTS_PRI)
set(MODULE_CMACRO_PRI)
set(MODULE_ASMACRO_PRI)
set(MODULE_CXXMACRO_PRI)

if(${CONFIG_USB_DMA_OFFSET} MATCHES "0x")
list(APPEND MODULE_CMACRO_PRI CFG_USB_DMA_OFFSET=${CONFIG_USB_DMA_OFFSET})
endif()

# add srcs to private target #
set(LOCAL_SRCS_y)
set(LOCAL_DIRS_y)

# list(APPEND LOCAL_SRCS_${CONFIG_DRIVERS_USB_COMPOSITE_GADGET}
#     ${CMAKE_CURRENT_SOURCE_DIR}/composite_open.c
# )

# if(CONFIG_DRIVERS_USB_UVC_GADGET OR CONFIG_DRIVERS_USB_CAMERA_GADGET)
#     list(APPEND LOCAL_SRCS_y
#         f_uvc_open.c
#         usbd_video_ioctl_open.c
#     )
# endif()

# if(CONFIG_DRIVERS_USB_MASS_STORAGE_GADGET)
#     list(APPEND LOCAL_SRCS_y
#         f_mass_storage_ram_open.c
#     )

# endif()

# list(APPEND LOCAL_SRCS_${CONFIG_DRIVERS_USB_MASS_STORAGE_GADGET}
#     ${FREEBSD_GADGET_SRC}/f_mass_storage_open.c
#     f_mass_storage_ram_open.c
# )

# list(APPEND LOCAL_SRCS_${CONFIG_DRIVERS_USB_COMPOSITE_GADGET}
#     ${CMAKE_CURRENT_SOURCE_DIR}/composite_adapter.c
#     ${NUTTX_USB_GADGET_PATH}/composite.c
# )

# list(APPEND LOCAL_SRCS_${CONFIG_DRIVERS_USB_ETH_SER_GADGET} f_multi.c)

# list(APPEND LOCAL_SRCS_y
#     ${CMAKE_CURRENT_SOURCE_DIR}/usbd_acm.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_acm.c
# )

# if(CONFIG_DRIVERS_USB_ETHERNET_GADGET OR CONFIG_DRIVERS_USB_ETH_SER_GADGET)
#     list(APPEND LOCAL_SRCS_y ${NUTTX_USB_GADGET_PATH}/rndis.c f_ether.c)
#     aux_source_directory(${NUTTX_USB_GADGET_PATH}/queue NUTTX_QUEUE_SRCS)
#     list(APPEND LOCAL_SRCS_y ${NUTTX_QUEUE_SRCS})
# endif()

# list(APPEND LOCAL_SRCS_y
#      ${CMAKE_CURRENT_SOURCE_DIR}/usbd_hid.c)

# if(DEFINED CONFIG_DRIVERS_USB_HID_CUSTOM)
#     list(APPEND LOCAL_SRCS_y
#         ${CMAKE_CURRENT_SOURCE_DIR}/f_hid_custom.c)
# else()
#     list(APPEND LOCAL_SRCS_y
#         ${CMAKE_CURRENT_SOURCE_DIR}/f_hid.c)
# endif()

# list(APPEND LOCAL_SRCS_y
#      ${CMAKE_CURRENT_SOURCE_DIR}/f_uac_hid.c)

# list(APPEND LOCAL_SRCS_y
#      ${CMAKE_CURRENT_SOURCE_DIR}/f_acm_hid.c)

# list(APPEND LOCAL_SRCS_y
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_dfu.c
# )

# if(CONFIG_DRIVERS_USB_UVC_GADGET OR CONFIG_DRIVERS_USB_CAMERA_GADGET)
#     list(APPEND LOCAL_SRCS_y usbd_video.c camera_control.c)
# endif()

# list(APPEND LOCAL_SRCS_y
#     ${CMAKE_CURRENT_SOURCE_DIR}/usbd_audio.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_uac.c
# )

# list(APPEND LOCAL_SRCS_y ${CMAKE_CURRENT_SOURCE_DIR}/f_usb_custom.c)

# list(APPEND LOCAL_SRCS_${CONFIG_DRIVERS_USB_CAMERA_GADGET} f_camera.c)

# set(OPEN_SOURCES
#     ${CMAKE_CURRENT_SOURCE_DIR}/composite_open.c
#     ${NUTTX_USB_GADGET_PATH}/composite.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_hid.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_hid_custom.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_dfu.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_uac.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_uac_hid.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_acm.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_acm_hid.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_mass_storage_ram_open.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_uvc_open.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/usbd_hid.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/usbd_video_ioctl_open.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_usb_custom.c
# )

# if("BUILD_FLASHBOOT" IN_LIST DEFINES)
# set(LOCAL_SRCS_y 
#     ${CMAKE_CURRENT_SOURCE_DIR}/f_dfu.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/composite_open.c
#     ${CMAKE_CURRENT_SOURCE_DIR}/composite_adapter.c
#     ${NUTTX_USB_GADGET_PATH}/composite.c
# )
# endif()

# set(OPEN_SOURCES_TEMP "${OPEN_SOURCES}")
# foreach(src ${OPEN_SOURCES_TEMP})
#     message(STATUS ${src})
#     if (${src} IN_LIST LOCAL_SRCS_y)
#         list(REMOVE_ITEM LOCAL_SRCS_y ${src})
#     else()
#         list(REMOVE_ITEM OPEN_SOURCES ${src})
#     endif()
# endforeach()

# for sdk closed package
if(NOT DEFINED CONFIG_DRIVERS_USB_UAC_GADGET)
    set(USBD_DEFINES 
        CONFIG_DRIVERS_USB_UAC_GADGET_VER_1_0
        CONFIG_DRIVERS_USB_UAC_GADGET_VER_1_0_SPEAKER
    )
endif()

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/standard-bs21-n1100/lib${COMPONENT_NAME}.a)

set(PUBLIC_DEFINES
)

set(PRIVATE_DEFINES ${USBD_DEFINES})

set(PUBLIC_HEADER
    ${MODULE_INCLUDE_PRI}
)

# use this when you want to add ccflags like -include xxx
set(COMPONENT_PUBLIC_CCFLAGS
)

set(COMPONENT_CCFLAGS
    -Wno-unused-parameter
    -Wno-unused-variable
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)

build_component()

set(COMPONENT_NAME "usb_class_open")

set(LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lib${COMPONENT_NAME}.a)

set(PUBLIC_HEADER
)

set(PRIVATE_HEADER
)

set(PRIVATE_DEFINES
${USBD_DEFINES}
)

set(PUBLIC_DEFINES
)

# use this when you want to add ccflags like -include xxx
set(COMPONENT_PUBLIC_CCFLAGS
)

set(COMPONENT_CCFLAGS
-Wno-unused-parameter
-Wno-unused-variable
)

set(WHOLE_LINK
    true
)

set(MAIN_COMPONENT
    false
)
return_if_not_build()
install_sdk(${CMAKE_CURRENT_SOURCE_DIR} "f_hid_custom.c")
build_component()
