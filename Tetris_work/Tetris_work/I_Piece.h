#pragma once
#ifndef I_PIECE_H
#define I_PIECE_H
#include "Piece.h"


#define DOWN 1
#define LEFT 2
#define RIGHT 3



class IPiece : public Piece
{
public:
	//constructor
	IPiece(char color = 'x');

	//void rotate(int direction);
	void move(GameBoard &gameArray, int direction, bool &placed, int stage);

	void rotate(GameBoard &gameArray, int stage, bool &placed);

	//spawns the piece on the gameboard
	void spawnPiece(GameBoard &gameArray);

	//resets the values of this piece (cordX, cordY, active, color)
	void resetPiece(char color);


};
#endif