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
    // to use sfml class in my class, inheritance needed?


    // a class to store the texture I need for the game in OOP rewrite
    // fields: texture- background, player, platform
    // function: use the picture I draw as texture
    //class Texture
    //{
    //};

    // class position
    // fields: x and y coordinates for position.



    /*
    sf::RenderWindow. This class is derived from sf::Window, and inherits all its functions
    
    */
    sf::RenderWindow game(sf::VideoMode(800, 600), "Jump Game"); 
    game.setFramerateLimit(60); //to avoid visual tearing


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

        game.clear();
        game.display();
    }



    return 0;
}
