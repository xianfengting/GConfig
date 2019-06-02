// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__STRING
#define __HEADER_FILE_PROTECTION__STRING

struct string
{
    char *buffer;
    int bufferSize;
};

#define string_new() _string_new(0)
extern struct string *_string_new(int len);
extern void string_add_char_back(struct string *str, char c);
extern void string_delete(struct string *str);

#endif
