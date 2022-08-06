#include "TOYRISCVFrameLowering.h"

using namespace llvm;

TOYRISCVFrameLowering::TOYRISCVFrameLowering(TOYRISCVSubtarget const &sti)
    : TargetFrameLowering(StackGrowsDown, Align(16), 0), STI(sti) {}

void TOYRISCVFrameLowering::emitPrologue(MachineFunction &MF,
                                         MachineBasicBlock &MBB) const {
  // TODO
}

void TOYRISCVFrameLowering::emitEpilogue(MachineFunction &MF,
                                         MachineBasicBlock &MBB) const {
  // TODO
}

bool TOYRISCVFrameLowering::hasFP(const MachineFunction &MF) const {
  // TODO
  return true;
}

MachineBasicBlock::iterator
TOYRISCVFrameLowering::eliminateCallFramePseudoInstr(
    MachineFunction &MF, MachineBasicBlock &MBB,
    MachineBasicBlock::iterator I) const {
  // TODO
  return I;
}

// vim: set ts=2 sw=2 sts=2:
