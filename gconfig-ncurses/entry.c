// SPDX-License-Identifier: GPL-3.0-or-later
// This project is licensed under the Anti-996 License.

#include <ncurses.h>
#include <signal.h>
#include <ncurses.h>

#include "main.h"
#include "screen.h"
#include "consts.h"

static void signal_handler(int signal)
{}

static void get_screen_lines_and_cols(int *linesResult, int *colsResult)
{
    initscr();
    *linesResult = LINES;
    *colsResult = COLS;
    endwin();
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "The number of arguments must be at least 2 to run this program.\n");
        return EXIT_CODE__ILLEGAL_PROGRAM_ARGS;
    }
    int lines = 0, cols = 0;
    printf("GConfig is detecting your screen; please wait and do not do any work on it.\n");
    get_screen_lines_and_cols(&lines, &cols);
    printf("GConfig finished detecting your screen.\n");
    if (lines < LEAST_LINES_COUNT || cols < LEAST_COLS_COUNT)
    {
        fprintf(stderr, "The screen is too small to run GConfig; please run GConfig in another larger screen.\n"
                        "(LINES:%d, at least:%d; COLS:%d, at least:%d)\n",
                LINES, LEAST_LINES_COUNT, COLS, LEAST_COLS_COUNT);
        return EXIT_CODE__ILLEGAL_LINES_OR_COLS;
    }

    signal(SIGINT, signal_handler);
    if (gconfig_parse(argv[1]) == -1)
    {
        fprintf(stderr, "The file \"%s\" does not exist; please have a check and run GConfig again.\n", argv[1]);
        return EXIT_CODE__ILLEGAL_FILE;
    }
    // screen_init();
    // screen_destory();
}
