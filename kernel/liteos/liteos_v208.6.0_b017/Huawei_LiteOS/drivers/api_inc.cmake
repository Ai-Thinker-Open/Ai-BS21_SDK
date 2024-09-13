# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.

## ATTENTION: api_inc.cmake is about external api header files' path. ##
## DON'T ADD OTHER VARS IN IT ##

if(LOSCFG_DRIVERS_UART_LITEOS)
    set(LITEOS_UART_INCLUDE ${LITEOSTOPDIR}/drivers/uart/include)
endif()

if(LOSCFG_DRIVERS_IOMMU)
    set(LITEOS_IOMMU_INCLUDE ${LITEOSTOPDIR}/drivers/iommu/include)
endif()

if(LOSCFG_DRIVERS_BASE)
    set(LITEOS_DBASE_INCLUDE ${LITEOSTOPDIR}/drivers/base/include)
endif()

if(LOSCFG_DRIVERS_MMC)
    set(LITEOS_MMC_INCLUDE
	${LITEOSTOPDIR}/drivers/mmc/include
	${LITEOSTOPDIR}/${LITEOS_OPENSOURCE_PATHNAME}/freebsd/liteos/drivers/mmc/include
    )
endif()

if(LOSCFG_DRIVERS_CIPHER)
    set(LITEOS_CIPHER_INCLUDE
        ${LITEOSTOPDIR}/drivers/cipher/cipher/include
        ${LITEOSTOPDIR}/drivers/cipher/cipher/src/drv/cipher_v1.0/osal/include
        ${LITEOSTOPDIR}/drivers/cipher/cipher/src/drv/cipher_v1.0/drivers/core/include
        ${LITEOSTOPDIR}/drivers/cipher/cipher/src/drv/cipher_v1.0/drivers/crypto/include
        ${LITEOSTOPDIR}/drivers/cipher/osal/include
        ${LITEOSTOPDIR}/drivers/cipher/sample
        ${LITEOSTOPDIR}/drivers/cipher/hi_include
    )
endif()

if(LOSCFG_DRIVERS_USB)
    set(LITEOS_USB_INCLUDE
        ${LITEOSTOPDIR}/drivers/usb/include
    )
endif()

if(LOSCFG_DRIVERS_VIDEO)
    set(LITEOS_VIDEO_INCLUDE ${LITEOSTOPDIR}/${LITEOS_OPENSOURCE_PATHNAME}/incubator-nuttx/liteos/drivers/video/include)
endif()

set(LITEOS_DRIVERS_INCLUDE
    ${LITEOSTOPDIR}/drivers/interrupt/include
    ${LITEOSTOPDIR}/drivers/timer/include
)

if(LOSCFG_DRIVERS_RANDOM)
    set(LITEOS_RANDOM_INCLUDE ${LITEOSTOPDIR}/drivers/random/include)
endif()

list(APPEND LITEOS_DRIVERS_INCLUDE
    ${LITEOS_MMC_INCLUDE}
    ${LITEOS_USB_INCLUDE}
    ${LITEOS_DBASE_INCLUDE}
    ${LITEOS_CIPHER_INCLUDE}
    ${LITEOS_VIDEO_INCLUDE}
    ${LITEOS_RANDOM_INCLUDE}
    ${LITEOS_IOMMU_INCLUDE}
)

if (LOSCFG_DRIVERS_USE_VENDOR_HISI_CAMERA)
    if (EXISTS ${LITEOSTOPDIR}/${LOSCFG_DRIVERS_VENDOR_PATH}/api_inc.cmake)
        include (${LITEOSTOPDIR}/${LOSCFG_DRIVERS_VENDOR_PATH}/api_inc.cmake)
    endif()
endif()
