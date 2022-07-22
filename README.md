## Getting started

Setup LLVM:

```sh
./setup.bash
cd ./llvm-project/llvm
mkdir ./build && cd ./build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DLLVM_TARGETS_TO_BUILD="X86;RISCV" -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi" ..
ninja
```

Setup RISC-V toolchain:

```sh
docker build . -t riscvback
docker run -it --rm -v $(pwd):/app riscvback /bin/bash
```

## Random notes

### How to compile

Compile sources.

Setting triple as `--target=riscv64-unknonw-linux-gnu` is necessary to emit LLVM IR targetting 64bit RISC-V processor.
`-march` may not be necessary, but ensure that CPU arch is `rv64g`. It emits `source.bc`.

```sh
./llvm-project/llvm/build/bin/clang --target=riscv64-unknown-linux-gnu -march=rv64g -emit-llvm -c source.c
```

Compile LLVM bitcode to assembly code.

Set CPU arch to `-march=riscv64`. Default value of `-mcpu` is `generic-v64` so it is not necessary but here we ensure it.
`-mattr` specifies what CPU excentions can be used. In this example, we enable 'd' extension by adding `+d`. It emits `source.s`.

```sh
./llvm-project/llvm/build/bin/llc -march=riscv64 -mcpu=generic-rv64 -mattr=+d -filetype=asm source.bc
```

Check the generated assembly code. The `.attribute 5` is the attribute representing CPU arch. Check the CPU arch supports
all features you need.

```asm
	.text
	.attribute	4, 16
	.attribute	5, "rv64i2p0_f2p0_d2p0"
	.file	"source.c"
	.globl	main
	.p2align	2
	.type	main,@function
main:
...
```

When no feature is enabled, the CPU arch will be `rv64i2p0`. If the assembly code tries to use a feature which is not
enabled by the processor, the following GCC command reports an error like below:

```
source.s:10: Error: ilp32d/lp64d ABI can't be used when d extension isn't supported
```

Finally compile the assembly code to an object file and run it via Spike simulator on Docker container.

```sh
riscv64-unknown-elf-gcc source.s -lc -o source.o
spike pk source.o
```

Note that compiling to an object file from LLVM bitcode via `llc` with `-filetype=obj` does not work.
