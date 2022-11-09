#include "skipgame.h"

void skipGame(Word skip, TabStr *games, Queue *antriangames)
{
    ADVWORD();
    int i, num = atoi(currentWord.TabWord);
    printf("Berikut adalah daftar game di antrian milikmu: \n");
    for (i = 1; i <= LengthQueue(*antriangames); i++)
    {
        printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);
    }
    if (num > LengthQueue(*antriangames) - 1)
    {
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    else
    {
        while (num != 0)
        {
            ElTypeQue val;
            Dequeue(antriangames, &val);
            num--;
        }
        playGame(games, antriangames);
    }
}