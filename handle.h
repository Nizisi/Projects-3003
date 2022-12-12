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
	void paint(sf::RenderWindow& game, playerLoc playerLoc, platLoc platform[],Visual visual)
	{
		/** @brief draw the sprite
		*
		* the order of the drawing matters
		*/

		game.draw(visual.spBack);


		visual.spPlayer.setPosition(playerLoc.locX, playerLoc.locY);// take the updated location, then draw
		game.draw(visual.spPlayer);

		for (int i = 0; i < 20; i++)
		{
			visual.spPlat.setPosition(platform[i].x, platform[i].y);// take the updated location, then draw

			game.draw(visual.spPlat);

		}


		//display
		game.display();
	};

	void cam_platspawn(playerLoc &playerLoc, platLoc platform[]) {
		/** @brief check whether player move up and move the camera up
		*/
		if (playerLoc.locY < playerLoc.locH)
		{
			for (int i = 0; i < 20; i++)
			{
				playerLoc.locY = playerLoc.locH;


				platform[i].y = platform[i].y - playerLoc.dy;// for the platform to go down when player go up


				if (platform[i].y > 596)
				{
					platform[i].x = rand() % 500 + 129;
					platform[i].y = 0; //new plat will appear at the top of screen

				}
			}
		}
	};

	void collicheck(playerLoc& playerLoc, platLoc platform[])
	{
		/** @brief check whether player jump on the platform
		*/
		for (int i = 0; i < 20; i++)
		{
			//first, check the location on Y for both platform and player (the height of each sprite with involved, but specific number is necessary to adjust)
			if ((playerLoc.locY + 75) > platform[i].y && (playerLoc.locY + 75) < (platform[i].y + 15))
			{

				// then check location on X for both object
				if (platform[i].x < (playerLoc.locX + 60) && (playerLoc.locX + 15) < (platform[i].x + 60))
				{
					//make sure the player is jump onto the plate with velocity check
					if (playerLoc.dy > 0)
					{
						playerLoc.dy = -10;
					}
				}
			}


		}
	}
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

