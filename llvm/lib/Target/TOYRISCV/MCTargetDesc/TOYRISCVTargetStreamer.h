#if !defined TOYRISCVTARGETSTREAMER_H_INCLUDED
#define TOYRISCVTARGETSTREAMER_H_INCLUDED

#include "llvm/MC/MCELFStreamer.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/FormattedStream.h"

namespace llvm {

class TOYRISCVTargetStreamer : public MCTargetStreamer {
public:
  explicit TOYRISCVTargetStreamer(MCStreamer &S);
};

// Assembly text streamer
class TOYRISCVTargetAsmStreamer : public TOYRISCVTargetStreamer {
  formatted_raw_ostream &OS;

public:
  TOYRISCVTargetAsmStreamer(MCStreamer &S, formatted_raw_ostream &OS);
};

} // namespace llvm

#endif // TOYRISCVTARGETSTREAMER_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
