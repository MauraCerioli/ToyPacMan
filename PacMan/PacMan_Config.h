#ifndef _PACMAN_CONFIG_H_
#define _PACMAN_CONFIG_H_
#include <string>
const int SIZE = 15;//Dimensione del labirinto (maze); non comprende i muri perimetrali
const std::string MAZE_CONFIG_NAME = "maze.cfg";//nome del file con i dati iniziali del labirinto
// Caratteri usati per stampare il labirinto a video
const char EMPTY_C = ' ';//spazio vuoto
const char WALL_C = '#';//muro
const char DOT_C = '.';//puntino

#endif


