// subscriber.cpp
#include <zmq.hpp>
#include <msgpack.hpp>
#include <iostream>

//i want all the code place in one file
struct Person {
  std::string name;
  int age;

  MSGPACK_DEFINE_MAP(name, age);

  // Parse from MessagePack object
  static Person parse(const msgpack::object& obj) {
    Person p;
    obj.convert(p);   // uses MSGPACK_DEFINE
    return p;
  }

  // Optional: in-place parse
  void parse_inplace(const msgpack::object& obj) {
    obj.convert(*this);
  }
};

int main() {
  zmq::context_t ctx(1);
  zmq::socket_t sub(ctx, zmq::socket_type::sub);

  sub.connect("tcp://localhost:5555");

  // Subscribe only to "person"
  sub.set(zmq::sockopt::subscribe, "person");

  std::cout << "Waiting for messages...\n";

  while (true) {
    zmq::message_t topic_msg;
    zmq::message_t payload_msg;

    // Receive topic
    sub.recv(topic_msg, zmq::recv_flags::none);
    std::string topic(
      static_cast<char*>(topic_msg.data()),
      topic_msg.size()
    );

    // Receive payload
    sub.recv(payload_msg, zmq::recv_flags::none);

    // Decode MessagePack
    msgpack::object_handle oh =
      msgpack::unpack(
        static_cast<const char*>(payload_msg.data()),
        payload_msg.size()
      );

    msgpack::object obj = oh.get();

    // Person p;
    // p.parse_inplace(obj);
    Person p = Person::parse(obj); // alternative

    std::cout << "Received [" << topic << "] "
              << "name=" << p.name
              << " age=" << p.age << "\n";
  }
}
