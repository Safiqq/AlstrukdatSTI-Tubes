#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mapscoreboard/map.h"

void gameTambahan (MapSB *sbgameTambahan){
    int skor;
    srand(time(NULL));
    skor = rand() % 100;
    
    printf("\nGAME OVER\n");

    insertSB(sbgameTambahan,skor);
}
