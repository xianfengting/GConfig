// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__UTIL
#define __HEADER_FILE_PROTECTION__UTIL

#include <stdlib.h>

#define xmalloc_type(type, size) xmalloc(sizeof(type) * size)

extern void *xmalloc(size_t size);
extern void xfree(void *mem);

#endif
