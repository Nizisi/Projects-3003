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

// larning drawing texture now.
int main()
{
    // a class to store the texture I need for the game in OOP rewrite
    // fields: texture- background, player, platform
    // function: use the picture I draw as texture
    //class Texture
    //{
    //};



    /*
    sf::RenderWindow. This class is derived from sf::Window, and inherits all its functions
    
    */
    sf::RenderWindow game(sf::VideoMode(800, 600), "Jump Game"); 
    game.setFramerateLimit(60); //to avoid visual tearing


    // a loop to show the window
    while (game.isOpen())
    {
        sf::Event event;
        while (game.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.close();
        }

        game.clear();
        game.display();
    }



    return 0;
}