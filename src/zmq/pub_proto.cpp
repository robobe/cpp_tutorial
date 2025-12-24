#include <zmq.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "person.pb.h"

int main() {
  zmq::context_t ctx(1);
  zmq::socket_t pub(ctx, zmq::socket_type::pub);

  pub.bind("tcp://*:5555");

  // Let subscribers connect
  std::this_thread::sleep_for(std::chrono::seconds(1));

  int count = 0;
  while (true) {
    // ----- Create protobuf message -----
    example::Person p;
    p.set_name("Alice");
    p.set_age(30 + count);

    // Serialize protobuf → raw bytes
    zmq::message_t payload(p.ByteSizeLong());
    p.SerializeToArray(payload.data(), payload.size());

    // Topic frame
    std::string topic = "person";

    // ----- Send multipart message -----
    pub.send(zmq::buffer(topic), zmq::send_flags::sndmore);
    pub.send(payload, zmq::send_flags::none);

    std::cout << "Published Person age=" << p.age() << std::endl;

    count++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
