#if !defined TOYRISCVREGISTERINFO_H_INCLUDED
#define TOYRISCVREGISTERINFO_H_INCLUDED

#include "TOYRISCV.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

namespace llvm {

class TOYRISCVRegisterInfo : public TOYRISCVGenRegisterInfo {
protected:
  MCPhysReg const *getCalleeSavedRegs(MachineFunction const *MF) const override;
  uint32_t const *getCallPreservedMask(MachineFunction const &MF,
                                       CallingConv::ID) const override;
  BitVector getReservedRegs(MachineFunction const &MF) const override;
  void eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
};

} // namespace llvm

#endif // TOYRISCVREGISTERINFO_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
