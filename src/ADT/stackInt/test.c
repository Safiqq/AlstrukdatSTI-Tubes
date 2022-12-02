#include "stackInt.h"

int main()
{
    StackInt S;
    infotypeSI x;
    // Membuat Stack
    CreateSI(&S);
    // Check apakah berhasil membuat stack
    printf("Stack berhasil dibuat dengan length : %d\n", LengthSI(S));
    // Menambahkan elemen
    PushSI(&S, 1);
    printf("Menambahkan satu elemen.\nApakah Stack kosong (Ya : 1 | No : 0) = %d\n", IsEmptySI(S));
    // Check apakah full
    printf("Panjang Stack : %d, CAPACITYnya : 10, Apakah full ? (Full : 1 | Tidak : 0) = %d\n", LengthSI(S), IsFullSI(S));
    // Mengurangi elemen
    PopSI(&S, &x);
    printf("Mengurangi satu elemen.\nApakah Stack kosong (Ya : 1 | No : 0) = %d\n", IsEmptySI(S));
}
