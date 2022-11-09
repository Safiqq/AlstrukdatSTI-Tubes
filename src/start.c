#include <stdlib.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

#define MAX_LENGTH 100

void start(TabStr *games)
{
    int i, j, len;
    char *temp;
    CreateArray(games);

    STARTWORD("../data/config.txt", "r");
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
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
}