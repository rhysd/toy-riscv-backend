#if !defined TOYRISCVSUBTARGET_H_INCLUDED
#define TOYRISCVSUBTARGET_H_INCLUDED

#include "TOYRISCVFrameLowering.h"
#include "TOYRISCVISelLowering.h"
#include "TOYRISCVInstrInfo.h"

#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/MC/MCInstrItineraries.h"

#define GET_SUBTARGETINFO_HEADER
#include "TOYRISCVGenSubtargetInfo.inc"

namespace llvm {

class StringRef;
class TOYRISCVTargetMachine;
class TOYRISCVSubtarget : public TOYRISCVGenSubtargetInfo {
  virtual void anchor();

protected:
  bool HasV64 = false; // FeatureRV64 is set to this field in TOYRISCV.td

public:
  TOYRISCVSubtarget &initializeSubtargetDependencies(StringRef CPU,
                                                     StringRef TuneCPU,
                                                     StringRef FS,
                                                     const TargetMachine &TM);
};

} // namespace llvm

#endif // TOYRISCVSUBTARGET_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
