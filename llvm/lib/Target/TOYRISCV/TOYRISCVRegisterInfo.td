let Namespace = "TOYRISCV" in {
  class TOYRISCVReg<bits<5> Enc, string n, list<string> alt = []> : Register<n> {
    let HWEncoding{4-0} = Enc;
    let AltNames = alt;
  }

  class TOYRISCVGPRReg<bits<5> Enc, string n, list<string> alt> : TOYRISCVReg<Enc, n, alt>;
}

// Define 32 general purpose integer registers
let Namespace = "TOYRISCV" in {
  def ZERO : TOYRISCVGPRReg<0, "x0", ["zero"]>,  DwarfRegNum<[0]>;
  def RA   : TOYRISCVGPRReg<1,  "x1", ["ra"]>,   DwarfRegNum<[1]>;
  def SP   : TOYRISCVGPRReg<2,  "x2", ["sp"]>,   DwarfRegNum<[2]>;
  def GP   : TOYRISCVGPRReg<3,  "x3", ["gp"]>,   DwarfRegNum<[3]>;
  def TP   : TOYRISCVGPRReg<4,  "x4", ["tp"]>,   DwarfRegNum<[4]>;
  def T0   : TOYRISCVGPRReg<5,  "x5", ["t0"]>,   DwarfRegNum<[5]>;
  def T1   : TOYRISCVGPRReg<6,  "x6", ["t1"]>,   DwarfRegNum<[6]>;
  def T2   : TOYRISCVGPRReg<7,  "x7", ["t2"]>,   DwarfRegNum<[7]>;
  def FP   : TOYRISCVGPRReg<8,  "x8", ["s0", "fp"]>, DwarfRegNum<[8]>;
  def S1   : TOYRISCVGPRReg<9,  "x9", ["s1"]>,   DwarfRegNum<[9]>;
  def A0   : TOYRISCVGPRReg<10, "x10", ["a0"]>,  DwarfRegNum<[10]>;
  def A1   : TOYRISCVGPRReg<11, "x11", ["a1"]>,  DwarfRegNum<[11]>;
  def A2   : TOYRISCVGPRReg<12, "x12", ["a2"]>,  DwarfRegNum<[12]>;
  def A3   : TOYRISCVGPRReg<13, "x13", ["a3"]>,  DwarfRegNum<[13]>;
  def A4   : TOYRISCVGPRReg<14, "x14", ["a4"]>,  DwarfRegNum<[10]>;
  def A5   : TOYRISCVGPRReg<15, "x15", ["a5"]>,  DwarfRegNum<[11]>;
  def A6   : TOYRISCVGPRReg<16, "x16", ["a6"]>,  DwarfRegNum<[12]>;
  def A7   : TOYRISCVGPRReg<17, "x17", ["a7"]>,  DwarfRegNum<[13]>;
  def S2   : TOYRISCVGPRReg<18, "x18", ["s2"]>,  DwarfRegNum<[18]>;
  def S3   : TOYRISCVGPRReg<19, "x19", ["s3"]>,  DwarfRegNum<[19]>;
  def S4   : TOYRISCVGPRReg<20, "x20", ["s4"]>,  DwarfRegNum<[20]>;
  def S5   : TOYRISCVGPRReg<21, "x21", ["s5"]>,  DwarfRegNum<[21]>;
  def S6   : TOYRISCVGPRReg<22, "x22", ["s6"]>,  DwarfRegNum<[22]>;
  def S7   : TOYRISCVGPRReg<23, "x23", ["s7"]>,  DwarfRegNum<[23]>;
  def S8   : TOYRISCVGPRReg<24, "x24", ["s8"]>,  DwarfRegNum<[24]>;
  def S9   : TOYRISCVGPRReg<25, "x25", ["s9"]>,  DwarfRegNum<[25]>;
  def S10  : TOYRISCVGPRReg<26, "x26", ["s10"]>, DwarfRegNum<[26]>;
  def S11  : TOYRISCVGPRReg<27, "x27", ["s11"]>, DwarfRegNum<[27]>;
  def T3   : TOYRISCVGPRReg<28, "x28", ["t3"]>,  DwarfRegNum<[28]>;
  def T4   : TOYRISCVGPRReg<29, "x29", ["t4"]>,  DwarfRegNum<[29]>;
  def T5   : TOYRISCVGPRReg<30, "x30", ["t5"]>,  DwarfRegNum<[30]>;
  def T6   : TOYRISCVGPRReg<31, "x31", ["t6"]>,  DwarfRegNum<[31]>;
}

// Note: Type of XLenVT depends on the mode．RV32 → i32，RV64 → i64，unspecified → i32
def XLenVT : ValueTypeByHwMode<
  [RV32, RV64, DefaultMode],
  [i32,  i64,  i32]
>;

// Register class for 32 general purpose integer registers
def GPR : RegisterClass<"TOYRISCV", [XLenVT], 32, (add
  ZERO,
  A0, A1, A2, A3, A4, A5, A6, A7,                   // args, return address
  T0, T1, T2, T3, T4, T5, T6,                       // temporary (caller-saved)
  FP, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, // temoprary (callee-saved)
  RA, SP, GP, TP                                    // others
  )> {
    // Note: RegInfo<RS, SS, SA> where RS is register size, SS is memory size for spill out, SA is alignment on spill out
    let RegInfos = RegInfoByHwMode<
      [RV32,              RV64,              DefaultMode],
      [RegInfo<32,32,32>, RegInfo<64,64,64>, RegInfo<32,32,32>]
    >;
}
