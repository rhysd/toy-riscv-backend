#include "TOYRISCVISelLowering.h"
#include "TOYRISCVTargetMachine.h"

#include "TOYRISCVGenCallingConv.inc"

using namespace llvm;

TOYRISCVTargetLowering::TOYRISCVTargetLowering(TOYRISCVTargetMachine const &TM,
                                               TOYRISCVSubtarget const &STI)
    : TargetLowering(TM), Subtarget(STI), ABI(TM.getABI()) {
  // TODO
}

SDValue TOYRISCVTargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    SmallVectorImpl<ISD::InputArg> const &Ins, SDLoc const &dl,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {
  // TODO
  return Chain;
}

SDValue
TOYRISCVTargetLowering::LowerReturn(SDValue Chain, CallingConv::ID CallConv,
                                    bool IsVarArg,
                                    SmallVectorImpl<ISD::OutputArg> const &Outs,
                                    SmallVectorImpl<SDValue> const &OutVals,
                                    SDLoc const &dl, SelectionDAG &DAG) const {
  // TODO
  return Chain;
}

// vim: set ts=2 sw=2 sts=2:
