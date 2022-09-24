set(This my_project)

set(HEADERS
    helper.hpp
)

set(SOURCES
    main.cpp
    helper.cpp
)

add_executable(${This} ${SOURCES})
target_include_directories(${This} 
    PRIVATE
    ${CMAKE_PROJECT_INCLUDE})
add_library(${This}_lib STATIC ${SOURCES})