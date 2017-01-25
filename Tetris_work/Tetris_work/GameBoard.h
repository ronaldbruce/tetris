#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Block.h"

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>

#define DOWN 1
#define LEFT 2
#define RIGHT 3


class GameBoard
{
public:
	
	GameBoard();

	bool isGameOver();

	Block gameArray[10][18];
	int score;


};

#endif