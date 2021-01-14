#include <cstdlib>

//Other header and source files
#include "init.hpp"
#include "apple.hpp"

//Define the default constructor of the apple
apple::apple()
{   //Randomly generate an apple position
    applePosX = (rand() % NROWS);
    applePosY = (rand() % NCOLS);
    //Initialize appleEaten
    appleEaten = 0;
    
    //Check if the apple is has a position in a wall
    if(applePosX == 0 || applePosX == (NROWS-1))
    {
        applePosX = (rand() % NROWS);
    }
    
    if(applePosY == 0 || applePosY == (NCOLS-1))
    {
        applePosY = (rand() % NCOLS);
    }
    
}

//Define the newApple member function
//Creates a new apple if the apple is eaten
void apple::newApple(void)
{   //Randomly generate a new apple position
    applePosX = (rand() % NROWS);
    applePosY = (rand() % NCOLS);
    //Increment appleEaten
    appleEaten++;
    
    //Check if the apple has spawned in a wall
    if(applePosX == 0 || applePosX == (NROWS-1))
    {
        applePosX = (rand() % NROWS);
    }
    
    if(applePosY == 0 || applePosY == (NCOLS-1))
    {
        applePosY = (rand() % NCOLS);
    }
    
    //return
    return;
}

//Define the getApplePos member function
void apple::getApplePos(int& X, int& Y)
{   //set the x aand y positions of the apple
    X = applePosX;
    Y = applePosY;
    
    //return
    return;
}

int apple::getAppleEaten(void)
{   //return the number of apples eaten
    return(appleEaten);
}