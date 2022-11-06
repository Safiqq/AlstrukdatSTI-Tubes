#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"

void playgame(TabStr *listgame, Queue *antriangameidx){
    QueElType play;
    printf("Berikut adalah daftar game milikmu: \n");
    for(int i=1;i<=length(*antriangameidx);i++){
        printf("%d. %s\n",i,listgame->TI[antriangameidx->buffer[i-1]]);
    }
    if (!isEmpty(*antriangameidx)){
        QueElType val;
        dequeue(antriangameidx, &val);
        play=val;
    }
    if (play==1){
        //dinnerdash();
    }
    else if (play==2){
        //rng();
    }
    else{
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. SIlakan pilih game lain.",play);
    }
}