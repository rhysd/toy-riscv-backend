#!/bin/bash

set -e -o pipefail

if [ ! -d .git ]; then
    echo 'This script must be run from repository root' 1>&2
    exit 1
fi

LLVM=./llvm-project/llvm
PATHS=(
    CMakeLists.txt
    cmake/config-ix.cmake
    include/llvm/ADT/Triple.h
    lib/Support/Triple.cpp
    lib/Target/TOYRISCV
)

set -x

git submodule foreach git reset --hard
git submodule foreach git clean -dfX

for path in "${PATHS[@]}"; do
    rm -rf "${LLVM}/${path}"
    ln -s "${PWD}/${path}" "${LLVM}/${path}"
done
