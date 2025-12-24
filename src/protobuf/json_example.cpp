#include <iostream>
#include <string>

#include "person.pb.h"
#include <google/protobuf/util/json_util.h>

int main() {
  example::Person p;
  p.set_name("Alice");
  p.set_age(30);

  // -------- Serialize to JSON --------
  std::string json;
  google::protobuf::util::JsonPrintOptions print_options;
  print_options.add_whitespace = true;   // pretty print
  print_options.always_print_primitive_fields = true;

  auto status =
    google::protobuf::util::MessageToJsonString(
      p, &json, print_options);

  if (!status.ok()) {
    std::cerr << "JSON serialization failed: "
              << status.ToString() << std::endl;
    return 1;
  }

  std::cout << "JSON output:\n" << json << std::endl;

  // -------- Parse from JSON --------
  example::Person q;
  auto parse_status =
    google::protobuf::util::JsonStringToMessage(json, &q);

  if (!parse_status.ok()) {
    std::cerr << "JSON parse failed: "
              << parse_status.ToString() << std::endl;
    return 1;
  }

  std::cout << "\nParsed message:\n";
  std::cout << "Name: " << q.name()
            << ", Age: " << q.age() << std::endl;

  return 0;
}
