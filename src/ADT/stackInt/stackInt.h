/* File : stackInt.h */
/* Deklarasi Stack of Int yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef __STACKINT_H__
#define __STACKINT_H__

#include <stdio.h>
#include "../../header/boolean.h"

#define NilSI -1
#define MaxElSI 10
/* NilSI adalah stack dengan elemen kosong . */

typedef int infotypeSI;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  infotypeSI T[MaxElSI]; /* tabel penyimpan elemen */
  int TOP;       /* alamat TOP: elemen puncak */
} StackInt;
/* Definisi stack S kosong : S.TOP = NilSI */
/* Elemen yang dipakai menyimpan nilai StackInt T[0]..T[MaxEl-1] */
/* Jika S adalah StackInt maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopSI(S) (S).TOP
#define InfoTopSI(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateSI(StackInt *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai NilSI */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySI(StackInt S);
/* Mengirim true jika StackInt kosong: lihat definisi di atas */
boolean IsFullSI(StackInt S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackInt ************ */
void PushSI(StackInt *S, infotypeSI X);
/* Menambahkan X sebagai elemen StackInt S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackInt ************ */
void PopSI(StackInt *S, infotypeSI *X);
/* Menghapus X dari StackInt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int LengthSI(StackInt S);

#endif