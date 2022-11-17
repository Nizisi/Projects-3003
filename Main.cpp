
/** @file Main.cpp

 *  @brief main program for jumping game

 *  This main program contain the main game loop for the jumping game, also contains setting
 * for the display window , frame rate, and random generator base on time

 *

 *  @author  Jie Zhou
 * class : COP 3003 CRN 80602

 *  @bug No known bugs.

 */

//LO5.OOP inheritance is  the reuse of implementations.Subtyping is for the compatibility of interfaces. 
//LO4:compare the procedural/functional approach and the object-oriented approach, 
//OOP gives me more possibility to play with each parts of the program, and organize different class


#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "visual.h"
#include "Position.h"
#include <SFML/Graphics.hpp>


int main()
{

	//generate random based on time
	srand(time(0));

	//sf::RenderWindow. This class is derived from sf::Window, and inherits all its functions
	sf::RenderWindow game(sf::VideoMode(800, 600), "Space Jump");
	game.setFramerateLimit(60); //to avoid visual tearing

	Visual visual;
	playerLoc playerLoc;


	visual.setUP();//LO1a

	//// Localize all platforms randomly
	platLoc platform[20];
	platform->algorithm(platform);


	/** @brief major game loop
	*/
	while (game.isOpen())
	{
		/** @brief following is to check the event before any display
		*/
		sf::Event event;
		while (game.pollEvent(event))
		{
			// close event trigger the window to close
			if (event.type == sf::Event::Closed)
				game.close();
		}


		playerLoc.moveRightCheck();

		playerLoc.moveLeftCheck();

		playerLoc.algorithm();      //LO1a

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

		// above is the hit check and the camera, main game function end above


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
	}


	return 0;
}



