#include "../header/snakeonmeteor.h"

boolean snakeGameOver = false;
boolean isBodyOnMeteor = false;
boolean addTailCommand = false;

boolean isHeadOnMeteor(Matrix2D M, ListDP L)
{
    addressLDP P = First(L);
    int i, j;
    for (i = 0; i < M.capacity; i++)
    {
        for (j = 0; j < M.capacity; j++)
        {
            if (M.MI[i][j] == 'M' && X(P) == i && Y(P) == j)
                return true;
        }
    }
    return false;
}

boolean isHeadCanMove(Matrix2D M, ListDP L)
{
    addressLDP P = First(L);
    int W = M.MI[X(P) - 1 < 0 ? 4 : X(P) - 1][Y(P)],
        A = M.MI[X(P) + 1 > 4 ? 0 : X(P) + 1][Y(P)],
        S = M.MI[X(P)][Y(P) - 1 < 0 ? 4 : Y(P) - 1],
        D = M.MI[X(P)][Y(P) + 1 > 4 ? 0 : Y(P) + 1];
    return ((W == 0 || W == 'o') || (A == 0 || A == 'o') || (S == 0 || S == 'o') || (D == 0 || D == 'o'));
}

void checkSnake(Matrix2D M, ListDP L)
{
    addressLDP P = First(L);
    int i = X(P), j = Y(P);
    snakeGameOver = IsFullMxI(M) || isHeadOnMeteor(M, L) || !isHeadCanMove(M, L);
}

void clearMeteor(Matrix2D *M)
{
    int i, j;
    isBodyOnMeteor = false;
    for (i = 0; i < M->capacity; i++)
    {
        for (j = 0; j < M->capacity; j++)
        {
            if (M->MI[i][j] == 'M')
                M->MI[i][j] = 0;
        }
    }
}

void clearFood(Matrix2D *M)
{
    int i, j;
    for (i = 0; i < M->capacity; i++)
    {
        for (j = 0; j < M->capacity; j++)
        {
            if (M->MI[i][j] == 'o')
                M->MI[i][j] = 0;
        }
    }
}

void addSnakeTail(Matrix2D M, ListDP *L)
{
    addressLDP P = Last(*L);
    if (M.MI[X(P)][Y(P) - 1 < 0 ? 4 : Y(P) - 1] == 0) // Cek kiri
        InsVLastLDP(L, Info(P) + 1, X(P), Y(P) - 1 < 0 ? 4 : Y(P) - 1);
    else if (M.MI[X(P) - 1 < 0 ? 4 : X(P) - 1][Y(P)] == 0) // Cek atas
        InsVLastLDP(L, Info(P) + 1, X(P) - 1 < 0 ? 4 : X(P) - 1, Y(P));
    else if (M.MI[X(P) + 1 > 4 ? 0 : X(P) + 1][Y(P)] == 0) // Cek bawah
        InsVLastLDP(L, Info(P) + 1, X(P) + 1 > 4 ? 0 : X(P) + 1, Y(P));
    else if (M.MI[X(P)][Y(P) + 1 > 4 ? 0 : Y(P) + 1] == 0) // Cek kanan
        InsVLastLDP(L, Info(P) + 1, X(P), Y(P) + 1 > 4 ? 0 : Y(P) + 1);
    else
        snakeGameOver = true;
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
    addressLDP P = First(*L),
               PW = SearchLDP(*L, X(P) - 1 < 0 ? 4 : X(P) - 1, Y(P)),
               PA = SearchLDP(*L, X(P), Y(P) - 1 < 0 ? 4 : Y(P) - 1),
               PS = SearchLDP(*L, X(P) + 1 < 0 ? 4 : X(P) + 1, Y(P)),
               PD = SearchLDP(*L, X(P), Y(P) + 1 < 0 ? 4 : Y(P) + 1);
    char inp;
    int W = M->MI[X(P) - 1 < 0 ? 4 : X(P) - 1][Y(P)],
        A = M->MI[X(P)][Y(P) - 1 < 0 ? 4 : Y(P) - 1],
        S = M->MI[X(P) + 1 < 0 ? 4 : X(P) + 1][Y(P)],
        D = M->MI[X(P)][Y(P) + 1 < 0 ? 4 : Y(P) + 1];
    boolean isEatFood;
    printf("Silakan masukkan command Anda: ");
    STARTWORD("", "");
    printf("\n");
    while (!IsEqual(currentWord, "W") && !IsEqual(currentWord, "A") && !IsEqual(currentWord, "S") && !IsEqual(currentWord, "D") && !IsEqual(currentWord, "ADDTAIL"))
    {
        printf("Command tidak valid! Silakan input command menggunakan huruf w/a/s/d\n");
        STARTWORD("", "");
        printf("\n");
    }
    if (IsEqual(currentWord, "ADDTAIL"))
    {
        isEatFood = true;
        addTailCommand = true;
    }
    else
    {
        addTailCommand = false;
        // Cek menabrak
        if ((PW != NilLDP && IsEqual(currentWord, "W")) ||
            (PA != NilLDP && IsEqual(currentWord, "A")) ||
            (PS != NilLDP && IsEqual(currentWord, "S")) ||
            (PD != NilLDP && IsEqual(currentWord, "D")))
        {
            printf("Anda tidak dapat bergerak ke tubuh anda sendiri!\n");
            printf("Silakan masukkan command lainnya\n\n");
            while ((PW != NilLDP && IsEqual(currentWord, "W")) ||
                   (PA != NilLDP && IsEqual(currentWord, "A")) ||
                   (PS != NilLDP && IsEqual(currentWord, "S")) ||
                   (PD != NilLDP && IsEqual(currentWord, "D")))
            {
                printf("Silakan masukkan command Anda: ");
                STARTWORD("", "");
                printf("\n");
            }
        }
        if ((W == 'M' && IsEqual(currentWord, "W")) ||
            (A == 'M' && IsEqual(currentWord, "A")) ||
            (S == 'M' && IsEqual(currentWord, "S")) ||
            (D == 'M' && IsEqual(currentWord, "D")))
        {
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut\n");
            printf("Silakan masukkan command lainnya\n\n");
            while ((W == 'M' && IsEqual(currentWord, "W")) ||
                   (A == 'M' && IsEqual(currentWord, "A")) ||
                   (S == 'M' && IsEqual(currentWord, "S")) ||
                   (D == 'M' && IsEqual(currentWord, "D")))
            {
                printf("Silakan masukkan command Anda: ");
                STARTWORD("", "");
                printf("\n");
            }
        }
        isEatFood = ((W == 'o' && IsEqual(currentWord, "W")) ||
                     (A == 'o' && IsEqual(currentWord, "A")) ||
                     (S == 'o' && IsEqual(currentWord, "S")) ||
                     (D == 'o' && IsEqual(currentWord, "D")));
        printf("Berhasil bergerak!\n\n");
        P = Last(*L);
        M->MI[X(P)][Y(P)] = 0;
        while (P != First(*L))
        {
            X(P) = X(Prev(P));
            Y(P) = Y(Prev(P));
            M->MI[X(Prev(P))][Y(Prev(P))] = Info(P);
            P = Prev(P);
        }
        if (IsEqual(currentWord, "W"))
        {
            X(P) -= 1;
            if (X(P) < 0)
                X(P) = 4;
        }
        else if (IsEqual(currentWord, "A"))
        {
            Y(P) -= 1;
            if (Y(P) < 0)
                Y(P) = 4;
        }
        else if (IsEqual(currentWord, "S"))
        {
            X(P) += 1;
            if (X(P) > 4)
                X(P) = 0;
        }
        else if (IsEqual(currentWord, "D"))
        {
            Y(P) += 1;
            if (Y(P) > 4)
                Y(P) = 0;
        }
        M->MI[X(P)][Y(P)] = 'H';
    }
    if (isEatFood)
    {
        addSnakeTail(*M, L);
        updateSnake(M, *L);
        summonFood(M);
    }
    ClearCurrentWord();
}

