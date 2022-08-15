// Spec 2.2 Base Instruction Formats
//
//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ┌─────────────────────────┬──────────────────┬──────────────┬────────┬─────────────────┬─────────────┐
// │         funct7          │       rs2        │     rs1      │ funct3 │       rd        │   opcode    │ R-type
// ├─────────────────────────┴──────────────────┼──────────────┼────────┼─────────────────┼─────────────┤
// │                imm[11:0]                   │     rs1      │ funct3 │       rd        │   opcode    │ I-type
// ├─────────────────────────┬──────────────────┼──────────────┼────────┼─────────────────┼─────────────┤
// │        imm[11:5]        │       rs2        │     rs1      │ funct3 │   imm[4:0]      │   opcode    │ S-type
// ├───────┬─────────────────┼──────────────────┼──────────────┼────────┼─────────┬───────┼─────────────┤
// │imm[12]│    imm[10:5]    │       rs2        │     rs1      │ funct3 │imm[4:1] │imm[11]│   opcode    │ B-type
// ├───────┴─────────────────┴──────────────────┴──────────────┴────────┼─────────┴───────┼─────────────┤
// │                             imm[31:12]                             │       rd        │   opcode    │ U-type
// ├───────┬────────────────────────────┬───────┬───────────────────────┼─────────────────┼─────────────┤
// │imm[20]│         imm[10:1]          │imm[11]│      imm[19:12]       │       rd        │   opcode    │ J-type
// └───────┴────────────────────────────┴───────┴───────────────────────┴─────────────────┴─────────────┘

class Format<bits<3> val> {
  bits<3> Value = val;
}

def FormatPseudo : Format<0>;
def FormatR      : Format<1>;
def FormatI      : Format<2>;
def FormatS      : Format<3>;
def FormatU      : Format<4>;
def FormatB      : Format<5>;
def FormatJ      : Format<6>;

class TOYRISCVInst<
  dag outs, dag ins, string asmstr, list<dag> pattern,
  InstrItinClass itin, Format format
>: Instruction {
  field bits<32> Inst;

  let Namespace = "TOYRISCV";
  let Size = 4;

  bits<7> Opcode = 0;

  let Inst{6-0} = Opcode;
  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
  let Itinerary = itin;

  let TSFlags{2-0} = format.Value;
  let DecoderNamespace = "TOYRISCV";

  field bits<32> SoftFail = 0;
}

//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ┌─────────────────────────┬──────────────────┬──────────────┬────────┬─────────────────┬─────────────┐
// │         funct7          │       rs2        │     rs1      │ funct3 │       rd        │   opcode    │ R-type
// ├─────────────────────────┴──────────────────┼──────────────┼────────┼─────────────────┼─────────────┤
class TOYRISCVInstR<
  bits<7> opcode, bits<3> funct3, bits<7> funct7, dag outs, dag ins, string asmstr, list<dag> pattern, InstrItinClass itin
>: TOYRISCVInst<outs, ins, asmstr, pattern, itin, FormatR> {
  bits<5> rd;
  bits<5> rs1;
  bits<5> rs2;

  let Inst{31-25} = funct7;
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Inst{6-0} = opcode;
}

//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ├─────────────────────────┴──────────────────┼──────────────┼────────┼─────────────────┼─────────────┤
// │                imm[11:0]                   │     rs1      │ funct3 │       rd        │   opcode    │ I-type
// ├─────────────────────────┬──────────────────┼──────────────┼────────┼─────────────────┼─────────────┤
class TOYRISCVInstI<
  bits<7> opcode, bits<3> funct3, dag outs, dag ins, string asmstr, list<dag> pattern, InstrItinClass itin
>: TOYRISCVInst<outs, ins, asmstr, pattern, itin, FormatR> {
  bits<5> rd;
  bits<5> rs1;
  bits<12> imm;

  let Inst{31-20} = imm;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Inst{6-0} = opcode;
}

//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ├─────────────────────────┬──────────────────┼──────────────┼────────┼─────────────────┼─────────────┤
// │        imm[11:5]        │       rs2        │     rs1      │ funct3 │   imm[4:0]      │   opcode    │ S-type
// ├───────┬─────────────────┼──────────────────┼──────────────┼────────┼─────────┬───────┼─────────────┤
class TOYRISCVInstS<
  bits<7> opcode, bits<3> funct3, dag outs, dag ins, string asmstr, list<dag> pattern, InstrItinClass itin
>: TOYRISCVInst<outs, ins, asmstr, pattern, itin, FormatR> {
  bits<5> rs1;
  bits<5> rs2;
  bits<12> imm;

  let Inst{31-25} = imm{11-5};
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-7} = imm{4-0};
  let Inst{6-0} = opcode;
}

//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ├───────┴─────────────────┴──────────────────┴──────────────┴────────┼─────────┴───────┼─────────────┤
// │                             imm[31:12]                             │       rd        │   opcode    │ U-type
// ├───────┬────────────────────────────┬───────┬───────────────────────┼─────────────────┼─────────────┤
class TOYRISCVInstU<
  bits<7> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, InstrItinClass itin
>: TOYRISCVInst<outs, ins, asmstr, pattern, itin, FormatR> {
  bits<5> rd;
  bits<20> imm;

  let Inst{31-12} = imm;
  let Inst{11-7} = rd;
  let Inst{6-0} = opcode;
}


//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ├───────┬─────────────────┼──────────────────┼──────────────┼────────┼─────────┬───────┼─────────────┤
// │imm[12]│    imm[10:5]    │       rs2        │     rs1      │ funct3 │imm[4:1] │imm[11]│   opcode    │ B-type
// ├───────┴─────────────────┴──────────────────┴──────────────┴────────┼─────────┴───────┼─────────────┤
class TOYRISCVInstB<
  bits<7> opcode, bits<3> funct3, dag outs, dag ins, string asmstr, list<dag> pattern, InstrItinClass itin
>: TOYRISCVInst<outs, ins, asmstr, pattern, itin, FormatR> {
  bits<5> rs1;
  bits<5> rs2;
  bits<12> imm;

  let Inst{31} = imm{11};
  let Inst{30-25} = imm{9-4};
  let Inst{24-20} = rs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = funct3;
  let Inst{11-8} = imm{3-0};
  let Inst{7} = imm{10};
  let Inst{6-0} = opcode;
}

//  31      30 29 28 27 26 25 24 23 22 21   20   19 18 17 16 15 14 13 12 11 10 9 8     7   6 5 4 3 2 1 0
// ├───────┬────────────────────────────┬───────┬───────────────────────┼─────────────────┼─────────────┤
// │imm[20]│         imm[10:1]          │imm[11]│      imm[19:12]       │       rd        │   opcode    │ J-type
// └───────┴────────────────────────────┴───────┴───────────────────────┴─────────────────┴─────────────┘
class TOYRISCVInstJ<
  bits<7> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, InstrItinClass itin
>: TOYRISCVInst<outs, ins, asmstr, pattern, itin, FormatR> {
  bits<5> rd;
  bits<20> imm;

  let Inst{31} = imm{19};
  let Inst{30-21} = imm{9-0};
  let Inst{20} = imm{10};
  let Inst{19-12} = imm{18-11};
  let Inst{11-7} = rd;
  let Inst{6-0} = opcode;
}

class Pseudo<dag outs, dag ins, string asmstr = "", list<dag> pattern>
    : TOYRISCVInst<outs, ins, asmstr, pattern, IIPseudo, FormatPseudo> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}
