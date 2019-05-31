// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include "screen.h"

WINDOW *main_window = NULL;

void screen_init(void)
{
    main_window = initscr();
    noecho();
}

void screen_destory(void)
{
    endwin();
}
