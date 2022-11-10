#include <stdlib.h>
#include "./ADT/array/array.h"
#include "./ADT/queue/queue.h"
#include "./ADT/mesinkata/mesinkata.h"

void queueGame(TabStr *games, Queue *antriangames)
{
    int i;
    printf("Berikut adalah daftar antrian game-mu\n");
    for (i = 1; i <= LengthQueue(*antriangames); i++)
    {
        printf("%d. %s\n", i, games->TI[antriangames->buffer[i - 1]]);
    }
    printf("\n");
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 1; i <= LengthArray(*games); i++)
    {
        printf("%d. %s\n", i, games->TI[i - 1]);
    }
    int n;
    printf("\nNomor Game yang mau ditambahkan ke antrian: ");
    STARTWORD("", "");
    n = atoi(currentWord.TabWord);
    if (n > games->Neff && n<=0)
    {
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else
    {
        Enqueue(antriangames, n - 1);
        printf("\nGame berhasil ditambahkan kedalam daftar antrian.\n");
    }
}
