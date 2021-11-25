#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#ifndef TEXTURE_H
#define TEXTURE_H

class Texture
{
public:
    // only 3 texture needed in the game, for access and control the total mber, I use protected
    sf::Texture back;
    sf::Texture plat;
    sf::Texture player;
    sf::Texture gameOver;
    void loadToTexture();
};
void Texture::loadToTexture()
{
    back.loadFromFile("images/background02.png");
    plat.loadFromFile("images/plat.png");
    player.loadFromFile("images/player.png");
    gameOver.loadFromFile("images/gameOver.png");
}


#endif // !TEXTURE_H

