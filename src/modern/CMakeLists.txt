find_package(spdlog REQUIRED)
find_package(fmt REQUIRED)

add_executable(hello_modern hello.cpp)
add_executable(chrono_hello chrono_hello.cpp)
target_link_libraries(chrono_hello PRIVATE spdlog::spdlog_header_only)

add_executable(fmt_hello fmt_hello.cpp)
target_link_libraries(fmt_hello PRIVATE fmt::fmt)

add_executable(move_demo move_demo.cpp)

add_executable(filesystem_hello filesystem_hello.cpp)

