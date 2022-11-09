#include "playgame.h"

void playGame(TabStr *games, Queue *antriangames)
{
    int i;
    ElTypeQue play;

    printf("Berikut adalah daftar game-mu di antrian sekarang: \n");
    for (i = 1; i <= LengthQueue(*antriangames); i++)
        printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);

    if (!IsEmptyQueue(*antriangames))
    {
        Dequeue(antriangames, &play);
        if (play == 0)
        {
            printf("Loading RNG ...\n");
            rng();
        }
        else if (play == 1)
        {
            printf("Loading DINNER DASH ...\n");
            dinerdash();
        }
        else if (play <= 4 && play >= 2)
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n", games->TI[play]);
        }
        else if (play == 5)
        { // ini kalo misalkan game bonus dimasukin ke config
            printf("Loading TICTACTOE ...");
            tictactoe();
        }
        else if (play >= 6 && play <= (*games).Neff)
        {
            gameTambahan();
        }
    }
    else
        printf("Belum ada game di antrianmu.\n");
}