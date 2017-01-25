#include "Z_Piece.h"

//default construcor
//takes in a color for modifying the color upon creation
//the inital coordinates will be specefic to each piece and are the starting coordinates of said piece
ZPiece::ZPiece(char color)
{
	block1.cordX = 4;
	block1.cordY = 16;
	block2.cordX = 3;
	block2.cordY = 16;
	block3.cordX = 4;
	block3.cordY = 15;
	block4.cordX = 5;
	block4.cordY = 15;

	block1.color = color;
	block2.color = color;
	block3.color = color;
	block4.color = color;

	block1.active = true;
	block2.active = true;
	block3.active = true;
	block4.active = true;

}

//places the piece in the gameArray at its initial coordinates
void ZPiece::spawnPiece(GameBoard &gameArray)
{
	gameArray.gameArray[block1.cordX][block1.cordY] = block1;
	gameArray.gameArray[block2.cordX][block2.cordY] = block2;
	gameArray.gameArray[block3.cordX][block3.cordY] = block3;
	gameArray.gameArray[block4.cordX][block4.cordY] = block4;

}
//resets the current piece by calling the default constructor on itself
void ZPiece::resetPiece(char color)
{
	*this = ZPiece(color);
}

//moves the piece left right or down depending on input. This function overides the base classes.
//It first checks collision in that direction and if not collision, executes move statements. 
//for the square the blocks are
//1 2
//3 4
//each move function will be slightly different per piece as the order depending on direction that the blocks are modified matters
//for instance: to move left, 1 must be updated before 2 or else 2 will overwrite 1 and cause it to be a single block instead of two
void ZPiece::move(GameBoard &gameArray, int direction, bool &placed, int stage)
{
	if (stage == 1 || stage == 3)
	{
		switch (direction) {
		case DOWN:
		{
			if (!isCollision(gameArray, DOWN, placed))
			{
				//block 4
				gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block4.cordX][block4.cordY - 1] = block4; //sets next location equal to block4
				block4.cordY--;

				//block 2
				gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block2.cordX][block2.cordY - 1] = block2; //sets next location equal to block2
				block2.cordY--;


				//block 3
				gameArray.gameArray[block3.cordX][block3.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block3.cordX][block3.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block3.cordX][block3.cordY - 1] = block3; //sets next location equal to block3
				block3.cordY--;



				//block 1
				gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block1.cordX][block1.cordY - 1] = block1; //sets next location equal to block1
				block1.cordY--;


			}
			break;
		case LEFT:
		{
			if (!isCollision(gameArray, LEFT, placed))
			{


				//block 2
				gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block2.cordX - 1][block2.cordY] = block2; //sets next location equal to block2
				block2.cordX--;

				//block 3
				gameArray.gameArray[block3.cordX][block3.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block3.cordX][block3.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block3.cordX - 1][block3.cordY] = block3; //sets next location equal to block3
				block3.cordX--;


				//block 1
				gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block1.cordX - 1][block1.cordY] = block1; //sets next location equal to block1
				block1.cordX--;


				//block 4
				gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block4.cordX - 1][block4.cordY] = block4; //sets next location equal to block4
				block4.cordX--;



			}
			break;
		}
		case RIGHT:
		{
			if (!isCollision(gameArray, RIGHT, placed))
			{

				//block 4
				gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block4.cordX + 1][block4.cordY] = block4; //sets next location equal to block4
				block4.cordX++;



				//block 1
				gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block1.cordX + 1][block1.cordY] = block1; //sets next location equal to block1
				block1.cordX++;

				//block 2
				gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block2.cordX + 1][block2.cordY] = block2; //sets next location equal to block2
				block2.cordX++;


				//block 3
				gameArray.gameArray[block3.cordX][block3.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block3.cordX][block3.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block3.cordX + 1][block3.cordY] = block3; //sets next location equal to block3
				block3.cordX++;
			}
		}
		}
		}
	}

	if (stage == 2 || stage == 4)
	{
		switch (direction) {
		case DOWN:
		{
			if (!isCollision(gameArray, DOWN, placed))
			{
				//block 2
				gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block2.cordX][block2.cordY - 1] = block2; //sets next location equal to block2
				block2.cordY--;


				//block 3
				gameArray.gameArray[block3.cordX][block3.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block3.cordX][block3.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block3.cordX][block3.cordY - 1] = block3; //sets next location equal to block3
				block3.cordY--;



				//block 1
				gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block1.cordX][block1.cordY - 1] = block1; //sets next location equal to block1
				block1.cordY--;

				//block 4
				gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block4.cordX][block4.cordY - 1] = block4; //sets next location equal to block4
				block4.cordY--;
			}
			break;
		case LEFT:
		{
			if (!isCollision(gameArray, LEFT, placed))
			{


				//block 2
				gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block2.cordX - 1][block2.cordY] = block2; //sets next location equal to block2
				block2.cordX--;
				//block 1
				gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block1.cordX - 1][block1.cordY] = block1; //sets next location equal to block1
				block1.cordX--;

				//block 3
				gameArray.gameArray[block3.cordX][block3.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block3.cordX][block3.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block3.cordX - 1][block3.cordY] = block3; //sets next location equal to block3
				block3.cordX--;




				//block 4
				gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block4.cordX - 1][block4.cordY] = block4; //sets next location equal to block4
				block4.cordX--;



			}
			break;
		}
		case RIGHT:
		{
			if (!isCollision(gameArray, RIGHT, placed))
			{

				//block 4
				gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block4.cordX + 1][block4.cordY] = block4; //sets next location equal to block4
				block4.cordX++;



				//block 3
				gameArray.gameArray[block3.cordX][block3.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block3.cordX][block3.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block3.cordX + 1][block3.cordY] = block3; //sets next location equal to block3
				block3.cordX++;

				//block 1
				gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block1.cordX + 1][block1.cordY] = block1; //sets next location equal to block1
				block1.cordX++;

				//block 2
				gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
				gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
				gameArray.gameArray[block2.cordX + 1][block2.cordY] = block2; //sets next location equal to block2
				block2.cordX++;

			}
		}
		}
		}
	}


}

