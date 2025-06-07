/* Capstone Disassembly Engine */
/* TMS320C67x Backend by retu2libc <cwrogg@umich.edu> 2025 */

#ifndef CS_TMS320C67XINSTPRINTER_H
#define CS_TMS320C67XINSTPRINTER_H

#include "../../MCInst.h"
#include "../../MCRegisterInfo.h"
#include "../../SStream.h"

void TMS320C67x_printInst(MCInst *MI, SStream *O, void *Info);

void TMS320C67x_post_printer(csh ud, cs_insn *insn, SStream *insn_asm, MCInst *mci);

#endif
