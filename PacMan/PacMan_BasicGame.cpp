#include <ostream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


#include "LabirinthElem.h"
#include "PacMan_Cmd.h"
#include "PacMan_BasicGame.h"
#include "PacMan_Type.h"

using namespace std;

void init_maze(string config_file_name, Labirinth_Elems mm[SIZE][SIZE]) {
	ifstream cfgfile;
	cfgfile.open(config_file_name);
	if (!cfgfile)
		throw "file not found: missing " + config_file_name;

	for (int y = 0; y<SIZE; ++y) {
		std::string line;
		if (!getline(cfgfile, line))
			line = "";
		std::istringstream line_stream(line);
		for (int x = 0; x < SIZE; ++x) {
			char c;
			if (line_stream >> c)
				mm[x][y] = char2lab_elem(c);
			else
				mm[x][y] = Labirinth_Elems::empty;//missing input is integrated by empty spaces
		}
	}
	cfgfile.close();
}

void set_pacman(PacMan& pac_man, int x, int y, PacmanDir d) {
	pac_man.X = x;
	pac_man.Y = y;
	pac_man.direction = d;
}

void init(string config_file_name, Labirinth_Elems M[SIZE][SIZE], PacMan& pac_man) {
	init_maze(config_file_name, M);
	set_pacman(pac_man, 0, 0, South);
}

void display_wall_line() {
	for (int x = -1; x <= SIZE; x++)
		cout << WALL_C;
	cout << endl;
}
void display(Labirinth_Elems m[SIZE][SIZE], PacMan pac_man)
{
	cout << endl << endl;
	display_wall_line();
	for (int y = 0; y < SIZE; ++y) {
		cout << WALL_C;
		for (int x = 0; x < SIZE; ++x) {
			if (y == pac_man.Y&&x == pac_man.X)
				cout << PacmanDir2char(pac_man.direction);
			else
				cout << lab_elem2char(m[x][y]);
		}
		std::cout << WALL_C << std::endl;
	}
	display_wall_line();
}

PacmanDir cmd2dir(Command c) {
	switch (c) {
	case Quit:
	case Unknown: throw "unexpected command";
	case Go_E:return East;
	case Go_W:return West;
	case Go_S:return South;
	case Go_N:return North;
	default:throw "not a command!";
	}
}

bool make_move(PacMan& pac_man, Command c, Labirinth_Elems M[SIZE][SIZE]) {
	int x = pac_man.X;
	int y = pac_man.Y;
	switch (c) {
	case Quit:
	case Unknown: throw "unexpected command";
	case Go_E: ++x;
		break;
	case Go_W: --x;
		break;
	case Go_S: ++y;
		break;
	case Go_N: --y;
		break;
	default: throw "not a command!";
	}
	if (0 > x || SIZE <= x || 0 > y || SIZE <= y)
		return false;
	if (wall == M[x][y])
		return false;
	set_pacman(pac_man, x, y, cmd2dir(c));
	return true;
}