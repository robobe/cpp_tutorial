import zmq
import msgpack

def main():
    context = zmq.Context()
    socket = context.socket(zmq.SUB)

    socket.connect("tcp://localhost:5555")

    # Subscribe only to the "person" topic
    socket.setsockopt_string(zmq.SUBSCRIBE, "person")

    print("Waiting for messages...")

    while True:
        # Receive multipart message: [topic][payload]
        topic, payload = socket.recv_multipart()

        topic = topic.decode("utf-8")

        # Decode MessagePack payload
        person = msgpack.unpackb(payload, raw=False)

        print(f"Received [{topic}] {person}")

if __name__ == "__main__":
    main()
