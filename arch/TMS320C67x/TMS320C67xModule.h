/* Capstone Disassembly Engine */
/* By Christopher Wrogg <cwrogg@umich.edu>, 2025 */

#ifndef CS_TMS320C67X_MODULE_H
#define CS_TMS320C67X_MODULE_H

#include "../../utils.h"

cs_err TMS320C67x_global_init(cs_struct *ud);
cs_err TMS320C67x_option(cs_struct *handle, cs_opt_type type, size_t value);

#endif
