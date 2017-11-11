#ifndef _LABIRINTH_H_
#define _LABIRINTH_H_
#include "PacMan_Config.h"

enum Labirinth_Elems { wall, empty, dot };
Labirinth_Elems char2lab_elem(char c);
char lab_elem2char(Labirinth_Elems e);
#endif
