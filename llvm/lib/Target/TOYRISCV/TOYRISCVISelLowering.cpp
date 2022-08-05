#include "TOYRISCVISelLowering.h"

#include "TOYRISCVGenCallingConv.inc"

using namespace llvm;

SDValue TOYRISCVTargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
    SmallVectorImpl<ISD::InputArg> const &Ins, SDLoc const &dl,
    SelectionDAG const &DAG, SmallVectorImpl<SDValue> &InVals) const {
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
