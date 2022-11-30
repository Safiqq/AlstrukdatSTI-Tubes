#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../ADT/arrayStr/arrayStr.h"
#include "../ADT/arrayChar/arrayChar.h"
#include "../ADT/arrayMap/arrayMap.h"
#include "../ADT/listdp/listdp.h"
#include "../ADT/mapInt/mapInt.h"
#include "../ADT/mapStr/mapStr.h"
#include "../ADT/matrixInt/matrixInt.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/queueInt/queueInt.h"
#include "../ADT/queueDS/queueDS.h"
#include "../ADT/stackStr/stackStr.h"
#include "../ADT/stackInt/stackInt.h"

#define MAX_LENGTH 100

void mainMenu();
void start(ArrayStr *games);
void load(char *namafile, ArrayStr *games, StackStr *history, ArrayMap *arrSB);
void save(char *namafile, ArrayStr games, StackStr riwayat, ArrayMap arrSB);
void createGame(char *name, ArrayStr *games, ArrayMap *arrSB);
void commandLain();
void listGame(ArrayStr games);
void deleteGame(ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *arrSB);
void queueGame(ArrayStr *games, Queue *antriangames);
void playGame(ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *arraySB);
void skipGame(Word skip, ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *ArraySB);
void history(StackStr *history, ArrayStr games);
void resetHistory(StackStr *history, ArrayStr games);
void resetScoreboard(ArrayMap *arrSB, ArrayStr games);
void scoreboard(ArrayMap arrSB, ArrayStr games);
void quit();
void help();

#endif