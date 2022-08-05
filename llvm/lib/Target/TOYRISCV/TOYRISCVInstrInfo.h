#if !defined TOYRISCVINSTRINFO_H_INCLUDED
#define TOYRISCVINSTRINFO_H_INCLUDED

#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "TOYRISCVGenInstrInfo.inc"

class TOYRISCVInstrInfo : public TOYRISCVGenInstrInfo {
  // TODO
};

#endif // TOYRISCVINSTRINFO_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
