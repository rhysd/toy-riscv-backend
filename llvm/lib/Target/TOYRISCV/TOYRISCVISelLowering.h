#if !defined TOYRISCVISELLOWERING_H_INCLUDED
#define TOYRISCVISELLOWERING_H_INCLUDED

#include "TOYRISCV.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class TOYRISCVTargetLowering : public TargetLowering {
public:
  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               SmallVectorImpl<ISD::InputArg> const &Ins,
                               SDLoc const &dl, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      SmallVectorImpl<ISD::OutputArg> const &Outs,
                      SmallVectorImpl<SDValue> const &OutVals, SDLoc const &dl,
                      SelectionDAG &DAG) const override;
};

} // namespace llvm

#endif // TOYRISCVISELLOWERING_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
