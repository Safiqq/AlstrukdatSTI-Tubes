#ifndef __MAIN_H__
#define __MAIN_H__

#include "./ADT/array/array.h"
#include "./ADT/map/map.h"
#include "./ADT/mesinkarakter/mesinkarakter.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"
#include "./ADT/queueDS/queue.h"

void mainmenu();
void start(TabStr *games);
void load(char* namafile, TabStr *games);
void save(char* namafile, TabStr games);
void createGame(char *name, TabStr *games);
void listGame(TabStr games);
void deletegame(TabStr *games, Queue antriangames);
void queueGame( TabStr *games, Queue *antriangames);
void playGame(TabStr *games, Queue *antriangames);
void skipGame(Word skip, TabStr *games, Queue *antriangames);
void quit();
void help();
void commandLain();

#endif