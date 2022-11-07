#include <stdio.h>
#include <stdlib.h>
#include "skipgame.h"

void skipgame(Word skip, TabStr *listgame, Queue *antriangameidx){
    ADVWORD();
    int i, num = atoi(currentWord.TabWord);        
    printf("Berikut adalah daftar game di antrian milikmu: \n");
    for(i=1;i<=length(*antriangameidx);i++){
        printf("%d. %s\n",i,listgame->TI[antriangameidx->buffer[i-1]]);
    }
    if (num>length(*antriangameidx)-1){
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    else{
        while (num!=0){
            QueElType val;
            dequeue(antriangameidx, &val);
            num--;
        }
        playgame(listgame,antriangameidx);
    }
}