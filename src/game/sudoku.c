#include "../header/sudoku.h"

char template1[9][9] = {
    {5, 8, 7, 2, 1, 0, 0, 9, 4},
    {0, 1, 4, 6, 9, 5, 0, 8, 3},
    {0, 0, 0, 0, 0, 7, 0, 5, 2},
    {1, 7, 0, 0, 6, 4, 0, 0, 0},
    {0, 0, 3, 0, 0, 0, 5, 0, 0},
    {0, 0, 0, 1, 3, 0, 0, 4, 0},
    {0, 2, 1, 0, 0, 0, 9, 7, 0},
    {0, 0, 0, 0, 0, 6, 0, 1, 0},
    {3, 5, 0, 9, 0, 0, 4, 0, 0}};

char template2[9][9] = {
    {0, 3, 0, 7, 0, 4, 8, 0, 5},
    {0, 7, 0, 5, 0, 9, 0, 4, 0},
    {2, 0, 0, 0, 0, 6, 0, 0, 1},
    {8, 1, 0, 6, 5, 0, 0, 7, 4},
    {7, 6, 0, 0, 4, 0, 1, 0, 0},
    {0, 5, 0, 0, 7, 8, 0, 0, 0},
    {4, 0, 0, 2, 0, 1, 5, 8, 0},
    {0, 0, 6, 0, 0, 5, 0, 0, 0},
    {5, 0, 3, 0, 6, 7, 0, 1, 2}};

char template3[9][9] = {
    {0, 5, 8, 0, 3, 0, 0, 2, 0},
    {4, 0, 2, 0, 0, 0, 9, 0, 5},
    {0, 0, 7, 0, 0, 0, 6, 8, 0},
    {2, 9, 0, 0, 5, 4, 0, 7, 0},
    {5, 0, 0, 0, 6, 2, 0, 0, 0},
    {0, 0, 3, 8, 1, 0, 2, 5, 0},
    {1, 0, 9, 0, 0, 3, 0, 6, 4},
    {8, 6, 5, 4, 9, 0, 1, 3, 0},
    {0, 7, 0, 0, 0, 6, 0, 0, 0}};

boolean cekBaris(Matrix2D M, int x, int y, int num)
{
    int i = 0;
    boolean isAvail = true;
    while (i < M.capacity && isAvail)
    {
        if (M.MI[x][i] == num && i != y)
            isAvail = false;
        i++;
    }
    return isAvail;
}

boolean cekKolom(Matrix2D M, int x, int y, int num)
{
    int i = 0;
    boolean isAvail = true;
    while (i < M.capacity && isAvail)
    {
        if (M.MI[i][y] == num && i != x)
            isAvail = false;
        i++;
    }
    return isAvail;
}

boolean cekBlok(Matrix2D M, int x, int y, int num)
{
    int blok = (0 <= y && y < 3 && 0 <= x && x < 3) ? 0 : (3 <= y && y < 6 && 0 <= x && x < 3) ? 1
                                                      : (6 <= y && y < 9 && 0 <= x && x < 3)   ? 2
                                                      : (0 <= y && y < 3 && 3 <= x && x < 6)   ? 3
                                                      : (3 <= y && y < 6 && 3 <= x && x < 6)   ? 4
                                                      : (6 <= y && y < 9 && 3 <= x && x < 6)   ? 5
                                                      : (0 <= y && y < 3 && 6 <= x && x < 9)   ? 6
                                                      : (3 <= y && y < 6 && 6 <= x && x < 9)   ? 7
                                                                                               : 8;
    int i = 3 * (blok / 3), j = 3 * (blok % 3), count = 0;
    boolean isAvail = true;
    while (count < M.capacity && isAvail)
    {
        count++;
        if (M.MI[i][j] == num && i != x && j != y)
            isAvail = false;
        if (count % 3 == 0)
        {
            i++;
            j -= 3;
        }
        j++;
    }
    return isAvail;
}

boolean cekAngka(Matrix2D M, int x, int y, int num)
{
    return M.MI[x][y] == 0 && cekBaris(M, x, y, num) && cekKolom(M, x, y, num) && cekBlok(M, x, y, num);
}

void createSudoku(Matrix2D *M)
{
    CreateMxI(M, 9);
    srand(time(NULL));
    int i, j, no = rand();
    for (i = 0; i < M->capacity; i++)
    {
        for (j = 0; j < M->capacity; j++)
        {
            M->MI[i][j] = no % 3 == 0 ? template1[i][j] : no % 3 == 1 ? template2[i][j]
                                                                      : template3[i][j];
        }
    }
}

void sudoku(ArrayMap *arrSB)
{
    // Jumlah percobaan maks 10
    // Tersedia 3 template papan yg akan dirandom
    int counter = 0, x = 0, y = 0, num = 0, i, j, k;
    boolean isDone = false;

    Matrix2D M;
    createSudoku(&M);

    counter = 0;
    while (counter < 10 && !isDone)
    {
        PrintMxI(M, 3, '.', false);
        if (IsFullMxI(M))
        {
            printf("Selamat, kamu berhasil menamatkan SUDOku!\n");
            isDone = true;
        }
        else
        {
            while (y < 1 || y > 9)
            {
                printf("Masukkan koordinat X [1..9]: ");
                STARTWORD("", "");
                y = atoi(currentWord.TabWord);
                if (y < 1 || y > 9)
                    printf("Input salah\n");
            }
            while (x < 1 || x > 9)
            {
                printf("Masukkan koordinat Y [1..9]: ");
                STARTWORD("", "");
                x = atoi(currentWord.TabWord);
                if (x < 1 || x > 9)
                    printf("Input salah\n");
            }
            while (num < 1 || num > 9)
            {
                printf("Masukkan angka [1..9]: ");
                STARTWORD("", "");
                num = atoi(currentWord.TabWord);
                if (num < 1 || num > 9)
                    printf("Input salah\n");
            }
            if (cekAngka(M, x - 1, y - 1, num))
                M.MI[x - 1][y - 1] = num;
            else
            {
                counter++;
                if (counter < 10)
                    printf("\nDahlah gabisa main, nyawa kamu sisa %d\n", 10 - counter);
                else
                {
                    printf("=========================================\n");
                    printf("Game over! Noob\n");
                    isDone = true;
                }
            }
            x = 0, y = 0, num = 0;
        }
    }
    int skor = 100 - (10 * counter);
    InsertSB(&arrSB->TIMap[6], skor);
    printf("=========================================\n\n");
}