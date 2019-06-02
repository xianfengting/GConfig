// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <ncurses.h>
#include <signal.h>

#include "main.h"
#include "screen.h"

static void signal_handler(int signal)
{}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "The number of arguments must be at least 2 to run this program.\n");
        return -1;
    }
    signal(SIGINT, signal_handler);
    gconfig_parse(argv[1]);
    // screen_init();
    // screen_destory();
}
