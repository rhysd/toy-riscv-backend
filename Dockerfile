# https://github.com/chadyuu/riscv-chisel-book/blob/master/dockerfile
FROM ubuntu:18.04

ENV RISCV=/opt/riscv
ENV PATH=$RISCV/bin:$PATH
WORKDIR $RISCV

# Install apt packages
RUN apt-get update && \
    apt-get install -y --no-install-recommends autoconf automake autotools-dev curl libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev pkg-config device-tree-compiler git ca-certificates && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Install RISC-V GNU toolchain, proxy kernel and spike
RUN git clone --recursive -b 2022.06.10 https://github.com/riscv-collab/riscv-gnu-toolchain.git && \
    cd riscv-gnu-toolchain && \
    mkdir build && cd build && ../configure --prefix=${RISCV} --enable-multilib && make -j4 && \
    cd ../pk && mkdir build && cd build && ../configure --prefix=$RISCV --host=riscv64-unknown-elf && make -j4 && make install && cd .. && \
    cd ../spike && mkdir build && cd build && ../configure --prefix=$RISCV && make -j4 && make install && \
    cd $RISCV && rm -rf riscv-gnu-toolchain

# Note: riscv-tools is too old to compile with recent riscv-gcc. The pre-built riscv-gnu-toolchain downloaded from
# official Sifive site (10.2.0-2020.12.8) also didn't work. Currently there is no way to build riscv-tools without
# preparing very old riscv-gcc.
