/* File: map.h */
/* Definisi ADT Map */

#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nill 0
#define MaxEle 10
#define Undefined -999

typedef char * keytype;
typedef int valuetype;
typedef int address;

typedef struct
{
	keytype Key;
	valuetype Value;
} infotypem;

typedef struct
{
	infotypem Elements[MaxEle];
	address Count;
} MapSB;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

extern void insertSB(MapSB *SB,int skor);

extern boolean stringEqual(char *a,char*b);

/* *** Konstruktor/Kreator *** */
extern void CreateMapSB(MapSB *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

extern boolean isEmptyMapSB(MapSB M);

extern boolean IsFullMapSB(MapSB M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

extern void InsertMapSB(MapSB *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
		M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

extern void DeleteMap(MapSB *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
		element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

extern boolean IsMemberMapSB(MapSB M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

extern valuetype Value(MapSB M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

#endif