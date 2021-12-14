/** @file visual.h

 *  @brief purpose: store the class for setting up texture and sprite for the game object.
 * texture is a image of the object, sprite is the object I want to have for the game


 *  @author  Jie Zhou
 * class : COP 3003 CRN 80602

 *  @bug No known bugs.

 */


#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

#ifndef VISUAL_H
#define VISUAL_H

 /** @brief a class that use for txture and sprite setup
 */

class Visual            //LO1
{


public:
	// only 3 texture needed in the game, for access and control the total mber, I use protected
	sf::Texture back;
	sf::Texture plat;
	sf::Texture player;
	sf::Texture gameOver;
	sf::Sprite spBack;
	sf::Sprite spPlat;
	sf::Sprite spPlayer;
	sf::Sprite spGameOver;
	void setUP();


};

/** @brief a function that load the file picture to the texture and set the texture for the sprite
*/
void Visual::setUP()
{
	back.loadFromFile("images/background02.png");
	plat.loadFromFile("images/plat.png");
	player.loadFromFile("images/player.png");
	gameOver.loadFromFile("images/gameOver.png");
	spBack.setTexture(back);
	spPlat.setTexture(plat);
	spPlayer.setTexture(player);
	spGameOver.setTexture(gameOver);
}


#endif 

