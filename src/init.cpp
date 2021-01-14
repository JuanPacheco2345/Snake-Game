#define XCURSES

#include <curses.h>

#include "init.hpp"

//------------------------------------------------------------//
void initXCurses(int argc, char** argv)
{
 Xinitscr(argc, argv); // Initialize X Display Screen
 PDC_set_title("Snake Game");
 // Relabel Window Title
 cbreak(); // Retain ^C Behavior

 curs_set(FALSE); // Make Cursor Invisible
 keypad(stdscr, TRUE); // Turn on Keypad
 if (getch()==KEY_RESIZE) // Match screen to current
    resize_term(0,0); // terminal size
 noecho(); // Don't echo input

 start_color(); // Start NCURSES Color

 nodelay(stdscr, TRUE); // Do not wait for input

 return;
}
//------------------------------------------------------------// 

//------------------------------------------------------------//
//Define the resetInfo function
void resetInfo(info &boardInfo)
{
    //Initialize the board to have all zeros
    for (int i = 0; i < NROWS; i++)
    {
        for(int j = 0; j < NCOLS; j++)
        {
            boardInfo.board[i][j] = 0;
        }
    }
    
    //Initialize the walls
    for(int i = 0; i < NCOLS; i++)
    {
        boardInfo.board[0][i] = -1;
        boardInfo.board[NROWS-1][i] = -1;
    }
    
    for(int i = 0; i < NROWS; i++)
    {
        boardInfo.board[i][0] = -1;
        boardInfo.board[i][NCOLS-1] = -1;
    }
    
    //Initialize speed
    boardInfo.speed = 100;
    
    //return
    return;
}