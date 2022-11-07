#include "playgame.h"

void playgame(TabStr *listgame, Queue *antriangameidx){
    int i;
    QueElType play;
    printf("Berikut adalah daftar game-mu di antrian sekarang: \n");
    for(i=1;i<=length(*antriangameidx);i++){
        printf("%d. %s\n",i,listgame->TI[antriangameidx->buffer[i-1]]);
    }
    if (!isEmpty(*antriangameidx)){
        QueElType val;
        dequeue(antriangameidx, &val);
        play=val;
        if (play==1){
            printf("Loading DINNER DASH ...");
            dinerdash();
        }
        else if (play==0){
            printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
            RNG_GAME();
        }
        else{
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. SIlakan pilih game lain.",listgame->TI[play]);
        }
    }
    else{
        printf("Belum ada game di antrianmu.\n");
    }
}