#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> data = {1,2,3,4};
    for (int i: data){
        cout << i << " ";
    }
    cout << endl;

    for (int& i: data){
        i++;
    }

    for (auto i: data){
        cout << i << " ";
    }
    cout << endl;
    
    data.push_back(5);
    cout << data.at(1) << endl;
    
    data.pop_back();
    return 0;
}
