include "TOYRISCVInstrFormats.td"

def simm12 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isInt<12>(Imm);}]> {
  let DecoderMethod = "decodeImmOperand<12>";
}
def simm20u : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isInt<32>(Imm) && !(Imm & 0x0fff);}]> {
  let DecoderMethod = "decodeImmOperand<20>";
}
def simm32: Operand<XLenVT>, ImmLeaf<XLenVT, [{return isInt<32>(Imm);}]>;

// Arithmetic logic operations with 2 registers inputs
class ArithLogicR<
  bits<7> opcode, bits<3> funct3, bits<7> funct7, string instr, SDNode OpNode, RegisterClass RC
>: TOYRISCVInstR<
  opcode, funct3, funct7, (outs RC:$rd), (ins RC:$rs1, RC:$rs2),
  !strconcat(instr, "\t$rd, $rs1, $rs2"),
  [(set RC:$rd, (OpNode RC:$rs1, RC:$rs2))],
  IIAlu
> {
  let isReMaterializable = 1;
}

// Arithmetic logic operations with a register and an immediate inputs
class ArithLogicI<
  bits<7> opcode, bits<3> funct3, string instr, SDNode OpNode, Operand Op, RegisterClass RC
>: TOYRISCVInstI<
  opcode, funct3, (outs RC:$rd), (ins RC:$rs1, Op:$imm),
  !strconcat(instr, "\t$rd, $rs1, $imm"),
  [(set RC:$rd, (OpNode RC:$rs1, Op:$imm))],
  IIAlu
> {
  let isReMaterializable = 1;
}

// Arithmetic logic operations with an immediate input
class ArithLogicU<
  bits<7> opcode, string instr, RegisterClass RC, Operand Op
>: TOYRISCVInstU<
  opcode, (outs RC:$rd), (ins Op:$imm),
  !strconcat(instr, "\t$rd, $imm"),
  [], IIAlu
> {
  let isReMaterializable = 1;
}

def SDT_CallSeqStart : SDCallSeqStart<[SDTCisVT<0, XLenVT>, SDTCisVT<1, XLenVT>]>;
def SDT_CallSeqEnd   : SDCallSeqEnd  <[SDTCisVT<0, XLenVT>, SDTCisVT<1, XLenVT>]>;
def CallSeqStart : SDNode<"ISD::CALLSEQ_START", SDT_CallSeqStart, [SDNPHasChain, SDNPOutGlue]>;
def CallSeqEnd   : SDNode<"ISD::CALLSEQ_END",   SDT_CallSeqEnd,   [SDNPHasChain, SDNPOptInGlue, SDNPOutGlue]>;

let Defs = [SP], Uses = [SP], hasSideEffects = 1 in {
  def ADJCALLSTACKDOWN : Pseudo<(outs), (ins simm12:$amt1, simm12:$amt2), "", [(CallSeqStart timm:$amt1, timm:$amt2)]>;
  def ADJCALLSTACKUP   : Pseudo<(outs), (ins simm12:$amt1, simm12:$amt2), "", [(CallSeqEnd timm:$amt1,   timm:$amt2)]>;
}

// Instructions. Refer spec p.130
def ADDI : ArithLogicI<0b0010011, 0b000, "addi", add, simm12, GPR>;
def LUI  : ArithLogicU<0b0110111, "lui", GPR, simm20u>;
def ADD  : ArithLogicR<0b0110011, 0b000, 0b0000000, "add", add, GPR>;
