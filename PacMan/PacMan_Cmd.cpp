#include "PacMan_Cmd.h"
#include <iostream>
using namespace std;
Command char2command(const char c) {
	switch (c) {
	case 'w':
	case'W': return Go_N;
		break;
	case 'a':
	case'A': return Go_W; break;
	case 'd':
	case'D': return Go_E; break;
	case 's':
	case'S': return Go_S; break;
	case 'q':
	case'Q': return Quit; break;
	default: return Unknown;
	}
}
Command get_command() {
	char answer;
	Command read_cmd;
	do {
		std::cout << "che cosa vuoi fare?" << endl;
		cout << "\tW per nord" << endl;
		cout << "\tS per sud" << endl;
		cout << "\tA per ovest" << endl;
		cout << "\tD per est" << endl;
		cout << "\tQ per smettere di giocare" << endl;
		cin >> answer;
		read_cmd = char2command(answer);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (read_cmd == Unknown);
	return read_cmd;
}