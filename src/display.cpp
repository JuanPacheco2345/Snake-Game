//PreProcessor Directives
#include <curses.h>
#include <string>

//Other source/header files
#include "init.hpp"
#include "display.hpp"
#include "apple.hpp"
#include "snake.hpp"
#include "color.hpp"



//Define the print board function
void printBoard(info &boardInfo)
{   
    //Create a wall around the edge of the screen
    for(int i = 0; i < NROWS; i++)
    {
        for(int j = 0; j < NCOLS; j++)
        {
            if(boardInfo.board[i][j] == -1)
            {
                attron(COLOR_PAIR(99));
                mvaddch(i, j, ACS_BLOCK);
                attroff(COLOR_PAIR(99));
            }
        }
    }
    
    //Refresh the screen
    refresh();
    
    //Print out the board
    for(int i = 0; i < NCOLS; i++)
    {
        for(int j = 0; j < NROWS; j++)
        {   //Print red apples
            if(boardInfo.board[j][i] == 10)
            {
                attron(COLOR_PAIR(10));
                mvaddch(j, i, 'A');
                attroff(COLOR_PAIR(10));
            }
            //Print yellow apples
            if(boardInfo.board[j][i] == 20)
            {
                attron(COLOR_PAIR(20));
                mvaddch(j, i, 'A');
                attroff(COLOR_PAIR(20));
            }
            //Print green apples
            if(boardInfo.board[j][i] == 30)
            {
                attron(COLOR_PAIR(30));
                mvaddch(j, i, 'A');
                attroff(COLOR_PAIR(30));
            }
            //Print magenta apples
            if(boardInfo.board[j][i] == 40)
            {
                attron(COLOR_PAIR(40));
                mvaddch(j, i, 'A');
                attroff(COLOR_PAIR(40));
            }
            //Print snake body
            if(boardInfo.board[j][i] == 1)
            {
                attron(COLOR_PAIR(1));
                mvaddch(j, i, 'S');
                attroff(COLOR_PAIR(1));
            }
            //Print snake head
            if(boardInfo.board[j][i] == 2)
            {
                attron(COLOR_PAIR(2));
                mvaddch(j, i, 'S');
                attroff(COLOR_PAIR(2));
            }
            //Print space
            if(boardInfo.board[j][i] == 0)
            {
                mvaddch(j, i, ' ');
            }
        }
    }
    
    //Refresh the screen
    refresh();
    
    //return
    return;
}

//Define the Welcome Screen
void welcome(void)
{   //Print out welcome
    attron(COLOR_PAIR(50));
    mvprintw((NROWS-1)/2, ((NCOLS-1)/2) - 13, "WELCOME TO THE SNAKE GAME!");
    attroff(COLOR_PAIR(50));
    
    //Print out the instructions
    mvprintw(4, (NCOLS-1)/2 - 32, 
            "The goal of the snake game is to eat as many apples as possible.");
    mvprintw(5, (NCOLS-1)/2 - 26, 
            "The snake dies if it runs into itself or into a wall.");
    mvprintw(6, (NCOLS-1)/2 - 29, 
            "There are 4 types of apples Red, Yellow, Green and Magenta.");
    mvprintw(7, (NCOLS-1)/2 - 24, 
            "Red apples are normal and give only 100 points:");
    
    attron(COLOR_PAIR(10));
    mvaddch(7, (NCOLS-1)/2 + 34, 'A');
    attroff(COLOR_PAIR(10));
    
    mvprintw(8, (NCOLS-1)/2 - 26, 
            "Yellow Apples are a bit juicier and give 1000 points:");
    
    attron(COLOR_PAIR(20));
    mvaddch(8, (NCOLS-1)/2 + 34, 'A');
    attroff(COLOR_PAIR(20));
    
    mvprintw(9, (NCOLS-1)/2 - 26, 
            "Green Apples are the juiciest and give 10000 points:");
    
    attron(COLOR_PAIR(30));
    mvaddch(9, (NCOLS-1)/2 + 34, 'A');
    attroff(COLOR_PAIR(30));
    
    mvprintw(10, (NCOLS-1)/2 - 32, 
            "Magenta apples however are poisonous eat one and the snake dies:");
    
    attron(COLOR_PAIR(40));
    mvaddch(10, (NCOLS-1)/2 + 34, 'A');
    attroff(COLOR_PAIR(40));
    
    //Refresh the screen
    refresh();
    
    //Press any key to continue
    nodelay(stdscr, FALSE);
    mvprintw((NROWS-1)/2 + 10, (NCOLS-1)/2 - 16,
            "PRESS ANY KEY TO START THE GAME!");
    
    //Grab character
    getch();
    
    //Return
    return;
}

//Define the pause function
void pauseGame(void)
{   int ch;
    
    //clear the screen
    clear();
    
    //Print out a notice that the game is paused
    mvprintw((NROWS-1)/2, ((NCOLS-1)/2) - 10, "THE GAME IS PAUSED...");
    
    nodelay(stdscr, FALSE);
    
    mvprintw((NROWS-1)/2 + 10, ((NCOLS-1)/2) - 11, "Press P/p to continue");
    
    //Refresh the screen
    refresh();
    
    //infinite loop til the player press p or P
    while(1)
    {
        ch = getch();
        
        if(ch == 'P' || ch == 'p')
        {
            break;
        }
        
    }
    
    //Change nodelay back to true
    nodelay(stdscr, TRUE);
    
    //return to the game
    return;
}

//Define the loss screen
void loss(int score)
{   //Clear screen
    clear();
    
    //Print out the loss screen
    mvprintw((NROWS-1)/2, ((NCOLS-1)/2) - 5, "GAME OVER!");
    
    //Print out the score
    mvprintw((NROWS-1)/2 + 1, ((NCOLS-1)/2) - 8, "YOUR SCORE IS: %d", score);
    
    //Press any key to continue
    nodelay(stdscr, FALSE);
    mvprintw((NROWS-1)/2 + 10, (NCOLS-1)/2 - 15,
            "PRESS ANY KEY TO END THE GAME!");
    getch();
    
    //Return
    return;
}