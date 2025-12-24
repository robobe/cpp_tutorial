#include <iostream>
#include <vector>
#include <msgpack.hpp>

// Define a simple struct
struct Person {
  std::string name;
  int age;

  // Enable msgpack support
  MSGPACK_DEFINE(name, age);
};

int main() {
  // ----- Create object -----
  Person p1;
  p1.name = "Alice";
  p1.age = 30;

  // ----- Serialize to buffer -----
  msgpack::sbuffer buffer;
  msgpack::pack(buffer, p1);

  std::cout << "Serialized size: " << buffer.size() << " bytes\n";

  // ----- Deserialize from buffer -----
  msgpack::object_handle handle =
      msgpack::unpack(buffer.data(), buffer.size());

  msgpack::object obj = handle.get();

  Person p2;
  obj.convert(p2);

  // ----- Use result -----
  std::cout << "Name: " << p2.name
            << ", Age: " << p2.age << std::endl;

  return 0;
}
