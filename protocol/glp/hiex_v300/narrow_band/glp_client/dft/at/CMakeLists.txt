if (BUILD_HICFBB_GLP)
    set(
        glp_at_header_list
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    set(GLP_CLIENT_PUBLIC_HEADER_LIST "${GLP_CLIENT_PUBLIC_HEADER_LIST}" "${glp_at_header_list}" CACHE INTERNAL "glp obj list"
        FORCE)
else()
    target_include_directories(
        ${glp_client_target}
        PRIVATE
        "$(CMAKE_CURRENT_SOURCE_DIR)"
    )
endif()

set(
    glp_at_list
    ${CMAKE_CURRENT_SOURCE_DIR}/slp_at.c
)
set(GLP_CLIENT_LIST "${GLP_CLIENT_LIST}" "${glp_at_list}" CACHE INTERNAL "glp obj list" FORCE)