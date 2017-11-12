#ifndef _PACMAN_BASIC_H_
#define _PACMAN_BASIC_H_
#include "PacMan_Type.h"
#include "PacMan_Config.h"
void init_maze(std::string config_file_name, Labirinth_Elems mm[SIZE][SIZE]);



void set_pacman(PacMan& pac_man, int x, int y, PacmanDir d);

void init(std::string config_file_name, Labirinth_Elems M[SIZE][SIZE], PacMan& pac_man);

void display(Labirinth_Elems m[SIZE][SIZE], PacMan pac_man);

PacmanDir cmd2dir(Command c);

bool make_move(PacMan& pac_man, PacmanDir d, Labirinth_Elems M[SIZE][SIZE]);

#endif
