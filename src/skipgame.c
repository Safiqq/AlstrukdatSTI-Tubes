#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"

void skipgame(Word skip, TabStr *listgame, Queue *antriangameidx){
    ADVWORD();
    int num=currentWord.TabWord[currentWord.Length]-'0';        //cara ngubah word ke int belum fix
    printf("Berikut adalah daftar game milikmu: \n");
    for(int i=1;i<=length(*antriangameidx);i++){
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