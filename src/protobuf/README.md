# protobuf tutorial

```bash
sudo apt install -y protobuf-compiler libprotobuf-dev
```

```bash
# from root folder where proto and msgs exists
protoc   -Iproto   --cpp_out=msgs   proto/*.proto
```