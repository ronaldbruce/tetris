#pragma once
#ifndef PIECE_H
#define PIECE_H

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Block.h"
#include "GameBoard.h"


class Piece
{
public:

	Piece();

	virtual void move(GameBoard &gameArray, int direction, bool &placed, int stage) = 0;

	virtual void rotate(GameBoard &gameArray, int stage, bool &placed) = 0;

	virtual void spawnPiece(GameBoard &gameArray) = 0;

	virtual void resetPiece(char color) = 0;

	bool isCollision(GameBoard &gameArray, int direction, bool &placed);

	Block block1, block2, block3, block4;

private:

	sf::SoundBuffer buffer;
	sf::Sound Place;

};

#endif