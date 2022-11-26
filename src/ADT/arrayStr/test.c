#include "arrayStr.h"

int main()
{
    // Inisialisasi
    ArrayStr A;
    // Membuat array kosong
    CreateAS(&A);
    if (IsEmptyAS(A))
    {
        printf("Array kosong berhasil dibuat.\n");
    }
    // SetAS (memasukkan elemen array) sekaligus mengetes setNeff di dalamnya
    IdxType i;
    ElTypeAS val;
    i = 0;
    val = " Halo ges";
    SetAS(&A, i, val);
    i = 1;
    val = " 20";
    SetAS(&A, i, val);
    // Melakukan print untuk mengecek apakah SetAS berhasil
    PrintAS(A);
    // Mengecek panjang array sekarang
    printf("Panjang array sekarang: %d\n", LengthAS(A));
    return 0;
}