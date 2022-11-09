#ifndef __PLAYGAME_H__
#define __PLAYGAME_H__

#include <stdlib.h>
#include "ADT/queue/queue.h"
#include "ADT/array/array.h"
#include "ADT/mesinkata/mesinkata.h"

void skipGame(Word skip, TabStr *games, Queue *antriangames);
void playGame(TabStr *games, Queue *antriangames);

#endif