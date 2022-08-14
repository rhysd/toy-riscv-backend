#include "TOYRISCVTargetMachine.h"
#include "TOYRISCV.h"
#include "TOYRISCVISelDagToDag.h"
#include "TOYRISCVTargetObjectFile.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <string>

using namespace llvm;

extern "C" void LLVMInitializeTOYRISCVTarget() {
  RegisterTargetMachine<TOYRISCV32TargetMachine> X(getTheTOYRISCV32Target());
  RegisterTargetMachine<TOYRISCV64TargetMachine> Y(getTheTOYRISCV64Target());
}

static StringRef computeDataLayout(const Triple &TT, StringRef CPU,
                                   const TargetOptions &Options) {
  // Example:
  //  e-m:e-p:64:64-i64:64-i128:128-n64-S128
  //    e = little endian
  //    m:e = mangling mode is ELF
  //    p:64 = pointer size
  //    i64:64-i128:128 = data alignment constraint
  //    n64 = size of integer register
  //    S128 = stack data size

  if (TT.isArch64Bit()) {
    return "e-m:m-p:64:64-i8:8:32-i16:16:32-i64:64-n64-S128";
  } else {
    assert(TT.isArch32Bit() && "TOYRISCV must be 32bit or 64bit architecture");
    return "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64";
  }
}

static Reloc::Model getEffectiveRelocModel(bool JIT,
                                           Optional<Reloc::Model> RM) {
  if (!RM.hasValue() || JIT) {
    return Reloc::Static;
  }
  return *RM;
}

class TOYRISCVPassConfig : public TargetPassConfig {
public:
  TOYRISCVPassConfig(TOYRISCVTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  bool addInstSelector() override {
    addPass(new TOYRISCVDAGToDAGISel(getTM<TOYRISCVTargetMachine>(),
                                     getOptLevel()));
    return false;
  }

  // TODO
};

TOYRISCVTargetMachine::TOYRISCVTargetMachine(Target const &T, Triple const &TT,
                                             StringRef CPU, StringRef FS,
                                             TargetOptions const &Options,
                                             Optional<Reloc::Model> RM,
                                             Optional<CodeModel::Model> CM,
                                             CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T, computeDataLayout(TT, CPU, Options), TT, CPU, FS,
                        Options, getEffectiveRelocModel(JIT, RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TOYRISCVTargetObjectFile>()),
      ABI(TOYRISCVABIInfo::computeTargetABI(Options.MCOptions.getABIName())),
      DefaultSubtarget(TT, CPU, CPU, FS, *this) {
  initAsmInfo();
}

TOYRISCVTargetMachine::~TOYRISCVTargetMachine() {}

TOYRISCVABIInfo const &TOYRISCVTargetMachine::getABI() const { return ABI; }

TOYRISCVSubtarget const *
TOYRISCVTargetMachine::getSubtargetImpl(Function const &F) const {
  return &DefaultSubtarget;
}

TargetPassConfig *TOYRISCVTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new TOYRISCVPassConfig(*this, PM);
}

TargetLoweringObjectFile *TOYRISCVTargetMachine::getObjFileLowering() const {
  return TLOF.get();
}

TOYRISCV32TargetMachine::TOYRISCV32TargetMachine(
    Target const &T, Triple const &TT, StringRef CPU, StringRef FS,
    TargetOptions const &Options, Optional<Reloc::Model> RM,
    Optional<CodeModel::Model> CM, CodeGenOpt::Level OL, bool JIT)
    : TOYRISCVTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, JIT) {}

void TOYRISCV32TargetMachine::anchor() {}

TOYRISCV64TargetMachine::TOYRISCV64TargetMachine(
    Target const &T, Triple const &TT, StringRef CPU, StringRef FS,
    TargetOptions const &Options, Optional<Reloc::Model> RM,
    Optional<CodeModel::Model> CM, CodeGenOpt::Level OL, bool JIT)
    : TOYRISCVTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, JIT) {}

void TOYRISCV64TargetMachine::anchor() {}

// vim: set ts=2 sw=2 sts=2:
