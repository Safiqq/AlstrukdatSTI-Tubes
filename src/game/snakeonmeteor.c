#include "../header/snakeonmeteor.h"

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

void updateSnake(Matrix2D *M, ListDP L)
{
    addressLDP P = First(L);
    while (P != NilLDP)
    {
        M->MI[X(P)][Y(P)] = Info(P);
        P = Next(P);
    }
}

void moveSnake(Matrix2D *M, ListDP *L)
{
    char inp;
    addressLDP P = First(*L);
    STARTWORD("", "");
    while (!isEqual(currentWord, "W") && !isEqual(currentWord, "A") && !isEqual(currentWord, "S") && !isEqual(currentWord, "D"))
    {
        printf("Input salah!\n");
        STARTWORD("", "");
    }
    if ((SearchLDP(*L, X(P) - 1, Y(P)) != NilLDP && isEqual(currentWord, "W")) ||
        (SearchLDP(*L, X(P), Y(P) - 1) != NilLDP && isEqual(currentWord, "A")) ||
        (SearchLDP(*L, X(P) + 1, Y(P)) != NilLDP && isEqual(currentWord, "S")) ||
        (SearchLDP(*L, X(P), Y(P) + 1) != NilLDP && isEqual(currentWord, "D")))
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

void summonMeteor(Matrix2D *M, ListDP *L)
{
    int x = rand() % 4, y = rand() % 4;
    addressLDP P = SearchLDP(*L, x, y);
    if (P != NilLDP)
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
            DelPLDP(L, Info(Prev(P)), x, y);
            while (P != NilLDP)
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

void summonSnake(Matrix2D *M, ListDP *L)
{
    int x = rand() % 4, y = rand() % 4;
    InsVLastLDP(L, 'H', x, y);
    addressLDP P = First(*L);
    if (y - 1 >= 0) // 1 DI KIRI
    {
        InsVLastLDP(L, '1', x, y - 1);
        if (y - 2 >= 0)
            InsVLastLDP(L, '2', x, y - 2);
        else if (x - 1 >= 0 && y - 1 >= 0)
            InsVLastLDP(L, '2', x - 1, y - 1);
        else
            InsVLastLDP(L, '2', x + 1, y - 1);
    }
    else if (x - 1 >= 0) // 1 DI ATAS
    {
        InsVLastLDP(L, '1', x - 1, y);
        if (x - 2 >= 0)
            InsVLastLDP(L, '2', x - 2, y);
        else
            InsVLastLDP(L, '2', x + 3, y);
    }
    else // 1 DI BAWAH
    {
        InsVLastLDP(L, '1', x + 1, y);
        if (x + 2 >= 0)
            InsVLastLDP(L, '2', x + 2, y);
        else
            InsVLastLDP(L, '2', x - 3, y);
    }
    updateSnake(M, *L);
}

void snakeOnMeteor(ArrayMap *arrSB)
{
    srand(time(NULL));
    Matrix2D M;
    ListDP L;
    int i;
    CreateMC(&M, 5), CreateLDP(&L);
    summonSnake(&M, &L);
    // summonFood(&M);
    PrintMC(M, 0, '.');
    while (true)
    {
        moveSnake(&M, &L);
        summonMeteor(&M, &L);
        PrintMC(M, 0, '.');
    }
}