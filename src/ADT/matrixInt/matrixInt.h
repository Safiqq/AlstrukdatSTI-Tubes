/* File: matrixInt.h */
/* Definisi ADT Matrix of Int */

#ifndef __MATRIXINT_H__
#define __MATRIXINT_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../header/boolean.h"

/* Definisi elemen dan koleksi objek */
typedef int ElTypeMxI;

typedef struct
{
   ElTypeMxI **MI; /* memori tempat penyimpan elemen (container) */
   int capacity;      /* kapasitas matriks */
   int Neff;          /* banyaknya elemen efektif */
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
extern void CreateMxI(Matrix2D *M, int cap);
/* I.S. sembarang
   F.S. Terbentuk matriks M berisi template dengan ukuran capxcap
*/

extern void PrintMxI(Matrix2D M, int sub, char zero);
/* I.S. sembarang
   F.S. Menampilkan matriks sesuai format
*/

extern boolean IsFullMxI(Matrix2D M);
/* I.S. sembarang
   F.S. Mengembalikan true apabila matriks penuh
*/

#endif