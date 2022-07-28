// ra, sp, fp(s0), s1..s11 are callee-saved registers. Reger spec p.137
def CSR_LP32 : CalleeSavedRegs<(add RA, SP, FP, S1, (sequence "S%u", 2, 11))>;
