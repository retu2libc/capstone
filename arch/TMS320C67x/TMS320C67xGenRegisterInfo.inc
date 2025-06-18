/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*Target Register Enum Values                                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM

enum {
  TMS320C67x_NoRegister,
  TMS320C67x_AMR = 1,
  TMS320C67x_CSR = 2,
  TMS320C67x_FADCR = 3,
  TMS320C67x_FAUCR = 4,
  TMS320C67x_FMCR = 5,
  TMS320C67x_ICR = 6,
  TMS320C67x_IER = 7,
  TMS320C67x_IFR = 8,
  TMS320C67x_IRP = 9,
  TMS320C67x_ISR = 10,
  TMS320C67x_ISTP = 11,
  TMS320C67x_NRP = 12,
  TMS320C67x_PCE1 = 13,
  TMS320C67x_A0 = 14,
  TMS320C67x_A1 = 15,
  TMS320C67x_A2 = 16,
  TMS320C67x_A3 = 17,
  TMS320C67x_A4 = 18,
  TMS320C67x_A5 = 19,
  TMS320C67x_A6 = 20,
  TMS320C67x_A7 = 21,
  TMS320C67x_A8 = 22,
  TMS320C67x_A9 = 23,
  TMS320C67x_A10 = 24,
  TMS320C67x_A11 = 25,
  TMS320C67x_A12 = 26,
  TMS320C67x_A13 = 27,
  TMS320C67x_A14 = 28,
  TMS320C67x_A15 = 29,
  TMS320C67x_A16 = 30,
  TMS320C67x_A17 = 31,
  TMS320C67x_A18 = 32,
  TMS320C67x_A19 = 33,
  TMS320C67x_A20 = 34,
  TMS320C67x_A21 = 35,
  TMS320C67x_A22 = 36,
  TMS320C67x_A23 = 37,
  TMS320C67x_A24 = 38,
  TMS320C67x_A25 = 39,
  TMS320C67x_A26 = 40,
  TMS320C67x_A27 = 41,
  TMS320C67x_A28 = 42,
  TMS320C67x_A29 = 43,
  TMS320C67x_A30 = 44,
  TMS320C67x_A31 = 45,
  TMS320C67x_B0 = 46,
  TMS320C67x_B1 = 47,
  TMS320C67x_B2 = 48,
  TMS320C67x_B3 = 49,
  TMS320C67x_B4 = 50,
  TMS320C67x_B5 = 51,
  TMS320C67x_B6 = 52,
  TMS320C67x_B7 = 53,
  TMS320C67x_B8 = 54,
  TMS320C67x_B9 = 55,
  TMS320C67x_B10 = 56,
  TMS320C67x_B11 = 57,
  TMS320C67x_B12 = 58,
  TMS320C67x_B13 = 59,
  TMS320C67x_B14 = 60,
  TMS320C67x_B15 = 61,
  TMS320C67x_B16 = 62,
  TMS320C67x_B17 = 63,
  TMS320C67x_B18 = 64,
  TMS320C67x_B19 = 65,
  TMS320C67x_B20 = 66,
  TMS320C67x_B21 = 67,
  TMS320C67x_B22 = 68,
  TMS320C67x_B23 = 69,
  TMS320C67x_B24 = 70,
  TMS320C67x_B25 = 71,
  TMS320C67x_B26 = 72,
  TMS320C67x_B27 = 73,
  TMS320C67x_B28 = 74,
  TMS320C67x_B29 = 75,
  TMS320C67x_B30 = 76,
  TMS320C67x_B31 = 77,
  TMS320C67x_NUM_TARGET_REGS // 78
};

// Register classes
enum {
  TMS320C67x_GPRegsRegClassID = 0,
  TMS320C67x_AFRegsRegClassID = 1,
  TMS320C67x_BFRegsRegClassID = 2,
  TMS320C67x_ControlRegsRegClassID = 3,

  };
#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*MC Register Information                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC

static const MCPhysReg TMS320C67xRegDiffLists[] = {
  /* 0 */ -1, 0,
};

static const uint16_t TMS320C67xSubRegIdxLists[] = {
  /* 0 */ 0,
};

