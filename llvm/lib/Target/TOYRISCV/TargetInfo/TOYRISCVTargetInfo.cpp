#include "TOYRISCV.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheTOYRISCV32Target() {
  static Target TheTOYRISCV32Target;
  return TheTOYRISCV32Target;
}

Target &llvm::getTheTOYRISCV64Target() {
  static Target TheTOYRISCV64Target;

  return TheTOYRISCV64Target;
}

extern "C" void LLVMInitializeTOYRISCVTargetInfo() {
  RegisterTarget<Triple::toyriscv32, true> X(
      getTheTOYRISCV32Target(), "toyriscv32", "TOYRISCV (32-bit)", "TOYRISCV");
  RegisterTarget<Triple::toyriscv64, true> Y(
      getTheTOYRISCV64Target(), "toyriscv64", "TOYRISCV (64-bit)", "TOYRISCV");
}

// vim: set ts=2 sw=2 sts=2:
