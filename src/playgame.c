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
            printf("Loading RNG ...");
            printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak X.\n");
            RNG_GAME();
        }
        else if (play<=4 && play>=2){
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silakan pilih game lain.\n",listgame->TI[play]);
        }   
        else if (play==5){          //ini kalo misalkan game bonus dimasukin ke config
            printf("Loading TICTACTOE ...");
            tictactoe();
        }
        else if (play>=6 && play<=(*listgame).Neff) {
            gametambahan();
        }
    }
    else{
        printf("Belum ada game di antrianmu.\n");
    }
}