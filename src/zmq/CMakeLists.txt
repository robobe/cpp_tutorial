set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#  Ubuntu’s ZeroMQ does not provide ZeroMQConfig.cmake, 
#  so you must use pkg-config or link directly instead of find_package(ZeroMQ).
find_package(PkgConfig REQUIRED)
pkg_check_modules(ZMQ REQUIRED libzmq)
find_package(Protobuf REQUIRED)


add_executable(publisher pub.cpp)
add_executable(subscriber sub.cpp)

target_include_directories(publisher PRIVATE ${ZMQ_INCLUDE_DIRS})
target_include_directories(subscriber PRIVATE ${ZMQ_INCLUDE_DIRS})

target_link_libraries(publisher PRIVATE ${ZMQ_LIBRARIES})
target_link_libraries(subscriber PRIVATE ${ZMQ_LIBRARIES})

# pub with protobuf
# Generate C++ sources from .proto files
set(PROTO_FILES
  ../protobuf/proto/person.proto
)
#build the protobuf files to curent binary dir
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_executable(pub_proto pub_proto.cpp ${PROTO_SRCS})
target_include_directories(pub_proto PRIVATE ${ZMQ_INCLUDE_DIRS} 
    ${Protobuf_INCLUDE_DIRS} 
    ${CMAKE_CURRENT_BINARY_DIR})  # Adjust the path as necessary
target_link_libraries(pub_proto PRIVATE ${ZMQ_LIBRARIES} ${Protobuf_LIBRARIES})

# sub with protobuf
add_executable(sub_proto sub_proto.cpp ${PROTO_SRCS})
target_include_directories(sub_proto PRIVATE ${ZMQ_INCLUDE_DIRS} 
    ${Protobuf_INCLUDE_DIRS} 
    ${CMAKE_CURRENT_BINARY_DIR})  # Adjust the path as necessary
target_link_libraries(sub_proto PRIVATE ${ZMQ_LIBRARIES} ${Protobuf_LIBRARIES})