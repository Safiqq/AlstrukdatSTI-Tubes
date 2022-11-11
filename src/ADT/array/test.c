#include "array.h"

int main()
{
    // Inisialisasi
    TabStr A;
    // Membuat array kosong
    CreateArray(&A);
    if (IsEmptyArray(A))
    {
        printf("Array kosong berhasil dibuat.\n");
    }
    // SetArray (memasukkan elemen array) sekaligus mengetes setNeff di dalamnya
    IdxType i;
    ElTypeArray val;
    i = 0;
    val = " Halo ges";
    SetArray(&A, i, val);
    i = 1;
    val = " 20";
    SetArray(&A, i, val);
    // Melakukan print untuk mengecek apakah setarray berhasil
    PrintArray(A);
    // Mengecek panjang array sekarang
    printf("Panjang array sekarang: %d\n", LengthArray(A));
    return 0;
}