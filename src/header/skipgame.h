#ifndef __SKIPGAME_H__
#define __SKIPGAME_H__

#include <stdlib.h>

#include "../ADT/arrayMap/arrayMap.h"
#include "../ADT/arrayStr/arrayStr.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/queueInt/queueInt.h"
#include "../ADT/stackStr/stackStr.h"
#include "../lib.h"

void playGame(ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *arraySB);

#endif