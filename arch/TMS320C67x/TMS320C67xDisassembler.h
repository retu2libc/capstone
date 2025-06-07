/* Capstone Disassembly Engine */
/* TMS320C67x Backend by Christopher Wrogg <cwrogg@umich.edu> 2025 */

#ifndef CS_TMS320C67XDISASSEMBLER_H
#define CS_TMS320C67XDISASSEMBLER_H

#include <stdint.h>

#include "capstone/capstone.h"
#include "../../MCRegisterInfo.h"
#include "../../MCInst.h"

void TMS320C67x_init(MCRegisterInfo *MRI);

bool TMS320C67x_getInstruction(csh ud, const uint8_t *code, size_t code_len,
		MCInst *instr, uint16_t *size, uint64_t address, void *info);

#endif

