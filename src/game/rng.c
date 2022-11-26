#include "../header/rng.h"

// RNG_MAX = RAND_MAX (32767) * 3 = 98301
#define RNG_MAX 98301

int randomNum(int min, int max)
{
    int r1, r2, r3, res;
    srand(time(NULL));
    r1 = rand();
    r2 = rand();
    r3 = rand();
    res = ((r1 + r2 + r3) % (max - min + 1)) + min;
    return res > 0 ? res : res * (-1);
}

void rng(ArrayMap *arrSB)
{
    // Jumlah percobaan maks 10
    // Angka random dari 1-100 inklusif
    boolean isTrue = false;
    int i = 0, inpNum = 0, answer = randomNum(1, 100);

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    printf("X merupakan angka random dengan range [1.100]\n");
    while (i < 10 && !isTrue)
    {
        while (inpNum < 1 || inpNum > 100)
        {
            printf("Tebakan [1.100]: ");
            STARTWORD("", "");
            inpNum = atoi(currentWord.TabWord);
            if (inpNum < 1 || inpNum > 100)
                printf("Input salah\n");
        }
        if (inpNum > answer)
            printf("Lebih kecil\n");
        else if (inpNum == answer)
            isTrue = true;
        else
            printf("Lebih besar\n");
        inpNum = 0;
        i++;
    }
    printf("=========================================\n");
    if (isTrue)
        printf("\nYa, X adalah %d.\n", answer);
    else
        printf("\nTebakan Anda salah semua, X adalah %d.\n", answer);
    int skor = 100 - (10 * i);
    InsertSB(&arrSB->TIMap[0], skor);
    printf("=========================================\n\n");
}