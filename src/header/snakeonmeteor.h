#ifndef __SNAKEONMETEOR_H__
#define __SNAKEONMETEOR_H__

#include <stdlib.h>
#include <time.h>

#include "../ADT/arrayMap/arrayMap.h"
#include "../ADT/listdp/listdp.h"
#include "../ADT/mapStr/mapStr.h"
#include "../ADT/matriksChar/matriksChar.h"
#include "../ADT/mesinkata/mesinkata.h"

boolean snakeGameOver;

boolean isHeadOnMeteor(Matrix2D M, ListDP L);
void checkSnake(Matrix2D M, ListDP L);
void clearFood(Matrix2D *M);
void clearMeteor(Matrix2D *M);
void addSnakeTail(Matrix2D M, ListDP *L);
void updateSnake(Matrix2D *M, ListDP L);
void moveSnake(Matrix2D *M, ListDP *L);
void summonFood(Matrix2D *M);
void summonMeteor(Matrix2D *M, ListDP *L);
void summonSnake(Matrix2D *M, ListDP *L);
void snakeOnMeteor(ArrayMap *arrSB);

#endif