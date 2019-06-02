// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include "parser-util.h"

inline BOOL is_null_char(char c)
{
    switch (c)
    {
    case '\0':
    case ' ':
    case '\t':
    case '\n':
        return TRUE;
    default:
        return FALSE;
    }
}
