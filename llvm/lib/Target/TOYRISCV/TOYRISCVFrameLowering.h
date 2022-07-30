#if !defined TOYRISCVFRAMELOWERING_H_INCLUDED
#define TOYRISCVFRAMELOWERING_H_INCLUDED

#include "TOYRISCV.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class TOYRSICVSubtarget;

class TOYRISCVFrameLowering : public TargetFrameLowering {
public:
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
};

} // namespace llvm

#endif // TOYRISCVFRAMELOWERING_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
