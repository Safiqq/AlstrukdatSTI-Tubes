/* File: arrayChar.h */
/* Definisi ADT Array of Char */

#ifndef __ARRAYCHAR_H__
#define __ARRAYCHAR_H__

#include <stdio.h>
#include "../../header/boolean.h"

/* Kamus Umum */
#define CAPACITY 100

/* Definisi elemen dan koleksi objek */
typedef char ElTypeAC;

typedef struct
{
    ElTypeAC TI[CAPACITY]; /* memori tempat penyimpan elemen (container) */
    int Neff;              /* banyaknya elemen efektif */
} ArrayChar;

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika T adalah ArrayChar, cara deklarasi dan akses: */
/* Deklarasi : T : ArrayChar */
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
extern void CreateAC(ArrayChar *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas CAPACITY */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
extern int LengthAC(ArrayChar T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
extern void SetAC(ArrayChar *T, int i, ElTypeAC v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
extern void SetNeffAC(ArrayChar *T, int N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
extern boolean IsEmptyAC(ArrayChar T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

#endif