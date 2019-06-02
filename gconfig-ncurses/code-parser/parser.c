// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include "parser.h"

static const char *gconfig_head_keywords[] =
{
    "mainmenu",
    "config"
};

static void parse_mainmenu(const char *mainmenu_code)
{}

void parse_gconfig_code(const char *code)
{
    if (!code)
        return;
}
