/*
* Name : Jie Zhou
* class : COP 3003 CRN 80602
* 
*using sfml instead of game engine
* write in straight forward first, then oop rewrite base on it
*comment to break every step that I done for OOP rewrite
*/

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Position.h"
#include "texture.h"


int main()
{

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

        platform[i].x = rand() % 500 + 129; // avoid plat generate on the wall
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
        //I set the jump velocity at this rate because random generate platform sometimes make the player 
        //impossible to survive, but at this velocity can probably ensure  player to survive 
        pos.dy += 0.1; 
        playerPos.iniY += pos.dy;

        // player died
        if (playerPos.iniY > 520)
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
                platform[i].y = platform[i].y - pos.dy;// for the platform to go down when player go up
                if (platform[i].y > 596)
                {
                    platform[i].y = 0; //new plat will appear at the top of screen
                    platform[i].x = rand() % 500 + 129;
                }
            }
        }

        //check whether hit the plat
        for (int i = 0; i < 10; i++)
        {
            if ((playerPos.iniY + 75) > platform[i].y && (playerPos.iniY + 75) < (platform[i].y + 15) && pos.dy > 0)
            {
                if (platform[i].x < (playerPos.iniX + 60) && (playerPos.iniX + 15) < (platform[i].x + 60))
                {
                    pos.dy = -10;
                }
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


    return 0;
}