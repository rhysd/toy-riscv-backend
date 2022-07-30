#if !defined MCTARGETDESC_TOYRISCVABIINFO_H_INCLUDED
#define MCTARGETDESC_TOYRISCVABIINFO_H_INCLUDED

#include "llvm/MC/MCRegisterInfo.h"

namespace llvm {

class MCTargetOptions;
class StringRef;
class TargetRegisterClass;

class TOYRISCVABIInfo {
public:
  enum class ABI { Unknown, LP, STACK };

  TOYRISCVABIInfo(ABI A) : ThisABI(A) {}

  static TOYRISCVABIInfo Unknown() { return TOYRISCVABIInfo(ABI::Unknown); }
  static TOYRISCVABIInfo LP() { return TOYRISCVABIInfo(ABI::LP); }
  static TOYRISCVABIInfo STACK() { return TOYRISCVABIInfo(ABI::STACK); }

  static TOYRISCVABIInfo computeTargetABI(StringRef ABIName);

protected:
  ABI ThisABI;
};

} // namespace llvm

#endif // MCTARGETDESC_TOYRISCVABIINFO_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
