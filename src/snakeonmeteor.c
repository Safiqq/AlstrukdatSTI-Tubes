#include "./ADT/matriks/matriks.h"
#include <stdlib.h>
#include <time.h>

void summonFood(Matrix2D *M)
{
    int x = randomNum(0, 4), y = randomNum(0, 4);
    M->MI[x][y] = 'H';
}

void summonSnake(Matrix2D *M)
{
    int x = randomNum(0, 4), y = randomNum(0, 4);
    M->MI[x][y] = 'H';
    if (y - 1 >= 0) // 1 DI KIRI
    {
        M->MI[x][y - 1] = '1';
        if (y - 2 >= 0)
            M->MI[x][y - 2] = '2';
        else if (x - 1 >= 0 && y - 1 >= 0)
            M->MI[x - 1][y - 1] = '2';
        else
            M->MI[x + 1][y - 1] = '2';
    }
    else if (x - 1 >= 0) // 1 DI ATAS
    {
        M->MI[x - 1][y] = '1';
        if (x - 2 >= 0)
            M->MI[x - 2][y] = '2';
        else
            M->MI[x + 3][y] = '2';
    }
    else // 1 DI BAWAH
    {
        M->MI[x + 1][y] = '1';
        if (x + 2 >= 0)
            M->MI[x + 2][y] = '2';
        else
            M->MI[x - 3][y] = '2';
    }
    PrintMtx(*M, 0, '.');
}

void snakeOnMeteor()
{
    Matrix2D M;
    int i;
    CreateMtx(&M, 5);
    summonSnake(&M);
    PrintMtx(M, 0, '.');
}