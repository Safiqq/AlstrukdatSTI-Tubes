#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/stackH/stack.h"

void deleteGame(TabStr *games, Queue *antriangames, Stack *history)
{
    int i;
    ElTypeQue hapus;

    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 1; i <= LengthArray(*games); i++)
        printf("%d. %s\n", i, games->TI[i - 1]);

    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD("", "");
    hapus = atoi(currentWord.TabWord);

    if (hapus <= 7 || hapus > games->Neff)
        printf("Game gagal dihapus.\n");
    else
    {
        boolean isInAntrian = false;
        i = 0;
        while ((i < LengthQueue(*antriangames)) && !isInAntrian)
        {
            if (hapus - 1 == (*antriangames).buffer[i])
                isInAntrian = true;
            i++;
        }
        if (isInAntrian)
            printf("Game gagal dihapus.\n");
        else
        {
            //Menghapus game yang ada di history
            Stack S2;
            CreateEmptyStack(&S2);
            while (!IsEmptyStack(*history))
            {
                infotype X;
                pop(history,&X);
                if (*X!=*games->TI[hapus-1]){
                    push(&S2,X);
                }
            }
            reversestack(&S2);
            int i;
            for (i=0;i<nbelmtStack(S2);i++){
                history->Tab[i]=S2.Tab[i];
            }
            history->TOP=S2.TOP;
            //Menghapus game dari list game
            for (i = hapus - 1; i < LengthArray(*games); i++)
            {
                if (i != LengthArray(*games) - 1)
                    (*games).TI[i] = (*games).TI[i + 1];
                else
                    (*games).Neff -= 1; // menghapus elemen terakhir menjadi sampah
            }
            ElTypeQue val;
            for (i = 0; i < LengthQueue(*antriangames); i++)
            {
                Dequeue(antriangames, &val);
                if (val >= hapus)
                    val--;
                Enqueue(antriangames, val);
            }
            printf("Game berhasil dihapus.\n");
        }
    }
}