#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"

void deleteGame(TabStr *games, Queue antriangames)
{
    int i;
    ElTypeQue hapus;

    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 1; i <= LengthArray(*games); i++)
        printf("%d. %s\n", i, games->TI[i - 1]);

    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD("", "");
    hapus = atoi(currentWord.TabWord);

    if (hapus <= 5 || hapus > games->Neff)
        printf("Game gagal dihapus.\n");
    else
    {
        boolean isInAntrian = false;
        i = 0;
        while ((i < LengthQueue(antriangames)) && !isInAntrian)
        {
            if (hapus == antriangames.buffer[i])
                isInAntrian = true;
            i++;
        }
        if (isInAntrian)
            printf("Game gagal dihapus.\n");
        else
        {
            for (i = hapus - 1; i < LengthArray(*games); i++)
            {
                if (i != LengthArray(*games) - 1)
                    (*games).TI[i] = (*games).TI[i + 1];
                else
                    (*games).Neff -= 1; // menghapus elemen terakhir menjadi sampah
            }
            printf("Game berhasil dihapus.\n");
        }
    }
}