#include "TOYRISCVISelDagToDag.h"

using namespace llvm;

TOYRISCVDAGToDAGISel::TOYRISCVDAGToDAGISel(TOYRISCVTargetMachine &TM,
                                           CodeGenOpt::Level OL)
    : SelectionDAGISel(TM, OL), Subtarget(nullptr) {}

StringRef TOYRISCVDAGToDAGISel::getPassName() const {
  return "TOYRISCV DAG->DAG Pattern Instruction Selection";
}

void TOYRISCVDAGToDAGISel::Select(SDNode *N) {
  if (N->isMachineOpcode()) {
    N->setNodeId(-1);
    return;
  }

  SelectCode(N);
}

// vim: set ts=2 sw=2 sts=2:
