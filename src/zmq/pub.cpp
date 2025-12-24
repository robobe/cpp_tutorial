#include <zmq.hpp>
#include <iostream>
#include <chrono>
#include <thread>

int main() {
  zmq::context_t context(1);
  zmq::socket_t socket(context, zmq::socket_type::pub);

  socket.bind("tcp://*:5555");

  int count = 0;
  while (true) {
    std::string msg = "Hello " + std::to_string(count++);

    zmq::message_t message(msg.size());
    memcpy(message.data(), msg.data(), msg.size());

    socket.send(message, zmq::send_flags::none);

    std::cout << "Sent: " << msg << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
