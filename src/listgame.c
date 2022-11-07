#include <stdio.h>
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"

void listgame(TabStr T)
{
    int i;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 0; i < T.Neff; i++)
    {
        printf(" %d.%s\n", i+1, T.TI[i]);
    }
}