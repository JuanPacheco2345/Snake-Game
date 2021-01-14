#include<curses.h>
#include<cstdlib>

#include"init.hpp"
#include"color.hpp"
#define XCURSES

using namespace std;

void initColors(void)
{
    //Initialize color pairs
    init_pair(50, COLOR_RED, COLOR_BLACK);
    init_pair(40, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(30, COLOR_GREEN, COLOR_BLACK);
    init_pair(20, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(99, COLOR_WHITE, COLOR_WHITE);
}