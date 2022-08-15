#include "TOYRISCVSubtarget.h"
#include "TOYRISCV.h"
#include "TOYRISCVISelLowering.h"
#include "TOYRISCVRegisterInfo.h"
#include "TOYRISCVTargetMachine.h"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "TOYRISCVGenSubtargetInfo.inc"

using namespace llvm;

TOYRISCVSubtarget::TOYRISCVSubtarget(Triple const &TT, StringRef &CPU,
                                     StringRef &TuneCPU, StringRef &FS,
                                     TOYRISCVTargetMachine const &TTM)
    : TOYRISCVGenSubtargetInfo(TT, CPU, TuneCPU, FS), TargetTriple(TT), TM(TTM),
      FrameLowering(initializeSubtargetDependencies(CPU, TuneCPU, FS, TM)),
      TargetLowering(TM, *this), RegInfo(*this, getHwMode()) {}

TOYRISCVSubtarget &TOYRISCVSubtarget::initializeSubtargetDependencies(
    StringRef CPU, StringRef TuneCPU, StringRef FS, TargetMachine const &TM) {
  if (TargetTriple.getArch() == Triple::toyriscv32) {
    if (CPU.empty() || CPU == "generic") {
      CPU = "cpu-rv32";
    }
  } else if (TargetTriple.getArch() == Triple::toyriscv64) {
    if (CPU.empty() || CPU == "generic") {
      CPU = "cpu-rv64";
    }
  } else {
    errs() << "Architecture " << TargetTriple.getArch()
           << " is not supported for CPU " << CPU << "\n";
    abort();
  }

  ParseSubtargetFeatures(CPU, TuneCPU, FS);

  InstrItins = getInstrItineraryForCPU(CPU);
  if (HasRV64) {
    XLenVT = MVT::i64;
  } else {
    XLenVT = MVT::i32;
  }

  return *this;
}

TOYRISCVSubtarget::~TOYRISCVSubtarget() {}

TOYRISCVInstrInfo const *TOYRISCVSubtarget::getInstrInfo() const {
  return &InstrInfo;
}

TOYRISCVFrameLowering const *TOYRISCVSubtarget::getFrameLowering() const {
  return &FrameLowering;
}

TOYRISCVTargetLowering const *TOYRISCVSubtarget::getTargetLowering() const {
  return &TargetLowering;
}

TOYRISCVRegisterInfo const *TOYRISCVSubtarget::getRegisterInfo() const {
  return &RegInfo;
}

void TOYRISCVSubtarget::anchor() {}

// vim: set ts=2 sw=2 sts=2:
