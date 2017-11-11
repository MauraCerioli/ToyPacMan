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
		case Go_E:++next_x;
			next_d = Est;
			break;
		case Go_W:--next_x;
			next_d = West;
			break;
		case Go_S:++next_y;
			next_d = South;
			break;
		case Go_N:--next_y;
			next_d = North;
			break;
		default:next_d=p.direction;//non dovrebbe mai succedere
		}
		if (!make_move(p,next_x,next_y,next_d,maze))
			cout << "Mossa impossibile: non puoi passare attraverso i muri!"<<endl;
	}
	while (true);
}
