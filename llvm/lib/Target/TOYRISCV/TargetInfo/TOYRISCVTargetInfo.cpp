#include "TOYRISCV.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

namespace llvm {

Target &getTheTOYRISCV32Target() {
  static Target TheTOYRISCV32Target;
  return TheTOYRISCV32Target;
}

Target &getTheTOYRISCV64Target() {
  static Target TheTOYRISCV64Target;

  return TheTOYRISCV64Target;
}

} // namespace llvm

extern "C" void LLVMInitializeTOYRISCVTargetInfo() {
  RegisterTarget<Triple::toyriscv32, true> X(
      getTheTOYRISCV32Target(), "toyriscv32", "TOYRISCV (32-bit)", "TOYRISCV");
  RegisterTarget<Triple::toyriscv64, true> Y(
      getTheTOYRISCV64Target(), "toyriscv64", "TOYRISCV (64-bit)", "TOYRISCV");
}
