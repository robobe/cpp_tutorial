#include <iostream>
#include <vector>
#include "person.pb.h"

int main() {
  example::Person p;
  p.set_name("Alice");
  p.set_age(30);

  // Allocate buffer of exact size
  const size_t size = p.ByteSizeLong();
  std::vector<uint8_t> buffer(size);

  // Serialize into raw array
  if (!p.SerializeToArray(buffer.data(), buffer.size())) {
    std::cerr << "Serialization failed\n";
    return 1;
  }

  example::Person q;
  // Parse from raw array
  if (!q.ParseFromArray(buffer.data(), buffer.size())) {
    std::cerr << "Parse failed\n";
    return 1;
  }

  std::cout << "Name: " << q.name()
            << ", Age: " << q.age() << std::endl;

  return 0;
}
