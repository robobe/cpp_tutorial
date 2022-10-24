#include <iostream>
#include <deque>

using namespace std;

void print_me(deque<int>& data){
    for(auto item: data){
        cout << item << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    deque<int> data = {1,2,3};
    data.push_back(4);
    data.push_front(5);

    print_me(data);

    data.pop_back();
    data.pop_front();

    print_me(data);
    return 0;
}
