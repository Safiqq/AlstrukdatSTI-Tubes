/*ENTER COMMAND: RESET SCOREBOARD

DAFTAR SCOREBOARD:
0. ALL
1. RNG
2. Diner DASH
3. HANGMAN
4. TOWER OF HANOI
5. SNAKE ON METEOR

SCOREBOARD YANG INGIN DIHAPUS: 0

APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)? YA

Scoreboard berhasil di-reset.
*/

#include <stdio.h>
#include "ADT/mapscoreboard/map.h"
#include "ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

void resetScoreboard( MapSB sbTOH,MapSB sbDiner,MapSB sbSOM,MapSB sbRNG,MapSB sbHangman, MapSB sbGameTambahan,MapSB sbTTT, MapSB sbsudoku){
    // printf("DAFTAR SCOREBOARD:\n");
    // printf("0. ALL\n");
    // printf("1. RNG\n");
    // printf("2. Diner Dash\n");
    // printf("3. HANGMAN\n");
    // printf("4. TOWER OF HANOI\n");
    // printf("5. SNAKE ON METEOR\n");
    // printf("6. TICTACTOE\n");
    // printf("7. SUDOKU\n");
    // printf("8. GAME TAMBAHAN\n");  

    char *resetSB[9] ={"ALL","RNG","DINER DASH","HANGMAN","TOWER OF HANOI","SNAKE ON METEOR","TICTACTOE","SUDOKU","GAME TAMBAHAN"};
    int i;
    for(i=0;i<9;i++){
        printf("%d. %s\n",i,resetSB[i]);
    }
    printf("SCOREBOARD YANG INGIN DIHAPUS: ");
    STARTWORD("", "");
    int n = atoi(currentWord.TabWord);
    
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ",resetSB[n]);
    STARTWORD("", "");

    if(isEqual(currentWord,"YA")){
        if(n==0){
            sbRNG.Count=0;
            sbDiner.Count=0;
            sbHangman.Count=0;
            sbTOH.Count=0;
            sbSOM.Count=0;
            sbTTT.Count=0;
            sbsudoku.Count=0;
            sbGameTambahan.Count=0;
        }
        else if(n==1){
            sbRNG.Count=0;
        }
        else if(n==2){
            sbDiner.Count=0;
        }
        else if(n==3){
            sbHangman.Count=0;
        }
         else if(n==4){
            sbTOH.Count=0;
        }
         else if(n==5){
            sbSOM.Count=0;
        }
        else if(n==6){
            sbTTT.Count=0;
        }
        else if(n==7){
            sbsudoku.Count=0;
        }
        else if(n==8){
            sbGameTambahan.Count=0;
        }
        printf("Scoreboard berhasil di-reset. \n");
    }
  else{
    printf("Scoreboard tidak di-reset. \n");
  }
}