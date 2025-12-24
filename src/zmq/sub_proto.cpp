#include <zmq.hpp>
#include <iostream>
#include "person.pb.h"

int main() {
  zmq::context_t ctx(1);
  zmq::socket_t sub(ctx, zmq::socket_type::sub);

  sub.connect("tcp://localhost:5555");

  // Subscribe ONLY to "person" topic
  sub.set(zmq::sockopt::subscribe, "person");

  while (true) {
    zmq::message_t topic_msg;
    zmq::message_t payload_msg;

    // Receive topic
    sub.recv(topic_msg, zmq::recv_flags::none);
    std::string topic(
      static_cast<char*>(topic_msg.data()),
      topic_msg.size()
    );

    // Receive protobuf payload
    sub.recv(payload_msg, zmq::recv_flags::none);

    // Deserialize protobuf
    example::Person p;
    if (!p.ParseFromArray(payload_msg.data(), payload_msg.size())) {
      std::cerr << "Failed to parse protobuf\n";
      continue;
    }

    std::cout << "Received [" << topic << "] "
              << "name=" << p.name()
              << " age=" << p.age() << std::endl;
  }
}
