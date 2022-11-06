#include "playgame.h"

void playgame(TabStr *listgame, Queue *antriangameidx){
    int i;
    QueElType play;
    printf("Berikut adalah daftar game milikmu: \n");
    for(i=1;i<=length(*antriangameidx);i++){
        printf("%d. %s\n",i,listgame->TI[antriangameidx->buffer[i-1]]);
    }
    if (!isEmpty(*antriangameidx)){
        QueElType val;
        dequeue(antriangameidx, &val);
        play=val;
    }
    if (play==1){
        dinerdash();
    }
    else if (play==2){
        RNG_GAME();
    }
    else{
        printf("Game %s masih dalam maintenance, belum dapat dimainkan. SIlakan pilih game lain.",play);
    }
}