#include "TOYRISCVAsmPrinter.h"
#include "TOYRISCV.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

TOYRISCVAsmPrinter::TOYRISCVAsmPrinter(TargetMachine &TM,
                                       std::unique_ptr<MCStreamer> Streamer)
    : AsmPrinter(TM, std::move(Streamer)) {}

StringRef TOYRISCVAsmPrinter::getPassName() const {
  return "TOYRISCV Assembly Printer";
}

extern "C" void LLVMInitializeTOYRISCVAsmPrinter() {
  RegisterAsmPrinter<TOYRISCVAsmPrinter> X(getTheTOYRISCV32Target());
  RegisterAsmPrinter<TOYRISCVAsmPrinter> Y(getTheTOYRISCV64Target());
}

// vim: set ts=2 sw=2 sts=2:
