#include <vector>

//include other headers and source
#include "snake.hpp"
#include "init.hpp"

//Define the default constructor for the snake
snake::snake()
{
    snakeHeadX = (NROWS-1)/2;
    snakeHeadY = (NCOLS-1)/2;
    snakeDirection = START;
    snakeLength = 5;
    snakeGrow = false;
    
    //Initialize the vectors
    for (int i = 1; i < 5; i++)
    {
        snakeBodyX.push_back(snakeHeadX + i);
        snakeBodyY.push_back(snakeHeadY);
    }
}

//Define the move member function for the snake
void snake::move(info &boardInfo, DIR direction)
{   //Declare variables
    int lastElement = (snakeBodyX.size()-1);
    snakeDirection = direction;
    int savedXPos, savedYPos;
    
    //save the x and y positions of the last element/body of the snake if
    //the snake needs to grow
    if(snakeGrow == true)
    {
        savedXPos = snakeBodyX[lastElement];
        savedYPos = snakeBodyY[lastElement];
    }
    
    //Move the snake
    if(snakeDirection == UP)
    {
        //Delete the last position of the end of the snake
        boardInfo.board[snakeBodyX[lastElement]][snakeBodyY[lastElement]] = 0;
        //Move the body of the snake
        for(int i = (snakeBodyX.size()-1); i > 0; i--)
        {
            snakeBodyX[i] = snakeBodyX[i-1];
            snakeBodyY[i] = snakeBodyY[i-1];
            boardInfo.board[snakeBodyX[i]][snakeBodyY[i]] = 1;
        }
        //Move the first body part to the head position
        snakeBodyX[0] = snakeHeadX;
        snakeBodyY[0] = snakeHeadY;
        //Change the head position
        snakeHeadX--;
        //Update the board
        boardInfo.board[snakeHeadX][snakeHeadY] = 2;
        boardInfo.board[snakeBodyX[0]][snakeBodyY[0]] = 1;
    }
    else if(snakeDirection == DOWN)
    {
        boardInfo.board[snakeBodyX[lastElement]][snakeBodyY[lastElement]] = 0;
        for(int i = (snakeBodyX.size()-1); i > 0; i--)
        {
            snakeBodyX[i] = snakeBodyX[i-1];
            snakeBodyY[i] = snakeBodyY[i-1];
            boardInfo.board[snakeBodyX[i]][snakeBodyY[i]] = 1;
        }
        snakeBodyX[0] = snakeHeadX;
        snakeBodyY[0] = snakeHeadY;
        snakeHeadX++;
        boardInfo.board[snakeHeadX][snakeHeadY] = 2;
        boardInfo.board[snakeBodyX[0]][snakeBodyY[0]] = 1;
    }
    else if(snakeDirection == LEFT)
    {
        boardInfo.board[snakeBodyX[lastElement]][snakeBodyY[lastElement]] = 0;
        for(int i = (snakeBodyX.size()-1); i > 0; i--)
        {
            snakeBodyX[i] = snakeBodyX[i-1];
            snakeBodyY[i] = snakeBodyY[i-1];
            boardInfo.board[snakeBodyX[i]][snakeBodyY[i]] = 1;
        }
        snakeBodyX[0] = snakeHeadX;
        snakeBodyY[0] = snakeHeadY;
        snakeHeadY--;
        boardInfo.board[snakeHeadX][snakeHeadY] = 2;
        boardInfo.board[snakeBodyX[0]][snakeBodyY[0]] = 1;
    }
    else if(snakeDirection == RIGHT)
    {
        boardInfo.board[snakeBodyX[lastElement]][snakeBodyY[lastElement]] = 0;
        for(int i = (snakeBodyX.size()-1); i > 0; i--)
        {
            snakeBodyX[i] = snakeBodyX[i-1];
            snakeBodyY[i] = snakeBodyY[i-1];
            boardInfo.board[snakeBodyX[i]][snakeBodyY[i]] = 1;
        }
        snakeBodyX[0] = snakeHeadX;
        snakeBodyY[0] = snakeHeadY;
        snakeHeadY++;
        boardInfo.board[snakeHeadX][snakeHeadY] = 2;
        boardInfo.board[snakeBodyX[0]][snakeBodyY[0]] = 1;
    }
    
    //Check if the snake needs to grow
    if(snakeGrow == true)
    {
        //Push back the body vectors
        snakeBodyX.push_back(savedXPos);
        snakeBodyY.push_back(savedYPos);
        //Change the last element to the new last element
        lastElement = (snakeBodyX.size()-1);
        //Update the board
        boardInfo.board[snakeBodyX[lastElement]][snakeBodyY[lastElement]] = 1;
        //reset snake growth
        snakeGrow = false;
    }
    
    //return
    return;
}

//Define the getHeadPos member function
void snake::getHeadPos(int &X, int &Y)
{   //set the x and y positions
    X = snakeHeadX;
    Y = snakeHeadY;
    
    //return
    return;
}

//Define the getBodyPos member function
void snake::getBodyPos(int& X, int& Y, int q)
{   //set the body positions
    X = snakeBodyX[q];
    Y = snakeBodyY[q];
}

//Define the getVector size member function
int snake::getVectorSize(void)
{   //Return the vector size
    return(snakeBodyX.size());
}

//Define the snakeHeadWall collision function
bool snake::snakeCollision(void)
{   //Check if the snake has eaten his body
    for(int i=0; i<snakeLength; i++)
    {
        if(snakeHeadX == snakeBodyX[i] && snakeHeadY == snakeBodyY[i])
            return(true);
    }
    
    //Check if the snake has hit a wall
    if (snakeHeadX == 0 || snakeHeadX == NROWS-1 || snakeHeadY == 0 ||
            snakeHeadY == NCOLS-1)
        return(true);
    else
        return(false);
}

void snake::snakeGrowth(void)
{   //Set snakeGrow to true
    snakeGrow = true;
    
    return;
}