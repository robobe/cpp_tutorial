#include <iostream>
#include <variant>
#include <any>
#include <optional>

using namespace std;

void play_variant(){
    variant<int, float> v1;
    v1 = 10;
    cout << get<int>(v1) << endl;

    variant<int, float> v2;
    v2 = 10.2f;
    cout << get<1>(v2) << endl;

    v1 = v2;
    cout << get<1>(v1) << endl;
}

void play_any(){
    cout << "======== any =======" << endl;
    any a;
    a = 1;
    cout << any_cast<int>(a) << endl;

    a = 3.14;
    cout << any_cast<double>(a) << endl;

    a = true;
    cout << boolalpha << any_cast<bool>(a) << endl;
}

std::optional<string> factory(bool create){
    if (create){
        return "string create";
    }
    return {};
}

void play_optional(){
    cout << "========== optional =======" << endl;
    auto data = factory(true);
    cout << data.value() << endl;

    auto data1 = factory(false);
    cout << data1.value_or("no data") << endl;

    if (data1.has_value())
    {
        cout << "+++++++++++" << endl;
    }
}



int main(int argc, char const *argv[])
{
    play_variant();    
    play_any();
    play_optional();

    return 0;
}
