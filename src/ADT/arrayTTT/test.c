#include "array.h"

int main()
{
    // Inisialisasi T
    TabChr T;

    // Check fungsi CreateArr
    CreateArr(&T);

    // Check isEmptyArr sekaligus check apakah T berhasil dibuat
    printf("isEmptyArr -> Jika T berhasil dibuat maka output 1 atau jika gagal output 0 : %d\n", IsEmptyArr(T));

    // Check apakah sudah berhasil CreateArr sekaligus check lengthnya
    printf("T berhasil dibuat dengan Neffnya : %d\n", LengthArr(T));

    // Check fungsi SetArr
    SetArr(&T, 0, 1);
    printf("Array baru saja ditambahkan sehingga Neffnya menjadi : %d\n", LengthArr(T));
    printf("Array yang ditambahkan yaitu : %d dengan index ke-%d\n", T.TI[0], 0);
    SetArr(&T, 5, 0);
    printf("Array baru saja ditambahkan sehingga Neffnya menjadi : %d\n", LengthArr(T));
    printf("Array yang ditambahkan yaitu : %d dengan index ke-%d\n", T.TI[5], 5);

    return 0;
}