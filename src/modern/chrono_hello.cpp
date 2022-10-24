#include <iostream>
#include <chrono>
#include <thread>
#include <spdlog/spdlog.h>

using namespace std;

int main(int argc, char const *argv[])
{
    spdlog::info("hello my app");
    auto start = chrono::steady_clock::now();
    std::this_thread::sleep_for(chrono::seconds(1));
    auto end = chrono::steady_clock::now();

    chrono::duration<double> sec = end - start;
    
    spdlog::warn("run time: {}", sec.count()); ;
    return 0;
}
