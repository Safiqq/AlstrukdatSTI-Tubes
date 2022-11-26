#include <stdio.h>
#include "ADT/mapscoreboard/mapsb.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayOfMap/arraymap.h"
#include "ADT/array/array.h"

int iMax(MapSB M){
    int max =M.Elements[0].Value;
    int i=1,j=0;
    for(i;i<M.Count;i++){
        if(max<M.Elements[i].Value){
            j=i;
            max =M.Elements[i].Value;
        }
    }
    return j;
}

void printScoreboard(MapSB sb,char * nama){
    MapSB temp = sb;
    printf("**** SCOREBOARD GAME %s ****\n",nama);
    printf("| NAMA\t\t| SKOR\t\t|\n");
    printf("|-------------------------------|\n");
    int i=0;
    for(i;i<sb.Count;i++){
        printf("| %s\t",temp.Elements[iMax(temp)].Key);
        if(StringLength(temp.Elements[iMax(temp)].Key)<6){
            printf("\t");
        }
        printf("| %d\t\t|\n",Value(temp,temp.Elements[iMax(temp)].Key));
        DeleteMap(&temp,temp.Elements[iMax(temp)].Key);
    }
    printf("\n");
}

void scoreboard(TabMap arrSB, TabStr games){
    int i;
    for(i=0;i<NbElmtArrMap(arrSB);i++){
        printScoreboard(arrSB.TIMap[i],  games.TI[i]);
    }
}
