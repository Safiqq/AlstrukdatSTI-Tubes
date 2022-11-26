#include "queue.h"

int main()
{
    // Inisialisasi
    Queue Q;
    // Membuat Queue kosong
    CreateQI(&Q);
    // Mengecek apakah kosong
    if (IsEmptyQI(Q))
    {
        printf("Queue masih kosong.\n");
    }
    // Melakukan EnqueueI
    ElTypeQue val;
    val = 3;
    EnqueueI(&Q, val);
    val = 20;
    EnqueueI(&Q, val);
    // Menampilkan isi queue setelah dienqueue
    DisplayQI(Q);

    // Mengecek panjang queue setelah di EnqueueI
    int len = LengthQI(Q);
    printf("Panjang Queue sekarang: %d\n", len);

    printf("--DequeueI--\n");
    DequeueI(&Q, &val);
    printf("Nilai val sekarang: %d\n", val);
    // Menampilkan isi queue setelah didequeue
    DisplayQI(Q);
    // Mengecek apakah queue kosong atau tidak
    if (!IsEmptyQI(Q))
    {
        printf("Queue sudah berisi.");
    }
    return 0;
}