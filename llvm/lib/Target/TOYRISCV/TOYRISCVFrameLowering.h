#if !defined TOYRISCVFRAMELOWERING_H_INCLUDED
#define TOYRISCVFRAMELOWERING_H_INCLUDED

#include "TOYRISCV.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {

class TOYRISCVSubtarget;

class TOYRISCVFrameLowering : public TargetFrameLowering {
protected:
  const TOYRISCVSubtarget &STI;

public:
  explicit TOYRISCVFrameLowering(const TOYRISCVSubtarget &sti);

  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  bool hasFP(const MachineFunction &MF) const override;
  MachineBasicBlock::iterator
  eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator I) const override;
};

} // namespace llvm

#endif // TOYRISCVFRAMELOWERING_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
