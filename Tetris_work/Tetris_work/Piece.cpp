#include "Piece.h"
Piece::Piece()
{
	buffer.loadFromFile("Thud1.wav");
	Place.setBuffer(buffer);
	
}
//checks for collisions based on the current pieces coordinates and inactive blocks on the board
//based on direction. returns collision = true if will collide, placed returns true if on top of another block
bool Piece::isCollision(GameBoard &gameArray, int direction, bool &placed)
{
	bool collision = false;

	switch (direction) {
	case DOWN:
	{
		if (gameArray.gameArray[block1.cordX][block1.cordY - 1].active == false &&
			gameArray.gameArray[block1.cordX][block1.cordY - 1].color != 'x')
		{
			collision = true;
			placed = true;
		}
		if (block1.cordY == 0)
		{
			collision = true;
			placed = true;
		}

		if (gameArray.gameArray[block2.cordX][block2.cordY - 1].active == false &&
			gameArray.gameArray[block2.cordX][block2.cordY - 1].color != 'x')
		{
			collision = true;
			placed = true;
		}
		if (block2.cordY == 0)
		{
			collision = true;
			placed = true;
		}

		if (gameArray.gameArray[block3.cordX][block3.cordY - 1].active == false &&
			gameArray.gameArray[block3.cordX][block3.cordY - 1].color != 'x')
		{
			collision = true;
			placed = true;
		}
		if (block3.cordY == 0)
		{
			collision = true;
			placed = true;
		}

		if (gameArray.gameArray[block4.cordX][block4.cordY - 1].active == false &&
			gameArray.gameArray[block4.cordX][block4.cordY - 1].color != 'x')
		{
			collision = true;
			placed = true;
		}
		if (block4.cordY == 0)
		{
			collision = true;
			placed = true;
		}
		break;

	}
	case LEFT:
	{
		if (gameArray.gameArray[block1.cordX - 1][block1.cordY].active == false &&
			gameArray.gameArray[block1.cordX - 1][block1.cordY].color != 'x')
		{
			collision = true;
		}
		if (block1.cordX - 1 <= -1)
		{
			collision = true;
		}
		if (gameArray.gameArray[block2.cordX - 1][block2.cordY].active == false &&
			gameArray.gameArray[block2.cordX - 1][block2.cordY].color != 'x')
		{
			collision = true;
		}
		if (block2.cordX - 1 <= -1)
		{
			collision = true;
		}
		if (gameArray.gameArray[block3.cordX - 1][block3.cordY].active == false &&
			gameArray.gameArray[block3.cordX - 1][block3.cordY].color != 'x')
		{
			collision = true;
		}
		if (block3.cordX - 1 <= -1)
		{
			collision = true;
		}
		if (gameArray.gameArray[block4.cordX - 1][block4.cordY].active == false &&
			gameArray.gameArray[block4.cordX - 1][block4.cordY].color != 'x')
		{
			collision = true;
		}
		if (block4.cordX - 1 <= -1)
		{
			collision = true;
		}
		break;
	}
	case RIGHT:

		if (gameArray.gameArray[block1.cordX + 1][block1.cordY].active == false &&
			gameArray.gameArray[block1.cordX + 1][block1.cordY].color != 'x')
		{
			collision = true;
		}
		if (block1.cordX + 1 >= 10)
		{
			collision = true;
		}
		if (gameArray.gameArray[block2.cordX + 1][block2.cordY].active == false &&
			gameArray.gameArray[block2.cordX + 1][block2.cordY].color != 'x')
		{
			collision = true;
		}
		if (block2.cordX + 1 >= 10)
		{
			collision = true;
		}
		if (gameArray.gameArray[block3.cordX + 1][block3.cordY].active == false &&
			gameArray.gameArray[block3.cordX + 1][block3.cordY].color != 'x')
		{
			collision = true;
		}
		if (block3.cordX + 1 >= 10)
		{
			collision = true;
		}
		if (gameArray.gameArray[block4.cordX + 1][block4.cordY].active == false &&
			gameArray.gameArray[block4.cordX + 1][block4.cordY].color != 'x')
		{
			collision = true;
		}
		if (block4.cordX  + 1 >= 10)
		{
			collision = true;
		}
		break;


	}

	if (placed == true)
	{
		Place.play();
	}

	return collision;
}

