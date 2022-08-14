#if !defined TOYRISCVTARGETMACHINE_H_INCLUDED
#define TOYRISCVTARGETMACHINE_H_INCLUDED

#include "MCTargetDesc/TOYRISCVABIInfo.h"
#include "TOYRISCVSubtarget.h"
#include "llvm/Target/TargetMachine.h"
#include <memory>

namespace llvm {

class formatted_raw_ostream;
class TOYRISCVRegisterInfo;

class TOYRISCVTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  TOYRISCVABIInfo ABI;
  TOYRISCVSubtarget DefaultSubtarget;

public:
  TOYRISCVTargetMachine(Target const &T, Triple const &TT, StringRef CPU,
                        StringRef FS, TargetOptions const &Options,
                        Optional<Reloc::Model> RM,
                        Optional<CodeModel::Model> CM, CodeGenOpt::Level OL,
                        bool JIT);
  ~TOYRISCVTargetMachine() override;

  TOYRISCVABIInfo const &getABI() const;

  TOYRISCVSubtarget const *getSubtargetImpl(Function const &F) const override;
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};

class TOYRISCV32TargetMachine : public TOYRISCVTargetMachine {
  virtual void anchor();

public:
  TOYRISCV32TargetMachine(Target const &T, Triple const &TT, StringRef CPU,
                          StringRef FS, TargetOptions const &Options,
                          Optional<Reloc::Model> RM,
                          Optional<CodeModel::Model> CM, CodeGenOpt::Level OL,
                          bool JIT);
};

class TOYRISCV64TargetMachine : public TOYRISCVTargetMachine {
  virtual void anchor();

public:
  TOYRISCV64TargetMachine(Target const &T, Triple const &TT, StringRef CPU,
                          StringRef FS, TargetOptions const &Options,
                          Optional<Reloc::Model> RM,
                          Optional<CodeModel::Model> CM, CodeGenOpt::Level OL,
                          bool JIT);
};

} // namespace llvm

#endif // TOYRISCVTARGETMACHINE_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
