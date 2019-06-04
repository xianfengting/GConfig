// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <stdio.h>
#include <string.h>

#include "util.h"
#include "string.h"

static void string_allocate_buffer(struct string *str, int len)
{
    str->buffer = xmalloc(len);
    memset(str->buffer, 0, len);
    str->bufferSize = len;
}

struct string *_string_new(int len)
{
    if (len < 0)
        return NULL;

    struct string *str = xmalloc_type(struct string, 1);
    if (len > 2)
        string_allocate_buffer(str, len);
    else
        string_allocate_buffer(str, 2);
    return str;
}

void string_add_char_back(struct string *str, char c)
{
    if (!str)
        return;

    if (str->bufferSize == strlen(str->buffer) + 1)
    {
        int newBufSize = str->bufferSize + 1;
        char *newBuf = xmalloc_type(char, newBufSize);
        sprintf(newBuf, "%s%c", str->buffer, c);
        xfree(str->buffer);
        str->buffer = newBuf;
        str->bufferSize = newBufSize;
    }
    else
    {
        str->buffer[strlen(str->buffer)] = c;
    }
}

void string_add_string_back(struct string *str, const_c_string_t backStr)
{
    for (int i = 0; i < strlen(backStr); i++)
        string_add_char_back(str, backStr[i]);
}

const_c_string_t string_get_c_string(struct string *str)
{
    return str->buffer;
}

void string_delete(struct string *str)
{
    if (!str)
        return;

    if (str->buffer)
        xfree(str->buffer);
    xfree(str);
}
