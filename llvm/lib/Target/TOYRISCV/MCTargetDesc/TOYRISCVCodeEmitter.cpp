#include "MCTargetDesc/TOYRISCVCodeEmitter.h"

#define DEBUG_TYPE "toyriscv-code-emitter"

#define GET_INSTRMAP_INFO
#include "TOYRISCVGenInstrInfo.inc"
#undef GET_INSTRMAP_INFO

using namespace llvm;

TOYRISCVMCCodeEmitter::TOYRISCVMCCodeEmitter(MCInstrInfo const &MCII,
                                             MCContext &Ctx, bool IsLittle)
    : MCII(MCII), Ctx(Ctx), IsLittleEndian(IsLittle) {}

void TOYRISCVMCCodeEmitter::encodeInstruction(
    MCInst const &MI, raw_ostream &OS, SmallVectorImpl<MCFixup> &Fixups,
    MCSubtargetInfo const &STI) const {
  // TODO
}

// vim: set ts=2 sw=2 sts=2:
