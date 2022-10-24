#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> data;
    data.insert(1);
    data.insert(2);
    data.insert(1);
    data.insert(-1);

    for(auto item: data){
        cout << item << " ";
    }

    cout << endl;

    set<int> data1 = {1,2,3,-1,2};

    for(auto& item: data1){
        cout << item << " ";
    }
    return 0;
}

