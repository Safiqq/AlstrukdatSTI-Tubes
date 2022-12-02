#include "../header/playgame.h"

void playGame(ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *arraySB)
{
    int i;
    ElTypeQue play;

    printf("Berikut adalah daftar game-mu di antrian sekarang: \n");
    for (i = 1; i <= LengthQI(*antriangames); i++)
        printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);

    if (!IsEmptyQI(*antriangames))
    {
        DequeueI(antriangames, &play);
        printf("Loading %s\n\n", games->TI[play]);
        if (play == 0)
        {
            rng(arraySB);
        }
        else if (play == 1)
        {
            dinerdash(arraySB);
        }
        else if (play == 2)
        {
            hangman(arraySB);
        }
        else if (play == 3)
        {
            towerofhanoi(arraySB);
        }
        else if (play == 4)
        {
            snakeOnMeteor(arraySB);
        }
        else if (play == 5)
        {
            tictactoe(arraySB);
        }
        else if (play == 6)
        {
            sudoku(arraySB);
        }
        else if (play == 7)
        {
            findTheNumber(arraySB);
        }
        else if (play >= 8 && play <= (*games).Neff)
        {
            gameTambahan(arraySB, play);
        }
        ElTypeAS hist;
        hist = games->TI[play];
        PushSS(history, hist);
    }
    else
        printf("Belum ada game di antrianmu.\n");
}