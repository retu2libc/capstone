/* Capstone Disassembly Engine */
/* TMS320C67x Backend by Christopher Wrogg <cwrogg@umich.edu> 2025 */

#ifdef CAPSTONE_HAS_TMS320C67X

#include <stdio.h>	// debug
#include <string.h>

#include "../../Mapping.h"
#include "../../utils.h"

#include "TMS320C67xMapping.h"

#define GET_INSTRINFO_ENUM
#include "TMS320C67xGenInstrInfo.inc"

static const name_map reg_name_maps[] = {
	{ TMS320C67X_REG_INVALID, NULL },

	{ TMS320C67X_REG_AMR, "amr" },
	{ TMS320C67X_REG_CSR, "csr" },
	{ TMS320C67X_REG_DIER, "dier" },
	{ TMS320C67X_REG_DNUM, "dnum" },
	{ TMS320C67X_REG_ECR, "ecr" },
	{ TMS320C67X_REG_GFPGFR, "gfpgfr" },
	{ TMS320C67X_REG_GPLYA, "gplya" },
	{ TMS320C67X_REG_GPLYB, "gplyb" },
	{ TMS320C67X_REG_ICR, "icr" },
	{ TMS320C67X_REG_IER, "ier" },
	{ TMS320C67X_REG_IERR, "ierr" },
	{ TMS320C67X_REG_ILC, "ilc" },
	{ TMS320C67X_REG_IRP, "irp" },
	{ TMS320C67X_REG_ISR, "isr" },
	{ TMS320C67X_REG_ISTP, "istp" },
	{ TMS320C67X_REG_ITSR, "itsr" },
	{ TMS320C67X_REG_NRP, "nrp" },
	{ TMS320C67X_REG_NTSR, "ntsr" },
	{ TMS320C67X_REG_REP, "rep" },
	{ TMS320C67X_REG_RILC, "rilc" },
	{ TMS320C67X_REG_SSR, "ssr" },
	{ TMS320C67X_REG_TSCH, "tsch" },
	{ TMS320C67X_REG_TSCL, "tscl" },
	{ TMS320C67X_REG_TSR, "tsr" },
	{ TMS320C67X_REG_A0, "a0" },
	{ TMS320C67X_REG_A1, "a1" },
	{ TMS320C67X_REG_A2, "a2" },
	{ TMS320C67X_REG_A3, "a3" },
	{ TMS320C67X_REG_A4, "a4" },
	{ TMS320C67X_REG_A5, "a5" },
	{ TMS320C67X_REG_A6, "a6" },
	{ TMS320C67X_REG_A7, "a7" },
	{ TMS320C67X_REG_A8, "a8" },
	{ TMS320C67X_REG_A9, "a9" },
	{ TMS320C67X_REG_A10, "a10" },
	{ TMS320C67X_REG_A11, "a11" },
	{ TMS320C67X_REG_A12, "a12" },
	{ TMS320C67X_REG_A13, "a13" },
	{ TMS320C67X_REG_A14, "a14" },
	{ TMS320C67X_REG_A15, "a15" },
	{ TMS320C67X_REG_A16, "a16" },
	{ TMS320C67X_REG_A17, "a17" },
	{ TMS320C67X_REG_A18, "a18" },
	{ TMS320C67X_REG_A19, "a19" },
	{ TMS320C67X_REG_A20, "a20" },
	{ TMS320C67X_REG_A21, "a21" },
	{ TMS320C67X_REG_A22, "a22" },
	{ TMS320C67X_REG_A23, "a23" },
	{ TMS320C67X_REG_A24, "a24" },
	{ TMS320C67X_REG_A25, "a25" },
	{ TMS320C67X_REG_A26, "a26" },
	{ TMS320C67X_REG_A27, "a27" },
	{ TMS320C67X_REG_A28, "a28" },
	{ TMS320C67X_REG_A29, "a29" },
	{ TMS320C67X_REG_A30, "a30" },
	{ TMS320C67X_REG_A31, "a31" },
	{ TMS320C67X_REG_B0, "b0" },
	{ TMS320C67X_REG_B1, "b1" },
	{ TMS320C67X_REG_B2, "b2" },
	{ TMS320C67X_REG_B3, "b3" },
	{ TMS320C67X_REG_B4, "b4" },
	{ TMS320C67X_REG_B5, "b5" },
	{ TMS320C67X_REG_B6, "b6" },
	{ TMS320C67X_REG_B7, "b7" },
	{ TMS320C67X_REG_B8, "b8" },
	{ TMS320C67X_REG_B9, "b9" },
	{ TMS320C67X_REG_B10, "b10" },
	{ TMS320C67X_REG_B11, "b11" },
	{ TMS320C67X_REG_B12, "b12" },
	{ TMS320C67X_REG_B13, "b13" },
	{ TMS320C67X_REG_B14, "b14" },
	{ TMS320C67X_REG_B15, "b15" },
	{ TMS320C67X_REG_B16, "b16" },
	{ TMS320C67X_REG_B17, "b17" },
	{ TMS320C67X_REG_B18, "b18" },
	{ TMS320C67X_REG_B19, "b19" },
	{ TMS320C67X_REG_B20, "b20" },
	{ TMS320C67X_REG_B21, "b21" },
	{ TMS320C67X_REG_B22, "b22" },
	{ TMS320C67X_REG_B23, "b23" },
	{ TMS320C67X_REG_B24, "b24" },
	{ TMS320C67X_REG_B25, "b25" },
	{ TMS320C67X_REG_B26, "b26" },
	{ TMS320C67X_REG_B27, "b27" },
	{ TMS320C67X_REG_B28, "b28" },
	{ TMS320C67X_REG_B29, "b29" },
	{ TMS320C67X_REG_B30, "b30" },
	{ TMS320C67X_REG_B31, "b31" },
	{ TMS320C67X_REG_PCE1, "pce1" },
};

