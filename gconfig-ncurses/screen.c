
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
