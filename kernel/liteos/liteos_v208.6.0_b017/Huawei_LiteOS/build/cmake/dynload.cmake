
set(DYNLOADTESTDIR ${LITEOSTOPDIR}/${TEST_PATH}/sample/kernel/extend/dynload)


##### command to test dynload #####
set(DYNLOAD_POST_PROCESS)
if(LOSCFG_KERNEL_DYNLOAD AND EXISTS "${LITEOS_SCRIPTPATH}/dynload_tools/check_gsymbol.py")
    list(APPEND DYNLOAD_POST_PROCESS
        COMMAND ${PYTHON3} ${LITEOS_SCRIPTPATH}/dynload_tools/check_gsymbol.py ${OUT}/${LITEOS_TARGET}
    )
endif()

if(LOSCFG_KERNEL_DYNLOAD)
    list(APPEND BUILD_LINKER_POST_PROCESS ${DYNLOAD_POST_PROCESS})
endif()
