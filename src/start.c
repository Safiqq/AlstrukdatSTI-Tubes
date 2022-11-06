#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

#define MAX_LENGTH 100

// Belum fix, masih jelek
void BNMO_START(TabStr *T)
{
    int i, j, len;
    char *temp;
    MakeEmpty(T);
    isFile = true;
    STARTWORD("../data/config.txt", "r");
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
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}