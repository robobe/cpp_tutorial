#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

int main(int argc, char const *argv[])
{
    auto my_logger = spdlog::basic_logger_mt("my_logger", "log.txt");

    my_logger->set_level(spdlog::level::debug);
    my_logger->debug("debug {}", "more data");
    my_logger->info("info {} {}", "data", 1);
    my_logger->warn("warn");
    my_logger->error("error");
    return 0;
}
