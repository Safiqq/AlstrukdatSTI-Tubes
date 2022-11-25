#include "../../boolean.h"
#include "../mapscoreboard/mapsb.h"

#ifndef ARRAYMAP_H
#define ARRAYMAP_H

/* Kamus Umum */

#define IdxMaxArrayMap 99
#define IdxMinArrayMap 0
#define IdxUndefArrayMap -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxTypeArrayMap;
typedef MapSB ElTypeArrayMap;

typedef struct
{
    MapSB TIMap[IdxMaxArrayMap - IdxMinArrayMap + 1]; /* memori tempat penyimpan elemen (container) */
    int NeffArrMap;                               /* banyaknya elemen efektif */
} TabMap;

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
void CreateEmptyArrMap(TabMap *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(TabMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

void InsertLast(TabMap *T);
/* I.S. T terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir T. */


void DeleteAt(TabMap *T, IdxTypeArrayMap i);
/* I.S. T terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen T pada indeks ke-i dihapus dari T. */

#endif