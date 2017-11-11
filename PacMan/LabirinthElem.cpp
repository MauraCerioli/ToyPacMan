#include "PacMan_Config.h"
#include "LabirinthElem.h"

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
	default: throw "not a valid labirinth element";
	}
}