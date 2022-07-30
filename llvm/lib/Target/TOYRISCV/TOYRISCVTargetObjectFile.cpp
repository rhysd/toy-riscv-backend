#include "TOYRISCVTargetObjectFile.h"

using namespace llvm;

void TOYRISCVTargetObjectFile::Initialize(MCContext &Ctx,
                                          TargetMachine const &TM) {
  TargetLoweringObjectFileELF::Initialize(Ctx, TM);
  // TODO
  this->TM = &static_cast<TOYRISCVTargetMachine const &>(TM);
}

// vim: set ts=2 sw=2 sts=2:
