set(ThisTests my_project_test)
set(This my_project)

set(HEADERS
    helper.hpp
)

set(SOURCES
    main.cpp
    func_test.cpp
)

add_executable(${ThisTests} ${SOURCES})
add_test(NAME ${ThisTests} COMMAND ${ThisTests})
target_link_libraries(${ThisTests} gtest ${This}_lib)
target_include_directories(${ThisTests}
    PRIVATE
    ${CMAKE_PROJECT_INCLUDE})