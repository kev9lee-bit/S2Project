#pragma once
#include "Piece.h"
#include <cmath>

class Board;

class King : public Piece { 
public:
	King(bool w) : Piece(w) {} 
char symbol() const override {
	//Return the symbol for the king piece, which is 'K' for white and 'k' for black
	return white_ ? 'K' : 'k';
}
bool canMoveShape(const Board&, const Move& m) const override {
	//The king can move one square in any direction, so we check if the move is within one square of the starting position
	int dr = abs(m.tr - m.fr);
	int dc = abs(m.tc - m.fc);
	return (dr <= 1 && dc <= 1);
}

};
class Knight : public Piece {
	public:
	Knight(bool w) : Piece(w) {}
	char symbol() const override {
		return white_ ? 'N' : 'n';
	}
	bool canMoveShape(const Board&, const Move& m) const override {
		int dr = abs(m.tr - m.fr);
		int dc = abs(m.tc - m.fc);
		//The knight moves in an L shape, so we check if the move is two squares in one direction and one square in the other direction
		return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
	}
};
class Bishop : public Piece {
	public:
	Bishop(bool w) : Piece(w) {}
	char symbol() const override {
		return white_ ? 'B' : 'b';
	}
	bool canMoveShape(const Board&, const Move& m) const override {
		int dr = abs(m.tr - m.fr);
		int dc = abs(m.tc - m.fc);
		//The bishop moves diagonally, so we check if the move is the same number of squares in both directions
		return dr == dc;
	}
};
class Rook : public Piece {
	public:
	Rook(bool w) : Piece(w) {}
	char symbol() const override {
		return white_ ? 'R' : 'r';
	}
	bool canMoveShape(const Board&, const Move& m) const override {
		int dr = abs(m.tr - m.fr);
		int dc = abs(m.tc - m.fc);
		//The rook moves horizontally or vertically, so we check if the move is in the same row or the same column
		return (dr == 0 || dc == 0);
	}
};
class Queen : public Piece {
	public:
	Queen(bool w) : Piece(w) {}
	char symbol() const override {
		return white_ ? 'Q' : 'q';
	}
	bool canMoveShape(const Board&, const Move& m) const override {
		int dr = abs(m.tr - m.fr);
		int dc = abs(m.tc - m.fc);
		//The queen moves horizontally, vertically, or diagonally, so we check if the move is in the same row, the same column, or the same number of squares in both directions
		return (dr == 0 || dc == 0) || (dr == dc);
	}
};
class Pawn : public Piece {
	public:
	Pawn(bool w) : Piece(w) {}
	char symbol() const override {
		return white_ ? 'P' : 'p';
	}
	bool canMoveShape(const Board&, const Move& m) const override {
		int dr = m.tr - m.fr;
		int dc = abs(m.tc - m.fc);
		//The pawn moves forward one square, so we check if the move is in the same column and one square forward
		if (white_) {//for white pawns, its negative because they move up the board, while for black pawns its positive because they move down the board
			return (dc == 0 && dr == -1) || (dc == 0 && dr == -2) || (dc == 1 && dr == -1); //capture
		}
		else {
			return (dc == 0 && dr == 1) || (dc == 0 && dr == 2) || (dc == 1 && dr == 1);
		}
	}
};