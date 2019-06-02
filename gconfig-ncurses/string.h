// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__STRING
#define __HEADER_FILE_PROTECTION__STRING

typedef const char *const_c_string_t;
typedef char *c_string_t;

struct string
{
    c_string_t buffer;
    int bufferSize;
};

#define string_new() _string_new(0)
extern struct string *_string_new(int len);
extern void string_add_char_back(struct string *str, char c);
extern void string_add_string_back(struct string *str, const char *backStr);
extern const_c_string_t string_get_c_string(struct string *str);
extern void string_delete(struct string *str);

#endif
