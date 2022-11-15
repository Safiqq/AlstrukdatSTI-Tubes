/* File: matriks.h */
/* Definisi ADT Matriks */

#ifndef __MATRIKS_H__
#define __MATRIKS_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../boolean.h"

/* Kamus Umum */
#define CAPACITY 9

/* Definisi elemen dan koleksi objek */
typedef int IdxType;

typedef struct
{
    int TI[CAPACITY][CAPACITY]; /* memori tempat penyimpan elemen (container) */
    int Neff;                   /* banyaknya elemen efektif */
} Matrix2D;

/* Indeks yang digunakan [0..CAPACITY-1][0..CAPACITY-1] */
/* Jika M adalah Matrix2D, cara deklarasi dan akses: */
/* Deklarasi : M : Matrix2D */
/* Maka cara akses:
 * M.Neff untuk mengetahui banyaknya elemen
 * M.TI untuk mengakses seluruh nilai elemen matriks
 * M.TI[i][j] untuk mengakses elemen baris ke-i kolom ke-j */
/* Definisi :
 * Matriks kosong: T.Neff = 0
 * Definisi elemen pertama : M.TI[i][j] dengan i=0 dan j=0
 * Definisi elemen terakhir yang terdefinisi: M.TI[i][j] dengan i=CAPACITY-1 dan j=CAPACITY-1 */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
extern void CreateMtx(Matrix2D *M);
/* I.S. sembarang
   F.S. Terbentuk matriks M berisi template dengan ukuran 9x9
*/

extern void PrintMtx(Matrix2D M);
/* I.S. sembarang
   F.S. Menampilkan matriks sesuai format
*/

extern boolean IsFullMtx(Matrix2D M);
/* I.S. sembarang
   F.S. Mengembalikan true apabila matriks penuh
*/

#endif