#ifndef _PACMAN_CMD_H_
#define _PACMAN_CMD_H_
enum Command { Go_N, Go_S, Go_W, Go_E, Quit, Unknown };
Command char2command(const char c);
Command get_command();
#endif
