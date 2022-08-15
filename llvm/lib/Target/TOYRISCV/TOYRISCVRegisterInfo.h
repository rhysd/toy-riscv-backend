#if !defined TOYRISCVREGISTERINFO_H_INCLUDED
#define TOYRISCVREGISTERINFO_H_INCLUDED

#include "TOYRISCV.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "TOYRISCVGenRegisterInfo.inc"

namespace llvm {

class TOYRISCVSubtarget;

class TOYRISCVRegisterInfo : public TOYRISCVGenRegisterInfo {
  const TOYRISCVSubtarget &Subtarget;

public:
  TOYRISCVRegisterInfo(TOYRISCVSubtarget const &ST, unsigned HwMode);
  MCPhysReg const *getCalleeSavedRegs(MachineFunction const *MF) const override;
  uint32_t const *getCallPreservedMask(MachineFunction const &MF,
                                       CallingConv::ID) const override;
  BitVector getReservedRegs(MachineFunction const &MF) const override;
  void eliminateFrameIndex(MachineBasicBlock::iterator II, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
  Register getFrameRegister(MachineFunction const &MF) const override;
};

} // namespace llvm

#endif // TOYRISCVREGISTERINFO_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
