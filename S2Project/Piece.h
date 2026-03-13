#pragma once
#include "Move.h"

class Board;

class Piece {
protected:
	bool white_;
public:
	Piece(bool w) : white_(w) {}
	// Pieces will be deleted through a pointer to Piece, so a virtual destructor to ensure that the correct destructor is called for each derived class
	virtual ~Piece() {}
	bool isWhite() const { return white_; }
	//Pure virtual function which must be implemented by derived classes to get the symbol of the piece
	virtual char symbol() const = 0;
    //Every piece MUST define its own movement rule
	virtual bool canMoveShape(const Board&, const Move& m) const = 0;
};