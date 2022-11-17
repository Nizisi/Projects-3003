
/** @file platMath.h

 *  @brief store the math function for platform spawn


 *  @author  Jie Zhou
 * class : COP 3003 CRN 80602

 *  @bug No known bugs.

 */


#include "Position.h"
#ifndef PLATMATH_H
#define PLATMATH_H

 /** @brief make array for a list of 20 platforms

platLoc platform[20];
*/

/** @brief Localize all platforms randomly with limitation in the window

void randomLocPlat()
{
	for (int i = 0; i < 20; i++)
	{
		/** @brief avoid plat generate on the wall
		
		platform[i].x = rand() % 500 + 129;
		platform[i].y = rand() % 596;
	}
}
*/

#endif 

