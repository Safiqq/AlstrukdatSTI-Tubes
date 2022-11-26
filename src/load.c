#include <stdlib.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"
#include "./ADT/stackH/stack.h"
#include "./ADT/mapscoreboard/mapsb.h"
#include "./ADT/arrayOfMap/arraymap.h"

void load(char *namafile, TabStr *games, Stack *history, TabMap * arrSB )
{
    int i = 8, j,k,l, lengame,len, skor, idxarr, lensb;
    char *temp, *hist, *nama, *charskor;
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
        lengame = atoi(currentWord.TabWord);
        for (i = 0; i < lengame; i++)
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
        ADVLINE();
        idxarr=0;
        if(lengame>7){
            for (i=7;i<lengame;i++){
                InsertLast(arrSB);
            }
        }
        for(k =0;k<lengame;k++){
            lensb = atoi(currentWord.TabWord);
            for(j=0;j<lensb;j++){
                ADVLINE();
                i = 0;
                nama = (char *)malloc(sizeof(char *) * (CAPACITY));
                while (currentWord.TabWord[i] != ' ')
                {
                    nama[i] = currentWord.TabWord[i];
                    i++;
                }
                nama[i]='\0';
                l =0;
                charskor = (char *)malloc(sizeof(char *) * (CAPACITY));
                while (currentWord.TabWord[i] != '\0')
                {
                    charskor[l] = currentWord.TabWord[i];
                    l++;
                    i++;
                }
                charskor[l]='\0';
                skor = atoi(charskor);
                InsertMapSB(&arrSB->TIMap[idxarr],nama,skor);
            }
            ADVLINE();
            idxarr++;
        }
        
        
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
    }
    else
        printf("File save tidak ditemukan.\n");
}