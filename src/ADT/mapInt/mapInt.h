/* File: mapInt.h */
/* Definisi ADT Map of Int */

#ifndef __MAPINT_H__
#define __MAPINT_H__

#include <stdio.h>
#include "../../header/boolean.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 10
#define Undefined -999

typedef int keytype;
typedef int valuetype;

typedef struct
{
	keytype Key;
	valuetype ValueMS;
} infotype;

typedef struct
{
	infotype Elements[MaxEl];
	int Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
extern void CreateMI(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

extern boolean IsFullMI(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

extern void InsertMI(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
		M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

extern void DeleteMI(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
		element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

extern boolean IsMemberMI(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif