
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
