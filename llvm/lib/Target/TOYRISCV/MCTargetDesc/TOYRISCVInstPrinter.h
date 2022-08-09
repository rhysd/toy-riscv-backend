#if !defined MCTARGETDESC_TOYRISCVINSTPRINTER_H_INCLUDED
#define MCTARGETDESC_TOYRISCVINSTPRINTER_H_INCLUDED

#include "llvm/MC/MCInstPrinter.h"

namespace llvm {

class TargetMachine;

class TOYRISCVInstPrinter : public MCInstPrinter {
public:
  TOYRISCVInstPrinter(MCAsmInfo const &MAI, MCInstrInfo const &MII,
                      MCRegisterInfo const &MRI);

  void printInst(MCInst const *MI, uint64_t Address, StringRef Annot,
                 MCSubtargetInfo const &STI, raw_ostream &O) override;
  void printRegName(raw_ostream &OS, unsigned RegNo) const override;
  void printOperand(MCInst const *MI, unsigned OpNo, raw_ostream &O);
  void printOperand(MCInst const *MI, uint64_t _Address, unsigned OpNum,
                    raw_ostream &O);

  // These member functions are generated in TOYRISCVGenAsmWriter.inc
  std::pair<char const *, uint64_t> getMnemonic(MCInst const *MI) override;
  void printInstruction(MCInst const *MI, uint64_t Address, raw_ostream &OS);
  static char const *getRegisterName(unsigned RegNo);
  bool printAliasInstr(MCInst const *MI, uint64_t Address, raw_ostream &OS);
};

} // namespace llvm

#endif // MCTARGETDESC_TOYRISCVINSTPRINTER_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
