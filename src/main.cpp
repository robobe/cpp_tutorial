#include <iostream>
#include <helper.hpp>
#include <functional>
#include <thread>
#include <tuple>

void func(int a, int b){
    std::cout << a + b << std::endl;
}

void func_nothing(){
    std::cout << "do nothing function" << std::endl;
}

int main(int argc, char const *argv[])
{
    auto data = std::make_tuple(1, "a", 2.3);
    const auto[a, b, c] = data;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    return 0;
}


