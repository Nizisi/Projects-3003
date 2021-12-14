
/** @file Position.h

 *  @brief store the class for controlling the position of the objects, including the moving based on user input


 *  @author  Jie Zhou
 * class : COP 3003 CRN 80602

 *  @bug No known bugs.

 */





#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#ifndef POSITION_H
#define POSITION_H


 /** @brief parent class for object location point
  */
class locPoint                  //LO1
{
public:
	int x{ 0 };
	int y{ 0 };

	/** @brief a function to store the algorithm for calculating the location
	* this functionality needs exist mainly in derived class, therefore, use virtual here for override.
	*/
	virtual void algorithm() {};
	//LO3. to calculate location point, an algorithm is necessary no matter who's location, therefore, I use dynamic dispatch here for possible extend in derived class
};

/** @brief player location class derived from location point class
 */

//LO2a. the public fields in locPoint are free to use in playerLoc class without restriction

class playerLoc :public locPoint    //LO2   
{
public:
	int locH = 200; // player location
	int locX = 100;
	int locY = 100;

	float dx = 0.0; // Velocity
	float dy = 0.0;


	/** @brief player location class derived from location point class
	*/
	void algorithm()
	{
		/** @brief algorithm for player's jumping velocity
		* 
		* I set the jump velocity at this rate because random generate platform sometimes make the player impossible to survive, but at this velocity can probably ensure  player to survive 
		*/
		dy += 0.1;
		locY += dy;
	}

	/** @brief check user keyboard input on moving right
	*/
	void moveRightCheck()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (locX < 625)             //set limitation so the player wont go through the wall
				locX += 4;
		}
	}

	/** @brief check user keyboard input on moving left
	*/
	void moveLeftCheck()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (locX > 100)
				locX -= 4;
		}

	}



};


/** @brief derived from location point , a location point for platform is probably necessary.
*/
class platLoc :public locPoint  //LO2
{
public:
	void algorithm() {};
};

#endif 
