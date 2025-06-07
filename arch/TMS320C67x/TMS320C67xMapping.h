/* Capstone Disassembly Engine */
/* TMS320C67x Backend by Christopher Wrogg <cwrogg@umich.edu> 2025 */

#ifndef CS_TMS320C67X_MAP_H
#define CS_TMS320C67X_MAP_H

#include "capstone/capstone.h"

// return name of register in friendly string
const char *TMS320C67x_reg_name(csh handle, unsigned int reg);

// given internal insn id, return public instruction info
void TMS320C67x_get_insn_id(cs_struct *h, cs_insn *insn, unsigned int id);

const char *TMS320C67x_insn_name(csh handle, unsigned int id);

const char *TMS320C67x_group_name(csh handle, unsigned int id);

// map internal raw register to 'public' register
tms320c67x_reg TMS320C67x_map_register(unsigned int r);

// map register name to register ID
tms320c67x_reg TMS320C67x_reg_id(char *name);

#endif

