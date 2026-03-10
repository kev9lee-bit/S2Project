#include "ConsoleUI.h"
#include <iostream>
#include <string>
using namespace std;

void ConsoleUI::run()
{
	cout << "Chess Teacher\n";
	while (true) {
		cout << "menu> ";
		string cmd;
		cin >> cmd;
		if (cmd == "quit") {
			break;
		}
		else if (cmd == "board") {
			cout << board_.render();
		}
		else {
			cout << "Unknown command: " << cmd << endl;
		}
 
	}
}