void summonFood(Matrix2D *M)
{
    int x = rand() % 4, y = rand() % 4;
    clearFood(M);
    // Open addressing
    while (M->MI[x][y] != 0)
    {
        x++;
        if (x > 4)
        {
            x = 0;
            y++;
        }
        if (y > 4)
            y = 0;
    }
    M->MI[x][y] = 'o';
}

void summonMeteor(Matrix2D *M, ListDP *L)
{
    int x = rand() % 4, y = rand() % 4;
    clearMeteor(M);
    addressLDP P = SearchLDP(*L, x, y), temp;
    if (M->MI[x][y] == 'o') // Meteor can't replace food
    {
        y++;
        if (y > 4)
            y = 0;
    }
    M->MI[x][y] = 'M';
    P = SearchLDP(*L, x, y);
    if (P != NilLDP)
    {
        if (Info(P) != 'H')
        {
            isBodyOnMeteor = true;
            temp = Next(P);
            DelPLDP(L, Info(P), x, y);
            while (temp != NilLDP)
            {
                Info(temp) -= 1;
                temp = Next(temp);
            }
            updateSnake(M, *L);
        }
    }
}

void summonSnake(Matrix2D *M, ListDP *L)
{
    int x = rand() % 4, y = rand() % 4;
    InsVLastLDP(L, 'H', x, y);
    addressLDP P = First(*L);
    if (y - 1 >= 0) // 1 DI KIRI
    {
        InsVLastLDP(L, 1, x, y - 1);
        if (y - 2 >= 0)
            InsVLastLDP(L, 2, x, y - 2);
        else if (x - 1 >= 0 && y - 1 >= 0)
            InsVLastLDP(L, 2, x - 1, y - 1);
        else
            InsVLastLDP(L, 2, x + 1, y - 1);
    }
    else if (x - 1 >= 0) // 1 DI ATAS
    {
        InsVLastLDP(L, 1, x - 1, y);
        if (x - 2 >= 0)
            InsVLastLDP(L, 2, x - 2, y);
        else
            InsVLastLDP(L, 2, x + 3, y);
    }
    else // 1 DI BAWAH
    {
        InsVLastLDP(L, 1, x + 1, y);
        if (x + 2 >= 0)
            InsVLastLDP(L, 2, x + 2, y);
        else
            InsVLastLDP(L, 2, x - 3, y);
    }
    updateSnake(M, *L);
}

void snakeOnMeteor(ArrayMap *arrSB)
{
    printf("Selamat datang di Snake on Meteor!\n");
    printf("Meng-generate peta, snake, dan makanan...\n");
    printf("Berhasil di-generate!\n\n");
    snakeGameOver = false;
    srand(time(NULL));
    Matrix2D M;
    ListDP L;
    int i;
    CreateMxI(&M, 5), CreateLDP(&L);
    summonSnake(&M, &L), summonFood(&M);
    PrintMxI(M, 0, '.', true);
    while (!snakeGameOver)
    {
        moveSnake(&M, &L);
        if (!snakeGameOver && !addTailCommand)
            summonMeteor(&M, &L);
        PrintMxI(M, 0, '.', true);
        if (isHeadOnMeteor(M, L))
            printf("Kepala snake terkena meteor!\n");
        else
        {
            if (isBodyOnMeteor)
                printf("Anda terkena meteor!\n");
            else
                printf("Anda beruntung tidak terkena meteor! Silakan lanjutkan permainan\n");
        }
        checkSnake(M, L);
    }
    int score = (LengthLDP(L) - isHeadOnMeteor(M, L)) * 2;
    printf("Game berakhir. Skor: %d\n", score);
    InsertSB(&arrSB->TIMap[4], score);
    ClearCurrentWord();
}