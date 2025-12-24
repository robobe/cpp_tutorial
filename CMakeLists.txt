cmake_minimum_required(VERSION 3.16)
project(protobuf_cpp_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/protobuf)
add_subdirectory(src/zmq)
add_subdirectory(src/msgpack)