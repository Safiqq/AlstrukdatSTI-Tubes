#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"

#define MAX_LENGTH 100

void BNMO_START(Queue *Q)
{
    int i, j, len;
    CreateQueue(Q);
    isFile = true;
    STARTWORD();
    len = atoi(currentWord.TabWord);
    for (i = 0; i < len; i++)
    {
        ADVLINE();
        printf("%s\n", currentWord.TabWord);

        // ElType = char* = string
        enqueue(Q, currentWord.TabWord);
    }
}