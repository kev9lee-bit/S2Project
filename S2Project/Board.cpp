#include <sstream>
#include "Board.h"

Board::Board()
{ //Initializing the grid to nullptr so that it cna be used to place pieces on the board
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			grid_[r][c] = nullptr;
		}
	}
	resetStart();
}
void Board::resetStart()
{ //Setting up the pieces on the board in their starting positions
	placePiece('r', 0, 0);
	placePiece('n', 0, 1);
	placePiece('b', 0, 2);
	placePiece('q', 0, 3);
	placePiece('k', 0, 4);
	placePiece('b', 0, 5);
	placePiece('n', 0, 6);
	placePiece('r', 0, 7);
	for (int c = 0; c < 8; c++) {
		placePiece('p', 1, c);
	}
	placePiece('R', 7, 0);
	placePiece('N', 7, 1);
	placePiece('B', 7, 2);
	placePiece('Q', 7, 3);
	placePiece('K', 7, 4);
	placePiece('B', 7, 5);
	placePiece('N', 7, 6);
	placePiece('R', 7, 7);
	for (int c = 0; c < 8; c++) {
		placePiece('P', 6, c);
	}

void Board::placePiece(char symbol, int r, int c)
{  //Setting up pieces on the board
	delete grid_[r][c];
	bool white = isupper(symbol);
	//Type of piece
	char type = toupper(symbol);
	//Pieces created in heap memory and store pointer on the grid
	if (type == 'K') {
		grid_[r][c] = new King(white);
	}
	else if (type == 'Q') {
		grid_[r][c] = new Queen(white);
	}
	else if (type == 'R') {
		grid_[r][c] = new Rook(white);
	}
	else if (type == 'B') {
		grid_[r][c] = new Bishop(white);
	}
	else if (type == 'N') {
		grid_[r][c] = new Knight(white);
	}
	else if (type == 'P') {
		grid_[r][c] = new Pawn(white);
	}

}

std::string Board::render() const
{

	std::ostringstream out;
	out << "  a b c d e f g h\n";
	for (int i = 0; i < 8; i++) {
		out << 8 - i << " . . . . . . . .\n";
	}
	out << " a b c d e f g h\n";
	return out.str();
}