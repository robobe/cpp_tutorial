#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    float my_array[3] = {1, 2, 3};
    my_array[0] = 1.0;
    int arr_size = sizeof(my_array) / sizeof(my_array[0]);
    cout << "array size:" << arr_size << endl;
    for (const auto i : my_array)
    {
        cout << i << endl;
    }
    return 0;
}
