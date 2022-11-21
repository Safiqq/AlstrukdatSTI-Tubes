#include "./ADT/array/array.h"
#include "./ADT/queue/queue.h"
#include "./ADT/stackH/stack.h"
// #include "playgame.h"

void playGame(TabStr *games, Queue *antriangames, Stack *history)
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
        { 
            printf("Loading TICTACTOE ...\n");
            tictactoe();
        }
        else if (play==6) {
            printf("Loading SUDOku ...\n");
            sudoku();
        }
        else if (play >= 7 && play <= (*games).Neff)
        {
            gameTambahan();
        }
        push(history, play);
    }
    else
        printf("Belum ada game di antrianmu.\n");
}