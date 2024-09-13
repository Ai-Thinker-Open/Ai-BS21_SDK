message(STATUS "======= current project : ${PROJECT_NAME} - ${project_name} =======")

if (${project_name} MATCHES "6020_device")
    include(ca11.cmake)
elseif (${CHIP} MATCHES "bs20|bs21|bs21a|bs22|bs26")
    include(bs21.cmake)
elseif (${project_name} MATCHES "5612")
    include(wf56.cmake)
endif()