static const MCRegisterDesc TMS320C67xRegDesc[] = { // Descriptors
  { 3, 0, 0, 0, 0 },
  { 241, 1, 1, 0, 1 },
  { 245, 1, 1, 0, 1 },
  { 249, 1, 1, 0, 1 },
  { 255, 1, 1, 0, 1 },
  { 261, 1, 1, 0, 1 },
  { 266, 1, 1, 0, 1 },
  { 270, 1, 1, 0, 1 },
  { 274, 1, 1, 0, 1 },
  { 278, 1, 1, 0, 1 },
  { 282, 1, 1, 0, 1 },
  { 287, 1, 1, 0, 1 },
  { 286, 1, 1, 0, 1 },
  { 24, 1, 1, 0, 1 },
  { 54, 1, 1, 0, 1 },
  { 81, 1, 1, 0, 1 },
  { 103, 1, 1, 0, 1 },
  { 125, 1, 1, 0, 1 },
  { 147, 1, 1, 0, 1 },
  { 169, 1, 1, 0, 1 },
  { 191, 1, 1, 0, 1 },
  { 213, 1, 1, 0, 1 },
  { 235, 1, 1, 0, 1 },
  { 0, 1, 1, 0, 1 },
  { 30, 1, 1, 0, 1 },
  { 65, 1, 1, 0, 1 },
  { 87, 1, 1, 0, 1 },
  { 109, 1, 1, 0, 1 },
  { 131, 1, 1, 0, 1 },
  { 153, 1, 1, 0, 1 },
  { 175, 1, 1, 0, 1 },
  { 197, 1, 1, 0, 1 },
  { 219, 1, 1, 0, 1 },
  { 8, 1, 1, 0, 1 },
  { 38, 1, 1, 0, 1 },
  { 73, 1, 1, 0, 1 },
  { 95, 1, 1, 0, 1 },
  { 117, 1, 1, 0, 1 },
  { 139, 1, 1, 0, 1 },
  { 161, 1, 1, 0, 1 },
  { 183, 1, 1, 0, 1 },
  { 205, 1, 1, 0, 1 },
  { 227, 1, 1, 0, 1 },
  { 16, 1, 1, 0, 1 },
  { 46, 1, 1, 0, 1 },
  { 27, 1, 1, 0, 1 },
  { 57, 1, 1, 0, 1 },
  { 84, 1, 1, 0, 1 },
  { 106, 1, 1, 0, 1 },
  { 128, 1, 1, 0, 1 },
  { 150, 1, 1, 0, 1 },
  { 172, 1, 1, 0, 1 },
  { 194, 1, 1, 0, 1 },
  { 216, 1, 1, 0, 1 },
  { 238, 1, 1, 0, 1 },
  { 4, 1, 1, 0, 1 },
  { 34, 1, 1, 0, 1 },
  { 69, 1, 1, 0, 1 },
  { 91, 1, 1, 0, 1 },
  { 113, 1, 1, 0, 1 },
  { 135, 1, 1, 0, 1 },
  { 157, 1, 1, 0, 1 },
  { 179, 1, 1, 0, 1 },
  { 201, 1, 1, 0, 1 },
  { 223, 1, 1, 0, 1 },
  { 12, 1, 1, 0, 1 },
  { 42, 1, 1, 0, 1 },
  { 77, 1, 1, 0, 1 },
  { 99, 1, 1, 0, 1 },
  { 121, 1, 1, 0, 1 },
  { 143, 1, 1, 0, 1 },
  { 165, 1, 1, 0, 1 },
  { 187, 1, 1, 0, 1 },
  { 209, 1, 1, 0, 1 },
  { 231, 1, 1, 0, 1 },
  { 20, 1, 1, 0, 1 },
  { 50, 1, 1, 0, 1 },
  { 60, 1, 1, 0, 1 },
};

