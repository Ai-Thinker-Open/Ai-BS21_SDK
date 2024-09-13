if (BUILD_HICFBB_GLP)
    set(
        utils_header_list
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    set(GLP_CLIENT_PUBLIC_HEADER_LIST "${GLP_CLIENT_PUBLIC_HEADER_LIST}" "${utils_header_list}" CACHE INTERNAL
        "glp obj list" FORCE)
else()
    target_include_directories(
        ${glp_client_target}
        PRIVATE
        "$(CMAKE_CURRENT_SOURCE_DIR)"
    )
endif()

set(
    utils_list
    ${CMAKE_CURRENT_SOURCE_DIR}/log_utils.c
)
set(GLP_CLIENT_LIST "${GLP_CLIENT_LIST}" "${utils_list}" CACHE INTERNAL "glp obj list" FORCE)