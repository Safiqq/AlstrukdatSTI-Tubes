#include <stdio.h>
#include "./ADT/array/array.h"
#include "./ADT/queue/queue.h"

// TabInt ElType= Char
void QueueGame(TabStr *listgame, Queue *antriangameidx)
{
    int i;
    printf("Berikut adalah daftar antrian game-mu\n");
    for (i = 1; i <= length(*antriangameidx); i++)
    {
        printf("%d. %s\n", i, listgame->TI[antriangameidx->buffer[i - 1]]);
    }
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 1; i <= LengthArray(*listgame); i++)
    {
        printf("%d. %s\n", i, listgame->TI[i - 1]);
    }
    int n;
    printf("\nNomor Game yang mau ditambahkan ke antrian: ");
    scanf("%d", &n);
    if (n > listgame->Neff)
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else
    {
        int found = 0;
        i = 0;
        while (i < length(*antriangameidx) && found == 0)
        {
            if (antriangameidx->buffer[i] == n - 1)
            {
                found = 1;
            }
            i++;
        }
        if (found == 0)
        {
            enqueue(&(*antriangameidx), n - 1);
        }
        printf("\nGame berhasil ditambahkan kedalam daftar antrian.\n");
    }
}
