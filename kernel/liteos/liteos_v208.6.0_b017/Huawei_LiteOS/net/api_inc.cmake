# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.

if(LOSCFG_NET_LWIP_SACK)
    list(APPEND LITEOS_DEP_LIBS_INT lwip)
    set(LITEOS_LWIP_SACK_INCLUDE ${LITEOSTOPDIR}/net/RivulNet/open_source/lwip/lwip-2.1.2/src/include)
    list(APPEND LITEOS_CMACRO LWIP_CONFIG_FILE=\"lwip/lwipopts.h\")
endif()

if(LOSCFG_NET_TELNET)
    set(LITEOS_TELNET_INCLUDE ${LITEOSTOPDIR}/net/telnet/include)
endif()

if(LOSCFG_NET_IPERF)
    set(LITEOS_IPERF_INCLUDE net/los_iperf/include)
endif()


## ATTENTION: api_inc.cmake is about external api header files' path. ##
## DON'T ADD OTHER VARS IN IT ##
set(LITEOS_NET_INCLUDE
    ${LITEOS_LWIP_SACK_INCLUDE}
    ${LITEOS_TELNET_INCLUDE}
    ${LITEOS_IPERF_INCLUDE}
)

