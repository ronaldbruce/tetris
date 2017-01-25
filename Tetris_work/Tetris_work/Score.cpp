#include "Score.h"
#include <iostream>

void checkline(GameBoard &game)
{
	int y, x;

	for (y = 0; y < 18; y++)
	{
		int fullcube = 0;
		int fullline = -1;
		for (x = 0; x < 10; x++)
		{
			if (game.gameArray[x][y].color != 'x')
			{
				fullcube += 1;
			}
		}
		if (fullcube == 10)
		{
			for (x = 0; x < 10; x++)
			{
				game.gameArray[x][fullline].color = 'x';

			}
			for (fullline = y; fullline < 17; fullline++)
			{
				for (x = 0; x < 10; x++)
				{
					game.gameArray[x][fullline].color = game.gameArray[x][fullline + 1].color;
					game.gameArray[x][fullline + 1].color = 'x';
				}
			}
			game.score++;
			y = -1;
		}
	}
}