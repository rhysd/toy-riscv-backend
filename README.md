## References

- Official RISC-V backend: https://github.com/llvm/llvm-project/tree/f28c006a5895fc0e329fe15fead81e37457cb1d1/llvm/lib/Target/RISCV
- RISC-V specification: https://riscv.org/technical/specifications/
  - v20191213 (PDF): https://github.com/riscv/riscv-isa-manual/releases/download/Ratified-IMAFDQC/riscv-spec-20191213.pdf
- RISC-V Assembly Manual: https://github.com/riscv-non-isa/riscv-asm-manual/blob/master/riscv-asm.md
- Writing an LLVM Backend: https://llvm.org/docs/WritingAnLLVMBackend.html
  - Basic Steps: https://llvm.org/docs/WritingAnLLVMBackend.html#basic-steps

## Getting started

Clone this repository:

```sh
git clone --recursive https://github.com/rhysd/toy-riscv-backend.git
```

Setup LLVM:

```sh
./setup.bash
cd ./llvm-project/llvm
mkdir ./build && cd ./build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DLLVM_TARGETS_TO_BUILD="X86;TOYRISCV;RISCV" -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi" ..
ninja
```

Setup RISC-V toolchain:

```sh
docker build . -t riscvback
docker run -it --rm -v $(pwd):/app riscvback /bin/bash
```

## Random notes

### How to compile and run C sources with RISCV backend

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

### How to compile C sources to assembly with our own TOYRISCV backend

Compile to LLVM bitcode using Clang with `riscv64-unknown-elf` target.

```sh
./llvm-project/llvm/build/bin/clang --target=riscv64-unknown-elf -O3 hello.c -c -emit-llvm -o hello.bc
```

Then compile the bitcode to RISC-V 64bit assembly using our own TOYRISCV backend.

```sh
./llvm-project/llvm/build/bin/llc -debug -march=toyriscv64 -filetype=asm hello.bc -o hello.S
```
