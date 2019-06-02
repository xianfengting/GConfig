// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#ifndef __HEADER_FILE_PROTECTION__SCREEN
#define __HEADER_FILE_PROTECTION__SCREEN

#include "../typedefs.h"
#include "../list.h"

enum config_type
{
    CONFIG_TYPE__BOOL = 0,
    CONFIG_TYPE__INT = 1,
    CONFIG_TYPE__STRING = 2
};

struct config
{
    char *name;
    char *title;
    config_type type;
};

struct menu
{
    bool_t isMain;
    char *name;
    char *title;
    struct list_head *configList;
    struct list_head *subMenuList;
};

#endif
