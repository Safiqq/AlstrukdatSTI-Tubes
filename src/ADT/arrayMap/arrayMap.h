/* File: arrayMap.h */
/* Definisi ADT Array of Map */

#include <stdio.h>
#include <stdlib.h>
#include "../mapStr/mapStr.h"
#include "../../header/boolean.h"

#ifndef __ARRAYMAP_H__
#define __ARRAYMAP_H__

/* Kamus Umum */

#define IdxMaxAM 99
#define IdxMinAM 0
#define IdxUndefAM -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeAM;
typedef MapStr ElTypeAM;

typedef struct
{
    MapStr TIMap[IdxMaxAM - IdxMinAM + 1]; /* memori tempat penyimpan elemen (container) */
    int NeffArrMap;                        /* banyaknya elemen efektif */
} ArrayMap;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah Tabstring, cara deklarasi dan akses: */
/* Deklarasi : T : Tabstring */
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
void CreateAM(ArrayMap *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtAM(ArrayMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void InsertLastAM(ArrayMap *T);
/* I.S. T terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir T. */

void DeleteAtAM(ArrayMap *T, IdxTypeAM i);
/* I.S. T terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen T pada indeks ke-i dihapus dari T. */

#endif