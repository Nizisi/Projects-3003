
/** @file platMath.h

 *  @brief store the math function for platform spawn


 *  @author  Jie Zhou
 * class : COP 3003 CRN 80602

 *  @bug No known bugs.

 */


#include "Position.h"
#ifndef PLATMATH_H
#define PLATMATH_H

 /** @brief check whether player move up and move the camera up
		 */

void collicheck(playerLoc playerLoc, platLoc platform[]) {

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
#endif 

