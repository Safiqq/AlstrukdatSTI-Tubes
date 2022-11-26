#include "stackInt.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateSI(StackInt *S)
{
    (*S).TOP = NilSI;
};
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySI(StackInt S)
{
    return (S.TOP == NilSI);
};

/* Mengirim true jika StackInt kosong: lihat definisi di atas */
boolean IsFullSI(StackInt S)
{
    return (S.TOP == MaxElSI - 1);
};
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackInt ************ */
void PushSI(StackInt *S, infotypeSI X)
{
    (*S).TOP++;
    (*S).T[(*S).TOP] = X;
};
/* Menambahkan X sebagai elemen StackInt S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackInt ************ */
void PopSI(StackInt *S, infotypeSI *X)
{
    *X = (*S).T[(*S).TOP];
    (*S).TOP--;
};
/* Menghapus X dari StackInt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int LengthSI(StackInt S)
{
    return TopSI(S) + 1;
}