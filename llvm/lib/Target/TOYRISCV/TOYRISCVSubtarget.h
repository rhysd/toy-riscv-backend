#if !defined TOYRISCVSUBTARGET_H_INCLUDED
#define TOYRISCVSUBTARGET_H_INCLUDED

#include "llvm/Target/TargetMachine.h"

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
