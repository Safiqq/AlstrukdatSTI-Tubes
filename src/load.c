#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

void load(char * namafile, TabStr *T) 
{
    int i, j, len;
    char *temp;
    MakeEmpty(T);
    isFile = true;
    scanf("%s", &namafile);
    STARTWORD(namafile, "r");
    len = atoi(currentWord.TabWord);
    for (i = 0; i < len; i++)
    {
        ADVLINE();
        temp = (char *)malloc(sizeof(char *) * (IdxMax - IdxMin + 1));
        j = 0;
        while (currentWord.TabWord[j] != '\0')
        {
            temp[j] = currentWord.TabWord[j];
            j++;
        }
        temp[j] = '\0';
        SetEl(T, i, temp);
    }
    isFile = false;
    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
}