const char *TMS320C67x_reg_name(csh handle, unsigned int reg)
{
#ifndef CAPSTONE_DIET
	if (reg >= ARR_SIZE(reg_name_maps))
		return NULL;

	return reg_name_maps[reg].name;
#else
	return NULL;
#endif
}

tms320c67x_reg TMS320C67x_reg_id(char *name)
{
	int i;

	for(i = 1; i < ARR_SIZE(reg_name_maps); i++) {
		if (!strcmp(name, reg_name_maps[i].name))
			return reg_name_maps[i].id;
	}

	return 0;
}

static const insn_map insns[] = {
	{
		0, 0,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { 0 }, 0, 0
#endif
	},

	{
		TMS320C67x_ABS_l1_pp, TMS320C67X_INS_ABS,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ABS_l1_rr, TMS320C67X_INS_ABS,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD2_d2_rrr, TMS320C67X_INS_ADD2,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD2_l1_rrr_x2, TMS320C67X_INS_ADD2,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD2_s1_rrr, TMS320C67X_INS_ADD2,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD4_l1_rrr_x2, TMS320C67X_INS_ADD4,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAB_d1_rir, TMS320C67X_INS_ADDAB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAB_d1_rrr, TMS320C67X_INS_ADDAB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAD_d1_rir, TMS320C67X_INS_ADDAD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAD_d1_rrr, TMS320C67X_INS_ADDAD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAH_d1_rir, TMS320C67X_INS_ADDAH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAH_d1_rrr, TMS320C67X_INS_ADDAH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAW_d1_rir, TMS320C67X_INS_ADDAW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDAW_d1_rrr, TMS320C67X_INS_ADDAW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDK_s2_ir, TMS320C67X_INS_ADDK,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDU_l1_rpp, TMS320C67X_INS_ADDU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADDU_l1_rrp_x2, TMS320C67X_INS_ADDU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_d1_rir, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_d1_rrr, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_d2_rir, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_d2_rrr, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_l1_ipp, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_l1_irr, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_l1_rpp, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_l1_rrp_x2, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_l1_rrr_x2, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_s1_irr, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_ADD_s1_rrr, TMS320C67X_INS_ADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_AND_d2_rir, TMS320C67X_INS_AND,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_AND_d2_rrr, TMS320C67X_INS_AND,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_AND_l1_irr, TMS320C67X_INS_AND,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_AND_l1_rrr_x2, TMS320C67X_INS_AND,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_AND_s1_irr, TMS320C67X_INS_AND,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_AND_s1_rrr, TMS320C67X_INS_AND,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_B_s5_i, TMS320C67X_INS_B,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 1, 0
#endif
	},
	{
		TMS320C67x_B_s6_r, TMS320C67X_INS_B,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 1, 0
#endif
	},
	{
		TMS320C67x_B_s7_irp, TMS320C67X_INS_B,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 1, 0
#endif
	},
	{
		TMS320C67x_B_s7_nrp, TMS320C67X_INS_B,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 1, 0
#endif
	},
	{
		TMS320C67x_CLR_s15_riir, TMS320C67X_INS_CLR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CLR_s1_rrr, TMS320C67X_INS_CLR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPEQ_l1_ipr, TMS320C67X_INS_CMPEQ,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPEQ_l1_irr, TMS320C67X_INS_CMPEQ,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPEQ_l1_rpr, TMS320C67X_INS_CMPEQ,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPEQ_l1_rrr_x2, TMS320C67X_INS_CMPEQ,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPGT_l1_ipr, TMS320C67X_INS_CMPGT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPGT_l1_irr, TMS320C67X_INS_CMPGT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPGT_l1_rpr, TMS320C67X_INS_CMPGT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPGT_l1_rrr_x2, TMS320C67X_INS_CMPGT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLTU_l1_ipr, TMS320C67X_INS_CMPLTU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLTU_l1_irr, TMS320C67X_INS_CMPLTU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLTU_l1_rpr, TMS320C67X_INS_CMPLTU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLTU_l1_rrr_x2, TMS320C67X_INS_CMPLTU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLT_l1_ipr, TMS320C67X_INS_CMPLT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLT_l1_irr, TMS320C67X_INS_CMPLT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLT_l1_rpr, TMS320C67X_INS_CMPLT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_CMPLT_l1_rrr_x2, TMS320C67X_INS_CMPLT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_EXTU_s15_riir, TMS320C67X_INS_EXTU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_EXTU_s1_rrr, TMS320C67X_INS_EXTU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_EXT_s15_riir, TMS320C67X_INS_EXT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_EXT_s1_rrr, TMS320C67X_INS_EXT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDBU_d5_mr, TMS320C67X_INS_LDBU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDBU_d6_mr, TMS320C67X_INS_LDBU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDB_d5_mr, TMS320C67X_INS_LDB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDB_d6_mr, TMS320C67X_INS_LDB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDDW_d7_mp, TMS320C67X_INS_LDDW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDHU_d5_mr, TMS320C67X_INS_LDHU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDHU_d6_mr, TMS320C67X_INS_LDHU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDH_d5_mr, TMS320C67X_INS_LDH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDH_d6_mr, TMS320C67X_INS_LDH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDW_d5_mr, TMS320C67X_INS_LDW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LDW_d6_mr, TMS320C67X_INS_LDW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LMBD_l1_irr, TMS320C67X_INS_LMBD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_LMBD_l1_rrr_x2, TMS320C67X_INS_LMBD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHLU_m4_rrr, TMS320C67X_INS_MPYHLU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHL_m4_rrr, TMS320C67X_INS_MPYHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHSLU_m4_rrr, TMS320C67X_INS_MPYHSLU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHSU_m4_rrr, TMS320C67X_INS_MPYHSU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHULS_m4_rrr, TMS320C67X_INS_MPYHULS,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHUS_m4_rrr, TMS320C67X_INS_MPYHUS,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYHU_m4_rrr, TMS320C67X_INS_MPYHU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYH_m4_rrr, TMS320C67X_INS_MPYH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYLHU_m4_rrr, TMS320C67X_INS_MPYLHU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYLH_m4_rrr, TMS320C67X_INS_MPYLH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYLSHU_m4_rrr, TMS320C67X_INS_MPYLSHU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYLUHS_m4_rrr, TMS320C67X_INS_MPYLUHS,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYSU_m4_irr, TMS320C67X_INS_MPYSU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYSU_m4_rrr, TMS320C67X_INS_MPYSU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYUS_m4_rrr, TMS320C67X_INS_MPYUS,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPYU_m4_rrr, TMS320C67X_INS_MPYU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPY_m4_irr, TMS320C67X_INS_MPY,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MPY_m4_rrr, TMS320C67X_INS_MPY,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MVC_s1_rr, TMS320C67X_INS_MVC,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MVC_s1_rr2, TMS320C67X_INS_MVC,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MVKLH_s12_ir, TMS320C67X_INS_MVKLH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MVKL_s12_ir, TMS320C67X_INS_MVKL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MVK_d1_rr, TMS320C67X_INS_MVK,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_MVK_l2_ir, TMS320C67X_INS_MVK,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_NOP_n, TMS320C67X_INS_NOP,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_NO, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_NORM_l1_pr, TMS320C67X_INS_NORM,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_NORM_l1_rr, TMS320C67X_INS_NORM,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_OR_d2_rir, TMS320C67X_INS_OR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_OR_d2_rrr, TMS320C67X_INS_OR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_OR_l1_irr, TMS320C67X_INS_OR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_OR_l1_rrr_x2, TMS320C67X_INS_OR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_OR_s1_irr, TMS320C67X_INS_OR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_OR_s1_rrr, TMS320C67X_INS_OR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SADD_l1_ipp, TMS320C67X_INS_SADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SADD_l1_irr, TMS320C67X_INS_SADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SADD_l1_rpp, TMS320C67X_INS_SADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SADD_l1_rrr_x2, TMS320C67X_INS_SADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SADD_s1_rrr, TMS320C67X_INS_SADD,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SAT_l1_pr, TMS320C67X_INS_SAT,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SET_s15_riir, TMS320C67X_INS_SET,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SET_s1_rrr, TMS320C67X_INS_SET,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHL_s1_pip, TMS320C67X_INS_SHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHL_s1_prp, TMS320C67X_INS_SHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHL_s1_rip, TMS320C67X_INS_SHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHL_s1_rir, TMS320C67X_INS_SHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHL_s1_rrp, TMS320C67X_INS_SHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHL_s1_rrr, TMS320C67X_INS_SHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHRU_s1_pip, TMS320C67X_INS_SHRU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHRU_s1_prp, TMS320C67X_INS_SHRU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHRU_s1_rir, TMS320C67X_INS_SHRU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHRU_s1_rrr, TMS320C67X_INS_SHRU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHR_s1_pip, TMS320C67X_INS_SHR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHR_s1_prp, TMS320C67X_INS_SHR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHR_s1_rir, TMS320C67X_INS_SHR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SHR_s1_rrr, TMS320C67X_INS_SHR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SMPYHL_m4_rrr, TMS320C67X_INS_SMPYHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SMPYH_m4_rrr, TMS320C67X_INS_SMPYH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SMPYLH_m4_rrr, TMS320C67X_INS_SMPYLH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SMPY_m4_rrr, TMS320C67X_INS_SMPY,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_M, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SSHL_s1_rir, TMS320C67X_INS_SSHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SSHL_s1_rrr, TMS320C67X_INS_SSHL,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SSUB_l1_ipp, TMS320C67X_INS_SSUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SSUB_l1_irr, TMS320C67X_INS_SSUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SSUB_l1_rrr_x1, TMS320C67X_INS_SSUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SSUB_l1_rrr_x2, TMS320C67X_INS_SSUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_STB_d5_rm, TMS320C67X_INS_STB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_STB_d6_rm, TMS320C67X_INS_STB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_STH_d5_rm, TMS320C67X_INS_STH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_STH_d6_rm, TMS320C67X_INS_STH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_STW_d5_rm, TMS320C67X_INS_STW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_STW_d6_rm, TMS320C67X_INS_STW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB2_d2_rrr, TMS320C67X_INS_SUB2,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB2_l1_rrr_x2, TMS320C67X_INS_SUB2,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB2_s1_rrr, TMS320C67X_INS_SUB2,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBAB_d1_rir, TMS320C67X_INS_SUBAB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBAB_d1_rrr, TMS320C67X_INS_SUBAB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBAH_d1_rir, TMS320C67X_INS_SUBAH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBAH_d1_rrr, TMS320C67X_INS_SUBAH,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBAW_d1_rir, TMS320C67X_INS_SUBAW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBAW_d1_rrr, TMS320C67X_INS_SUBAW,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBC_l1_rrr_x2, TMS320C67X_INS_SUBC,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBU_l1_rrp_x1, TMS320C67X_INS_SUBU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUBU_l1_rrp_x2, TMS320C67X_INS_SUBU,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_d1_rir, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_d1_rrr, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_d2_rrr, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_l1_ipp, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_l1_irr, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_l1_rrp_x1, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_l1_rrp_x2, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_l1_rrr_x1, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_l1_rrr_x2, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_s1_irr, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_s1_rrr, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_SUB_s4_rrr, TMS320C67X_INS_SUB,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_XOR_d2_rir, TMS320C67X_INS_XOR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_XOR_d2_rrr, TMS320C67X_INS_XOR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_D, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_XOR_l1_irr, TMS320C67X_INS_XOR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_XOR_l1_rrr_x2, TMS320C67X_INS_XOR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_L, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_XOR_s1_irr, TMS320C67X_INS_XOR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
	{
		TMS320C67x_XOR_s1_rrr, TMS320C67X_INS_XOR,
#ifndef CAPSTONE_DIET
		{ 0 }, { 0 }, { TMS320C67X_GRP_FUNIT_S, 0 }, 0, 0
#endif
	},
};

void TMS320C67x_get_insn_id(cs_struct *h, cs_insn *insn, unsigned int id)
{
	unsigned short i;

	i = insn_find(insns, ARR_SIZE(insns), id, &h->insn_cache);
	if (i != 0) {
		insn->id = insns[i].mapid;

		if (h->detail_opt) {
#ifndef CAPSTONE_DIET
			memcpy(insn->detail->regs_read, insns[i].regs_use, sizeof(insns[i].regs_use));
			insn->detail->regs_read_count = (uint8_t)count_positive(insns[i].regs_use);

			memcpy(insn->detail->regs_write, insns[i].regs_mod, sizeof(insns[i].regs_mod));
			insn->detail->regs_write_count = (uint8_t)count_positive(insns[i].regs_mod);

			memcpy(insn->detail->groups, insns[i].groups, sizeof(insns[i].groups));
			insn->detail->groups_count = (uint8_t)count_positive8(insns[i].groups);

			if (insns[i].branch || insns[i].indirect_branch) {
				insn->detail->groups[insn->detail->groups_count] = TMS320C67X_GRP_JUMP;
				insn->detail->groups_count++;
			}
#endif
		}
	}
}

#ifndef CAPSTONE_DIET
//grep TMS320C67X_INS include/capstone/tms320C67x.h | awk '{print "{"$1 "\""tolower(substr($1, 16, length($1)-16))"\"""},"}'
static const name_map insn_name_maps[] = {
	{TMS320C67X_INS_INVALID, NULL},
	{TMS320C67X_INS_ABS, "abs"},
	{TMS320C67X_INS_ADD, "add"},
	{TMS320C67X_INS_ADD2, "add2"},
	{TMS320C67X_INS_ADDAB, "addab"},
	{TMS320C67X_INS_ADDAD, "addad"},
	{TMS320C67X_INS_ADDAH, "addah"},
	{TMS320C67X_INS_ADDAW, "addaw"},
	{TMS320C67X_INS_ADDK, "addk"},
	{TMS320C67X_INS_ADDU, "addu"},
	{TMS320C67X_INS_AND, "and"},
	{TMS320C67X_INS_B, "b"},
	{TMS320C67X_INS_CLR, "clr"},
	{TMS320C67X_INS_CMPEQ, "cmpeq"},
	{TMS320C67X_INS_CMPGT, "cmpgt"},
	{TMS320C67X_INS_CMPLT, "cmplt"},
	{TMS320C67X_INS_CMPLTU, "cmpltu"},
	{TMS320C67X_INS_EXT, "ext"},
	{TMS320C67X_INS_EXTU, "extu"},
	{TMS320C67X_INS_LDB, "ldb"},
	{TMS320C67X_INS_LDBU, "ldbu"},
	{TMS320C67X_INS_LDDW, "lddw"},
	{TMS320C67X_INS_LDH, "ldh"},
	{TMS320C67X_INS_LDHU, "ldhu"},
	{TMS320C67X_INS_LDW, "ldw"},
	{TMS320C67X_INS_LMBD, "lmbd"},
	{TMS320C67X_INS_MPY, "mpy"},
	{TMS320C67X_INS_MPYH, "mpyh"},
	{TMS320C67X_INS_MPYHL, "mpyhl"},
	{TMS320C67X_INS_MPYHLU, "mpyhlu"},
	{TMS320C67X_INS_MPYHSLU, "mpyhslu"},
	{TMS320C67X_INS_MPYHSU, "mpyhsu"},
	{TMS320C67X_INS_MPYHU, "mpyhu"},
	{TMS320C67X_INS_MPYHULS, "mpyhuls"},
	{TMS320C67X_INS_MPYHUS, "mpyhus"},
	{TMS320C67X_INS_MPYLH, "mpylh"},
	{TMS320C67X_INS_MPYLHU, "mpylhu"},
	{TMS320C67X_INS_MPYLSHU, "mpylshu"},
	{TMS320C67X_INS_MPYLUHS, "mpyluhs"},
	{TMS320C67X_INS_MPYSU, "mpysu"},
	{TMS320C67X_INS_MPYU, "mpyu"},
	{TMS320C67X_INS_MPYUS, "mpyus"},
	{TMS320C67X_INS_MVC, "mvc"},
	{TMS320C67X_INS_MVK, "mvk"},
	{TMS320C67X_INS_MVKL, "mvkl"},
	{TMS320C67X_INS_MVKLH, "mvklh"},
	{TMS320C67X_INS_NOP, "nop"},
	{TMS320C67X_INS_NORM, "norm"},
	{TMS320C67X_INS_OR, "or"},
	{TMS320C67X_INS_SADD, "sadd"},
	{TMS320C67X_INS_SAT, "sat"},
	{TMS320C67X_INS_SET, "set"},
	{TMS320C67X_INS_SHL, "shl"},
	{TMS320C67X_INS_SHR, "shr"},
	{TMS320C67X_INS_SHRU, "shru"},
	{TMS320C67X_INS_SMPY, "smpy"},
	{TMS320C67X_INS_SMPYH, "smpyh"},
	{TMS320C67X_INS_SMPYHL, "smpyhl"},
	{TMS320C67X_INS_SMPYLH, "smpylh"},
	{TMS320C67X_INS_SSHL, "sshl"},
	{TMS320C67X_INS_SSUB, "ssub"},
	{TMS320C67X_INS_STB, "stb"},
	{TMS320C67X_INS_STH, "sth"},
	{TMS320C67X_INS_STW, "stw"},
	{TMS320C67X_INS_SUB, "sub"},
	{TMS320C67X_INS_SUB2, "sub2"},
	{TMS320C67X_INS_SUBAB, "subab"},
	{TMS320C67X_INS_SUBAH, "subah"},
	{TMS320C67X_INS_SUBAW, "subaw"},
	{TMS320C67X_INS_SUBC, "subc"},
	{TMS320C67X_INS_SUBU, "subu"},
	{TMS320C67X_INS_XOR, "xor"},
	{TMS320C67X_INS_IDLE, "idle"},
	{TMS320C67X_INS_MV, "mv"},
	{TMS320C67X_INS_NEG, "neg"},
	{TMS320C67X_INS_NOT, "not"},
	{TMS320C67X_INS_ZERO, "zero"},
};

#endif

const char *TMS320C67x_insn_name(csh handle, unsigned int id)
{
#ifndef CAPSTONE_DIET
	if (id >= TMS320C67X_INS_ENDING)
		return NULL;

	return insn_name_maps[id].name;
#else
	return NULL;
#endif
}

#ifndef CAPSTONE_DIET
static const name_map group_name_maps[] = {
	{ TMS320C67X_GRP_INVALID, NULL },
	{ TMS320C67X_GRP_FUNIT_D, "funit_d" },
	{ TMS320C67X_GRP_FUNIT_L, "funit_l" },
	{ TMS320C67X_GRP_FUNIT_M, "funit_m" },
	{ TMS320C67X_GRP_FUNIT_S, "funit_s" },
	{ TMS320C67X_GRP_FUNIT_NO, "funit_no" },
	{ TMS320C67X_GRP_JUMP, "jump" },
};
#endif

const char *TMS320C67x_group_name(csh handle, unsigned int id)
{
#ifndef CAPSTONE_DIET
	unsigned int i;

	if (id >= ARR_SIZE(group_name_maps))
		return NULL;

	for (i = 0; i < ARR_SIZE(group_name_maps); i++) {
		if (group_name_maps[i].id == id)
			return group_name_maps[i].name;
	}

	return group_name_maps[id].name;
#else
	return NULL;
#endif
}

tms320c67x_reg TMS320C67x_map_register(unsigned int r)
{
	static unsigned int map[] = { 0,
	};

	if (r < ARR_SIZE(map))
		return map[r];

	return 0;
}

#endif
