#include "TOYRISCVISelDagToDag.h"

using namespace llvm;

TOYRISCVDAGToDAGISel::TOYRISCVDAGToDAGISel(TOYRISCVTargetMachine &TM,
                                           CodeGenOpt::Level OL)
    : SelectionDAGISel(TM, OL), Subtarget(nullptr) {}

StringRef TOYRISCVDAGToDAGISel::getPassName() const {
  return "TOYRISCV DAG->DAG Pattern Instruction Selection";
}

void TOYRISCVDAGToDAGISel::Select(SDNode *N) {
  assert(N->isMachineOpcode() && "unsupported node");
  N->setNodeId(-1);
}

// vim: set ts=2 sw=2 sts=2:
