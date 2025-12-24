
find_package(Protobuf REQUIRED)

# Generate C++ sources from .proto files
set(PROTO_FILES
  proto/person.proto
#   proto/address.proto
#   proto/company.proto
)
#build the protobuf files to curent binary dir
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_executable(example
  hello.cpp
  ${PROTO_SRCS}
)

target_include_directories(example PRIVATE ${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(example PRIVATE ${Protobuf_LIBRARIES})

# array buffer example good for zmq
add_executable(array_buffer_example
  buffer_example.cpp
  ${PROTO_SRCS}
)

target_include_directories(array_buffer_example PRIVATE ${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(array_buffer_example PRIVATE ${Protobuf_LIBRARIES})

# json example
add_executable(json_example
  json_example.cpp
  ${PROTO_SRCS}
)

target_include_directories(json_example PRIVATE ${Protobuf_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(json_example PRIVATE ${Protobuf_LIBRARIES})
target_link_libraries(array_buffer_example PRIVATE ${Protobuf_LIBRARIES})

