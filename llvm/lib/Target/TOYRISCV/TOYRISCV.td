include "llvm/Target/Target.td"

// Note: + and - represents to add/remove a feature
def RV64 : HwMode<"+64bit">;
def RV32 : HwMode<"-64bit">;

include "TOYRISCVRegisterInfo.td"
include "TOYRISCVSchedule.td"
include "TOYRISCVInstrInfo.td"
include "TOYRISCVCallingConv.td"

def TOYRISCVInstrInfo : InstrInfo;

def TOYRISCV : Target {
  let InstructionSet = TOYRISCVInstrInfo;
}

def FeatureRV64 : SubtargetFeature<"64bit", "HasRV64", "true", "RV64 support">;

def : ProcessorModel<"cpu-rv32", NoSchedModel, []>;
def : ProcessorModel<"cpu-rv64", NoSchedModel, [FeatureRV64]>;
