#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "init.hpp"

void welcome(void);
//Displays a welcome screen

void printBoard(info &boardInfo);
//Prints the board to the window

void pauseGame(void);
//Prints a pause screen

void loss(int score);
//Prints the loss screen

#endif /* DISPLAY_HPP */