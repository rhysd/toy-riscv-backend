include "llvm/Target/Target.td"

def MYRISCVX : Target {
  let InstructionSet = TOYRISCVInstrInfo;
}
