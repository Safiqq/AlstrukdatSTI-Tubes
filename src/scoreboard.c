#include <stdio.h>
#include "ADT/mapscoreboard/map.h"
#include "ADT/mesinkata/mesinkata.h"

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

boolean stringEq(char *a,char*b){
    boolean beda=false;
    if(StringLength(a)==StringLength(b)){
        while(*a!='\0' && !beda){
            if(*a!=*b){
                beda = true;
            }
            *a++;
            *b++;
        }
        return !beda;
    }
    else{
        return beda;
    }
}

valuetype Val(MapSB M, keytype k){
    if(IsMemberMap(M,k)){
        int i = 0;
        boolean found=false;
        while(i<M.Count && !found){
            if(stringEq(M.Elements[i].Key,k)){

                found = true;
            }
            else{
                i++;
            }
        }
        return M.Elements[i].Value;
    }
    else{
        return Undefined;
    }  
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
        printf("| %d\t\t|\n",Val(temp,temp.Elements[iMax(temp)].Key));
        DeleteMap(&temp,temp.Elements[iMax(temp)].Key);
    }
    printf("\n");
}

void scoreboard(MapSB sbTOH,MapSB sbDiner, MapSB sbSOM, MapSB sbRNG,MapSB sbHangman, MapSB sbGameT ){
    printScoreboard(sbTOH, "TOWER OF HANOI");
    printScoreboard(sbDiner, "DINER DASH");
    printScoreboard(sbRNG,  "SNAKE ON METEOR");
    printScoreboard(sbRNG,  "RANDOM NUMBER GENERATOR");
    printScoreboard(sbHangman, "HANGMAN");
    printScoreboard(sbGameT,  "GAME TAMBAHAN");
}