void ZPiece::rotate(GameBoard &gameArray, int stage, bool &placed)
{
	if (stage == 1 || stage == 3)
	{
		if (!isCollision(gameArray, DOWN, placed))
		{
			//block 2
			gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
			gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
			gameArray.gameArray[block2.cordX][block2.cordY + 2] = block2; //sets next location equal to block3
			block2.cordY += 2;
			//block 4
			gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
			gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
			gameArray.gameArray[block4.cordX + 1][block4.cordY - 1] = block4; //sets next location equal to block4
			block4.cordX += 1;
			block4.cordY -= 1;
			//block 1
			gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
			gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
			gameArray.gameArray[block1.cordX + 1][block1.cordY + 1] = block1; //sets next location equal to block1
			block1.cordX += 1;
			block1.cordY += 1;


		}
	}

	else if (stage == 2 || stage == 4)
	{
		if (!isCollision(gameArray, DOWN, placed))
		{
			//block 1
			gameArray.gameArray[block1.cordX][block1.cordY].active = false; //sets previous location to non active
			gameArray.gameArray[block1.cordX][block1.cordY].color = 'x'; //sets previous location to background
			gameArray.gameArray[block1.cordX - 1][block1.cordY - 1] = block1; //sets next location equal to block1
			block1.cordX -= 1;
			block1.cordY -= 1;

			//block 2
			gameArray.gameArray[block2.cordX][block2.cordY].active = false; //sets previous location to non active
			gameArray.gameArray[block2.cordX][block2.cordY].color = 'x'; //sets previous location to background
			gameArray.gameArray[block2.cordX][block2.cordY - 2] = block2; //sets next location equal to block3
			block2.cordY -= 2;

			//block 4
			gameArray.gameArray[block4.cordX][block4.cordY].active = false; //sets previous location to non active
			gameArray.gameArray[block4.cordX][block4.cordY].color = 'x'; //sets previous location to background
			gameArray.gameArray[block4.cordX - 1][block4.cordY + 1] = block4; //sets next location equal to block4
			block4.cordX -= 1;
			block4.cordY += 1;
		}
	}
}