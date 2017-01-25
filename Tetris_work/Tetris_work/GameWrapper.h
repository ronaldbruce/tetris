#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Display.h"
#include "Square_Piece.h"
#include "I_Piece.h"
#include "J_Piece.h"
#include "L_Piece.h"
#include "S_Piece.h"
#include "T_Piece.h"
#include "Z_Piece.h"
#include "stdlib.h"
#include "Score.h"
#include "windows.h"

#define DOWN 1
#define LEFT 2
#define RIGHT 3

class GameWrapper
{
public:
	
	~GameWrapper();

	void runGame();

	Piece *& generatePiece();

	Piece *newPiece;

};