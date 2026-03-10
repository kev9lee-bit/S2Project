#pragma once
#include <string>
struct Move
{
	int fr, fc;
	int tr, tc;
	char promotion;
};
bool parseMove(const std::string& s, Move& m);
