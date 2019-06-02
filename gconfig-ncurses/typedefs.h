// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__TYPEDEFS
#define __HEADER_FILE_PROTECTION__TYPEDEFS

#ifdef __cplusplus
typedef bool bool_t;
#else
typedef char bool_t;
#ifdef true
#pragma comment("The macro 'true' is defined; undefining it")
#undef true
#endif
#define true ((bool_t) 1)
#ifdef false
#pragma comment("The macro 'false' is defined; undefining it")
#undef false
#endif
#define false ((bool_t) 0)
#endif

typedef int func_result_t;
#define FUNC_RESULT__NORMAL ((func_result_t) 0)
#define FUNC_RESULT__ERROR ((func_result_t) -1)

#endif
