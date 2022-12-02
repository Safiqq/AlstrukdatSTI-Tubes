#ifndef __PLAYGAME_H__
#define __PLAYGAME_H__

#include "../ADT/arrayMap/arrayMap.h"
#include "../ADT/arrayStr/arrayStr.h"
#include "../ADT/mapStr/mapStr.h"
#include "../ADT/queueInt/queueInt.h"
#include "../ADT/stackStr/stackStr.h"

void rng(ArrayMap *arrSB);
void dinerdash(ArrayMap *arrSB);
void hangman(ArrayMap *arrSB);
void towerofhanoi(ArrayMap *arrSB);
void snakeOnMeteor(ArrayMap *arrSB);
void tictactoe(ArrayMap *arrSB);
void sudoku(ArrayMap *arrSB);
void findTheNumber(ArrayMap *arrSB);
void gameTambahan(ArrayMap *arrSB, int play);

#endif