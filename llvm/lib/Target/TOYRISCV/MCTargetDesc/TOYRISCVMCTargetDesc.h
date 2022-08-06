#if !defined MCTARGETDESC_MCTARGETDESC_H_INCLUDED
#define MCTARGETDESC_MCTARGETDESC_H_INCLUDED

#include "llvm/MC/MCTargetOptions.h"
#include "llvm/Support/DataTypes.h"

namespace llvm {

class Target;

Target &getTheTOYRISCV32Target();
Target &getTheTOYRISCV64Target();

} // namespace llvm

#define GET_REGINFO_ENUM
#include "TOYRISCVGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "TOYRISCVGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "TOYRISCVGenSubtargetInfo.inc"

#endif // MCTARGETDESC_MCTARGETDESC_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
