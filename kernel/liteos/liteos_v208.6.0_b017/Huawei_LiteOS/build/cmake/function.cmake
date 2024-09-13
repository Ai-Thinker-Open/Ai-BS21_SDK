
function(IMPORT_BOARD_CONFIG PREPEND_CONFIG VALID_CONFIG_INPUT CONFIG_OUTPUT_FILE)
    # Parse entries prefixed with 'PREPEND_CONFIG' in ${VALID_CONFIG_INPUT}
    file(STRINGS ${VALID_CONFIG_INPUT} LOS_CONFIG_LIST REGEX "^${PREPEND_CONFIG}" ENCODING "UTF-8")

    foreach (LOSCFG ${LOS_CONFIG_LIST})
        # LOSCFG maybe: LOSCFG_CC_STACKPROTECTOR_STRONG=y

        # The first: variable name
        string(REGEX MATCH "[^=]+" LOSCFG_VAR_NAME "${LOSCFG}")

        # The second: variable value
        string(REGEX MATCH "=(.+$)" LOSCFG_VAR_VAL "${LOSCFG}")
        set(LOSCFG_VAR_VAL ${CMAKE_MATCH_1})

        # write to menuconfig.h
        if(CONFIG_OUTPUT_FILE)
            if(LOSCFG_VAR_VAL MATCHES "^y$")
                file(APPEND ${CONFIG_OUTPUT_FILE} "#define ${LOSCFG_VAR_NAME} 1\n")
            else()
                file(APPEND ${CONFIG_OUTPUT_FILE} "#define ${LOSCFG_VAR_NAME} ${LOSCFG_VAR_VAL}\n")
            endif()
        endif()

        # remove quotes
        if("${LOSCFG_VAR_VAL}" MATCHES "^\"(.*)\"$")
            set(LOSCFG_VAR_VAL ${CMAKE_MATCH_1})
        endif()

        # config globally
        set(${LOSCFG_VAR_NAME} ${LOSCFG_VAR_VAL} PARENT_SCOPE)
        MESSAGE("${LOSCFG_VAR_NAME} is set to ${LOSCFG_VAR_VAL}")
    endforeach()
endfunction()

function(check_program_exists program_name return_val)
    execute_process(
        COMMAND bash -c "which ${program_name}"
        RESULT_VARIABLE _result
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
    if(_result EQUAL 0)
        # found
        set(${return_val} TRUE PARENT_SCOPE)
    else()
        # not found
        set(${return_val} FALSE PARENT_SCOPE)
    endif()
endfunction()