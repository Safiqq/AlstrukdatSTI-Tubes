/* File: array.h */
/* Definisi ADT Array */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "../../boolean.h"

/* Kamus Umum */

#define IdxMax 99
#define IdxMin 0
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef char *ArrElType;

typedef struct
{
    ArrElType TI[IdxMax - IdxMin + 1]; /* memori tempat penyimpan elemen (container) */
    int Neff;                          /* banyaknya elemen efektif */
} TabStr;

/* Indeks yang digunakan [IdxMin..IdxMax] */
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
extern void MakeEmpty(TabStr *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
extern int NbElmt(TabStr T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
extern int MaxNbEl(TabStr T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
extern IdxType GetFirstIdx(TabStr T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
extern IdxType GetLastIdx(TabStr T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
extern ArrElType GetElmt(TabStr T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
extern void SetTab(TabStr Tin, TabStr *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
extern void SetEl(TabStr *T, IdxType i, ArrElType v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
extern void SetNeff(TabStr *T, IdxType N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
extern boolean IsIdxValid(TabStr T, IdxType i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
extern boolean IsIdxEff(TabStr T, IdxType i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
extern boolean IsEmpty(TabStr T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
extern boolean IsFull(TabStr T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

extern void CopyStr(char *str1, char *str2);

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
extern void TulisIsi(TabStr T);
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