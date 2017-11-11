
#include "PacMan_Type.h"

char PacmanDir2char(PacmanDir d) {
	switch (d) {
	case South: return '^';
	case Est:return '<';
	case West:return '>';
	case North:return 'v';
	}
}
