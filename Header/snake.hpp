#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include "init.hpp"

class snake
{
public:
    snake(); //Default Constructor
    void move(info &boardInfo, DIR direction); //moves the snake
    void getHeadPos(int &X, int &Y); //Gets the head of the snake
    void getBodyPos(int &X, int &Y, int q); //Gets the position of a body
    int getVectorSize(void); //returns the current size of the vector
    bool snakeCollision(void); //Detects collision with wall
    void snakeGrowth(void); //Tells the class that the snake needs to grow
    
private:
    int snakeHeadX;
    int snakeHeadY;
    DIR snakeDirection;
    int snakeLength; //including the head
    bool snakeGrow;
    std::vector<int> snakeBodyX;
    std::vector<int> snakeBodyY;
};

#endif /* SNAKE_HPP */