FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential clang

COPY . /repo
WORKDIR /repo
RUN ./configure
RUN make -j8
RUN clang++ /repo/mayhem/fuzz_mxmlLoadString.cpp -fsanitize=fuzzer,address -I /repo /repo/libmxml.a -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /repo/testmxml /
COPY --from=builder /fuzz /fuzz_mxmlLoadString
