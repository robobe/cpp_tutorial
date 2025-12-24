
# Cpp sample

```
cmake -S . -B build
cmake --build build
```

## msgpack

| file  | description  |
|---|---|
| hello.cpp  | simple struct serialize deserialize  using msgpack |
| pub_msg.cpp | publish message using zmq (pub) with topic (can read message using  sub_msg.py)|
| sub_msg.cpp | subscriber message using zmq and msgpack use strct to hold data (sub to message from pub_msg.py)|



## protobuf

| file  | description  |
|---|---|
| hello.cpp  | demo using SerializeToString and ParseFromString to serialization/deserialization proto message  |
| buffer_example.cpp  | demo using SerializeToArray and ParseFromArray to serialization/deserialization proto message  |
| json_example.cpp  | demo using MessageToJsonString and JsonStringToMessage to serialization/deserialization proto message  |



## zmq

| file  | description  |
|---|---|
| pub.cpp  |   |
| sub.cpp  |   |
| pub_proto.cpp  | send protobuf message using zmq  |
| sub_proto.cpp  | subscribe and get to protobuf message  |


## Scripts

| file  | description  |
|---|---|
| scripts/msgpack/sub_msg.py  | subscribe to message that publish by pub_msg.cpp  |
| scripts/msgpack/pub_msg.py  | publish message using zmq and and serial using msgpack, using dataclass as object |


terminator -e "bash -c 'echo pane1; exec ./build/src/msgpack/pub_msg'" \
           -e "bash -c 'echo pane2; exec ./build/src/msgpack/sub_msg'"