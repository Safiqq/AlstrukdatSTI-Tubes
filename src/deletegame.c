#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"
#include "boolean.h"

void deletegame(TabStr *listgame, Queue antriangameidx)
{
    int i;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 1; i <= LengthArray(*listgame); i++)
    {
        printf("%d. %s\n", i, listgame->TI[i - 1]);
    }
    QueElType hapus;
    printf("Masukkan nomor game yang akan dihapus:");
    scanf("%d", &hapus);
    if (hapus <= 5 && hapus >= 1)
    {
        printf("Game gagal dihapus.\n");
    }
    else
    {
        boolean isInAntrian = false;
        i = 0;
        while ((i < length(antriangameidx)) && !isInAntrian)
        {
            if (hapus == antriangameidx.buffer[i])
            {
                isInAntrian = true;
            }
            i++;
        }
        if (isInAntrian)
        {
            printf("Game gagal dihapus.\n");
        }
        else
        {
            for (i = hapus - 1; i < LengthArray(*listgame); i++)
            {
                if (i != LengthArray(*listgame) - 1)
                {
                    (*listgame).TI[i] = (*listgame).TI[i + 1];
                }
                else
                {
                    (*listgame).Neff -= 1; // menghapus elemen terakhir menjadi sampah
                }
            }
            printf("Game berhasil dihapus.\n");
        }
    }
}