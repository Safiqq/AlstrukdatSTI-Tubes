#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "ADT/mapscoreboard/map.h"

void gameTambahan(Map * sbGameTambahan){
    int skor;
    char *nama;
    Map M;
    srand(time(NULL));
    skor = rand() % 100;

    printf("GAME OVER\n");
    
    printf("Silahkan input nama anda: ");
    STARTWORD("", "");
    // wordToString(currentWord,*(&nama));

    if(IsMemberMap(*sbGameTambahan, nama)){
        printf("Nama sudah ada, silahkan input nama anda lagi: ");
        STARTWORD("", "");
        // wordToString(currentWord,*(&nama));
    }
    else{
        InsertMap(&M,nama,skor);
        printf("a");
    }

    printf("Skor akhir: %d\n", skor);
}

// void gameTambahan(Map * sbGameTambahan)
// {
//     int skor;
//     int i;
//     srand(time(NULL));
//     skor = rand() % 100;

//     printf("Silahkan input nama anda: ");
//     STARTWORD("", "");

//     char *str;
//     for (i = 0; i < currentWord.Length; i++)
//     {
//         *(str+i) = currentWord.TabWord[i];
//     }
//     *(str+i)='\0';

//     if(IsMemberMap(*sbGameTambahan, str)){
//         printf("Nama sudah ada, silahkan input nama anda lagi: \n");
//     }
//     else{
//         InsertMap(&M,*sbGameTambahan,skor);
//         printf("a");
//     }
//     InsertMap(*(&scoreboardGameTambahan),currentWord,skor);
//     printf("GAME OVER\n");
//     printf("Skor akhir: %d\n", skor);
// }

