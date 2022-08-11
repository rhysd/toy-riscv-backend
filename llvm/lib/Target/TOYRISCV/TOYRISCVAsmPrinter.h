#if !defined TOYRISCVASMPRINTER_H_INCLUDED
#define TOYRISCVASMPRINTER_H_INCLUDED

#include "TOYRISCVSubtarget.h"
#include "TOYRISCVTargetMachine.h"
#include "llvm/CodeGen/AsmPrinter.h"

namespace llvm {

class TOYRISCVAsmPrinter : public AsmPrinter {
public:
  TOYRISCVAsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer);
};

} // namespace llvm

#endif // TOYRISCVASMPRINTER_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