// GPRegs Register Class...
static const MCPhysReg GPRegs[] = {
  TMS320C67x_A0, TMS320C67x_A1, TMS320C67x_A2, TMS320C67x_A3, TMS320C67x_A4, TMS320C67x_A5, TMS320C67x_A6, TMS320C67x_A7, TMS320C67x_A8, TMS320C67x_A9, TMS320C67x_A10, TMS320C67x_A11, TMS320C67x_A12, TMS320C67x_A13, TMS320C67x_A14, TMS320C67x_A15, TMS320C67x_A16, TMS320C67x_A17, TMS320C67x_A18, TMS320C67x_A19, TMS320C67x_A20, TMS320C67x_A21, TMS320C67x_A22, TMS320C67x_A23, TMS320C67x_A24, TMS320C67x_A25, TMS320C67x_A26, TMS320C67x_A27, TMS320C67x_A28, TMS320C67x_A29, TMS320C67x_A30, TMS320C67x_A31, TMS320C67x_B0, TMS320C67x_B1, TMS320C67x_B2, TMS320C67x_B3, TMS320C67x_B4, TMS320C67x_B5, TMS320C67x_B6, TMS320C67x_B7, TMS320C67x_B8, TMS320C67x_B9, TMS320C67x_B10, TMS320C67x_B11, TMS320C67x_B12, TMS320C67x_B13, TMS320C67x_B14, TMS320C67x_B15, TMS320C67x_B16, TMS320C67x_B17, TMS320C67x_B18, TMS320C67x_B19, TMS320C67x_B20, TMS320C67x_B21, TMS320C67x_B22, TMS320C67x_B23, TMS320C67x_B24, TMS320C67x_B25, TMS320C67x_B26, TMS320C67x_B27, TMS320C67x_B28, TMS320C67x_B29, TMS320C67x_B30, TMS320C67x_B31,
};

// GPRegs Bit set.
static const uint8_t GPRegsBits[] = {
  0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01,
};

// AFRegs Register Class...
static const MCPhysReg AFRegs[] = {
  TMS320C67x_A0, TMS320C67x_A1, TMS320C67x_A2, TMS320C67x_A3, TMS320C67x_A4, TMS320C67x_A5, TMS320C67x_A6, TMS320C67x_A7, TMS320C67x_A8, TMS320C67x_A9, TMS320C67x_A10, TMS320C67x_A11, TMS320C67x_A12, TMS320C67x_A13, TMS320C67x_A14, TMS320C67x_A15, TMS320C67x_A16, TMS320C67x_A17, TMS320C67x_A18, TMS320C67x_A19, TMS320C67x_A20, TMS320C67x_A21, TMS320C67x_A22, TMS320C67x_A23, TMS320C67x_A24, TMS320C67x_A25, TMS320C67x_A26, TMS320C67x_A27, TMS320C67x_A28, TMS320C67x_A29, TMS320C67x_A30, TMS320C67x_A31,
};

// AFRegs Bit set.
static const uint8_t AFRegsBits[] = {
  0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x01,
};

// BFRegs Register Class...
static const MCPhysReg BFRegs[] = {
  TMS320C67x_B0, TMS320C67x_B1, TMS320C67x_B2, TMS320C67x_B3, TMS320C67x_B4, TMS320C67x_B5, TMS320C67x_B6, TMS320C67x_B7, TMS320C67x_B8, TMS320C67x_B9, TMS320C67x_B10, TMS320C67x_B11, TMS320C67x_B12, TMS320C67x_B13, TMS320C67x_B14, TMS320C67x_B15, TMS320C67x_B16, TMS320C67x_B17, TMS320C67x_B18, TMS320C67x_B19, TMS320C67x_B20, TMS320C67x_B21, TMS320C67x_B22, TMS320C67x_B23, TMS320C67x_B24, TMS320C67x_B25, TMS320C67x_B26, TMS320C67x_B27, TMS320C67x_B28, TMS320C67x_B29, TMS320C67x_B30, TMS320C67x_B31,
};

// BFRegs Bit set.
static const uint8_t BFRegsBits[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x01,
};

// ControlRegs Register Class...
static const MCPhysReg ControlRegs[] = {
  TMS320C67x_AMR, TMS320C67x_CSR, TMS320C67x_FADCR, TMS320C67x_FAUCR, TMS320C67x_FMCR, TMS320C67x_ICR, TMS320C67x_IER, TMS320C67x_IRP, TMS320C67x_ISR, TMS320C67x_ISTP, TMS320C67x_NRP, TMS320C67x_PCE1,
};

// ControlRegs Bit set.
static const uint8_t ControlRegsBits[] = {
  0xfe, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
};

static const MCRegisterClass TMS320C67xMCRegisterClasses[] = {
  { GPRegs, GPRegsBits, TMS320C67x_GPRegsRegClassID },
  { AFRegs, AFRegsBits, TMS320C67x_AFRegsRegClassID },
  { BFRegs, BFRegsBits, TMS320C67x_BFRegsRegClassID },
  { ControlRegs, ControlRegsBits, TMS320C67x_ControlRegsRegClassID },
};

#endif // GET_REGINFO_MC_DESC