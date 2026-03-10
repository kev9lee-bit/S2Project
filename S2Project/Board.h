#pragma once
#include <string>

class Piece;
class Board
{
private:
	Piece* grid_[8][8];

public:
	Board();
	std::string render() const;
	//Function to place a piece on the board, takes in the symbol of the piece and the row and column to place it at
	void placePiece(char symbol, int r, int c);
	void resetStart();
	

};