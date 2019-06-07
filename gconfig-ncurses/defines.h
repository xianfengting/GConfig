// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__DEFINES
#define __HEADER_FILE_PROTECTION__DEFINES

#define NULL_POINTER_RETURN(name)\
    if (!name) return;

#define NULL_POINTER_RETURN_VALUE(name, val)\
    if (!name) return val;

#endif
