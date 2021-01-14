#ifndef INIT_HPP
#define INIT_HPP

const int NROWS = 48;
const int NCOLS = 96;

enum DIR {UP, DOWN, LEFT, RIGHT, START};

struct info
{
    int board[NROWS][NCOLS];
    int speed;
};

extern info boardInfo;

void initXCurses(int argc, char** argv);
//Initializes the Xcurses library

void resetInfo(info &boardInfo);
//Resets the board

#endif /* INIT_HPP */
