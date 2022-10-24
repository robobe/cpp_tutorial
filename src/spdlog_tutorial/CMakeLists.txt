find_package(spdlog REQUIRED)

add_executable(hello_spd hello_spd.cpp)
target_link_libraries(hello_spd PRIVATE spdlog::spdlog_header_only)