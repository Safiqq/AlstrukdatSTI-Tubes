/* File: array.h */
/* Definisi ADT Array */

#ifndef __ARRAYTTT_H__
#define __ARRAYTTT_H__

#include <stdio.h>
#include "../../boolean.h"

/* Kamus Umum */
#define CAPACITY 100

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char ElTypeArr;

typedef struct
{
    ElTypeArr TI[CAPACITY]; /* memori tempat penyimpan elemen (container) */
    int Neff;            /* banyaknya elemen efektif */
} TabChr;

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika T adalah TabChr, cara deklarasi dan akses: */
/* Deklarasi : T : TabChr */
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
extern void CreateArr(TabChr *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas CAPACITY */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
extern int LengthArr(TabChr T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
extern void SetArr(TabChr *T, IdxType i, ElTypeArr v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
extern void SetNeffArr(TabChr *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
extern boolean IsEmptyArr(TabChr T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */



#endif