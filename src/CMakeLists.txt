add_subdirectory(collection_tutorials)
add_subdirectory(modern)
add_subdirectory(spdlog_tutorial)
# set(This my_project)

# set(HEADERS
#     helper.hpp
# )

# set(SOURCES
#     main.cpp
#     helper.cpp
# )

# add_executable(${This} ${SOURCES})
# target_include_directories(${This} 
#     PRIVATE
#     ${CMAKE_PROJECT_INCLUDE})
# add_library(${This}_lib STATIC ${SOURCES})

# message(${PROJECT_BINARY_DIR})
# message(${PROJECT_SOURCE_DIR})
# message(("-00000000000000000000000"))
# install(TARGETS ${This} 
#     RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
#     INCLUDES DESTINATION ${PROJECT_SOURCE_DIR}/bin/include
#     LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/bin/lib
#     ARCHIVE  DESTINATION ${PROJECT_SOURCE_DIR}/bin/lib
#     )
# install(FILES ${HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/bin/include)
# add_custom_command(TARGET ${This} POST_BUILD
# COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/bin/1)
# # configure_file(${This}-config.cmake.in ${PROJECT_BINARY_DIR}/${This}-config.cmake)