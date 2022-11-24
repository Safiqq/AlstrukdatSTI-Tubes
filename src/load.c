#include <stdlib.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"
#include "./ADT/stackH/stack.h"
#include "./ADT/mapscoreboard/map.h"

void load(char *namafile, TabStr *games, Stack *history, MapSB *sbTOH,MapSB *sbDiner,MapSB *sbSOM,MapSB *sbRNG,MapSB *sbHangman, MapSB *sbGameTambahan,MapSB *sbTTT, MapSB *sbsudoku)
{
    int i = 8, j, len;
    char *temp, *hist;
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
        //Membaca LISTGAME
        //CreateArray(games);
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
        //Membaca HISTORY
        //CreateEmptyStack(history);
        ADVLINE();
        len = atoi(currentWord.TabWord);
        for (i = 0; i < len; i++)
        {
            ADVLINE();
            hist = (char *)malloc(sizeof(char *) * (CAPACITY));
            j = 0;
            while (currentWord.TabWord[j] != '\0')
            {
                hist[j] = currentWord.TabWord[j];
                j++;
            }
            hist[j] = '\0';
            push(history,hist);
        }
        reversestack(history);
        //Membaca SCOREBOARD
        
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
    else
        printf("File save tidak ditemukan.\n");
}