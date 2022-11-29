/* File : stackStr.h */
/* Deklarasi Stack of Str yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef __STACKSTR_H__
#define __STACKSTR_H__

#include <stdio.h>
#include "../../header/boolean.h"

#define NilSS -1
#define MaxElSS 100
/* Nil adalah stack dengan elemen kosong . */

typedef char *infotypeSS;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  infotypeSS Tab[MaxElSS]; /* tabel penyimpan elemen */
  int TOP;             /* alamat TOP: elemen puncak */
} StackStr;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai StackStr T[0]..T[MaxElSS-1] */
/* Jika S adalah StackStr maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).Tab[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateSS(StackStr *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElSS */
/* jadi indeksnya antara 0.. MaxElSS */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySS(StackStr S);
/* Mengirim true jika StackStr kosong: lihat definisi di atas */

/* ************ Menambahkan sebuah elemen ke StackStr ************ */
void PushSS(StackStr *S, infotypeSS X);
/* Menambahkan X sebagai elemen StackStr S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackStr ************ */
void PopSS(StackStr *S, infotypeSS *X);
/* Menghapus X dari StackStr S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int NbElmtSS(StackStr S);
/* Mengembalikan jumlah elemen dari stack*/

void ReverseSS(StackStr *S);
/* I.S StackStr tidak kosong, stack terdefinisi*/
/* F.S StackStr berisi elemen yang urutannya terbalik dari yang awal*/

#endif