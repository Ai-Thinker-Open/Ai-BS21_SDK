set(BOX_RESOURCE_PATH ${LITEOSTOPDIR}/targets/${LITEOS_PLATFORM}/box/boxes_cfg)
if (NOT EXISTS ${BOX_RESOURCE_PATH}/box_resource.cmake)
    return()
endif()
include(${BOX_RESOURCE_PATH}/box_resource.cmake)
set(LITEOS_PERBOX_SCRIPTPATH ${LITEOS_SCRIPTPATH}/perbox)
set(PERBOX_DIR ${OUT}/perbox)
set(PERBOX_FILE ${PERBOX_DIR}/perbox_var.c)
set(PERBOX_H_FILE ${PERBOX_DIR}/perbox_var.h)
set(AUTOGEN_PERBOX_VAR autogen_perbox_var)
add_custom_target(
    ${AUTOGEN_PERBOX_VAR} ALL
    DEPENDS ${PERBOX_FILE} ${PERBOX_H_FILE}
)

add_custom_command(
    OUTPUT ${PERBOX_FILE} ${PERBOX_H_FILE}
    COMMAND rm -rf ${PERBOX_DIR}
    COMMAND mkdir -p ${PERBOX_DIR}
    COMMAND python3 ${LITEOS_SCRIPTPATH}/autogen_perbox_var.py ${LOSCFG_BASE_BOX_MAX_LIMIT} ${PERBOX_DIR} ${BOX_RESOURCE_FILE}
)
