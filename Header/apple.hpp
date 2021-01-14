#ifndef APPLE_HPP
#define APPLE_HPP

class apple
{
public:
    apple(); //Default constructor
    void newApple(void); // Function to create a new apple
    void getApplePos(int &X, int &Y); //Function to determine apple position
    int getAppleEaten(void); //Function to get how many apples were eaten
    
private:
    int applePosX; //Contains the X position of the apple
    int applePosY; //Contains the Y position of the apple
    int appleEaten; //Contains the number of apples eaten
    int appleColor; //Contains the color of the apple
};


#endif /* APPLE_HPP */