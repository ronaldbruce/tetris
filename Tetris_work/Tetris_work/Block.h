#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include <SFML\Graphics.hpp>
#include <iostream>

class Block
{
public:
	//constructor
	Block(int newCordX = 0, int newCordY = 0);

	bool active;
	int cordX;
	int cordY;
	char color;
	
	//overloaded assignment operator
	Block & operator = (const Block &rhs);

};
#endif