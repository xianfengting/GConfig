// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__CONSTS
#define __HEADER_FILE_PROTECTION__CONSTS

enum exit_code
{
    EXIT_CODE__NORMAL = 0,
    EXIT_CODE__OUT_OF_MEMORY = 1,
    EXIT_CODE__ILLEGAL_PROGRAM_ARGS = 2,
    EXIT_CODE__ILLEGAL_LINES_OR_COLS = 3
};

#define LEAST_LINES_COUNT ((int) 15)
#define LEAST_COLS_COUNT ((int) 60)

#endif
