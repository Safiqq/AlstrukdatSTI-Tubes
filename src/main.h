#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include "./ADT/array/array.h"
#include "./ADT/mapDS/map.h"
#include "./ADT/mesinkarakter/mesinkarakter.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"
#include "./ADT/queueDS/queue.h"
#include "boolean.h"

void BNMO_START(TabStr *T);

void load(TabStr *T);

void save(char* namafile, TabStr listgame);

void createGame(char *name, TabStr *T);

void listgame(TabStr T);

void deletegame(TabStr *listgame, Queue antriangameidx);

void QueueGame( TabStr *listgame, Queue *antriangameidx);

void playgame(TabStr *listgame, Queue *antriangameidx);

void quit();

void help();

#endif