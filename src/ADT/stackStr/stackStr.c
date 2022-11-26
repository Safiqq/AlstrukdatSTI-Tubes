#include "stackStr.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateSS(StackStr *S)
{
    Top(*S) = NilSS;
};
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElSS */
/* jadi indeksnya antara 0.. MaxElSS */
/* Ciri stack kosong : Top berNilSSai NilSS */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySS(StackStr S)
{
    return (Top(S) == NilSS);
};

/* Mengirim true jika StackStr kosong: lihat definisi di atas */
boolean IsFullSS(StackStr S)
{
    return (Top(S) == MaxElSS - 1);
};
/* Mengirim true jika tabel penampung NilSSai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackStr ************ */
void PushSS(StackStr *S, infotypeSS X)
{
    Top(*S)++;
    InfoTop(*S) = X;
};
/* Menambahkan X sebagai elemen StackStr S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi Top yang baru,Top bertambah 1 */

/* ************ Menghapus sebuah elemen StackStr ************ */
void PopSS(StackStr *S, infotypeSS *X)
{
    *X = InfoTop(*S);
    Top(*S)--;
};
/* Menghapus X dari StackStr S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilSSai elemen Top yang lama, Top berkurang 1 */

int NbElmtSS(StackStr S)
/* Mengembalikan jumlah elemen dari stack*/
{
    return Top(S) + 1;
}

void ReverseSS(StackStr *S)
/* I.S StackStr tidak kosong, stack terdefinisi*/
/* F.S StackStr berisi elemen yang urutannya terbalik dari yang awal*/
{
    StackStr S2;
    CreateSS(&S2);
    while (!IsEmptySS(*S))
    {
        infotypeSS X;
        PopSS(S, &X);
        PushSS(&S2, X);
    }
    int i;
    for (i = 0; i < NbElmtSS(S2); i++)
    {
        S->Tab[i] = S2.Tab[i];
    }
    S->TOP = S2.TOP;
}