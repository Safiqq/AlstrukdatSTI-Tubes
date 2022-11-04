#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "boolean.h"

void deletegame(Queue *listgame, Queue antriangame){
    printf("Berikut adalah daftar game yang tersedia\n");
    for(int i = 0; i < length(*listgame); i++){
        printf("\t%d.%s\n", i, (*listgame).buffer[i]);
    }
    int hapus;
    if (hapus<=5 && hapus>=1){
        printf("Game gagal dihapus.\n");
    }
    else{
        QueElType game;
        game=(*listgame).buffer[hapus-1];
        boolean isInAntrian= false;
        int i=0;
        while ((i<length(antriangame)) && !isInAntrian) {
            if (game==antriangame.buffer[i]){
                isInAntrian=true;
            }
            i++;
        }
        if (isInAntrian){
            printf("Game gagal dihapus.\n");
        }
        else{
            for (int i=hapus-1; i<length(*listgame);i++){
                if (i!=length(*listgame)-1){
                    (*listgame).buffer[i]=(*listgame).buffer[i+1];
                }
                else{
                    (*listgame).idxTail-=1;         //menghapus elemen terakhir menjadi sampah
                }
            }
            printf("Game berhasil dihapus.\n");
        }
    }
}