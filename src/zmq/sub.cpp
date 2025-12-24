#include <zmq.hpp>
#include <iostream>

int main() {
  zmq::context_t context(1);
  zmq::socket_t socket(context, zmq::socket_type::sub);

  socket.connect("tcp://localhost:5555");

  // Subscribe to ALL messages
  socket.set(zmq::sockopt::subscribe, "");

  while (true) {
    zmq::message_t message;
    socket.recv(message, zmq::recv_flags::none);

    std::string msg(static_cast<char*>(message.data()), message.size());
    std::cout << "Received: " << msg << std::endl;
  }
}
