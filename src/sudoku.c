#include "./ADT/matriks/matriks.h"
#include "./ADT/mesinkata/mesinkata.h"

boolean cekBaris(Matrix2D M, int x, int y, int num)
{
    int i = 0;
    boolean isAvail = true;
    while (i < CAPACITY && isAvail)
    {
        if (M.TI[x][i] == num && i != y)
            isAvail = false;
        i++;
    }
    return isAvail;
}

boolean cekKolom(Matrix2D M, int x, int y, int num)
{
    int i = 0;
    boolean isAvail = true;
    while (i < CAPACITY && isAvail)
    {
        if (M.TI[i][y] == num && i != x)
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
    while (count < CAPACITY && isAvail)
    {
        count++;
        if (M.TI[i][j] == num && i != x && j != y)
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
    return M.TI[x][y] == 0 && cekBaris(M, x, y, num) && cekKolom(M, x, y, num) && cekBlok(M, x, y, num);
}

void sudoku()
{
    // Jumlah percobaan maks 10
    // Tersedia 3 template papan yg akan dirandom
    int counter = 0, x = 0, y = 0, num = 0, i, j, k;
    boolean isDone = false;

    Matrix2D M;
    CreateMtx(&M);

    counter = 0;
    while (counter < 10 && !isDone)
    {
        PrintMtx(M);
        if (IsFullMtx(M))
        {
            printf("Selamat, kamu berhasil menamatkan SUDOku!");
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
                M.TI[x - 1][y - 1] = num;
            else
            {
                counter++;
                if (counter < 10)
                    printf("\nDahlah gabisa main, nyawa kamu sisa %d\n", 10 - counter);
                else
                {
                    printf("Game over! Noob\n");
                    isDone = true;
                }
            }
            x = 0, y = 0, num = 0;
        }
    }
    printf("Skor kamu %d\n", 100 - (10 * counter));
}