/* File: mapStr.h */
/* Definisi ADT Map of Str */

#ifndef __MAPSTR_H__
#define __MAPSTR_H__

#include <stdio.h>
#include <stdlib.h>
#include "../mesinkata/mesinkata.h"
#include "../../lib.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilMS 0
#define MaxElMS 10
#define UndefinedMS -999

typedef char *keytypeMS;
typedef int valuetypeMS;

typedef struct
{
	keytypeMS Key;
	valuetypeMS ValueMS;
} infotypeMS;

typedef struct
{
	infotypeMS Elements[MaxElMS];
	int Count;
} MapStr;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

extern void InsertSB(MapStr *SB, int skor);

/* *** Konstruktor/Kreator *** */
extern void CreateMS(MapStr *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

extern boolean IsEmptyMS(MapStr M);

extern boolean IsFullMS(MapStr M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

extern void InsertMS(MapStr *M, keytypeMS k, valuetypeMS v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
		M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

extern void DeleteMS(MapStr *M, keytypeMS k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
		element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

extern boolean IsMemberMS(MapStr M, keytypeMS k);
/* Mengembalikan true jika k adalah member dari M */

extern valuetypeMS ValueMS(MapStr M, keytypeMS k);
/* Mengembalikan nilai ValueMS dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

extern int iMax(MapStr M);

#endif