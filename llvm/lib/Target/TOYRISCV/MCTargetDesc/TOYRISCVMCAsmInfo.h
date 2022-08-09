#if !defined MCTARGETDESC_TOYRISCVMCASMINFO_H_INCLUDED
#define MCTARGETDESC_TOYRISCVMCASMINFO_H_INCLUDED

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class TOYRISCVMCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit TOYRISCVMCAsmInfo(Triple const &TheTriple);
};

} // namespace llvm

#endif // MCTARGETDESC_TOYRISCVMCASMINFO_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
