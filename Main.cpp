
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
#include "handle.h"
#include "platMath.h"
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

	handle handle;

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

		handle.checkOver(game,playerLoc,visual);


			

		handle.cam_platspawn(playerLoc, platform);

		handle.collicheck(playerLoc, platform);

		// above is the hit check and the camera, main game function end above


		/** @brief draw the sprite
		* 
		* the order of the drawing matters
		*/

		handle.paint(game, playerLoc, platform, visual);
	}


	return 0;
}



