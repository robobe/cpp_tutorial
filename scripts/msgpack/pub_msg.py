# publisher.py
import time
import zmq
import msgpack
from dataclasses import asdict
from dataclasses import dataclass


@dataclass
class Person:
    name: str
    age: int

def main():
    context = zmq.Context()
    socket = context.socket(zmq.PUB)
    socket.bind("tcp://*:5555")

    # Give subscribers time to connect
    time.sleep(1)

    count = 0
    while True:
        person = Person(name="Alice", age=30 + count)

        # Convert dataclass → dict → msgpack
        payload = msgpack.packb(asdict(person), use_bin_type=True)

        topic = "person"

        # Send multipart message
        socket.send_multipart([
            topic.encode("utf-8"),
            payload
        ])

        print(f"Published [{topic}] {person}")
        count += 1
        time.sleep(1)

if __name__ == "__main__":
    main()
