set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MSGPACK REQUIRED msgpack)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ZMQ REQUIRED libzmq)

add_executable(hello hello.cpp)
target_include_directories(hello PRIVATE
  ${MSGPACK_INCLUDE_DIRS}
)
target_link_directories(hello PRIVATE
  ${MSGPACK_LIBRARY_DIRS}
)
target_link_libraries(hello PRIVATE
  ${MSGPACK_LIBRARIES}
)

# Publisher example
add_executable(pub_msg pub_msg.cpp)
target_include_directories(pub_msg PRIVATE ${MSGPACK_INCLUDE_DIRS} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(pub_msg PRIVATE ${MSGPACK_LIBRARIES} ${ZMQ_LIBRARIES})

# Subscriber example
add_executable(sub_msg sub_msg.cpp)
target_include_directories(sub_msg PRIVATE ${MSGPACK_INCLUDE_DIRS} ${ZMQ_INCLUDE_DIRS})
target_link_libraries(sub_msg PRIVATE ${MSGPACK_LIBRARIES} ${ZMQ_LIBRARIES})