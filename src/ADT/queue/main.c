#include "queue.h"

int main()
{
    //Inisialisasi
    Queue Q;
    //Membuat Queue kosong
    CreateQueue(&Q);
    //Mengecek apakah kosong
    if (IsEmptyQueue(Q)){
        printf("Queue masih kosong.\n");
    }
    //Melakukan Enqueue
    ElTypeQue val;
    val=3;
    Enqueue(&Q,val);
    val=20;
    Enqueue(&Q,val);
    //Menampilkan isi queue setelah dienqueue
    DisplayQueue(Q);

    //Mengecek panjang queue setelah di enqueue
    int len=LengthQueue(Q);
    printf("Panjang Queue sekarang: %d\n", len);

    printf("--Dequeue--\n");
    Dequeue(&Q,&val);
    printf("Nilai val sekarang: %d\n", val);
    //Menampilkan isi queue setelah didequeue
    DisplayQueue(Q);
    //Mengecek apakah queue kosong atau tidak
    if (!IsEmptyQueue(Q)){
        printf("Queue sudah berisi.");
    }
    return 0;
}