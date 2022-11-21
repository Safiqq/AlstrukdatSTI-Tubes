#include <stdlib.h>
#include "ADT/queue/queue.h"
#include "ADT/array/array.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/stackH/stack.h"

void skipGame(Word skip, TabStr *games, Queue *antriangames, Stack *history)
{
    ADVWORD();
    int i, num = atoi(currentWord.TabWord);
    if (num>=0){
        printf("Berikut adalah daftar game di antrian milikmu: \n");
        for (i = 1; i <= LengthQueue(*antriangames); i++)
        {
            printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);
        }
        if (num > LengthQueue(*antriangames) - 1)
        {
            while (!IsEmptyQueue(*antriangames))
            {
                ElTypeQue val;
                Dequeue(antriangames, &val);
            }
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
            playGame(games, antriangames, history);
        }
    }
    else{
        printf("Masukan <n> tidak valid. Silakan ulangi.\n");
    }
}