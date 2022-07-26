add_llvm_component_group(TOYRISCV)
set(LLVM_TARGET_DEFINITIONS TOYRISCV.td)

tablegen(LLVM TOYRISCVGenRegisterInfo.inc -gen-register-info)
add_public_tablegen_target(TOYRISCVCommonTableGen)
add_llvm_target(TOYRISCVCodeGen
    TOYRISCVTargetMachine.cpp
)

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
