#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

#define MAX_LENGTH 100

void BNMO_START(TabStr *T)
{
    int i, j, len;
    MakeEmpty(T);
    isFile = true;
    STARTWORD("../data/config.txt", "r");
    len = atoi(currentWord.TabWord);
    for (i = 0; i < len; i++)
    {
        ADVLINE();
        // Bug, all elements [0..len-2] replaced by last el
        SetEl(T, i, currentWord.TabWord);
    }
}