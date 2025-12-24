#include <iostream>
#include "person.pb.h"

int main() {
  example::Person p;
  p.set_name("Alice");
  p.set_age(30);

  std::string data;
  p.SerializeToString(&data);
    
  example::Person q;
  q.ParseFromString(data);

  std::cout << "Name: " << q.name() << ", Age: " << q.age() << std::endl;
  return 0;
}
