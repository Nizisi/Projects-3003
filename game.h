#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Position.h"
#include "texture.h"

#ifndef GAME_H
#define GAME_H
void mainGame() {


    //generate random based on time
    srand(time(0));
    /*
    sf::RenderWindow. This class is derived from sf::Window, and inherits all its functions
    */
    sf::RenderWindow game(sf::VideoMode(800, 600), "Jump Game");
    game.setFramerateLimit(60); //to avoid visual tearing
    Texture texture;
    //texture is a image of the object
    texture.loadToTexture();

    //sprite is the object I want to have for the game
    sf::Sprite background(texture.back);
    sf::Sprite plat(texture.plat);
    sf::Sprite player(texture.player);
    sf::Sprite gameOver(texture.gameOver);

    Position pos;
    PlatPosition platform[10];
    PlayerPosition playerPos;


    //// Localize all platforms
    for (int i = 0; i < 10; i++)
    {

        platform[i].x = rand() % 689;
        platform[i].y = rand() % 596;
    }

    // above is all for the set of the game




    // a loop to show the window
    while (game.isOpen())
    {
        // following is to check the event before any display
        sf::Event event;
        while (game.pollEvent(event))
        {
            // close event trigger the window to close
            if (event.type == sf::Event::Closed)
                game.close();
        }


        playerPos.checkInput();

        // Moving the player up and down
        pos.dy += 0.2;
        playerPos.iniY += pos.dy;

        // player died

        if (playerPos.iniY > 500)
        {

            pos.dy = -10;
            while (game.isOpen())
            {
                sf::Event event;
                while (game.pollEvent(event))
                {
                    // close event trigger the window to close
                    if (event.type == sf::Event::Closed)
                        game.close();
                }
                game.clear();
                game.draw(gameOver);
                game.display();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                {
                    game.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                {
                    //need a way to reset the game loop here
                }

            }


        }


        //check whether player move up
        if (playerPos.iniY < playerPos.iniH)
        {
            for (int i = 0; i < 10; i++)
            {
                playerPos.iniY = playerPos.iniH;
                platform[i].y = platform[i].y - pos.dy;
                if (platform[i].y > 596)
                {
                    platform[i].y = 0;
                    platform[i].x = rand() % 689;
                }
            }
        }

        //check whether hit the plat
        for (int i = 0; i < 10; i++)
        {
            if (platform[i].x < (playerPos.iniX + 50) && (playerPos.iniX + 20) < (platform[i].x + 68)
                && (playerPos.iniY + 70) > platform[i].y && (playerPos.iniY + 70) < (platform[i].y + 14) && pos.dy > 0)
            {
                pos.dy = -10;
            }


        }


        // Reset Position of player
        player.setPosition(playerPos.iniX, playerPos.iniY);

        //// Reset locations of sprites
        game.draw(background);
        game.draw(player);
        for (int i = 0; i < 10; i++)
        {
            plat.setPosition(platform[i].x, platform[i].y);

            game.draw(plat);

        }




        game.display();
    }
}


#endif // !GAME_H




