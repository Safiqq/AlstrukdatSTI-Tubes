#include <stdlib.h>
#include <time.h>
#include "./ADT/matriks/matriks.h"
#include "./ADT/listlinier/listlinier.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/mapscoreboard/mapsb.h"
#include "./ADT/arrayOfMap/arraymap.h"

// int meteorX, meteorY, foodX, foodY;

void clearMeteor(Matrix2D *M)
{
    int i, j;
    for (i = 0; i < M->capacity; i++)
    {
        for (j = 0; j < M->capacity; j++)
        {
            if (M->MI[i][j] == 'M')
                M->MI[i][j] = '0';
        }
    }
}

void updateSnake(Matrix2D *M, List L)
{
    address P = First(L);
    while (P != Nil)
    {
        M->MI[X(P)][Y(P)] = Info(P);
        P = Next(P);
    }
}

void moveSnake(Matrix2D *M, List *L)
{
    char inp;
    address P = First(*L);
    STARTWORD("", "");
    while (!isEqual(currentWord, "W") && !isEqual(currentWord, "A") && !isEqual(currentWord, "S") && !isEqual(currentWord, "D"))
    {
        printf("Input salah!\n");
        STARTWORD("", "");
    }
    if ((SearchList(*L, X(P) - 1, Y(P)) != Nil && isEqual(currentWord, "W")) ||
        (SearchList(*L, X(P), Y(P) - 1) != Nil && isEqual(currentWord, "A")) ||
        (SearchList(*L, X(P) + 1, Y(P)) != Nil && isEqual(currentWord, "S")) ||
        (SearchList(*L, X(P), Y(P) + 1) != Nil && isEqual(currentWord, "D")))
    {
        printf("Menabrak body\n");
    }
    else
    {
        P = Last(*L);
        M->MI[X(P)][Y(P)] = '0';
        while (P != First(*L))
        {
            X(P) = X(Prev(P));
            Y(P) = Y(Prev(P));
            M->MI[X(Prev(P))][Y(Prev(P))] = Info(P);
            P = Prev(P);
        }
        if (isEqual(currentWord, "W"))
        {
            X(P) -= 1;
            if (X(P) < 0)
                X(P) = 4;
        }
        else if (isEqual(currentWord, "A"))
        {
            Y(P) -= 1;
            if (Y(P) < 0)
                Y(P) = 4;
        }
        else if (isEqual(currentWord, "S"))
        {
            X(P) += 1;
            if (X(P) > 4)
                X(P) = 0;
        }
        else if (isEqual(currentWord, "D"))
        {
            Y(P) += 1;
            if (Y(P) > 4)
                Y(P) = 0;
        }
        M->MI[X(P)][Y(P)] = 'H';
    }
}

void summonFood(Matrix2D *M)
{
    int x = rand() % 4, y = rand() % 4;
    while (M->MI[x][y] != '0')
    {
        x++;
        if (x == 5)
        {
            x = 0;
            y++;
        }
        if (y == 5)
            y = 0;
    }
    M->MI[x][y] = 'o';
}

void summonMeteor(Matrix2D *M, List *L)
{
    int x = rand() % 4, y = rand() % 4;
    address P = SearchList(*L, x, y);
    if (P != Nil)
    {
        if (Info(P) == 'H')
        {
            printf("Kepala snake terkena meteor!\n");
            // gameover
        }
        else
        {
            printf("Anda terkena meteor!\n");
            P = Next(P);
            DelPList(L, Info(Prev(P)), x, y);
            while (P != Nil)
            {
                Info(P) -= 1;
                P = Next(P);
            }
        }
    }
    updateSnake(M, *L);
    clearMeteor(M);
    M->MI[x][y] = 'M';
}

void summonSnake(Matrix2D *M, List *L)
{
    int x = rand() % 4, y = rand() % 4;
    InsVLastList(L, 'H', x, y);
    address P = First(*L);
    if (y - 1 >= 0) // 1 DI KIRI
    {
        InsVLastList(L, '1', x, y - 1);
        if (y - 2 >= 0)
            InsVLastList(L, '2', x, y - 2);
        else if (x - 1 >= 0 && y - 1 >= 0)
            InsVLastList(L, '2', x - 1, y - 1);
        else
            InsVLastList(L, '2', x + 1, y - 1);
    }
    else if (x - 1 >= 0) // 1 DI ATAS
    {
        InsVLastList(L, '1', x - 1, y);
        if (x - 2 >= 0)
            InsVLastList(L, '2', x - 2, y);
        else
            InsVLastList(L, '2', x + 3, y);
    }
    else // 1 DI BAWAH
    {
        InsVLastList(L, '1', x + 1, y);
        if (x + 2 >= 0)
            InsVLastList(L, '2', x + 2, y);
        else
            InsVLastList(L, '2', x - 3, y);
    }
    updateSnake(M, *L);
}

void snakeOnMeteor(TabMap *arrSB)
{
    srand(time(NULL));
    Matrix2D M;
    List L;
    int i;
    CreateMtx(&M, 5), CreateEmptyList(&L);
    summonSnake(&M, &L);
    // summonFood(&M);
    PrintMtx(M, 0, '.');
    while (true)
    {
        moveSnake(&M, &L);
        summonMeteor(&M, &L);
        PrintMtx(M, 0, '.');
    }
}