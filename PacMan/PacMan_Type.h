#ifndef _PACMAN_TYPE_H_
#define _PACMAN_TYPE_H_

enum PacmanDir { North, South, West, Est };
struct PacMan
{
	PacmanDir direction;
	int X;
	int Y;
};

char PacmanDir2char(PacmanDir d);

#endif
