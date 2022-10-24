#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, int> data1 = {
        {"a", 10},
        {"b", 20}
    };

    map<string, int> data;
    data["a"]=1;
    data["b"]=2;

    for(auto t: data){
        cout << t.first << " " << t.second << endl;
    }

    data1["b"] = 30;
    for(auto t: data1){
        cout << t.first << " " << t.second << endl;
    }

    
    return 0;
}
