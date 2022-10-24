#include <iostream>
#include <fmt/core.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "world";
    fmt::print("hello {}\n", s);
    auto data = fmt::format("{1} {0}", "hello", 1, 2, 3);
    cout << data << endl;
    return 0;
}
