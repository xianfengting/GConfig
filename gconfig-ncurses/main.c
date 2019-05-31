// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under 996 License.

#include <ncurses.h>
#include <signal.h>

#include "screen.h"

static void signal_handler(int signal)
{}

int main(int argc, const char *argv[])
{
    signal(SIGINT, signal_handler);
    screen_init();
    screen_destory();
}
