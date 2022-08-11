#include "MCTargetDesc/TOYRISCVTargetStreamer.h"

using namespace llvm;

TOYRISCVTargetStreamer::TOYRISCVTargetStreamer(MCStreamer &S)
    : MCTargetStreamer(S) {}

TOYRISCVTargetAsmStreamer::TOYRISCVTargetAsmStreamer(MCStreamer &S,
                                                     formatted_raw_ostream &OS)
    : TOYRISCVTargetStreamer(S), OS(OS) {}

// vim: set ts=2 sw=2 sts=2:
