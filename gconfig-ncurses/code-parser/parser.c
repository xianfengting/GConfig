// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include "../defines.h"
#include "parser.h"

static const char *gconfig_head_keywords[] =
{
    "mainmenu",
    "config"
};

static void parse_mainmenu(const char *mainmenu_code)
{}

void parse_gconfig_code(const char *code, const char *fileFolder)
{
    NULL_POINTER_RETURN(code)
    NULL_POINTER_RETURN(fileFolder)
}
