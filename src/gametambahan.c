#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "ADT/mapscoreboard/map.h"

void gameTambahan (MapSB *sbgameTambahan){
    int skor;
    srand(time(NULL));
    skor = rand() % 100;
 
    printf("\nGAME OVER\n");
    printf("Silahkan input nama anda: ");
    STARTWORD("", "");
    char *str = currentWord.TabWord;

    if(!IsMemberMap(*sbgameTambahan,str)){
        InsertMap(*(&sbgameTambahan),str,skor);
        printf("Oke, nama akan dimasukkan ke scoreboard\n");
    }
    else{
        printf("Nama tidak valid\n");
    }
    

    printf("Skor akhir: %d\n", skor);
    printf("Nama: %s\n", str);
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

// int main(){
//     MapSB M;
//     CreateMap(&M);
//     gameTambahan(&M);
// }
