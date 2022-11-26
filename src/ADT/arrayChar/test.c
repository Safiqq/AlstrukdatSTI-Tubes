#include "arrayChar.h"

int main()
{
    // Inisialisasi T
    ArrayChar T;

    // Check fungsi CreateAC
    CreateAC(&T);

    // Check IsEmptyAC sekaligus check apakah T berhasil dibuat
    printf("IsEmptyAC -> Jika T berhasil dibuat maka output 1 atau jika gagal output 0 : %d\n", IsEmptyAC(T));

    // Check apakah sudah berhasil CreateAC sekaligus check lengthnya
    printf("T berhasil dibuat dengan Neffnya : %d\n", LengthAC(T));

    // Check fungsi SetAC
    SetAC(&T, 0, 1);
    printf("Array baru saja ditambahkan sehingga Neffnya menjadi : %d\n", LengthAC(T));
    printf("Array yang ditambahkan yaitu : %d dengan index ke-%d\n", T.TI[0], 0);
    SetAC(&T, 5, 0);
    printf("Array baru saja ditambahkan sehingga Neffnya menjadi : %d\n", LengthAC(T));
    printf("Array yang ditambahkan yaitu : %d dengan index ke-%d\n", T.TI[5], 5);

    return 0;
}