#include <iostream>
using namespace std;
enum Labirinth_Elems { wall, empty, dot};
enum PacmanDir{North, South, West, Est};
struct PacMan
{
	PacmanDir direction;
	int W;
	int Y;
};

int main()
{
	const int SIZE = 15;
	Labirinth_Elems maze[SIZE];
	cout << "PAC MAN";
}