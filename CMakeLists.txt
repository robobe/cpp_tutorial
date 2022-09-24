cmake_minimum_required(VERSION 3.8)

project(ExampleProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)

enable_testing()