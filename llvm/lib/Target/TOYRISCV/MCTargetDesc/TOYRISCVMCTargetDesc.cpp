#include "TOYRISCVMCTargetDesc.h"
#include "MCTargetDesc/TOYRISCVInstPrinter.h"
#include "MCTargetDesc/TOYRISCVMCAsmInfo.h"
#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrAnalysis.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MachineLocation.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"

#define GET_INSTRINFO_MC_DESC
#include "TOYRISCVGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "TOYRISCVGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "TOYRISCVGenRegisterInfo.inc"

using namespace llvm;

static MCAsmInfo *createTOYRISCVMCAsmInfo(MCRegisterInfo const &MRI,
                                          Triple const &TT,
                                          MCTargetOptions const &Options) {
  MCAsmInfo *MAI = new TOYRISCVMCAsmInfo(TT);

  MCRegister SP = MRI.getDwarfRegNum(TOYRISCV::SP, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);

  return MAI;
}

static MCInstrInfo *createTOYRISCVMCInstrInfo() {
  MCInstrInfo *I = new MCInstrInfo();
  // This function is defined in TOYRISCVGenInstrInfo.inc
  InitTOYRISCVMCInstrInfo(I);
  return I;
}

static MCRegisterInfo *createTOYRISCVMCRegisterInfo(Triple const &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  // This function is defined in TOYRISCVGenRegisterInfo.inc
  InitTOYRISCVMCRegisterInfo(X, TOYRISCV::RA);
  return X;
}

static MCSubtargetInfo *
createTOYRISCVMCSubtargetInfo(Triple const &TT, StringRef CPU, StringRef FS) {
  if (CPU.empty()) {
    CPU = TT.isArch64Bit() ? "cpu-rv64" : "cpu-rv32";
  }
  // This function is defined in TOYRISCVGenSubtargetInfo.inc
  return createTOYRISCVMCSubtargetInfoImpl(TT, CPU, CPU, FS);
}

static MCInstrAnalysis *createTOYRISCVMCInstrAnalysis(const MCInstrInfo *Info) {
  return new MCInstrAnalysis(Info);
}

// This function will be called by llc via C preprocessor
extern "C" void LLVMInitializeTOYRISCVTargetMC() {
  Target &T = getTheTOYRISCV32Target();

  RegisterMCAsmInfoFn X(T, createTOYRISCVMCAsmInfo);
  TargetRegistry::RegisterMCInstrInfo(T, createTOYRISCVMCInstrInfo);
  TargetRegistry::RegisterMCRegInfo(T, createTOYRISCVMCRegisterInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createTOYRISCVMCSubtargetInfo);
  TargetRegistry::RegisterMCInstrAnalysis(T, createTOYRISCVMCInstrAnalysis);
}

// vim: set ts=2 sw=2 sts=2:
