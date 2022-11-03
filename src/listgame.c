#include <stdio.h>
#include "./ADT/queue/queue.h"

void listgame(Queue Q)
{
    int i;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 0; i < length(Q); i++)
    {
        printf("\t%d.%s\n", i, Q.buffer[i]);
    }
}