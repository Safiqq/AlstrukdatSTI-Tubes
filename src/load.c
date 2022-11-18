#include <stdlib.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

void load(char *namafile, TabStr *games)
{
    int i = 8, j, len;
    char *temp;
    char path[100] = "../data/";

    while (*namafile != '\0')
    {
        path[i] = *namafile;
        i++;
        *namafile++;
    }
    STARTWORD(path, "r");

    if (pitaFile != NULL)
    {
        CreateArray(games);
        len = atoi(currentWord.TabWord);
        for (i = 0; i < len; i++)
        {
            ADVLINE();
            temp = (char *)malloc(sizeof(char *) * (CAPACITY));
            j = 0;
            while (currentWord.TabWord[j] != '\0')
            {
                temp[j] = currentWord.TabWord[j];
                j++;
            }
            temp[j] = '\0';
            SetArray(games, i, temp);
        }
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
    else
        printf("File save tidak ditemukan.\n");
}