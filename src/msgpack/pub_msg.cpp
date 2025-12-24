// publisher.cpp
#include <zmq.hpp>
#include <msgpack.hpp>
#include <iostream>
#include <thread>
#include <chrono>

struct Person {
  std::string name;
  int age;

  // Enable msgpack support
  // MSGPACK_DEFINE(...) = array-based encoding
  MSGPACK_DEFINE_MAP(name, age);
};

int main() {
  zmq::context_t ctx(1);
  zmq::socket_t pub(ctx, zmq::socket_type::pub);
  pub.bind("tcp://*:5555");

  // Give subscribers time to connect
  std::this_thread::sleep_for(std::chrono::seconds(1));

  int count = 0;
  while (true) {
    Person p{ "Alice", 30 + count };

    // Serialize to MessagePack buffer
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, p);

    // Topic frame
    const std::string topic = "person";

    // Send multipart: topic -> payload
    pub.send(zmq::buffer(topic), zmq::send_flags::sndmore);
    pub.send(zmq::buffer(sbuf.data(), sbuf.size()),
             zmq::send_flags::none);

    std::cout << "Published [" << topic << "] age=" << p.age << "\n";
    count++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
