#include <iostream>

#include "PacMan_Config.h"
#include "LabirinthElem.h"
#include "PacMan_Type.h"
#include "PacMan_Cmd.h"
#include "PacMan_BasicGame.h"


using namespace std;


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
		int next_x = p.X;
		int next_y = p.Y;
		PacmanDir next_d;
		switch (cmd) {
		case Quit:cout << "Grazie di aver giocato con me, alla prossima!" << endl;
			return 0;
		case Unknown: throw "unexpected command";
		case Go_E:
		case Go_W:
		case Go_S:
		case Go_N: next_d = cmd2dir(cmd);;
			break;
		default:throw "not a command!";
		}
		if (!make_move(p,next_d,maze))
			cout << "Mossa impossibile: non puoi passare attraverso i muri!"<<endl;
	}
	while (true);
}
