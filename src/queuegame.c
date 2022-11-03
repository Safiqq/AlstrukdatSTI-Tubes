#include <stdio.h>
#include "./ADT/array/array.h"
#include "./ADT/queue/queue.h"

//TabInt ElType= Char
void QueueGame( TabStr *listgame, Queue *antriangameidx){
    for(int i=0;i<length(*antriangameidx);i++){
        printf("%d. %c",i,listgame->TI[antriangameidx->buffer[i]]);
    }
    for(int i=0;i<NbElmt(*listgame);i++){
        printf("%d. %c",i,listgame->TI[i]);
    }
    int n;
    Queue q;
    CreateQueue(&q);
    scanf("Nomor Game yang mau ditambahkan ke antrian: %d", &n);
    if (n > length(*antriangameidx)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else{
        enqueue(&(*antriangameidx),n-1);
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}

