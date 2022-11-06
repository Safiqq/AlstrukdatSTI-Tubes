#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"
#include "boolean.h"

void deletegame(TabStr *listgame, Queue antriangameidx){
    printf("Berikut adalah daftar game yang tersedia\n");
    for(int i=1;i<=NbElmt(*listgame);i++){
        printf("%d. %s\n",i,listgame->TI[i-1]);
    }
    QueElType hapus;
    if (hapus<=5 && hapus>=1){
        printf("Game gagal dihapus.\n");
    }
    else{
        boolean isInAntrian= false;
        int i=0;
        while ((i<length(antriangameidx)) && !isInAntrian) {
            if (hapus==antriangameidx.buffer[i]){
                isInAntrian=true;
            }
            i++;
        }
        if (isInAntrian){
            printf("Game gagal dihapus.\n");
        }
        else{
            for (int i=hapus-1; i<NbElmt(*listgame);i++){
                if (i!=NbElmt(*listgame)-1){
                    (*listgame).TI[i]=(*listgame).TI[i+1];
                }
                else{
                    (*listgame).Neff-=1;         //menghapus elemen terakhir menjadi sampah
                }
            }
            printf("Game berhasil dihapus.\n");
        }
    }
}