/* File: array.h */
/* Definisi ADT Array */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "boolean.h"

/* Kamus Umum */
#define CAPACITY 100

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char ElType;

typedef struct
{
    ElType TI[CAPACITY]; /* memori tempat penyimpan elemen (container) */
    int Neff;                 /* banyaknya elemen efektif */
} Tab;

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika T adalah Tab, cara deklarasi dan akses: */
/* Deklarasi : T : Tab */
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
extern void CreateArray(Tab *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas CAPACITY */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
extern int LengthArray(Tab T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
extern ElType GetArray(Tab T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
extern void CopyArray(Tab Tin, Tab *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
extern void SetArray(Tab *T, IdxType i, ElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
extern void SetNeffArray(Tab *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
extern boolean IsEmptyArray(Tab T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
extern boolean IsFullArray(Tab T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
extern void PrintArray(Tab T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel ["RNG", "Diner DASH", "DINOSAUR IN EARTH"] maka akan diprint
RNG
Diner DASH
DINOSAUR IN EARTH
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

#endif