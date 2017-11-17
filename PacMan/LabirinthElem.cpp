#include "PacMan_Config.h"
#include "LabirinthElem.h"

Labirinth_Elems char2lab_elem(char c) {
	switch (c) {
	case WALL_C:
		return  wall;
	case EMPTY_C:
		return Labirinth_Elems::empty;
	case DOT_C:
		return dot;
	default:return Labirinth_Elems::empty;
	}
}
char lab_elem2char(Labirinth_Elems e) {
	switch (e) {
	case wall:
		return  WALL_C;
	case Labirinth_Elems::empty:
		return EMPTY_C;
	case dot:
		return DOT_C;
	default: throw "not a valid labirinth element";
	}
}