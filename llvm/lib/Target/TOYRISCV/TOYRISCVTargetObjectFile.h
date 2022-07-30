#if !defined TOYRISCVTARGETOBJECTFILE_H_INCLUDED
#define TOYRISCVTARGETOBJECTFILE_H_INCLUDED

#include "TOYRISCVTargetMachine.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

namespace llvm {

class TOYRISCVTargetMachine;

class TOYRISCVTargetObjectFile : public TargetLoweringObjectFileELF {
  TOYRISCVTargetMachine const *TM;

public:
  void Initialize(MCContext &Ctx, TargetMachine const &TM) override;
};

} // namespace llvm

#endif // TOYRISCVTARGETOBJECTFILE_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
