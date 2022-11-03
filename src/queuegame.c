#include <stdio.h>
#include "./ADT/queue/queue.h"

// halo
void QueueGame(Queue *antriangame, Queue *listgame){
    for(int i =0;i<length(*antriangame);i++){
        printf("%d. %c",i,antriangame->buffer[i]);
    }
    for(int i =0;i<length(*listgame);i++){
        printf("%d. %c",i,listgame->buffer[i]);
    }
    int n;
    Queue q;
    CreateQueue(&q);
    scanf("Nomor Game yang mau ditambahkan ke antrian: %d",&n);
    if(n>length(*listgame)){
        printf("Nomor permainan tidak valid, silahkan masukkan nomor game pada list.\n");
    }
    else{
        char val = listgame->buffer[n-1];
        for(int i=0;i<length(*listgame);i++){
            if(i!=n-1){
                enqueue(&q,listgame->buffer[i]);
            }
        }
        enqueue(&(*antriangame),val);
        *listgame = q;
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}