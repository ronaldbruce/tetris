#include "Block.h"

//default constructor that allows for setting the coordinates specefically. I have not used this feature yet
Block::Block(int newCordX, int newCordY)
{
	active = false;
	cordX = newCordX;
	cordY = newCordY;
	color = 'x';
}

//overloaded equality operator allows for copying one element in array to another
Block & Block::operator = (const Block &rhs)
{
	active = rhs.active;
	cordX = rhs.cordX;
	cordY = rhs.cordY;
	color = rhs.color;

	return *this;
}