#include "MCTargetDesc/TOYRISCVInstPrinter.h"
#include "TOYRISCVInstrInfo.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

#define DEBUG_TYPE "toyriscv-asm-printer"

// This `using` must be inserted before the following #include because
// TOYRISCVGenAsmWriter.inc assumes it
using namespace llvm;

#define PRINT_ALIAS_INSTR
#include "TOYRISCVGenAsmWriter.inc"

TOYRISCVInstPrinter::TOYRISCVInstPrinter(MCAsmInfo const &MAI,
                                         MCInstrInfo const &MII,
                                         MCRegisterInfo const &MRI)
    : MCInstPrinter(MAI, MII, MRI) {}

void TOYRISCVInstPrinter::printInst(MCInst const *MI, uint64_t Address,
                                    StringRef Annot, MCSubtargetInfo const &STI,
                                    raw_ostream &O) {
  if (!printAliasInstr(MI, Address, O)) {
    printInstruction(MI, Address, O);
  }
  printAnnotation(O, Annot);
}

void TOYRISCVInstPrinter::printRegName(raw_ostream &OS, unsigned RegNo) const {
  OS << StringRef(getRegisterName(RegNo)).lower();
}

void TOYRISCVInstPrinter::printOperand(MCInst const *MI, unsigned OpNo,
                                       raw_ostream &OS) {
  MCOperand const &Op = MI->getOperand(OpNo);
  if (Op.isReg()) {
    printRegName(OS, Op.getReg());
    return;
  }

  if (Op.isImm()) {
    OS << Op.getImm();
    return;
  }

  assert(Op.isExpr() && "unknown operand kind in printOperand");
  Op.getExpr()->print(OS, &MAI, true);
}

void TOYRISCVInstPrinter::printOperand(MCInst const *MI, uint64_t _Address,
                                       unsigned OpNum, raw_ostream &O) {
  printOperand(MI, OpNum, O);
}

// std::pair<char const *, uint64_t>
// TOYRISCVInstPrinter::getMnemonic(MCInst const *MI) {}

// vim: set ts=2 sw=2 sts=2:
