#include "GameBoard.h"

//default constructor
GameBoard::GameBoard()
{
	score = 0;
}

bool GameBoard::isGameOver()
{
	bool gameOver = false;

	if (gameArray[4][16].active == false && gameArray[4][16].color != 'x')
	{
		gameOver = true;
	}

	return gameOver;
}