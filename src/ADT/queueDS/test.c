#include "queue.h"

int main(){
    // Inisialisasi QueueDS
    QueueDS Q;

    // Check fungsi CreateQueueDS
    CreateQueueDS(&Q);

    // Check fungsi isEmptyQueueDS
    printf("isEmptyQueueDS -> Q berhasil dibuat dengan Q kosong maka akan menampilkan 1 dan jika salah maka 0 : %d\n", IsEmptyQueueDS(Q));

    // Check apakah berhasil membuat QueueDS Q sekaligus check fungsi lengthQueueDS
    printf("Q baru saja dibuat dengan length : %d\n", LengthQueueDS(Q));

    // Check fungsi EnqueueDS dan check apakah bertambah panjangnya setelah dienqueue
    ElTypeDS order1, order2;
    order1.timeC = 1; order1.timeK = 1; order1.price = 1;
    order2.timeC = 2; order2.timeK = 2; order2.price = 2;
    EnqueueDS(&Q, order1);
    printf("Order 1 baru dienqueue, dan length Q menjadi : %d\n", LengthQueueDS(Q));
    EnqueueDS(&Q, order2);
    printf("Order 2 baru dienqueue, dan length Q menjadi : %d\n", LengthQueueDS(Q));

    // Check fungsi DequeueDS
    ElTypeDS dorder1, dorder2;
    DequeueDS(&Q, &dorder2);
    printf("Order 2 baru didequeue dan length Q menjadi : %d\n", LengthQueueDS(Q));
    DequeueDS(&Q, &dorder1);
    printf("Order 1 baru didequeue dan length Q menjadi : %d\n", LengthQueueDS(Q));


    return 0;
}