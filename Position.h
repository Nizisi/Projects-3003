#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#ifndef POSITION_H
#define POSITION_H
class Position
{
public:
    int x;
    int y;
    float dx = 0; // Velocity
    float dy = 0;

    virtual void setPos() {}
};

class PlayerPosition : public Position
{
public:
    //player's initial position
    int iniH = 200;
    int iniX = 100;
    int iniY = 100;

    void setPos() {}

    void checkInput()
    {
        //kryboard input move the player
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            iniX += 3;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            iniX -= 3;
        }


    }

};
class PlatPosition : public Position
{
public:
    int iniH;
    int iniX;
    int iniY;


    void setPos() {}
};


#endif // !POSITION_H
