#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// CONFIGURAZIONE DEL GIOCO
const int SIZE = 15;
const string MAZE_CONFIG_NAME = "maze.cfg";
// MAZE ELEMENTS
const char EMPTY_C = ' ';
const char WALL_C = '#';
const char DOT_C = '.';
// CONFIGURAZIONE DEL GIOCO



enum Labirinth_Elems { wall, empty, dot};
Labirinth_Elems char2lab_elem(char c) {
	switch (c) {
	case WALL_C:
		return  wall;
		break;
	case EMPTY_C:
		return Labirinth_Elems::empty;
		break;
	case DOT_C:
		return dot;
		break;
	default:return Labirinth_Elems::empty;
	}
}
char lab_elem2char(Labirinth_Elems e) {
	switch (e) {
	case wall:
		return  WALL_C;
		break;
	case Labirinth_Elems::empty:
		return EMPTY_C;
		break;
	case dot:
		return DOT_C;
		break;
	default:return EMPTY_C;
	}
}
enum PacmanDir{North, South, West, Est};
struct PacMan
{
	PacmanDir direction;
	int X;
	int Y;
};

char PacmanDir2char(PacmanDir d) {
	switch (d) {
	case South: return '^';
	case Est:return '<';
	case West:return '>';
	case North:return 'v';
	}
}

enum Command { Go_N,Go_S, Go_W, Go_E, Quit, Unknown};
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

/*TODO ECCEZIONI 
 *file_not_found
 *
 */
	void init_maze(string config_file_name, Labirinth_Elems mm[SIZE][SIZE]) {
		ifstream cfgfile;
		cfgfile.open(config_file_name);
		if (!cfgfile)
			throw "file not found: missing "+ config_file_name;

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

void set_pacman(PacMan& pac_man) {
	pac_man.X = 0;
	pac_man.Y = 0;
	pac_man.direction = South;
}

	void init(string config_file_name, Labirinth_Elems M[SIZE][SIZE],PacMan& pac_man) {
		init_maze(config_file_name, M);
		set_pacman(pac_man);
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
				if (y==pac_man.Y&&x==pac_man.X)
					cout << PacmanDir2char(pac_man.direction);
				else
					cout << lab_elem2char(m[x][y]);
			}
			cout << WALL_C << endl;
		}
		display_wall_line();
	}

	Command get_command() {
		char answer;
		Command read_cmd;
		do {
			cout << "che cosa vuoi fare?" << endl;
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
bool make_move(PacMan& pac_man,PacMan next,Labirinth_Elems M[SIZE][SIZE]) {
	bool res = wall != M[next.X][next.Y];
	if (res)
		pac_man = next;
	return res;
}
int main()
{
	Labirinth_Elems maze[SIZE][SIZE];
	PacMan p;
	cout << "PAC MAN";
	try {
		init(MAZE_CONFIG_NAME, maze, p);
	}
	catch (string& e) {
		cout << e;
		return -1;
	}
	Command cmd = Unknown;
	do {
		display(maze, p);
		cmd = get_command();
		PacMan next_p { p.direction,p.X,p.Y};
		switch (cmd) {
		case Quit:cout << "Grazie di aver giocato con me, alla prossima!" << endl;
			return 0;
		case Go_E:++p.X;
			p.direction = Est;
			break;
		case Go_W:--p.X;
			p.direction = West;
			break;
		case Go_S:++p.Y;
			p.direction = South;
			break;
		case Go_N:--p.Y;
			p.direction = North;
			break;
		}
		if (!make_move(p,next_p,maze))
			cout << "Mossa impossibile: non puoi passare attraverso i muri!"<<endl;
	}
	while (true);
	

}
