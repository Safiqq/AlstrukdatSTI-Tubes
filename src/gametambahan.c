#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mapscoreboard/map.h"

void insertSB(MapSB *SB,int skor){
    char *str=malloc(sizeof(char)*13);
    printf("Masukkan nama anda: ");
    scanf("%s", str);
    while(!(!IsMemberMapSB(*SB,str)&& StringLength(str)<13)){
        printf("Nama tidak boleh sama dan panjang kurang dari 13\n");
        printf("Masukkan nama anda: ");
        scanf("%s", str);
    }
    InsertMap(SB,str,skor);
    printf("\nOke, nama akan dimasukkan ke scoreboard\n");

    printf("Skor akhir : %d\n", skor);
    printf("Nama       : %s\n", str);
}

void gameTambahan (MapSB *sbgameTambahan){
    int skor;
    srand(time(NULL));
    skor = rand() % 100;
    
    printf("\nGAME OVER\n");

    insertSB(sbgameTambahan,skor);
}
