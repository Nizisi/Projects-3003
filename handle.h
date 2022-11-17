#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "visual.h"
#include "Position.h"
#include <SFML/Graphics.hpp>

/** @file handle.h

 *  @brief purpose: handle event in the main game loop


 *  @author  Jie Zhou


 */


#ifndef HANDLE_H
#define HANDLE_H

class handle
{
public:
	void checkOver(sf::RenderWindow& game, playerLoc playerLoc, Visual visual);
};

 //pass sf::RenderWindow &game as reference bacause it can not be copy to use
void handle::checkOver(sf::RenderWindow& game, playerLoc playerLoc, Visual visual) {
	/** @brief if player died, create a loop to draw a gameover screen
		*/
	if (playerLoc.locY > 520)
	{


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
			game.draw(visual.spGameOver);
			game.display();


			//user can press x to close the game
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				game.close();
			}


		}


	}
}


#endif // !HEADER_H

