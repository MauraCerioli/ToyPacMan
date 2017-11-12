
#include "PacMan_Type.h"

char PacmanDir2char(PacmanDir d) {
	switch (d) {
	case South: return '^';
	case East:return '<';
	case West:return '>';
	case North:return 'v';
	default: throw "not a valid direction";
	}
}
