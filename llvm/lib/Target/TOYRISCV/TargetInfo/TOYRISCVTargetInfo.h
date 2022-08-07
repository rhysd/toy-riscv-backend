#if !defined TOYRISCVTARGETINFO_H_INCLUDED
#define TOYRISCVTARGETINFO_H_INCLUDED

namespace llvm {

class Target;

Target &getTheTOYRISCV32Target();
Target &getTheTOYRISCV64Target();

} // namespace llvm

#endif // TOYRISCVTARGETINFO_H_INCLUDED

// vim: set ts=2 sw=2 sts=2:
