#include <iostream>
#include <tuple>

using namespace std;

int main(int argc, char const *argv[])
{
    std::tuple<int, string, double> data;
    data = {1, "aaa", 10.0};
    cout << get<int>(data) << endl;
    cout << get<1>(data) << endl;

    // unpack
    auto [n, m, d] = data;
    cout << m << endl;

    // using
    using my_tuple = std::tuple<int, string, int>;
    my_tuple data1 = make_tuple(1, "a", 2);
    cout << get<1>(data1) << endl;
    return 0;
}
