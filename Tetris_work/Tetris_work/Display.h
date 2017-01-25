#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include "Block.h"
#include <SFML\Graphics.hpp>
#include <iostream>

using sf::Color;

class Display
{
public:
	//all of these functions are independent of any other class, these will always function properly

	//traverses the array and displays the blocks according to their position and color value
	void translateArray(sf::RenderWindow &newWindow, Block gameArray[10][18]);

	//displays a black screen as the background and sets the "background" blocks
	void displayBackground(sf::RenderWindow &newWindow);

	//creates a block with the position specefied (converts from int to pixels) with the color given
	sf::RectangleShape createBlock(sf::Color newColor, int x, int y);
};
#endif


 