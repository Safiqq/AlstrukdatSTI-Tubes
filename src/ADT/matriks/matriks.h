/* File: array.h */
/* Definisi ADT Array */

#ifndef __ARRAYTTT_H__
#define __ARRAYTTT_H__

#include <stdio.h>
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

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika T adalah Matrix2D, cara deklarasi dan akses: */
/* Deklarasi : T : Matrix2D */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff-1 */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
extern void CreateMtx(Matrix2D *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas CAPACITY */

#endif