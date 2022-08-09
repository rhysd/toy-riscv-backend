#include "MCTargetDesc/TOYRISCVMCAsmInfo.h"

using namespace llvm;

void TOYRISCVMCAsmInfo::anchor() {}

TOYRISCVMCAsmInfo::TOYRISCVMCAsmInfo(Triple const &T) {
  AlignmentIsInBytes = true;
  Data16bitsDirective = "\t.half\t";
  Data32bitsDirective = "\t.word\t";
  Data64bitsDirective = "\t.double\t";
  PrivateGlobalPrefix = "$";
  PrivateLabelPrefix = "$";
  CommentString = "#";
  ZeroDirective = "\t.space\t";
  GPRel32Directive = "\t.gpword\t";
  GPRel64Directive = "\t.gpdword\t";
  WeakRefDirective = "\t.weak\t";
  UseAssignmentForEHBegin = true;
  SupportsDebugInformation = true;
  DwarfRegNumForCFI = true;
}

// vim: set ts=2 sw=2 sts=2:
