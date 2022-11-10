/* File: array.h */
/* Definisi ADT Array */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include "../../boolean.h"

/* Kamus Umum */
#define CAPACITY 100

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char *ElTypeArray;

typedef struct
{
    ElTypeArray TI[CAPACITY]; /* memori tempat penyimpan elemen (container) */
    int Neff;                 /* banyaknya elemen efektif */
} TabStr;

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika T adalah TabStr, cara deklarasi dan akses: */
/* Deklarasi : T : TabStr */
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
extern void CreateArray(TabStr *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas CAPACITY */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
extern int LengthArray(TabStr T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */

extern void SetArray(TabStr *T, IdxType i, ElTypeArray v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
extern void SetNeffArray(TabStr *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
extern boolean IsEmptyArray(TabStr T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
extern void PrintArray(TabStr T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel ["RNG", "Diner DASH", "DINOSAUR IN EARTH"] maka akan diprint
1.RNG
2.Diner DASH
3.DINOSAUR IN EARTH
*/

#endif