#include "TOYRISCVInstrInfo.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "TOYRISCVGenInstrInfo.inc"

using namespace llvm;

void TOYRISCVInstrInfo::anchor() {}

TOYRISCVInstrInfo::TOYRISCVInstrInfo()
    : TOYRISCVGenInstrInfo(TOYRISCV::ADJCALLSTACKDOWN,
                           TOYRISCV::ADJCALLSTACKUP) {}

// vim: set ts=2 sw=2 sts=2:
