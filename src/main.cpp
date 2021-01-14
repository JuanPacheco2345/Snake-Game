#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <ctime>
#include <unistd.h>
#include <fstream>

using namespace std;

//Other source and header files
#include "init.hpp"
#include "apple.hpp"
#include "display.hpp"
#include "snake.hpp"
#include "color.hpp"

//Declare a boardInfo structure
info boardInfo;

//Define the main function
int main(int argc, char** argv) {
    //Declare position variables
    int x, y, xTwo, yTwo, xThree, yThree, xPoison, yPoison;
    int snakeRow, snakeCol, snakeBodyPosX, snakeBodyPosY;
    
    //Declare helper variables
    int ch, size, choice;
    
    //Declare informational variables
    int score;
    bool playerLost;
    DIR direction;
    DIR lastDirection = START;
    
    //initialize the screen
    initXCurses(argc, argv);
    flushinp();
    
    //initialize colors
    initColors();
    
    //Initialize and reset boardInfo
    resetInfo(boardInfo);
    
    //seed the RNG
    srand(time(0));
    
    //Print out a welcome screen
    welcome();
    
    //Initially setup the board, snake, and apple structures and classes
    //Declare snake object
    snake snakeBody;
    
    //Declare apple
    apple appleRed;
    apple appleYellow;
    apple appleGreen;
    apple applePoison[3];
    
    //Grab apple info
    appleRed.getApplePos(x, y);
    appleYellow.getApplePos(xTwo,yTwo);
    appleGreen.getApplePos(xThree, yThree);
    
    //Set the board with apple positions
    boardInfo.board[x][y] = 10;
    boardInfo.board[xTwo][yTwo] = 20;
    boardInfo.board[xThree][yThree] = 30;

    for(int i = 0; i < 3; i++)
    {
        applePoison[i].getApplePos(xPoison, yPoison);
        boardInfo.board[xPoison][yPoison] = 40;
    }
    
    //Grab snake info
    snakeBody.getHeadPos(snakeRow, snakeCol);
    
    boardInfo.board[snakeRow][snakeCol] = 2;;
    
    //Get vector size
    size = snakeBody.getVectorSize();
    
    //Set the board for the body of the snake
    for(int i = 0; i < size; i++)
    {
        snakeBody.getBodyPos(snakeBodyPosX, snakeBodyPosY, i);
        boardInfo.board[snakeBodyPosX][snakeBodyPosY] = 1;
    }
    
    //End of initial set-up
    
    //reset no delay
    nodelay(stdscr, TRUE);
    
    //Print the board
    printBoard(boardInfo);
    
    //Start of gameplay loop
    while(1)
    {   //Grab a character
        ch = getch();
        
        //grab head and apple positions
        snakeBody.getHeadPos(snakeRow, snakeCol);
        appleRed.getApplePos(x, y);
        appleYellow.getApplePos(xTwo, yTwo);
        appleGreen.getApplePos(xThree, yThree);
        
        //Check head position with red apple position
        if(snakeRow == x && snakeCol == y)
        {
            //Call a function to increment snake head
            snakeBody.snakeGrowth();
            
            //Generate a new apple
            appleRed.newApple();
            
            //Grab new apple position
            appleRed.getApplePos(x, y);
            
            //Change the game board to change apple
            boardInfo.board[x][y] = 10;
        }
        
        //Check head position with yellow apple position
        if(snakeRow == xTwo && snakeCol == yTwo)
        {
            //Call a function to increment snake head
            snakeBody.snakeGrowth();
            
            //Generate a new apple
            appleYellow.newApple();
            
            //grab new apple position
            appleYellow.getApplePos(xTwo, yTwo);
            
            //Change the game board to change apple
            boardInfo.board[xTwo][yTwo] = 20;
        }
        
        //Check head position with green apple position
        if(snakeRow == xThree && snakeCol == yThree)
        {
            //Call a function to increment snake head
            snakeBody.snakeGrowth();
            
            //Generate a new apple
            appleGreen.newApple();
            
            //grab new apple position
            appleGreen.getApplePos(xThree, yThree);
            
            //Change the game board to change apple
            boardInfo.board[xThree][yThree] = 30;
        }
        
        //Change Direction, Pause, Quit, Change Speed,
        //Or keep moving in the same direction
        if(ch == KEY_LEFT && lastDirection != RIGHT)
        {
            //move left
            direction = LEFT;
            snakeBody.move(boardInfo, direction);
            lastDirection = direction;
        }
        else if(ch == KEY_DOWN && lastDirection != UP)
        {
            //move down
            direction = DOWN;
            snakeBody.move(boardInfo, direction);
            lastDirection = direction;
        }
        else if(ch == KEY_RIGHT && lastDirection != LEFT)
        {
            //move right
            direction = RIGHT;
            snakeBody.move(boardInfo, direction);
            lastDirection = direction;
        }
        else if(ch == KEY_UP && lastDirection != DOWN)
        {
            //move up
            direction = UP;
            snakeBody.move(boardInfo, direction);
            lastDirection = direction;
        }
        else if(ch == '+' && boardInfo.speed != 100)
        {
            boardInfo.speed = boardInfo.speed / 10;
        }
        else if(ch == '-' && boardInfo.speed != 100000)
        {
            boardInfo.speed = boardInfo.speed * 10;
        }
        else if(ch == 'P' || ch == 'p')
        {
            pauseGame();
        }
        else if(ch == 'Q' || ch == 'q')
        {
            playerLost = false;
            break;
        }
        else
        {
            //move in last direction
            snakeBody.move(boardInfo, lastDirection);
        }
        
        //Grab poison apple coordinates and compare to head position
        for(int i = 0; i < 3; i++)
        {
            applePoison[i].getApplePos(xPoison, yPoison);
            if(snakeRow == xPoison && snakeCol == yPoison)
            {
                playerLost = true;
            }
        }
        
        //Break out of the loop if the snake eats the apple
        if(playerLost == true)
        {
            break;
        }
        
        //Check if snake has collided with itself or wall
        if(snakeBody.snakeCollision() == true)
        {
            cout << "Snake has collided." << endl;
            playerLost = true;
            break;
        }
        
        //print the board
        printBoard(boardInfo);
    
        //sleep to slow down the game
        usleep(boardInfo.speed);
        
    }
    
    //Print out loss
    if(playerLost == true)
    {
        score = 100 * appleRed.getAppleEaten();
        score = score + (1000 * appleYellow.getAppleEaten());
        score = score + (10000 * appleGreen.getAppleEaten());
        loss(score);
    }
    
    //Close window
    endwin();
    
    exit(EXIT_SUCCESS);
}