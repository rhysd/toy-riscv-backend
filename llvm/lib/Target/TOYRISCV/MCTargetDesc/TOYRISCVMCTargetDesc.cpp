#include "TOYRISCVMCTargetDesc.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MachineLocation.h"

#define GET_INSTRINFO_MC_DESC
#include "TOYRISCVGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "TOYRISCVGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "TOYRISCVGenRegisterInfo.inc"

using namespace llvm;

extern "C" void LLVMInitializeTOYRISCVTargetMC() {
  // TODO
}

// vim: set ts=2 sw=2 sts=2:
