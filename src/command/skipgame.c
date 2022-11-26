#include "../header/skipgame.h"

void skipGame(Word skip, ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *arraySB)
{
    ADVWORD();
    int i, num = atoi(currentWord.TabWord);
    if (num >= 0)
    {
        printf("Berikut adalah daftar game di antrian milikmu: \n");
        for (i = 1; i <= LengthQI(*antriangames); i++)
        {
            printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);
        }
        if (num > LengthQI(*antriangames) - 1)
        {
            while (!IsEmptyQI(*antriangames))
            {
                ElTypeQue val;
                DequeueI(antriangames, &val);
            }
            printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
        }
        else
        {
            while (num != 0)
            {
                ElTypeQue val;
                DequeueI(antriangames, &val);
                num--;
            }
            playGame(games, antriangames, history, arraySB);
        }
    }
    else
    {
        printf("Masukan <n> tidak valid. Silakan ulangi.\n");
    }
}