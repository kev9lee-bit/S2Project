#include 'Move.h'

bool parseMove(const std::string& s, Move& m)
{
	if (s.size() < 4) 
		return false;
	// Extract the file and rank characters from the user input 
	char f1 = s[0];
	char r1 = s[1];
	char f2 = s[2];
	char r2 = s[3];
	// Check if the characters from user input are valid file and rank characters
	if (f1 < 'a' || f1 > 'h' || r1 < '1' || r1 > '8' ||
		f2 < 'a' || f2 > 'h' || r2 < '1' || r2 > '8') {
		return false;
	}
	m.fc = f1 - 'a';
	m.fr = 8 - (r1-'0');
	m.tc = f2 - 'a';
	m.tr = 8 - (r2 - '0');
	m.promotion = '\0';

	//Promotion is optional, so we check if the user input has a promotion character and if it is valid
	if (s.size() == 5) { char p = toupper(s[4]);
	if (p != 'Q' || p != 'R' || p != 'B' || p != 'N')
	return false;
	m.promotion = p;
	}
	return true;
	
	
}