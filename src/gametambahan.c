#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/mapscoreboard/mapsb.h"
#include "ADT/arrayOfMap/arraymap.h"

void gameTambahan (TabMap * arrSB, int play){
    int skor;
    srand(time(NULL));
    skor = rand() % 100;
    printf("=========================================\n");
    printf("GAME OVER\n");
    insertSB(&arrSB->TIMap[play],skor);
    printf("=========================================\n\n");

}
