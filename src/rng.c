#include <stdlib.h>
#include <time.h>
#include "./ADT/mesinkata/mesinkata.h"

// RNG_MAX = RAND_MAX (32767) * 3 = 98301
#define RNG_MAX 98301

int random(int min, int max)
{
    int r1, r2, r3;
    srand(time(NULL));
    r1 = rand();
    r2 = rand();
    r3 = rand();
    return ((r1 + r2 + r3) % (max - min + 1)) + min;
}

void rng()
{
    // Jumlah percobaan maks 10
    // Angka random dari 1-100 inklusif
    boolean isTrue = false;
    int i = 0, inpNum, randomNum = random(1, 100);

    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
    while (i < 10 && !isTrue)
    {
        printf("Tebakan: ");
        STARTWORD("", "");
        inpNum = atoi(currentWord.TabWord);
        if (inpNum > randomNum)
            printf("Lebih kecil\n");
        else if (inpNum == randomNum)
            isTrue = true;
        else
            printf("Lebih besar\n");
        i++;
    }
    if (isTrue)
        printf("\nYa, X adalah %d.\n", randomNum);
    else
        printf("\nTebakan Anda salah semua, X adalah %d.\n", randomNum);
}