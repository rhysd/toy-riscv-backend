add_llvm_component_group(TOYRISCV)
set(LLVM_TARGET_DEFINITIONS TOYRISCV.td)

tablegen(LLVM TOYRISCVGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM TOYRISCVGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM TOYRISCVGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM TOYRISCVGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM TOYRISCVGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM TOYRISCVGenCallingConv.inc -gen-callingconv)
tablegen(LLVM TOYRISCVGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(TOYRISCVCommonTableGen)

add_llvm_target(TOYRISCVCodeGen
    TOYRISCVTargetMachine.cpp
    TOYRISCVFrameLowering.cpp
    TOYRISCVISelLowering.cpp
    TOYRISCVRegisterInfo.cpp
    TOYRISCVSubtarget.cpp
    TOYRISCVInstrInfo.cpp
    TOYRISCVTargetObjectFile.cpp
    TOYRISCVAsmPrinter.cpp
    TOYRISCVISelDagToDag.cpp
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
