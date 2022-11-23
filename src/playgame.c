#include "./ADT/array/array.h"
#include "./ADT/queue/queue.h"
#include "./ADT/stackH/stack.h"
#include "./ADT/mapscoreboard/map.h"
// #include "playgame.h"

void playGame(TabStr *games, Queue *antriangames, Stack *history, MapSB *sbTOH,MapSB *sbDiner,MapSB *sbSOM,MapSB *sbRNG,MapSB *sbHangman, MapSB *sbGameTambahan)
{
    int i;
    ElTypeQue play;

    printf("Berikut adalah daftar game-mu di antrian sekarang: \n");
    for (i = 1; i <= LengthQueue(*antriangames); i++)
        printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);

    if (!IsEmptyQueue(*antriangames))
    {
        Dequeue(antriangames, &play);
        printf("Loading %s\n", games->TI[play]);
        if (play == 0)
        {
            rng();
        }
        else if (play == 1)
        {
            dinerdash();
        }
        else if (play == 2)
        {
            hangman();
        }
        else if (play == 3)
        {
            towerofhanoi();
        }
        else if (play == 4)
        {
            snakeOnMeteor();
        }
        else if (play == 5)
        {
            tictactoe();
        }
        else if (play == 6)
        {
            sudoku();
        }
        else if (play >= 7 && play <= (*games).Neff)
        {
            gameTambahan(sbGameTambahan);
        }
        push(history, play);
    }
    else
        printf("Belum ada game di antrianmu.\n");
}