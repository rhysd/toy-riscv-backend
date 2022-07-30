#include "TOYRISCVABIInfo.h"

using namespace llvm;

TOYRISCVABIInfo TOYRISCVABIInfo::computeTargetABI(StringRef ABIName) {
  if (ABIName.empty() || ABIName == "lp") {
    return TOYRISCVABIInfo::LP();
  }
  if (ABIName == "stack") {
    return TOYRISCVABIInfo::STACK();
  }

  errs() << "Unknown ABI: " << ABIName << "\n";

  abort();
}
