#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/mesinkata/mesinkata.h"

void playgame(Queue *antriangame){
    QueElType play;
    printf("Berikut adalah daftar game milikmu: \n");
    for(int i =0;i<length(*antriangame);i++){
        printf("%d. %c",i,antriangame->buffer[i]);
    }
    if (!isEmpty(*antriangame)){
        QueElType val;
        dequeue(antriangame, &val);
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